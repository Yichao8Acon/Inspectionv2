﻿#ifndef __CAMERA_STATUS_DEF__
#define __CAMERA_STATUS_DEF__

/// @ingroup MV_TYPEDEF
/// \~chinese SDK
/// \~english SDK error code
typedef int CameraSdkStatus;



#define SDK_SUCCESS(_FUC_)              (_FUC_ == CAMERA_STATUS_SUCCESS)

#define SDK_UNSUCCESS(_FUC_)            (_FUC_ != CAMERA_STATUS_SUCCESS)

#define SDK_UNSUCCESS_RETURN(_FUC_,RET) if((RET = _FUC_) != CAMERA_STATUS_SUCCESS)\
                                        {\
                                            return RET;\
                                        }

#define SDK_UNSUCCESS_BREAK(_FUC_)      if(_FUC_ != CAMERA_STATUS_SUCCESS)\
                                        {\
                                            break;\
                                        }


/// @ingroup MV_MACRO_TYPE 
/// @{
/* ³£ÓÃ´íÎó  */

#define CAMERA_STATUS_SUCCESS                    0   ///< \~chinese  \~english Successful
#define CAMERA_STATUS_FAILED                    -1   ///< \~chinese  \~english operation failed
#define CAMERA_STATUS_INTERNAL_ERROR            -2   ///< \~chinese  \~english internal error
#define CAMERA_STATUS_UNKNOW                    -3   ///< \~chinese  \~english unknown error
#define CAMERA_STATUS_NOT_SUPPORTED             -4   ///< \~chinese  \~english Does not support this feature
#define CAMERA_STATUS_NOT_INITIALIZED           -5   ///< \~chinese  \~english Incomplete initialization
#define CAMERA_STATUS_PARAMETER_INVALID         -6   ///< \~chinese  \~english Invalid argument
#define CAMERA_STATUS_PARAMETER_OUT_OF_BOUND    -7   ///< \~chinese  \~english Out of bounds of parameters
#define CAMERA_STATUS_UNENABLED                 -8   ///< \~chinese  \~english Not enabled
#define CAMERA_STATUS_USER_CANCEL               -9   ///< \~chinese  \~english The user manually canceled, such as roi panel click cancel, return
#define CAMERA_STATUS_PATH_NOT_FOUND            -10  ///< \~chinese  \~english The corresponding path was not found in the registry
#define CAMERA_STATUS_SIZE_DISMATCH             -11  ///< \~chinese  \~english The length of the obtained image data does not match the defined size
#define CAMERA_STATUS_TIME_OUT                  -12  ///< \~chinese  \~english Timeout error
#define CAMERA_STATUS_IO_ERROR                  -13  ///< \~chinese  \~english Hardware IO error
#define CAMERA_STATUS_COMM_ERROR                -14  ///< \~chinese  \~english Communication error
#define CAMERA_STATUS_BUS_ERROR                 -15  ///< \~chinese  \~english Bus error
#define CAMERA_STATUS_NO_DEVICE_FOUND           -16  ///< \~chinese  \~english No device found
#define CAMERA_STATUS_NO_LOGIC_DEVICE_FOUND     -17  ///< \~chinese  \~english Logical device not found
#define CAMERA_STATUS_DEVICE_IS_OPENED          -18  ///< \~chinese  \~english The device is already open
#define CAMERA_STATUS_DEVICE_IS_CLOSED          -19  ///< \~chinese  \~english Device is off
#define CAMERA_STATUS_DEVICE_VEDIO_CLOSED       -20  ///< \~chinese  \~english Without opening the device video, when the video-related function is called, if the camera video is not open, the error is returned back.
#define CAMERA_STATUS_NO_MEMORY                 -21  ///< \~chinese  \~english Not enough system memory
#define CAMERA_STATUS_FILE_CREATE_FAILED        -22  ///< \~chinese  \~english Failed to create file
#define CAMERA_STATUS_FILE_INVALID              -23  ///< \~chinese  \~english Invalid file format
#define CAMERA_STATUS_WRITE_PROTECTED           -24  ///< \~chinese  \~english Write protection, not write
#define CAMERA_STATUS_GRAB_FAILED               -25  ///< \~chinese  \~english Data collection failed
#define CAMERA_STATUS_LOST_DATA                 -26  ///< \~chinese  \~english Loss of data, incomplete
#define CAMERA_STATUS_EOF_ERROR                 -27  ///< \~chinese  \~english No frame terminator received
#define CAMERA_STATUS_BUSY                      -28  ///< \~chinese  \~english Busy (last operation is still in progress), this operation cannot be performed
#define CAMERA_STATUS_WAIT                      -29  ///< \~chinese  \~english Need to wait (condition of operation is not established), can try again
#define CAMERA_STATUS_IN_PROCESS                -30  ///< \~chinese  \~english Ongoing, has been operated
#define CAMERA_STATUS_IIC_ERROR                 -31  ///< \~chinese  \~english IIC transmission error
#define CAMERA_STATUS_SPI_ERROR                 -32  ///< \~chinese  \~english SPI transmission error
#define CAMERA_STATUS_USB_CONTROL_ERROR         -33  ///< \~chinese  \~english USB control transmission error
#define CAMERA_STATUS_USB_BULK_ERROR            -34  ///< \~chinese  \~english USB BULK transmission error
#define CAMERA_STATUS_SOCKET_INIT_ERROR         -35  ///< \~chinese  \~english Network Transport Suite Initialization Failed
#define CAMERA_STATUS_GIGE_FILTER_INIT_ERROR    -36  ///< \~chinese  \~english The webcam kernel filter driver failed to initialize. Please check if the driver is installed correctly or reinstall it.
#define CAMERA_STATUS_NET_SEND_ERROR            -37  ///< \~chinese  \~english Network data sending error
#define CAMERA_STATUS_DEVICE_LOST               -38  ///< \~chinese  \~english Lost connection with webcam, heartbeat timeout
#define CAMERA_STATUS_DATA_RECV_LESS            -39  ///< \~chinese  \~english Received fewer bytes than requested
#define CAMERA_STATUS_FUNCTION_LOAD_FAILED      -40  ///< \~chinese  \~english Failed to load program from file
#define CAMERA_STATUS_CRITICAL_FILE_LOST        -41  ///< \~chinese  \~english The file necessary to run the program is missing.
#define CAMERA_STATUS_SENSOR_ID_DISMATCH        -42  ///< \~chinese  \~english The firmware and program do not match because the wrong firmware was downloaded.
#define CAMERA_STATUS_OUT_OF_RANGE              -43  ///< \~chinese  \~english The parameter is out of valid range.
#define CAMERA_STATUS_REGISTRY_ERROR            -44  ///< \~chinese  \~english Setup registration error. Please reinstall the program, or run the installation directory Setup/Installer.exe
#define CAMERA_STATUS_ACCESS_DENY               -45  ///< \~chinese  \~english No Access. When the specified camera has been occupied by another program, it will return to this state if you request to access the camera. (A camera cannot be accessed simultaneously by multiple programs)
#define CAMERA_STATUS_CAMERA_NEED_RESET         -46  ///< \~chinese  \~english It means that the camera needs to be reset before it can be used normally. At this time, please make the camera power off and restart, or restart the operating system, then it can be used normally.
#define CAMERA_STATUS_ISP_MOUDLE_NOT_INITIALIZED -47 ///< \~chinese  \~english ISP module is not initialized
#define CAMERA_STATUS_ISP_DATA_CRC_ERROR        -48  ///< \~chinese  \~english Data check error
#define CAMERA_STATUS_MV_TEST_FAILED            -49  ///< \~chinese  \~english Data test failed
#define CAMERA_STATUS_INTERNAL_ERR1             -50	 ///< \~chinese  \~english Internal error 1
#define CAMERA_STATUS_U3V_NO_CONTROL_EP			-51	 ///< \~chinese U3V \~english U3V control endpoint not found
#define CAMERA_STATUS_U3V_CONTROL_ERROR			-52	 ///< \~chinese U3V \~english U3V control communication error
#define CAMERA_STATUS_INVALID_FRIENDLY_NAME		-53	 ///< \~chinese  \~english Invalid device name, the name cannot contain the following characters (\/:*?"<>|")
#define CAMERA_STATUS_FORMAT_ERROR				-54	 ///< \~chinese  \~english Format error
#define CAMERA_STATUS_PCIE_OPEN_ERROR			-55  ///< \~chinese PCIE \~english PCIE device open failed
#define CAMERA_STATUS_PCIE_COMM_ERROR			-56  ///< \~chinese PCIE \~english PCIE device communication failed
#define CAMERA_STATUS_PCIE_DDR_ERROR			-57  ///< \~chinese PCIE DDR\~english PCIE DDR error
#define CAMERA_STATUS_IP_ERROR					-58  ///< \~chinese IP \~english IP error


