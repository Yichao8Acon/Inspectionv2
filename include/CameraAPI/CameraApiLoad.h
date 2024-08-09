#ifndef _MV_CAM_API
#define _MV_CAM_API

#include "CameraDefine.H"
#include "CameraStatus.h"

#ifndef MAX_PATH
#define MAX_PATH 256
#endif

//BIG5 TRANS ALLOWED


/******************************************************/
// ������   : CameraSdkInit
// �������� : ���SDK��ʼ�����ڵ����κ�SDK�����ӿ�ǰ������
//        �ȵ��øýӿڽ��г�ʼ�����ú�����������������
//        �ڼ�ֻ��Ҫ����һ�Ρ�   
// ����     : iLanguageSel ����ѡ��SDK�ڲ���ʾ��Ϣ�ͽ��������,
//               0:��ʾӢ��,1:��ʾ���ġ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSdkInit)(
	int     iLanguageSel
	);
	
/// @ingroup API_BASIC
/// \~chinese
/// \brief ����ϵͳѡ�ͨ����Ҫ��CameraInit�����֮ǰ���úã�
/// \param [in] optionName ѡ��("NumBuffers", "3")
/// \param [in] value ֵ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Configure system options (usually required before CameraInit turns on the camera)
/// \param [in] optionName option name("NumBuffers", "3")
/// \param [in] value setting value
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetSysOption)(
	char const* optionName,
	char const* value
	);

/******************************************************/
// ������   : CameraEnumerateDevice
// �������� : ö���豸���������豸�б��ڵ���CameraInit
//        ֮ǰ��������øú���������豸����Ϣ��    
// ����     : pCameraList   �豸�б�����ָ�롣
//            piNums        �豸�ĸ���ָ�룬����ʱ����pCameraList
//                            �����Ԫ�ظ�������������ʱ������ʵ���ҵ����豸������
//              ע�⣬piNumsָ���ֵ�����ʼ�����Ҳ�����pCameraList����Ԫ�ظ�����
//              �����п�������ڴ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraEnumerateDevice)(
	tSdkCameraDevInfo* pCameraList, 
	INT*               piNums
	);

/******************************************************/
// ������ 	: CameraEnumerateDeviceEx
// ��������	: ö���豸���������豸�б��ڵ���CameraInitEx
//			  ֮ǰ��������øú���ö���豸��
// ����	     : 
// ����ֵ     : �����豸������0��ʾ�ޡ�
/******************************************************/
typedef INT (__stdcall *_CameraEnumerateDeviceEx)(
	);

/******************************************************/
// ������   : CameraIsOpened
// �������� : ����豸�Ƿ��Ѿ�������Ӧ�ó���򿪡��ڵ���CameraInit
//        ֮ǰ������ʹ�øú������м�⣬����Ѿ����򿪣�����
//        CameraInit�᷵���豸�Ѿ����򿪵Ĵ����롣    
// ����     : pCameraList �豸��ö����Ϣ�ṹ��ָ�룬��CameraEnumerateDevice��á�
//            pOpened       �豸��״ָ̬�룬�����豸�Ƿ񱻴򿪵�״̬��TRUEΪ�򿪣�FALSEΪ���С�          
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraIsOpened)(
	tSdkCameraDevInfo*  pCameraList, 
	BOOL*       pOpened
	);

/******************************************************/
// ������   : CameraInit
// �������� : �����ʼ������ʼ���ɹ��󣬲��ܵ����κ�����
//        �����صĲ����ӿڡ�    
// ����     : pCameraInfo    ��������豸������Ϣ����CameraEnumerateDevice
//               ������á� 
//            iParamLoadMode  �����ʼ��ʱʹ�õĲ������ط�ʽ��-1��ʾʹ���ϴ��˳�ʱ�Ĳ������ط�ʽ��
//            emTeam         ��ʼ��ʱʹ�õĲ����顣-1��ʾ�����ϴ��˳�ʱ�Ĳ����顣
//            pCameraHandle  ����ľ��ָ�룬��ʼ���ɹ��󣬸�ָ��
//               ���ظ��������Ч������ڵ����������
//               ��صĲ����ӿ�ʱ������Ҫ����þ������Ҫ
//               ���ڶ����֮������֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraInit)(
	tSdkCameraDevInfo*  pCameraInfo,
	int         emParamLoadMode,
	int         emTeam,
	CameraHandle*   pCameraHandle
	);

/******************************************************/
// ������ 	: CameraInitEx
// ��������	: �����ʼ������ʼ���ɹ��󣬲��ܵ����κ�����
//			  �����صĲ����ӿڡ�		
// ����	    : iDeviceIndex    ����������ţ�CameraEnumerateDeviceEx�������������	
//            iParamLoadMode  �����ʼ��ʱʹ�õĲ������ط�ʽ��-1��ʾʹ���ϴ��˳�ʱ�Ĳ������ط�ʽ��
//                             Ϊ PARAM_MODE_BY_MODEL ��ʾ���ͺż���
//                             Ϊ PARAM_MODE_BY_SN ��ʾ�����кż���
//                             Ϊ PARAM_MODE_BY_NAME ��ʾ���ǳƼ���
//                             ��ϸ��ο�CameraDefine.h�� emSdkParameterMode ���塣
//            emTeam         ��ʼ��ʱʹ�õĲ����顣-1��ʾ�����ϴ��˳�ʱ�Ĳ����顣
//            pCameraHandle  ����ľ��ָ�룬��ʼ���ɹ��󣬸�ָ��
//							 ���ظ��������Ч������ڵ����������
//							 ��صĲ����ӿ�ʱ������Ҫ����þ������Ҫ
//							 ���ڶ����֮������֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraInitEx)(
	int             iDeviceIndex,
	int             iParamLoadMode,
	int             emTeam,
	CameraHandle*   pCameraHandle
	);

/******************************************************/
// ������ 	: CameraInitEx2
// ��������	: �����ʼ������ʼ���ɹ��󣬲��ܵ����κ�����
//			  �����صĲ����ӿڡ�	ע����Ҫ�ȵ���CameraEnumerateDeviceExö�����
// ����	    : CameraName    �������
//            pCameraHandle  ����ľ��ָ�룬��ʼ���ɹ��󣬸�ָ��
//							 ���ظ��������Ч������ڵ����������
//							 ��صĲ����ӿ�ʱ������Ҫ����þ������Ҫ
//							 ���ڶ����֮������֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraInitEx2)(
	char* CameraName,
	CameraHandle   *pCameraHandle
	);

/******************************************************/
// ������   : CameraSetCallbackFunction
// �������� : ����ͼ�񲶻�Ļص��������������µ�ͼ������֡ʱ��
//        pCallBack��ָ��Ļص������ͻᱻ���á� 
// ����     : hCamera ����ľ������CameraInit������á�
//            pCallBack �ص�����ָ�롣
//            pContext  �ص������ĸ��Ӳ������ڻص�����������ʱ
//            �ø��Ӳ����ᱻ���룬����ΪNULL��������
//            ������ʱЯ��������Ϣ��
//            pCallbackOld  ���ڱ��浱ǰ�Ļص�����������ΪNULL��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetCallbackFunction)(
	CameraHandle        hCamera,
	CAMERA_SNAP_PROC    pCallBack,
	PVOID               pContext,
	CAMERA_SNAP_PROC*   pCallbackOld
	);

/******************************************************/
// ������   : CameraUnInit
// �������� : �������ʼ�����ͷ���Դ��
// ����     : hCamera ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraUnInit)(
	CameraHandle hCamera
	);

/******************************************************/
// ������   : CameraGetInformation
// �������� : ��������������Ϣ
// ����     : hCamera ����ľ������CameraInit������á�
//            pbuffer ָ�����������Ϣָ���ָ�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetInformation)(
	CameraHandle    hCamera, 
	char**          pbuffer
	);

/******************************************************/
// ������   : CameraImageProcess
// �������� : ����õ����ԭʼ���ͼ�����ݽ��д������ӱ��Ͷȡ�
//        ��ɫ�����У��������ȴ���Ч�������õ�RGB888
//        ��ʽ��ͼ�����ݡ�  
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbyIn    ����ͼ�����ݵĻ�������ַ������ΪNULL�� 
//            pbyOut   �����ͼ������Ļ�������ַ������ΪNULL��
//            pFrInfo  ����ͼ���֡ͷ��Ϣ��������ɺ�֡ͷ��Ϣ
//             �е�ͼ���ʽuiMediaType����֮�ı䡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraImageProcess)(
	CameraHandle        hCamera, 
	BYTE*               pbyIn, 
	BYTE*               pbyOut,
	tSdkFrameHead*      pFrInfo
	);

/******************************************************/
// ������ 	: CameraImageProcessEx
// ��������	: ����õ����ԭʼ���ͼ�����ݽ��д������ӱ��Ͷȡ�
//			  ��ɫ�����У��������ȴ���Ч�������õ�RGB888
//			  ��ʽ��ͼ�����ݡ�	
// ����	    : hCamera      ����ľ������CameraInit������á�
//            pbyIn	     ����ͼ�����ݵĻ�������ַ������ΪNULL��	
//            pbyOut        �����ͼ������Ļ�������ַ������ΪNULL��
//            pFrInfo       ����ͼ���֡ͷ��Ϣ��������ɺ�֡ͷ��Ϣ
//            uOutFormat    �������ͼ��������ʽ
//            uReserved     Ԥ����������������Ϊ0     
//					   �е�ͼ���ʽuiMediaType����֮�ı䡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImageProcessEx)(
	CameraHandle        hCamera, 
	BYTE*               pbyIn, 
	BYTE*               pbyOut,
	tSdkFrameHead*      pFrInfo,
	UINT                uOutFormat,
	UINT                uReserved
	);


/******************************************************/
// ������   : CameraDisplayInit
// �������� : ��ʼ��SDK�ڲ�����ʾģ�顣�ڵ���CameraDisplayRGB24
//        ǰ�����ȵ��øú�����ʼ����������ڶ��ο����У�
//        ʹ���Լ��ķ�ʽ����ͼ����ʾ(������CameraDisplayRGB24)��
//        ����Ҫ���ñ�������  
// ����     : hCamera   ����ľ������CameraInit������á�
//            hWndDisplay ��ʾ���ڵľ����һ��Ϊ���ڵ�m_hWnd��Ա��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraDisplayInit)(
	CameraHandle    hCamera,
	HWND            hWndDisplay
	);

/******************************************************/
// ������   : CameraDisplayInitEx
// �������� : ��ʼ��SDK�ڲ�����ʾģ�顣�ڵ���CameraDisplayRGB24
//        ǰ�����ȵ��øú�����ʼ����������ڶ��ο����У�
//        ʹ���Լ��ķ�ʽ����ͼ����ʾ(������CameraDisplayRGB24)��
//        ����Ҫ���ñ������� �ú����� CameraDisplayInit��������
//        �ú���ʱΪͼ���ļ�����һ��SDK�������ʹ�����ڲ�ISP����ʾ�ӿ�
// ����     : pCameraHandle   ��������ľ����
//            hWndDisplay ��ʾ���ڵľ����һ��Ϊ���ڵ�m_hWnd��Ա��
//            szFileName  ͼ���ļ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraDisplayInitEx)(
	CameraHandle*   pCameraHandle,
	HWND            hWndDisplay,
	char*           szFileName
	);

/******************************************************/
// ������   : CameraDisplayRGB24
// �������� : ��ʾͼ�񡣱�����ù�CameraDisplayInit����
//        ��ʼ�����ܵ��ñ�������  
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbyRGB24 ͼ������ݻ�������RGB888��ʽ��
//            pFrInfo  ͼ���֡ͷ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraDisplayRGB24)(
	CameraHandle        hCamera,
	BYTE*               pbyRGB24, 
	tSdkFrameHead*      pFrInfo
	);

/******************************************************/
// ������   : CameraSetDisplayMode
// �������� : ������ʾ��ģʽ��������ù�CameraDisplayInit
//        ���г�ʼ�����ܵ��ñ�������
// ����     : hCamera  ����ľ������CameraInit������á�
//            iMode    ��ʾģʽ��DISPLAYMODE_SCALE����
//             DISPLAYMODE_REAL,����μ�CameraDefine.h
//             ��emSdkDisplayMode�Ķ��塣    
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetDisplayMode)(
	CameraHandle    hCamera,
	INT             iMode
	);

/******************************************************/
// ������   : CameraSetDisplayOffset
// �������� : ������ʾ����ʼƫ��ֵ��������ʾģʽΪDISPLAYMODE_REAL
//        ʱ��Ч��������ʾ�ؼ��Ĵ�СΪ320X240����ͼ���
//        �ĳߴ�Ϊ640X480����ô��iOffsetX = 160,iOffsetY = 120ʱ
//        ��ʾ���������ͼ��ľ���320X240��λ�á�������ù�
//        CameraDisplayInit���г�ʼ�����ܵ��ñ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            iOffsetX  ƫ�Ƶ�X���ꡣ
//            iOffsetY  ƫ�Ƶ�Y���ꡣ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetDisplayOffset)(
	CameraHandle    hCamera,
	int             iOffsetX, 
	int             iOffsetY
	);

/******************************************************/
// ������   : CameraSetDisplaySize
// �������� : ������ʾ�ؼ��ĳߴ硣������ù�
//        CameraDisplayInit���г�ʼ�����ܵ��ñ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            iWidth    ���
//            iHeight   �߶�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetDisplaySize)(
	CameraHandle    hCamera, 
	INT             iWidth, 
	INT             iHeight
	);

/******************************************************/
// ������   : CameraGetImageBuffer
// �������� : ���һ֡ͼ�����ݡ�Ϊ�����Ч�ʣ�SDK��ͼ��ץȡʱ�������㿽�����ƣ�
//        CameraGetImageBufferʵ�ʻ�����ں��е�һ����������ַ��
//        �ú����ɹ����ú󣬱������CameraReleaseImageBuffer�ͷ���
//        CameraGetImageBuffer�õ��Ļ�����,�Ա����ں˼���ʹ��
//        �û�������  
// ����     : hCamera   ����ľ������CameraInit������á�
//            pFrameInfo  ͼ���֡ͷ��Ϣָ�롣
//            pbyBuffer   ָ��ͼ������ݵĻ�����ָ�롣����
//              �������㿽�����������Ч�ʣ����
//              ����ʹ����һ��ָ��ָ���ָ�롣
//            UINT wTimes ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//              wTimesʱ���ڻ�δ���ͼ����ú���
//              �᷵�س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetImageBuffer)(
	CameraHandle        hCamera, 
	tSdkFrameHead*      pFrameInfo, 
	BYTE**              pbyBuffer,
	UINT                wTimes
	);

/******************************************************/
// ������ 	: CameraGetImageBufferEx
// ��������	: ���һ֡ͼ�����ݡ��ýӿڻ�õ�ͼ���Ǿ���������RGB��ʽ���ú������ú�
//			  ����Ҫ���� CameraReleaseImageBuffer �ͷţ�Ҳ��Ҫ����free֮��ĺ����ͷ�
//              ���ͷŸú������ص�ͼ�����ݻ�������
// ����	    : hCamera	  ����ľ������CameraInit������á�
//            piWidth    ����ָ�룬����ͼ��Ŀ��
//            piHeight   ����ָ�룬����ͼ��ĸ߶�
//            UINT wTimes ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//						  wTimesʱ���ڻ�δ���ͼ����ú���
//						  �᷵�س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������RGB���ݻ��������׵�ַ;
//            ���򷵻�0��
/******************************************************/
typedef unsigned char* (__stdcall *_CameraGetImageBufferEx)(
	CameraHandle        hCamera, 
	INT*                piWidth,
	INT*                piHeight,
	UINT                wTimes
	);

/******************************************************/
// ������   : CameraSnapToBuffer
// �������� : ץ��һ��ͼ�񵽻������С���������ץ��ģʽ������
//        �Զ��л���ץ��ģʽ�ķֱ��ʽ���ͼ�񲶻�Ȼ��
//        ���񵽵����ݱ��浽�������С�
//        �ú����ɹ����ú󣬱������CameraReleaseImageBuffer
//        �ͷ���CameraSnapToBuffer�õ��Ļ�������������ο�
//        CameraGetImageBuffer�����Ĺ����������֡�  
// ����     : hCamera   ����ľ������CameraInit������á�
//            pFrameInfo  ָ�룬����ͼ���֡ͷ��Ϣ��
//            pbyBuffer   ָ��ָ���ָ�룬��������ͼ�񻺳����ĵ�ַ��
//            uWaitTimeMs ��ʱʱ�䣬��λ���롣�ڸ�ʱ���ڣ������Ȼû��
//              �ɹ���������ݣ��򷵻س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSnapToBuffer)(
	CameraHandle        hCamera,
	tSdkFrameHead*      pFrameInfo,
	BYTE**              pbyBuffer,
	UINT                uWaitTimeMs
	);

typedef    CameraSdkStatus (__stdcall *_CameraSnapJpegToFile)(
	CameraHandle    hCamera,
	char const*     lpszFileName,
	BYTE            byQuality,
	UINT            wTimes
	);

/******************************************************/
// ������   : CameraReleaseImageBuffer
// �������� : �ͷ���CameraGetImageBuffer��õĻ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            pbyBuffer   ��CameraGetImageBuffer��õĻ�������ַ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraReleaseImageBuffer)(
	CameraHandle    hCamera, 
	BYTE*           pbyBuffer
	);

/******************************************************/
// ������   : CameraPlay
// �������� : ��SDK���빤��ģʽ����ʼ��������������͵�ͼ��
//        ���ݡ������ǰ����Ǵ���ģʽ������Ҫ���յ�
//        ����֡�Ժ�Ż����ͼ��
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraPlay)(
	CameraHandle hCamera
	);

/******************************************************/
// ������   : CameraPause
// �������� : ��SDK������ͣģʽ�����������������ͼ�����ݣ�
//        ͬʱҲ�ᷢ�������������ͣ������ͷŴ������
//        ��ͣģʽ�£����Զ�����Ĳ����������ã���������Ч��  
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraPause)(
	CameraHandle hCamera
	);

/******************************************************/
// ������   : CameraStop
// �������� : ��SDK����ֹͣ״̬��һ���Ƿ���ʼ��ʱ���øú�����
//        �ú��������ã������ٶ�����Ĳ����������á�
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraStop)(
	CameraHandle hCamera
	);

/******************************************************/
// ������   : CameraInitRecord
// �������� : ��ʼ��һ��¼��
// ����     : hCamera   ����ľ������CameraInit������á�
//            iFormat   ¼��ĸ�ʽ����ǰֻ֧�ֲ�ѹ����MSCV���ַ�ʽ��  
//              0:��ѹ����1:MSCV��ʽѹ����
//            pcSavePath  ¼���ļ������·����
//            b2GLimit    ���ΪTRUE,���ļ�����2Gʱ�Զ��ָ
//            dwQuality   ¼����������ӣ�Խ��������Խ�á���Χ1��100.
//            iFrameRate  ¼���֡�ʡ������趨�ı�ʵ�ʲɼ�֡�ʴ�
//              �����Ͳ���©֡��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraInitRecord)(
	CameraHandle    hCamera,
	int             iFormat,
	char*           pcSavePath,
	BOOL            b2GLimit,
	DWORD           dwQuality,
	int             iFrameRate
	);

/******************************************************/
// ������   : CameraStopRecord
// �������� : ��������¼�񡣵�CameraInitRecord�󣬿���ͨ���ú���
//        ������һ��¼�񣬲�����ļ����������
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraStopRecord)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraPushFrame
// �������� : ��һ֡���ݴ���¼�����С��������CameraInitRecord
//        ���ܵ��øú�����CameraStopRecord���ú󣬲����ٵ���
//        �ú������������ǵ�֡ͷ��Ϣ��Я����ͼ��ɼ���ʱ���
//        ��Ϣ�����¼����Ծ�׼��ʱ��ͬ����������֡�ʲ��ȶ�
//        ��Ӱ�졣
// ����     : hCamera     ����ľ������CameraInit������á�
//            pbyImageBuffer    ͼ������ݻ�������������RGB��ʽ��
//            pFrInfo           ͼ���֡ͷ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraPushFrame)(
	CameraHandle    hCamera,
	BYTE*           pbyImageBuffer,
	tSdkFrameHead*  pFrInfo
	);

/******************************************************/
// ������   : CameraSaveImage
// �������� : ��ͼ�񻺳��������ݱ����ͼƬ�ļ���
// ����     : hCamera    ����ľ������CameraInit������á�
//            lpszFileName   ͼƬ�����ļ�����·����
//            pbyImageBuffer ͼ������ݻ�������
//            pFrInfo        ͼ���֡ͷ��Ϣ��
//            byFileType     ͼ�񱣴�ĸ�ʽ��ȡֵ��Χ�μ�CameraDefine.h
//               ��emSdkFileType�����Ͷ��塣Ŀǰ֧��  
//               BMP��JPG��PNG��RAW���ָ�ʽ������RAW��ʾ
//               ��������ԭʼ���ݣ�����RAW��ʽ�ļ�Ҫ��
//               pbyImageBuffer��pFrInfo����CameraGetImageBuffer
//               ��õ����ݣ�����δ��CameraImageProcessת��
//               ��BMP��ʽ����֮�����Ҫ�����BMP��JPG����
//               PNG��ʽ����pbyImageBuffer��pFrInfo����
//               CameraImageProcess������RGB��ʽ���ݡ�
//                 �����÷����Բο�Advanced�����̡�   
//            byQuality      ͼ�񱣴���������ӣ���������ΪJPG��ʽ
//                 ʱ�ò�����Ч����Χ1��100�������ʽ
//                           ����д��0��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSaveImage)(
	CameraHandle    hCamera,
	char*           lpszFileName,
	BYTE*           pbyImageBuffer,
	tSdkFrameHead*  pFrInfo,
	UINT            byFileType,
	BYTE            byQuality
	);

/******************************************************/
// ������   : CameraGetImageResolution
// �������� : ��õ�ǰԤ���ķֱ��ʡ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            psCurVideoSize �ṹ��ָ�룬���ڷ��ص�ǰ�ķֱ��ʡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetImageResolution)(
	CameraHandle            hCamera, 
	tSdkImageResolution*    psCurVideoSize
	);

/******************************************************/
// ������   : CameraGetImageResolutionEx
// �������� : ��ȡ����ķֱ��ʡ�
// ����     : hCamera      ����ľ������CameraInit������á�
//            iIndex	   �����ţ�[0,N]��ʾԤ��ķֱ���(N ΪԤ��ֱ��ʵ���������һ�㲻����20),OXFF ��ʾ�Զ���ֱ���(ROI)
//			  acDescription �÷ֱ��ʵ�������Ϣ����Ԥ��ֱ���ʱ����Ϣ��Ч���Զ���ֱ��ʿɺ��Ը���Ϣ
//			  Mode		   0: ��ͨģʽ     1��Sum       2��Average        3��Skip        4��Resample
//			  ModeSize	   ��ͨģʽ�º��ԣ���1λ��ʾ2X2 �ڶ�λ��ʾ3X3 ...
//			  x, y		   ˮƽ����ֱƫ��
//			  width, height ���
//			  ZoomWidth,ZoomHeight �������ʱ����Ϊ���0��ʾ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetImageResolutionEx)(
	CameraHandle            hCamera, 
	int*					iIndex,
	char					acDescription[32],
	int*					Mode,
	UINT*					ModeSize,
	int*					x,
	int*					y,
	int*					width,
	int*					height,
	int*					ZoomWidth,
	int*					ZoomHeight
	);

/******************************************************/
// ������   : CameraSetImageResolution
// �������� : ����Ԥ���ķֱ��ʡ�
// ����     : hCamera      ����ľ������CameraInit������á�
//            pImageResolution �ṹ��ָ�룬���ڷ��ص�ǰ�ķֱ��ʡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetImageResolution)(
	CameraHandle            hCamera, 
	tSdkImageResolution*    pImageResolution
	);

/******************************************************/
// ������   : CameraSetImageResolutionEx
// �������� : ��������ķֱ��ʡ�
// ����     : hCamera      ����ľ������CameraInit������á�
//            iIndex	   �����ţ�[0,N]��ʾԤ��ķֱ���(N ΪԤ��ֱ��ʵ���������һ�㲻����20),OXFF ��ʾ�Զ���ֱ���(ROI)
//			  Mode		   0: ��ͨģʽ     1��Sum       2��Average        3��Skip        4��Resample
//			  ModeSize	   ��ͨģʽ�º��ԣ���1λ��ʾ2X2 �ڶ�λ��ʾ3X3 ...
//			  x, y		   ˮƽ����ֱƫ��
//			  width, height ���
//			  ZoomWidth,ZoomHeight �������ʱ����Ϊ���0��ʾ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetImageResolutionEx)(
	CameraHandle            hCamera, 
	int						iIndex,
	int						Mode,
	UINT					ModeSize,
	int						x,
	int						y,
	int						width,
	int						height,
	int						ZoomWidth,
	int						ZoomHeight
	);

/******************************************************/
// ������   : CameraGetMediaType
// �������� : ��������ǰ���ԭʼ���ݵĸ�ʽ�����š�
// ����     : hCamera   ����ľ������CameraInit������á�
//            piMediaType   ָ�룬���ڷ��ص�ǰ��ʽ���͵������š�
//              ��CameraGetCapability�����������ԣ�
//              ��tSdkCameraCapbility�ṹ���е�pMediaTypeDesc
//              ��Ա�У����������ʽ���������֧�ֵĸ�ʽ��
//              piMediaType��ָ��������ţ����Ǹ�����������š�
//              pMediaTypeDesc[*piMediaType].iMediaType���ʾ��ǰ��ʽ�� 
//              ���롣�ñ�����μ�CameraDefine.h��[ͼ���ʽ����]���֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetMediaType)(
	CameraHandle    hCamera, 
	INT*            piMediaType
	);

/******************************************************/
// ������   : CameraSetMediaType
// �������� : ������������ԭʼ���ݸ�ʽ��
// ����     : hCamera   ����ľ������CameraInit������á�
//            iMediaType  ��CameraGetCapability�����������ԣ�
//              ��tSdkCameraCapbility�ṹ���е�pMediaTypeDesc
//              ��Ա�У����������ʽ���������֧�ֵĸ�ʽ��
//              iMediaType���Ǹ�����������š�
//              pMediaTypeDesc[iMediaType].iMediaType���ʾ��ǰ��ʽ�� 
//              ���롣�ñ�����μ�CameraDefine.h��[ͼ���ʽ����]���֡�   
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetMediaType)(
	CameraHandle    hCamera, 
	INT             iMediaType
	);
	
/// @ingroup API_ADVANCE
/// \~chinese
/// \brief ��ȡRAW���ݵ������Чλ��
/// \param [in] hCamera ����ľ����
/// \param [out] pMaxAvailBits	����RAW�������Чλ��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the maximum number of significant bits of RAW data
/// \param [in] hCamera Camera handle.
/// \param [out] pMaxAvailBits	returns the maximum number of significant bits of RAW data
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetRawMaxAvailBits)(
	CameraHandle    hCamera,
	int*           pMaxAvailBits
	);

/// @ingroup API_ADVANCE
/// \~chinese
/// \brief ����RAW���ݵ������ʼλ
/// \param [in] hCamera ����ľ����
/// \param [in] startBit ��ʼBIT��Ĭ�������8λ��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the output start bit of RAW data
/// \param [in] hCamera Camera handle.
/// \param [in] startBit Start BIT (The high 8 bits are output by default)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetRawStartBit)(
	CameraHandle    hCamera,
	int             startBit
	);

/// @ingroup API_ADVANCE
/// \~chinese
/// \brief ��ȡRAW���ݵ������ʼλ
/// \param [in] hCamera ����ľ����
/// \param [out] startBit ��ʼBIT
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the output start bit of RAW data
/// \param [in] hCamera Camera handle.
/// \param [out] startBit Start BIT
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetRawStartBit)(
	CameraHandle    hCamera,
	int*            startBit
	);

/******************************************************/
// ������   : CameraSetAeState
// �������� : ��������ع��ģʽ���Զ������ֶ���
// ����     : hCamera   ����ľ������CameraInit������á�
//            bAeState    TRUE��ʹ���Զ��ع⣻FALSE��ֹͣ�Զ��ع⡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetAeState)(
	CameraHandle    hCamera, 
	BOOL            bAeState
	);

/******************************************************/
// ������   : CameraGetAeState
// �������� : ��������ǰ���ع�ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pAeState   ָ�룬���ڷ����Զ��ع��ʹ��״̬��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetAeState)(
	CameraHandle    hCamera, 
	BOOL*           pAeState
	);

/******************************************************/
// ������   : CameraSetSharpness
// �������� : ����ͼ��Ĵ�����񻯲�����
// ����     : hCamera  ����ľ������CameraInit������á�
//            iSharpness �񻯲�������Χ��CameraGetCapability
//               ��ã�һ����[0,100]��0��ʾ�ر��񻯴���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetSharpness)(
	CameraHandle    hCamera, 
	int             iSharpness
	);

/******************************************************/
// ������   : CameraGetSharpness
// �������� : ��ȡ��ǰ���趨ֵ��
// ����     : hCamera   ����ľ������CameraInit������á�
//            piSharpness ָ�룬���ص�ǰ�趨���񻯵��趨ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetSharpness)(
	CameraHandle    hCamera, 
	int*            piSharpness
	);

/******************************************************/
// ������   : CameraSetLutMode
// �������� : ��������Ĳ��任ģʽLUTģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            emLutMode  LUTMODE_PARAM_GEN ��ʾ��٤��ͶԱȶȲ�����̬����LUT��
//             LUTMODE_PRESET    ��ʾʹ��Ԥ���LUT��
//             LUTMODE_USER_DEF  ��ʾʹ���û��Զ���LUT��
//             LUTMODE_PARAM_GEN�Ķ���ο�CameraDefine.h��emSdkLutMode���͡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetLutMode)(
	CameraHandle    hCamera,
	int             emLutMode
	);

