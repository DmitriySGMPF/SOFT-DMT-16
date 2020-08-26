#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "log.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    k = 0;
    //Запуск бакэнда
    //Запуск бакэнда

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("CP 1251"));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QWidget * contein = new QWidget(this);
    mainLayout->addWidget(contein);
    InfoRight *right = new InfoRight("admin", "Администратор",this);
    mainLayout->addWidget(right);

    scroll = new ScrollInfoDev(contein);
    centralWidget()->setLayout(mainLayout);
    contein->resize(1440, 1000);

    back = new BackEnd(scroll);
    //backDMT16 = new BackEndDMT16(scroll);

    contein->show();
    scroll -> show();


    connect(&backEndThread, &QThread::started, back, &BackEnd::run);
    //connect(&backEndThreadDMT16, &QThread::started, backDMT16, &BackEndDMT16::run);//DMT16

    connect(right, &InfoRight::ex, this, &MainWindow::ext);

    back->moveToThread(&backEndThread);
    backEndThread.start();

    //backDMT16->moveToThread(&backEndThreadDMT16);//DMT16
    //backEndThreadDMT16.start();



    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");
    QSettings settings;
    settings.remove("uses");





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::ext()
{
    back->stop();  // ждем пока выйдет
    QThread::msleep(1500);
    backEndThread.terminate();
    deleteLater();
}


