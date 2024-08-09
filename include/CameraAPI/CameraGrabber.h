#ifndef _MV_CAMERA_GRABBER_H_
#define _MV_CAMERA_GRABBER_H_

#include "CameraDefine.H"
#include "CameraStatus.h"


/// @ingroup GRABBER_CREATE
/// \~chinese
/// \brief ��������б����û�ѡ��Ҫ�򿪵����
/// \param [out] Grabber �����´����Ĳɼ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \note �������ڲ�ʹ���� @link CameraInit @endlink ���������˿���ʹ�� @link CameraGrabber_GetCameraHandle @endlink ��ȡ������������ʹ������SDK API�����������
/// \~english
/// \brief Pop-up camera list allows the user to select the camera to open
/// \param [out] Grabber returns newly created grabber
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \note This function uses @link CameraInit @endlink internally to open the camera, so you can use @link CameraGrabber_GetCameraHandle @endlink to get the camera handle and use other SDK APIs to operate the camera.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_CreateFromDevicePage(
	void** Grabber
	);

/// @ingroup GRABBER_CREATE
/// \~chinese
/// \brief ʹ������б���������Grabber
/// \param [out] Grabber �����´����Ĳɼ���
/// \param [in] Index �������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \note �������ڲ�ʹ���� @link CameraInit @endlink ���������˿���ʹ�� @link CameraGrabber_GetCameraHandle @endlink ��ȡ������������ʹ������SDK API�����������
/// \~english
/// \brief Creating a Grabber Using a Camera List Index
/// \param [out] Grabber returns newly created grabber
/// \param [in] Index Camera index
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \note This function uses @link CameraInit @endlink internally to open the camera, so you can use @link CameraGrabber_GetCameraHandle @endlink to get the camera handle and use other SDK APIs to operate the camera.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_CreateByIndex(
	void** Grabber,
	int Index
	);

/// @ingroup GRABBER_CREATE
/// \~chinese
/// \brief ʹ��������ƴ���Grabber
/// \param [out] Grabber �����´����Ĳɼ���
/// \param [in] Name ������ơ�@link #tSdkCameraDevInfo.acFriendlyName @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \note �������ڲ�ʹ���� @link CameraInit @endlink ���������˿���ʹ�� @link CameraGrabber_GetCameraHandle @endlink ��ȡ������������ʹ������SDK API�����������
/// \~english
/// \brief Create a Grabber with a Camera Name
/// \param [out] Grabber returns newly created grabber
/// \param [in] Name Camera name.@link #tSdkCameraDevInfo.acFriendlyName @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \note This function uses @link CameraInit @endlink internally to open the camera, so you can use @link CameraGrabber_GetCameraHandle @endlink to get the camera handle and use other SDK APIs to operate the camera.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_CreateByName(
	void** Grabber,
	char* Name
	);

/// @ingroup GRABBER_CREATE
/// \~chinese
/// \brief ���豸��Ϣ����Grabber
/// \param [out] Grabber �����´����Ĳɼ���
/// \param [in] pDevInfo �豸��Ϣ��@link #CameraEnumerateDevice @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \note �������ڲ�ʹ���� @link CameraInit @endlink ���������˿���ʹ�� @link CameraGrabber_GetCameraHandle @endlink ��ȡ������������ʹ������SDK API�����������
/// \~english
/// \brief Create Grabber from device info
/// \param [out] Grabber returns newly created grabber
/// \param [in] pDevInfo device information. @link #CameraEnumerateDevice @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \note This function uses @link CameraInit @endlink internally to open the camera, so you can use @link CameraGrabber_GetCameraHandle @endlink to get the camera handle and use other SDK APIs to operate the camera.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_Create(
	void** Grabber,
	tSdkCameraDevInfo* pDevInfo
	);

/// @ingroup GRABBER_DESTROY
/// \~chinese
/// \brief ����Grabber
/// \param [in] Grabber �ɼ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Destroy Grabber
/// \param [in] Grabber
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_Destroy(
	void* Grabber
	);