/******************************************************/
// ������   : CameraGetLutMode
// �������� : �������Ĳ��任ģʽLUTģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pemLutMode ָ�룬���ص�ǰLUTģʽ��������CameraSetLutMode
//             ��emLutMode������ͬ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetLutMode)(
	CameraHandle    hCamera,
	int*            pemLutMode
	);

/******************************************************/
// ������   : CameraSelectLutPreset
// �������� : ѡ��Ԥ��LUTģʽ�µ�LUT��������ʹ��CameraSetLutMode
//        ��LUTģʽ����ΪԤ��ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iSel     ��������š���ĸ�����CameraGetCapability
//             ��á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSelectLutPreset)(
	CameraHandle    hCamera,
	int             iSel
	);

/******************************************************/
// ������   : CameraGetLutPresetSel
// �������� : ���Ԥ��LUTģʽ�µ�LUT�������š�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piSel      ָ�룬���ر�������š�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetLutPresetSel)(
	CameraHandle    hCamera,
	int*            piSel
	);

/******************************************************/
// ������   : CameraSetCustomLut
// �������� : �����Զ����LUT��������ʹ��CameraSetLutMode
//        ��LUTģʽ����Ϊ�Զ���ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//             iChannel ָ��Ҫ�趨��LUT��ɫͨ������ΪLUT_CHANNEL_ALLʱ��
//                      ����ͨ����LUT����ͬʱ�滻��
//                      �ο�CameraDefine.h��emSdkLutChannel���塣
//            pLut     ָ�룬ָ��LUT��ĵ�ַ��LUT��Ϊ�޷��Ŷ��������飬�����СΪ
//           4096���ֱ������ɫͨ����0��4096(12bit��ɫ����)��Ӧ��ӳ��ֵ�� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetCustomLut)(
	CameraHandle    hCamera,
	int       iChannel,
	USHORT*         pLut
	);

/******************************************************/
// ������   : CameraGetCustomLut
// �������� : ��õ�ǰʹ�õ��Զ���LUT��
// ����     : hCamera  ����ľ������CameraInit������á�
//             iChannel ָ��Ҫ��õ�LUT��ɫͨ������ΪLUT_CHANNEL_ALLʱ��
//                      ���غ�ɫͨ����LUT��
//                      �ο�CameraDefine.h��emSdkLutChannel���塣
//            pLut       ָ�룬ָ��LUT��ĵ�ַ��LUT��Ϊ�޷��Ŷ��������飬�����СΪ
//           4096���ֱ������ɫͨ����0��4096(12bit��ɫ����)��Ӧ��ӳ��ֵ�� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetCustomLut)(
	CameraHandle    hCamera,
	int       iChannel,
	USHORT*         pLut
	);

/******************************************************/
// ������   : CameraGetCurrentLut
// �������� : ��������ǰ��LUT�����κ�LUTģʽ�¶����Ե���,
//        ����ֱ�۵Ĺ۲�LUT���ߵı仯��
// ����     : hCamera  ����ľ������CameraInit������á�
//             iChannel ָ��Ҫ��õ�LUT��ɫͨ������ΪLUT_CHANNEL_ALLʱ��
//                      ���غ�ɫͨ����LUT��
//                      �ο�CameraDefine.h��emSdkLutChannel���塣
//            pLut       ָ�룬ָ��LUT��ĵ�ַ��LUT��Ϊ�޷��Ŷ��������飬�����СΪ
//           4096���ֱ������ɫͨ����0��4096(12bit��ɫ����)��Ӧ��ӳ��ֵ�� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetCurrentLut)(
	CameraHandle    hCamera,
	int       iChannel,
	USHORT*         pLut
	);

/******************************************************/
// ������   : CameraSetWbMode
// �������� : ���������ƽ��ģʽ����Ϊ�ֶ����Զ����ַ�ʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bAuto      TRUE�����ʾʹ���Զ�ģʽ��
//             FALSE�����ʾʹ���ֶ�ģʽ��ͨ������
//                 CameraSetOnceWB������һ�ΰ�ƽ�⡣        
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetWbMode)(
	CameraHandle    hCamera,
	BOOL            bAuto
	);

/******************************************************/
// ������   : CameraGetWbMode
// �������� : ��õ�ǰ�İ�ƽ��ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbAuto   ָ�룬����TRUE��ʾ�Զ�ģʽ��FALSE
//             Ϊ�ֶ�ģʽ�� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetWbMode)(
	CameraHandle    hCamera,
	BOOL*           pbAuto
	);

/******************************************************/
// ������   : CameraSetPresetClrTemp
// �������� : ѡ��ָ��Ԥ��ɫ��ģʽ
// ����     : hCamera  ����ľ������CameraInit������á�
//            iSel Ԥ��ɫ�µ�ģʽ�����ţ���0��ʼ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetPresetClrTemp)(
	CameraHandle    hCamera,
	int             iSel
	);

/******************************************************/
// ������   : CameraGetPresetClrTemp
// �������� : ��õ�ǰѡ���Ԥ��ɫ��ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            piSel  ָ�룬����ѡ���Ԥ��ɫ��������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetPresetClrTemp)(
	CameraHandle    hCamera,
	int*            piSel
	);

/******************************************************/
// ������   : CameraSetUserClrTempGain
// �������� : �����Զ���ɫ��ģʽ�µ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            iRgain  ��ɫ���棬��Χ0��400����ʾ0��4��
//            iGgain  ��ɫ���棬��Χ0��400����ʾ0��4��
//            iBgain  ��ɫ���棬��Χ0��400����ʾ0��4��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetUserClrTempGain)(
	CameraHandle  hCamera,
	int       iRgain,
	int       iGgain,
	int       iBgain
	);


/******************************************************/
// ������   : CameraGetUserClrTempGain
// �������� : ����Զ���ɫ��ģʽ�µ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            piRgain  ָ�룬���غ�ɫ���棬��Χ0��400����ʾ0��4��
//            piGgain  ָ�룬������ɫ���棬��Χ0��400����ʾ0��4��
//            piBgain  ָ�룬������ɫ���棬��Χ0��400����ʾ0��4��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetUserClrTempGain)(
	CameraHandle  hCamera,
	int*      piRgain,
	int*      piGgain,
	int*      piBgain
	);

/******************************************************/
// ������   : CameraSetUserClrTempMatrix
// �������� : �����Զ���ɫ��ģʽ�µ���ɫ����
// ����     : hCamera  ����ľ������CameraInit������á�
//            pMatrix ָ��һ��float[3][3]������׵�ַ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetUserClrTempMatrix)(
	CameraHandle  hCamera,
	float*      pMatrix
	);


/******************************************************/
// ������   : CameraGetUserClrTempMatrix
// �������� : ����Զ���ɫ��ģʽ�µ���ɫ����
// ����     : hCamera  ����ľ������CameraInit������á�
//            pMatrix ָ��һ��float[3][3]������׵�ַ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetUserClrTempMatrix)(
	CameraHandle  hCamera,
	float*      pMatrix
	);

/******************************************************/
// ������   : CameraSetClrTempMode
// �������� : ���ð�ƽ��ʱʹ�õ�ɫ��ģʽ��
//              ֧�ֵ�ģʽ�����֣��ֱ����Զ���Ԥ����Զ��塣
//              �Զ�ģʽ�£����Զ�ѡ����ʵ�ɫ��ģʽ
//              Ԥ��ģʽ�£���ʹ���û�ָ����ɫ��ģʽ
//              �Զ���ģʽ�£�ʹ���û��Զ����ɫ����������;���
// ����     : hCamera ����ľ������CameraInit������á�
//            iMode ģʽ��ֻ����emSdkClrTmpMode�ж����һ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetClrTempMode)(
	CameraHandle  hCamera,
	int       iMode
	);

/******************************************************/
// ������   : CameraGetClrTempMode
// �������� : ��ð�ƽ��ʱʹ�õ�ɫ��ģʽ���ο�CameraSetClrTempMode
//              �й����������֡�
// ����     : hCamera ����ľ������CameraInit������á�
//            pimode ָ�룬����ģʽѡ�񣬲ο�emSdkClrTmpMode���Ͷ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetClrTempMode)(
	CameraHandle  hCamera,
	int*      pimode
	);


/******************************************************/
// ������   : CameraSetOnceWB
// �������� : ���ֶ���ƽ��ģʽ�£����øú��������һ�ΰ�ƽ�⡣
//        ��Ч��ʱ��Ϊ���յ���һ֡ͼ������ʱ��
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetOnceWB)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraSetOnceBB
// �������� : ִ��һ�κ�ƽ�������
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetOnceBB)(
	CameraHandle    hCamera
	);


/******************************************************/
// ������   : CameraSetAeTarget
// �������� : �趨�Զ��ع������Ŀ��ֵ���趨��Χ��CameraGetCapability
//        ������á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iAeTarget  ����Ŀ��ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetAeTarget)(
	CameraHandle    hCamera, 
	int             iAeTarget
	);

/******************************************************/
// ������   : CameraGetAeTarget
// �������� : ����Զ��ع������Ŀ��ֵ��
// ����     : hCamera   ����ľ������CameraInit������á�
//            *piAeTarget ָ�룬����Ŀ��ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetAeTarget)(
	CameraHandle    hCamera, 
	int*            piAeTarget
	);

/******************************************************/
// ������   : CameraSetAeExposureRange
// �������� : �趨�Զ��ع�ģʽ���ع�ʱ����ڷ�Χ
// ����     : hCamera  ����ľ������CameraInit������á�
//           fMinExposureTime ��С�ع�ʱ�䣨΢�룩
//			 fMaxExposureTime ����ع�ʱ�䣨΢�룩
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetAeExposureRange)(
	CameraHandle    hCamera, 
	double          fMinExposureTime,
	double			fMaxExposureTime
	);

/******************************************************/
// ������   : CameraGetAeExposureRange
// �������� : ����Զ��ع�ģʽ���ع�ʱ����ڷ�Χ
// ����     : hCamera   ����ľ������CameraInit������á�
//           fMinExposureTime ��С�ع�ʱ�䣨΢�룩
//			 fMaxExposureTime ����ع�ʱ�䣨΢�룩
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetAeExposureRange)(
	CameraHandle    hCamera, 
	double*         fMinExposureTime,
	double*			fMaxExposureTime
	);

/******************************************************/
// ������   : CameraSetAeAnalogGainRange
// �������� : �趨�Զ��ع�ģʽ��������ڷ�Χ
// ����     : hCamera  ����ľ������CameraInit������á�
//           iMinAnalogGain ��С����
//			 iMaxAnalogGain �������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetAeAnalogGainRange)(
	CameraHandle    hCamera, 
	int				iMinAnalogGain,
	int				iMaxAnalogGain
	);

/******************************************************/
// ������   : CameraGetAeAnalogGainRange
// �������� : ����Զ��ع�ģʽ��������ڷ�Χ
// ����     : hCamera   ����ľ������CameraInit������á�
//           iMinAnalogGain ��С����
//			 iMaxAnalogGain �������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetAeAnalogGainRange)(
	CameraHandle    hCamera, 
	int*			iMinAnalogGain,
	int*			iMaxAnalogGain
	);

/******************************************************/
// ������   : CameraSetAeThreshold
// �������� : �����Զ��ع�ģʽ�ĵ�����ֵ
// ����     : hCamera   ����ľ������CameraInit������á�
//           iThreshold   ��� abs(Ŀ������-ͼ������) < iThreshold ��ֹͣ�Զ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetAeThreshold)(
	CameraHandle    hCamera, 
	int				iThreshold
	);

/******************************************************/
// ������   : CameraGetAeThreshold
// �������� : ��ȡ�Զ��ع�ģʽ�ĵ�����ֵ
// ����     : hCamera   ����ľ������CameraInit������á�
//           iThreshold   ��ȡ���ĵ�����ֵ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetAeThreshold)(
	CameraHandle    hCamera, 
	int*			iThreshold
	);

/******************************************************/
// ������   : CameraSetExposureTime
// �������� : �����ع�ʱ�䡣��λΪ΢�롣����CMOS�����������ع�
//        �ĵ�λ�ǰ�����������ģ���ˣ��ع�ʱ�䲢������΢��
//        ���������ɵ������ǻᰴ��������ȡ�ᡣ�ڵ���
//        �������趨�ع�ʱ��󣬽����ٵ���CameraGetExposureTime
//        �����ʵ���趨��ֵ��
// ����     : hCamera      ����ľ������CameraInit������á�
//            fExposureTime �ع�ʱ�䣬��λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetExposureTime)(
	CameraHandle    hCamera, 
	double          fExposureTime
	);

//******************************************************/
// ������   : CameraGetExposureLineTime
// �������� : ���һ�е��ع�ʱ�䡣����CMOS�����������ع�
//        �ĵ�λ�ǰ�����������ģ���ˣ��ع�ʱ�䲢������΢��
//        ���������ɵ������ǻᰴ��������ȡ�ᡣ���������
//          ���þ��Ƿ���CMOS����ع�һ�ж�Ӧ��ʱ�䡣
// ����     : hCamera  ����ľ������CameraInit������á�
//            double *pfLineTime ָ�룬����һ�е��ع�ʱ�䣬��λΪ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/

typedef    CameraSdkStatus (__stdcall *_CameraGetExposureLineTime)(
	CameraHandle    hCamera, 
	double*         pfLineTime
	);

/******************************************************/
// ������   : CameraGetExposureTime
// �������� : ���������ع�ʱ�䡣��μ�CameraSetExposureTime
//        �Ĺ���������
// ����     : hCamera        ����ľ������CameraInit������á�
//            pfExposureTime  ָ�룬���ص�ǰ���ع�ʱ�䣬��λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetExposureTime)(
	CameraHandle    hCamera, 
	double*         pfExposureTime
	);

/******************************************************/
// ������   : CameraGetExposureTimeRange
// �������� : ���������ع�ʱ�䷶Χ
// ����     : hCamera        ����ľ������CameraInit������á�
//            pfMin			ָ�룬�����ع�ʱ�����Сֵ����λ΢�롣
//            pfMax			ָ�룬�����ع�ʱ������ֵ����λ΢�롣
//            pfStep		ָ�룬�����ع�ʱ��Ĳ���ֵ����λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetExposureTimeRange)(
	CameraHandle    hCamera, 
	double*         pfMin,
	double*			pfMax,
	double*			pfStep
	);
	
/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ���ö����ع�ʱ�䡣��λΪ΢�롣(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [in] index �ع�������
/// \param [in] fExposureTime �ع�ʱ�䣬��λ΢�롣
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \note ����CMOS�����������ع�ĵ�λ�ǰ�����������ģ���ˣ��ع�ʱ�䲢������΢�뼶�������ɵ������ǻᰴ��������ȡ�ᡣ�ڵ��ñ������趨�ع�ʱ��󣬽����ٵ���@link #CameraGetMultiExposureTime @endlink�����ʵ���趨��ֵ��
/// \~english
/// \brief Set the multiple exposure time. The unit is microseconds. (This feature is only supported by line camera)
/// \param [in] hCamera Camera handle.
/// \param [in] index Exposure index.
/// \param [in] fExposureTime Exposure time in microseconds.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \note For CMOS sensors, the unit of exposure is calculated in rows, so the exposure time cannot be continuously adjusted in microseconds. Instead, the entire line will be chosen. After calling this function to set the exposure time, it is recommended to call @link #CameraGetMultiExposureTime @endlink to get the actual set value.
typedef    CameraSdkStatus (__stdcall *_CameraSetMultiExposureTime)(
	CameraHandle    hCamera, 
	int				index,
	double          fExposureTime
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع�ʱ�䡣��λΪ΢�롣(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [in] index �ع�������
/// \param [out] fExposureTime �����ع�ʱ�䣬��λ΢�롣
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the multiple exposure time. The unit is microseconds. (This feature is only supported by line camera)
/// \param [in] hCamera Camera handle.
/// \param [in] index Exposure index.
/// \param [out] fExposureTime Returns exposure time in microseconds.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureTime)(
	CameraHandle    hCamera, 
	int				index,
	double*         fExposureTime
	);
	
/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ���ö����ع��gammaֵ��(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [in] index �ع�������
/// \param [in] iGamma Ҫ�趨��Gammaֵ��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \note �趨��ֵ�����ϱ�����SDK�ڲ�������ֻ�е�������ڶ�̬�������ɵ�LUTģʽʱ���Ż���Ч����ο�@link #CameraSetLutMode @endlink�ĺ���˵�����֡�
/// \~english
/// \brief Sets the gamma value for multiple exposures. (This function is only supported by line scan cameras)
/// \param [in] hCamera Camera handle.
/// \param [in] index Exposure index.
/// \param [in] iGamma The gamma to be set.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \note The set value will be stored in the SDK immediately, but it will only take effect when the camera is in LUT mode generated by dynamic parameters. Please refer to the function description part of @link #CameraSetLutMode @endlink.
typedef    CameraSdkStatus (__stdcall *_CameraSetMultiExposureGamma)(
	CameraHandle    hCamera, 
	int				index,
	int             iGamma
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع��gammaֵ��(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [in] index �ع�������
/// \param [out] piGamma  ָ�룬���ص�Gammaֵ��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \see CameraSetMultiExposureGamma
/// \~english
/// \brief Get the gamma value for multiple exposures. (This function is only supported by line scan cameras)
/// \param [in] hCamera Camera handle.
/// \param [in] index Exposure index.
/// \param [out] piGamma Returns the gamma value.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \see CameraSetMultiExposureGamma
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureGamma)(
	CameraHandle    hCamera, 
	int				index,
	int*            piGamma
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ���ö����ع�ʹ�ܸ�����(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [in] count ʹ�ܸ�����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the number of multiple exposure enable. (This feature is only supported by line camera)
/// \param [in] hCamera Camera handle.
/// \param [in] count The number of exposures enabled.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetMultiExposureCount)(
	CameraHandle    hCamera, 
	int				count
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع�ʹ�ܸ�����(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [out] count ʹ�ܸ�����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the number of multiple exposure enable. (This feature is only supported by line camera)
/// \param [in] hCamera Camera handle.
/// \param [out] count The number of exposures enabled.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureCount)(
	CameraHandle    hCamera, 
	int*			count
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع������ع������(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [out] max_count ֧�ֵ�����ع������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the maximum number of exposures for multiple exposures. (This feature is only supported by line camera)
/// \param [in] hCamera Camera handle.
/// \param [out] max_count The maximum number of exposures supported.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureMaxCount)(
	CameraHandle    hCamera, 
	int*			max_count
	);
	
/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع�Ĺ���֧��λ��(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [out] pSupported ֧�ֵĹ��ܡ���bit0: gamma��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the function support bits for multiple exposures. (This function is only supported by line scan cameras)
/// \param [in] hCamera Camera handle.
/// \param [out] pSupported Supported functions. (bit0: gamma)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureSupported)(
	CameraHandle    hCamera, 
	UINT*			pSupported
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع�Ļ�Ϲ���֧��λ��(�˹��ܽ��������֧��)
/// \param [in] hCamera ����ľ����
/// \param [out] pSupported ֧�ֵĻ�ϸ�������bit0=1֧��2���ع�Ļ�ϣ�bit1=1֧��3�� ��������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the blend function support bit for multiple exposures. (This function is only supported by line scan cameras)
/// \param [in] hCamera Camera handle.
/// \param [out] pSupported The number of mixes supported. (bit0=1 supports the mixing of 2 exposures, bit1=1 supports 3 exposures...)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureBlendingSupported)(
	CameraHandle    hCamera, 
	UINT*			pSupported
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ���ý��ö����ع�Ļ�Ϲ��ܡ�
/// \param [in] hCamera ����ľ����
/// \param [in] bEnable �Ƿ�����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Enables and disables the blending function for multiple exposures.
/// \param [in] hCamera Camera handle.
/// \param [in] bEnable Whether to enable
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetMultiExposureBlendingEnable)(
	CameraHandle    hCamera, 
	BOOL			bEnable
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع�Ļ�Ϲ����Ƿ�����
/// \param [in] hCamera ����ľ����
/// \param [out] pbEnable ��������״̬
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get whether the blending function of multiple exposures is enabled
/// \param [in] hCamera Camera handle.
/// \param [out] pbEnable returns enable status
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureBlendingEnable)(
	CameraHandle    hCamera, 
	BOOL*			pbEnable
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ���ö����ع��ϵ�ϵ��
/// \param [in] hCamera ����ľ����
/// \param [in] pRatios ϵ��ָ�루ϵ��ȡֵ��Χ0-100����ʾ%0-%100��
/// \param [in] iNumRatios ϵ��������ϵ������=�ع�����-1������3���ع��ֻ������2��ϵ����ϵ��3=100-(ϵ��1+ϵ��2)��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief set the multi-exposure blend coefficient
/// \param [in] hCamera Camera handle.
/// \param [in] pRatios coefficient pointer (coefficient value range 0-1.0 and the sum of all coefficients <= 1.0)
/// \param [in] iNumRatios Number of coefficients (number of coefficients = number of exposures - 1, for example, only 2 coefficients need to be configured for 3 exposures, coefficient 3 = 1.0-(coefficient 1 + coefficient 2))
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetMultiExposureBlendingRatios)(
	CameraHandle    hCamera, 
	int*			pRatios,
	int				iNumRatios
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��ȡ�����ع��ϵ�ϵ��
/// \param [in] hCamera ����ľ����
/// \param [out] pRatios ϵ��ָ��
/// \param [inout] piNumRatios ϵ�����������룺����ǰ����ΪpRatios�����С   ��������ض�ȡ����ϵ������(�ع�����-1)
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the coefficient of multiple exposure blending
/// \param [in] hCamera Camera handle.
/// \param [out] pRatios coefficient pointer
/// \param [inout] piNumRatios number of coefficients, input: set to pRatios array size before calling   Output: return the number of coefficients read (number of exposures - 1)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetMultiExposureBlendingRatios)(
	CameraHandle    hCamera, 
	int*			pRatios,
	int*			piNumRatios
	);

/******************************************************/
// ������   : CameraSetAnalogGain
// �������� : ���������ͼ��ģ������ֵ����ֵ����CameraGetCapability���
//        ��������Խṹ����sExposeDesc.fAnalogGainStep����
//        �õ�ʵ�ʵ�ͼ���źŷŴ�����
// ����     : hCamera   ����ľ������CameraInit������á�
//            iAnalogGain �趨��ģ������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetAnalogGain)(
	CameraHandle    hCamera,
	INT             iAnalogGain
	);

/******************************************************/
// ������   : CameraGetAnalogGain
// �������� : ���ͼ���źŵ�ģ������ֵ���μ�CameraSetAnalogGain
//        ��ϸ˵����
// ����     : hCamera    ����ľ������CameraInit������á�
//            piAnalogGain ָ�룬���ص�ǰ��ģ������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetAnalogGain)(
	CameraHandle    hCamera, 
	INT*            piAnalogGain
	);
	
/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ���������ģ������Ŵ�����
/// \param [in] hCamera ����ľ����
/// \param [in] fGain �趨��ģ������Ŵ�����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the image gain magnification of the camera.
/// \param [in] hCamera Camera handle.
/// \param [in] fGain Gain magnification.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetAnalogGainX)(
	CameraHandle    hCamera,
	float    		fGain
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ���ͼ���źŵ�ģ������Ŵ�����
/// \param [in] hCamera ����ľ����
/// \param [out] pfGain ָ�룬���ص�ǰ��ģ������Ŵ�����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \see CameraSetAnalogGainX
/// \~english
/// \brief Obtain the gain magnification of the image signal.
/// \param [in] hCamera Camera handle.
/// \param [out] pfGain pointer, returns the current gain magnification.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \see CameraSetAnalogGainX
typedef    CameraSdkStatus (__stdcall *_CameraGetAnalogGainX)(
	CameraHandle    hCamera, 
	float*          pfGain
	);

/// @ingroup API_EXPOSURE
/// \~chinese
/// \brief ��������ģ������Ŵ���ȡֵ��Χ
/// \param [in] hCamera		����ľ����
/// \param [out] pfMin		ָ�룬������С������
/// \param [out] pfMax		ָ�룬�����������
/// \param [out] pfStep		ָ�룬���ز���ֵ��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the value range of the camera's gain magnification
/// \param [in] hCamera		Camera handle.
/// \param [out] pfMin		pointer, returns the minimum multiple.
/// \param [out] pfMax		pointer, returns the maximum multiple.
/// \param [out] pfStep		pointer, returns the step value.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetAnalogGainXRange)(
	CameraHandle	hCamera, 
	float*			pfMin,
	float*			pfMax,
	float*			pfStep
	);

/******************************************************/
// ������   : CameraSetGain
// �������� : ����ͼ����������档�趨��Χ��CameraGetCapability
//        ��õ�������Խṹ����sRgbGainRange��Ա������
//        ʵ�ʵķŴ������趨ֵ/100��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iRGain   ��ɫͨ��������ֵ�� 
//            iGGain   ��ɫͨ��������ֵ��
//            iBGain   ��ɫͨ��������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetGain)(
	CameraHandle    hCamera, 
	int             iRGain, 
	int             iGGain, 
	int             iBGain
	);


/******************************************************/
// ������   : CameraGetGain
// �������� : ���ͼ������������档������μ�CameraSetGain
//        �Ĺ����������֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piRGain  ָ�룬���غ�ɫͨ������������ֵ��
//            piGGain    ָ�룬������ɫͨ������������ֵ��
//            piBGain    ָ�룬������ɫͨ������������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetGain)(
	CameraHandle    hCamera, 
	int*            piRGain, 
	int*            piGGain, 
	int*            piBGain
	);


/******************************************************/
// ������   : CameraSetGamma
// �������� : �趨LUT��̬����ģʽ�µ�Gammaֵ���趨��ֵ��
//        ���ϱ�����SDK�ڲ�������ֻ�е�������ڶ�̬
//        �������ɵ�LUTģʽʱ���Ż���Ч����ο�CameraSetLutMode
//        �ĺ���˵�����֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iGamma     Ҫ�趨��Gammaֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetGamma)(
	CameraHandle    hCamera, 
	int             iGamma
	);

/******************************************************/
// ������   : CameraGetGamma
// �������� : ���LUT��̬����ģʽ�µ�Gammaֵ����ο�CameraSetGamma
//        �����Ĺ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            piGamma    ָ�룬���ص�ǰ��Gammaֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetGamma)(
	CameraHandle    hCamera, 
	int*            piGamma
	);

/******************************************************/
// ������   : CameraSetContrast
// �������� : �趨LUT��̬����ģʽ�µĶԱȶ�ֵ���趨��ֵ��
//        ���ϱ�����SDK�ڲ�������ֻ�е�������ڶ�̬
//        �������ɵ�LUTģʽʱ���Ż���Ч����ο�CameraSetLutMode
//        �ĺ���˵�����֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iContrast  �趨�ĶԱȶ�ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetContrast)(
	CameraHandle    hCamera, 
	int             iContrast
	);

/******************************************************/
// ������   : CameraGetContrast
// �������� : ���LUT��̬����ģʽ�µĶԱȶ�ֵ����ο�
//        CameraSetContrast�����Ĺ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            piContrast ָ�룬���ص�ǰ�ĶԱȶ�ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetContrast)(
	CameraHandle    hCamera, 
	int*            piContrast
	);

/******************************************************/
// ������   : CameraSetSaturation
// �������� : �趨ͼ����ı��Ͷȡ��Ժڰ������Ч��
//        �趨��Χ��CameraGetCapability��á�100��ʾ
//        ��ʾԭʼɫ�ȣ�����ǿ��
// ����     : hCamera    ����ľ������CameraInit������á�
//            iSaturation  �趨�ı��Ͷ�ֵ�� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetSaturation)(
	CameraHandle    hCamera, 
	int             iSaturation
	);

/******************************************************/
// ������   : CameraGetSaturation
// �������� : ���ͼ����ı��Ͷȡ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            piSaturation ָ�룬���ص�ǰͼ����ı��Ͷ�ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetSaturation)(
	CameraHandle    hCamera, 
	int*            piSaturation
	);

/******************************************************/
// ������   : CameraSetMonochrome
// �������� : ���ò�ɫתΪ�ڰ׹��ܵ�ʹ�ܡ�
// ����     : hCamera ����ľ������CameraInit������á�
//            bEnable   TRUE����ʾ����ɫͼ��תΪ�ڰס�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetMonochrome)(
	CameraHandle    hCamera, 
	BOOL            bEnable
	);

/******************************************************/
// ������   : CameraGetMonochrome
// �������� : ��ò�ɫת���ڰ׹��ܵ�ʹ��״����
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbEnable   ָ�롣����TRUE��ʾ�����˲�ɫͼ��
//             ת��Ϊ�ڰ�ͼ��Ĺ��ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetMonochrome)(
	CameraHandle    hCamera, 
	BOOL*           pbEnable
	);

/******************************************************/
// ������   : CameraSetInverse
// �������� : ���ò�ͼ����ɫ��ת���ܵ�ʹ�ܡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            bEnable    TRUE����ʾ����ͼ����ɫ��ת���ܣ�
//             ���Ի�����ƽ����Ƭ��Ч����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetInverse)(
	CameraHandle    hCamera, 
	BOOL            bEnable
	);

/******************************************************/
// ������   : CameraGetInverse
// �������� : ���ͼ����ɫ��ת���ܵ�ʹ��״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbEnable   ָ�룬���ظù���ʹ��״̬�� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetInverse)(
	CameraHandle    hCamera, 
	BOOL*           pbEnable
	);

/******************************************************/
// ������   : CameraSetAntiFlick
// �������� : �����Զ��ع�ʱ��Ƶ�����ܵ�ʹ��״̬�������ֶ�
//        �ع�ģʽ����Ч��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bEnable    TRUE��������Ƶ������;FALSE���رոù��ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetAntiFlick)(
	CameraHandle    hCamera,
	BOOL            bEnable
	);

/******************************************************/
// ������   : CameraGetAntiFlick
// �������� : ����Զ��ع�ʱ��Ƶ�����ܵ�ʹ��״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbEnable   ָ�룬���ظù��ܵ�ʹ��״̬��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetAntiFlick)(
	CameraHandle    hCamera, 
	BOOL*           pbEnable
	);

