#ifndef FILEMAN_H
#define FILEMAN_H

#include <QDialog>
#include <QFileSystemModel>
#include <QSettings>
#include <QListView>


#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QGraphicsVideoItem>
#include <QGridLayout>
#include <QWidget>
#include "downloadmanager.h"
#include "fileinfoforlist.h"

#include <QCalendarWidget>
namespace Ui {
class FileMan;
}

class FileMan : public QDialog
{
    Q_OBJECT

public:
    explicit FileMan(QWidget *parent = nullptr);
    ~FileMan();

private slots:

    void on_pushButton_clicked();

    void on_users_activated(const QString &arg1);
    void refrsh();

    void on_video_clicked();

    void on_image_clicked();

    void on_audio_clicked();


    void on_dateDown_clicked();


    void on_pushButton_3_clicked();

    void on_reset_clicked();


    void on_FirstDate_dateChanged(const QDate &date);

    void on_SecondDate_dateChanged(const QDate &date);

private:
    Ui::FileMan *ui;
    QFileSystemModel *model;
    QStringList subdivision, logins;
    int ind;
    QSettings settings;
    QListView *listView;
    void recursiveContentList(QDir &dir, QFileInfoList &contentList);
    QFileInfoList *listFiles;
    void refrash(QFileInfoList contentList, bool videoFlag, bool imageFlag, bool audioFlag, QString Date, int dateFlag);
    QGridLayout *layout;
    QWidget *container;
    bool videoFlag, imageFlag, audioFlag;
    QDir *parantPath;
    QString Date;
    int dateFlag;
    QDateTime dateFile;
    QString path;
    bool aund;

    QDate firstDate, secondDate, bufferDate, dateFileNotTime;

};

#endif // FILEMAN_H
