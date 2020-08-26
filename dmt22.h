#if !defined(_include_unisafty_dmt22_h_)
#define _include_unisafty_dmt22_h_

#if defined(WIN32)
    #pragma warning(disable : 4996)
    #if defined(DMT12_EXPORTS)
        #define ZYFLIB __declspec(dllexport)
    #else 
        #define ZYFLIB __declspec(dllimport)
        #if defined(DEBUG)
            #pragma comment(lib,"D:/dmt10.lib") 
            #pragma message("Automatically linking Debug with dmt22.dll")
        #else
            #pragma comment(lib,"D:/dmt10.lib") 
            #pragma message("Automatically linking Release with dmt22.dll")
        #endif
    #endif
#else
    #define ZYFLIB
#endif

//  BASE_DMT为开发版
// M-VIEW和不用是两个不同版本
// 主要屏掉几个参数，与m_VIEW组合
//#define  CHINA 1
#define BASE_DMT 1
//#define M_VIEW 1

enum
{
    ERR_SUCCESS                 = 0x00, // 成功
    ERR_FAILED                  = 0x01, // 失败
    ERR_NOTCONNECT              = 0x02, // 没有连接设备
    ERR_PARAM                   = 0x03, // 参数错误
    ERR_VERIFI_PASSWORD_FAILED  = 0x04, // 密码验证失败
    ERR_VERSION                 = 0x05, // 连接成功，但固件版本不对应，
    ERR_VERIFI_PAS_MAX_NUMBER   = 0x06, // 密码验证错误次数太多。请3分钟后重试
	ERR_UNSPUPPORT_CMD = 0x07, // 不支持的命令
	ERR_DISK_OPEND = 0x08,//磁盘已打开
                                        // 请调用GetDeviceVersion查看固件与接口版本对应关系
} ;

// 开关
#define SWITCH_LOCK_OFF     0   // 关
#define SWITCH_LOCK_ON      1   // 开

// 图像分辨率
#define SYSSET_MRES_3840X2160_P30       0
#define SYSSET_MRES_2560X1140_P30       1
#define SYSSET_MRES_2304X1296_P30       2
#define SYSSET_MRES_1920X1080_P120      3
#define SYSSET_MRES_1920X1080_P100      4
#define SYSSET_MRES_1920X1080_P60       5
#define SYSSET_MRES_1920X1080_P30       6
#define SYSSET_MRES_1440X1080_P30       7
#define SYSSET_MRES_1280X720_P240       8
#define SYSSET_MRES_1280X720_P200       9
#define SYSSET_MRES_1280X720_P60        10
#define SYSSET_MRES_1280X720_P30        11
#define SYSSET_MRES_848X480_P60         12
#define SYSSET_MRES_848X480_P30         13
#define SYSSET_MRES_640X480_P30         14

// 图像质量
#define SYSSET_QUALITY_HIGH     0       // 高
#define SYSSET_QUALITY_MEDIUM   1       // 中
#define SYSSET_QUALITY_LOW      2       // 低

// 子码图像分辨率
#define SYSSET_SMRES_1920X1080_P30       0
#define SYSSET_SMRES_1280X720_P30        1
#define SYSSET_SMRES_848X480_P30         2
#define SYSSET_SMRES_432X240_P30         3
/*#define SYSSET_SMRES_1920X1080_P24       1
#define SYSSET_SMRES_1280X720_P30        2
#define SYSSET_SMRES_1280X720_P24        3
#define SYSSET_SMRES_768X432_P30         4
#define SYSSET_SMRES_576X320_P30         5*/

// 实时流
#define SYSSET_REAL_TIME_STREAM_OFF     0   // 关闭
#define SYSSET_REAL_TIME_STREAM_AUDIO   1   // 音频
#define SYSSET_REAL_TIME_STREAM_VIDEO   2   // 视频
#define SYSSET_REAL_TIME_STREAM_AV      3   // 音视频
#define SYSSET_REAL_TIME_STREAM_TEXT    4   // 文本
#define SYSSET_REAL_TIME_STREAM_ALL     5   // 音视频


// 视频分段
#define SYSSET_VIDEO_SPLIT_OFF      0
#define SYSSET_VIDEO_SPLIT_1MINS    1
#define SYSSET_VIDEO_SPLIT_2MINS    2
#define SYSSET_VIDEO_SPLIT_3MINS    3
#define SYSSET_VIDEO_SPLIT_5MINS    4
#define SYSSET_VIDEO_SPLIT_10MINS   5
#define SYSSET_VIDEO_SPLIT_15MINS   6	
#define SYSSET_VIDEO_SPLIT_20MINS   7
#define SYSSET_VIDEO_SPLIT_30MINS   8

// 视频预录
#define SYSSET_VIDEO_PRE_RECORD_OFF     0
#define SYSSET_VIDEO_PRE_RECORD_5S      1
#define SYSSET_VIDEO_PRE_RECORD_10S     2
#define SYSSET_VIDEO_PRE_RECORD_15S     3
#define SYSSET_VIDEO_PRE_RECORD_20S     4
#define SYSSET_VIDEO_PRE_RECORD_30S     5
#define SYSSET_VIDEO_PRE_RECORD_60S     6
#define SYSSET_VIDEO_PRE_RECORD_120S    7

// 视频延录
#define SYSSET_POST_RECORD_OFF       0
#define SYSSET_POST_RECORD_5S        1
#define SYSSET_POST_RECORD_10S       2
#define SYSSET_POST_RECORD_20S       3
#define SYSSET_POST_RECORD_30S       4
#define SYSSET_POST_RECORD_60S       5