/******************************************************/
// ������   : CameraGetLightFrequency
// �������� : ����Զ��ع�ʱ����Ƶ����Ƶ��ѡ��
// ����     : hCamera      ����ľ������CameraInit������á�
//            piFrequencySel ָ�룬����ѡ��������š�0:50HZ 1:60HZ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetLightFrequency)(
	CameraHandle    hCamera, 
	int*            piFrequencySel
	);

/******************************************************/
// ������   : CameraSetLightFrequency
// �������� : �����Զ��ع�ʱ��Ƶ����Ƶ�ʡ�
// ����     : hCamera     ����ľ������CameraInit������á�
//            iFrequencySel 0:50HZ , 1:60HZ 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetLightFrequency)(
	CameraHandle    hCamera,
	int             iFrequencySel
	);

/******************************************************/
// ������   : CameraSetFrameSpeed
// �������� : �趨������ͼ���֡�ʡ�����ɹ�ѡ���֡��ģʽ��
//        CameraGetCapability��õ���Ϣ�ṹ����iFrameSpeedDesc
//        ��ʾ���֡��ѡ��ģʽ������
// ����     : hCamera   ����ľ������CameraInit������á�
//            iFrameSpeed ѡ���֡��ģʽ�����ţ���Χ��0��
//              CameraGetCapability��õ���Ϣ�ṹ����iFrameSpeedDesc - 1   
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetFrameSpeed)(
	CameraHandle    hCamera, 
	int             iFrameSpeed
	);

/******************************************************/
// ������   : CameraGetFrameSpeed
// �������� : ���������ͼ���֡��ѡ�������š������÷��ο�
//        CameraSetFrameSpeed�����Ĺ����������֡�
// ����     : hCamera    ����ľ������CameraInit������á�
//            piFrameSpeed ָ�룬����ѡ���֡��ģʽ�����š� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetFrameSpeed)(
	CameraHandle    hCamera, 
	int*            piFrameSpeed
	);

/// @ingroup API_ADVANCE
/// \~chinese
/// \brief �趨�����֡Ƶ(����)����Ƶ(����)�����������������֧�֣�
/// \param [in] hCamera ����ľ����
/// \param [in] uRateHZ ֡Ƶ����Ƶ��<=0��ʾ���Ƶ�ʣ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the frame frequency (area) or line frequency (line scan). (only supported by some gige camera)
/// \param [in] hCamera Camera handle.
/// \param [in] uRateHZ frame rate or line rate (<=0 means maximum frequency).
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetFrameRate)(
	CameraHandle    hCamera, 
	int             RateHZ
	);

/// @ingroup API_ADVANCE
/// \~chinese
/// \brief ��ȡ�趨�����֡Ƶ(����)����Ƶ(����)
/// \param [in] hCamera ����ľ����
/// \param [out] uRateHZ ֡Ƶ����Ƶ��<=0��ʾ���Ƶ�ʣ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the frame frequency (area) or line frequency (line scan).
/// \param [in] hCamera Camera handle.
/// \param [out] uRateHZ frame rate or line rate (<=0 means maximum frequency).
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetFrameRate)(
	CameraHandle    hCamera, 
	int*            RateHZ
	);

/******************************************************/
// ������   : CameraSetParameterMode
// �������� : �趨������ȡ��Ŀ�����
// ����     : hCamera  ����ľ������CameraInit������á�
//            iMode  ������ȡ�Ķ��󡣲ο�CameraDefine.h
//          ��emSdkParameterMode�����Ͷ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetParameterMode)(
	CameraHandle    hCamera, 
	int             iTarget
	);

/******************************************************/
// ������   : CameraGetParameterMode
// �������� : 
// ����     : hCamera  ����ľ������CameraInit������á�
//            int* piTarget
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetParameterMode)(
	CameraHandle    hCamera, 
	int*            piTarget
	);

/******************************************************/
// ������   : CameraSetParameterMask
// �������� : ���ò�����ȡ�����롣�������غͱ���ʱ����ݸ�
//        ��������������ģ��������Ƿ���ػ��߱��档
// ����     : hCamera ����ľ������CameraInit������á�
//            uMask     ���롣�ο�CameraDefine.h��PROP_SHEET_INDEX
//            ���Ͷ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetParameterMask)(
	CameraHandle    hCamera, 
	UINT            uMask
	);

/******************************************************/
// ������   : CameraSaveParameter
// �������� : ���浱ǰ���������ָ���Ĳ������С�����ṩ��A,B,C,D
//        A,B,C,D����ռ������в����ı��档 
// ����     : hCamera  ����ľ������CameraInit������á�
//            iTeam      PARAMETER_TEAM_A ���浽A����,
//             PARAMETER_TEAM_B ���浽B����,
//             PARAMETER_TEAM_C ���浽C����,
//             PARAMETER_TEAM_D ���浽D����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSaveParameter)(
	CameraHandle    hCamera, 
	int             iTeam
	);

/******************************************************/
// ������   : CameraReadParameterFromFile
// �������� : ��PC��ָ���Ĳ����ļ��м��ز������ҹ�˾�������
//        ������PC��Ϊ.config��׺���ļ���λ�ڰ�װ�µ�
//        Camera\Configs�ļ����С�
// ����     : hCamera  ����ľ������CameraInit������á�
//            *sFileName �����ļ�������·����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraReadParameterFromFile)(
	CameraHandle    hCamera,
	char*           sFileName
	);

/******************************************************/
// ������   : CameraLoadParameter
// �������� : ����ָ����Ĳ���������С�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iTeam    PARAMETER_TEAM_A ����A�����,
//             PARAMETER_TEAM_B ����B�����,
//             PARAMETER_TEAM_C ����C�����,
//             PARAMETER_TEAM_D ����D�����,
//             PARAMETER_TEAM_DEFAULT ����Ĭ�ϲ�����    
//             ���Ͷ���ο�CameraDefine.h��emSdkParameterTeam����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraLoadParameter)(
	CameraHandle    hCamera, 
	int             iTeam
	);

/******************************************************/
// ������   : CameraGetCurrentParameterGroup
// �������� : ��õ�ǰѡ��Ĳ����顣
// ����     : hCamera  ����ľ������CameraInit������á�
//            piTeam     ָ�룬���ص�ǰѡ��Ĳ����顣����ֵ
//             �ο�CameraLoadParameter��iTeam������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetCurrentParameterGroup)(
	CameraHandle    hCamera, 
	int*            piTeam
	);

/******************************************************/
// ������   : CameraSetTransPackLen
// �������� : �����������ͼ�����ݵķְ���С��
//        Ŀǰ��SDK�汾�У��ýӿڽ���GIGE�ӿ������Ч��
//        �����������紫��ķְ���С������֧�־�֡��������
//        ���ǽ���ѡ��8K�ķְ���С��������Ч�Ľ��ʹ���
//        ��ռ�õ�CPU����ʱ�䡣
// ����     : hCamera  ����ľ������CameraInit������á�
//            iPackSel   �ְ�����ѡ��������š��ְ����ȿ���
//             ���������Խṹ����pPackLenDesc��Ա������
//             iPackLenDesc��Ա���ʾ����ѡ�ķְ�ģʽ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetTransPackLen)(
	CameraHandle    hCamera, 
	INT             iPackSel
	);

/******************************************************/
// ������   : CameraGetTransPackLen
// �������� : ��������ǰ����ְ���С��ѡ�������š�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piPackSel  ָ�룬���ص�ǰѡ��ķְ���С�����š�
//             �μ�CameraSetTransPackLen��iPackSel��
//             ˵����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetTransPackLen)(
	CameraHandle    hCamera, 
	INT*            piPackSel
	);

/******************************************************/
// ������   : CameraIsAeWinVisible
// �������� : ����Զ��ع�ο����ڵ���ʾ״̬��
// ����     : hCamera    ����ľ������CameraInit������á�
//            pbIsVisible  ָ�룬����TRUE�����ʾ��ǰ���ڻ�
//               ��������ͼ�������ϡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraIsAeWinVisible)(
	CameraHandle    hCamera,
	BOOL*           pbIsVisible
	);

/******************************************************/
// ������   : CameraSetAeWinVisible
// �������� : �����Զ��ع�ο����ڵ���ʾ״̬�������ô���״̬
//        Ϊ��ʾ������CameraImageOverlay���ܹ�������λ��
//        �Ծ��εķ�ʽ������ͼ���ϡ�
// ����     : hCamera   ����ľ������CameraInit������á�
//            bIsVisible  TRUE������Ϊ��ʾ��FALSE������ʾ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetAeWinVisible)(
	CameraHandle    hCamera,
	BOOL            bIsVisible
	);

/******************************************************/
// ������   : CameraGetAeWindow
// �������� : ����Զ��ع�ο����ڵ�λ�á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piHOff     ָ�룬���ش���λ�����ϽǺ�����ֵ��
//            piVOff     ָ�룬���ش���λ�����Ͻ�������ֵ��
//            piWidth    ָ�룬���ش��ڵĿ�ȡ�
//            piHeight   ָ�룬���ش��ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetAeWindow)(
	CameraHandle    hCamera, 
	INT*            piHOff, 
	INT*            piVOff, 
	INT*            piWidth, 
	INT*            piHeight
	);

/******************************************************/
// ������   : CameraSetAeWindow
// �������� : �����Զ��ع�Ĳο����ڡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iHOff    �������Ͻǵĺ�����
//            iVOff      �������Ͻǵ�������
//            iWidth     ���ڵĿ�� 
//            iHeight    ���ڵĸ߶�
//        ���iHOff��iVOff��iWidth��iHeightȫ��Ϊ0����
//        ��������Ϊÿ���ֱ����µľ���1/2��С����������
//        �ֱ��ʵı仯������仯�����iHOff��iVOff��iWidth��iHeight
//        �������Ĵ���λ�÷�Χ�����˵�ǰ�ֱ��ʷ�Χ�ڣ� 
//          ���Զ�ʹ�þ���1/2��С���ڡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetAeWindow)(
	CameraHandle    hCamera, 
	int             iHOff, 
	int             iVOff, 
	int             iWidth, 
	int             iHeight
	);

/******************************************************/
// ������   : CameraSetMirror
// �������� : ����ͼ������������������Ϊˮƽ�ʹ�ֱ��������
// ����     : hCamera  ����ľ������CameraInit������á�
//            iDir     ��ʾ����ķ���0����ʾˮƽ����1����ʾ��ֱ����
//            bEnable  TRUE��ʹ�ܾ���;FALSE����ֹ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetMirror)(
	CameraHandle    hCamera, 
	int             iDir, 
	BOOL            bEnable
	);

/******************************************************/
// ������   : CameraGetMirror
// �������� : ���ͼ��ľ���״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iDir     ��ʾҪ��õľ�����
//             0����ʾˮƽ����1����ʾ��ֱ����
//            pbEnable   ָ�룬����TRUE�����ʾiDir��ָ�ķ���
//             ����ʹ�ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetMirror)(
	CameraHandle    hCamera, 
	int             iDir, 
	BOOL*           pbEnable
	);
	
/// @ingroup API_MIRROR
/// \~chinese
/// \brief ����Ӳ�����񡣷�Ϊˮƽ�ʹ�ֱ�������򡣣����������ڡ�U3���֧�ִ˹��ܣ�
/// \param [in] hCamera ����ľ����
/// \param [in] iDir     ��ʾ����ķ���0����ʾˮƽ����1����ʾ��ֱ����
/// \param [in] bEnable  TRUE��ʹ�ܾ���;FALSE����ֹ����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set up the hardware mirror. Divided into two directions, horizontal and vertical. (Only some GigE and U3 cameras support this feature)
/// \param [in] hCamera Camera handle.
/// \param [in] iDir Indicates the direction of the mirror. 0 means horizontal direction; 1 means vertical direction.
/// \param [in] bEnable TRUE to enable mirroring; FALSE to disable mirroring
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetHardwareMirror)(
	CameraHandle    hCamera, 
	int             iDir, 
	BOOL            bEnable
	);

/// @ingroup API_MIRROR
/// \~chinese
/// \brief ��ȡ���õ�Ӳ������״̬��
/// \param [in] hCamera ����ľ����
/// \param [in] iDir     ��ʾҪ��õľ�����0����ʾˮƽ����1����ʾ��ֱ����
/// \param [out] pbEnable   ָ�룬����TRUE�����ʾiDir��ָ�ķ�����ʹ�ܡ�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the hardware mirrored state of the image.
/// \param [in] hCamera Camera handle.
/// \param [in] iDir Indicates the mirroring direction to be obtained. 0 means horizontal direction; 1 means vertical direction.
/// \param [out] pbEnable Returns TRUE, indicating that the direction mirror image of iDir is enabled.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetHardwareMirror)(
	CameraHandle    hCamera, 
	int             iDir, 
	BOOL*           pbEnable
	);

/******************************************************/
// ������   : CameraSetRotate
// �������� : ����ͼ����ת����
// ����     : hCamera  ����ľ������CameraInit������á�
//            iRot     ��ʾ��ת�ĽǶȣ���ʱ�뷽�򣩣�0������ת 1:90�� 2:180�� 3:270�ȣ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetRotate)(
	CameraHandle    hCamera, 
	int             iRot 
	);

/******************************************************/
// ������   : CameraGetRotate
// �������� : ���ͼ�����ת״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iRot     ��ʾҪ��õ���ת����
//               ����ʱ�뷽�򣩣�0������ת 1:90�� 2:180�� 3:270�ȣ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetRotate)(
	CameraHandle    hCamera, 
	int*            iRot 
	);

/******************************************************/
// ������   : CameraGetWbWindow
// �������� : ��ð�ƽ��ο����ڵ�λ�á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            PiHOff   ָ�룬���زο����ڵ����ϽǺ����� ��
//            PiVOff     ָ�룬���زο����ڵ����Ͻ������� ��
//            PiWidth    ָ�룬���زο����ڵĿ�ȡ�
//            PiHeight   ָ�룬���زο����ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetWbWindow)(
	CameraHandle    hCamera, 
	INT*            PiHOff, 
	INT*            PiVOff, 
	INT*            PiWidth, 
	INT*            PiHeight
	);

/******************************************************/
// ������   : CameraSetWbWindow
// �������� : ���ð�ƽ��ο����ڵ�λ�á�
// ����     : hCamera ����ľ������CameraInit������á�
//            iHOff   �ο����ڵ����ϽǺ����ꡣ
//            iVOff     �ο����ڵ����Ͻ������ꡣ
//            iWidth    �ο����ڵĿ�ȡ�
//            iHeight   �ο����ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetWbWindow)(
	CameraHandle    hCamera, 
	INT             iHOff, 
	INT             iVOff, 
	INT             iWidth, 
	INT             iHeight
	);

/******************************************************/
// ������   : CameraIsWbWinVisible
// �������� : ��ð�ƽ�ⴰ�ڵ���ʾ״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbShow   ָ�룬����TRUE�����ʾ�����ǿɼ��ġ� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraIsWbWinVisible)(
	CameraHandle    hCamera,
	BOOL*           pbShow
	);

/******************************************************/
// ������   : CameraSetWbWinVisible
// �������� : ���ð�ƽ�ⴰ�ڵ���ʾ״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bShow      TRUE�����ʾ����Ϊ�ɼ����ڵ���
//             CameraImageOverlay��ͼ�������Ͻ��Ծ���
//             �ķ�ʽ���Ӱ�ƽ��ο����ڵ�λ�á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetWbWinVisible)(
	CameraHandle    hCamera, 
	BOOL            bShow
	);

/******************************************************/
// ������   : CameraImageOverlay
// �������� : �������ͼ�������ϵ���ʮ���ߡ���ƽ��ο����ڡ�
//        �Զ��ع�ο����ڵ�ͼ�Ρ�ֻ������Ϊ�ɼ�״̬��
//        ʮ���ߺͲο����ڲ��ܱ������ϡ�
//        ע�⣬�ú���������ͼ�������RGB��ʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pRgbBuffer ͼ�����ݻ�������
//            pFrInfo    ͼ���֡ͷ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraImageOverlay)(
	CameraHandle    hCamera,
	BYTE*           pRgbBuffer,
	tSdkFrameHead*  pFrInfo
	);

/******************************************************/
// ������   : CameraSetCrossLine
// �������� : ����ָ��ʮ���ߵĲ�����
// ����     : hCamera  ����ľ������CameraInit������á�
//            iLine    ��ʾҪ���õڼ���ʮ���ߵ�״̬����ΧΪ[0,8]����9����    
//            x          ʮ��������λ�õĺ�����ֵ��
//            y      ʮ��������λ�õ�������ֵ��
//            uColor     ʮ���ߵ���ɫ����ʽΪ(R|(G<<8)|(B<<16))
//            bVisible   ʮ���ߵ���ʾ״̬��TRUE����ʾ��ʾ��
//             ֻ������Ϊ��ʾ״̬��ʮ���ߣ��ڵ���
//             CameraImageOverlay��Żᱻ���ӵ�ͼ���ϡ�     
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetCrossLine)(
	CameraHandle    hCamera, 
	int             iLine, 
	INT             x,
	INT             y,
	UINT            uColor,
	BOOL            bVisible
	);

/******************************************************/
// ������   : CameraGetCrossLine
// �������� : ���ָ��ʮ���ߵ�״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iLine    ��ʾҪ��ȡ�ĵڼ���ʮ���ߵ�״̬����ΧΪ[0,8]����9����  
//            px     ָ�룬���ظ�ʮ��������λ�õĺ����ꡣ
//            py     ָ�룬���ظ�ʮ��������λ�õĺ����ꡣ
//            pcolor     ָ�룬���ظ�ʮ���ߵ���ɫ����ʽΪ(R|(G<<8)|(B<<16))��
//            pbVisible  ָ�룬����TRUE�����ʾ��ʮ���߿ɼ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetCrossLine)(
	CameraHandle    hCamera, 
	INT             iLine,
	INT*            px,
	INT*            py,
	UINT*           pcolor,
	BOOL*           pbVisible
	);

/******************************************************/
// ������   : CameraGetCapability
// �������� : �����������������ṹ�塣�ýṹ���а��������
//        �����õĸ��ֲ����ķ�Χ��Ϣ����������غ����Ĳ���
//        ���أ�Ҳ�����ڶ�̬������������ý��档
// ����     : hCamera   ����ľ������CameraInit������á�
//            pCameraInfo ָ�룬���ظ�������������Ľṹ�塣
//                        tSdkCameraCapbility��CameraDefine.h�ж��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetCapability)(
	CameraHandle            hCamera, 
	tSdkCameraCapbility*    pCameraInfo
	);

/******************************************************/
// ������   : CameraWriteSN
// �������� : ������������кš��ҹ�˾������кŷ�Ϊ3����
//        0�������ҹ�˾�Զ����������кţ�����ʱ�Ѿ�
//        �趨�ã�1����2���������ο���ʹ�á�ÿ������
//        �ų��ȶ���32���ֽڡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbySN    ���кŵĻ������� 
//            iLevel   Ҫ�趨�����кż���ֻ����1����2��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraWriteSN)(
	CameraHandle    hCamera, 
	BYTE*           pbySN, 
	INT             iLevel
	);

/******************************************************/
// ������   : CameraReadSN
// �������� : ��ȡ���ָ����������кš����кŵĶ�����ο�
//          CameraWriteSN�����Ĺ����������֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbySN    ���кŵĻ�������
//            iLevel     Ҫ��ȡ�����кż���ֻ����1��2��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraReadSN)(
	CameraHandle        hCamera, 
	BYTE*               pbySN, 
	INT                 iLevel
	);
/******************************************************/
// ������   : CameraSetTriggerDelayTime
// �������� : ����Ӳ������ģʽ�µĴ�����ʱʱ�䣬��λ΢�롣
//        ��Ӳ�����ź����ٺ󣬾���ָ������ʱ���ٿ�ʼ�ɼ�
//        ͼ�񡣽������ͺŵ����֧�ָù��ܡ�������鿴
//        ��Ʒ˵���顣
// ����     : hCamera    ����ľ������CameraInit������á�
//            uDelayTimeUs Ӳ������ʱ����λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetTriggerDelayTime)(
	CameraHandle    hCamera, 
	UINT            uDelayTimeUs
	);

/******************************************************/
// ������   : CameraGetTriggerDelayTime
// �������� : ��õ�ǰ�趨��Ӳ������ʱʱ�䡣
// ����     : hCamera     ����ľ������CameraInit������á�
//            puDelayTimeUs ָ�룬������ʱʱ�䣬��λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetTriggerDelayTime)(
	CameraHandle    hCamera, 
	UINT*           puDelayTimeUs
	);

/******************************************************/
// ������   : CameraSetTriggerCount
// �������� : ���ô���ģʽ�µĴ���֡���������������Ӳ������
//        ģʽ����Ч��Ĭ��Ϊ1֡����һ�δ����źŲɼ�һ֡ͼ��
// ����     : hCamera ����ľ������CameraInit������á�
//            iCount    һ�δ����ɼ���֡����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetTriggerCount)(
	CameraHandle    hCamera, 
	INT             iCount
	);

/******************************************************/
// ������   : CameraGetTriggerCount
// �������� : ���һ�δ�����֡����
// ����     : hCamera  ����ľ������CameraInit������á�
//            INT* piCount
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetTriggerCount)(
	CameraHandle    hCamera, 
	INT*            piCount
	);

/******************************************************/
// ������   : CameraSoftTrigger
// �������� : ִ��һ��������ִ�к󣬻ᴥ����CameraSetTriggerCount
//          ָ����֡����
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSoftTrigger)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraSetTriggerMode
// �������� : ��������Ĵ���ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iModeSel   ģʽѡ�������š����趨��ģʽ��
//             CameraGetCapability������ȡ����ο�
//               CameraDefine.h��tSdkCameraCapbility�Ķ��塣
//             һ�������0��ʾ�����ɼ�ģʽ��1��ʾ
//             �������ģʽ��2��ʾӲ������ģʽ��  
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetTriggerMode)(
	CameraHandle    hCamera, 
	int             iModeSel
	);

/******************************************************/
// ������   : CameraGetTriggerMode
// �������� : �������Ĵ���ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            piModeSel  ָ�룬���ص�ǰѡ����������ģʽ�������š�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetTriggerMode)(
	CameraHandle    hCamera,
	INT*            piModeSel
	);

/******************************************************/
// ������ 	: CameraSetStrobeMode
// ��������	: ����IO���Ŷ����ϵ�STROBE�źš����źſ���������ƿ��ƣ�Ҳ�������ⲿ��е���ſ��ơ�
// ����	    : hCamera ����ľ������CameraInit������á�
//             iMode   ��ΪSTROBE_SYNC_WITH_TRIG_AUTO      �ʹ����ź�ͬ������������������ع�ʱ���Զ�����STROBE�źš�
//                                                         ��ʱ����Ч���Կ�����(CameraSetStrobePolarity)��
//                     ��ΪSTROBE_SYNC_WITH_TRIG_MANUALʱ���ʹ����ź�ͬ����������STROBE��ʱָ����ʱ���(CameraSetStrobeDelayTime)��
//                                                         �ٳ���ָ��ʱ�������(CameraSetStrobePulseWidth)��
//                                                         ��Ч���Կ�����(CameraSetStrobePolarity)��
//                     ��ΪSTROBE_ALWAYS_HIGHʱ��STROBE�źź�Ϊ��,������������
//                     ��ΪSTROBE_ALWAYS_LOWʱ��STROBE�źź�Ϊ��,������������
//
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetStrobeMode)(
	CameraHandle    hCamera, 
	INT             iMode
	);

/******************************************************/
// ������ 	: CameraGetStrobeMode
// ��������	: ���ߵ�ǰSTROBE�ź����õ�ģʽ��
// ����	    : hCamera ����ľ������CameraInit������á�
//             piMode  ָ�룬����STROBE_SYNC_WITH_TRIG_AUTO,STROBE_SYNC_WITH_TRIG_MANUAL��STROBE_ALWAYS_HIGH����STROBE_ALWAYS_LOW��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetStrobeMode)(
	CameraHandle    hCamera, 
	INT*            piMode
	);

/******************************************************/
// ������ 	: CameraSetStrobeDelayTime
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú�����������Դ����ź���ʱʱ�䡣
// ����	    : hCamera       ����ľ������CameraInit������á�
//             uDelayTimeUs  ��Դ����źŵ���ʱʱ�䣬��λΪus������Ϊ0��������Ϊ������ 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetStrobeDelayTime)(
	CameraHandle    hCamera, 
	UINT            uDelayTimeUs
	);

/******************************************************/
// ������ 	: CameraGetStrobeDelayTime
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú����������Դ����ź���ʱʱ�䡣
// ����	    : hCamera           ����ľ������CameraInit������á�
//             upDelayTimeUs     ָ�룬������ʱʱ�䣬��λus��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetStrobeDelayTime)(
	CameraHandle    hCamera, 
	UINT*           upDelayTimeUs
	);

/******************************************************/
// ������ 	: CameraSetStrobePulseWidth
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú��������������ȡ�
// ����	    : hCamera       ����ľ������CameraInit������á�
//             uTimeUs       ����Ŀ�ȣ���λΪʱ��us��  
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetStrobePulseWidth)(
	CameraHandle    hCamera, 
	UINT            uTimeUs
	);

/******************************************************/
// ������ 	: CameraGetStrobePulseWidth
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú�������������ȡ�
// ����	    : hCamera   ����ľ������CameraInit������á�
//             upTimeUs  ָ�룬���������ȡ���λΪʱ��us��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetStrobePulseWidth)(
	CameraHandle    hCamera, 
	UINT*           upTimeUs
	);


/******************************************************/
// ������ 	: CameraSetStrobePolarity
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú�����������Ч��ƽ�ļ��ԡ�Ĭ��Ϊ����Ч���������źŵ���ʱ��STROBE�źű����ߡ�
// ����	    : hCamera   ����ľ������CameraInit������á�
//             iPolarity STROBE�źŵļ��ԣ�0Ϊ�͵�ƽ��Ч��1Ϊ�ߵ�ƽ��Ч��Ĭ��Ϊ�ߵ�ƽ��Ч��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetStrobePolarity)(
	CameraHandle    hCamera, 
	INT             iPolarity
	);

/******************************************************/
// ������ 	: CameraGetStrobePolarity
// ��������	: ��������ǰSTROBE�źŵ���Ч���ԡ�Ĭ��Ϊ�ߵ�ƽ��Ч��
// ����	    : hCamera       ����ľ������CameraInit������á�
//             ipPolarity    ָ�룬����STROBE�źŵ�ǰ����Ч���ԡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetStrobePolarity)(
	CameraHandle    hCamera, 
	INT*            ipPolarity
	);

/******************************************************/
// ������ 	: CameraSetExtTrigSignalType
// ��������	: ��������ⴥ���źŵ����ࡣ�ϱ��ء��±��ء����߸ߡ��͵�ƽ��ʽ��
// ����	    : hCamera   ����ľ������CameraInit������á�
//             iType     �ⴥ���ź����࣬����ֵ�ο�CameraDefine.h��
//                       emExtTrigSignal���Ͷ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetExtTrigSignalType)(
	CameraHandle    hCamera, 
	INT             iType
	);

/******************************************************/
// ������ 	: CameraGetExtTrigSignalType
// ��������	: ��������ǰ�ⴥ���źŵ����ࡣ
// ����	    : hCamera   ����ľ������CameraInit������á�
//             ipType    ָ�룬�����ⴥ���ź����࣬����ֵ�ο�CameraDefine.h��
//                       emExtTrigSignal���Ͷ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetExtTrigSignalType)(
	CameraHandle    hCamera, 
	INT*            ipType
	);

/******************************************************/
// ������ 	: CameraSetExtTrigShutterType
// ��������	: �����ⴥ��ģʽ�£�������ŵķ�ʽ��Ĭ��Ϊ��׼���ŷ�ʽ��
//              ���ֹ������ŵ�CMOS���֧��GRR��ʽ��
// ����	    : hCamera   ����ľ������CameraInit������á�
//             iType     �ⴥ�����ŷ�ʽ���ο�CameraDefine.h��emExtTrigShutterMode���͡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetExtTrigShutterType)(
	CameraHandle    hCamera, 
	INT             iType
	);

/******************************************************/
// ������ 	: CameraSetExtTrigShutterType
// ��������	: ����ⴥ��ģʽ�£�������ŵķ�ʽ��Ĭ��Ϊ��׼���ŷ�ʽ��
//              ���ֹ������ŵ�CMOS���֧��GRR��ʽ��
// ����	    : hCamera   ����ľ������CameraInit������á�
//             ipType    ָ�룬���ص�ǰ�趨���ⴥ�����ŷ�ʽ������ֵ�ο�
//                       CameraDefine.h��emExtTrigShutterMode���͡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetExtTrigShutterType)(
	CameraHandle    hCamera, 
	INT*            ipType
	);

/******************************************************/
// ������ 	: CameraSetExtTrigDelayTime
// ��������	: �����ⴥ���ź���ʱʱ�䣬Ĭ��Ϊ0����λΪ΢�롣 
//              �����õ�ֵuDelayTimeUs��Ϊ0ʱ��������յ��ⴥ���źź󣬽���ʱuDelayTimeUs��΢����ٽ���ͼ�񲶻�
// ����	    : hCamera       ����ľ������CameraInit������á�
//             uDelayTimeUs  ��ʱʱ�䣬��λΪ΢�룬Ĭ��Ϊ0.
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetExtTrigDelayTime)(
	CameraHandle    hCamera, 
	UINT            uDelayTimeUs
	);

/******************************************************/
// ������ 	: CameraGetExtTrigDelayTime
// ��������	: ������õ��ⴥ���ź���ʱʱ�䣬Ĭ��Ϊ0����λΪ΢�롣 
// ����	    : hCamera   ����ľ������CameraInit������á�
//            UINT* upDelayTimeUs
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetExtTrigDelayTime)(
	CameraHandle    hCamera, 
	UINT*           upDelayTimeUs
	);