/// @ingroup GRABBER_CTRL
/// \~chinese
/// \brief ����Ԥ����Ƶ����ʾ����
/// \param [in] Grabber �ɼ���
/// \param [in] hWnd ��ʾ���ڵĴ��ھ��
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set the preview video display window
/// \param [in] Grabber
/// \param [in] hWnd window handle of the display window
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SetHWnd(
	void* Grabber,
	HWND hWnd
	);

/// @ingroup GRABBER_CTRL
/// \~chinese
/// \brief ����Grabberȡͼʱʹ�õ����ȼ�
/// \param [in] Grabber �ɼ���
/// \param [in] Priority ȡͼ���ȼ� �����@link #emCameraGetImagePriority @endlink
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Sets the priority used by Grabber when fetching graphs
/// \param [in] Grabber
/// \param [in] Priority GetImageBuffer priority, For details see: @link #emCameraGetImagePriority @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SetPriority(
	void* Grabber,
	UINT Priority
	);

/// @ingroup GRABBER_CTRL
/// \~chinese
/// \brief ��ʼ�ɼ�
/// \param [in] Grabber �ɼ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \note Grabber�������ɼ�״̬���ɼ��ص���ץͼ�ȹ��ܲ�����������
/// \~english
/// \brief Start Grabber
/// \param [in] Grabber
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \note Grabber must enter the acquisition state, grab callbacks, snapshot and other functions in order to function properly
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_StartLive(
	void* Grabber
	);

/// @ingroup GRABBER_CTRL
/// \~chinese
/// \brief ֹͣ�ɼ�
/// \param [in] Grabber �ɼ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \warning �������ڲ���ȴ����лص�����������ŷ��ص�����,�����ڵȴ�ʱ���ɷ�windows��Ϣ��
/// \~english
/// \brief Stop Grabber
/// \param [in] Grabber
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \warning This function will wait for all callbacks to end before returning to the caller,And it will dispatch windows messages while waiting.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_StopLive(
	void* Grabber
	);

/// @ingroup GRABBER_SNAPSHOT
/// \~chinese
/// \brief ͬ��ץͼ
/// \param [in] Grabber �ɼ���
/// \param [out] Image ����ץȡ����ͼ�� \note ��Ҫ����@link #CameraImage_Destroy @endlink�ͷ�
/// \param [in] TimeOut ��ʱʱ�䣨���룩
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Synchronized snapshot
/// \param [in] Grabber
/// \param [out] Image Returns Captured Image \note Need to Call @link #CameraImage_Destroy @endlink Release
/// \param [in] TimeOut Timeout (milliseconds)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SaveImage(
	void* Grabber,
	void** Image,
	DWORD TimeOut
	);

/// @ingroup GRABBER_SNAPSHOT
/// \~chinese
/// \brief �ύһ���첽��ץͼ�����ύ�ɹ����ץͼ��ɻ�ص��û����õ���ɺ���
/// \param [in] Grabber �ɼ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \see CameraGrabber_SetSaveImageCompleteCallback
/// \~english
/// \brief Submit an asynchronous snapshot request, complete the user's completion function after the completion of the submission.
/// \param [in] Grabber
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \see CameraGrabber_SetSaveImageCompleteCallback
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SaveImageAsync(
	void* Grabber
	);

/// @ingroup GRABBER_SNAPSHOT
/// \~chinese
/// \brief �ύһ���첽��ץͼ�����ύ�ɹ����ץͼ��ɻ�ص��û����õ���ɺ���
/// \param [in] Grabber �ɼ���
/// \param [in] UserData �û����ݣ���ʹ�� @link CameraImage_GetUserData @endlink ��Image��ȡ��ֵ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \see CameraGrabber_SetSaveImageCompleteCallback
/// \~english
/// \brief Submit an asynchronous snapshot request, complete the user's completion function after the completion of the submission.
/// \param [in] Grabber
/// \param [in] UserData user data, which can be obtained from Image using @link CameraImage_GetUserData @endlink
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \see CameraGrabber_SetSaveImageCompleteCallback
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SaveImageAsyncEx(
	void* Grabber,
	void* UserData
	);

