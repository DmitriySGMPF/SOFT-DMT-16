#include "fileman.h"
#include "ui_fileman.h"

FileMan::FileMan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileMan)
{
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    videoFlag = true;
    imageFlag = true;
    audioFlag = true;
    aund = false;
    dateFlag = 0;
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("DMTSOFT");

    //if (settings.value("subdivision/" + login + "/info/status").toString() == "admin"){
        //qDebug() << "DUSHKFLVFuduzhsA.";
        //path = "D:/Bodycam/";
        path = settings.value("setting/firstpath", "C:/Bodycam").toString()+"/";
        qDebug() << path;
        if (!QDir(path).exists()){
            qDebug() << "YES";
            QDir().mkdir(path);
        }
    //}

    /*
    QDir parantPath(path);
    listFiles = new QFileInfoList;

    recursiveContentList(parantPath, *listFiles);

    layout = new QGridLayout;
    container = new QWidget;
    container->setLayout(layout);
    ui->scroll->setWidget(container);



    int i = 0;
    foreach(QFileInfo diffInfo, *listFiles){
        if (diffInfo.isFile()){
            fileInfoForList *file = new fileInfoForList(&diffInfo);
            layout->addWidget(file,i,0);
            container = new QWidget;
            container -> setLayout(layout);
            ui->scroll->setWidget(container);
            i++;
        }
    }

    ind = 0;
    settings.beginGroup("devices");
    logins = settings.childGroups();
    subdivision << "Все";
    for(int i = 0; i < logins.size(); i++){
        qDebug() << logins[i];
        qDebug() << settings.value(logins[i] +"/user").toString();

        subdivision << settings.value(logins[i] +"/user").toString();
    }
    settings.endGroup();
    ui->users->addItems(subdivision);

    */
    ui->lineEdit_3->setFocus();
    setWindowTitle("Управление файлами");
    setWindowIcon(QIcon(":/res/img/DMT_EX.png"));
}

FileMan::~FileMan()
{
    delete ui;

}










void FileMan::on_pushButton_clicked()
{
    if (aund){
    //QDate date = ui->calendarWidget->selectedDate();
    //Date = date.toString("dd-MM-yy");
    dateFlag = 2;
    refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
    ui->pushButton->setStyleSheet("background-color: rgb(60, 81, 73); color: rgb(229, 223, 215); border-radius: 3px;");

    ui->dateDown->setStyleSheet("background-color: rgb(100, 95, 94); color: rgb(229, 223, 215); border-radius: 3px;");
    ui->reset->setStyleSheet("background-color: rgb(100, 95, 94); color: rgb(229, 223, 215); border-radius: 3px;");
    }
}


void FileMan::recursiveContentList(QDir &dir, QFileInfoList &contentList)
{
    foreach(QFileInfo info, dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)){
        contentList.append(info);
        qDebug() << info;
        if(info.isDir()){
            dir.cd(info.fileName());
            recursiveContentList(dir, contentList);
            dir.cdUp();
        }
    }

}

void FileMan::refrash(QFileInfoList contentList, bool videoFlag, bool imageFlag, bool audioFlag, QString Date, int dateFlag)
{
    delete layout;
    delete container;
    layout = new QGridLayout;
    container = new QWidget;
    int i = 0;
    foreach(QFileInfo diffInfo, contentList){

            if (diffInfo.isFile())
            {
                if (dateFlag == 2)
                {
                    dateFile = diffInfo.lastModified();
                }
                if (dateFlag == 1)
                {
                    dateFile = diffInfo.created();
                }

                QString strDate = dateFile.toString("dd-MM-yy");

                if (secondDate < firstDate)
                {
                    bufferDate = secondDate;
                    secondDate = firstDate;
                    firstDate = bufferDate;

                }

                if ((dateFile.date() <= secondDate) && (dateFile.date() >= firstDate) ||(dateFlag == 0)){
                    QString suff = diffInfo.suffix();
                    if ( suff == "MP4" && !videoFlag)
                    {
                        continue;
                    }
                    if ( suff == "MP3" && !audioFlag)
                    {
                        continue;
                    }
                    if ( suff == "JPEG" && !imageFlag)
                    {
                        continue;
                    }
                    fileInfoForList *file = new fileInfoForList(&diffInfo);
                    connect(file, &fileInfoForList::rfrsh, this, &FileMan::refrsh);
                    layout->addWidget(file,i,0);
                    container = new QWidget;
                    container -> setLayout(layout);
                    ui->scroll->setWidget(container);
                    i++;
                }
            }
        }
    }

void FileMan::on_users_activated(const QString &arg1)
{
    if (aund){
    delete listFiles;
    listFiles = new QFileInfoList;
    if (arg1 == "Все"){
        parantPath = new QDir(path + "/");
        listFiles = new QFileInfoList;
        recursiveContentList(*parantPath, *listFiles);
        refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
    }
    else{
        parantPath = new QDir(path + "/" + arg1 + "/");
        recursiveContentList(*parantPath, *listFiles);
        refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
    }
    }

}