/// @ingroup API_TRIGGER
/// \~chinese
/// \brief �����ⴥ���źż��ʱ�䣬Ĭ��Ϊ0����λΪ΢�롣 
/// \param [in] hCamera ����ľ����
/// \param [in] uTimeUs  ���ʱ�䣬��λΪ΢�룬Ĭ��Ϊ0.
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the interval time of external trigger signal. The default is 0 and the unit is microsecond.
/// \param [in] hCamera Camera handle.
/// \param [in] uTimeUs Interval time in microseconds. Default is 0.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraSetExtTrigIntervalTime)(
	CameraHandle    hCamera, 
	UINT            uTimeUs
	);

/// @ingroup API_TRIGGER
/// \~chinese
/// \brief ������õ��ⴥ���źż��ʱ�䣬Ĭ��Ϊ0����λΪ΢�롣
/// \param [in] hCamera ����ľ����
/// \param [out] upTimeUs �������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the set external trigger signal interval time, the default is 0, the unit is microseconds.
/// \param [in] hCamera Camera handle.
/// \param [out] upTimeUs trigger interval
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef    CameraSdkStatus (__stdcall *_CameraGetExtTrigIntervalTime)(
	CameraHandle    hCamera, 
	UINT*           upTimeUs
	);

/******************************************************/
// ������ 	: CameraSetExtTrigJitterTime
// ��������	: ��������ⴥ���źŵ�����ʱ�䡣Ĭ��Ϊ0����λΪ΢�롣
// ����	    : hCamera   ����ľ������CameraInit������á�
//            UINT uTimeUs
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetExtTrigJitterTime)(
	CameraHandle    hCamera,
	UINT            uTimeUs
	);

/******************************************************/
// ������ 	: CameraGetExtTrigJitterTime
// ��������	: ������õ�����ⴥ������ʱ�䣬Ĭ��Ϊ0.��λΪ΢��
// ����	    : hCamera   ����ľ������CameraInit������á�
//            UINT* upTimeUs
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetExtTrigJitterTime)(
	CameraHandle    hCamera,
	UINT*           upTimeUs
	);

/******************************************************/
// ������ 	: CameraGetExtTrigCapability
// ��������	: �������ⴥ������������
// ����	    : hCamera           ����ľ������CameraInit������á�
//             puCapabilityMask  ָ�룬���ظ�����ⴥ���������룬����ο�CameraDefine.h��
//                               EXT_TRIG_MASK_ ��ͷ�ĺ궨�塣   
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetExtTrigCapability)(
	CameraHandle    hCamera,
	UINT*           puCapabilityMask
	);

typedef CameraSdkStatus (__stdcall *_CameraPauseLevelTrigger)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraGetResolutionForSnap
// �������� : ���ץ��ģʽ�µķֱ���ѡ�������š�
// ����     : hCamera        ����ľ������CameraInit������á�
//            pImageResolution ָ�룬����ץ��ģʽ�ķֱ��ʡ� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetResolutionForSnap)(
	CameraHandle            hCamera,
	tSdkImageResolution*    pImageResolution
	);

/******************************************************/
// ������   : CameraSetResolutionForSnap
// �������� : ����ץ��ģʽ��������ͼ��ķֱ��ʡ�
// ����     : hCamera       ����ľ������CameraInit������á�
//            pImageResolution ���pImageResolution->iWidth 
//                 �� pImageResolution->iHeight��Ϊ0��
//                         ���ʾ�趨Ϊ���浱ǰԤ���ֱ��ʡ�ץ
//                         �µ���ͼ��ķֱ��ʻ�͵�ǰ�趨�� 
//                 Ԥ���ֱ���һ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetResolutionForSnap)(
	CameraHandle            hCamera, 
	tSdkImageResolution*    pImageResolution
	);

/******************************************************/
// ������   : CameraCustomizeResolution
// �������� : �򿪷ֱ����Զ�����壬��ͨ�����ӻ��ķ�ʽ
//        ������һ���Զ���ֱ��ʡ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            pImageCustom ָ�룬�����Զ���ķֱ��ʡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraCustomizeResolution)(
	CameraHandle            hCamera,
	tSdkImageResolution*    pImageCustom
	);

/******************************************************/
// ������   : CameraCustomizeReferWin
// �������� : �򿪲ο������Զ�����塣��ͨ�����ӻ��ķ�ʽ��
//        ���һ���Զ��崰�ڵ�λ�á�һ�������Զ����ƽ��
//        ���Զ��ع�Ĳο����ڡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iWinType   Ҫ���ɵĲο����ڵ���;��0,�Զ��ع�ο����ڣ�
//             1,��ƽ��ο����ڡ�
//            hParent    ���øú����Ĵ��ڵľ��������ΪNULL��
//            piHOff     ָ�룬�����Զ��崰�ڵ����ϽǺ����ꡣ
//            piVOff     ָ�룬�����Զ��崰�ڵ����Ͻ������ꡣ
//            piWidth    ָ�룬�����Զ��崰�ڵĿ�ȡ� 
//            piHeight   ָ�룬�����Զ��崰�ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraCustomizeReferWin)(
	CameraHandle    hCamera,
	INT             iWinType,
	HWND            hParent, 
	INT*            piHOff,
	INT*            piVOff,
	INT*            piWidth,
	INT*            piHeight
	);

/******************************************************/
// ������   : CameraShowSettingPage
// �������� : ��������������ô�����ʾ״̬�������ȵ���CameraCreateSettingPage
//        �ɹ���������������ô��ں󣬲��ܵ��ñ���������
//        ��ʾ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bShow    TRUE����ʾ;FALSE�����ء�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraShowSettingPage)(
	CameraHandle    hCamera,
	BOOL            bShow
	);

/******************************************************/
// ������   : CameraCreateSettingPage
// �������� : ������������������ô��ڡ����øú�����SDK�ڲ���
//        ������������������ô��ڣ�ʡȥ�������¿������
//        ���ý����ʱ�䡣ǿ�ҽ���ʹ����ʹ�øú�����
//        SDKΪ�����������ô��ڡ�
// ����     : hCamera     ����ľ������CameraInit������á�
//            hParent       Ӧ�ó��������ڵľ��������ΪNULL��
//            pWinText      �ַ���ָ�룬������ʾ�ı�������
//            pCallbackFunc ������Ϣ�Ļص�����������Ӧ���¼�����ʱ��
//              pCallbackFunc��ָ��ĺ����ᱻ���ã�
//              �����л��˲���֮��Ĳ���ʱ��pCallbackFunc
//              ���ص�ʱ������ڲ�����ָ������Ϣ���͡�
//              �������Է������Լ������Ľ�����������ɵ�UI
//              ֮�����ͬ�����ò�������ΪNULL��    
//            pCallbackCtx  �ص������ĸ��Ӳ���������ΪNULL��pCallbackCtx
//              ����pCallbackFunc���ص�ʱ����Ϊ����֮һ���롣
//              ������ʹ�øò�������һЩ�����жϡ�
//            uReserved     Ԥ������������Ϊ0��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraCreateSettingPage)(
	CameraHandle            hCamera,
	HWND                    hParent,
	char*                   pWinText,
	CAMERA_PAGE_MSG_PROC    pCallbackFunc,
	PVOID                   pCallbackCtx,
	UINT                    uReserved
	);

/******************************************************/
// ������   : CameraSetActiveSettingSubPage
// �������� : ����������ô��ڵļ���ҳ�档������ô����ж��
//        ��ҳ�湹�ɣ��ú��������趨��ǰ��һ����ҳ��
//        Ϊ����״̬����ʾ����ǰ�ˡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            index      ��ҳ��������š��ο�CameraDefine.h��
//             PROP_SHEET_INDEX�Ķ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetActiveSettingSubPage)(
	CameraHandle    hCamera,
	INT             index
	);

typedef    CameraSdkStatus (__stdcall *_CameraSetSettingPageParent)(
	CameraHandle    hCamera,
	HWND            hParentWnd,
	DWORD			Flags
	);

typedef    CameraSdkStatus (__stdcall *_CameraGetSettingPageHWnd)(
	CameraHandle    hCamera,
	HWND*           hWnd
	);
	
typedef    CameraSdkStatus (__stdcall *_CameraUpdateSettingPage)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraSpecialControl
// �������� : ���һЩ�������������õĽӿڣ����ο���ʱһ�㲻��Ҫ
//        ���á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            dwCtrlCode �����롣
//            dwParam    �������룬��ͬ��dwCtrlCodeʱ�����岻ͬ��
//            lpData     ���Ӳ�������ͬ��dwCtrlCodeʱ�����岻ͬ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSpecialControl)(
	CameraHandle    hCamera, 
	DWORD           dwCtrlCode,
	DWORD           dwParam,
	LPVOID          lpData
	);

/******************************************************/
// ������   : CameraGetFrameStatistic
// �������� : ����������֡�ʵ�ͳ����Ϣ����������֡�Ͷ�֡�������
// ����     : hCamera        ����ľ������CameraInit������á�
//            psFrameStatistic ָ�룬����ͳ����Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetFrameStatistic)(
	CameraHandle            hCamera, 
	tSdkFrameStatistic*     psFrameStatistic
	);

/******************************************************/
// ������   : CameraSetNoiseFilter
// �������� : ����ͼ����ģ���ʹ��״̬��
// ����     : hCamera ����ľ������CameraInit������á�
//            bEnable   TRUE��ʹ�ܣ�FALSE����ֹ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraSetNoiseFilter)(
	CameraHandle    hCamera,
	BOOL            bEnable
	);

/******************************************************/
// ������   : CameraGetNoiseFilterState
// �������� : ���ͼ����ģ���ʹ��״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            *pEnable   ָ�룬����״̬��TRUE��Ϊʹ�ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraGetNoiseFilterState)(
	CameraHandle    hCamera,
	BOOL*           pEnable
	);


/******************************************************/
// ������   : CameraRstTimeStamp
// �������� : ��λͼ��ɼ���ʱ�������0��ʼ��
// ����     : CameraHandle hCamera
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef    CameraSdkStatus (__stdcall *_CameraRstTimeStamp)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraGetCapabilityEx
// �������� : �����������������ṹ�塣�ýṹ���а��������
//        �����õĸ��ֲ����ķ�Χ��Ϣ����������غ����Ĳ���
//        ���أ�Ҳ�����ڶ�̬������������ý��档
// ����     : sDeviceModel    ������ͺţ���ɨ���б��л�ȡ
//             pCameraInfo   ָ�룬���ظ�������������Ľṹ�塣
//             PVOID         hCameraHandle
//            tSdkCameraCapbility��CameraDefine.h�ж��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetCapabilityEx)(
	char*                   sDeviceModel, 
	tSdkCameraCapbility*    pCameraInfo,
	PVOID                   hCameraHandle
	);

/******************************************************/
// ������   : CameraFreeCapabilityEx
// �������� : 
//        ���أ�Ҳ�����ڶ�̬������������ý��档
// ����     : sDeviceModel    ������ͺţ���ɨ���б��л�ȡ
//            hCameraHandle  ָ��
//                        tSdkCameraCapbility��CameraDefine.h�ж��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraFreeCapabilityEx)(
	char*                   sDeviceModel, 
	PVOID                   hCameraHandle
	);



/******************************************************/
// ������   : CameraSaveUserData
// �������� : ���û��Զ�������ݱ��浽����ķ����Դ洢���С�
//              ÿ���ͺŵ��������֧�ֵ��û���������󳤶Ȳ�һ����
//              ���Դ��豸�����������л�ȡ�ó�����Ϣ��
// ����     : hCamera    ����ľ������CameraInit������á�
//            uStartAddr  ��ʼ��ַ����0��ʼ��
//            pbData      ���ݻ�����ָ��
//            ilen        д�����ݵĳ��ȣ�ilen + uStartAddr����
//                        С���û�����󳤶�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSaveUserData)(
	CameraHandle    hCamera,
	UINT            uStartAddr,
	BYTE            *pbData,
	int             ilen
	);

/******************************************************/
// ������   : CameraLoadUserData
// �������� : ������ķ����Դ洢���ж�ȡ�û��Զ�������ݡ�
//              ÿ���ͺŵ��������֧�ֵ��û���������󳤶Ȳ�һ����
//              ���Դ��豸�����������л�ȡ�ó�����Ϣ��
// ����     : hCamera    ����ľ������CameraInit������á�
//            uStartAddr  ��ʼ��ַ����0��ʼ��
//            pbData      ���ݻ�����ָ�룬���ض��������ݡ�
//            ilen        ��ȡ���ݵĳ��ȣ�ilen + uStartAddr����
//                        С���û�����󳤶�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraLoadUserData)(
	CameraHandle    hCamera,
	UINT            uStartAddr,
	BYTE            *pbData,
	int             ilen
	);



/******************************************************/
// ������   : CameraGetFriendlyName
// �������� : ��ȡ�û��Զ�����豸�ǳơ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            pName      ָ�룬����ָ��0��β���ַ�����
//             �豸�ǳƲ�����32���ֽڣ���˸�ָ��
//             ָ��Ļ�����������ڵ���32���ֽڿռ䡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetFriendlyName)(
	CameraHandle  hCamera,
	char*     pName
	);


/******************************************************/
// ������   : CameraSetFriendlyName
// �������� : �����û��Զ�����豸�ǳơ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            pName      ָ�룬ָ��0��β���ַ�����
//             �豸�ǳƲ�����32���ֽڣ���˸�ָ��
//             ָ���ַ�������С�ڵ���32���ֽڿռ䡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetFriendlyName)(
	CameraHandle  hCamera,
	char*       pName
	);


/******************************************************/
// ������   : CameraSdkGetVersionString
// �������� : 
// ����     : pVersionString ָ�룬����SDK�汾�ַ�����
//                            ��ָ��ָ��Ļ�������С�������
//                            32���ֽ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSdkGetVersionString)(
	char*       pVersionString
	);

/******************************************************/
// ������   : CameraCheckFwUpdate
// �������� : ���̼��汾���Ƿ���Ҫ������
// ����     : hCamera ����ľ������CameraInit������á�
//            pNeedUpdate ָ�룬���ع̼����״̬��TRUE��ʾ��Ҫ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraCheckFwUpdate)(
	CameraHandle  hCamera,
	BOOL*     pNeedUpdate
	);

/******************************************************/
// ������   : CameraGetFirmwareVersion
// �������� : ��ù̼��汾���ַ���
// ����     : hCamera ����ľ������CameraInit������á�
//            pVersion ����ָ��һ������32�ֽڵĻ�������
//                      ���ع̼��İ汾�ַ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetFirmwareVersion)(
	CameraHandle  hCamera,
	char*     pVersion
	);

/******************************************************/
// ������   : CameraGetFirmwareVision
// �������� : ��ù̼��汾���ַ���
// ����     : hCamera ����ľ������CameraInit������á�
//            pVersion ����ָ��һ������32�ֽڵĻ�������
//                      ���ع̼��İ汾�ַ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetFirmwareVision)(
	CameraHandle  hCamera,
	char*     pVersion
	);

/******************************************************/
// ������   : CameraGetEnumInfo
// �������� : ���ָ���豸��ö����Ϣ
// ����     : hCamera ����ľ������CameraInit������á�
//            pCameraInfo ָ�룬�����豸��ö����Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetEnumInfo)(
	CameraHandle    hCamera,
	tSdkCameraDevInfo*  pCameraInfo
	);

/******************************************************/
// ������   : CameraGetInerfaceVersion
// �������� : ���ָ���豸�ӿڵİ汾
// ����     : hCamera ����ľ������CameraInit������á�
//            pVersion ָ��һ������32�ֽڵĻ����������ؽӿڰ汾�ַ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetInerfaceVersion)(
	CameraHandle    hCamera,
	char*       pVersion
	);

/******************************************************/
// ������   : CameraSetIOState
// �������� : ����ָ��IO�ĵ�ƽ״̬��IOΪ�����IO�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iOutputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�
//            iOutputIOIndex IO�������ţ���0��ʼ��
//            uState Ҫ�趨��״̬��1Ϊ�ߣ�0Ϊ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetIOState)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	UINT        uState
	);

typedef CameraSdkStatus (__stdcall *_CameraSetIOStateEx)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	UINT        uState
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡָ��IO�ĵ�ƽ״̬��IOΪ�����IO�����Ԥ���ɱ�����IO�ĸ�����@link #tSdkCameraCapbility.iOutputIoCounts @endlink������
/// \param [in] hCamera ����ľ����
/// \param [in] iOutputIOIndex IO�������ţ���0��ʼ��
/// \param [out] puState ����IO״̬��1Ϊ�ߣ�0Ϊ��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Read the level state of the specified IO. IO is the output IO. The number of programmable output IOs for the camera is determined by @link #tSdkCameraCapbility.iOutputIoCounts @endlink.
/// \param [in] hCamera Camera handle.
/// \param [in] iOutputIOIndex IO index, starting from 0.
/// \param [out] puState return IO state, 1 is high, 0 is low
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetOutPutIOState)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	UINT*       puState
	);

typedef CameraSdkStatus (__stdcall *_CameraGetOutPutIOStateEx)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	UINT*       puState
	);

/******************************************************/
// ������   : CameraGetIOState
// �������� : ����ָ��IO�ĵ�ƽ״̬��IOΪ������IO�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iInputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�          
//            iInputIOIndex IO�������ţ���0��ʼ��
//            puState ָ�룬����IO״̬,1Ϊ�ߣ�0Ϊ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetIOState)(
	CameraHandle      hCamera,
	INT               iInputIOIndex,
	UINT*             puState
	);

typedef CameraSdkStatus (__stdcall *_CameraGetIOStateEx)(
	CameraHandle      hCamera,
	INT               iInputIOIndex,
	UINT*             puState
	);

/******************************************************/
// ������   : CameraSetInPutIOMode
// �������� : ��������IO��ģʽ�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iInputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�          
//            iInputIOIndex IO�������ţ���0��ʼ��
//            iMode IOģʽ,�ο�CameraDefine.h��emCameraGPIOMode
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetInPutIOMode)(
	CameraHandle    hCamera,
	INT         iInputIOIndex,
	INT			iMode
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ����IO��ģʽ
/// \param [in] hCamera ����ľ����
/// \param [in] iInputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piMode IOģʽ,�ο�@link #emCameraGPIOMode @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the input IO mode
/// \param [in] hCamera Camera handle.
/// \param [in] iInputIOIndex IO index, starting from 0.
/// \param [out] piMode IO mode, reference @link #emCameraGPIOMode @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetInPutIOMode)(
	CameraHandle    hCamera,
	INT				iInputIOIndex,
	INT*			piMode
	);

/******************************************************/
// ������   : CameraSetOutPutIOMode
// �������� : �������IO��ģʽ�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iOutputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�          
//            iOutputIOIndex IO�������ţ���0��ʼ��
//            iMode IOģʽ,�ο�CameraDefine.h��emCameraGPIOMode
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetOutPutIOMode)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	INT			iMode
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ���IO��ģʽ
/// \param [in] hCamera ����ľ����
/// \param [in] iOutputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piMode IOģʽ,�ο�@link #emCameraGPIOMode @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the output IO mode
/// \param [in] hCamera Camera handle.
/// \param [in] iOutputIOIndex IO index, starting from 0.
/// \param [out] piMode IO mode, reference @link #emCameraGPIOMode @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetOutPutIOMode)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	INT*		piMode
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ����IO��ģʽ֧������
/// \param [in] hCamera ����ľ����
/// \param [in] iInputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piCapbility IOģʽ֧��λ����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the mode support capability of the input IO
/// \param [in] hCamera Camera handle.
/// \param [in] iInputIOIndex IO index, starting from 0.
/// \param [out] piCapbility IO mode support bit mask
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetInPutIOModeCapbility)(
	CameraHandle    hCamera,
	INT				iInputIOIndex,
	UINT*			piCapbility
	);

/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ���IO��ģʽ֧������
/// \param [in] hCamera ����ľ����
/// \param [in] iOutputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piCapbility IOģʽ֧��λ����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the mode support capability of the output IO
/// \param [in] hCamera Camera handle.
/// \param [in] iOutputIOIndex IO index, starting from 0.
/// \param [out] piCapbility IO mode support bit mask
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetOutPutIOModeCapbility)(
	CameraHandle    hCamera,
	INT				iOutputIOIndex,
	UINT*			piCapbility
	);

/******************************************************/
// ������   : CameraSetOutPutPWM
// �������� : ����PWM������Ĳ��������
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iOutputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�          
//            iOutputIOIndex IO�������ţ���0��ʼ��
//            iCycle PWM�����ڣ���λ(us)
//			  uDuty  ռ�ñȣ�ȡֵ1%~99%
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetOutPutPWM)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	UINT		iCycle,
	UINT		uDuty
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ���ñ�������Ч����
/// \param [in] hCamera ����ľ����
/// \param [in] dir ��Ч����0:����ת����Ч   1��˳ʱ�루A�೬ǰ��B��   2:��ʱ�룩
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the effective direction of the rotary encoder
/// \param [in] hCamera Camera handle.
/// \param [in] dir Valid direction (0: Both positive and negative are valid    1: Clockwise (A phase leads B)    2: Counterclockwise)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraSetRotaryEncDir)(
	CameraHandle    hCamera,
	INT				dir
	);

/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ��������Ч����
/// \param [in] hCamera ����ľ����
/// \param [out] dir ��Ч����0:����ת����Ч   1��˳ʱ�루A�೬ǰ��B��   2:��ʱ�룩
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the effective direction of the rotary encoder
/// \param [in] hCamera Camera handle.
/// \param [out] dir Valid direction (0: Both positive and negative are valid    1: Clockwise (A phase leads B)    2: Counterclockwise)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetRotaryEncDir)(
	CameraHandle    hCamera,
	INT*			dir
	);

/// @ingroup API_GPIO
/// \~chinese
/// \brief ���ñ�����Ƶ��
/// \param [in] hCamera ����ľ����
/// \param [in] mul ��Ƶ
/// \param [in] div ��Ƶ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the frequency of the rotary encoder
/// \param [in] hCamera Camera handle.
/// \param [in] mul frequency multiplier
/// \param [in] div frequency division
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraSetRotaryEncFreq)(
	CameraHandle hCamera,
	INT			mul,
	INT			div
	);

/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ������Ƶ��
/// \param [in] hCamera ����ľ����
/// \param [out] mul ��Ƶ
/// \param [out] div ��Ƶ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the frequency of the rotary encoder
/// \param [in] hCamera Camera handle.
/// \param [out] mul frequency multiplier
/// \param [out] div frequency division
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetRotaryEncFreq)(
	CameraHandle hCamera,
	INT*		mul,
	INT*		div
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��������IO�ĸ�ʽ
/// \param [in] hCamera ����ľ����
/// \param [in] iInputIOIndex IO�������ţ���0��ʼ��
/// \param [in] iFormat IO��ʽ,�ο�@link #emCameraGPIOFormat @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the input IO format
/// \param [in] hCamera Camera handle.
/// \param [in] iInputIOIndex IO index, starting from 0.
/// \param [in] iFormat IO format, reference @link #emCameraGPIOFormat @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraSetInPutIOFormat)(
	CameraHandle    hCamera,
	INT         iInputIOIndex,
	INT			iFormat
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ����IO�ĸ�ʽ
/// \param [in] hCamera ����ľ����
/// \param [in] iInputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piFormat IO��ʽ,�ο�@link #emCameraGPIOFormat @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the input IO format
/// \param [in] hCamera Camera handle.
/// \param [in] iInputIOIndex IO index, starting from 0.
/// \param [out] piFormat IO format, reference @link #emCameraGPIOFormat @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetInPutIOFormat)(
	CameraHandle    hCamera,
	INT				iInputIOIndex,
	INT*			piFormat
	);

/// @ingroup API_GPIO
/// \~chinese
/// \brief �������IO�ĸ�ʽ
/// \param [in] hCamera ����ľ����
/// \param [in] iOutputIOIndex IO�������ţ���0��ʼ��
/// \param [in] iFormat IO��ʽ,�ο�@link #emCameraGPIOFormat @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the output IO format
/// \param [in] hCamera Camera handle.
/// \param [in] iOutputIOIndex IO index, starting from 0.
/// \param [in] iFormat IO format, reference @link #emCameraGPIOFormat @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraSetOutPutIOFormat)(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	INT			iFormat
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ���IO�ĸ�ʽ
/// \param [in] hCamera ����ľ����
/// \param [in] iOutputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piFormat IO��ʽ,�ο�@link #emCameraGPIOFormat @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the output IO format
/// \param [in] hCamera Camera handle.
/// \param [in] iOutputIOIndex IO index, starting from 0.
/// \param [out] piFormat IO format, reference @link #emCameraGPIOFormat @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetOutPutIOFormat)(
	CameraHandle    hCamera,
	INT				iOutputIOIndex,
	INT*			piFormat
	);
	
/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ����IO�ĸ�ʽ֧������
/// \param [in] hCamera ����ľ����
/// \param [in] iInputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piCapbility IO��ʽ֧��λ����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the format support capability of the input IO
/// \param [in] hCamera Camera handle.
/// \param [in] iInputIOIndex IO index, starting from 0.
/// \param [out] piCapbility IO format support bit mask
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetInPutIOFormatCapbility)(
	CameraHandle    hCamera,
	INT				iInputIOIndex,
	UINT*			piCapbility
	);

/// @ingroup API_GPIO
/// \~chinese
/// \brief ��ȡ���IO�ĸ�ʽ֧������
/// \param [in] hCamera ����ľ����
/// \param [in] iOutputIOIndex IO�������ţ���0��ʼ��
/// \param [out] piCapbility IO��ʽ֧��λ����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the format support capability of the output IO
/// \param [in] hCamera Camera handle.
/// \param [in] iOutputIOIndex IO index, starting from 0.
/// \param [out] piCapbility IO format support bit mask
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraGetOutPutIOFormatCapbility)(
	CameraHandle    hCamera,
	INT				iOutputIOIndex,
	UINT*			piCapbility
	);

/******************************************************/
// ������   : CameraSetBayerDecAlgorithm
// �������� : ����Bayer����ת��ɫ���㷨��
// ����     : hCamera       ����ľ������CameraInit������á� 
//            iIspProcessor   ѡ��ִ�и��㷨�Ķ��󣬲ο�CameraDefine.h
//                emSdkIspProcessor�Ķ���
//            iAlgorithmSel     Ҫѡ����㷨��š���0��ʼ�����ֵ��tSdkCameraCapbility
//                ��iBayerDecAlmSwDesc��iBayerDecAlmHdDesc������    
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetBayerDecAlgorithm)(
	CameraHandle    hCamera,
	INT             iIspProcessor,
	INT             iAlgorithmSel
	);

/******************************************************/
// ������   : CameraGetBayerDecAlgorithm
// �������� : ���Bayer����ת��ɫ��ѡ����㷨��
// ����     : hCamera       ����ľ������CameraInit������á� 
//            iIspProcessor   ѡ��ִ�и��㷨�Ķ��󣬲ο�CameraDefine.h
//                emSdkIspProcessor�Ķ���
//            piAlgorithmSel    ���ص�ǰѡ����㷨��š���0��ʼ�����ֵ��tSdkCameraCapbility
//                ��iBayerDecAlmSwDesc��iBayerDecAlmHdDesc������  
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetBayerDecAlgorithm)(
	CameraHandle    hCamera,
	INT             iIspProcessor,
	INT*            piAlgorithmSel
	);

/******************************************************/
// ������ 	: CameraSetBlackLevel
// ��������	: ����ͼ��ĺڵ�ƽ��׼��Ĭ��ֵΪ0
// ����	    : hCamera	  ����ľ������CameraInit������á� 
//            iBlackLevel Ҫ�趨�ĵ�ƽֵ����ΧΪ0��128��	
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetBlackLevel)
	(
	CameraHandle    hCamera,
	INT             iBlackLevel
	);

/******************************************************/
// ������ 	: CameraGetBlackLevel
// ��������	: ���ͼ��ĺڵ�ƽ��׼��Ĭ��ֵΪ0
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            piBlackLevel ���ص�ǰ�ĺڵ�ƽֵ����ΧΪ0��128��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetBlackLevel)
	(
	CameraHandle    hCamera,
	INT*            piBlackLevel
	);


/******************************************************/
// ������ 	: CameraSetWhiteLevel
// ��������	: ����ͼ��İ׵�ƽ��׼��Ĭ��ֵΪ255
// ����	    : hCamera		����ľ������CameraInit������á� 
//            iWhiteLevel	Ҫ�趨�ĵ�ƽֵ����ΧΪ128��255��	
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetWhiteLevel)
	(
	CameraHandle    hCamera,
	INT             iWhiteLevel
	);



/******************************************************/
// ������ 	: CameraGetWhiteLevel
// ��������	: ���ͼ��İ׵�ƽ��׼��Ĭ��ֵΪ255
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            piWhiteLevel ���ص�ǰ�İ׵�ƽֵ����ΧΪ128��255��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetWhiteLevel)
	(
	CameraHandle    hCamera,
	INT*            piWhiteLevel
	);


/******************************************************/
// ������ 	: CameraSetIspOutFormat
// ��������	: ����CameraGetImageBuffer������ͼ����������ʽ��֧��
//              CAMERA_MEDIA_TYPE_MONO8��CAMERA_MEDIA_TYPE_RGB8��CAMERA_MEDIA_TYPE_RGBA8
//              (��CameraDefine.h�ж���)���֣��ֱ��Ӧ8λ�Ҷ�ͼ���24��32λ��ɫͼ��
// ����	    : hCamera		����ľ������CameraInit������á� 
//             uFormat	     Ҫ�趨��ʽ��CAMERA_MEDIA_TYPE_MONO8����CAMERA_MEDIA_TYPE_RGB8��CAMERA_MEDIA_TYPE_RGBA8	
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetIspOutFormat)
	(
	CameraHandle    hCamera,
	UINT            uFormat
	);

