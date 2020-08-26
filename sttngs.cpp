#include "sttngs.h"
#include "ui_sttngs.h"

Sttngs::Sttngs(QString login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sttngs)
{
    ui->setupUi(this);
    this->login = login;
    aund = false;

    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");
    deleteFlag = settings.value("setting/deleteflag", false).toBool();
    ui->radioButton->setChecked(deleteFlag);
    ui->lineEdit_3->setFocus();
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->lineEdit_3->setFocus();
    setWindowTitle("Настройки");
    setWindowIcon(QIcon(":/res/img/DMT_EX.png"));
}

Sttngs::~Sttngs()
{
    delete ui;

}

void Sttngs::on_comboBox_activated(int index)
{
    ind = index;
    qDebug() << "EEEE";
}

void Sttngs::on_pushButton_4_clicked()
{
    qDebug() << "Изменено";
    if (aund)
    {
        settings.setValue("setting/password",ui->lineEdit_5->text());
        qDebug() << "Изменено";
    }
}

void Sttngs::on_pushButton_3_clicked()
{
    if(!aund)
    {
        if(ui->lineEdit_3->text() == settings.value("setting/password", "000000").toString())
        {
            aund = true;
            ui->pushButton_3->setText("Успешно");
            ui->pushButton_3->setStyleSheet("background-color:green; color: rgb(229, 223, 215);");
            ui->lineEdit_3->deleteLater();
            ui->label_11->deleteLater();
            ui->label_4->setText(settings.value("setting/firstpath", "C:/Bodycam").toString());
            QString buffer = settings.value("setting/firstpath", "C:/Bodycam").toString();
            ui->label_5->setText(settings.value("setting/secondpath", buffer+"/izb").toString());
            ui->widget->deleteLater();
        }
        else
        {
            QMessageBox::critical(this, "Неверный пароль", "Повторите вход");
        }
    }
}




void Sttngs::on_pushButton_clicked()
{
    if (aund){
        QFileDialog filePath;
        QString path;
        path = filePath.getExistingDirectory();
        if(path != ""){
            settings.setValue("setting/firstpath",path);
            ui->label_4->setText(settings.value("setting/firstpath").toString());
        }
    }
}

void Sttngs::on_pushButton_2_clicked()
{
    if (aund){
        QFileDialog filePath;
        QString path;
        path = filePath.getExistingDirectory();
        if(path != ""){
            settings.setValue("setting/secondpath",path);
            ui->label_5->setText(settings.value("setting/secondpath").toString());
        }
    }
}

void Sttngs::on_radioButton_clicked()
{
    if(aund){
        if(deleteFlag){
            deleteFlag = false;
            settings.setValue("setting/deleteflag",false);
        }
        else
        {
            deleteFlag = true;
            settings.setValue("setting/deleteflag",true);
        }
    }
    else
    {
        ui->radioButton->setChecked(deleteFlag);
    }
}
