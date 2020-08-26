
#include "addnewdevtoorg.h"
#include "ui_addnewdevtoorg.h"

AddNewDevToOrg::AddNewDevToOrg(DEV_HANDLE Handle, char disk, int statusDev,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDevToOrg)
{
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");

    ui->setupUi(this);

    this->Handle = Handle;
    drive = disk;
    this -> statusDev = statusDev;

    int w = ui->DMT->width();
    int h = ui->DMT->height();/////////////////////////

    setWindowTitle("Добавление нового устройства");
    setWindowIcon(QIcon(":/res/img/DMT_EX.png"));

    if (statusDev > 1)
    {

        delete ui->widget;

        if (statusDev == 2)
        {
            QPixmap devImg3(":/res/img/DMT16.png"); // Поменять картинку
            ui->DMT->setPixmap(devImg3.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
    else
    {
        QPixmap devImg1(":/res/img/DMT_EX.png");
        QPixmap devImg2(":/res/img/DMT10_.png");
        ui->DMT->setPixmap(devImg1.scaled(w,h,Qt::KeepAspectRatio));
    }


}

AddNewDevToOrg::~AddNewDevToOrg()
{
    delete ui;
}


void AddNewDevToOrg::on_comboBox_activated(int index)
{
    ind = index-1;

}

void AddNewDevToOrg::on_pushButton_clicked()
{
    qDebug() << "HELLO";
    char ID[10];
    char COMPID[10] = "000000";
    char D[10] = "000000";
    srand(static_cast<unsigned int>(time(0))); // random
    int setID = 100000 + rand() % 899999;
    itoa(setID, ID, 10);
    qDebug() << setID;
    SetUserDevID(Handle, ID, COMPID, D);
    QString Id = QString(ID);
    if(setDriveToDevice(drive, ID))
    {
    qDebug() << "ЗАРЕГАН!";
    name = ui->lgn->text();
    qDebug() << name;
    settings.setValue("devices/" + QString(ID) + "/user", name);


    if (statusDev < 2){
        if(ui->radioButton->isChecked()){

            settings.setValue("devices/" + QString(ID) + "/status", int(0));
        }
        else{
            settings.setValue("devices/" + QString(ID) + "/status", int(1));
        }
    }

    if (statusDev == 2)
    {
        settings.setValue("devices/" + QString(ID) + "/status", int(2));
    }

    settings.setValue("devices/" + QString(ID) + "/user", name);
    }
    else
    {
        QMessageBox::warning(this, "Систеная ошибка порта USB", "Возникла ошибка. Пожалуйста, извлеките устройство и попробуйте снова.");

    }
    close();
}

bool AddNewDevToOrg::setDriveToDevice(char drive, char *ID)
{
    qDebug() << QChar(drive);
    qDebug() << "ЗДАРОВА";
    string path = "";
    path += drive;
    path += "://LOG";
    if (!FileExists(path.c_str())){
        return false;
    }
    path += "/INFO.txt";
    remove(path.c_str());
    ofstream setDiskID(path); //создать
    setDiskID << ID;
    setDiskID.close();
    return true;
}

bool AddNewDevToOrg::FileExists(const char *fname)
{
    return access(fname, 0) != -1;
}


void AddNewDevToOrg::on_radioButton_clicked()
{
    QPixmap devImg1(":/res/img/DMT_EX.png");
    int w = ui->DMT->width();
    int h = ui->DMT->height();/////////////////////////
    ui->DMT->setPixmap(devImg1.scaled(w,h,Qt::KeepAspectRatio));
}

void AddNewDevToOrg::on_radioButton_2_clicked()
{
    QPixmap devImg2(":/res/img/DMT10_.png");
    int w = ui->DMT->width();
    int h = ui->DMT->height();/////////////////////////
    ui->DMT->setPixmap(devImg2.scaled(w,h,Qt::KeepAspectRatio));
}