/******************************************************/
// ������ 	: CameraGetIspOutFormat
// ��������	: ���CameraGetImageBuffer����ͼ����������ʽ��֧��
//              CAMERA_MEDIA_TYPE_MONO8��CAMERA_MEDIA_TYPE_RGB8��CAMERA_MEDIA_TYPE_RGBA8
//              (��CameraDefine.h�ж���)���֣��ֱ��Ӧ8λ�Ҷ�ͼ���24��32λ��ɫͼ��
// ����	    : hCamera		����ľ������CameraInit������á� 
//             puFormat	���ص�ǰ�趨�ĸ�ʽ��CAMERA_MEDIA_TYPE_MONO8����CAMERA_MEDIA_TYPE_RGB8��CAMERA_MEDIA_TYPE_RGBA8	
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetIspOutFormat)
	(
	CameraHandle    hCamera,
	UINT*           puFormat
	);

/******************************************************/
// ������ 	: CameraGetErrorString
// ��������	: ��ô������Ӧ�������ַ���
// ����	    : iStatusCode		�����롣(������CameraStatus.h��)
// ����ֵ   : �ɹ�ʱ�����ش������Ӧ���ַ����׵�ַ;
//            ���򷵻�NULL��
/******************************************************/
typedef char* (__stdcall *_CameraGetErrorString)(
	CameraSdkStatus     iStatusCode
	);

/******************************************************/
// ������ 	: CameraGetImageBufferEx2
// ��������	: ���һ֡ͼ�����ݡ��ýӿڻ�õ�ͼ���Ǿ���������RGB��ʽ���ú������ú�
//			  ����Ҫ���� CameraReleaseImageBuffer �ͷţ�Ҳ��Ҫ����free֮��ĺ����ͷ�
//              ���ͷŸú������ص�ͼ�����ݻ�������
// ����	    : hCamera	    ����ľ������CameraInit������á�
//             pImageData  ����ͼ�����ݵĻ���������С�����uOutFormatָ���ĸ�ʽ��ƥ�䣬�������ݻ����
//             piWidth     ����ָ�룬����ͼ��Ŀ��
//             piHeight    ����ָ�룬����ͼ��ĸ߶�
//             wTimes      ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//						wTimesʱ���ڻ�δ���ͼ����ú���
//						�᷵�س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������RGB���ݻ��������׵�ַ;
//            ���򷵻�0��
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetImageBufferEx2)(
	CameraHandle    hCamera, 
	BYTE*           pImageData,
	UINT            uOutFormat,
	int*            piWidth,
	int*            piHeight,
	UINT            wTimes
	);

/******************************************************/
// ������ 	: CameraGetImageBufferEx3
// ��������	: ���һ֡ͼ�����ݡ��ýӿڻ�õ�ͼ���Ǿ���������RGB��ʽ���ú������ú�
//			  ����Ҫ���� CameraReleaseImageBuffer �ͷ�.
//              uOutFormat 0 : 8 BIT gray 1:rgb24 2:rgba32 3:bgr24 4:bgra32
// ����	    : hCamera	    ����ľ������CameraInit������á�
//             pImageData  ����ͼ�����ݵĻ���������С�����uOutFormatָ���ĸ�ʽ��ƥ�䣬�������ݻ����
//            piWidth      ����ָ�룬����ͼ��Ŀ��
//            piHeight     ����ָ�룬����ͼ��ĸ߶�
//            puTimeStamp  �޷������Σ�����ͼ��ʱ��� 
//            UINT wTimes  ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//			wTimes       ʱ���ڻ�δ���ͼ����ú����᷵�س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������RGB���ݻ��������׵�ַ;
//            ���򷵻�0��
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetImageBufferEx3)(
	CameraHandle hCamera, 
	BYTE*pImageData,
	UINT uOutFormat,
	int *piWidth,
	int *piHeight,
	UINT* puTimeStamp,
	UINT wTimes
	);

/******************************************************/
// ������ 	: CameraGetCapabilityEx2
// ��������	: ��ø������һЩ���ԡ�
// ����	    : hCamera		    ����ľ������CameraInit������á� 
//             pMaxWidth	    ���ظ�������ֱ��ʵĿ��
//             pMaxHeight      ���ظ�������ֱ��ʵĸ߶� 
//             pbColorCamera    ���ظ�����Ƿ��ǲ�ɫ�����1��ʾ��ɫ�����0��ʾ�ڰ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetCapabilityEx2)(
	CameraHandle    hCamera,
	int*            pMaxWidth,
	int*            pMaxHeight,
	int*            pbColorCamera
	);


/******************************************************/
// ������ 	: CameraReConnect
// ��������	: ���������豸������USB�豸������ߺ�����
// ����	    : hCamera	   ����ľ������CameraInit������á� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraReConnect)(
	CameraHandle    hCamera
	);


/******************************************************/
// ������ 	: CameraConnectTest
// ��������	: �������������״̬�����ڼ������Ƿ����
// ����	    : hCamera	   ����ľ������CameraInit������á� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraConnectTest)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������ 	: CameraSetLedEnable
// ��������	: ���������LEDʹ��״̬������LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index       LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             enable      ʹ��״̬
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetLedEnable)(
	CameraHandle    hCamera,
	int             index,
	BOOL            enable
	);

/******************************************************/
// ������ 	: CameraGetLedEnable
// ��������	: ��������LEDʹ��״̬������LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index       LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             enable      ָ�룬����LEDʹ��״̬
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetLedEnable)(
	CameraHandle    hCamera,
	int             index,
	BOOL*           enable
	);

/******************************************************/
// ������ 	: CameraSetLedOnOff
// ��������	: ���������LED����״̬������LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index       LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             onoff	   LED����״̬
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetLedOnOff)(
	CameraHandle    hCamera,
	int             index,
	BOOL            onoff
	);

/******************************************************/
// ������ 	: CameraGetLedOnOff
// ��������	: ��������LED����״̬������LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index       LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             onoff	   ָ�룬����LED����״̬
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetLedOnOff)(
	CameraHandle    hCamera,
	int             index,
	BOOL*           onoff
	);

/******************************************************/
// ������ 	: CameraSetLedDuration
// ��������	: ���������LED����ʱ�䣬����LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	    ����ľ������CameraInit������á� 
//             index        LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             duration		LED����ʱ�䣬��λ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetLedDuration)(
	CameraHandle    hCamera,
	int             index,
	UINT            duration
	);

/******************************************************/
// ������ 	: CameraGetLedDuration
// ��������	: ��������LED����ʱ�䣬����LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	    ����ľ������CameraInit������á� 
//             index        LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             duration		ָ�룬����LED����ʱ�䣬��λ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetLedDuration)(
	CameraHandle    hCamera,
	int             index,
	UINT*           duration
	);

/******************************************************/
// ������ 	: CameraSetLedLightless
// ��������	: ���������LED���ȣ�����LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index      LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             uLightless LED����ֵ����Χ0��255. 0��ʾ�رգ�255������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetLedBrightness)(
	CameraHandle    hCamera,
	int             index,
	UINT            uLightless
	);

/******************************************************/
// ������ 	: CameraGetLedLightless
// ��������	: ��������LED���ȣ�����LED���ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index      LED�Ƶ������ţ���0��ʼ�����ֻ��һ���ɿ������ȵ�LED����ò���Ϊ0 ��
//             uLightless ָ�룬����LED����ֵ����Χ0��255. 0��ʾ�رգ�255������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetLedBrightness)(
	CameraHandle    hCamera,
	int             index,
	UINT*           uLightless
	);


/******************************************************/
// ������ 	: CameraEnableTransferRoi
// ��������	: ʹ�ܻ��߽�ֹ����Ķ������书�ܣ������ù��ܵ��ͺţ��˺������ش�����룬��ʾ��֧�֡�
//              �ù�����Ҫ����������˽��ɼ������������з֣�ֻ����ָ���Ķ����������ߴ���֡�ʡ�
//              ��������䵽PC�Ϻ󣬻��Զ�ƴ�ӳ��������棬û�б�����Ĳ��֣����ú�ɫ��䡣
// ����	    : hCamera	    ����ľ������CameraInit������á� 
//             index       ROI����������ţ���0��ʼ��
//             uEnableMask ����ʹ��״̬���룬��Ӧ�ı���λΪ1��ʾʹ�ܡ�0Ϊ��ֹ��ĿǰSDK֧��4���ɱ༭����index��ΧΪ0��3����bit0 ��bit1��bit2��bit3����4�������ʹ��״̬��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֶ�����ROI������ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��   
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraEnableTransferRoi)(
	CameraHandle    hCamera,
	UINT            uEnableMask
	);


/******************************************************/
// ������ 	: CameraSetTransferRoi
// ��������	: �����������Ĳü�����������ˣ�ͼ��Ӵ������ϱ��ɼ��󣬽��ᱻ�ü���ָ�������������ͣ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index      ROI����������ţ���0��ʼ��
//             X1,Y1      ROI��������Ͻ�����
//             X2,Y2      ROI��������Ͻ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֶ�����ROI������ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��   
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetTransferRoi)(
	CameraHandle    hCamera,
	int             index,
	UINT            X1,
	UINT            Y1,
	UINT            X2,
	UINT            Y2
	);


/******************************************************/
// ������ 	: CameraGetTransferRoi
// ��������	: �����������Ĳü�����������ˣ�ͼ��Ӵ������ϱ��ɼ��󣬽��ᱻ�ü���ָ�������������ͣ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//             index      ROI����������ţ���0��ʼ��
//             pX1,pY1      ROI��������Ͻ�����
//             pX2,pY2      ROI��������Ͻ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֶ�����ROI������ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��   
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetTransferRoi)(
	CameraHandle    hCamera,
	int             index,
	UINT*           pX1,
	UINT*           pY1,
	UINT*           pX2,
	UINT*           pY2
	);

/******************************************************/
// ������ 	: CameraAlignMalloc
// ��������	: ����һ�ζ�����ڴ�ռ䡣���ܺ�malloc���ƣ���
//						�Ƿ��ص��ڴ�����alignָ�����ֽ�������ġ�
// ����	    : size	   �ռ�Ĵ�С�� 
//            align    ��ַ������ֽ�����
// ����ֵ   : �ɹ�ʱ�����ط�0ֵ����ʾ�ڴ��׵�ַ��ʧ�ܷ���NULL��
/******************************************************/

typedef BYTE* (__stdcall *_CameraAlignMalloc)(
	int             size,
	int             align
	);

/******************************************************/
// ������ 	: CameraAlignFree
// ��������	: �ͷ���CameraAlignMalloc����������ڴ�ռ䡣
// ����	    : membuffer	   ��CameraAlignMalloc���ص��ڴ��׵�ַ�� 
// ����ֵ   : �ޡ�
/******************************************************/
typedef void (__stdcall *_CameraAlignFree)(
	BYTE*           membuffer
	);


/******************************************************/
// ������ 	: CameraSetAutoConnect
// ��������	: �����Զ�ʹ������
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//			  bEnable	   ʹ�������������λTRUEʱ��SDK�ڲ��Զ��������Ƿ���ߣ����ߺ��Լ�������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֵ��ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��   
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetAutoConnect)(
	CameraHandle hCamera,
	BOOL bEnable
	);

/******************************************************/
// ������ 	: CameraGetAutoConnect
// ��������	: ��ȡ�Զ�����ʹ��
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//			  pbEnable	   �����������ʹ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֵ��ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��   
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetAutoConnect)(CameraHandle hCamera,BOOL *pbEnable);

/******************************************************/
// ������ 	: CameraGetReConnectCounts
// ��������	: �������Զ������Ĵ�����ǰ����CameraSetAutoConnect ʹ������Զ��������ܡ�Ĭ����ʹ�ܵġ�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//			 puCounts	   ���ص����Զ������Ĵ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֵ��ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��   
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetReConnectCounts)(
	CameraHandle hCamera,
	UINT* puCounts
	);

/******************************************************/
// ������ 	: CameraSetSingleGrabMode
// ��������	: ʹ�ܵ�֡ץȡģʽ
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//			  bEnable	   ʹ�ܵ�֡ץȡģʽ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֵ��ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetSingleGrabMode)(CameraHandle hCamera, BOOL bEnable);

/******************************************************/
// ������ 	: CameraGetSingleGrabMode
// ��������	: �������ĵ�֡ץȡģʽ
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//			 pbEnable	   ��������ĵ�֡ץȡģʽ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֵ��ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetSingleGrabMode)(CameraHandle hCamera, BOOL* pbEnable);

/******************************************************/
// ������ 	: CameraRestartGrab
// ��������	: ��������ڵ�֡ץȡģʽʱ��ÿ���ɹ�ץȡ��һ֡��SDK�������ͣ״̬�����ô˺�����ʹSDK�˳���ͣ״̬����ʼץȡ��һ֡
// ����	    : hCamera	   ����ľ������CameraInit������á� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���ڲ�֧�ֵ��ͺţ��ú����᷵�� CAMERA_STATUS_NOT_SUPPORTED(-4) ��ʾ��֧��
//            ������0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraRestartGrab)(CameraHandle hCamera);

/******************************************************/
// ������   : CameraDrawText
// �������� : �������ͼ�������л�������
// ����     : pRgbBuffer ͼ�����ݻ�����
//			  pFrInfo ͼ���֡ͷ��Ϣ
//			  pFontFileName �����ļ���
//			  FontWidth ������
//			  FontHeight ����߶�
//			  pText Ҫ���������
//			  (Left, Top, Width, Height) ���ֵ��������
//			  TextColor ������ɫRGB
//			  uFlags �����־,���emCameraDrawTextFlags�еĶ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraDrawText)(
	BYTE*           pRgbBuffer,
	tSdkFrameHead*  pFrInfo,
	char const*		pFontFileName, 
	UINT			FontWidth,
	UINT			FontHeight,
	char const*		pText, 
	INT				Left,
	INT				Top,
	UINT			Width,
	UINT			Height,
	UINT			TextColor,
	UINT			uFlags
	);
	
/// @ingroup API_ENUM
/// \~chinese
/// \brief ��ָ��IPö��GIGE�豸���������豸�б�����������͵��Բ���ͬһ���ε������
/// \param [in] ppIpList Ŀ��IP
/// \param [in] numIp Ŀ��IP����
/// \param [out] pCameraList �豸�б�����ָ��
/// \param [inout] piNums �豸�ĸ���ָ�룬����ʱ����pCameraList�����Ԫ�ظ�������������ʱ������ʵ���ҵ����豸����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ���
/// \warning piNumsָ���ֵ�����ʼ�����Ҳ�����pCameraList����Ԫ�ظ����������п�������ڴ����
/// \note ���ص������Ϣ�б������acFriendlyName����ġ�������Խ���������ֱ��Ϊ��Camera1���͡�Camera2�������ֺ�����Ϊ��Camera1�����������ǰ�棬��Ϊ��Camera2��������ź��档
/// \~english
/// \brief Enumerates GIGE devices from the specified IP and builds a device list (applicable when the camera and computer are not on the same network segment)
/// \param [in] ppIpList target IP
/// \param [in] numIp number of target IPs
/// \param [out] pCameraList Device list array pointer
/// \param [inout] piNums The number of pointers to the device, the number of elements passed to the pCameraList array at the time of the call. When the function returns, the number of devices actually found is saved.
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \warning piNums The value pointed to must be initialized and does not exceed the number of pCameraList array elements, otherwise it may cause memory overflow
/// \note The list of returned camera information will be sorted according to acFriendlyName. For example, after changing the two cameras to the names of "Camera1" and "Camera2," the camera named "Camera1" will be in front, and the camera named "Camera2" will be behind the row.
typedef CameraSdkStatus (__stdcall *_CameraGigeEnumerateDevice)(
	char const**        ppIpList,
	int                 numIp,
	tSdkCameraDevInfo*  pCameraList, 
	int*                piNums
	);

/******************************************************/
// ������   : CameraGigeGetIp
// �������� : ��ȡGIGE�����IP��ַ
// ����     : pCameraInfo ������豸������Ϣ������CameraEnumerateDevice������á� 
//			  CamIp ���IP(ע�⣺���뱣֤����Ļ��������ڵ���16�ֽ�)
//			  CamMask �����������(ע�⣺���뱣֤����Ļ��������ڵ���16�ֽ�)
//			  CamGateWay �������(ע�⣺���뱣֤����Ļ��������ڵ���16�ֽ�)
//			  EtIp ����IP(ע�⣺���뱣֤����Ļ��������ڵ���16�ֽ�)
//			  EtMask ������������(ע�⣺���뱣֤����Ļ��������ڵ���16�ֽ�)
//			  EtGateWay ��������(ע�⣺���뱣֤����Ļ��������ڵ���16�ֽ�)
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGigeGetIp)(
	tSdkCameraDevInfo* pCameraInfo,
	char* CamIp,
	char* CamMask,
	char* CamGateWay,
	char* EtIp,
	char* EtMask,
	char* EtGateWay
	);

/******************************************************/
// ������   : CameraGigeSetIp
// �������� : ����GIGE�����IP��ַ
// ����     : pCameraInfo ������豸������Ϣ������CameraEnumerateDevice������á� 
//			  Ip ���IP(�磺192.168.1.100)
//			  SubMask �����������(�磺255.255.255.0)
//			  GateWay �������(�磺192.168.1.1)
//			  bPersistent TRUE: �������Ϊ�̶�IP��FALSE����������Զ�����IP�����Բ���Ip, SubMask, GateWay��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGigeSetIp)(
	tSdkCameraDevInfo* pCameraInfo,
	char const* Ip,
	char const* SubMask,
	char const* GateWay,
	BOOL bPersistent
	);

/******************************************************/
// ������   : CameraGigeGetMac
// �������� : ��ȡGIGE�����MAC��ַ
// ����     : pCameraInfo ������豸������Ϣ������CameraEnumerateDevice������á� 
//			  CamMac ���MAC(ע�⣺���뱣֤����Ļ��������ڵ���18�ֽ�)
//			  EtMac ����MAC(ע�⣺���뱣֤����Ļ��������ڵ���18�ֽ�)
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGigeGetMac)(
	tSdkCameraDevInfo* pCameraInfo,
	char* CamMac,
	char* EtMac
	);

/******************************************************/
// ������   : CameraEnableFastResponse
// �������� : ʹ�ܿ�����Ӧ
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraEnableFastResponse)(
	CameraHandle hCamera
	);

/******************************************************/
// ������   : CameraSetCorrectDeadPixel
// �������� : ʹ�ܻ�������
// ����     : hCamera  ����ľ������CameraInit������á�
//				bEnable     TRUE: ʹ�ܻ�������   FALSE: �رջ�������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetCorrectDeadPixel)(
	CameraHandle hCamera,
	BOOL bEnable
	);

/******************************************************/
// ������   : CameraGetCorrectDeadPixel
// �������� : ��ȡ��������ʹ��״̬
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetCorrectDeadPixel)(
	CameraHandle hCamera,
	BOOL* pbEnable
	);

/******************************************************/
// ������   : CameraFlatFieldingCorrectSetEnable
// �������� : ʹ��ƽ��У��
// ����     : hCamera  ����ľ������CameraInit������á�
//				bEnable     TRUE: ʹ��ƽ��У��   FALSE: �ر�ƽ��У��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraFlatFieldingCorrectSetEnable)(
	CameraHandle hCamera,
	BOOL bEnable
	);

/******************************************************/
// ������   : CameraFlatFieldingCorrectGetEnable
// �������� : ��ȡƽ��У��ʹ��״̬
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraFlatFieldingCorrectGetEnable)(
	CameraHandle hCamera,
	BOOL* pbEnable
	);

/******************************************************/
// ������   : CameraFlatFieldingCorrectSetParameter
// �������� : ����ƽ��У������
// ����     :	hCamera  ����ľ������CameraInit������á�
//				pDarkFieldingImage ����ͼƬ
//				pDarkFieldingFrInfo ����ͼƬ��Ϣ
//				pLightFieldingImage ����ͼƬ
//				pLightFieldingFrInfo ����ͼƬ��Ϣ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraFlatFieldingCorrectSetParameter)(
	CameraHandle hCamera,
	BYTE const* pDarkFieldingImage,
	tSdkFrameHead const* pDarkFieldingFrInfo,
	BYTE const* pLightFieldingImage,
	tSdkFrameHead const* pLightFieldingFrInfo
	);

/******************************************************/
// ������   : CameraFlatFieldingCorrectSaveParameterToFile
// �������� : ����ƽ��У���������ļ�
// ����     :	hCamera  ����ľ������CameraInit������á�
//				pszFileName �ļ�·��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraFlatFieldingCorrectSaveParameterToFile)(
	CameraHandle hCamera,
	char const* pszFileName
	);

/******************************************************/
// ������   : CameraFlatFieldingCorrectLoadParameterFromFile
// �������� : ���ļ��м���ƽ��У������
// ����     :	hCamera  ����ľ������CameraInit������á�
//				pszFileName �ļ�·��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraFlatFieldingCorrectLoadParameterFromFile)(
	CameraHandle hCamera,
	char const* pszFileName
	);

/******************************************************/
// ������   : CameraCommonCall
// �������� : �����һЩ���⹦�ܵ��ã����ο���ʱһ�㲻��Ҫ���á�
// ����     : hCamera   ����ľ������CameraInit������á�
//            pszCall   ���ܼ�����
//            pszResult ���ý������ͬ��pszCallʱ�����岻ͬ��
//            uResultBufSize pszResultָ��Ļ��������ֽڴ�С
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraCommonCall)(
	CameraHandle    hCamera, 
	char const*		pszCall,
	char*			pszResult,
	UINT			uResultBufSize
	);

/******************************************************/
// ������   : CameraSetDenoise3DParams
// �������� : ����3D�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            bEnable  ���û����
//            nCount   ʹ�ü���ͼƬ���н���(2-8��)
//            Weights  ����Ȩ��
//					   �統ʹ��3��ͼƬ���н���������������Դ���3������(0.3,0.3,0.4)�����һ��ͼƬ��Ȩ�ش���ǰ2��
//					   �������Ҫʹ��Ȩ�أ���������������0����ʾ����ͼƬ��Ȩ����ͬ(0.33,0.33,0.33)
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetDenoise3DParams)(
	CameraHandle    hCamera, 
	BOOL			bEnable,
	int				nCount,
	float			*Weights
	);

/******************************************************/
// ������   : CameraGetDenoise3DParams
// �������� : ��ȡ��ǰ��3D�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            bEnable  ���û����
//            nCount   ʹ���˼���ͼƬ���н���
//			  bUseWeight �Ƿ�ʹ���˽���Ȩ��
//            Weights  ����Ȩ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetDenoise3DParams)(
	CameraHandle    hCamera, 
	BOOL			*bEnable,
	int				*nCount,
	BOOL			*bUseWeight,
	float			*Weights
	);

/******************************************************/
// ������   : CameraManualDenoise3D
// �������� : ��һ��֡����һ�ν��봦��
// ����     : InFramesHead  ����֡ͷ
//			  InFramesData  ����֡����
//            nCount   ����֡������
//            Weights  ����Ȩ��
//					   �統ʹ��3��ͼƬ���н���������������Դ���3������(0.3,0.3,0.4)�����һ��ͼƬ��Ȩ�ش���ǰ2��
//					   �������Ҫʹ��Ȩ�أ���������������0����ʾ����ͼƬ��Ȩ����ͬ(0.33,0.33,0.33)
//			  OutFrameHead ���֡ͷ
//			  OutFrameData ���֡����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraManualDenoise3D)(
	tSdkFrameHead	*InFramesHead,
	BYTE			**InFramesData,
	int				nCount,
	float			*Weights,
	tSdkFrameHead	*OutFrameHead,
	BYTE			*OutFrameData
	);

/******************************************************/
// ������   : CameraCustomizeDeadPixels
// �������� : �򿪻���༭���
// ����     : hCamera    ����ľ������CameraInit������á�
//            hParent    ���øú����Ĵ��ڵľ��������ΪNULL��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraCustomizeDeadPixels)(
	CameraHandle	hCamera,
	HWND			hParent
	);

/******************************************************/
// ������   : CameraReadDeadPixels
// �������� : ��ȡ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//			  pRows ����y����
//			  pCols ����x����
//			  pNumPixel ����ʱ��ʾ���л������Ĵ�С������ʱ��ʾ���л������з��صĻ���������
//			  ��pRows����pColsΪNULLʱ������������ǰ�Ļ������ͨ��pNumPixel����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraReadDeadPixels)(
	CameraHandle    hCamera,
	USHORT*			pRows,
	USHORT*			pCols,
	UINT*			pNumPixel
	);

/******************************************************/
// ������   : CameraAddDeadPixels
// �������� : ����������
// ����     : hCamera   ����ľ������CameraInit������á�
//			  pRows ����y����
//			  pCols ����x����
//			  NumPixel ���л������еĻ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraAddDeadPixels)(
	CameraHandle    hCamera,
	USHORT*			pRows,
	USHORT*			pCols,
	UINT			NumPixel
	);

/******************************************************/
// ������   : CameraRemoveDeadPixels
// �������� : ɾ�����ָ������
// ����     : hCamera   ����ľ������CameraInit������á�
//			  pRows ����y����
//			  pCols ����x����
//			  NumPixel ���л������еĻ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraRemoveDeadPixels)(
	CameraHandle    hCamera,
	USHORT*			pRows,
	USHORT*			pCols,
	UINT			NumPixel
	);

/******************************************************/
// ������   : CameraRemoveAllDeadPixels
// �������� : ɾ����������л���
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraRemoveAllDeadPixels)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraSaveDeadPixels
// �������� : ����������㵽����洢��
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSaveDeadPixels)(
	CameraHandle    hCamera
	);

/******************************************************/
// ������   : CameraSaveDeadPixelsToFile
// �������� : ����������㵽�ļ���
// ����     : hCamera   ����ľ������CameraInit������á�
//			  sFileName  �����ļ�������·����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSaveDeadPixelsToFile)(
	CameraHandle    hCamera,
	char const*		sFileName
	);

/******************************************************/
// ������   : CameraLoadDeadPixelsFromFile
// �������� : ���ļ������������
// ����     : hCamera   ����ľ������CameraInit������á�
//			  sFileName  �����ļ�������·����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraLoadDeadPixelsFromFile)(
	CameraHandle    hCamera,
	char const*		sFileName
	);

/******************************************************/
// ������   : CameraGetImageBufferPriority
// �������� : ���һ֡ͼ�����ݡ�Ϊ�����Ч�ʣ�SDK��ͼ��ץȡʱ�������㿽�����ƣ�
//        CameraGetImageBufferʵ�ʻ�����ں��е�һ����������ַ��
//        �ú����ɹ����ú󣬱������CameraReleaseImageBuffer�ͷ���
//        CameraGetImageBuffer�õ��Ļ�����,�Ա����ں˼���ʹ��
//        �û�������  
// ����     : hCamera   ����ľ������CameraInit������á�
//            pFrameInfo  ͼ���֡ͷ��Ϣָ�롣
//            pbyBuffer   ָ��ͼ������ݵĻ�����ָ�롣����
//              �������㿽�����������Ч�ʣ����
//              ����ʹ����һ��ָ��ָ���ָ�롣
//            wTimes ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//              wTimesʱ���ڻ�δ���ͼ����ú���
//              �᷵�س�ʱ��Ϣ��
//			  Priority ȡͼ���ȼ� �����emCameraGetImagePriority
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetImageBufferPriority)(
	CameraHandle        hCamera, 
	tSdkFrameHead*      pFrameInfo, 
	BYTE**              pbyBuffer,
	UINT                wTimes,
	UINT				Priority
	);

/******************************************************/
// ������ 	: CameraGetImageBufferPriorityEx
// ��������	: ���һ֡ͼ�����ݡ��ýӿڻ�õ�ͼ���Ǿ���������RGB��ʽ���ú������ú�
//			  ����Ҫ���� CameraReleaseImageBuffer �ͷţ�Ҳ��Ҫ����free֮��ĺ����ͷ�
//              ���ͷŸú������ص�ͼ�����ݻ�������
// ����	    : hCamera	  ����ľ������CameraInit������á�
//            piWidth    ����ָ�룬����ͼ��Ŀ��
//            piHeight   ����ָ�룬����ͼ��ĸ߶�
//            UINT wTimes ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//						  wTimesʱ���ڻ�δ���ͼ����ú���
//						  �᷵�س�ʱ��Ϣ��
//			  Priority   ȡͼ���ȼ� �����emCameraGetImagePriority
// ����ֵ   : �ɹ�ʱ������RGB���ݻ��������׵�ַ;
//            ���򷵻�0��
/******************************************************/
typedef unsigned char* (__stdcall *_CameraGetImageBufferPriorityEx)(
	CameraHandle        hCamera, 
	INT*                piWidth,
	INT*                piHeight,
	UINT                wTimes,
	UINT				Priority
	);

/******************************************************/
// ������ 	: CameraGetImageBufferPriorityEx2
// ��������	: ���һ֡ͼ�����ݡ��ýӿڻ�õ�ͼ���Ǿ���������RGB��ʽ���ú������ú�
//			  ����Ҫ���� CameraReleaseImageBuffer �ͷţ�Ҳ��Ҫ����free֮��ĺ����ͷ�
//              ���ͷŸú������ص�ͼ�����ݻ�������
// ����	    : hCamera	    ����ľ������CameraInit������á�
//             pImageData  ����ͼ�����ݵĻ���������С�����uOutFormatָ���ĸ�ʽ��ƥ�䣬�������ݻ����
//             piWidth     ����ָ�룬����ͼ��Ŀ��
//             piHeight    ����ָ�룬����ͼ��ĸ߶�
//             wTimes      ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//						wTimesʱ���ڻ�δ���ͼ����ú���
//						�᷵�س�ʱ��Ϣ��
//			  Priority	   ȡͼ���ȼ� �����emCameraGetImagePriority
// ����ֵ   : �ɹ�ʱ������RGB���ݻ��������׵�ַ;
//            ���򷵻�0��
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetImageBufferPriorityEx2)(
	CameraHandle    hCamera, 
	BYTE*           pImageData,
	UINT            uOutFormat,
	int*            piWidth,
	int*            piHeight,
	UINT            wTimes,
	UINT			Priority
	);

