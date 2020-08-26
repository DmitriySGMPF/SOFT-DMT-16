#if !defined(_include_unisafty_zyfi8_h__)
#define _include_unisafty_zyfi8_h__

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


// 错误代码定义
typedef enum _RESULT_FLAG
{
    CONNECT_SUCCESS = 0x01, /*执法记录仪连接成功*/
    CONNECT_FAILED,         /*执法记录仪连接失败*/
    CHECK_PWD_SUCCESS,      /*执法记录仪管理员密码校验成功*/
    CHECK_PWD_FAILED,      /*执法记录仪管理员密码校验失败*/
    SET_SYSTEMTIME_SUCCESS, /*执法记录仪系统时间同步成功*/
    SET_SYSTEMTIME_FAILED,  /*执法记录仪系统时间同步失败*/
    MSDC_SUCCESS,           /*执法记录仪转换移动磁盘模式成功*/
    MSDC_FAILED,             /*执法记录仪转换移动磁盘模式失败*/
    FORMAT_SUCCESS,         // 格式化磁盘成功

}RESULT_FLAG;

#pragma pack(1)

typedef struct _tagZFY_INFO{
    char cSerial[8];        // 执法记录仪产品序号，不可为空
    char userNo[7];         // 执法记录仪使用者警号，不可为空
    char userName[33];      // 执法记录仪使用者姓名，管理平台使用警号关联时可为空
    char unitNo[13];        // 执法记录仪使用者单位编号，管理平台使用警号关联时可为空
    char unitName[33];      // 单位名称
} ZFY_INFO;

#pragma pack()


extern "C"
{
/* 
功能：初始化设备1
返回值：
    true：成功，否则失败
参数说明：
    IDCode
        [in] 识别码
    uRet
        [out] 详见错误代码定义
*/
    ZYFLIB bool Init_Device(char* IDCode, unsigned short *uRet);

/*
功能：释放由Init_Device申请的资源，与Init_Device成对使用
返回值：
    true：成功，否则失败
参数说明：
    IDCode
        [in] 识别码
    uRet
        [out] 详见错误代码定义
*/
    ZYFLIB bool Uninit_Device(char *IDCode, unsigned short *uRet);

/*
功能：读取记录仪产品型号1
返回值: 
    true：成功，否则失败
参数说明：
    IDCode
        [out] 返回产品型号
    uRet
        [out] 详见错误代码定义
*/
    ZYFLIB bool GetIDCode(char* IDCode, unsigned short *uRet);
    ZYFLIB bool SetIDCode(char* IDCode, unsigned short *uRet);

/*
功能：读取记录仪设备ID
返回值: 
    true：成功，否则失败
参数说明：
    IDCode
        [out] 调用成功，返回设备ID
    uRet
        [out] 详见错误代码
*/
    //ZYFAPI bool GetDeviceID (char * DeviceID, unsigned short*uRet);

/*
功能：设置设备ID
返回值: 
    true：成功，否则失败 
参数说明：
    DeviceID
        [in] 要设置的设备ID号
    uRet
        [out] 详见错误代码
*/
    //ZYFAPI bool SetDeviceID (char *DeviceID, unsigned short *uRet);

/*
功能：读取记录仪信息1
返回值: 
    true：成功，否则失败
参数说明：
    info：
        [out] 记录仪信息，详见ZFY_INFO定义
    sPwd	
        [in] 管理员密码
    uRet
        [out] 详见错误代码
*/
    ZYFLIB bool GetZFYInfo(ZFY_INFO *info, char* spwd, unsigned short *uRet);

/*
功能：写记录仪信息1
返回值: 
    true：成功，否则失败
参数说明：
    info：
        [in] 要写入的记录仪信息，详见ZFY_INFO定义
    sPwd	
        [in] 管理员密码
    uRet
        [out] 详见错误代码
*/
    ZYFLIB bool WriteZFYInfo(ZFY_INFO *info, char* spwd, unsigned short *uRet);

/*
功能：读取\设置记录仪密码
返回值: 
    true：成功，否则失败
参数说明：
    sPwd
        [out] 记录仪密码
    uRet
        [out] 详见错误代码
*/
   // ZYFLIB bool GetZFYPassWord (char *sPwd, int usertype, unsigned short *uRet);
    ZYFLIB bool SetZFYPassWord (char *sPwd, int usertype, unsigned short *uRet);
    ZYFLIB bool VerificationPassword(char *spwd, int usertype, unsigned short *uRet);

/*
功能：同步记录仪时间，与当前系统时间同步1
返回值: 
    true：成功，否则失败
参数说明：
    sPwd
        [in] 管理员密码
    uRet
        [out] 详见错误代码
*/
    ZYFLIB bool SyncDevTime(char* spwd, unsigned short *uRet);

/*
功能：设置为移动磁盘1
返回值: 
    true：成功，否则失败
参数说明：
    sPwd
        [in] 管理员密码
    uRet
        [out] 详见错误代码
*/
    ZYFLIB bool SetMSDC(char* spwd, unsigned short *uRet);

/*
功能：读取记录仪容量
返回值: 
    true：成功，否则失败
参数说明：
    sCapacity
        [out] 磁盘容量，以字节为单位
    sPwd
        [in] 密码
    uRet
        [out] 详见错误代码
描述：
    获取记录仪容量后，会自动切换至移动磁盘模式
*/
    ZYFLIB bool ReadDeviceCapacity(unsigned long long *sCapacity, char *sPwd, unsigned short *uRet);

/*
功能：读取记录仪电量1
返回值: 
    true：成功，否则失败
参数说明：
    Battery
        [out] 读取成功返回电量百分比值，取值范围：0-100 
    sPwd
        [in] 密码
    uRet
        [out] 详见错误代码
*/
    ZYFLIB bool ReadDeviceBatteryDumpEnergy(int *Battery, char* spwd, unsigned short *uRet);

/*
功能：读取记录仪分辨率1
返回值: 
    true：成功，否则失败
参数说明：
    Width
        [out] 读取成功则返回分辨率的宽
    Height
        [out] 读取成功则返回分辨率的高
    sPwd
        [in] 管理员密码
    uRet
        [out] 详见错误代码
*/
    ZYFLIB bool ReadDeviceResolution(int *Width, int *Height, char* spwd, unsigned short *uRet);

/*
功能：读取设备序列号
返回值: 
    true：成功，否则失败
参数说明：
    SerialID
        [out] 设备序列号
    uRet
        [out] 详见错误代码
*/
    ZYFLIB bool GetSerialID(char *SerialID, unsigned short *uRet);
   // ZYFLIB bool SetSerialID(char *SerialID, unsigned short *uRet);
}

#endif