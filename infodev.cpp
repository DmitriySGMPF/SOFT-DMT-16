#include "infodev.h"
#include "ui_infodev.h"

void InfoDev::SetUser(QString USER_NAME)
{
    ui->USER->setText(USER_NAME);
    qDebug() << "EEEE";
    qDebug() << ui->USER->text();


    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");

}

void InfoDev::SetBatVal(int bat)
{
    ui->bat_1->setValue(bat);

}

void InfoDev::SetDownloadProgress(int progress)
{
    ui->DownloadProgress->setValue(progress);
}

void InfoDev::SetStatusDev(QString ID)
{
    QSettings settings;
    exStatus = settings.value("devices/" + QString(ID) + "/status").toInt();

    int w = ui->DMT10->width();
    int h = ui->DMT10->height();/////////////////////////
    qDebug() << exStatus;
    qDebug() << "sfvgbggds";
    if(exStatus == 0)
    {
        ui->bat_1->deleteLater();
        QPixmap devImg(":/res/img/DMT_EX.png");
        ui->DMT10->setPixmap(devImg.scaled(w,h,Qt::KeepAspectRatio));
        ui->label_4->setText("DMT-EX-2");
        //ui->label_3->set

    }

    if(exStatus == 1)
    {
        QPixmap devImg(":/res/img/DMT10_.png");
        ui->DMT10->setPixmap(devImg.scaled(w,h,Qt::KeepAspectRatio));
    }

    if(exStatus == 2)
    {
        QPixmap devImg(":/res/img/DMT16.png");
        ui->DMT10->setPixmap(devImg.scaled(w,h,Qt::KeepAspectRatio));
        ui->label_4->setText("DMT16");
    }
}


InfoDev::InfoDev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoDev)
{
    ui->setupUi(this);





    ui->bat_1->setStyleSheet("QProgressBar {"
                              "background-color: rgb(178, 34, 34);"
                              "color: black;"
                              //"border-style: outset;"
                              //"border-width: 2px;"
                              //"border-color: black;"
                              //"border-radius: 3px;"
                              "font-weight: bold;"
                              "text-align: center; }"

                              "QProgressBar::chunk {"
                              "background-color: #5cc081; }");

    ui->DownloadProgress->setStyleSheet("QProgressBar {"
                              "background-color: rgb(178, 34, 34);"
                              "color: black;"
                              //"border-style: outset;"
                              //"border-width: 2px;"
                              //"border-color: black;"
                              //"border-radius: 3px;"
                              "font-weight: bold;"
                              "text-align: center; }"

                              "QProgressBar::chunk {"
                              "background-color: #5cc081; }");
}



InfoDev::~InfoDev()
{
    delete ui;
}
