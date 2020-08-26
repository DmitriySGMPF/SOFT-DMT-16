#if !defined(_include_unisafty_zfy_h_)
#define _include_unisafty_zfy_h_

#if defined(WIN32)
    #pragma warning(disable : 4996)
    #if defined(ZYFLIB_EXPORTS)
        #define ZYFLIB __declspec(dllexport)
    #else
        #define ZYFLIB __declspec(dllimport)
    #endif
#else
    #define ZYFLIB
#endif

enum
{
    ERR_SUCCESS                 = 0x00, // �ɹ�
    ERR_FAILED                  = 0x01, // ʧ��
    ERR_NOTCONNECT              = 0x02, // û�������豸
    ERR_PARAM                   = 0x03, // ��������
    ERR_VERIFI_PASSWORD_FAILED  = 0x04, // ������֤ʧ��
    ERR_VERSION                 = 0x05, // ���ӳɹ������̼��汾����Ӧ��
                                        // ������GetDeviceVersion�鿴�̼����ӿڰ汾��Ӧ��ϵ
} ;

// ����
#define SWITCH_LOCK_OFF     0   // ��
#define SWITCH_LOCK_ON      1   // ��

// ͼ���ֱ���
#define SYSSET_MRES_2560X1080_P30   0
#define SYSSET_MRES_2304X1296_P30   1
#define SYSSET_MRES_1920X1080_P30   3
#define SYSSET_MRES_1440X1080_P30   4
#define SYSSET_MRES_1280X720_P60    6
#define SYSSET_MRES_1280X720_P30    7
#define SYSSET_MRES_840X480_P60     8
#define SYSSET_MRES_848X480_P30     9

// ��Ƶ�ֶ�
#define SYSSET_VIDEO_SPLIT_OFF      0
#define SYSSET_VIDEO_SPLIT_5MINS    300
#define SYSSET_VIDEO_SPLIT_10MINS   600
#define SYSSET_VIDEO_SPLIT_15MINS   900
#define SYSSET_VIDEO_SPLIT_20MINS   1200

// ͼ������
#define SYSSET_QUALITY_HIGH     0
#define SYSSET_QUALITY_MEDIUM   1
#define SYSSET_QUALITY_LOW      2

// ͼƬ��С
#define SYSSET_PHOTOSIZE_21M    2
#define SYSSET_PHOTOSIZE_16M    3
#define SYSSET_PHOTOSIZE_12M    4
#define SYSSET_PHOTOSIZE_8M     5
#define SYSSET_PHOTOSIZE_5M     6
#define SYSSET_PHOTOSIZE_3M     7

// ��Ƶ��¼
#define SYSSET_POSTRECORD_OFF       0
#define SYSSET_POSTRECORD_10S       10
#define SYSSET_POSTRECORD_20S       20
#define SYSSET_POSTRECORD_30S       30
#define SYSSET_POSTRECORD_60S       60

// ¼Ӱ����
#define SYSSET_RECORDINGWARN_OFF    0
#define SYSSET_RECORDINGWARN_10S    10
#define SYSSET_RECORDINGWARN_30S    30
#define SYSSET_RECORDINGWARN_60S    60

// �����л�
#define SYSSET_IRCUTSWITCHAUTO          0  // �Զ����غ���
#define SYSSET_IRCUTSWITCHMANUAL        1  // ���Զ��򿪺���
#define SYSSET_IRCUTSWITCHRECORDINGAUTO 2  // During Recording
// ���������� 0-10
//#define SYSSET_IR_SENSITIVITY_LOW       0   // ��
//#define SYSSET_IR_SENSITIVITY_MEDIUM    1   // ��
//#define SYSSET_IR_SENSITIVITY_HIGH      2   // ��

// ����ģʽ
#define PHOTO_BURST_OFF     0
#define PHOTO_BURST_2P      2
#define PHOTO_BURST_3P      3
#define PHOTO_BURST_5P      5


