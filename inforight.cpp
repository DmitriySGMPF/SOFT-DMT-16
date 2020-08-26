#include "inforight.h"
#include "ui_inforight.h"

InfoRight::InfoRight(QString login,QString nameOrg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoRight)
{
    ui->setupUi(this);


    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");
    QSettings settings;

    ui->NameOrg->setText(settings.value("setting/name").toString());
    QPixmap logo(":/res/img/2_black.png");
    int w = ui->LOGO->width();
    int h = ui->LOGO->height();
    ui->LOGO->setPixmap(logo.scaled(w,h,Qt::KeepAspectRatio));
}

InfoRight::~InfoRight()
{
    delete ui;
}




void InfoRight::on_Exit_clicked()
{
    ex();
}

void InfoRight::on_pushButton_3_clicked()
{
    //FileMan *files = new FileMan(login);
    //files->show();
    FileMan files;
    files.setModal(true);
    files.exec();
}

void InfoRight::on_pushButton_clicked()
{
    Sttngs set(login);
    set.setModal(true);
    set.exec();
}

void InfoRight::on_pushButton_4_clicked()
{
    RegInfoForList *regInfoForList = new RegInfoForList;
    regInfoForList->setModal(true);
    regInfoForList->exec();//
}
