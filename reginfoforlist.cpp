#include "reginfoforlist.h"
#include "ui_reginfoforlist.h"

RegInfoForList::RegInfoForList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegInfoForList)
{
    ui->setupUi(this);
    aund = false;
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");
    layout = new QGridLayout;
    container = new QWidget;
    deleteStatus = true;
    setWindowTitle("Управление видеорегистраторами");
    ui->lineEdit_3->setFocus();
    setWindowIcon(QIcon(":/res/img/DMT_EX.png"));
}

RegInfoForList::~RegInfoForList()
{
    delete ui;
}

void RegInfoForList::on_aund_clicked()
{
    if(!aund){
    if(ui->lineEdit_3->text() == settings.value("setting/password", "000000").toString())
    {
        aund = true;
        ui->aund->setText("Успешно");
        ui->aund->setStyleSheet("background-color:green; color: rgb(229, 223, 215);");
        ui->lineEdit_3->deleteLater();
        ui->widget->deleteLater();
        ui->widget_2->deleteLater();
        ui->label_11->deleteLater();
        settings.beginGroup("devices");
        logins = settings.childGroups();
        refrash();
    }
    else
    {
        QMessageBox::critical(this, "Неверный пароль", "Повторите вход");
    }
    }
}

void RegInfoForList::refrash()
{
    //delete layout;
    //delete container;
    layout = new QGridLayout;
    container = new QWidget;
    for (int i = 0; i < logins.size(); i++ ){
        DevInList *file = new DevInList(logins[i], this);
        List.push_back(file);
        layout->addWidget(file,i,0);
        container = new QWidget;
        container -> setLayout(layout);
        ui->scroll->setWidget(container);
    }
}

void RegInfoForList::on_aund_3_clicked()
{   if(aund)
    {
        if(deleteStatus){

            for (int i = 0; i < logins.size(); i++ ){
                if (List[i]->deleteStatus){
                    List[i]->deleteDev();
                }
            }
            deleteStatus = false;
            ui->aund_3->setStyleSheet("background-color:green; color: rgb(229, 223, 215); border-radius: 3px;");

            ui->aund_3->setText("Восстановить");
        }
        else
        {
            for (int i = 0; i < logins.size(); i++ ){
                if (!List[i]->deleteStatus){
                    List[i]->deleteDev();
                }
            }
            deleteStatus = true;
            ui->aund_3->setStyleSheet("background-color: rgb(120, 0, 0); color: rgb(229, 223, 215); border-radius: 3px;");
            ui->aund_3->setText("Сброс всех устройств");
        }
    }
}