// ��ʱ����ʱ��
#define SYSSET_LCDOFF_OFF       0
#define SYSSET_LCDOFF_10S       10
#define SYSSET_LCDOFF_20S       20
#define SYSSET_LCDOFF_30S       30
#define SYSSET_LCDOFF_60S       60
#define SYSSET_LCDOFF_300S      300

// ��ʱ�ػ�ʱ��
#define SYSSET_POWEROFF_OFF     0
#define SYSSET_POWEROFF_3M      180
#define SYSSET_POWEROFF_5M      300
#define SYSSET_POWEROFF_10M     600
#define SYSSET_POWEROFF_15M     900
#define SYSSET_POWEROFF_20M     1200

// ��Ƶ��ʽ
#define TV_OUT_NTSC 0
#define TV_OUT_PAL  1
// ��Ƶ
#define REFRESH_RATE_50HZ   0 // 50Hz
#define REFRESH_RATE_60HZ   1 // 60Hz
#define REFRESH_RATE_AUTO   2 // �Զ�

// �ļ�����
#define FILE_TAGGING_NORMAL         0
#define FILE_TAGGING_TARFFIC        1
#define FILE_TAGGING_DWI            2
#define FILE_TAGGING_CONFIDENTIAL   3
#define FILE_TAGGING_CRIMINAL       4
#define FILE_TAGGING_OTHERS         5

// ���ڸ�ʽ
#define DATE_FORMAT_DMY 0 // DD-MM-YYYY
#define DATE_FORMAT_MDY 1 // MM-DD-YYYY
#define DATE_FORMAT_YMD 2 // YYYY-MM-DD

// �ļ�����
#define FILE_FORMAT_MP4 0
#define FILE_FORMAT_MOV 1

// WIFI����
#define WIFI_OFF    0
#define WIFI_AUTO   1
#define WIFI_MANUAL 2


#pragma pack(1)
// ϵͳ��������
typedef struct _tagParamInfo
{
    unsigned short mres;            // ͼ���ֱ��� ����SYSSET_MRES_*����
    unsigned short videoSplit;      // ��Ƶ�ֶΣ���SYSSET_VIDEO_SPLIT_*����
    unsigned char  quality;         // ͼ����������SYSSET_QUALITY_*����
    unsigned char  photoSize;       // ͼƬ��С,��SYSSET_PHOTOSIZE_*����
    unsigned char  videoPreRecord;  // ��ƵԤ¼����SWITCH_LOCK_*����
    unsigned char  videoPostRecord; // ��Ƶ��¼����SYSSET_POSTRECORD_*����
    unsigned char  recordingWarn;   // ¼Ӱ���ѣ���SYSSET_RECORDINGWARN_*����
    unsigned char  wifi;            // WIFI���ӣ���SWITCH_LOCK_*����
    unsigned char  mic;             // ���˷��趨����SWITCH_LOCK_*����
    unsigned char  ircutSwitch;     // ���������л�����SYSSET_IRCUTSWITCH*����
    unsigned short autoPowerOff;    // ��ʱ�ػ�����SYSSET_POWEROFF_*����
    unsigned char  tvOut;           // ϵͳ��ʽ ����SWITCH_LOCK_*
    unsigned char  refreshRate;     // ��Ƶ ����REFRESH_RATE_*
    unsigned char  beepSound;       // ���������� ����SWITCH_LOCK_*
    unsigned char  ledLight;        // ָʾ�� ����SWITCH_LOCK_*
    unsigned char  fileTagging;     // �ļ����ǣ�����FILE_TAGGING_*����
    unsigned char  dateFormat;      // ʱ�����ڸ�ʽ ����DATE_FORMAT_*����
    unsigned char  enableOSD;       // ����ˮӡ,��SWITCH_LOCK_*
    unsigned char  IRSensitivity ;  // ����������  �����ͣ������У�������
    unsigned char  Stealthmode;     // ����ģʽ  0���رգ�������������ģʽ
    unsigned char  FileFormat;      // �ļ���ʽ
    unsigned char  PowerOnAutoRecord;  // �����Զ�¼�񣬣��رգ����������Զ�¼��
    unsigned char  PreRecordMute;   // ��¼����  0���رգ���������
    unsigned char  burstMode;       // ����ģʽ����PHOTO_BURST_*����
    unsigned char  FileProtection;  // �ļ�����������������������
} PARAM_INFO, *PPARAM_INFO;