// 录影静音
#define SYSET_VIDEO_MUTE_OFF            0
#define SYSET_VIDEO_MUTE_ON             1
#define SYSET_VIDEO_MUTE_PRE_RECORD     2   // 仅预录

// 录影提醒
#define SYSSET_RECORDING_WARN_OFF   0
#define SYSSET_RECORDING_WARN_5S    1
#define SYSSET_RECORDING_WARN_10S   2
#define SYSSET_RECORDING_WARN_15S   3
#define SYSSET_RECORDING_WARN_30S   4
#define SYSSET_RECORDING_WARN_60S   5

// 图片大小
#define SYSSET_PHOTO_SIZE_42M    0
#define SYSSET_PHOTO_SIZE_28M    1
#define SYSSET_PHOTO_SIZE_21M    2
#define SYSSET_PHOTO_SIZE_16M    3
#define SYSSET_PHOTO_SIZE_12M    4
#define SYSSET_PHOTO_SIZE_8M     5
#define SYSSET_PHOTO_SIZE_5M     6
#define SYSSET_PHOTO_SIZE_4M     7
#define SYSSET_PHOTO_SIZE_3M     8
#define SYSSET_PHOTO_SIZE_30M    9
#define SYSSET_PHOTO_SIZE_40M    10


// 连拍模式
#define PHOTO_BURST_OFF     0
#define PHOTO_BURST_2PCS    1
#define PHOTO_BURST_3PCS    2
#define PHOTO_BURST_5PCS    3
#define PHOTO_BURST_10PCS   4
#define PHOTO_BURST_15PCS   5
#define PHOTO_BURST_20PCS   6
#define PHOTO_BURST_30PCS   7

// 自拍模式
#define PHOTO_SELFIE_OFF    0
#define PHOTO_SELFIE_3S     1
#define PHOTO_SELFIE_5S     2
#define PHOTO_SELFIE_10S    3

// 间隔拍照
#define PHOTO_INTERVAL_SHOOTING_OFF     0
#define PHOTO_INTERVAL_SHOOTING_500MS   1
#define PHOTO_INTERVAL_SHOOTING_1S      2
#define PHOTO_INTERVAL_SHOOTING_3S      3
#define PHOTO_INTERVAL_SHOOTING_5S      4
#define PHOTO_INTERVAL_SHOOTING_10S     5

// 光频
#define SYSSET_REFRESH_RATE_AUTO    0 // 自动
#define SYSSET_REFRESH_RATE_60HZ    1 // 60Hz
#define SYSSET_REFRESH_RATE_50HZ    2 // 50Hz

// 电视输出
#define OUTPUT_TV_NTSC  0
#define OUTPUT_TV_PAL   1

// 自动屏幕保护
#define AUTO_SCREENSAVER_OFF    0
#define AUTO_SCREENSAVER_10S    1
#define AUTO_SCREENSAVER_30S    2
#define AUTO_SCREENSAVER_1MINS  3
#define AUTO_SCREENSAVER_3MINS  4
#define AUTO_SCREENSAVER_5MINS  5


// 日期格式
#define DATE_FORMAT_YMD 0 // YYYY-MM-DD
#define DATE_FORMAT_DMY 1 // DD-MM-YYYY
#define DATE_FORMAT_MDY 2 // MM-DD-YYYY

// 文件标记
#define FILE_TAGGING_NORMAL         0
#define FILE_TAGGING_TRAFFIC        1   // 交警
#define FILE_TAGGING_DWI            2   // DWI
#define FILE_TAGGING_CONFIDENTIAL   3   // 机密
#define FILE_TAGGING_CRIMINAL       4   // 刑事
#define FILE_TAGGING_OTHERS         5   // 其它


// 红外切换
#define SYSSET_IRCUT_SWITCH_OFF         0  // 自动开关红外
#define SYSSET_IRCUT_SWITCH_MANUAL      1  // 不自动打开红外
#define SYSSET_IRCUT_SWITCH_RECORDING   2  // During Recording
#define SYSSET_IRCUT_SWITCH_AUTO        3  // 自动

// 定时关机时间
#define SYSSET_POWEROFF_OFF     0
#define SYSSET_POWEROFF_30S     1
#define SYSSET_POWEROFF_1MINS   2
#define SYSSET_POWEROFF_3MINS   3
#define SYSSET_POWEROFF_5MINS   4
#define SYSSET_POWEROFF_10MINS  5
#define SYSSET_POWEROFF_30MINS  6

// 语言
#define SYSSET_LANGUAGE_ENGLISH             0 // 英文
#define SYSSET_LANGUAGE_SIMPLIFIED_CHINESE  1 // 简体中文
#define SYSSET_LANGUAGE_TRADITIONAL_CHINESE 2 // 繁体中文

// 回放模式
#define SYSSET_PLAYBACK_UNICAST         0 // 单播
#define SYSSET_PLAYBACK_UPLAY_ALL       1 // 播放所有
#define SYSSET_PLAYBACK_LOOP_UNICAST    2 // 循环单播
#define SYSSET_PLAYBACK_UPLAY_LOOP_ALL  3 // 循环播放所有 

// WIFI设置
#define SYSSET_WIFI_OFF    0 // 关闭
#define SYSSET_WIFI_AUTO   1 // 自动
#define SYSSET_WIFI_MANUAL 2 // 手动

