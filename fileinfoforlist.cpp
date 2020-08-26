#include "fileinfoforlist.h"
#include "ui_fileinfoforlist.h"
#include <QDateTime>
fileInfoForList::fileInfoForList(QFileInfo *thisFile, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fileInfoForList)
{
    ui->setupUi(this);
    QDateTime filee = thisFile->lastModified();
    QString textDate = filee.toString();
    //qDebug() << textDate;
    ui->path->setText(textDate);
    this->thisFile = *thisFile;
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");


    if (settings.value("fileman/seestatus/" + this->thisFile.fileName()).toBool() == true){
        ui->widget->setStyleSheet("#widget { background-color: rgb(0, 0, 0);}");
    }
    if (settings.value("fileman/lastFile").toString() == this->thisFile.fileName()){
        ui->widget->setStyleSheet("#widget { background-color: rgb(80, 90, 90);}");
    }
    if (settings.value("fileman/izbstatus/" + this->thisFile.fileName()).toBool() == true){
        ui->widget->setStyleSheet("#widget { background-color: rgb(0, 155, 73);}");
    }

}

fileInfoForList::~fileInfoForList()
{
    delete ui;
}

void fileInfoForList::on_open_clicked()
{
    QString path = thisFile.filePath();
    qDebug() << path;
    thisFile.fileName();
    //QDesktopServices::openUrl(QUrl(path));
    QDesktopServices::openUrl( QUrl::fromLocalFile(path) );
    settings.setValue("fileman/lastFile",thisFile.fileName());
    settings.setValue("fileman/seestatus/" +thisFile.fileName(),thisFile.fileName());
    ui->widget->setStyleSheet("#widget { background-color: rgb(80, 90, 90);}");
}

void fileInfoForList::on_save_clicked()
{
    settings.setValue("fileman/izbstatus/" +thisFile.fileName(),thisFile.fileName());
    ui->widget->setStyleSheet("#widget { background-color: rgb(0, 155, 73);}");
    Favorites fav(thisFile);
    fav.setModal(true);
    fav.exec();
}
