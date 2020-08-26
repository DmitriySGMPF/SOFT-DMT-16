#ifndef SORTDRIVES_H
#define SORTDRIVES_H

#include <QObject>
#include <io.h>
#include <windows.h>
#include <fstream>

class SortDrives : public QObject
{
    Q_OBJECT
public:
    explicit SortDrives(QObject *parent = nullptr);
    char getDrives(char *ID);

signals:

private:
    bool FileExists(const char* fname);
    char drive;
    char *ID;
};

#endif // SORTDRIVES_H