/******************************************************/
// ������ 	: CameraGetImageBufferPriorityEx3
// ��������	: ���һ֡ͼ�����ݡ��ýӿڻ�õ�ͼ���Ǿ���������RGB��ʽ���ú������ú�
//			  ����Ҫ���� CameraReleaseImageBuffer �ͷ�.
//              uOutFormat 0 : 8 BIT gray 1:rgb24 2:rgba32 3:bgr24 4:bgra32
// ����	    : hCamera	    ����ľ������CameraInit������á�
//             pImageData  ����ͼ�����ݵĻ���������С�����uOutFormatָ���ĸ�ʽ��ƥ�䣬�������ݻ����
//            piWidth      ����ָ�룬����ͼ��Ŀ��
//            piHeight     ����ָ�룬����ͼ��ĸ߶�
//            puTimeStamp  �޷������Σ�����ͼ��ʱ��� 
//            UINT wTimes  ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//			  wTimes       ʱ���ڻ�δ���ͼ����ú����᷵�س�ʱ��Ϣ��
//			  Priority	   ȡͼ���ȼ� �����emCameraGetImagePriority
// ����ֵ   : �ɹ�ʱ������RGB���ݻ��������׵�ַ;
//            ���򷵻�0��
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetImageBufferPriorityEx3)(
	CameraHandle hCamera, 
	BYTE*pImageData,
	UINT uOutFormat,
	int *piWidth,
	int *piHeight,
	UINT* puTimeStamp,
	UINT wTimes,
	UINT Priority
	);

/******************************************************/
// ������   : CameraClearBuffer
// �������� : ���������ѻ��������֡
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraClearBuffer)(
	CameraHandle hCamera
	);

/******************************************************/
// ������   : CameraSoftTriggerEx
// �������� : ִ��һ��������ִ�к󣬻ᴥ����CameraSetTriggerCount
//          ָ����֡����
// ����     : hCamera  ����ľ������CameraInit������á�
//			  uFlags ���ܱ�־,���emCameraSoftTriggerExFlags�еĶ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSoftTriggerEx)(
	CameraHandle hCamera,
	UINT uFlags
	);

/******************************************************/
// ������ 	: CameraSetHDR
// ��������	: ���������HDR����Ҫ���֧�֣�����HDR���ܵ��ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            value		   HDRϵ������Χ0.0��1.0
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetHDR)(
	CameraHandle    hCamera,
	float           value
	);

/******************************************************/
// ������ 	: CameraGetHDR
// ��������	: ��ȡ�����HDR����Ҫ���֧�֣�����HDR���ܵ��ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            value		   HDRϵ������Χ0.0��1.0
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetHDR)(
	CameraHandle    hCamera,
	float*          value
	);

/******************************************************/
// ������ 	: CameraGetFrameID
// ��������	: ��ȡ��ǰ֡��ID�������֧��(����ȫϵ��֧��)���˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            id		   ֡ID
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetFrameID)(
	CameraHandle    hCamera,
	UINT*			id
	);

/******************************************************/
// ������ 	: CameraGetFrameTimeStamp
// ��������	: ��ȡ��ǰ֡��ʱ���(��λ΢��)
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            TimeStampL   ʱ�����32λ
//			  TimeStampH   ʱ�����32λ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetFrameTimeStamp)(
	CameraHandle    hCamera,
	UINT*           TimeStampL,
	UINT*			TimeStampH
	);

/******************************************************/
// ������ 	: CameraSetHDRGainMode
// ��������	: �������������ģʽ����Ҫ���֧�֣���������ģʽ�л����ܵ��ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            value		   0��������    1��������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetHDRGainMode)(
	CameraHandle    hCamera,
	int				value
	);

/******************************************************/
// ������ 	: CameraGetHDRGainMode
// ��������	: ��ȡ���������ģʽ����Ҫ���֧�֣���������ģʽ�л����ܵ��ͺţ��˺������ش�����룬��ʾ��֧�֡�
// ����	    : hCamera	   ����ľ������CameraInit������á� 
//            value		   0��������    1��������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGetHDRGainMode)(
	CameraHandle    hCamera,
	int*			value
	);

/******************************************************/
// ������ 	: CameraCreateDIBitmap
// ��������	: ��֡���ݴ���HBITMAP
// ����	    : hDC: Handle to a device context��WIN32 API CreateDIBitmap�Ĳ���hdc��
//            pFrameBuffer: ֡����
//			  pFrameHead: ֡ͷ
//			  outBitmap: �´�����HBITMAP��ʹ�������Ҫ����WIN32 API DeleteObject�ͷţ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraCreateDIBitmap)(
	HDC hDC, 
	BYTE *pFrameBuffer, 
	tSdkFrameHead* pFrameHead,
	HBITMAP* outBitmap
	);

/******************************************************/
// ������ 	: CameraDrawFrameBuffer
// ��������	: ����֡��ָ������
// ����	    : pFrameBuffer: ֡����
//			  pFrameHead: ֡ͷ
//			  hWnd: Ŀ�Ĵ���
//			  Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
//			  Mode ����ģʽ   0: �ȱ�����  1����������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraDrawFrameBuffer)(
	BYTE *pFrameBuffer, 
	tSdkFrameHead* pFrameHead,
	HWND hWnd,
	int Algorithm,
	int Mode
	);

/******************************************************/
// ������ 	: CameraFlipFrameBuffer
// ��������	: ��ת֡����
// ����	    : pFrameBuffer: ֡����
//			  pFrameHead: ֡ͷ
//			  Flags: 1:����   2������    3�����¡����ҽ���һ�η�ת(�൱����ת180��)
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraFlipFrameBuffer)(
	BYTE *pFrameBuffer, 
	tSdkFrameHead* pFrameHead,
	int Flags
	);

/******************************************************/
// ������ 	: CameraConvertFrameBufferFormat
// ��������	: ת��֡���ݸ�ʽ
// ����	    : hCamera: ������
//			  pInFrameBuffer: ����֡����
//			  pOutFrameBuffer: ���֡����
//			  outWidth: ������
//			  outHeight: ����߶�
//			  outMediaType: �����ʽ
//			  pFrameHead: ֡ͷ��Ϣ��ת���ɹ����������Ϣ�ᱻ�޸�Ϊ���֡����Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)
//            ���򷵻� ��0ֵ���ο�CameraStatus.h�д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraConvertFrameBufferFormat)(
	CameraHandle hCamera,
	BYTE *pInFrameBuffer, 
	BYTE *pOutFrameBuffer, 
	int outWidth,
	int outHeight,
	UINT outMediaType,
	tSdkFrameHead* pFrameHead
	);

/******************************************************/
// ������   : CameraSetConnectionStatusCallback
// �������� : �����������״̬�ı�Ļص�֪ͨ��������������ߡ�����ʱ��
//        pCallBack��ָ��Ļص������ͻᱻ���á� 
// ����     : hCamera ����ľ������CameraInit������á�
//            pCallBack �ص�����ָ�롣
//            pContext  �ص������ĸ��Ӳ������ڻص�����������ʱ
//				�ø��Ӳ����ᱻ���룬����ΪNULL��������
//				������ʱЯ��������Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetConnectionStatusCallback)(
	CameraHandle        hCamera,
	CAMERA_CONNECTION_STATUS_CALLBACK pCallBack,
	PVOID               pContext
	);

/******************************************************/
// ������   : CameraSetLightingControllerMode
// �������� : ���ù�Դ�����������ģʽ���������ϵ������ҪӲ��֧�֣�
// ����     : hCamera ����ľ������CameraInit������á�
//            index ����������
//            mode ���ģʽ��0:��������� 1:�ֶ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetLightingControllerMode)(
	CameraHandle        hCamera,
	int					index,
	int					mode
	);

/******************************************************/
// ������   : CameraSetLightingControllerState
// �������� : ���ù�Դ�����������״̬���������ϵ������ҪӲ��֧�֣�
// ����     : hCamera ����ľ������CameraInit������á�
//            index ����������
//            state ���״̬��0:�ر�  1���򿪣�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraSetLightingControllerState)(
	CameraHandle        hCamera,
	int					index,
	int					state
	);

typedef CameraSdkStatus (__stdcall *_CameraSetFrameResendCount)(
	CameraHandle        hCamera,
	int					count
	);

typedef CameraSdkStatus (__stdcall *_CameraGetEyeCount)(
	CameraHandle        hCamera,
	int*				EyeCount
	);

typedef CameraSdkStatus (__stdcall *_CameraMultiEyeImageProcess)(
	CameraHandle        hCamera, 
	int					iEyeIndex,
	BYTE*               pbyIn, 
	tSdkFrameHead*		pInFrInfo,
	BYTE*               pbyOut,
	tSdkFrameHead*      pOutFrInfo,
	UINT                uOutFormat,
	UINT                uReserved
	);
	
typedef CameraSdkStatus (__stdcall *_CameraGetRegionAverageGray)(
	BYTE *pFrameBuffer, 
	tSdkFrameHead* pFrameHead,
	int Left,
	int Top,
	int Width,
	int Height,
	int *AvgGray
	);

typedef CameraSdkStatus (__stdcall *_CameraGetMediaCapability)(
	CameraHandle    hCamera, 
	int	            iMediaType,
	UINT			*uCap
	);

typedef CameraSdkStatus (__stdcall *_CameraSetMediaBitRate)(
	CameraHandle    hCamera, 
	int	            iMediaType,
	UINT			uRate
	);

typedef CameraSdkStatus (__stdcall *_CameraGetMediaBitRate)(
	CameraHandle    hCamera, 
	int	            iMediaType,
	UINT			*uRate
	);
	
typedef CameraSdkStatus (__stdcall *_CameraSetFrameEventCallback)(
	CameraHandle        hCamera,
	CAMERA_FRAME_EVENT_CALLBACK pCallBack,
	PVOID               pContext
	);
	
typedef CameraSdkStatus (__stdcall *_CameraSetNoiseReductionValue)(
	CameraHandle    hCamera,
	int				value
	);

typedef CameraSdkStatus (__stdcall *_CameraGetNoiseReductionValue)(
	CameraHandle    hCamera,
	int*			value
	);

typedef CameraSdkStatus (__stdcall *_CameraSetLogarithmicCurveValue)(
	CameraHandle    hCamera,
	int				value
	);

typedef CameraSdkStatus (__stdcall *_CameraGetLogarithmicCurveValue)(
	CameraHandle    hCamera,
	int*			value
	);

typedef CameraSdkStatus (__stdcall *_CameraSetSpliceLines)(
	CameraHandle    hCamera,
	int             numLines
	);

typedef CameraSdkStatus (__stdcall *_CameraGetSpliceLines)(
	CameraHandle    hCamera,
	int*            numLines
	);
	
typedef CameraSdkStatus (__stdcall *_CameraSnapChannelBuffer)(
	CameraHandle	hCamera,
	char const*		pszChannelName,
	tSdkFrameHead*	pFrameInfo,
	BYTE**			pbyBuffer,
	UINT			wTimes
	);
	
typedef CameraSdkStatus (__stdcall *_CameraReleaseChannelBuffer)(
	CameraHandle    hCamera, 
	char const*		pszChannelName,
	BYTE*           pbyBuffer
	);
	
typedef CameraSdkStatus (__stdcall *_CameraSetRotaryEncTrigger)(
	CameraHandle    hCamera,
	int             action
	);

typedef CameraSdkStatus (__stdcall *_CameraGetRotaryEncTrigger)(
	CameraHandle    hCamera,
	int*            action
	);

/******************************************************/
// ������   : CameraGrabber_CreateFromDevicePage
// �������� : ��������б����û�ѡ��Ҫ�򿪵����
// ����     : �������ִ�гɹ����غ���������Grabber
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_CreateFromDevicePage)(
	void** Grabber
	);

/******************************************************/
// ������   : CameraGrabber_CreateByIndex
// �������� : ʹ������б���������Grabber
// ����     : Grabber    �������ִ�гɹ����غ���������Grabber
//			  Index		�������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_CreateByIndex)(
	void** Grabber,
	int Index
	);

/******************************************************/
// ������   : CameraGrabber_CreateByName
// �������� : ʹ��������ƴ���Grabber
// ����     : Grabber    �������ִ�гɹ����غ���������Grabber
//			  Name		�������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_CreateByName)(
	void** Grabber,
	char* Name
	);

/******************************************************/
// ������   : CameraGrabber_Create
// �������� : ���豸������Ϣ����Grabber
// ����     : Grabber    �������ִ�гɹ����غ���������Grabber����
//			  pDevInfo	��������豸������Ϣ����CameraEnumerateDevice������á� 
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_Create)(
	void** Grabber,
	tSdkCameraDevInfo* pDevInfo
	);

/******************************************************/
// ������   : CameraGrabber_Destroy
// �������� : ����Grabber
// ����     : Grabber
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_Destroy)(
	void* Grabber
	);

/******************************************************/
// ������	: CameraGrabber_SetHWnd
// ��������	: ����Ԥ����Ƶ����ʾ����
// ����		: Grabber
//			  hWnd  ���ھ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SetHWnd)(
	void* Grabber,
	HWND hWnd
	);

/******************************************************/
// ������	: CameraGrabber_SetPriority
// ��������	: ����ȡͼʹ�õ����ȼ�
// ����		: Grabber
//			  Priority  ȡͼ���ȼ� �����emCameraGetImagePriority
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SetPriority)(
	void* Grabber,
	UINT Priority
	);

/******************************************************/
// ������	: CameraGrabber_StartLive
// ��������	: ����Ԥ��
// ����		: Grabber
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_StartLive)(
	void* Grabber
	);

/******************************************************/
// ������	: CameraGrabber_StopLive
// ��������	: ֹͣԤ��
// ����		: Grabber
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_StopLive)(
	void* Grabber
	);

/******************************************************/
// ������	: CameraGrabber_SaveImage
// ��������	: ץͼ
// ����		: Grabber
//			  Image ����ץȡ����ͼ����Ҫ����CameraImage_Destroy�ͷţ�
//			  TimeOut ��ʱʱ�䣨���룩
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SaveImage)(
	void* Grabber,
	void** Image,
	DWORD TimeOut
	);

/******************************************************/
// ������	: CameraGrabber_SaveImageAsync
// ��������	: �ύһ���첽��ץͼ�����ύ�ɹ����ץͼ��ɻ�ص��û����õ���ɺ���
// ����		: Grabber
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SaveImageAsync)(
	void* Grabber
	);

/******************************************************/
// ������	: CameraGrabber_SaveImageAsyncEx
// ��������	: �ύһ���첽��ץͼ�����ύ�ɹ����ץͼ��ɻ�ص��û����õ���ɺ���
// ����		: Grabber
//			  UserData ��ʹ��CameraImage_GetUserData��Image��ȡ��ֵ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SaveImageAsyncEx)(
	void* Grabber,
	void* UserData
	);

/******************************************************/
// ������	: CameraGrabber_SetSaveImageCompleteCallback
// ��������	: �����첽��ʽץͼ����ɺ���
// ����		: Grabber
//			  Callback ����ץͼ�������ʱ������
//			  Context ��Callback������ʱ����Ϊ��������Callback
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SetSaveImageCompleteCallback)(
	void* Grabber,
	pfnCameraGrabberSaveImageComplete Callback,
	void* Context
	);

/******************************************************/
// ������	: CameraGrabber_SetFrameListener
// ��������	: ����֡��������
// ����		: Grabber
//			  Listener �����������˺�������0��ʾ������ǰ֡
//			  Context ��Listener������ʱ����Ϊ��������Listener
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SetFrameListener)(
	void* Grabber,
	pfnCameraGrabberFrameListener Listener,
	void* Context
	);

/******************************************************/
// ������	: CameraGrabber_SetRawCallback
// ��������	: ����RAW�ص�����
// ����		: Grabber
//			  Callback Raw�ص�����
//			  Context ��Callback������ʱ����Ϊ��������Callback
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SetRawCallback)(
	void* Grabber,
	pfnCameraGrabberFrameCallback Callback,
	void* Context
	);

/******************************************************/
// ������	: CameraGrabber_SetRGBCallback
// ��������	: ����RGB�ص�����
// ����		: Grabber
//			  Callback RGB�ص�����
//			  Context ��Callback������ʱ����Ϊ��������Callback
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_SetRGBCallback)(
	void* Grabber,
	pfnCameraGrabberFrameCallback Callback,
	void* Context
	);

/******************************************************/
// ������	: CameraGrabber_GetCameraHandle
// ��������	: ��ȡ������
// ����		: Grabber
//			  hCamera ���ص�������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_GetCameraHandle)(
	void* Grabber,
	CameraHandle *hCamera
	);

/******************************************************/
// ������	: CameraGrabber_GetStat
// ��������	: ��ȡ֡ͳ����Ϣ
// ����		: Grabber
//			  stat ���ص�ͳ����Ϣ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_GetStat)(
	void* Grabber,
	tSdkGrabberStat *stat
	);

/******************************************************/
// ������	: CameraGrabber_GetCameraDevInfo
// ��������	: ��ȡ���DevInfo
// ����		: Grabber
//			  DevInfo ���ص����DevInfo
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraGrabber_GetCameraDevInfo)(
	void* Grabber,
	tSdkCameraDevInfo *DevInfo
	);

/******************************************************/
// ������	: CameraImage_Create
// ��������	: ����һ���µ�Image
// ����		: Image
//			  pFrameBuffer ֡���ݻ�����
//			  pFrameHead ֡ͷ
//			  bCopy TRUE: ���Ƴ�һ���µ�֡����  FALSE: �����ƣ�ֱ��ʹ��pFrameBufferָ��Ļ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_Create)(
	void** Image,
	BYTE *pFrameBuffer, 
	tSdkFrameHead* pFrameHead,
	BOOL bCopy
	);

/******************************************************/
// ������	: CameraImage_Destroy
// ��������	: ����Image
// ����		: Image
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_Destroy)(
	void* Image
	);

/******************************************************/
// ������	: CameraImage_GetData
// ��������	: ��ȡImage����
// ����		: Image
//			  DataBuffer ͼ������
//			  Head ͼ����Ϣ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_GetData)(
	void* Image,
	BYTE** DataBuffer,
	tSdkFrameHead** Head
	);

/******************************************************/
// ������	: CameraImage_GetUserData
// ��������	: ��ȡImage���û��Զ�������
// ����		: Image
//			  UserData �����û��Զ�������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_GetUserData)(
	void* Image,
	void** UserData
	);

/******************************************************/
// ������	: CameraImage_SetUserData
// ��������	: ����Image���û��Զ�������
// ����		: Image
//			  UserData �û��Զ�������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_SetUserData)(
	void* Image,
	void* UserData
	);

/******************************************************/
// ������	: CameraImage_IsEmpty
// ��������	: �ж�һ��Image�Ƿ�Ϊ��
// ����		: Image
//			  IsEmpty Ϊ�շ���:TRUE(1)  ���򷵻�:FALSE(0)
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_IsEmpty)(
	void* Image,
	BOOL* IsEmpty
	);

/******************************************************/
// ������	: CameraImage_Draw
// ��������	: ����Image��ָ������
// ����		: Image
//			  hWnd Ŀ�Ĵ���
//			  Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_Draw)(
	void* Image,
	HWND hWnd,
	int Algorithm
	);

/******************************************************/
// ������	: CameraImage_BitBlt
// ��������	: ����Image��ָ�����ڣ������ţ�
// ����		: Image
//			  hWnd Ŀ�Ĵ���
//			  xDst,yDst: Ŀ����ε����Ͻ�����
//			  cxDst,cyDst: Ŀ����εĿ��
//			  xSrc,ySrc: ͼ����ε����Ͻ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_BitBlt)(
	void* Image,
	HWND hWnd,
	int xDst,
	int yDst,
	int cxDst,
	int cyDst,
	int xSrc,
	int ySrc
	);

/******************************************************/
// ������	: CameraImage_SaveAsBmp
// ��������	: ��bmp��ʽ����Image
// ����		: Image
//			  FileName �ļ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_SaveAsBmp)(
	void* Image,
	char const* FileName
	);

/******************************************************/
// ������	: CameraImage_SaveAsJpeg
// ��������	: ��jpg��ʽ����Image
// ����		: Image
//			  FileName �ļ���
//			  Quality ��������(1-100)��100Ϊ������ѵ��ļ�Ҳ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_SaveAsJpeg)(
	void* Image,
	char const* FileName,
	BYTE  Quality
	);

/******************************************************/
// ������	: CameraImage_SaveAsPng
// ��������	: ��png��ʽ����Image
// ����		: Image
//			  FileName �ļ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_SaveAsPng)(
	void* Image,
	char const* FileName
	);

/******************************************************/
// ������	: CameraImage_SaveAsRaw
// ��������	: ����raw Image
// ����		: Image
//			  FileName �ļ���
//			  Format 0: 8Bit Raw     1: 16Bit Raw
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
typedef CameraSdkStatus (__stdcall *_CameraImage_SaveAsRaw)(
	void* Image,
	char const* FileName,
	int Format
	);
	
/// @ingroup API_UTIL
/// \~chinese
/// \brief �������Ź���
/// \param [out] ZoomTool �����´��������Ź���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Create a zoom tool
/// \param [out] ZoomTool returns the newly created zoom tool
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_Create)(
	void** ZoomTool
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief �������Ź���
/// \param [in] ZoomTool ���Ź���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Destory a zoom tool
/// \param [in] ZoomTool zoom tool
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_Destory)(
	void* ZoomTool
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief �����ӿ�ԭ��
/// \param [in] ZoomTool ���Ź���
/// \param [in] x      ������ֵ
/// \param [in] y      ������ֵ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the viewport origin
/// \param [in] ZoomTool zoom tool
/// \param [in] x coordinate value
/// \param [in] y coordinate value
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_SetViewOrg)(
	void*			ZoomTool, 
	float           x,
	float           y
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ�ӿ�ԭ��
/// \param [in] ZoomTool ���Ź���
/// \param [in] x      ������ֵ
/// \param [in] y      ������ֵ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the viewport origin
/// \param [in] ZoomTool zoom tool
/// \param [in] x coordinate value
/// \param [in] y coordinate value
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetViewOrg)(
	void*			ZoomTool, 
	float*          x,
	float*          y
	);
	
/// @ingroup API_UTIL
/// \~chinese
/// \brief �����ӿ����ĵ�����
/// \param [in] ZoomTool ���Ź���
/// \param [in] x      ������ֵ
/// \param [in] y      ������ֵ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the viewport center point coordinates
/// \param [in] ZoomTool zoom tool
/// \param [in] x coordinate value
/// \param [in] y coordinate value
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_SetViewCenter)(
	void*			ZoomTool, 
	float           x,
	float           y
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ�ӿ����ĵ�����
/// \param [in] ZoomTool ���Ź���
/// \param [out] x      ������ֵ
/// \param [out] y      ������ֵ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the coordinates of the center point of the viewport
/// \param [in] ZoomTool zoom tool
/// \param [out] x coordinate value
/// \param [out] y coordinate value
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetViewCenter)(
	void*			ZoomTool, 
	float*          x,
	float*          y
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief �����ӿڴ�С
/// \param [in] ZoomTool ���Ź���
/// \param [in] w      �ӿڿ��
/// \param [in] h      �ӿڸ߶�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the viewport size
/// \param [in] ZoomTool zoom tool
/// \param [in] w Viewport width
/// \param [in] h Viewport height
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_SetViewSize)(
	void*			ZoomTool, 
	int             w,
	int             h
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ�ӿڴ�С
/// \param [in] ZoomTool ���Ź���
/// \param [in] w      �ӿڿ��
/// \param [in] h      �ӿڸ߶�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the viewport size
/// \param [in] ZoomTool zoom tool
/// \param [in] w Viewport width
/// \param [in] h Viewport height
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetViewSize)(
	void*			ZoomTool, 
	int*            w,
	int*            h
	);
	
/// @ingroup API_UTIL
/// \~chinese
/// \brief �����ӿڵĹ���λ��
/// \param [in] ZoomTool ���Ź���
/// \param [in] xPos     ����ֵ��0-1��
/// \param [in] yPos     ����ֵ��0-1��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the scroll position of the viewport
/// \param [in] ZoomTool zoom tool
/// \param [in] xPos horizontal value (0-1)
/// \param [in] yPos vertical value (0-1)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_SetViewScrollPos)(
	void*			ZoomTool, 
	float           xPos,
	float           yPos
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ�ӿڵĹ���λ��
/// \param [in] ZoomTool ���Ź���
/// \param [out] xPos    ����ֵ��0-1����<0��ʾ�������ȫ��ʾ���������
/// \param [out] yPos    ����ֵ��0-1����<0��ʾ�������ȫ��ʾ���������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the scroll position of the viewport
/// \param [in] ZoomTool zoom tool
/// \param [out] xPos horizontal value (0-1)(<0 means the landscape can be completely displayed without scrolling)
/// \param [out] yPos vertical value (0-1)(<0 means the portrait can be fully displayed without scrolling)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetViewScrollPos)(
	void*			ZoomTool, 
	float*          xPos,
	float*          yPos
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ�ӿڵĹ�����Χ
/// \param [in] ZoomTool ���Ź���
/// \param [out] xRange  ���������Χ
/// \param [out] yRange  ���������Χ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the scrolling range of the viewport
/// \param [in] ZoomTool zoom tool
/// \param [out] xRange horizontal scrolling range
/// \param [out] yRange vertical scrolling range
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetViewScrollRange)(
	void*			ZoomTool, 
	float*          xRange,
	float*          yRange
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ����ͼƬ֡�Ĵ�С
/// \param [in] ZoomTool ���Ź���
/// \param [in] w      ֡���
/// \param [in] h      ֡�߶�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the frame size
/// \param [in] ZoomTool zoom tool
/// \param [in] w Frame width
/// \param [in] h Frame height
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_SetFrameSize)(
	void*			ZoomTool, 
	int             w,
	int             h
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡͼƬ֡�Ĵ�С
/// \param [in] ZoomTool ���Ź���
/// \param [in] w      ֡���
/// \param [in] h      ֡�߶�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the frame size
/// \param [in] ZoomTool zoom tool
/// \param [in] w Frame width
/// \param [in] h Frame height
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetFrameSize)(
	void*			ZoomTool, 
	int*            w,
	int*            h
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief �������ű���
/// \param [in] ZoomTool ���Ź���
/// \param [in] ratio   ���ű���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the zoom ratio
/// \param [in] ZoomTool zoom tool
/// \param [in] ratio scaling ratio
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_SetScale)(
	void*			ZoomTool, 
	float           ratio
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ���ű���
/// \param [in] ZoomTool ���Ź���
/// \param [in] ratio   ���ű���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the zoom ratio
/// \param [in] ZoomTool zoom tool
/// \param [in] ratio scaling ratio
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetScale)(
	void*			ZoomTool, 
	float*          ratio
	);
	
/// @ingroup API_UTIL
/// \~chinese
/// \brief �������Ųο���
/// \param [in] ZoomTool ���Ź���
/// \param [in] xAnchor  ˮƽ�ο���(0-1)
/// \param [in] yAnchor  ��ֱ�ο���(0-1)
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set zoom reference point
/// \param [in] ZoomTool zoom tool
/// \param [in] xAnchor horizontal reference point (0-1)
/// \param [in] yAnchor vertical reference point (0-1)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_SetScaleAnchor)(
	void*			ZoomTool, 
	float           xAnchor,
	float           yAnchor
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ���Ųο���
/// \param [in] ZoomTool ���Ź���
/// \param [out] xAnchor  ˮƽ�ο���(0-1)
/// \param [out] yAnchor  ��ֱ�ο���(0-1)
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get zoom reference point
/// \param [in] ZoomTool zoom tool
/// \param [out] xAnchor horizontal reference point (0-1)
/// \param [out] yAnchor vertical reference point (0-1)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetScaleAnchor)(
	void*			ZoomTool, 
	float*          xAnchor,
	float*          yAnchor
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��ȡ���ƾ���
/// \param [in] ZoomTool ���Ź���
/// \param [in] FrameX   ֡�ھ���X����
/// \param [in] FrameY   ֡�ھ���Y����
/// \param [in] FrameW   ֡�ھ��ο��
/// \param [in] FrameH   ֡�ھ��θ߶�
/// \param [in] ViewX    �ӿ��ھ���X����
/// \param [in] ViewY    �ӿ��ھ���Y����
/// \param [in] ViewW    �ӿ��ھ��ο��
/// \param [in] ViewH    �ӿ��ھ��θ߶�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get the drawing rectangle
/// \param [in] ZoomTool zoom tool
/// \param [in] FrameX Intra-frame rectangle X coordinate
/// \param [in] FrameY Intra-frame rectangle Y coordinate
/// \param [in] FrameW Intra-frame rectangle width
/// \param [in] FrameH Intra-frame height
/// \param [in] ViewX The X coordinate of the rectangle inside the viewport
/// \param [in] ViewY The Y coordinate of the rectangle inside the viewport
/// \param [in] ViewW The width of the rectangle inside the viewport
/// \param [in] ViewH The height of the rectangle inside the viewport
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_GetDrawRect)(
	void*			ZoomTool, 
	int*			FrameX,
	int*			FrameY,
	int*			FrameW,
	int*			FrameH,
	int*			ViewX,
	int*			ViewY,
	int*			ViewW,
	int*			ViewH
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ����任
/// \param [in] ZoomTool ���Ź���
/// \param [in] Type     �任����   0: �ӿ�ת֡����     1���ӿ�ת��������(֡����*��������)
/// \param [inout] PointX    X���꣨���ر任���X���꣩
/// \param [inout] PointY    Y���꣨���ر任���Y���꣩
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Coordinate transformation
/// \param [in] ZoomTool zoom tool
/// \param [in] Type Transform type    0: Viewport to frame coordinates   1: Viewport to world coordinates (frame coordinates * zoom factor)
/// \param [inout] PointX X coordinate (returns the transformed X coordinate)
/// \param [inout] PointY Y coordinate (returns the transformed Y coordinate)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_Transform)(
	void*			ZoomTool, 
	int				Type,
	float*			PointX,
	float*			PointY
	);

