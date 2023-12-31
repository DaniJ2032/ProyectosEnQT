#include "mainwidget.h"
#include "ui_mainwidget.h"

/*El constructor de MainWindow inicializa la ventana principal y crea la interfaz gráfica.*/
mainWidget::mainWidget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWidget),
    mSerialThread(nullptr)
{
    ui->setupUi(this);
    // Seteo del puerto serie
    serialPort = new QSerialPort;
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    inicializarUI();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &mainWidget::sistemInit);
    timer->start(250); // Delay para los Diales y botones de la interfaz
}

void mainWidget::inicializarUI(){

//     Botones para las salidas digitales
    for(int i = 0; i < 8; i++){
        QPushButton *button = findChild<QPushButton*>("D" + QString::number(i));
        buttons.append(button);

        QStateMachine *machine = new QStateMachine(this);

        QState *off = new QState();
        off->assignProperty(button, "text", "0");
        off->setObjectName("0");

        QState *on = new QState();
        on->setObjectName("1");
        on->assignProperty(button, "text", "1");

        off->addTransition(button, &QPushButton::clicked, on);
        on->addTransition(button, &QPushButton::clicked, off);

        machine->addState(off);
        machine->addState(on);

        machine->setInitialState(off);
        machine->start();

        machines.append(machine);
    }
    //  Set para los Diales
    ui->dailAnalog1->setMinimum(0);
    ui->dailAnalog1->setMaximum(100);
    ui->dailAnalog2->setMinimum(0);
    ui->dailAnalog2->setMaximum(100);
}

/* El destructor de MainWindow */
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

    if (!mSerialThread) {  // Se busca que puerto esta abierto
        const QString portName = portList.first().portName();   //Se almacena el puerto que esta abierto
        QSerialPort *serialPort = new QSerialPort(portName);

        mSerialThread = new serialThread(serialPort, this); // Se pasa el puerto a la clase serialThread
        // Con connect se establece una señál entre y un private slot.
        connect(mSerialThread, &serialThread::dataReceived, this, &mainWidget::sistemInit);
        connect(mSerialThread, &serialThread::dataTransmiter, this, &mainWidget::appendDataToListWidget);
        mSerialThread->start(); // Inicio el Hilo

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
}

/* Aca se inicia el sistema para la toma de datos de la interfaz cada 250 ms*/
void mainWidget::sistemInit(){

    static QDateTime lastDateTime = QDateTime::currentDateTime();

    if(mSerialThread){
        QDateTime currentDateTime = QDateTime::currentDateTime();

        if(lastDateTime.msecsTo(currentDateTime) >= 1000){
            lastDateTime = currentDateTime;
            // Actualiza los botones y Diales
            updateDataButonsAndDials();
            // Actualiza los display de las entradas analógicas
            updateAnalogDisplay();
            // Actualiza los display de las entradas Digitales
            updateDisplayDigital();
       }
   }

}

/* Para debug, imprime las tramas recibidas y enviadas */
void mainWidget::appendDataToListWidget(){

    QString strFrame = mSerialThread->printToFrameRx();
    QString strFrameTx = mSerialThread->printToFrameTx();
    qDebug()<<"Trama recibida: " + strFrame;
    qDebug()<<"Trama enviada: " + strFrameTx;
}

/* Actaualiza valores de los display */
void mainWidget::updateAnalogDisplay(){

    double *voltage = mSerialThread->updateADisplay();

    for (int i = 0; i < 8; i++) {
        // Calcula el nombre del LCD correspondiente (puede variar según tu implementación)
        QString lcdName = QString("AN%1").arg(i + 1);
        // Muestra el valor en el display correspondiente
        QLCDNumber* lcd = this->findChild<QLCDNumber*>(lcdName);
        if (lcd) {
            lcd->display(QString::number(*(voltage+i), 'f', 2));
        } else {
            qDebug() << "No se encontró el LCD para" << lcdName;
        }
    }
}

/* Actualiza display Digitales */
void mainWidget::updateDisplayDigital(){

    bool * bit = mSerialThread->updateDigDisplay();
    for (int i = 0; i < 8; ++i) {
        QString lcdNameDig = QString("DispD%1").arg(i);
        QLCDNumber* DisplayD = this->findChild<QLCDNumber*>(lcdNameDig);
        if(DisplayD){
            DisplayD->display(*(bit+i));
        } else {
            qDebug() << "No se encontro Display para la entrada digital" << lcdNameDig;
        }
    }
}

/* Actualiza valor de los botones y de los diales*/
void mainWidget::updateDataButonsAndDials(){
    readyToSendData = false;

    uint8_t* buttonValues = getButtonStates();
    if(readyToSendData && mSerialThread){ mSerialThread->readButtonValue(buttonValues); }

    uint8_t valueDAC0 = setdailAnalog1();
    if(readyToSendData && mSerialThread){ mSerialThread->readDialDAC(valueDAC0, 0); }

    uint8_t valueDAC1 = setdailAnalog2();
    if(readyToSendData && mSerialThread){ mSerialThread->readDialDAC(valueDAC1, 1); }
}

/* Obtener valores de los botones*/
uint8_t* mainWidget::getButtonStates(){

    static uint8_t buttonValues[8] = {0};
    // Variable estatica para los valores previos de botones
    static uint8_t previousButtonValues[8] = {0};
    bool buttonValuesChanged = false;

    for (int i = 0; i < 8; i++) {
        bool isOn = buttons[i]->property("text").toString() == "1";
        buttonValues[i] = isOn ? 1 : 0;
    }    
    for (int i = 0; i < 8; i++) {
        if (buttonValues[i] != previousButtonValues[i]) {
            buttonValuesChanged = true;
            break;
        }
    }    
    // Actualiza los valores previos de los botones
    for (int i = 0; i < 8; i++) {
        previousButtonValues[i] = buttonValues[i];
    }
    if (buttonValuesChanged && mSerialThread) {
        readyToSendData = true;
        return buttonValues;
    }else{
        readyToSendData = false;
        return 0;
    }
}

/* Obtener valor del Dial 1*/
uint8_t mainWidget::setdailAnalog1(){
    uint8_t value = ui->dailAnalog1->value();
    static uint8_t previousValue = 0;

    if(value != previousValue){
        readyToSendData = true;
        previousValue = value;
        return value;
    }else{
        readyToSendData = false;
        return 0;
    }
}

/* Obtener valor del Dial1*/
uint8_t mainWidget::setdailAnalog2(){
    uint8_t value = ui->dailAnalog2->value();
    static uint8_t previousValue = 0;

    if(value != previousValue){
        readyToSendData = true;
        previousValue = value;
        return value;
    }else{
        readyToSendData = false;
        return 0;
    }
}