/// @ingroup GRABBER_SNAPSHOT
/// \~chinese
/// \brief �����첽��ʽץͼ����ɺ���
/// \param [in] Grabber �ɼ���
/// \param [in] Callback ���첽ץͼ�������ʱ������
/// \param [in] Context ��Callback������ʱ����Ϊ��������Callback
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \see CameraGrabber_SaveImageAsync CameraGrabber_SaveImageAsyncEx
/// \~english
/// \brief Set the completion function of asynchronous mode snapshot
/// \param [in] Grabber
/// \param [in] Callback Callback is called when the asynchronous snapshot task completes
/// \param [in] Context Passed as a parameter when the Callback is invoked
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
/// \see CameraGrabber_SaveImageAsync CameraGrabber_SaveImageAsyncEx
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SetSaveImageCompleteCallback(
	void* Grabber,
	pfnCameraGrabberSaveImageComplete Callback,
	void* Context
	);

/// @ingroup GRABBER_CB
/// \~chinese
/// \brief ����֡��������
/// \param [in] Grabber �ɼ���
/// \param [in] Listener ��������
/// \param [in] Context ��Listener������ʱ����Ϊ��������Listener
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set frame listening function
/// \param [in] Grabber
/// \param [in] Listener listener function
/// \param [in] Context Passed as a parameter when the Listener is invoked
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SetFrameListener(
	void* Grabber,
	pfnCameraGrabberFrameListener Listener,
	void* Context
	);

/// @ingroup GRABBER_CB
/// \~chinese
/// \brief ����RAW���ݻص�����
/// \param [in] Grabber �ɼ���
/// \param [in] Callback Raw�ص�����
/// \param [in] Context ��Callback������ʱ����Ϊ��������Callback
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set RAW data callback function
/// \param [in] Grabber
/// \param [in] Callback Raw data callback function
/// \param [in] Context Passed as a parameter when the Callback is invoked
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SetRawCallback(
	void* Grabber,
	pfnCameraGrabberFrameCallback Callback,
	void* Context
	);

/// @ingroup GRABBER_CB
/// \~chinese
/// \brief ����RGB�ص�����
/// \param [in] Grabber �ɼ���
/// \param [in] Callback RGB�ص�����
/// \param [in] Context ��Callback������ʱ����Ϊ��������Callback
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set RGB callback function
/// \param [in] Grabber
/// \param [in] Callback RGB data callback function
/// \param [in] Context Passed as a parameter when the Callback is invoked
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_SetRGBCallback(
	void* Grabber,
	pfnCameraGrabberFrameCallback Callback,
	void* Context
	);

/// @ingroup GRABBER_CTRL
/// \~chinese
/// \brief ��ȡ������
/// \param [in] Grabber �ɼ���
/// \param [out] hCamera ���ص�������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get camera handle
/// \param [in] Grabber
/// \param [out] hCamera returned camera handle
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_GetCameraHandle(
	void* Grabber,
	CameraHandle *hCamera
	);

/// @ingroup GRABBER_CTRL
/// \~chinese
/// \brief ��ȡ֡ͳ����Ϣ
/// \param [in] Grabber �ɼ���
/// \param [out] stat ���ص�ͳ����Ϣ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get frame statistics
/// \param [in] Grabber
/// \param [out] stat returned statistics
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_GetStat(
	void* Grabber,
	tSdkGrabberStat *stat
	);

/// @ingroup GRABBER_CTRL
/// \~chinese
/// \brief ��ȡ���DevInfo
/// \param [in] Grabber �ɼ���
/// \param [out] DevInfo ���ص����DevInfo
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get Camera DevInfo
/// \param [in] Grabber
/// \param [out] DevInfo Returns Camera DevInfo
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraGrabber_GetCameraDevInfo(
	void* Grabber,
	tSdkCameraDevInfo *DevInfo
	);




#endif // _MV_CAMERA_GRABBER_H_