void FileMan::refrsh()
{
    refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
    qDebug() << "выдшрамыдафврваааааааааааааааааааааааааааааааааааааа";
}


void FileMan::on_video_clicked()
{
    if (aund){
    if(videoFlag)
    {
        videoFlag = false;
        ui->video->setStyleSheet("background-color: red; background-image: url(:/res/img/videoIcon.png);");
    }
    else
    {
        videoFlag = true;
        ui->video->setStyleSheet("background-color: green; background-image: url(:/res/img/videoIcon.png);");
    }
    refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
    }
}

void FileMan::on_image_clicked()
{
    if (aund){
    if(imageFlag)
    {
        imageFlag = false;
        ui->image->setStyleSheet("background-color: red; background-image: url(:/res/img/photoIcon.png);");
    }
    else
    {
        imageFlag = true;
        ui->image->setStyleSheet("background-color: green; background-image: url(:/res/img/photoIcon.png);");
    }
    refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
    }
}

void FileMan::on_audio_clicked()
{
    if (aund){
    if(audioFlag)
    {
        audioFlag = false;
        ui->audio->setStyleSheet("background-color: red; background-image: url(:/res/img/audioIcon.png);");
    }
    else
    {
        audioFlag = true;
        ui->audio->setStyleSheet("background-color: green; background-image: url(:/res/img/audioIcon.png);");
    }
    refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
    }
}


void FileMan::on_dateDown_clicked()
{
    //QDate date = ui->calendarWidget->selectedDate();
    //Date = date.toString("dd-MM-yy");
    if(aund){
        dateFlag = 1;
        refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
        ui->dateDown->setStyleSheet("background-color: rgb(60, 81, 73); color: rgb(229, 223, 215); border-radius: 3px;");

        ui->pushButton->setStyleSheet("background-color: rgb(100, 95, 94); color: rgb(229, 223, 215); border-radius: 3px;");
        ui->reset->setStyleSheet("background-color: rgb(100, 95, 94); color: rgb(229, 223, 215); border-radius: 3px;");
    }
}

void FileMan::on_pushButton_3_clicked()
{
    if(!aund){
    if(ui->lineEdit_3->text() == settings.value("setting/password", "000000").toString())
    {
       dateFlag = 1;
       QDateTime todayDate = QDateTime::currentDateTime();
       ui->FirstDate->setDate(todayDate.date());
       ui->SecondDate->setDate(todayDate.date());

       ui->widget->deleteLater();
       ui->widget_2->deleteLater();
       aund = true;
       //
       QDir parantPath(path);
       listFiles = new QFileInfoList;

       recursiveContentList(parantPath, *listFiles);

       layout = new QGridLayout;
       container = new QWidget;
       container->setLayout(layout);
       ui->scroll->setWidget(container);

       refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);

        /*
       int i = 0;
       foreach(QFileInfo diffInfo, *listFiles){
           if (diffInfo.isFile()){
               fileInfoForList *file = new fileInfoForList(&diffInfo);
               layout->addWidget(file,i,0);
               container = new QWidget;
               container -> setLayout(layout);
               ui->scroll->setWidget(container);
               i++;
           }
       }*/

       ind = 0;
       settings.beginGroup("devices");
       logins = settings.childGroups();
       subdivision << "Все";
       for(int i = 0; i < logins.size(); i++){
           qDebug() << logins[i];
           qDebug() << settings.value(logins[i] +"/user").toString();

           subdivision << settings.value(logins[i] +"/user").toString();
       }
       settings.endGroup();
       ui->users->addItems(subdivision);
       ui->dateDown->setStyleSheet("background-color: rgb(60, 81, 73); color: rgb(229, 223, 215); border-radius: 3px;");
       ui->pushButton_3->setText("Успешно");
       ui->pushButton_3->setStyleSheet("background-color:green; color: rgb(229, 223, 215);");
       ui->lineEdit_3->deleteLater();
       ui->label_11->deleteLater();
    }
    else
    {
        QMessageBox::critical(this, "Неверный пароль", "Повторите вход");
    }
    }
}

void FileMan::on_reset_clicked()
{
    if(aund){
        dateFlag = 0;
        refrash(*listFiles, videoFlag, imageFlag, audioFlag, Date, dateFlag);
        ui->reset->setStyleSheet("background-color: rgb(60, 81, 73); color: rgb(229, 223, 215); border-radius: 3px;");

        ui->dateDown->setStyleSheet("background-color: rgb(100, 95, 94); color: rgb(229, 223, 215); border-radius: 3px;");
        ui->pushButton->setStyleSheet("background-color: rgb(100, 95, 94); color: rgb(229, 223, 215); border-radius: 3px;");
    }
}




void FileMan::on_FirstDate_dateChanged(const QDate &date)
{
    firstDate = date;
}

void FileMan::on_SecondDate_dateChanged(const QDate &date)
{
    secondDate = date;
}