typedef struct _tagDevtm
{
    int year;   // �꣬��ǰ����
    int mon;    // �� [1,12]
    int day;    // ��  [1,31]
    int hour;   // ʱ [0,23]
    int min;    // �� [0,59]
    int sec;    // ��  [0,59]
}DEV_TM,*PDEV_TM;


#pragma pack()


#if !defined(DEV_HANDLE)
#define DEV_DEVICE void*
#define DEV_HANDLE void*
#endif

#ifdef  __cplusplus
extern "C" {
#endif
/*
���ܣ���ȡ�豸�б�
����˵����
    handle
        [in|out] handleΪһ�����飬����handleΪNULL�����������豸����
    size
        [in] handle������С
����ֵ��
    �����оٳ������豸����
*/
ZYFLIB int EnumDeviceList(DEV_DEVICE *handle, int size);
ZYFLIB int EnumStorageList(DEV_DEVICE *handle, int size);
/*
���ܣ��ͷ��б���Դ
����˵����
    handle
        [in] EnumDeviceList��EnumStorageListö�ٳ������豸����
    size
        [in] EnumDeviceList��EnumStorageListö�ٳ����豸����ֵ������
����ֵ��
    ����ֵΪ�������κ�����
*/
ZYFLIB int ReleaseList(DEV_DEVICE *handle, int size);
/*
���ܣ������豸
����˵����
    cDrv
        [in]
            �豸�̷��ţ���'H'
    devDevice
        [in] ��EnumDeviceList��EnumStorageList��ȡ���豸�б�
    handle
        [in|out] �������ӳɹ������豸���������Ժ��ĺ���������Ҫ�õ�
����ֵ��
    �ɹ���ERR_SUCCESS���������������б�
������
    ConnectDevice��ConnectStorageDevice���������ڣ��ú�����ͨ����EnumDeviceList��EnumStorageListö�ٳ������豸�������ӣ�
    ��ConnectStorageDevice��ͨ�����̵ķ�ʽ�����豸��������������ʵ����Ҫ��ѡһ��
*/
ZYFLIB int ConnectDevice(DEV_DEVICE devDevice, DEV_HANDLE *handle);
ZYFLIB int ConnectStorageDevice(char cDrv, DEV_HANDLE *handle);
/*
���ܣ��Ͽ����豸������
����˵����
    handle
        [in] ��ConnectDevice��ConnectStorageDevice���ӳɹ��󷵻ص��豸����
����ֵ��
    ����ֵ��ERR_SUCCESS
*/
ZYFLIB int CloseDevice(DEV_HANDLE handle);
/*
���ܣ���ȡ�豸�汾��Ϣ
����˵����
    handle
        [in] ��ConnectDevice��ConnectStorageDevice���ӳɹ��󷵻ص��豸����
    pVersion
        [in|out] �̼��汾�ţ���ʽ��V����_WIFI_GPS_Ӳ���汾
����ֵ��
    ������������
*/
ZYFLIB int GetDeviceVersion(DEV_HANDLE handle, char *pVersion);
// ��λ�豸����
ZYFLIB int ResetDevice(DEV_HANDLE handle);
/*
���ܣ���ȡ/����/��֤����
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    chPsw
        [in|out] Ҫ���û���ȡ���������ַ���
    userType
        [in] �������ͣ�0:һ���û���1:����Ա
����ֵ��
    ������������
*/
ZYFLIB int SetPassword(DEV_HANDLE handle, char *cszPsw, int userType);
ZYFLIB int VerifiPassword(DEV_HANDLE handle, char *cszPsw, int userType);
/*
���ܣ���ȡʱ��
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    DateTime
        [in] DateTime: ������/��/��/ʱ/��/����Ϣ������DEV_TM
����ֵ��
    ������������
��ע��
*/
ZYFLIB int GetTime(DEV_HANDLE handle, PDEV_TM DateTime);
// ͬ��ʱ��
ZYFLIB int SyncDateTime(DEV_HANDLE handle);


/*
���ܣ���ȡ/�����û����ź��豸����
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    chUserID
        [in|out] �û������ַ���.
    csUserName
        [in|out] �û�����
    chDevID:
        [in|out] �豸�����ַ���.
����ֵ��
    ������������
*/

ZYFLIB int GetUserDevID(DEV_HANDLE handle, char *cszUserID, char *csUserName, char *cszDevID);
ZYFLIB int SetUserDevID(DEV_HANDLE handle, char *cszUserID, char *csUserName, char *cszDevID);

ZYFLIB int GetDeptInfo(DEV_HANDLE handle, char *deptCode, char *deptName);
ZYFLIB int SetDeptInfo(DEV_HANDLE handle, char *deptCode, char *deptName);
/*
���ܣ���ȡ/����ϵͳ����
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
����ֵ��
    ������������
*/
ZYFLIB int GetSysParam(DEV_HANDLE handle, PPARAM_INFO param);
ZYFLIB int SetSysParam(DEV_HANDLE handle, PPARAM_INFO param);

/*
���ܣ���ȡ/����WIFI��Ϣ
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
����ֵ��
    ������������
*/
ZYFLIB int GetWifiInfo(DEV_HANDLE handle, char *cszWifiSSID, char *cszWifiPwd);
ZYFLIB int SetWifiInfo(DEV_HANDLE handle, char *cszWifiSSID, char *cszWifiPwd);


/*
���ܣ���ȡ����
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    uBattery
        [in|out] ���ص���ֵ��ȡֵ��0-100
����ֵ��
    ������������
*/
ZYFLIB int GetBattery(DEV_HANDLE handle, unsigned short *uBattery);
/*
���ܣ�תUSB
����˵����
����ֵ��
    ������������
*/
ZYFLIB int SetMSCMode(DEV_HANDLE handle);

/*
���ܣ���ȡ����ID��.
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
����ֵ��
    ������������
*/
ZYFLIB int GetModelID(DEV_HANDLE handle, char *cszModelID);
ZYFLIB int SetModelID(DEV_HANDLE handle, char *cszModelID);
/*
���ܣ�������.
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    cszBarCode
        [in] ��ȡ�����õ�����ֵ
����ֵ��
    ������������
*/
ZYFLIB int GetBarCode(DEV_HANDLE handle, char *cszBarCode);
/*
���ܣ������̿ռ���Ϣ.
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    totalSize
        [in|out] ����������
    freeSize
        [in|out] ���̿�������
����ֵ��
    ������������
*/
ZYFLIB int GetDiskSpaceInfo(DEV_HANDLE handle, unsigned long *totalSize, unsigned long *freeSize);
/*
���ܣ����ö�ȡMAC��ַ.
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    mac
        [in|out] MAC��ַ
����ֵ��
    ������������
*/
ZYFLIB int GetMacAddress(DEV_HANDLE handle, char *mac);

// �����ػ�/����
ZYFLIB int SetCameraShutdown(DEV_HANDLE handle);
ZYFLIB int CameraReboot(DEV_HANDLE handle);
/*
���ܣ����û���ȡ�ڴ�����״̬.
����˵����
    handle
        [in] ��ConnectDevice���ӳɹ��󷵻ص��豸����
    lock
        [in|out] 1:������������0:δ����������
����ֵ��
    ������������
*/
ZYFLIB int SetLockMemoryState(DEV_HANDLE handle, int lock, char *pwd);
ZYFLIB int GetLockMemoryState(DEV_HANDLE handle, int *lock);

#ifdef  __cplusplus
}
#endif

#endif
