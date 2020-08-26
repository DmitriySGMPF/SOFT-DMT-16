#include "devinlist.h"
#include "ui_devinlist.h"

DevInList::DevInList(QString devID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DevInList)
{
    ui->setupUi(this);
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");

    this->devID = devID;
    deleteStatus = true;

    devName = settings.value("devices/" + devID + "/user").toString();
    ui->userName->setText(devName);
    devStatus = settings.value("devices/" + QString(devID) + "/status").toBool();

    if(devStatus){
        ui->regModel->setText("DMT-EX");
    }
    else
    {
        ui->regModel->setText("DMT-10");
    }
}

DevInList::~DevInList()
{
    delete ui;
}

void DevInList::on_deleteReg_clicked()
{
    deleteDev();
}

void DevInList::deleteDev()
{
    if (deleteStatus)
    {
        settings.remove("devices/" + devID);
        deleteStatus = false;
        ui->deleteReg->setStyleSheet("background-color:green; color: rgb(229, 223, 215); border-radius: 3px;");
        ui->deleteReg->setText("Отмена");
    }
    else
    {
        settings.setValue("devices/" + devID + "/user", devName);
        settings.setValue("devices/" + devID + "/status", devStatus);
        deleteStatus = true;
        ui->deleteReg->setStyleSheet("background-color: rgb(120, 0, 0);  color: rgb(229, 223, 215); border-radius: 3px;");
        ui->deleteReg->setText("Удалить");
    }
}




void DevInList::on_userName_textEdited(const QString &arg1)
{
    settings.setValue("devices/" + devID + "/user", ui->userName->text());
}