/// @ingroup API_UTIL
/// \~chinese
/// \brief ��֡���ݰ��趨���ӿںͱ������Ƶ�����
/// \param [in] ZoomTool ���Ź���
/// \param [in] Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
/// \param [in] pFrameBuffer ֡����
/// \param [in] pFrameHead ֡ͷ
/// \param [in] hWnd Ŀ�Ĵ��ھ��
/// \param [in] xDst Ŀ��������Ͻ�X����
/// \param [in] yDst Ŀ��������Ͻ�Y����
/// \param [in] hBackBrush ������ˢ(NULL:����䱳��)
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Draw frame data to a window according to the set viewport and scale
/// \param [in] ZoomTool zoom tool
/// \param [in] Algorithm scaling algorithm 0:fast but slightly worse quality   1:slower but better quality
/// \param [in] pFrameBuffer frame data
/// \param [in] pFrameHead frame header
/// \param [in] hWnd destination window handle
/// \param [in] xDst X coordinate of the upper left corner of the target rectangle
/// \param [in] yDst Y coordinate of the upper left corner of the target rectangle
/// \param [in] hBackBrush background brush (NULL: no background fill)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_Draw)(
	void*			ZoomTool, 
	int				Algorithm,
	void*			pFrameBuffer,
	tSdkFrameHead*	pFrameHead,
	HWND			hWnd,
	int				xDst,
	int				yDst,
	HBRUSH			hBackBrush
	);
	
/// @ingroup API_ZOOM_DISPLAY
/// \~chinese
/// \brief ��֡���ݰ��趨���ӿںͱ������Ƶ����ڣ����ҵ���ʮ���ߡ��ع�Ͱ�ƽ�ⴰ�ڡ�
/// \param [in] ZoomTool ���Ź���
/// \param [in] Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
/// \param [in] pFrameBuffer ֡����
/// \param [in] pFrameHead ֡ͷ
/// \param [in] hWnd Ŀ�Ĵ��ھ��
/// \param [in] xDst Ŀ��������Ͻ�X����
/// \param [in] yDst Ŀ��������Ͻ�Y����
/// \param [in] hBackBrush ������ˢ(NULL:����䱳��)
/// \param [in] hOverlayCam ���Ӵ������ʮ���ߡ��عⴰ�ڡ���ƽ�ⴰ��(<=0: ������)
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Draw frame data to a window according to the set viewport and scale
/// \param [in] ZoomTool zoom tool
/// \param [in] Algorithm scaling algorithm 0:fast but slightly worse quality   1:slower but better quality
/// \param [in] pFrameBuffer frame data
/// \param [in] pFrameHead frame header
/// \param [in] hWnd destination window handle
/// \param [in] xDst X coordinate of the upper left corner of the target rectangle
/// \param [in] yDst Y coordinate of the upper left corner of the target rectangle
/// \param [in] hBackBrush background brush (NULL: no background fill)
/// \param [in] hOverlayCam Overlay this camera's cross hair, exposure window, white balance window (<=0: no overlay)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
typedef CameraSdkStatus (__stdcall *_CameraZoomTool_DrawEx)(
	void*			ZoomTool, 
	int				Algorithm,
	void*			pFrameBuffer,
	tSdkFrameHead*	pFrameHead,
	HWND			hWnd,
	int				xDst,
	int				yDst,
	HBRUSH			hBackBrush,
	CameraHandle	hOverlayCam
	);


#ifdef API_LOAD_MAIN
#define EXTERN 
#else
#define EXTERN extern
#endif

EXTERN INT gSdkLanguageSel;//0:English 1:Chinese

EXTERN _CameraSdkInit CameraSdkInit;

EXTERN _CameraSetSysOption CameraSetSysOption;

EXTERN _CameraSetCallbackFunction CameraSetCallbackFunction;

EXTERN _CameraGetInformation CameraGetInformation;

EXTERN _CameraSaveImage CameraSaveImage;

EXTERN _CameraInitRecord CameraInitRecord;

EXTERN _CameraStopRecord CameraStopRecord;

EXTERN _CameraPushFrame CameraPushFrame;

EXTERN _CameraSpecialControl CameraSpecialControl;

EXTERN _CameraSnapToBuffer CameraSnapToBuffer;

EXTERN _CameraSnapJpegToFile CameraSnapJpegToFile;

EXTERN _CameraIsOpened CameraIsOpened;

EXTERN _CameraInit CameraInit;

EXTERN _CameraInitEx CameraInitEx;

EXTERN _CameraInitEx2 CameraInitEx2;

EXTERN _CameraUnInit CameraUnInit;

EXTERN _CameraPlay CameraPlay;

EXTERN _CameraPause CameraPause;

EXTERN _CameraStop CameraStop;

EXTERN _CameraSetDisplayMode CameraSetDisplayMode;

EXTERN _CameraDisplayRGB24 CameraDisplayRGB24;

EXTERN _CameraSetDisplayOffset CameraSetDisplayOffset;

EXTERN _CameraImageOverlay CameraImageOverlay;

EXTERN _CameraDisplayInit CameraDisplayInit;

EXTERN _CameraDisplayInitEx CameraDisplayInitEx;

EXTERN _CameraSetDisplaySize CameraSetDisplaySize;

EXTERN _CameraGetImageBuffer CameraGetImageBuffer;

EXTERN _CameraGetImageBufferEx CameraGetImageBufferEx;

EXTERN _CameraReleaseImageBuffer CameraReleaseImageBuffer;

EXTERN _CameraCreateSettingPage CameraCreateSettingPage;

EXTERN _CameraSetActiveSettingSubPage CameraSetActiveSettingSubPage;

EXTERN _CameraSetSettingPageParent CameraSetSettingPageParent;

EXTERN _CameraGetSettingPageHWnd CameraGetSettingPageHWnd;

EXTERN _CameraUpdateSettingPage CameraUpdateSettingPage;

EXTERN _CameraCustomizeResolution CameraCustomizeResolution;

EXTERN _CameraSetMirror CameraSetMirror;

EXTERN _CameraGetMirror CameraGetMirror;

EXTERN _CameraSetHardwareMirror CameraSetHardwareMirror;

EXTERN _CameraGetHardwareMirror CameraGetHardwareMirror;

EXTERN _CameraSetRotate CameraSetRotate;

EXTERN _CameraGetRotate CameraGetRotate;

EXTERN _CameraSetMonochrome CameraSetMonochrome;

EXTERN _CameraGetMonochrome CameraGetMonochrome;

EXTERN _CameraSetInverse CameraSetInverse;

EXTERN _CameraGetInverse CameraGetInverse;

EXTERN _CameraGetImageResolution CameraGetImageResolution;

EXTERN _CameraGetImageResolutionEx CameraGetImageResolutionEx;

EXTERN _CameraSetImageResolution CameraSetImageResolution;

EXTERN _CameraSetImageResolutionEx CameraSetImageResolutionEx;

EXTERN _CameraGetMediaType CameraGetMediaType;

EXTERN _CameraSetMediaType CameraSetMediaType;

EXTERN _CameraGetRawMaxAvailBits CameraGetRawMaxAvailBits;

EXTERN _CameraSetRawStartBit CameraSetRawStartBit;

EXTERN _CameraGetRawStartBit CameraGetRawStartBit;

EXTERN _CameraSetAeState CameraSetAeState;

EXTERN _CameraGetAeState CameraGetAeState;

EXTERN _CameraSetAeTarget CameraSetAeTarget;

EXTERN _CameraGetAeTarget CameraGetAeTarget;

EXTERN _CameraSetAeExposureRange CameraSetAeExposureRange;

EXTERN _CameraGetAeExposureRange CameraGetAeExposureRange;

EXTERN _CameraSetAeAnalogGainRange CameraSetAeAnalogGainRange;

EXTERN _CameraGetAeAnalogGainRange CameraGetAeAnalogGainRange;

EXTERN _CameraSetAeThreshold CameraSetAeThreshold;

EXTERN _CameraGetAeThreshold CameraGetAeThreshold;

EXTERN _CameraSetExposureTime CameraSetExposureTime;

EXTERN _CameraGetExposureTime CameraGetExposureTime;

EXTERN _CameraGetExposureTimeRange CameraGetExposureTimeRange;

EXTERN _CameraSetMultiExposureTime CameraSetMultiExposureTime;

EXTERN _CameraGetMultiExposureTime CameraGetMultiExposureTime;

EXTERN _CameraSetMultiExposureGamma CameraSetMultiExposureGamma;

EXTERN _CameraGetMultiExposureGamma CameraGetMultiExposureGamma;

EXTERN _CameraSetMultiExposureCount CameraSetMultiExposureCount;

EXTERN _CameraGetMultiExposureCount CameraGetMultiExposureCount;

EXTERN _CameraGetMultiExposureMaxCount CameraGetMultiExposureMaxCount;

EXTERN _CameraGetMultiExposureSupported CameraGetMultiExposureSupported;

EXTERN _CameraGetMultiExposureBlendingSupported CameraGetMultiExposureBlendingSupported;

EXTERN _CameraSetMultiExposureBlendingEnable CameraSetMultiExposureBlendingEnable;

EXTERN _CameraGetMultiExposureBlendingEnable CameraGetMultiExposureBlendingEnable;

EXTERN _CameraSetMultiExposureBlendingRatios CameraSetMultiExposureBlendingRatios;

EXTERN _CameraGetMultiExposureBlendingRatios CameraGetMultiExposureBlendingRatios;

EXTERN _CameraGetExposureLineTime CameraGetExposureLineTime;

EXTERN _CameraSetAnalogGain CameraSetAnalogGain;

EXTERN _CameraGetAnalogGain CameraGetAnalogGain;

EXTERN _CameraSetAnalogGainX CameraSetAnalogGainX;

EXTERN _CameraGetAnalogGainX CameraGetAnalogGainX;

EXTERN _CameraGetAnalogGainXRange CameraGetAnalogGainXRange;

EXTERN _CameraSetSharpness CameraSetSharpness;

EXTERN _CameraGetSharpness CameraGetSharpness;

EXTERN _CameraGetPresetClrTemp CameraGetPresetClrTemp;

EXTERN _CameraSetPresetClrTemp CameraSetPresetClrTemp;

EXTERN _CameraSetUserClrTempGain CameraSetUserClrTempGain;

EXTERN _CameraGetUserClrTempGain CameraGetUserClrTempGain;

EXTERN _CameraSetUserClrTempMatrix CameraSetUserClrTempMatrix;

EXTERN _CameraGetUserClrTempMatrix CameraGetUserClrTempMatrix;

EXTERN _CameraSetClrTempMode CameraSetClrTempMode;

EXTERN _CameraGetClrTempMode CameraGetClrTempMode;

EXTERN _CameraSetLutMode CameraSetLutMode;

EXTERN _CameraGetLutMode CameraGetLutMode;

EXTERN _CameraSelectLutPreset CameraSelectLutPreset;

EXTERN _CameraGetLutPresetSel CameraGetLutPresetSel;

EXTERN _CameraSetCustomLut CameraSetCustomLut;

EXTERN _CameraGetCustomLut CameraGetCustomLut;

EXTERN _CameraGetCurrentLut CameraGetCurrentLut;

EXTERN _CameraSetOnceWB CameraSetOnceWB;

EXTERN _CameraSetOnceBB CameraSetOnceBB;

EXTERN _CameraSetWbMode CameraSetWbMode;

EXTERN _CameraGetWbMode CameraGetWbMode;

EXTERN _CameraSetWbWindow CameraSetWbWindow;

EXTERN _CameraGetWbWindow CameraGetWbWindow;

EXTERN _CameraSetGain CameraSetGain;

EXTERN _CameraGetGain CameraGetGain;

EXTERN _CameraSetGamma CameraSetGamma;

EXTERN _CameraGetGamma CameraGetGamma;

EXTERN _CameraSetSaturation CameraSetSaturation;

EXTERN _CameraGetSaturation CameraGetSaturation;

EXTERN _CameraSetContrast CameraSetContrast;

EXTERN _CameraGetContrast CameraGetContrast;

EXTERN _CameraSetFrameSpeed CameraSetFrameSpeed;

EXTERN _CameraGetFrameSpeed CameraGetFrameSpeed;

EXTERN _CameraSetFrameRate CameraSetFrameRate;

EXTERN _CameraGetFrameRate CameraGetFrameRate;

EXTERN _CameraSetAntiFlick CameraSetAntiFlick;

EXTERN _CameraGetAntiFlick CameraGetAntiFlick;

EXTERN _CameraGetLightFrequency CameraGetLightFrequency;

EXTERN _CameraSetLightFrequency CameraSetLightFrequency;

EXTERN _CameraSetTransPackLen CameraSetTransPackLen;

EXTERN _CameraGetTransPackLen CameraGetTransPackLen;

EXTERN _CameraWriteSN CameraWriteSN;

EXTERN _CameraReadSN CameraReadSN;

EXTERN _CameraSaveParameter CameraSaveParameter;

EXTERN _CameraLoadParameter CameraLoadParameter;

EXTERN _CameraGetCurrentParameterGroup CameraGetCurrentParameterGroup;

EXTERN _CameraEnumerateDevice CameraEnumerateDevice;

EXTERN _CameraEnumerateDeviceEx CameraEnumerateDeviceEx;

EXTERN _CameraGetCapability CameraGetCapability;

EXTERN _CameraImageProcess CameraImageProcess;

EXTERN _CameraImageProcessEx CameraImageProcessEx;

EXTERN _CameraSoftTrigger CameraSoftTrigger;

EXTERN _CameraSetTriggerMode CameraSetTriggerMode;

EXTERN _CameraGetTriggerMode CameraGetTriggerMode;

EXTERN _CameraSetStrobeMode CameraSetStrobeMode;

EXTERN _CameraGetStrobeMode CameraGetStrobeMode;

EXTERN _CameraSetStrobeDelayTime CameraSetStrobeDelayTime;

EXTERN _CameraGetStrobeDelayTime CameraGetStrobeDelayTime;

EXTERN _CameraSetStrobePulseWidth CameraSetStrobePulseWidth;

EXTERN _CameraGetStrobePulseWidth CameraGetStrobePulseWidth;

EXTERN _CameraSetStrobePolarity CameraSetStrobePolarity;

EXTERN _CameraGetStrobePolarity CameraGetStrobePolarity;

EXTERN _CameraSetExtTrigSignalType CameraSetExtTrigSignalType;

EXTERN _CameraGetExtTrigSignalType CameraGetExtTrigSignalType;

EXTERN _CameraSetExtTrigShutterType CameraSetExtTrigShutterType;

EXTERN _CameraGetExtTrigShutterType CameraGetExtTrigShutterType;

EXTERN _CameraSetExtTrigDelayTime CameraSetExtTrigDelayTime;

EXTERN _CameraGetExtTrigDelayTime CameraGetExtTrigDelayTime;

EXTERN _CameraSetExtTrigIntervalTime CameraSetExtTrigIntervalTime;

EXTERN _CameraGetExtTrigIntervalTime CameraGetExtTrigIntervalTime;

EXTERN _CameraSetExtTrigJitterTime CameraSetExtTrigJitterTime;

EXTERN _CameraGetExtTrigJitterTime CameraGetExtTrigJitterTime;

EXTERN _CameraGetExtTrigCapability CameraGetExtTrigCapability;

EXTERN _CameraPauseLevelTrigger CameraPauseLevelTrigger;

EXTERN _CameraShowSettingPage CameraShowSettingPage;

EXTERN _CameraGetFrameStatistic CameraGetFrameStatistic;

EXTERN _CameraGetResolutionForSnap CameraGetResolutionForSnap;

EXTERN _CameraSetResolutionForSnap CameraSetResolutionForSnap;

EXTERN _CameraIsAeWinVisible CameraIsAeWinVisible;

EXTERN _CameraIsWbWinVisible CameraIsWbWinVisible;

EXTERN _CameraGetNoiseFilterState CameraGetNoiseFilterState;

EXTERN _CameraSetParameterMode CameraSetParameterMode;

EXTERN _CameraGetParameterMode CameraGetParameterMode;

EXTERN _CameraSetParameterMask CameraSetParameterMask;

EXTERN _CameraGetTriggerCount CameraGetTriggerCount;

EXTERN _CameraGetCrossLine CameraGetCrossLine;

EXTERN _CameraSetCrossLine CameraSetCrossLine;

EXTERN _CameraGetTriggerDelayTime CameraGetTriggerDelayTime;

EXTERN _CameraSetTriggerDelayTime CameraSetTriggerDelayTime;

EXTERN _CameraSetAeWinVisible CameraSetAeWinVisible;

EXTERN _CameraSetNoiseFilter CameraSetNoiseFilter;

EXTERN _CameraSetTriggerCount CameraSetTriggerCount;

EXTERN _CameraCustomizeReferWin CameraCustomizeReferWin;

EXTERN _CameraSetAeWindow CameraSetAeWindow;

EXTERN _CameraGetAeWindow CameraGetAeWindow;

EXTERN _CameraReadParameterFromFile CameraReadParameterFromFile;

EXTERN _CameraSetWbWinVisible CameraSetWbWinVisible;

EXTERN _CameraRstTimeStamp CameraRstTimeStamp;

EXTERN _CameraGetCapabilityEx CameraGetCapabilityEx;

EXTERN _CameraSaveUserData CameraSaveUserData;

EXTERN _CameraLoadUserData CameraLoadUserData;

EXTERN _CameraGetFriendlyName CameraGetFriendlyName;

EXTERN _CameraSetFriendlyName CameraSetFriendlyName;

EXTERN _CameraSdkGetVersionString CameraSdkGetVersionString; 

EXTERN _CameraCheckFwUpdate CameraCheckFwUpdate;

EXTERN _CameraGetFirmwareVersion CameraGetFirmwareVersion;

EXTERN _CameraGetFirmwareVision CameraGetFirmwareVision;

EXTERN _CameraGetEnumInfo CameraGetEnumInfo;

EXTERN _CameraGetInerfaceVersion CameraGetInerfaceVersion;

EXTERN _CameraSetIOState CameraSetIOState;
EXTERN _CameraSetIOStateEx CameraSetIOStateEx;

EXTERN _CameraGetOutPutIOState CameraGetOutPutIOState;
EXTERN _CameraGetOutPutIOStateEx CameraGetOutPutIOStateEx;

EXTERN _CameraGetIOState CameraGetIOState;
EXTERN _CameraGetIOStateEx CameraGetIOStateEx;

EXTERN _CameraSetInPutIOMode CameraSetInPutIOMode;

EXTERN _CameraGetInPutIOMode CameraGetInPutIOMode;

EXTERN _CameraSetOutPutIOMode CameraSetOutPutIOMode;

EXTERN _CameraGetOutPutIOMode CameraGetOutPutIOMode;

EXTERN _CameraGetInPutIOModeCapbility CameraGetInPutIOModeCapbility;

EXTERN _CameraGetOutPutIOModeCapbility CameraGetOutPutIOModeCapbility;

EXTERN _CameraSetOutPutPWM CameraSetOutPutPWM;

EXTERN _CameraSetRotaryEncDir CameraSetRotaryEncDir;

EXTERN _CameraGetRotaryEncDir CameraGetRotaryEncDir;

EXTERN _CameraSetRotaryEncFreq CameraSetRotaryEncFreq;

EXTERN _CameraGetRotaryEncFreq CameraGetRotaryEncFreq;

EXTERN _CameraSetInPutIOFormat CameraSetInPutIOFormat;

EXTERN _CameraGetInPutIOFormat CameraGetInPutIOFormat;

EXTERN _CameraSetOutPutIOFormat CameraSetOutPutIOFormat;

EXTERN _CameraGetOutPutIOFormat CameraGetOutPutIOFormat;

EXTERN _CameraGetInPutIOFormatCapbility CameraGetInPutIOFormatCapbility;

EXTERN _CameraGetOutPutIOFormatCapbility CameraGetOutPutIOFormatCapbility;

EXTERN _CameraSetBayerDecAlgorithm CameraSetBayerDecAlgorithm;

EXTERN _CameraGetBayerDecAlgorithm CameraGetBayerDecAlgorithm;

EXTERN _CameraSetBlackLevel CameraSetBlackLevel;

EXTERN _CameraGetBlackLevel CameraGetBlackLevel;

EXTERN _CameraSetWhiteLevel CameraSetWhiteLevel;

EXTERN _CameraGetWhiteLevel CameraGetWhiteLevel;

EXTERN _CameraSetIspOutFormat CameraSetIspOutFormat;

EXTERN _CameraGetIspOutFormat CameraGetIspOutFormat;

EXTERN _CameraGetErrorString CameraGetErrorString;

EXTERN _CameraGetCapabilityEx2 CameraGetCapabilityEx2;

EXTERN _CameraGetImageBufferEx2 CameraGetImageBufferEx2;

EXTERN _CameraGetImageBufferEx3 CameraGetImageBufferEx3;

EXTERN _CameraReConnect CameraReConnect;

EXTERN _CameraConnectTest CameraConnectTest;

EXTERN _CameraSetLedEnable CameraSetLedEnable;

EXTERN _CameraGetLedEnable CameraGetLedEnable;

EXTERN _CameraSetLedOnOff CameraSetLedOnOff;

EXTERN _CameraGetLedOnOff CameraGetLedOnOff;

EXTERN _CameraSetLedDuration CameraSetLedDuration;

EXTERN _CameraGetLedDuration CameraGetLedDuration;

EXTERN _CameraSetLedBrightness CameraSetLedBrightness;

EXTERN _CameraGetLedBrightness CameraGetLedBrightness;

EXTERN _CameraEnableTransferRoi CameraEnableTransferRoi;

EXTERN _CameraSetTransferRoi CameraSetTransferRoi;

EXTERN _CameraGetTransferRoi CameraGetTransferRoi;

EXTERN _CameraAlignMalloc CameraAlignMalloc;

EXTERN _CameraAlignFree CameraAlignFree;

EXTERN _CameraSetAutoConnect CameraSetAutoConnect;

EXTERN _CameraGetAutoConnect CameraGetAutoConnect;

EXTERN _CameraGetReConnectCounts CameraGetReConnectCounts;

EXTERN _CameraSetSingleGrabMode CameraSetSingleGrabMode;

EXTERN _CameraGetSingleGrabMode CameraGetSingleGrabMode;

EXTERN _CameraRestartGrab CameraRestartGrab;

EXTERN _CameraDrawText CameraDrawText;

EXTERN _CameraGigeEnumerateDevice CameraGigeEnumerateDevice;

EXTERN _CameraGigeGetIp CameraGigeGetIp;

EXTERN _CameraGigeSetIp CameraGigeSetIp;

EXTERN _CameraGigeGetMac CameraGigeGetMac;

EXTERN _CameraEnableFastResponse CameraEnableFastResponse;

EXTERN _CameraSetCorrectDeadPixel CameraSetCorrectDeadPixel;

EXTERN _CameraGetCorrectDeadPixel CameraGetCorrectDeadPixel;

EXTERN _CameraFlatFieldingCorrectSetEnable CameraFlatFieldingCorrectSetEnable;

EXTERN _CameraFlatFieldingCorrectGetEnable CameraFlatFieldingCorrectGetEnable;

EXTERN _CameraFlatFieldingCorrectSetParameter CameraFlatFieldingCorrectSetParameter;

EXTERN _CameraFlatFieldingCorrectSaveParameterToFile CameraFlatFieldingCorrectSaveParameterToFile;

EXTERN _CameraFlatFieldingCorrectLoadParameterFromFile CameraFlatFieldingCorrectLoadParameterFromFile;

EXTERN _CameraCommonCall CameraCommonCall;

EXTERN _CameraSetDenoise3DParams CameraSetDenoise3DParams;

EXTERN _CameraGetDenoise3DParams CameraGetDenoise3DParams;

EXTERN _CameraManualDenoise3D CameraManualDenoise3D;

EXTERN _CameraCustomizeDeadPixels CameraCustomizeDeadPixels;

EXTERN _CameraReadDeadPixels CameraReadDeadPixels;

EXTERN _CameraAddDeadPixels CameraAddDeadPixels;

EXTERN _CameraRemoveDeadPixels CameraRemoveDeadPixels;

EXTERN _CameraRemoveAllDeadPixels CameraRemoveAllDeadPixels;

EXTERN _CameraSaveDeadPixels CameraSaveDeadPixels;

EXTERN _CameraSaveDeadPixelsToFile CameraSaveDeadPixelsToFile;

EXTERN _CameraLoadDeadPixelsFromFile CameraLoadDeadPixelsFromFile;

EXTERN _CameraGetImageBufferPriority CameraGetImageBufferPriority;

EXTERN _CameraGetImageBufferPriorityEx CameraGetImageBufferPriorityEx;

EXTERN _CameraGetImageBufferPriorityEx2 CameraGetImageBufferPriorityEx2;

EXTERN _CameraGetImageBufferPriorityEx3 CameraGetImageBufferPriorityEx3;

EXTERN _CameraClearBuffer CameraClearBuffer;

EXTERN _CameraSoftTriggerEx CameraSoftTriggerEx;

EXTERN _CameraSetHDR CameraSetHDR;

EXTERN _CameraGetHDR CameraGetHDR;

EXTERN _CameraGetFrameID CameraGetFrameID;

EXTERN _CameraGetFrameTimeStamp CameraGetFrameTimeStamp;

EXTERN _CameraSetHDRGainMode CameraSetHDRGainMode;

EXTERN _CameraGetHDRGainMode CameraGetHDRGainMode;

EXTERN _CameraCreateDIBitmap CameraCreateDIBitmap;

EXTERN _CameraDrawFrameBuffer CameraDrawFrameBuffer;

EXTERN _CameraFlipFrameBuffer CameraFlipFrameBuffer;

EXTERN _CameraConvertFrameBufferFormat CameraConvertFrameBufferFormat;

EXTERN _CameraSetConnectionStatusCallback CameraSetConnectionStatusCallback;

EXTERN _CameraSetLightingControllerMode CameraSetLightingControllerMode;

EXTERN _CameraSetLightingControllerState CameraSetLightingControllerState;

EXTERN _CameraSetFrameResendCount CameraSetFrameResendCount;

EXTERN _CameraGetEyeCount CameraGetEyeCount;

EXTERN _CameraMultiEyeImageProcess CameraMultiEyeImageProcess;

EXTERN _CameraGetRegionAverageGray CameraGetRegionAverageGray;

EXTERN _CameraGetMediaCapability CameraGetMediaCapability;

EXTERN _CameraSetMediaBitRate CameraSetMediaBitRate;

EXTERN _CameraGetMediaBitRate CameraGetMediaBitRate;

EXTERN _CameraSetFrameEventCallback CameraSetFrameEventCallback;

EXTERN _CameraSetNoiseReductionValue CameraSetNoiseReductionValue;
EXTERN _CameraGetNoiseReductionValue CameraGetNoiseReductionValue;
EXTERN _CameraSetLogarithmicCurveValue CameraSetLogarithmicCurveValue;
EXTERN _CameraGetLogarithmicCurveValue CameraGetLogarithmicCurveValue;
EXTERN _CameraSetSpliceLines CameraSetSpliceLines;
EXTERN _CameraGetSpliceLines CameraGetSpliceLines;
EXTERN _CameraSnapChannelBuffer CameraSnapChannelBuffer;
EXTERN _CameraReleaseChannelBuffer CameraReleaseChannelBuffer;
EXTERN _CameraSetRotaryEncTrigger CameraSetRotaryEncTrigger;
EXTERN _CameraGetRotaryEncTrigger CameraGetRotaryEncTrigger;

EXTERN _CameraGrabber_CreateFromDevicePage CameraGrabber_CreateFromDevicePage;

EXTERN _CameraGrabber_CreateByIndex CameraGrabber_CreateByIndex;

EXTERN _CameraGrabber_CreateByName CameraGrabber_CreateByName;

EXTERN _CameraGrabber_Create CameraGrabber_Create;

EXTERN _CameraGrabber_Destroy CameraGrabber_Destroy;

EXTERN _CameraGrabber_SetHWnd CameraGrabber_SetHWnd;

EXTERN _CameraGrabber_SetPriority CameraGrabber_SetPriority;

EXTERN _CameraGrabber_StartLive CameraGrabber_StartLive;

EXTERN _CameraGrabber_StopLive CameraGrabber_StopLive;

EXTERN _CameraGrabber_SaveImage CameraGrabber_SaveImage;

EXTERN _CameraGrabber_SaveImageAsync CameraGrabber_SaveImageAsync;

EXTERN _CameraGrabber_SaveImageAsyncEx CameraGrabber_SaveImageAsyncEx;

EXTERN _CameraGrabber_SetSaveImageCompleteCallback CameraGrabber_SetSaveImageCompleteCallback;

EXTERN _CameraGrabber_SetFrameListener CameraGrabber_SetFrameListener;

EXTERN _CameraGrabber_SetRawCallback CameraGrabber_SetRawCallback;

EXTERN _CameraGrabber_SetRGBCallback CameraGrabber_SetRGBCallback;

EXTERN _CameraGrabber_GetCameraHandle CameraGrabber_GetCameraHandle;

EXTERN _CameraGrabber_GetStat CameraGrabber_GetStat;

EXTERN _CameraGrabber_GetCameraDevInfo CameraGrabber_GetCameraDevInfo;

EXTERN _CameraImage_Create CameraImage_Create;

EXTERN _CameraImage_Destroy CameraImage_Destroy;

EXTERN _CameraImage_GetData CameraImage_GetData;

EXTERN _CameraImage_GetUserData CameraImage_GetUserData;

EXTERN _CameraImage_SetUserData CameraImage_SetUserData;

EXTERN _CameraImage_IsEmpty CameraImage_IsEmpty;

EXTERN _CameraImage_Draw CameraImage_Draw;

EXTERN _CameraImage_BitBlt CameraImage_BitBlt;

EXTERN _CameraImage_SaveAsBmp CameraImage_SaveAsBmp;

EXTERN _CameraImage_SaveAsJpeg CameraImage_SaveAsJpeg;

EXTERN _CameraImage_SaveAsPng CameraImage_SaveAsPng;

EXTERN _CameraImage_SaveAsRaw CameraImage_SaveAsRaw;