// wifi模式
#define SYSSET_WIFI_MODE_HOTSPOT    0 // 热点
#define SYSSET_WIFI_MODE_STA    1 // 直连
#define SYSSET_WIFI_MODE_P2P    2 // 客户端

// wifi超时连接
#define	SYSSET_WIFI_CONNECT_TIMEOUT_OFF		0
#define	SYSSET_WIFI_CONNECT_TIMEOUT_1MIN	1
#define	SYSSET_WIFI_CONNECT_TIMEOUT_3MINS	2
#define	SYSSET_WIFI_CONNECT_TIMEOUT_5MINS	3
#define	SYSSET_WIFI_CONNECT_TIMEOUT_10MINS	4
#define	SYSSET_WIFI_CONNECT_TIMEOUT_30MINS	5

// 蓝牙设置
#define SYSSET_BLUETOOTH_OFF    0 // 关闭
#define SYSSET_BLUETOOTH_AUTO   1 // 开机自动启动
#define SYSSET_BLUETOOTH_MANUAL 2 // 手动

// 4g设置
#define SYSSET_4G_OFF    0 // 关闭
#define SYSSET_4G_AUTO   1 // 开机自动启动
#define SYSSET_4G_MANUAL 2 // 手动

#define SYSSET_VOICE_REMINDING_OFF      0   // 关闭
#define SYSSET_VOICE_REMINDING_BEEP     1   // 响铃
#define SYSSET_VOICE_REMINDING_SPEECH   2   // 语音

// 生成PIN Code源
#define SYSSET_GENERATED_PINCODE_BWC            0   // 相机生成
#define SYSSET_GENERATED_PINCODE_OTHER_DEVICE   1   // 其它设备生成

//  Streaming Bitrate
#define SYSSET_STREAMING_BITRATE_5000KBS    0
#define SYSSET_STREAMING_BITRATE_4000KBS    1
#define SYSSET_STREAMING_BITRATE_3000KBS    2
#define SYSSET_STREAMING_BITRATE_2000KBS    3
#define SYSSET_STREAMING_BITRATE_1000KBS    4
#define SYSSET_STREAMING_BITRATE_500KBS     5
#define SYSSET_STREAMING_BITRATE_300KBS     6

// Web Server
typedef enum SYSSET_WEB_SERVER
{
    SYSSET_WEB_SERVER_OFF = 0x0,
    SYSSET_WEB_SERVER_HTTP,
    SYSSET_WEB_SERVER_HTTPS,
    SYSSET_WEB_SERVER_HTTP_HTTPS
} SYSSET_WEB_SERVER;

// Data Encryption
typedef enum SYSSET_DATA_ENCRYPTION
{
    SYSSET_DATA_ENCRYPTION_OFF = 0x0,
    SYSSET_DATA_ENCRYPTION_FILE,
    SYSSET_DATA_ENCRYPTION_STREAMING,
    SYSSET_DATA_ENCRYPTION_BOTH
} SYSSET_DATA_ENCRYPTION;

// Charge State
typedef enum SYSSET_CHARGE_STATE
{
    SYSSET_CHARGE_STATE_OFF = 0x0,
    SYSSET_CHARGE_STATE_NORMAL,
    SYSSET_CHARGE_STATE_FAST
} SYSSET_CHARGE_STATE;

// 编码格式
typedef enum SYSSET_ENCODING_FORMAT
{
    SYSSET_ENCODING_FORMAT_H264 = 0x0,
    SYSSET_ENCODING_FORMAT_H265,
} SYSSET_ENCODING_FORMAT;

// 双击录影
typedef enum SYSSET_DOUBLE_CLICK_RECORD
{
	SYSSET_DOUBLE_CLICK_RECORD_OFF = 0x0,
	SYSSET_DOUBLE_CLICK_RECORD_ON,
} SYSSET_DOUBLE_CLICK_RECORD;

typedef enum SYSSET_NETWORK_PROTOCOL
{
    SYSSET_NETWORK_PROTOCOL_OFF = 0x0,
    SYSSET_NETWORK_PROTOCOL_ONVIF,
    SYSSET_NETWORK_PROTOCOL_CMSV,
    SYSSET_NETWORK_PROTOCOL_28181
} SYSSET_NETWORK_PROTOCOL;