/**
 * CameraLink Acquisition Device
 */
#define CAMERA_STATUS_CL_GRABBER_NOT_FOUND              -100  ///< \~chinese  \~english The specified frame grabber not found
#define CAMERA_STATUS_CL_GRABBER_NOT_ACCESSIBLE         -101  ///< \~chinese  \~english The specified frame grabber is busy
#define CAMERA_STATUS_CL_GRABBER_RES_NOT_FOUND          -102  ///< \~chinese  \~english The resource on the firmware of the frame grabber not found
#define CAMERA_STATUS_CL_GRABBER_RES_NOT_AVAILABLE      -103  ///< \~chinese  \~english Device resource is not available for the frame grabber
#define CAMERA_STATUS_CL_GRABBER_NOT_VALID              -104  ///< \~chinese  \~english Specified parameter is invalid for current device resource
#define CAMERA_STATUS_CL_GRABBER_PRM_ILLEGAL            -105  ///< \~chinese  \~english The setting value for parameter is an illegal value or this frame grabber not supported
#define CAMERA_STATUS_CL_GRABBER_SERIAL_OPEN_FAILED     -106  ///< \~chinese  \~english The serial port open failed
#define CAMERA_STATUS_CL_GRABBER_NOT_START_ACQ          -107  ///< \~chinese  \~english The specified frame grabber doesn't received a start acquisition signal.
#define CAMERA_STATUS_CL_GRABBER_NOT_SUPPORTED_FEATURE  -108  ///< \~chinese  \~english The frame grabber not supported this feature.
#define CAMERA_STATUS_CL_GRABBER_UNKNOWN_ERROR          -199  ///< \~chinese  \~english Unknown error occurred in frame grabber


