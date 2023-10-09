#include "mainwidget.h"
#include "ui_mainwidget.h"

/*El constructor de MainWindow inicializa la ventana principal y crea la interfaz gráfica.*/
mainWidget::mainWidget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWidget),
    mSerialThread(nullptr)
{
    ui->setupUi(this);
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

    if (!mSerialThread) {
        // Configurar y crear el hilo del lector serie con el puerto serie seleccionado
        QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();  // Se lista los puertos disponibles

        if (!portList.isEmpty()) {  // Se busca que puerto esta abierto

            const QString portName = portList.first().portName();   //Se almacena el puerto que esta abierto
            mSerialThread = new serialThread("COM6", this); // Se pasa el puerto a la clase serialThread

            // Con connect se establece una señál entre y un private slot.
            connect(mSerialThread, &serialThread::dataReceived, this, &mainWidget::appendDataToListWidget);
            mSerialThread->start();
        } else {
            qDebug() << "No se encontraron puertos serie disponibles.";
        }
    }
}


/* Con el boton de finalizar se cierra el puerto y limpia el plainText.*/
void mainWidget::on_Finalizar_clicked(){

    if(mSerialThread){
        mSerialThread->requestInterruption();
        mSerialThread->wait();
        delete mSerialThread;
        mSerialThread = nullptr;
    }
//    ui->plainTextEdit->clear();
}
/* llama cuando se reciben datos y se encarga de mostrar los datos en una lista
   en la interfaz gráfica. También almacena los datos en archivos de texto y binarios.*/
void mainWidget::appendDataToListWidget(const charFrame_t& data){

    QString str;
    str.sprintf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d ", data.tramaEntrada.start, data.tramaEntrada.count,
                data.tramaEntrada.a1in, data.tramaEntrada.a2in, data.tramaEntrada.a3in, data.tramaEntrada.a4in,
                data.tramaEntrada.a5in, data.tramaEntrada.a6in, data.tramaEntrada.a7in, data.tramaEntrada.a8in,
                data.tramaEntrada.a1out, data.tramaEntrada.a2out,
                data.tramaEntrada.dIns, data.tramaEntrada.dOuts);
    ui->plainTextEdit->appendPlainText(str);    //Se imprime en plainText lo recibido en sus valores enteros
    // Almacenar la cadena en un archivo .txt
    QFile txtFile("datos.txt");
    if (txtFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream txtStream(&txtFile);
        txtStream << str << "\n"; // Escribe la cadena en el archivo de texto y agrega una nueva línea
        txtFile.close();
    }
    // Almacenar los datos en un archivo .bin
    QFile binFile("datos.bin");
    if (binFile.open(QIODevice::Append)) {
        QDataStream binStream(&binFile);
        binStream.writeRawData(data.tramaEntradaChar, sizeof(data.tramaEntradaChar)); // Escribe los datos binarios
        binFile.close();
    }
}