typedef enum  SYSSET_NETWORK_SERVER_AREA {
	CHINA_SERVER_AREA = 0,
	AMERICA_SERVER_AREA = 1,
	ARGENTINA_SERVER_AREA = 2,
	AUSTRALIA_SERVER_AREA = 3,
	BAHAMAS_SERVER_AREA = 4,
	BANGLADESH_SERVER_AREA = 5,
	BELGIUM_SERVER_AREA = 6,
	BRAZIL_SERVER_AREA = 7,
	CAMBODIA_SERVER_AREA = 8,
	CANADA_SERVER_AREA = 9,
	CHILE_SERVER_AREA = 10,
	COLOMBIA_SERVER_AREA = 11,
	CONGO_SERVER_AREA = 12,
	COSTA_RICA_SERVER_AREA = 13,
	EL_SALVADOR_SERVER_AREA = 14,
	FINLAND_SERVER_AREA = 15,
	FRANCE_SERVER_AREA = 16,
	GERMANY_SERVER_AREA = 17,
	GUATEMALE_SERVER_AREA = 18,
	HONDURAS_SERVER_AREA = 19,
	HK_SERVER_AREA = 20,
	HUNGARY_SERVER_AREA = 21,
	INDIA_SERVER_AREA = 22,
	INDONESIA_SERVER_AREA = 23,
	IRELAND_SERVER_AREA = 24,
	ISRAEL_SERVER_AREA = 25,
	ITALY_SERVER_AREA = 25,
	IVORY_COAST_SERVER_AREA = 26,
	KAZAKHSTAN_SERVER_AREA = 27,
	NETHERLANDS_SERVER_AREA = 28,
	NEW_ZEALAND_SERVER_AREA = 29,
	NIGERIA_SERVER_AREA = 30,
	MALAYSIA_SERVER_AREA = 31,
	MEXICO_SERVER_AREA = 32,
	MYANMAR_SERVER_AREA = 33,
	PANAMA_SERVER_AREA = 34,
	PHILIPPINES_SERVER_AREA = 35,
	POLAND_SERVER_AREA = 36,
	RUSSIA_SERVER_AREA = 37,
	SINGAPORE_SERVER_AREA = 38,
	SOUTH_AFRICA_SERVER_AREA = 39,
	SOUTH_KOREA_SERVER_AREA = 40,
	SPAIN_SERVER_AREA = 41,
	SRI_LANKA_SERVER_AREA = 42,
	SWEDEN_SERVER_AREA = 43,
	SWITZERLAND_SERVER_AREA = 44,
	TAIWAN_SERVER_AREA = 45,
	THAILAND_SERVER_AREA = 46,
	UNITED_KINGDOM_SERVER_AREA = 47,
	VIETNAM_SERVER_AREA = 48,
	USER_DEFINED_SERVER_AREA = 49,
	CLOUD_DMS_SERVER_AREA_NUM
}SYSSET_NETWORK_SERVER_AREA;

typedef enum SYSSET_STREAMING_FRAME_RATE
{
	SYSSET_STREAMING_FRAME_RATE_5FPS = 0x0,
	SYSSET_STREAMING_FRAME_RATE_10FPS,
	SYSSET_STREAMING_FRAME_RATE_15FPS,
	SYSSET_STREAMING_FRAME_RATE_20FPS,
	SYSSET_STREAMING_FRAME_RATE_25FPS,
	SYSSET_STREAMING_FRAME_RATE_30FPS
} SYSSET_STREAMING_FRAME_RATE;

typedef enum SYSSET_VIDEO_EIS
{
	SYSSET_VIDEO_EIS_OFF = 0x0,
	SYSSET_VIDEO_EIS_ON
} SYSSET_VIDEO_EIS;

#pragma pack(1)
// 系统参数定义
typedef struct _tagParamInfo
{
	unsigned char  mres;            // 图像分辨率 ，见SYSSET_MRES_*定义
	unsigned char  quality;         // 图像质量，见SYSSET_QUALITY_*定义
	unsigned char  secondMres;      // 子图像分辨率，见SYSSET_SMRES_*定义
	//unsigned char  sencodQuality;   // 子图像质量，见SYSSET_QUALITY_*定义
	unsigned char  realStream;      // 时实流控制，SYSSET_REAL_TIME_STREAM_
	//unsigned char  dubStream;       // 双码流，SWITCH_LOCK_
	unsigned char  loopRecord;      // 循环录像，SWITCH_LOCK_
	unsigned char  videoSplit;      // 视频分段，见SYSSET_VIDEO_SPLIT_*定义
	unsigned char  videoPreRecord;  // 视频预录，见SWITCH_LOCK_*定义
	unsigned char  videoPostRecord; // 视频延录，见SYSSET_POST_RECORD_*定义
	unsigned char  videoMute;       // 录影静音，SYSET_VIDEO_MUTE_
	unsigned char  recordingWarn;   // 录影提醒，见SYSSET_RECORDINGWARN_*定义
	unsigned char  autoRecord;      // 自动录影，SWITCH_LOCK_
	unsigned char  autoDetection;   // 自动侦测，SWITCH_LOCK_

	unsigned char  photoSize;       // 图片大小，见SYSSET_PHOTO_SIZE_*定义
	unsigned char  photoQuality;    // 图片质量，SYSSET_QUALITY_
	unsigned char  burstMode;       // 连拍模式，见PHOTO_BURST_*定义
	unsigned char  selfie;          // 自拍模式，PHOTO_SELFIE_
	unsigned char  IntervalShooting;// 间隔拍照，PHOTO_INTERVAL_SHOOTING_

	unsigned char  refreshRate;     // 光频 详见SYSSET_REFRESH_RATE_*

	unsigned char  outputTV;        // 电视输出，OUTPUT_TV_
	unsigned char  brightness;      // 屏幕亮度，0->9表示1->10
	unsigned char  autoAdjustBright;// 自动调节屏幕亮度，SWITCH_LOCK_
	unsigned char  autoScreensaver; // 自动屏幕保护，AUTO_SCREENSAVER_
	unsigned char  keyTone;         // 按键音 SWITCH_LOCK_
	unsigned char  volume;          // 音量，0-10
	unsigned char  voiceReminding;  // 声音提醒，SWITCH_LOCK_

	unsigned char  ledLight;        // LED灯，SWITCH_LOCK_
	unsigned char  clockBeep;       // 时钟播报，SWITCH_LOCK_
	unsigned char  cardMode;        // 车载模式，SWITCH_LOCK_
	unsigned char  dateFormat;      // 时间日期格式 详见DATE_FORMAT_*定义
	unsigned char  fileTagging;     // 文件标记,FILE_TAGGING_
	unsigned char  location;        // 定位服务，SWITCH_LOCK_
	unsigned char  autoSyncTime;    // 自动同步时间,SWITCH_LOCK_
	unsigned char  timeZone;        // 时区，0-48,从-12->,12每0.5为一个时区
	unsigned char  shockReminding;  // 震动提醒，SWITCH_LOCK_
	unsigned char  ircutSwitch;     // 红外滤光切换，SYSSET_IRCUT_SWITCH_
	unsigned char  ircutSensitivity;     // 红外滤光切换灵敏度
	unsigned char  autoPowerOff;    // 定时关机，见SYSSET_POWEROFF_*定义
	unsigned char  Stealthmode;     // 秘密模式， SWITCH_LOCK_
	unsigned char  language;        // 语言，YSSET_LANGUAGE_
	unsigned char  standby;         // 待机,SWITCH_LOCK_
	unsigned char  playback;        // 回放模式， SYSSET_PLAYBACK_
    unsigned char  StreamingBitrate;// 见SYSSET_STREAMING_BITRATE_ 
    unsigned char  WebServer;       // 见SYSSET_WEB_SERVER_
    unsigned char  WatermarkLogo;   // 见SWITCH_LOCK_
    unsigned char  ChargeState;     // Charge State详见SYSSET_CHARGE_STATE
    unsigned char  EncodingFormat;  // 编码格式，详见SYSSET_ENCODING_FORMAT
	unsigned char  StreamingFrameRate;//实时流帧率，详见SYSSET_STREAMING_FRAME_RATE
	unsigned char  VideoEIS;		//防抖，详见SYSSET_VIDEO_EIS
    unsigned char  memoryWarning;   // 内存警告
    unsigned char  electricWarning; // 电量警告
	unsigned char  DoubleClickRecord; //双击录影
} PARAM_INFO, *PPARAM_INFO;

