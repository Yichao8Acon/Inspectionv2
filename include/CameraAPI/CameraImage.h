#ifndef _MV_CAMERA_IMAGE_H_
#define _MV_CAMERA_IMAGE_H_

#include <OCIdl.h>
#include "CameraDefine.H"
#include "CameraStatus.h"


/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����һ���µ�Image
/// \param [out] Image �´�����ͼƬ
/// \param [in] pFrameBuffer ֡����
/// \param [in] pFrameHead ֡ͷ
/// \param [in] bCopy TRUE: ���Ƴ�һ���µ�֡����   FALSE: �����ƣ�ֱ��ʹ��pFrameBufferָ��Ļ�����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Create a new Image
/// \param [out] Image Newly Created Image
/// \param [in] pFrameBuffer frame data
/// \param [in] pFrameHead Frame Header
/// \param [in] bCopy TRUE: Copy a new frame data FALSE: Do not copy, directly use the buffer pointed to by pFrameBuffer
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_Create(
	void** Image,
	BYTE *pFrameBuffer, 
	tSdkFrameHead* pFrameHead,
	BOOL bCopy
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����һ���յ�Image
/// \param [out] Image �´�����ͼƬ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Create an empty Image
/// \param [out] Image Newly Created Image
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_CreateEmpty(
	void** Image
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����Image
/// \param [in] Image
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Destroy Image
/// \param [in] Image
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_Destroy(
	void* Image
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��Image��ȡ֡���ݺ�֡ͷ
/// \param [in] Image
/// \param [out] DataBuffer ֡����
/// \param [out] Head ֡ͷ
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get frame data and frame header from Image
/// \param [in] Image
/// \param [out] DataBuffer Frame Data
/// \param [out] Head header
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_GetData(
	void* Image,
	BYTE** DataBuffer,
	tSdkFrameHead** Head
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��ȡImage���û��Զ�������
/// \param [in] Image
/// \param [out] UserData �����û��Զ�������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Get User's Custom Data of Image
/// \param [in] Image
/// \param [out] UserData returns user-defined data
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_GetUserData(
	void* Image,
	void** UserData
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����Image���û��Զ�������
/// \param [in] Image
/// \param [in] UserData �û��Զ�������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Set user-defined data for Image
/// \param [in] Image
/// \param [in] UserData User-defined data
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_SetUserData(
	void* Image,
	void* UserData
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief �ж�һ��Image�Ƿ�Ϊ��
/// \param [in] Image
/// \param [out] IsEmpty Ϊ�շ���:TRUE(1)  ���򷵻�:FALSE(0)
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Determine if an Image is empty
/// \param [in] Image
/// \param [out] IsEmpty Empty Returns: TRUE(1) Otherwise returns: FALSE(0)
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_IsEmpty(
	void* Image,
	BOOL* IsEmpty
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����Image��ָ������
/// \param [in] Image
/// \param [in] hWnd Ŀ�Ĵ���
/// \param [in] Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Draw Image to the specified window
/// \param [in] Image
/// \param [in] hWnd destination window
/// \param [in] Algorithm scaling algorithm 0:fast but slightly worse quality  1:slower but better quality
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_Draw(
	void* Image,
	HWND hWnd,
	int Algorithm
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��������Image��ָ������
/// \param [in] Image
/// \param [in] hWnd Ŀ�Ĵ���
/// \param [in] Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Pull up drawing Image to the specified window
/// \param [in] Image
/// \param [in] hWnd destination window
/// \param [in] Algorithm scaling algorithm 0:fast but slightly worse quality  1:slower but better quality
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_DrawFit(
	void* Image,
	HWND hWnd,
	int Algorithm
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����Image��ָ��DC
/// \param [in] Image
/// \param [in] hDC Ŀ��DC
/// \param [in] Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
/// \param [in] xDst Ŀ����ε����Ͻ�X����
/// \param [in] yDst Ŀ����ε����Ͻ�Y����
/// \param [in] cxDst Ŀ����εĿ��
/// \param [in] cyDst Ŀ����εĸ߶�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Draw Image to specified DC
/// \param [in] Image
/// \param [in] hDC destination DC
/// \param [in] Algorithm scaling algorithm 0:fast but slightly worse quality   1:slower but better quality
/// \param [in] xDst The X coordinate of the upper left corner of the target rectangle
/// \param [in] yDst The Y coordinate of the upper left corner of the target rectangle
/// \param [in] cxDst Width of target rectangle
/// \param [in] cyDst Height of target rectangle
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_DrawToDC(
	void* Image,
	HDC hDC,
	int Algorithm,
	int xDst,
	int yDst,
	int cxDst,
	int cyDst
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��������Image��ָ��DC
/// \param [in] Image
/// \param [in] hDC Ŀ��DC
/// \param [in] Algorithm �����㷨  0�����ٵ������Բ�  1���ٶ�����������
/// \param [in] xDst Ŀ����ε����Ͻ�X����
/// \param [in] yDst Ŀ����ε����Ͻ�Y����
/// \param [in] cxDst Ŀ����εĿ��
/// \param [in] cyDst Ŀ����εĸ߶�
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Pull up drawing Image to specified DC
/// \param [in] Image
/// \param [in] hDC destination DC
/// \param [in] Algorithm scaling algorithm 0:fast but slightly worse quality   1:slower but better quality
/// \param [in] xDst The X coordinate of the upper left corner of the target rectangle
/// \param [in] yDst The Y coordinate of the upper left corner of the target rectangle
/// \param [in] cxDst Width of target rectangle
/// \param [in] cyDst Height of target rectangle
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_DrawToDCFit(
	void* Image,
	HDC hDC,
	int Algorithm,
	int xDst,
	int yDst,
	int cxDst,
	int cyDst
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����Image��ָ�����ڣ������ţ�
/// \param [in] Image
/// \param [in] hWnd Ŀ�Ĵ���
/// \param [in] xDst Ŀ����ε����Ͻ�X����
/// \param [in] yDst Ŀ����ε����Ͻ�Y����
/// \param [in] cxDst Ŀ����εĿ��
/// \param [in] cyDst Ŀ����εĸ߶�
/// \param [in] xSrc ͼ����ε����Ͻ�X����
/// \param [in] ySrc ͼ����ε����Ͻ�Y����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Draw Image to specified window (without scaling)
/// \param [in] Image
/// \param [in] hWnd destination window
/// \param [in] xDst The X coordinate of the upper left corner of the target rectangle
/// \param [in] yDst The Y coordinate of the upper left corner of the target rectangle
/// \param [in] cxDst Width of target rectangle
/// \param [in] cyDst Height of target rectangle
/// \param [in] xSrc X coordinate of the upper left corner of the image rectangle
/// \param [in] ySrc Y coordinate of the upper left corner of the image rectangle
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_BitBlt(
	void* Image,
	HWND hWnd,
	int xDst,
	int yDst,
	int cxDst,
	int cyDst,
	int xSrc,
	int ySrc
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ����Image��ָ��DC�������ţ�
/// \param [in] Image
/// \param [in] hDC Ŀ��DC
/// \param [in] xDst Ŀ����ε����Ͻ�X����
/// \param [in] yDst Ŀ����ε����Ͻ�Y����
/// \param [in] cxDst Ŀ����εĿ��
/// \param [in] cyDst Ŀ����εĸ߶�
/// \param [in] xSrc ͼ����ε����Ͻ�X����
/// \param [in] ySrc ͼ����ε����Ͻ�Y����
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Draw Image to specified DC (without scaling)
/// \param [in] Image
/// \param [in] hDC destination DC
/// \param [in] xDst The X coordinate of the upper left corner of the target rectangle
/// \param [in] yDst The Y coordinate of the upper left corner of the target rectangle
/// \param [in] cxDst Width of target rectangle
/// \param [in] cyDst Height of target rectangle
/// \param [in] xSrc X coordinate of the upper left corner of the image rectangle
/// \param [in] ySrc Y coordinate of the upper left corner of the image rectangle
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_BitBltToDC(
	void* Image,
	HDC hDC,
	int xDst,
	int yDst,
	int cxDst,
	int cyDst,
	int xSrc,
	int ySrc
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��bmp��ʽ����Image
/// \param [in] Image
/// \param [in] FileName �ļ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Save Image as bmp
/// \param [in] Image
/// \param [in] FileName file name
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_SaveAsBmp(
	void* Image,
	char const* FileName
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��jpg��ʽ����Image
/// \param [in] Image
/// \param [in] FileName �ļ���
/// \param [in] Quality ��������(1-100)��100Ϊ������ѵ��ļ�Ҳ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Save Image as jpg
/// \param [in] Image
/// \param [in] FileName file name
/// \param [in] Quality save quality (1-100), 100 is the best quality but the file is also the largest
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_SaveAsJpeg(
	void* Image,
	char const* FileName,
	BYTE  Quality
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��png��ʽ����Image
/// \param [in] Image
/// \param [in] FileName �ļ���
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Save Image as png
/// \param [in] Image
/// \param [in] FileName file name
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_SaveAsPng(
	void* Image,
	char const* FileName
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��raw��ʽ����Image
/// \param [in] Image
/// \param [in] FileName �ļ���
/// \param [in] Format 0: 8Bit Raw     1: 16Bit Raw
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Save Image as raw
/// \param [in] Image
/// \param [in] FileName file name
/// \param [in] Format 0: 8Bit Raw     1: 16Bit Raw
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_SaveAsRaw(
	void* Image,
	char const* FileName,
	int Format
	);

/// @ingroup MV_IMAGE
/// \~chinese
/// \brief ��Image����һ��IPicture
/// \param [in] Image
/// \param [out] NewPic �´�����IPicture
/// \return �ɹ����� CAMERA_STATUS_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� CameraStatus.h �д�����Ķ��塣
/// \~english
/// \brief Create an IPicture from an Image
/// \param [in] Image
/// \param [out] NewPic Newly created IPicture
/// \return Returns CAMERA_STATUS_SUCCESS(0) successfully. Otherwise, it returns a non-zero error code. Please refer to the definition of the error code in CameraStatus.h.
MVSDK_API CameraSdkStatus __stdcall CameraImage_IPicture(
	void* Image,
	IPicture** NewPic
	);




#endif // _MV_CAMERA_IMAGE_H_
