#include "mainwidget.h"
#include "ui_mainwidget.h"

/*El constructor de MainWindow inicializa la ventana principal y crea la interfaz gráfica.*/
mainWidget::mainWidget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWidget),
    mSerialThread(nullptr)
{
    ui->setupUi(this);
    serialPort = new QSerialPort;
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

}

/* El destructor de MainWindow se encarga de detener el hilo SerialReaderThread y liberar
   recursos al cerrar la aplicación.*/
mainWidget::~mainWidget()
{
    if(mSerialThread){
        mSerialThread->requestInterruption();
        mSerialThread->wait();
        delete mSerialThread;
    }

    delete ui;
}

/* Con el boton de inicio se incializa el hilo lector y se lista los puertos y se toma el que esta abierto,*/
void mainWidget::on_Iniciar_clicked(){

        // Configurar y crear el hilo del lector serie con el puerto serie seleccionado
        QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();  // Se lista los puertos disponibles

        if (!portList.isEmpty()) {  // Se busca que puerto esta abierto

            const QString portName = portList.first().portName();   //Se almacena el puerto que esta abierto
            QSerialPort *serialPort = new QSerialPort(portName);

            mSerialThread = new serialThread(serialPort, this); // Se pasa el puerto a la clase serialThread
            // Con connect se establece una señál entre y un private slot.
            connect(mSerialThread, &serialThread::dataReceived, this, &mainWidget::appendDataToListWidget);
            connect(mSerialThread, &serialThread::dataTransmiter, this, &mainWidget::appendDataToListWidgetTx);
            mSerialThread->start();

        } else {
            qDebug() << "No se encontraron puertos serie disponibles.";
        }
}

/* Con el boton de finalizar se cierra el puerto y limpia el plainText.*/
void mainWidget::on_Finalizar_clicked(){

    if(mSerialThread){
        mSerialThread->requestInterruption();
        mSerialThread->wait();
        delete mSerialThread;
        mSerialThread = nullptr;
        mSerialThread->resetHeaderDetection();
    }

//    ui->plainTextEdit->clear();
}

/* llama cuando se reciben datos y se encarga de mostrar los datos en una lista
   en la interfaz gráfica. También almacena los datos en archivos de texto y binarios.*/
void mainWidget::appendDataToListWidget(const charFrame_t& data){


    QString  strFrame;
    uint8_t  uartCRC8 = data.tramaEntrada.crc8;
    uint8_t  checkCRC8;
    checkCRC8 = codeCRC8((uint8_t *)&data.tramaEntrada, sizeof (data.tramaEntrada)-2);

    strFrame.sprintf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", data.tramaEntrada.start, data.tramaEntrada.count,
                data.tramaEntrada.a1in, data.tramaEntrada.a2in, data.tramaEntrada.a3in, data.tramaEntrada.a4in,
                data.tramaEntrada.a5in, data.tramaEntrada.a6in, data.tramaEntrada.a7in, data.tramaEntrada.a8in,
                data.tramaEntrada.a1out, data.tramaEntrada.a2out,
                data.tramaEntrada.dIns, data.tramaEntrada.dOuts, data.tramaEntrada.crc8);

    QString crc8Text = QString("CRC8 recibido: %1  Calculado: %2").arg(uartCRC8).arg(checkCRC8);

    ui->plainTextEdit->appendPlainText("Trama recibida: " + strFrame + "\r\n");    //Se imprime en plainText lo recibido en sus valores enteros

    double voltage[8];
    float rangeanalogMax = 4095.0;
    float voltageMax = 10.0;

    voltage[0] = (static_cast<double>(data.tramaEntrada.a1in) / rangeanalogMax) * voltageMax;
    voltage[1] = (static_cast<double>(data.tramaEntrada.a2in) / rangeanalogMax) * voltageMax;
    voltage[2] = (static_cast<double>(data.tramaEntrada.a3in) / rangeanalogMax) * voltageMax;
    voltage[3] = (static_cast<double>(data.tramaEntrada.a4in) / rangeanalogMax) * voltageMax;
    voltage[4] = (static_cast<double>(data.tramaEntrada.a5in) / rangeanalogMax) * voltageMax;
    voltage[5] = (static_cast<double>(data.tramaEntrada.a6in) / rangeanalogMax) * voltageMax;
    voltage[6] = (static_cast<double>(data.tramaEntrada.a7in) / rangeanalogMax) * voltageMax;
    voltage[7] = (static_cast<double>(data.tramaEntrada.a8in) / rangeanalogMax) * voltageMax;

    for (int i = 0; i < 8; i++) {
        // Calcula el nombre del LCD correspondiente (puede variar según tu implementación)
        QString lcdName = QString("AN%1").arg(i + 1);

        // Muestra el valor en el display correspondiente
        QLCDNumber* lcd = this->findChild<QLCDNumber*>(lcdName);
        if (lcd) {
            lcd->display(QString::number(voltage[i], 'f', 2));
        } else {
            qDebug() << "No se encontró el LCD para" << lcdName;
        }
    }

}

void mainWidget::appendDataToListWidgetTx(const charTxFrame_t& data){

    QString strFrameTx;

    strFrameTx.sprintf("Trama Enviada: %d %d %d %d %d %d \r\n", data.tramaEnvio.start,
                    data.tramaEnvio.count, data.tramaEnvio.a1out,
                    data.tramaEnvio.a2out, data.tramaEnvio.dOuts, data.tramaEnvio.crc8);

    ui->plainTextEdit->appendPlainText(strFrameTx);
}



uint8_t mainWidget::codeCRC8(uint8_t *dataFrame, uint8_t longitud){

    uint8_t polinomio_generador = 0x07; // Polinomio generador CRC-8 (0x07)
    uint8_t reg_crc = 0; // Inicializa el registro CRC en cero

    for (uint8_t i = 0; i < longitud; i++) { // Se recorre la estructura
        reg_crc ^= dataFrame[i]; // Realiza un XOR con el byte actual

        for (uint8_t j = 0; j < 8; j++) {

            if (reg_crc & 0x80) {	// // Si el bit MSB = 1
                /*se realiza una operación XOR con el polinomio generador y se
                 * desplaza el registro CRC un bit a la izquierda*/
                reg_crc = (reg_crc << 1) ^ polinomio_generador;

             // Si el MSB = 0 Simplemente se desplaza 1 bit a la izquierda el reg_crc
            }else reg_crc <<= 1;
        }
    }

    return reg_crc;
}


//    if(checkCRC8 == data.tramaEntrada.crc8){
//        ui->plainTextEdit->appendPlainText(crc8Text);
//    }
//    else {
//        ui->plainTextEdit->appendPlainText("Error en trama recibida");
//        ui->plainTextEdit->appendPlainText(crc8Text);
//    }


//     Almacenar la cadena en un archivo .txt
//    QFile txtFile("datos.txt");
//    if (txtFile.open(QIODevice::Append | QIODevice::Text)) {
//        QTextStream txtStream(&txtFile);
//        txtStream << str << "\n"; // Escribe la cadena en el archivo de texto y agrega una nueva línea
//        txtFile.close();
//    }
//    // Almacenar los datos en un archivo .bin
//    QFile binFile("datos.bin");
//    if (binFile.open(QIODevice::Append)) {
//        QDataStream binStream(&binFile);
//        binStream.writeRawData(data.tramaEntradaChar, sizeof(data.tramaEntradaChar)); // Escribe los datos binarios
//        binFile.close();
//    }
