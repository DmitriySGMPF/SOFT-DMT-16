#include "sortdrives.h"
#include <QDebug>
using namespace std;


SortDrives::SortDrives(QObject *parent) : QObject(parent)
{
}

char SortDrives::getDrives(char *ID)
{
    char Buf[300]{ 0 };
            string drives = "";

            GetLogicalDriveStrings(300, LPWSTR(Buf));
            for (int i = 0; i < 300; i += 8) {
                if (isalpha(Buf[i])) {
                    drives += Buf[i];
                }
            }
            string DMT = "";
                    for (int i = 1; i < drives.length(); i++) {
                        qDebug() << i;
                        qDebug() << "Открвытый Диск";
                        string path = "";
                        path += drives[i];
                        path += "://LOG";


                        if (FileExists(path.c_str())) {

                            DMT += drives[i];
                        }

                    }

                    for (int i = 0; i < DMT.length(); i++) {
                                string path = "";
                                path += DMT[i];
                                path += "://LOG/INFO.txt";


                                string buffer;


                                ifstream INFO(path);
                                getline(INFO, buffer);
                                INFO.close();
                                if ((buffer == ID) || (DMT.length() == 1)) {
                                    drive = DMT[i];
                                    return drive;
                                }

                            }
                    qDebug() << "NOOOOOOOOO";
                    return 0;
}




bool SortDrives::FileExists(const char *fname)
{
    return access(fname, 0) != -1;
}