// NetWork设置
typedef struct CMD_NETWORK_INFO
{
	char DeviceName[32];
	unsigned char ProtocolType;
	unsigned char ServerArea;
	char ServerURL[16];
	char ServerIP[16];
	char ServerPort[8];
	char Account[16];
	char PassWord[16];
} CMD_NETWORK_INFO, *P_CMD_NETWORK_INFO;

typedef struct _tagDevtm
{
    int year;   // 年，当前年份
    int mon;    // 月 [1,12] 
    int day;    // 日 [1,31] 
    int hour;   // 时 [0,23] 
    int min;    // 分 [0,59] 
    int sec;    // 秒 [0,59]
}DEV_TM,*PDEV_TM;

// 夏令时间设置
typedef struct _tagSUMMER_TIME_INFO
{
    unsigned char summerTime;   // 1:夏令时间，其它或0非夏令时间
    unsigned char autoSyncTime; // 自动更新时间
    unsigned char startMonth;   // 夏令时开始月
    unsigned char startWeek;    // 夏令时开始周
    unsigned char startHour;    // 夏令时开始时间
    unsigned char endMonth;     // 夏令时结束时月
    unsigned char endWeek;      // 夏令时结束周
    unsigned char endHour;      // 夏令时结束时间
} SUMMER_TIME_INFO, *PSUMMER_TIME_INFO;
/*
// WIFI信息
typedef struct WIFI_INFO
{
    unsigned char ssid[32]; // WIFI SSID； wifi模式为SYSSET_WIFI_MODE_HOTSPOT：时表示热点，
                            // wifi模式为SYSSET_WIFI_MODE_STA时，表示客户端
    unsigned char pwd[32];  // WIFI密码
    unsigned char DirectPIN[32];   // 直连PIN码
    unsigned char PINCodeGeneratingSource;  // 0：BWC Generated PinCode(相机生成)1:Other Device Generated PinCode（其它设备生成）
    unsigned char  wifi;            // WIFI连接，启动方式，见SYSSET_WIFI_*定义
    unsigned char  wifimode;        // wifi模式，SYSSET_WIFI_MODE_
    unsigned char  route;           // WIFI通道 选择，0：2.4G，1：5G
    unsigned char  selRoute24;      // WIFI信道参数,0：自动，1-13分别表示1-13
    unsigned char  selRoute5;       // WIFI信道参数 0：自动，1:36,2:40,3:44, 4:48,5:52,6:56,7:60,8:64,9:100
                                    //            10:104,11:108,12:112,13:116,14:120,15:124,16:128
                                    //            17:132,18:136,19:140,20:149,21:153,22:157,23:161,24:165
} WIFI_INFO, *PWIFI_INFO;
*/
// wifi的通用设置
typedef struct WIFI_UNIVERSAL_INFO
{
	char start_mode; // WIFI启动方式：off ,auto ,manual.，详见SYSSET_WIFI_
	char work_mode; // WIFIa工作模式：ap, sta,p2p	，详见SYSSET_WIFI_MODE_
	char SecurityConnectTimeout;
	char mac[32];   // mac地址
	char ip[16];   // ip地址
	char Gateway[16];  // 网关
} WIFI_UNIVERSAL_INFO, *PWIFI_UNIVERSAL_INFO;

typedef struct WIFI_CHANNEL_INFO
{
    unsigned char route24[14]; // 0：自动，1 - 13分别表示1 - 13
    unsigned char rount5[25];  // 0：自动，1:36,2:40,3:44, 4:48,5:52,6:56,7:60,8:64,9:100
                               // 10:104,11:108,12:112,13:116,14:120,15:124,16:128
                               // 17:132,18:136,19:140,20:149,21:153,22:157,23:161,24:165
} WIFI_CHANNEL_INFO, *PWIFI_CHANNEL_INFO;

