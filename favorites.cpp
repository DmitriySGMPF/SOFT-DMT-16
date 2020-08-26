#include "favorites.h"
#include "ui_favorites.h"

Favorites::Favorites(QFileInfo info, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Favorites)
{
    ui->setupUi(this);
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->name->setText(info.baseName());
    //path = settings.value("setting/secondpath").toString();
    QString buffer = settings.value("setting/firstpath", "C:/Bodycam").toString();
    path = settings.value("setting/secondpath", buffer+"/izb").toString();
    ui->path->setText(path);
    this->info = info;
    radioBut = false;
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");
    setWindowTitle("Добавление в избранное");
    setWindowIcon(QIcon(":/res/img/DMT_EX.png"));
}

Favorites::~Favorites()
{
    delete ui;
}

void Favorites::on_pushButton_clicked()
{
    QFileDialog filePath;
    path = filePath.getExistingDirectory();
    ui->path->setText(path);

}

void Favorites::on_pushButton_2_clicked()
{
    if (!QDir(path).exists()){
        QDir().mkdir(path);
    }
    QString pathh = path+"/"+info.fileName();
    qDebug() << info.absoluteFilePath();
    qDebug() << pathh;
    if( !QFile::copy(info.absoluteFilePath(), path + "/" + ui->name->text()+"."+info.suffix()) )
    {
        QMessageBox::critical(this,"Ошибка","Файл с именем " + ui->name->text() + " уже существует. Файл не был скопирован.");
    }
    else
    {
        if(radioBut)
        {
           QFile::remove(info.absoluteFilePath());
           qDebug()<<"УДАЛЁН";
        }
        this->close();
    }
    //QFile::rename ( pathh, path + "/" + ui->name->text()+"."+info.suffix());
}

void Favorites::on_radioButton_clicked()
{
    if(!radioBut)
    {
        radioBut = true;
    }
    else
    {
        radioBut = false;
    }
}