EXTERN _CameraZoomTool_Create CameraZoomTool_Create;
EXTERN _CameraZoomTool_Destory CameraZoomTool_Destory;
EXTERN _CameraZoomTool_SetViewOrg CameraZoomTool_SetViewOrg;
EXTERN _CameraZoomTool_GetViewOrg CameraZoomTool_GetViewOrg;
EXTERN _CameraZoomTool_SetViewCenter CameraZoomTool_SetViewCenter;
EXTERN _CameraZoomTool_GetViewCenter CameraZoomTool_GetViewCenter;
EXTERN _CameraZoomTool_SetViewSize CameraZoomTool_SetViewSize;
EXTERN _CameraZoomTool_GetViewSize CameraZoomTool_GetViewSize;
EXTERN _CameraZoomTool_SetViewScrollPos CameraZoomTool_SetViewScrollPos;
EXTERN _CameraZoomTool_GetViewScrollPos CameraZoomTool_GetViewScrollPos;
EXTERN _CameraZoomTool_GetViewScrollRange CameraZoomTool_GetViewScrollRange;
EXTERN _CameraZoomTool_SetFrameSize CameraZoomTool_SetFrameSize;
EXTERN _CameraZoomTool_GetFrameSize CameraZoomTool_GetFrameSize;
EXTERN _CameraZoomTool_SetScale CameraZoomTool_SetScale;
EXTERN _CameraZoomTool_GetScale CameraZoomTool_GetScale;
EXTERN _CameraZoomTool_SetScaleAnchor CameraZoomTool_SetScaleAnchor;
EXTERN _CameraZoomTool_GetScaleAnchor CameraZoomTool_GetScaleAnchor;
EXTERN _CameraZoomTool_GetDrawRect CameraZoomTool_GetDrawRect;
EXTERN _CameraZoomTool_Transform CameraZoomTool_Transform;
EXTERN _CameraZoomTool_Draw CameraZoomTool_Draw;
EXTERN _CameraZoomTool_DrawEx CameraZoomTool_DrawEx;


CameraSdkStatus LoadSdkApi();

CameraSdkStatus UnloadCameraSdk();

#ifdef API_LOAD_MAIN
#undef API_LOAD_MAIN


//���SDK�汾��ƥ�䣬���ܳ���ĳЩ��������ʧ�ܡ�

#define CHCEK_API_LOAD 0 // 1:����API�������⣬�������ʧ�ܣ�������ʾ�� 0:�����(����ͨ��SDK�汾�Ž��жԱ�)��

#if CHCEK_API_LOAD
#define CHECK_API(API) if(API == NULL)\
{\
	MessageBoxA(NULL,#API,gSdkLanguageSel?"��������ʧ��":"Function load failed!",0);\
	return CAMERA_STATUS_FAILED;\
}
#else
#define CHECK_API(API) 
#endif

HMODULE ghSDK = NULL;

CameraSdkStatus LoadSdkApi()
{
	char szCompany[64];
	char strPath[MAX_PATH];
	char strDir[MAX_PATH];
	HKEY hkey = NULL;
	DWORD dwType = REG_SZ;
	DWORD dwSize = MAX_PATH;
	BYTE abyValue[MAX_PATH];
	LONG status;

	gSdkLanguageSel = 0;

	if (ERROR_SUCCESS != RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Industry Camera", 0, KEY_READ, &hkey))
		return CAMERA_STATUS_NOT_INITIALIZED;
	dwSize = sizeof(szCompany);
	status = RegQueryValueExA(hkey, "Company", NULL, &dwType, (LPBYTE)szCompany, &dwSize);
	RegCloseKey(hkey);
	hkey = NULL;
	if (status != ERROR_SUCCESS)
		return CAMERA_STATUS_NOT_INITIALIZED;

#ifdef _WIN64
	sprintf_s(strPath, sizeof(strPath), "Software\\%s\\Settings_X64", szCompany);
#else
	sprintf_s(strPath, sizeof(strPath), "Software\\%s\\Settings", szCompany);
#endif
	hkey = NULL;
	RegCreateKeyExA(HKEY_LOCAL_MACHINE, strPath, 0, NULL, 0, KEY_READ, NULL, &hkey, NULL);

	do
	{
		if (NULL != hkey)
		{
			memset(abyValue, 0x00, MAX_PATH);
			dwType = REG_SZ;
			dwSize = MAX_PATH;
			status = RegQueryValueExA(hkey, "Language", NULL, &dwType, abyValue, &dwSize);
			if (ERROR_SUCCESS == status)
			{
				abyValue[MAX_PATH-1] = '\0';
				if (strcmp((const char *)abyValue,"Chinese") == 0)
				{
					gSdkLanguageSel = 1;
				}
				else if (strcmp((const char *)abyValue,"TradChinese") == 0)
				{
					gSdkLanguageSel = 2;
				}
			}

			dwType = REG_SZ;
			dwSize = MAX_PATH;
			status = RegQueryValueExA(hkey, "SdkPath", NULL, &dwType, abyValue, &dwSize);
			if (ERROR_SUCCESS == status)
			{
				abyValue[MAX_PATH-1] = '\0';
				strcpy(strPath,(const char *)abyValue);
				break;
			}
		}

		MessageBoxA(NULL, "Failed to access registry", "Error", 0);
		return CAMERA_STATUS_FAILED;
	} while(0);

	if (hkey != NULL)
	{
		RegCloseKey(hkey);
		hkey = NULL;
	}

#ifndef _WIN64
	sprintf_s(strDir,sizeof(strDir),"%s%s",strPath,"\\MVCAMSDK.dll");
#else
	sprintf_s(strDir,sizeof(strDir),"%s%s",strPath,"\\MVCAMSDK_X64.dll");
#endif
	ghSDK = ::LoadLibraryA(strDir);


	if (NULL == ghSDK)
	{
		if (gSdkLanguageSel == 1)
		{
			sprintf_s(strPath,sizeof(strPath),"�ļ�[%s]����ʧ�� ,��ȷ�ϸ�·�����ڸ��ļ��������½��а�װ!",strDir);
			MessageBoxA(NULL, strPath, "����", 0); 
		}
		else
		{
			sprintf_s(strPath,sizeof(strPath),"Failed to load file[%s] ,put the file on the directory or re-install the platform and try again!",strDir);
			MessageBoxA(NULL, strPath, "Error", 0);
		} 
		return CAMERA_STATUS_FAILED;
	}
	
#define GET_MVSDK_API(name)			\
	name = (_##name)GetProcAddress(ghSDK, #name);\
	CHECK_API(name)

	GET_MVSDK_API(CameraSdkInit);
	GET_MVSDK_API(CameraSetSysOption);
	GET_MVSDK_API(CameraSetCallbackFunction);
	GET_MVSDK_API(CameraGetInformation);
	GET_MVSDK_API(CameraInit);
	GET_MVSDK_API(CameraInitEx);
	GET_MVSDK_API(CameraInitEx2);
	GET_MVSDK_API(CameraUnInit);
	GET_MVSDK_API(CameraImageProcess);
	GET_MVSDK_API(CameraImageProcessEx);
	GET_MVSDK_API(CameraPlay);
	GET_MVSDK_API(CameraPause);
	GET_MVSDK_API(CameraStop);
	GET_MVSDK_API(CameraDisplayRGB24);
	GET_MVSDK_API(CameraSetDisplayMode);
	GET_MVSDK_API(CameraImageOverlay);
	GET_MVSDK_API(CameraDisplayInit);
	GET_MVSDK_API(CameraDisplayInitEx);
	GET_MVSDK_API(CameraSetDisplaySize);
	GET_MVSDK_API(CameraSetDisplayOffset);
	GET_MVSDK_API(CameraInitRecord);
	GET_MVSDK_API(CameraStopRecord);
	GET_MVSDK_API(CameraPushFrame);
	GET_MVSDK_API(CameraSpecialControl);
	GET_MVSDK_API(CameraSnapToBuffer);
	GET_MVSDK_API(CameraSnapJpegToFile);
	GET_MVSDK_API(CameraGetImageBuffer);
	GET_MVSDK_API(CameraGetImageBufferEx);
	GET_MVSDK_API(CameraReleaseImageBuffer);
	GET_MVSDK_API(CameraCreateSettingPage);
	GET_MVSDK_API(CameraSetActiveSettingSubPage);
	GET_MVSDK_API(CameraSetSettingPageParent);
	GET_MVSDK_API(CameraGetSettingPageHWnd);
	GET_MVSDK_API(CameraUpdateSettingPage);
	GET_MVSDK_API(CameraSetMirror);
	GET_MVSDK_API(CameraGetMirror);
	GET_MVSDK_API(CameraSetHardwareMirror);
	GET_MVSDK_API(CameraGetHardwareMirror);
	GET_MVSDK_API(CameraSetRotate);
	GET_MVSDK_API(CameraGetRotate);
	GET_MVSDK_API(CameraSetMonochrome);
	GET_MVSDK_API(CameraGetMonochrome);
	GET_MVSDK_API(CameraSetInverse);
	GET_MVSDK_API(CameraGetInverse);
	GET_MVSDK_API(CameraCustomizeResolution);
	GET_MVSDK_API(CameraGetImageResolution);
	GET_MVSDK_API(CameraGetImageResolutionEx);
	GET_MVSDK_API(CameraSetImageResolution);
	GET_MVSDK_API(CameraSetImageResolutionEx);
	GET_MVSDK_API(CameraGetMediaType);
	GET_MVSDK_API(CameraSetMediaType);
	GET_MVSDK_API(CameraGetRawMaxAvailBits);
	GET_MVSDK_API(CameraSetRawStartBit);
	GET_MVSDK_API(CameraGetRawStartBit);
	GET_MVSDK_API(CameraSetAeState);
	GET_MVSDK_API(CameraGetAeState);
	GET_MVSDK_API(CameraSetAeTarget);
	GET_MVSDK_API(CameraGetAeTarget);
	GET_MVSDK_API(CameraSetAeExposureRange);
	GET_MVSDK_API(CameraGetAeExposureRange);
	GET_MVSDK_API(CameraSetAeAnalogGainRange);
	GET_MVSDK_API(CameraGetAeAnalogGainRange);
	GET_MVSDK_API(CameraSetAeThreshold);
	GET_MVSDK_API(CameraGetAeThreshold);
	GET_MVSDK_API(CameraIsAeWinVisible);
	GET_MVSDK_API(CameraSetExposureTime);
	GET_MVSDK_API(CameraGetExposureTime);
	GET_MVSDK_API(CameraGetExposureTimeRange);
	GET_MVSDK_API(CameraSetMultiExposureTime);
	GET_MVSDK_API(CameraGetMultiExposureTime);
	GET_MVSDK_API(CameraSetMultiExposureGamma);
	GET_MVSDK_API(CameraGetMultiExposureGamma);
	GET_MVSDK_API(CameraSetMultiExposureCount);
	GET_MVSDK_API(CameraGetMultiExposureCount);
	GET_MVSDK_API(CameraGetMultiExposureMaxCount);
	GET_MVSDK_API(CameraGetMultiExposureSupported);
	GET_MVSDK_API(CameraGetMultiExposureBlendingSupported);
	GET_MVSDK_API(CameraSetMultiExposureBlendingEnable);
	GET_MVSDK_API(CameraGetMultiExposureBlendingEnable);
	GET_MVSDK_API(CameraSetMultiExposureBlendingRatios);
	GET_MVSDK_API(CameraGetMultiExposureBlendingRatios);
	GET_MVSDK_API(CameraGetExposureLineTime);
	GET_MVSDK_API(CameraSetAnalogGain);
	GET_MVSDK_API(CameraGetAnalogGain);
	GET_MVSDK_API(CameraSetAnalogGainX);
	GET_MVSDK_API(CameraGetAnalogGainX);
	GET_MVSDK_API(CameraGetAnalogGainXRange);
	GET_MVSDK_API(CameraSetSharpness);
	GET_MVSDK_API(CameraGetSharpness);
	GET_MVSDK_API(CameraSetOnceWB);
	GET_MVSDK_API(CameraSetLutMode);
	GET_MVSDK_API(CameraGetLutMode);
	GET_MVSDK_API(CameraSelectLutPreset);
	GET_MVSDK_API(CameraGetLutPresetSel);
	GET_MVSDK_API(CameraSetCustomLut);  
	GET_MVSDK_API(CameraGetCustomLut);
	GET_MVSDK_API(CameraGetCurrentLut);
	GET_MVSDK_API(CameraSetWbMode);
	GET_MVSDK_API(CameraGetWbMode);
	GET_MVSDK_API(CameraSetWbWindow);
	GET_MVSDK_API(CameraGetWbWindow);
	GET_MVSDK_API(CameraIsWbWinVisible);
	GET_MVSDK_API(CameraSaveImage);
	GET_MVSDK_API(CameraSetGain);
	GET_MVSDK_API(CameraGetGain);
	GET_MVSDK_API(CameraSetGamma);
	GET_MVSDK_API(CameraGetGamma);
	GET_MVSDK_API(CameraSetSaturation);
	GET_MVSDK_API(CameraGetSaturation);
	GET_MVSDK_API(CameraSetContrast);
	GET_MVSDK_API(CameraGetContrast);
	GET_MVSDK_API(CameraSetFrameSpeed);
	GET_MVSDK_API(CameraGetFrameSpeed);
	GET_MVSDK_API(CameraSetFrameRate);
	GET_MVSDK_API(CameraGetFrameRate);
	GET_MVSDK_API(CameraSetAntiFlick);
	GET_MVSDK_API(CameraGetAntiFlick);
	GET_MVSDK_API(CameraGetLightFrequency);
	GET_MVSDK_API(CameraSetLightFrequency);
	GET_MVSDK_API(CameraSetTransPackLen);
	GET_MVSDK_API(CameraGetTransPackLen);
	GET_MVSDK_API(CameraWriteSN);
	GET_MVSDK_API(CameraReadSN);
	GET_MVSDK_API(CameraGetPresetClrTemp);
	GET_MVSDK_API(CameraSetPresetClrTemp);
	GET_MVSDK_API(CameraSaveParameter);
	GET_MVSDK_API(CameraLoadParameter);
	GET_MVSDK_API(CameraGetCurrentParameterGroup);
	GET_MVSDK_API(CameraEnumerateDevice);
	GET_MVSDK_API(CameraEnumerateDeviceEx);
	GET_MVSDK_API(CameraGetCapability);
	GET_MVSDK_API(CameraSoftTrigger);
	GET_MVSDK_API(CameraSetTriggerMode);
	GET_MVSDK_API(CameraGetTriggerMode);
	GET_MVSDK_API(CameraShowSettingPage);
	GET_MVSDK_API(CameraGetFrameStatistic);
	GET_MVSDK_API(CameraGetResolutionForSnap);
	GET_MVSDK_API(CameraSetResolutionForSnap);
	GET_MVSDK_API(CameraGetNoiseFilterState);
	GET_MVSDK_API(CameraSetParameterMode);
	GET_MVSDK_API(CameraGetParameterMode);
	GET_MVSDK_API(CameraSetParameterMask);
	GET_MVSDK_API(CameraGetTriggerCount);
	GET_MVSDK_API(CameraGetCrossLine);
	GET_MVSDK_API(CameraSetCrossLine);
	GET_MVSDK_API(CameraGetTriggerDelayTime);
	GET_MVSDK_API(CameraSetTriggerDelayTime);
	GET_MVSDK_API(CameraSetAeWinVisible);
	GET_MVSDK_API(CameraSetNoiseFilter);
	GET_MVSDK_API(CameraSetTriggerCount);
	GET_MVSDK_API(CameraCustomizeReferWin);
	GET_MVSDK_API(CameraSetAeWindow);
	GET_MVSDK_API(CameraGetAeWindow);
	GET_MVSDK_API(CameraReadParameterFromFile);
	GET_MVSDK_API(CameraSetWbWinVisible);
	GET_MVSDK_API(CameraRstTimeStamp);
	GET_MVSDK_API(CameraGetCapabilityEx);
	GET_MVSDK_API(CameraLoadUserData);
	GET_MVSDK_API(CameraSaveUserData);
	GET_MVSDK_API(CameraIsOpened);
	GET_MVSDK_API(CameraSetFriendlyName);
	GET_MVSDK_API(CameraGetFriendlyName);
	GET_MVSDK_API(CameraSetUserClrTempGain);
	GET_MVSDK_API(CameraGetUserClrTempGain);
	GET_MVSDK_API(CameraSetUserClrTempMatrix);
	GET_MVSDK_API(CameraGetUserClrTempMatrix);
	GET_MVSDK_API(CameraSetClrTempMode);
	GET_MVSDK_API(CameraGetClrTempMode);
	GET_MVSDK_API(CameraSdkGetVersionString);
	GET_MVSDK_API(CameraCheckFwUpdate);
	GET_MVSDK_API(CameraGetFirmwareVersion);
	GET_MVSDK_API(CameraGetFirmwareVision);
	GET_MVSDK_API(CameraGetEnumInfo);
	GET_MVSDK_API(CameraGetInerfaceVersion);
	GET_MVSDK_API(CameraSetIOState);
	GET_MVSDK_API(CameraSetIOStateEx);
	GET_MVSDK_API(CameraGetOutPutIOState);
	GET_MVSDK_API(CameraGetOutPutIOStateEx);
	GET_MVSDK_API(CameraGetIOState);
	GET_MVSDK_API(CameraGetIOStateEx);
	GET_MVSDK_API(CameraSetInPutIOMode);
	GET_MVSDK_API(CameraGetInPutIOMode);
	GET_MVSDK_API(CameraSetOutPutIOMode);
	GET_MVSDK_API(CameraGetOutPutIOMode);
	GET_MVSDK_API(CameraGetInPutIOModeCapbility);
	GET_MVSDK_API(CameraGetOutPutIOModeCapbility);
	GET_MVSDK_API(CameraSetOutPutPWM);
	GET_MVSDK_API(CameraSetRotaryEncDir);
	GET_MVSDK_API(CameraGetRotaryEncDir);
	GET_MVSDK_API(CameraSetRotaryEncFreq);
	GET_MVSDK_API(CameraGetRotaryEncFreq);
	GET_MVSDK_API(CameraSetInPutIOFormat);
	GET_MVSDK_API(CameraGetInPutIOFormat);
	GET_MVSDK_API(CameraSetOutPutIOFormat);
	GET_MVSDK_API(CameraGetOutPutIOFormat);
	GET_MVSDK_API(CameraGetInPutIOFormatCapbility);
	GET_MVSDK_API(CameraGetOutPutIOFormatCapbility);
	CameraSetBayerDecAlgorithm = (_CameraSetBayerDecAlgorithm)GetProcAddress(ghSDK, 
#ifdef _WIN64
		"CameraSetBayerDecAlgorithm");
#else
		"_CameraSetBayerDecAlgorithm@12");
#endif
	CHECK_API(CameraSetBayerDecAlgorithm);
	GET_MVSDK_API(CameraGetBayerDecAlgorithm);
	GET_MVSDK_API(CameraSetBlackLevel);
	GET_MVSDK_API(CameraGetBlackLevel);
	GET_MVSDK_API(CameraSetWhiteLevel);
	GET_MVSDK_API(CameraGetWhiteLevel);
	GET_MVSDK_API(CameraSetIspOutFormat);
	GET_MVSDK_API(CameraGetIspOutFormat);
	GET_MVSDK_API(CameraSetStrobeMode);
	GET_MVSDK_API(CameraGetStrobeMode);
	GET_MVSDK_API(CameraSetStrobeDelayTime);
	GET_MVSDK_API(CameraGetStrobeDelayTime);
	GET_MVSDK_API(CameraSetStrobePulseWidth);
	GET_MVSDK_API(CameraGetStrobePulseWidth);
	GET_MVSDK_API(CameraSetStrobePolarity);
	GET_MVSDK_API(CameraGetStrobePolarity);
	GET_MVSDK_API(CameraSetExtTrigSignalType);
	GET_MVSDK_API(CameraGetExtTrigSignalType);
	GET_MVSDK_API(CameraSetExtTrigShutterType);
	GET_MVSDK_API(CameraGetExtTrigShutterType);
	GET_MVSDK_API(CameraSetExtTrigDelayTime);
	GET_MVSDK_API(CameraGetExtTrigDelayTime);
	GET_MVSDK_API(CameraSetExtTrigIntervalTime);
	GET_MVSDK_API(CameraGetExtTrigIntervalTime);
	GET_MVSDK_API(CameraSetExtTrigJitterTime);
	GET_MVSDK_API(CameraGetExtTrigJitterTime);
	GET_MVSDK_API(CameraGetExtTrigCapability);
	GET_MVSDK_API(CameraPauseLevelTrigger);
	GET_MVSDK_API(CameraGetErrorString);
	GET_MVSDK_API(CameraGetCapabilityEx2);
	GET_MVSDK_API(CameraGetImageBufferEx2);
	GET_MVSDK_API(CameraGetImageBufferEx3);
	GET_MVSDK_API(CameraReConnect);
	GET_MVSDK_API(CameraConnectTest);
	GET_MVSDK_API(CameraSetLedEnable);
	GET_MVSDK_API(CameraGetLedEnable);
	GET_MVSDK_API(CameraSetLedOnOff);
	GET_MVSDK_API(CameraGetLedOnOff);
	GET_MVSDK_API(CameraSetLedDuration);
	GET_MVSDK_API(CameraGetLedDuration);
	GET_MVSDK_API(CameraSetLedBrightness);
	GET_MVSDK_API(CameraGetLedBrightness);
	GET_MVSDK_API(CameraEnableTransferRoi);
	GET_MVSDK_API(CameraSetTransferRoi);
	GET_MVSDK_API(CameraGetTransferRoi);
	GET_MVSDK_API(CameraAlignMalloc);
	GET_MVSDK_API(CameraAlignFree);
	GET_MVSDK_API(CameraSetAutoConnect);
	GET_MVSDK_API(CameraGetAutoConnect);
	GET_MVSDK_API(CameraGetReConnectCounts);
	GET_MVSDK_API(CameraSetSingleGrabMode);
	GET_MVSDK_API(CameraGetSingleGrabMode);
	GET_MVSDK_API(CameraRestartGrab);
	GET_MVSDK_API(CameraDrawText);
	GET_MVSDK_API(CameraGigeEnumerateDevice);
	GET_MVSDK_API(CameraGigeGetIp);
	GET_MVSDK_API(CameraGigeSetIp);
	GET_MVSDK_API(CameraGigeGetMac);
	GET_MVSDK_API(CameraEnableFastResponse);
	GET_MVSDK_API(CameraSetCorrectDeadPixel);
	GET_MVSDK_API(CameraGetCorrectDeadPixel);
	GET_MVSDK_API(CameraFlatFieldingCorrectSetEnable);
	GET_MVSDK_API(CameraFlatFieldingCorrectGetEnable);
	GET_MVSDK_API(CameraFlatFieldingCorrectSetParameter);
	GET_MVSDK_API(CameraFlatFieldingCorrectSaveParameterToFile);
	GET_MVSDK_API(CameraFlatFieldingCorrectLoadParameterFromFile);
	GET_MVSDK_API(CameraCommonCall);
	GET_MVSDK_API(CameraSetDenoise3DParams);
	GET_MVSDK_API(CameraGetDenoise3DParams);
	GET_MVSDK_API(CameraManualDenoise3D);
	GET_MVSDK_API(CameraCustomizeDeadPixels);
	GET_MVSDK_API(CameraReadDeadPixels);
	GET_MVSDK_API(CameraAddDeadPixels);
	GET_MVSDK_API(CameraRemoveDeadPixels);
	GET_MVSDK_API(CameraRemoveAllDeadPixels);
	GET_MVSDK_API(CameraSaveDeadPixels);
	GET_MVSDK_API(CameraSaveDeadPixelsToFile);
	GET_MVSDK_API(CameraLoadDeadPixelsFromFile);
	GET_MVSDK_API(CameraGetImageBufferPriority);
	GET_MVSDK_API(CameraGetImageBufferPriorityEx);
	GET_MVSDK_API(CameraGetImageBufferPriorityEx2);
	GET_MVSDK_API(CameraGetImageBufferPriorityEx3);
	GET_MVSDK_API(CameraClearBuffer);
	GET_MVSDK_API(CameraSoftTriggerEx);
	GET_MVSDK_API(CameraSetHDR);
	GET_MVSDK_API(CameraGetHDR);
	GET_MVSDK_API(CameraGetFrameID);
	GET_MVSDK_API(CameraGetFrameTimeStamp);
	GET_MVSDK_API(CameraSetHDRGainMode);
	GET_MVSDK_API(CameraGetHDRGainMode);
	GET_MVSDK_API(CameraCreateDIBitmap);
	GET_MVSDK_API(CameraDrawFrameBuffer);
	GET_MVSDK_API(CameraFlipFrameBuffer);
	GET_MVSDK_API(CameraConvertFrameBufferFormat);
	GET_MVSDK_API(CameraSetConnectionStatusCallback);
	GET_MVSDK_API(CameraSetLightingControllerMode);
	GET_MVSDK_API(CameraSetLightingControllerState);
	GET_MVSDK_API(CameraSetFrameResendCount);
	GET_MVSDK_API(CameraGetEyeCount);
	GET_MVSDK_API(CameraMultiEyeImageProcess);
	GET_MVSDK_API(CameraGetRegionAverageGray);
	GET_MVSDK_API(CameraGetMediaCapability);
	GET_MVSDK_API(CameraSetMediaBitRate);
	GET_MVSDK_API(CameraGetMediaBitRate);
	GET_MVSDK_API(CameraSetFrameEventCallback);
	GET_MVSDK_API(CameraSetNoiseReductionValue);
	GET_MVSDK_API(CameraGetNoiseReductionValue);
	GET_MVSDK_API(CameraSetLogarithmicCurveValue);
	GET_MVSDK_API(CameraGetLogarithmicCurveValue);
	GET_MVSDK_API(CameraSetSpliceLines);
	GET_MVSDK_API(CameraGetSpliceLines);
	GET_MVSDK_API(CameraSnapChannelBuffer);
	GET_MVSDK_API(CameraReleaseChannelBuffer);
	GET_MVSDK_API(CameraSetRotaryEncTrigger);
	GET_MVSDK_API(CameraGetRotaryEncTrigger);

	GET_MVSDK_API(CameraGrabber_CreateFromDevicePage);
	GET_MVSDK_API(CameraGrabber_CreateByIndex);
	GET_MVSDK_API(CameraGrabber_CreateByName);
	GET_MVSDK_API(CameraGrabber_Create);
	GET_MVSDK_API(CameraGrabber_Destroy);
	GET_MVSDK_API(CameraGrabber_SetHWnd);
	GET_MVSDK_API(CameraGrabber_SetPriority);
	GET_MVSDK_API(CameraGrabber_StartLive);
	GET_MVSDK_API(CameraGrabber_StopLive);
	GET_MVSDK_API(CameraGrabber_SaveImage);
	GET_MVSDK_API(CameraGrabber_SaveImageAsync);
	GET_MVSDK_API(CameraGrabber_SaveImageAsyncEx);
	GET_MVSDK_API(CameraGrabber_SetSaveImageCompleteCallback);
	GET_MVSDK_API(CameraGrabber_SetFrameListener);
	GET_MVSDK_API(CameraGrabber_SetRawCallback);
	GET_MVSDK_API(CameraGrabber_SetRGBCallback);
	GET_MVSDK_API(CameraGrabber_GetCameraHandle);
	GET_MVSDK_API(CameraGrabber_GetStat);
	GET_MVSDK_API(CameraGrabber_GetCameraDevInfo);

	GET_MVSDK_API(CameraImage_Create);
	GET_MVSDK_API(CameraImage_Destroy);
	GET_MVSDK_API(CameraImage_GetData);
	GET_MVSDK_API(CameraImage_GetUserData);
	GET_MVSDK_API(CameraImage_SetUserData);
	GET_MVSDK_API(CameraImage_IsEmpty);
	GET_MVSDK_API(CameraImage_Draw);
	GET_MVSDK_API(CameraImage_BitBlt);
	GET_MVSDK_API(CameraImage_SaveAsBmp);
	GET_MVSDK_API(CameraImage_SaveAsJpeg);
	GET_MVSDK_API(CameraImage_SaveAsPng);
	GET_MVSDK_API(CameraImage_SaveAsRaw);
	
	GET_MVSDK_API(CameraZoomTool_Create);
	GET_MVSDK_API(CameraZoomTool_Destory);
	GET_MVSDK_API(CameraZoomTool_SetViewOrg);
	GET_MVSDK_API(CameraZoomTool_GetViewOrg);
	GET_MVSDK_API(CameraZoomTool_SetViewCenter);
	GET_MVSDK_API(CameraZoomTool_GetViewCenter);
	GET_MVSDK_API(CameraZoomTool_SetViewSize);
	GET_MVSDK_API(CameraZoomTool_GetViewSize);
	GET_MVSDK_API(CameraZoomTool_SetViewScrollPos);
	GET_MVSDK_API(CameraZoomTool_GetViewScrollPos);
	GET_MVSDK_API(CameraZoomTool_GetViewScrollRange);
	GET_MVSDK_API(CameraZoomTool_SetFrameSize);
	GET_MVSDK_API(CameraZoomTool_GetFrameSize);
	GET_MVSDK_API(CameraZoomTool_SetScale);
	GET_MVSDK_API(CameraZoomTool_GetScale);
	GET_MVSDK_API(CameraZoomTool_SetScaleAnchor);
	GET_MVSDK_API(CameraZoomTool_GetScaleAnchor);
	GET_MVSDK_API(CameraZoomTool_GetDrawRect);
	GET_MVSDK_API(CameraZoomTool_Transform);
	GET_MVSDK_API(CameraZoomTool_Draw);
	GET_MVSDK_API(CameraZoomTool_DrawEx);

#undef GET_MVSDK_API

	return CAMERA_STATUS_SUCCESS;
}

CameraSdkStatus UnloadCameraSdk()
{
	if (ghSDK)
	{
		FreeLibrary(ghSDK); 
	} 
	return CAMERA_STATUS_SUCCESS;
}
#endif

#endif
