#include "scrollinfodev.h"
#include "ui_scrollinfodev.h"
using namespace std;

ScrollInfoDev::ScrollInfoDev(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::ScrollInfoDev)
{
    ui->setupUi(this);
    layout = new QGridLayout;
    container = new QWidget;
    container->setLayout(layout);
    setWidget(container);
    //connect(this, &BackEnd::uppendSlot, scroll, &ScrollInfoDev::uppendSignal);
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");
    errorInfoMes = true;
}

ScrollInfoDev::~ScrollInfoDev()
{
    delete ui;
}

void ScrollInfoDev::SetGraphWindow(int k)
{
    int row, col;
    InfoList.push_back(new InfoDev);
    qDebug()<< InfoList.size();
    qDebug() << k;
    row = k/4;
    col = k%4;
    layout->addWidget(InfoList[k],row,col);
    container = new QWidget;
    container -> setLayout(layout);
    setWidget(container);
}

void ScrollInfoDev::error(QString mes1, QString mes2)
{
    if(errorInfoMes){
        errorInfoMes = false;
        QMessageBox::warning(this, mes1, mes2);

    }
}

void ScrollInfoDev::CreateInfoWin(int k, QString USER, unsigned short uBattery, QString ID)
{
    k--;
    SetGraphWindow(k);
    InfoList[k]->SetUser(QString(USER));
    InfoList[k]->SetBatVal(uBattery);
    InfoList[k]->SetDownloadProgress(0);
    InfoList[k]->SetStatusDev(ID);
}

void ScrollInfoDev::deleteInfoDevSlot(int k)
{
    k--;
    int row = k/4;
    int col = k%4;
    layout->removeItem(layout->itemAtPosition(row,col));
    InfoList[k]->~InfoDev();
    qDebug() << "--Удаление виджета с экрана";
    qDebug() << k;
    qDebug() << "---------------------------";
    InfoList.erase(InfoList.begin()+k);

    for(int i = 0; i < InfoList.size(); i++){

        int row = i/4;
        int col = i%4;

        QThread::msleep(30);

        layout->addWidget(InfoList[i],row,col);
        container = new QWidget;
        container -> setLayout(layout);
        setWidget(container);
    }


    //
    qDebug() << 33333333;
    container = new QWidget;
    container -> setLayout(layout);
    qDebug() << 44444444;
    setWidget(container);
}

void ScrollInfoDev::regNewDevice(void *Handle, int statusDev)
{
    errorInfoMes = true;
    newDev = new AddNewDevToOrg(Handle, diskNewDEv, statusDev);
    newDev->setModal(true);
    newDev->exec();

}

void ScrollInfoDev::refreshInfoDevSlot(int k, unsigned short uBattery, int downloadStatus)
{
    //InfoList[k-1]->SetBatVal(uBattery);
    qDebug() << "NOOOOOOOOOOOOOOOOOOOOOOO";
    InfoList[k-1]->SetDownloadProgress(downloadStatus);
}