typedef struct WIFI_AP_SETTING
{
    char ssid[16];              // ap 的ssid
    char pwd[32];               // ap 的密码
    char link_number;           //  ap 热点的个数，取值(1-5)
    char channel_sel;           //  ap通道选择，选择，0：2.4G，1：5G
    unsigned char  channel; //  WIFI信道参数  ，详见WIFI_CHANNEL_INFO
} WIFI_AP_SETTING, *PWIFI_AP_SETTING;

// sta模式设置当前要连接的热点
typedef struct WIFI_STA_SETTING_CUR_SSID
{
	char cur_ssid[16];      // 热点的ssid
	char cur_pwd[32];       // 热点的password
	char AutoGetIP;			//DHCP自动获取IP
} WIFI_STA_SETTING_CUR_SSID, *PWIFI_STA_SETTING_CUR_SSID;

// sta模式已连接过的热点 （这个成员里的值，由相机上传给上位机）
typedef struct WIFI_STA_LIST_INFO
{
    char ssid_list_cnt; // 已连接过热点的个数
    char ssid_list[5][16]; // 保存已连接过的热点 （以List形式）	
} WIFI_STA_LIST_INFO, *PWIFI_STA_LIST_INFO;

// BlueTooth设置
typedef struct CMD_BLUETOOTH_INFO
{
	unsigned char StartMode; // link mode
	char MacAddr[32];
	char PairDevName[32];
	char PairDevMac[32];
	unsigned char MinHeartRate;
	unsigned char MaxHeartRate;
} CMD_BLUETOOTH_INFO, *P_CMD_BLUETOOTH_INFO;

// 4G设置
typedef struct CMD_4G_INFO
{
	unsigned char  StartMode;      // 4G设置，SYSSET_4G_ 
	char  SimPin[16];     //SIM CARD PIN Number
	char  APN[32]; // APN
	char  APN_UserName[16]; // APN
	char  APN_PWD[16]; // APN
} CMD_4G_INFO, *P_CMD_4G_INFO;

#pragma pack()


#if !defined(DEV_HANDLE)
#define DEV_DEVICE void*
#define DEV_HANDLE void*
#endif