//ºÍAIAÖÆ¶¨µÄ±ê×¼ÏàÍ¬
/*#define CAMERA_AIA_SUCCESS                        0x0000 */
#define CAMERA_AIA_PACKET_RESEND                          0x0100 ///< \~chinese \~english The frame needs to be retransmitted
#define CAMERA_AIA_NOT_IMPLEMENTED                        0x8001 ///< \~chinese \~english Device does not support commands
#define CAMERA_AIA_INVALID_PARAMETER                      0x8002 ///< \~chinese \~english Illegal command parameters
#define CAMERA_AIA_INVALID_ADDRESS                        0x8003 ///< \~chinese \~english Inaccessible address
#define CAMERA_AIA_WRITE_PROTECT                          0x8004 ///< \~chinese \~english The accessed object cannot be written
#define CAMERA_AIA_BAD_ALIGNMENT                          0x8005 ///< \~chinese \~english Visited address is not aligned as required
#define CAMERA_AIA_ACCESS_DENIED                          0x8006 ///< \~chinese \~english No access
#define CAMERA_AIA_BUSY                                   0x8007 ///< \~chinese \~english Command is processing
#define CAMERA_AIA_DEPRECATED                             0x8008 ///< \~chinese 0x8008-0x0800B  0x800F\~english 0x8008-0x0800B 0x800F This instruction has been deprecated
#define CAMERA_AIA_PACKET_UNAVAILABLE                     0x800C ///< \~chinese  \~english Invalid package
#define CAMERA_AIA_DATA_OVERRUN                           0x800D ///< \~chinese \~english Data overflow, usually more data than needed
#define CAMERA_AIA_INVALID_HEADER                         0x800E ///< \~chinese \~english Some areas in the packet header do not match the protocol
#define CAMERA_AIA_PACKET_NOT_YET_AVAILABLE               0x8010 ///< \~chinese \~english Image packet data is not ready yet. It is mostly used in trigger mode. Application access timeout
#define CAMERA_AIA_PACKET_AND_PREV_REMOVED_FROM_MEMORY    0x8011 ///< \~chinese \~english Subcontracts that require access no longer exist. Mostly used for data retransmission is not in the buffer
#define CAMERA_AIA_PACKET_REMOVED_FROM_MEMORY             0x8012 ///< \~chinese CAMERA_AIA_PACKET_AND_PREV_REMOVED_FROM_MEMORY \~english CAMERA_AIA_PACKET_AND_PREV_REMOVED_FROM_MEMORY
#define CAMERA_AIA_NO_REF_TIME                            0x0813 ///< \~chinese \~english There is no reference clock source. When used for time synchronization commands
#define CAMERA_AIA_PACKET_TEMPORARILY_UNAVAILABLE         0x0814 ///< \~chinese \~english Due to channel bandwidth issues, the current subcontracting is temporarily unavailable and needs to be accessed later
#define CAMERA_AIA_OVERFLOW                               0x0815 ///< \~chinese \~english Data overflow on the device, usually the queue is full
#define CAMERA_AIA_ACTION_LATE                            0x0816 ///< \~chinese \~english Command execution has exceeded valid specified time
#define CAMERA_AIA_ERROR                                  0x8FFF ///< \~chinese  \~english error

// ×Ô¶¨Òå
#define CAMERA_MV_SSR_COMM_ERROR					      0xF000 ///< \~chinese  \~english SSR communication error
#define CAMERA_MV_SSR_TRAIN_ERROR					      0xF001 ///< \~chinese SSRÑµÁ·´íÎó \~english SSR training error

/// @} end of MV_MACRO_TYPE

                                        

#endif