#ifdef  __cplusplus
extern "C" {
#endif
/* 
功能：获取设备列表
参数说明：
    handle
        [in|out] handle为一个数组，如果handle为NULL，函数返回设备数量
    size
        [in] handle数组大小
返回值：
    返回列举出来的设备数量
*/
ZYFLIB int EnumDeviceList(DEV_DEVICE *handle, int size);
ZYFLIB int EnumStorageList(DEV_DEVICE *handle, int size);
/* 
功能：获取磁盘号
参数说明：
    handle
        [in] 必须为EnumStorageList枚举出来的磁盘设备，传其它值无效
返回值：
    返回磁盘号，否则返回０
*/
ZYFLIB int GetStorageDisk(DEV_DEVICE handle);
ZYFLIB int GetStorageID(DEV_HANDLE handle);
/* 
功能：磁盘转换成卷标，并移除磁盘号
参数说明：
    drv
        [in] 磁盘号
    lpszVolumeName
        [in|out] 返回卷标名
返回值：
    返回磁盘号，否则返回０
*/
ZYFLIB int StorageToVolumeName(char drv, char *lpszVolumeName);
/* 
功能：释放列表资源
参数说明：
    handle
        [in] EnumDeviceList或EnumStorageList枚举出来的设备数组
    size
        [in] EnumDeviceList或EnumStorageList枚举出的设备返回值的数量
返回值：
    返回值为０，无任何意义
*/
ZYFLIB int ReleaseList(DEV_DEVICE *handle, int size);
/* 
功能：连接设备
参数说明：
    cDrv
        [in]
            设备盘符号，如'H'
    devDevice
        [in] 由EnumDeviceList或EnumStorageList获取的设备列表
    handle
        [in|out] 返回连接成功后的设备句柄，在以后的函数调用中要用到
返回值：
    成功：ERR_SUCCESS，其它详见错误列表
描述：
    ConnectDevice与ConnectStorageDevice的区别在于，该函数是通过由EnumDeviceList或EnumStorageList枚举出来的设备进行连接，
    而ConnectStorageDevice是通过磁盘的方式连接设备，二个函数根据实际需要任选一个
*/
ZYFLIB int ConnectDevice(DEV_DEVICE devDevice, DEV_HANDLE *handle);
ZYFLIB int ConnectStorageDevice(char cDrv, DEV_HANDLE *handle);
/* 
功能：断开与设备的连接
参数说明：
    handle
        [in] 由ConnectDevice或ConnectStorageDevice连接成功后返回的设备句柄
返回值：
    返回值：ERR_SUCCESS
*/
ZYFLIB int CloseDevice(DEV_HANDLE handle);
// 获取设备描述符
ZYFLIB int GetDescriptorString(DEV_HANDLE handle, char *szManufacturer, char *szProduct, char *szSerialNumber);
/* 
功能：获取设备版本信息
参数说明：
    handle
        [in] 由ConnectDevice或ConnectStorageDevice连接成功后返回的设备句柄
    pVersion
        [in|out] 固件版本号，格式：V日期_WIFI_GPS_硬件版本
返回值：
    详见错误代码
*/
ZYFLIB int GetDeviceVersion(DEV_HANDLE handle, char *pVersion);
// 复位设备参数
ZYFLIB int ResetDevice(DEV_HANDLE handle);
/* 
功能：获取/设置/验证密码
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    chPsw
        [in|out] 要设置或读取到的密码字符串
    userType
        [in] 密码类型，0:一般用户，1:管理员
返回值：
    详见错误代码
*/
ZYFLIB int SetPassword(DEV_HANDLE handle, char *cszPsw, int userType);
#if defined(BASE_DMT)
ZYFLIB int GetPassword(DEV_HANDLE handle, char *cszPsw, int userType);
#endif
ZYFLIB int VerifiPassword(DEV_HANDLE handle, char *cszPsw, int userType);
/* 
功能：读取时间
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    DateTime
        [in] DateTime: 返回年/月/日/时/分/秒信息，详见DEV_TM
返回值：
    详见错误代码
备注：
*/
ZYFLIB int GetTime(DEV_HANDLE handle, PDEV_TM DateTime);
#if defined(BASE_DMT)
ZYFLIB int SetTime(DEV_HANDLE handle, PDEV_TM DateTime);
#endif
// 同步时间
ZYFLIB int SyncDateTime(DEV_HANDLE handle);


/* 
功能：获取/设置用户编号和设备编号
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
	chUserID
        [in|out] 用户编号字符串.
    csUserName
        [in|out] 用户姓名
	chDevID: 
        [in|out] 设备编号字符串.
返回值：
    详见错误代码
*/

ZYFLIB int GetUserDevID(DEV_HANDLE handle, char *cszUserID, char *csUserName, char *cszDevID);
ZYFLIB int SetUserDevID(DEV_HANDLE handle, char *cszUserID, char *csUserName, char *cszDevID);

ZYFLIB int GetDeptInfo(DEV_HANDLE handle, char *deptCode, char *deptName);
ZYFLIB int SetDeptInfo(DEV_HANDLE handle, char *deptCode, char *deptName);
/* 
功能：获取/设置系统参数
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
返回值：
    详见错误代码
*/
ZYFLIB int GetSysParam(DEV_HANDLE handle, PPARAM_INFO param);
ZYFLIB int SetSysParam(DEV_HANDLE handle, PPARAM_INFO param);

/* 
功能：获取/设置WIFI信息
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
返回值：
    详见错误代码
*/
//ZYFLIB int GetWifiInfo(DEV_HANDLE handle, char *cszWifiSSID, char *cszWifiPwd);
//ZYFLIB int SetWifiInfo(DEV_HANDLE handle, char *cszWifiSSID, char *cszWifiPwd);


/* 
功能：获取电量
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    uBattery
        [in|out] 返回电量值，取值　0-100
返回值：
    详见错误代码
*/
ZYFLIB int GetBattery(DEV_HANDLE handle, unsigned short *uBattery);
/* 
功能：转USB
参数说明：
返回值：
    详见错误代码
*/
ZYFLIB int SetMSCMode(DEV_HANDLE handle);

/* 
功能：获取机型ID号.
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
返回值：
    详见错误代码
*/
ZYFLIB int GetModelID(DEV_HANDLE handle, char *cszModelID);
ZYFLIB int SetModelID(DEV_HANDLE handle, char *cszModelID);
/* 
功能：条型码.
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    cszBarCode
        [in] 读取或设置的条码值
返回值：
    详见错误代码
*/
ZYFLIB int GetBarCode(DEV_HANDLE handle, char *cszBarCode);
#if defined(BASE_DMT)
ZYFLIB int SetBarCode(DEV_HANDLE handle, char *cszBarCode);
#endif
/* 
功能：读磁盘空间信息.
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    totalSize
        [in|out] 磁盘总容易
    freeSize
        [in|out] 磁盘空闲容易
返回值：
    详见错误代码
*/
ZYFLIB int GetDiskSpaceInfo(DEV_HANDLE handle, unsigned long *totalSize, unsigned long *freeSize);
/* 
功能：设置读取MAC地址.
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    mac
        [in|out] MAC地址
返回值：
    详见错误代码
*/
ZYFLIB int GetMacAddress(DEV_HANDLE handle, char *mac);
ZYFLIB int SetMacAddress(DEV_HANDLE handle, char *mac);
/* 
功能：设置读取水印信息
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    mac
        [in|out] MAC地址
返回值：
    详见错误代码
*/
ZYFLIB int GetWaterMark(DEV_HANDLE handle, char *pszWaterMark);
ZYFLIB int SetWaterMark(DEV_HANDLE handle, char *pszWaterMark);

// 相机关机/重启
ZYFLIB int SetCameraShutdown(DEV_HANDLE handle);
ZYFLIB int CameraReboot(DEV_HANDLE handle);
/* 
功能：设置或获取内存加锁状态.
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    lock
        [in|out] 1:加锁或上锁，0:未加锁或解锁
返回值：
    详见错误代码
*/
ZYFLIB int SetLockMemoryState(DEV_HANDLE handle, int lock, char *pwd);
ZYFLIB int GetLockMemoryState(DEV_HANDLE handle, int *lock);

/* 
功能：设置LED状态.
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    type
        [in] 0x00（红）0x01（绿）0x02（蓝）0x03（白）
    state
        [in] 0x00(灭) 0x01（亮）0x02(闪烁)
    tim
        [in] 时间间隔，毫秒，100的整倍数，最大值为25.5秒，state为0x02时有效
返回值：
    详见错误代码
*/
ZYFLIB int SetLedState(DEV_HANDLE handle, int type, int state, int tim);
/* 
功能：设置蜂鸣器
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    number
        [in] 0x00-0xff(0-255),为0x00时关闭响声
    tim
        [in] 时间间隔，毫秒，100的整倍数，最大值为25.5秒
返回值：
    详见错误代码
*/
ZYFLIB int SetBuzzer(DEV_HANDLE handle, int number, int tim);

/* 
心跳
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    iTimeOut
        [in] 设置超时时间，0-20分钟，单位毫秒
    outNumber
        [out] 底层效验完后的返回值
    piTimeOut
        [out] 返回底层已设置的超时时间
返回值：
    详见错误代码
*/
ZYFLIB int SendHeartbeat(DEV_HANDLE handle, unsigned int iTimeOut, unsigned int *outNumber);
ZYFLIB int GetTimeOut(DEV_HANDLE handle, unsigned int *piTimeOut);
/* 
功能：设置或读取4G信息
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    g4
        [out] 4G信息
返回值：
    详见错误代码
*/
ZYFLIB int Get4GInfo(DEV_HANDLE handle, P_CMD_4G_INFO pInfo);
ZYFLIB int Set4GInfo(DEV_HANDLE handle, P_CMD_4G_INFO pInfo);
/* 
功能：网络设置
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    pszNetWorkName
        [in|out] 网络设备名
    pszserverIP
        [in|out] 服务器IP地址
    pszNetWorkIP
        [in|out] IP地址设置
    count
        [in|out] 连接数量 ，0-4,表示 1-5
返回值：
    详见错误代码
*/
ZYFLIB int GetNetworkInfo(DEV_HANDLE handle, P_CMD_NETWORK_INFO pInfo);
ZYFLIB int SetNetworkInfo(DEV_HANDLE handle, P_CMD_NETWORK_INFO pInfo);
/*
功能：Wifi设置
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    pInfo
        [in|out] WIFI信息，详见WIFI_INFO
返回值：
    详见错误代码
*/
//ZYFLIB int GetWifiInfo(DEV_HANDLE handle, WIFI_INFO *pInfo);
//ZYFLIB int SetWifiInfo(DEV_HANDLE handle, WIFI_INFO *pInfo);
/*
功能：蓝牙设置
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    Bluetooth
        [in|out] 蓝牙连接方式
    BluetoothAddr
        [in|out] 蓝牙地址
返回值：
    详见错误代码
*/
ZYFLIB int GetBluetoothInfo(DEV_HANDLE handle, P_CMD_BLUETOOTH_INFO pInfo);
ZYFLIB int SetBluetoothInfo(DEV_HANDLE handle, P_CMD_BLUETOOTH_INFO pInfo);

/*
功能：夏令时间设置
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    info
        [in] 详见SUMMER_TIME_INFO定义
返回值：
    详见错误代码
*/
ZYFLIB int GetSummerTimeInfo(DEV_HANDLE handle, PSUMMER_TIME_INFO pInfo);
ZYFLIB int SetSummerTimeInfo(DEV_HANDLE handle, PSUMMER_TIME_INFO pInfo);
/*
功能：设置系统 类型
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    sysType
        [in] 设置系统类型，0：linux，1：Windows
返回值：
    详见错误代码
*/
ZYFLIB int SetSystemType(DEV_HANDLE handle, int sysType);
/*
功能：设置P2P CODE
参数说明：
    handle
        [in] 由ConnectDevice连接成功后返回的设备句柄
    p2pCode
        [in] 设置系统类型，P2P CODE
返回值：
    详见错误代码
*/
ZYFLIB int SetP2pCode(DEV_HANDLE handle, char *p2pCode);
ZYFLIB int GetP2pCode(DEV_HANDLE handle, char *p2pCode);

// 读取相机所支持的通道信息
ZYFLIB int GetWifiChannelInfo(DEV_HANDLE handle, PWIFI_CHANNEL_INFO);

ZYFLIB int GetWifiApSetting(DEV_HANDLE handle, PWIFI_AP_SETTING);
ZYFLIB int SetWifiApSetting(DEV_HANDLE handle, PWIFI_AP_SETTING);

// wifi通用设置
ZYFLIB int GetWifiUniversal(DEV_HANDLE handle, PWIFI_UNIVERSAL_INFO pInfo);
ZYFLIB int SetWifiUniversal(DEV_HANDLE handle, PWIFI_UNIVERSAL_INFO pInfo);

// sta模式设置当前要连接的热点
ZYFLIB int GetWifiStaSetting(DEV_HANDLE handle, PWIFI_STA_SETTING_CUR_SSID  pInfo);
ZYFLIB int SetWifiStaSetting(DEV_HANDLE handle, PWIFI_STA_SETTING_CUR_SSID  pInfo);

ZYFLIB int GetStaListInfo(DEV_HANDLE handle, PWIFI_STA_LIST_INFO pInfo);
ZYFLIB int DeleteStaInfo(DEV_HANDLE handle, char *ssid);
ZYFLIB int DeleteStaInfoAll(DEV_HANDLE handle);

ZYFLIB int FormatDisk(DEV_HANDLE handle);

ZYFLIB int SetEncryption(DEV_HANDLE handle, unsigned char DataEncryption, unsigned char DecryptionPlay, unsigned char *desKey);
ZYFLIB int GetEncryption(DEV_HANDLE handle, unsigned char *DataEncryption, unsigned char *DecryptionPlay, unsigned char *desKey);

#ifdef  __cplusplus
}
#endif

#endif