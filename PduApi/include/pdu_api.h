#ifndef PDU_API_H
#define PDU_API_H

#ifdef VLD
  #include "vld.h"
#endif

typedef char           CHAR8;
typedef unsigned char  UNUM8;
typedef signed char    SNUM8;
typedef unsigned short UNUM16;
typedef signed short   SNUM16;
typedef unsigned long  UNUM32;
typedef signed long    SNUM32;
namespace native_api {
  ///////////////////////////////////////////////////////////////////////////////
  // 9.4.22 EventCallback prototype
  ///////////////////////////////////////////////////////////////////////////////

  typedef void(*CALLBACKFNC)(UNUM32 eventType, UNUM32 hMod, UNUM32 hCll, void* pCllTag, void* pAPITag);

  /******************************************************************************
  * CONSTANTS*
  *******************************************************************************/


  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.9 Reserved ID and handle values
  ///////////////////////////////////////////////////////////////////////////////

  const UNUM32 PDU_ID_UNDEF = 0xFFFFFFFE;
  const UNUM32 PDU_HANDLE_ASYNC = 0xFFFFFFFE;
  const UNUM32 PDU_HANDLE_UNDEF = 0xFFFFFFFF;



  /******************************************************************************
  * ENUMERATIONS																  *
  *******************************************************************************/


  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.1 D-PDU API item type values
  ///////////////////////////////////////////////////////////////////////////////

  enum T_PDU_IT
  {
    PDU_IT_IO_UNUM32 = 0x1000,  // IOCTL UNUM32 item
    PDU_IT_IO_PROG_VOLTAGE = 0x1001,  // IOCTL Program Voltage item.  
    PDU_IT_IO_BYTEARRAY = 0x1002,  // IOCTL Byte Array item.  
    PDU_IT_IO_FILTER = 0x1003,  // IOCTL Filter item.  
    PDU_IT_IO_EVENT_QUEUE_PROPERTY = 0x1004,  // IOCTL Event Queue Property item.  
    PDU_IT_RSC_STATUS = 0x1100,  // Resource Status item  
    PDU_IT_PARAM = 0x1200,  // ComParam item  
    PDU_IT_RESULT = 0x1300,  // Result item  
    PDU_IT_STATUS = 0x1301,  // Status notification item  
    PDU_IT_ERROR = 0x1302,  // Error notification item  
    PDU_IT_INFO = 0x1303,  // Information notification item  
    PDU_IT_RSC_ID = 0x1400,  // Resource ID item  
    PDU_IT_RSC_CONFLICT = 0x1500,  // Resource Conflict Item  
    PDU_IT_MODULE_ID = 0x1600,  // Module ID item  
    PDU_IT_UNIQUE_RESP_ID_TABLE = 0x1700,  // Unique Response Id Table Item 
    PDU_IT_IO_VEHICLE_ID_REQUEST = 0x1800,  // IOCTL DoIP Vehicle ID request item
    PDU_IT_IO_ETH_SWITCH_STATE = 0x1801,  // DoIP ethernet activation item
    PDU_IT_IO_ENTITY_ADDRESS = 0x1802,  // Volkswagen spezifische Ergänzungen der ISO 13400 Querschnittslastenheft LAH DUM 907 AQ
    PDU_IT_IO_ENTITY_STATUS = 0x1803,  // Volkswagen spezifische Ergänzungen der ISO 13400 Querschnittslastenheft LAH DUM 907 AQ
    // In2Soft specific item type values
    PDU_I2S_IT_UNUM8_ARY = 0x2000,
    PDU_I2S_IT_UNUM32_ARY = 0x2001,
    PDU_I2S_IT_CHAR8_ARY = 0x2002,
    PDU_I2S_IT_IO_PROG_VOLTAGE_DATA = 0x2003,
    PDU_I2S_IT_IO_BYTEARRAY_DATA = 0x2004,
    PDU_I2S_IT_IO_FILTER_LIST = 0x2005,
    PDU_I2S_IT_IO_FILTER_LIST_DATA = 0x2006,
    PDU_I2S_IT_RSC_STATUS_DATA = 0x2007,
    PDU_I2S_IT_FLAG = 0x2008,	// PDU_FLAG_DATA
    PDU_I2S_IT_EXTRA_INFO = 0x2009,
    PDU_I2S_IT_RSC_ID_ITEM_DATA = 0x200A,
    PDU_I2S_IT_RSC_CONFLICT_DATA = 0x200B,
    PDU_I2S_IT_MODULE_DATA = 0x200C,	// PDU_MODULE_DATA
    PDU_I2S_IT_COP_CTRL = 0x200D,
    PDU_I2S_IT_EXP_RESP_DATA = 0x200E,
    PDU_I2S_IT_RSC_DATA = 0x200F,	// PDU_RSC_DATA
    PDU_I2S_IT_PIN_DATA = 0x2010,
    PDU_I2S_IT_RESOURCE_TABLE_ENTRY = 0x2011,	// PDU_RESOURCE_TABLE_ENTRY
    PDU_I2S_IT_ECU_UNIQUE_RESP_DATA = 0x2012,	// PDU_ECU_UNIQUE_RESP_DATA
    PDU_I2S_IT_IO_UNUM32_DATA = 0x2013,	// PDU_IO_UNUM32_DATA
    PDU_I2S_IT_IP_ADDR_INFO = 0x2014	// PDU_IP_ADDR_INFO
  } ;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.2 ComPrimitive type values
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_COPT
  {
    PDU_COPT_STARTCOMM = 0x8001,
    PDU_COPT_STOPCOMM = 0x8002,
    PDU_COPT_UPDATEPARAM = 0x8003,
    PDU_COPT_SENDRECV = 0x8004,
    PDU_COPT_DELAY = 0x8005,
    PDU_COPT_RESTORE_PARAM = 0x8006
  } T_PDU_COPT;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.3 Object type values
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_OBJT
  {
    PDU_OBJT_PROTOCOL = 0x8021,
    PDU_OBJT_BUSTYPE = 0x8022,
    PDU_OBJT_IO_CTRL = 0x8023,
    PDU_OBJT_COMPARAM = 0x8024,
    PDU_OBJT_PINTYPE = 0x8025,
    PDU_OBJT_RESOURCE = 0x8026
  } T_PDU_OBJT;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.4 Status code values
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_STATUS
  {
    //  ComPrimitive status
    PDU_COPST_IDLE = 0x8010,
    PDU_COPST_EXECUTING = 0x8011,
    PDU_COPST_FINISHED = 0x8012,
    PDU_COPST_CANCELLED = 0x8013,
    PDU_COPST_WAITING = 0x8014,
    //  ComLogicalLink status   
    PDU_CLLST_OFFLINE = 0x8050,
    PDU_CLLST_ONLINE = 0x8051,
    PDU_CLLST_COMM_STARTED = 0x8052,
    PDU_CLLST_DISCONNECTING = 0x8053,
    //  Module status
    PDU_MODST_READY = 0x8060,
    PDU_MODST_NOT_READY = 0x8061,
    PDU_MODST_NOT_AVAIL = 0x8062,
    PDU_MODST_AVAIL = 0x8063
  } T_PDU_STATUS;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.5 Information event values
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_INFO
  {
    PDU_INFO_MODULE_LIST_CHG = 0x8070,
    PDU_INFO_RSC_LOCK_CHG = 0x8071,
    PDU_INFO_PHYS_COMPARAM_CHG = 0x8072
  } T_PDU_INFO;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.8 Event callback data values
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_EVT_DATA
  {
    PDU_EVT_DATA_AVAILABLE = 0x0801,
    PDU_EVT_DATA_LOST = 0x0802
  } T_PDU_EVT_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.10 IOCTL filter type values
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_FILTER
  {
    PDU_FLT_PASS = 0x00000001,
    PDU_FLT_BLOCK = 0x00000002,
    PDU_FLT_PASS_UUDT = 0x00000011,
    PDU_FLT_BLOCK_UUDT = 0x00000012
  } T_PDU_FILTER;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.1.11 IOCTL event queue mode type values
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_QUEUE_MODE
  {
    PDU_QUE_UNLIMITED = 0x00000000,
    PDU_QUE_LIMITED = 0x00000001,
    PDU_QUE_CIRCULAR = 0x00000002
  } T_PDU_QUEUE_MODE;



  ///////////////////////////////////////////////////////////////////////////////
  /// D.3 Function return values
  ///////////////////////////////////////////////////////////////////////////////

  enum T_PDU_ERROR
  {
    PDU_STATUS_NOERROR = 0x00000000,
    PDU_ERR_FCT_FAILED = 0x00000001,
    PDU_ERR_DEVICE_NOT_CONNECTED = 0x00000010,
    PDU_ERR_COMM_PC_TO_VCI_FAILED = 0x00000011,
    PDU_ERR_PDUAPI_NOT_CONSTRUCTED = 0x00000020,
    PDU_ERR_SHARING_VIOLATION = 0x00000021,
    PDU_ERR_RESOURCE_BUSY = 0x00000030,
    PDU_ERR_RESOURCE_TABLE_CHANGED = 0x00000031,
    PDU_ERR_RESOURCE_ERROR = 0x00000032,
    PDU_ERR_CLL_NOT_CONNECTED = 0x00000040,
    PDU_ERR_CLL_NOT_STARTED = 0x00000041,
    PDU_ERR_INVALID_PARAMETERS = 0x00000050,
    PDU_ERR_INVALID_HANDLE = 0x00000060,
    PDU_ERR_VALUE_NOT_SUPPORTED = 0x00000061,
    PDU_ERR_ID_NOT_SUPPORTED = 0x00000062,
    PDU_ERR_COMPARAM_NOT_SUPPORTED = 0x00000063,
    PDU_ERR_COMPARAM_LOCKED = 0x00000064,
    PDU_ERR_TX_QUEUE_FULL = 0x00000070,
    PDU_ERR_EVENT_QUEUE_EMPTY = 0x00000071,
    PDU_ERR_VOLTAGE_NOT_SUPPORTED = 0x00000080,
    PDU_ERR_MUX_RSC_NOT_SUPPORTED = 0x00000081,
    PDU_ERR_CABLE_UNKNOWN = 0x00000082,
    PDU_ERR_NO_CABLE_DETECTED = 0x00000083,
    PDU_ERR_CLL_CONNECTED = 0x00000084,
    PDU_ERR_TEMPPARAM_NOT_ALLOWED = 0x00000090,
    PDU_ERR_RSC_LOCKED = 0x000000A0,
    PDU_ERR_RSC_LOCKED_BY_OTHER_CLL = 0x000000A1,
    PDU_ERR_RSC_NOT_LOCKED = 0x000000A2,
    PDU_ERR_MODULE_NOT_CONNECTED = 0x000000A3,
    PDU_ERR_API_SW_OUT_OF_DATE = 0x000000A4,
    PDU_ERR_MODULE_FW_OUT_OF_DATE = 0x000000A5,
    PDU_ERR_DOIP_RESPONSE_TIMEOUT = 0x000000A6,
    PDU_ERR_IP_PROTOCOL_NOT_SUPPORTED = 0x000000B0,
    PDU_ERR_DOIP_ROUTING_ACTIVATION_FAILED = 0x000000B1,
    PDU_ERR_DOIP_ROUTING_ACTIVATION_AUTHENTICATION_FAILED = 0x000000B2,
    PDU_ERR_DOIP_AMBIGUOUS_LOGICAL_ADDRESS = 0x000000B3,
    PDU_ERR_NO_VALID_LICENSE = 0x000000B4,
    PDU_ERR_INVALID_I2SCOMLIB_VERSION = 0x000000B5,
    PDU_ERR_INVALID_ISO14230_VERSION = 0x000000B6,
    PDU_ERR_INVALID_CANBASE_VERSION = 0x000000B7
  };



  ///////////////////////////////////////////////////////////////////////////////
  /// D.4 Event error codes
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_ERR_EVT
  {
    PDU_ERR_EVT_NOERROR = 0x00000000,
    PDU_ERR_EVT_FRAME_STRUCT = 0x00000100,
    PDU_ERR_EVT_TX_ERROR = 0x00000101,
    PDU_ERR_EVT_TESTER_PRESENT_ERROR = 0x00000102,
    PDU_ERR_EVT_RX_TIMEOUT = 0x00000103,
    PDU_ERR_EVT_RX_ERROR = 0x00000104,
    PDU_ERR_EVT_PROT_ERR = 0x00000105,
    PDU_ERR_EVT_LOST_COMM_TO_VCI = 0x00000106,
    PDU_ERR_EVT_VCI_HARDWARE_FAULT = 0x00000107,
    PDU_ERR_EVT_INIT_ERROR = 0x00000108,
    PDU_ERR_EVT_RSC_LOCKED = 0x00000109	// DEFINED BY IN2SOFT
  } T_PDU_ERR_EVT;




  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.2 ComParam class
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_PC
  {
    PDU_PC_UNDEFINED = 0,
    PDU_PC_TIMING = 1,
    PDU_PC_INIT = 2,
    PDU_PC_COM = 3,
    PDU_PC_ERRHDL = 4,
    PDU_PC_BUSTYPE = 5,
    PDU_PC_UNIQUE_ID = 6,
    PDU_PC_TESTER_PRESENT = 7
  } T_PDU_PC;



  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.3 ComParam data type
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_PT
  {
    PDU_PT_UNDEFINED = 0xFFFFFFFF,
    PDU_PT_UNUM8 = 0x00000101,    // Unsigned byte  
    PDU_PT_SNUM8 = 0x00000102,    // Signed byte  
    PDU_PT_UNUM16 = 0x00000103,    // Unsigned two bytes  
    PDU_PT_SNUM16 = 0x00000104,    // Signed two bytes  
    PDU_PT_UNUM32 = 0x00000105,    // Unsigned four bytes  
    PDU_PT_SNUM32 = 0x00000106,    // Signed four bytes  
    PDU_PT_BYTEFIELD = 0x00000107,
    PDU_PT_STRUCTFIELD = 0x00000108,
    PDU_PT_LONGFIELD = 0x00000109
  } T_PDU_PT;



  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.3.2 ComParamStructType structures
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_CPST
  {
    PDU_CPST_SESSION_TIMING = 0x00000001,
    PDU_CPST_ACCESS_TIMING = 0x00000002
  } T_PDU_CPST;



  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.6
  ///////////////////////////////////////////////////////////////////////////////

  typedef enum E_PDU_PL
  {
    PDU_PL_UNDEFINED = 0,
    PDU_PL_APPLICATION,
    PDU_PL_TRANSPORT,
    PDU_PL_PHYSICAL,
    PDU_PL_URID							// IN2SOFT SPECIFIC
  } T_PDU_PL;



  /******************************************************************************
  * DATA STRUCTURES															  *
  *******************************************************************************/



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.2 Generic Item for type evaluation and casting
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    T_PDU_IT  ItemType;
  } PDU_ITEM;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.3.1 Item for Generic IOCTL data item
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    T_PDU_IT  ItemType;
    void    *pData;
  } PDU_DATA_ITEM;


  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.3.2 IOCTL programming voltage structure (PDU_IT_IO_PROG_VOLTAGE) 
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32  ProgVoltage_mv;
    UNUM32  PinOnDLC;
  } PDU_IO_PROG_VOLTAGE_DATA;


  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.3.3 IOCTL byte array structure (PDU_IT_IO_BYTEARRAY) 
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32  DataSize;
    UNUM8   *pData;
  } PDU_IO_BYTEARRAY_DATA;


  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.3.4 IOCTL filter list structure (PDU_IT_IO_FILTER)
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    T_PDU_FILTER  FilterType;
    UNUM32  FilterNumber;
    UNUM32  FilterCompareSize;
    UNUM8   FilterMaskMessage[12];
    UNUM8   FilterPatternMessage[12];
  } PDU_IO_FILTER_DATA;


  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.3.5 IOCTL filter data structure
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32  NumFilterEntries;
    PDU_IO_FILTER_DATA *pFilterData;
  } PDU_IO_FILTER_LIST;


  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.3.6 IOCTL event queue property structure 
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32 QueueSize;
    T_PDU_QUEUE_MODE QueueMode;
  } PDU_IO_EVENT_QUEUE_PROPERTY_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.4 Item for resource status information via PDUGetResourceStatus
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32  hMod;
    UNUM32  ResourceId;
    UNUM32  ResourceStatus;
  } PDU_RSC_STATUS_DATA;


  typedef struct
  {
    T_PDU_IT  ItemType;
    UNUM32  NumEntries;
    PDU_RSC_STATUS_DATA *pResourceStatusData;
  } PDU_RSC_STATUS_ITEM;


  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.5 Item for ComParam data (used by PDUGetComParam, PDUSetComParam) 
  ///////////////////////////////////////////////////////////////////////////////

  struct PDU_PARAM_ITEM
  {
    PDU_PARAM_ITEM();
    PDU_PARAM_ITEM(UNUM32 _paramId, T_PDU_PC _paramClass, UNUM32 _value);
    PDU_PARAM_ITEM(const PDU_PARAM_ITEM& _paramItem);
    ~PDU_PARAM_ITEM();
    PDU_PARAM_ITEM& operator =(const PDU_PARAM_ITEM& _paramItem);
    void DeleteComParamData();

    T_PDU_IT	ItemType;
    UNUM32		ComParamId;
    T_PDU_PT	ComParamDataType;
    T_PDU_PC	ComParamClass;
    void		*pComParamData;
  };



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.6 Item for module identification (used by PDUGetModuleIds) 
  ///////////////////////////////////////////////////////////////////////////////

  struct PDU_MODULE_DATA
  {
    UNUM32  ModuleTypeId;
    UNUM32  hMod;
    CHAR8   *pVendorModuleName;
    CHAR8   *pVendorAdditionalInfo;
    T_PDU_STATUS  ModuleStatus;
  };


  struct PDU_MODULE_ITEM
  {
    T_PDU_IT  ItemType;
    UNUM32  NumEntries;
    PDU_MODULE_DATA *pModuleData;
  };



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.7 Items for resource identification (used by PDUGetResourceIds)
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32 hMod;
    UNUM32 NumIds;
    UNUM32 *pResourceIdArray;
  } PDU_RSC_ID_ITEM_DATA;


  typedef struct
  {
    T_PDU_IT ItemType;
    UNUM32 NumModules;
    PDU_RSC_ID_ITEM_DATA *pResourceIdDataArray;
  } PDU_RSC_ID_ITEM;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.8 Structure for resource data
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32  DLCPinNumber;
    UNUM32  DLCPinTypeId;
  } PDU_PIN_DATA;


  typedef struct
  {
    UNUM32 BusTypeId;
    UNUM32 ProtocolId;
    UNUM32 NumPinData;
    PDU_PIN_DATA *pDLCPinData;
  } PDU_RSC_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.9 Item for conflicting resources (PDUGetConflictingResources) 
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32 hMod;
    UNUM32 ResourceId;
  } PDU_RSC_CONFLICT_DATA;


  typedef struct
  {
    T_PDU_IT ItemType;
    UNUM32 NumEntries;
    PDU_RSC_CONFLICT_DATA *pRscConflictData;
  } PDU_RSC_CONFLICT_ITEM;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.10 Item for unique response identification
  ///////////////////////////////////////////////////////////////////////////////

  struct PDU_ECU_UNIQUE_RESP_DATA
  {
    PDU_ECU_UNIQUE_RESP_DATA();
    PDU_ECU_UNIQUE_RESP_DATA(const PDU_ECU_UNIQUE_RESP_DATA& _paramItem);
    PDU_ECU_UNIQUE_RESP_DATA& operator =(const PDU_ECU_UNIQUE_RESP_DATA& _paramItem);
    ~PDU_ECU_UNIQUE_RESP_DATA();
    UNUM32 UniqueRespIdentifier;
    UNUM32 NumParamItems;
    PDU_PARAM_ITEM *pParams;
  };


  struct PDU_UNIQUE_RESP_ID_TABLE_ITEM
  {
    PDU_UNIQUE_RESP_ID_TABLE_ITEM();
    PDU_UNIQUE_RESP_ID_TABLE_ITEM(const PDU_UNIQUE_RESP_ID_TABLE_ITEM& _paramItem);
    PDU_UNIQUE_RESP_ID_TABLE_ITEM& operator =(const PDU_UNIQUE_RESP_ID_TABLE_ITEM& _paramItem);
    ~PDU_UNIQUE_RESP_ID_TABLE_ITEM();

    T_PDU_IT ItemType;
    UNUM32 NumEntries;
    PDU_ECU_UNIQUE_RESP_DATA *pUniqueData;
  };



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.11 Item for event notification
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    T_PDU_IT  ItemType;
    UNUM32  hCoP;
    void*   pCoPTag;
    UNUM32  Timestamp;
    void*   pData;
  } PDU_EVENT_ITEM;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.11.1 Structure for status data
  ///////////////////////////////////////////////////////////////////////////////

  typedef T_PDU_STATUS PDU_STATUS_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.11.2 Asynchronous event information notification for PDU_IT_INFO
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    T_PDU_INFO	InfoCode;
    UNUM32		ExtraInfoData;
  } PDU_INFO_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.11.3 Asynchronous error notification structure for the PDU_IT_ERROR 
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    T_PDU_ERR_EVT	ErrorCodeId;
    UNUM32			ExtraErrorInfoId;
  } PDU_ERROR_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.13 Structure for flag data
  ///////////////////////////////////////////////////////////////////////////////

  struct PDU_FLAG_DATA
  {
    PDU_FLAG_DATA(bool _bRawMode, bool _bChecksumMode);
    ~PDU_FLAG_DATA();
    UNUM32  NumFlagBytes;
    UNUM8   *pFlagData;
  };



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.12 Structure for extra result data information
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32 NumHeaderBytes;
    UNUM32 NumFooterBytes;
    UNUM8 *pHeaderBytes;
    UNUM8 *pFooterBytes;
  } PDU_EXTRA_INFO;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.11.4 Structure for result data
  ///////////////////////////////////////////////////////////////////////////////

  struct PDU_RESULT_DATA
  {
    PDU_FLAG_DATA RxFlag;
    UNUM32  UniqueRespIdentifier;
    UNUM32  AcceptanceId;
    PDU_FLAG_DATA  TimestampFlags;
    UNUM32  TxMsgDoneTimestamp;
    UNUM32  StartMsgTimestamp;
    PDU_EXTRA_INFO *pExtraInfo;
    UNUM32  NumDataBytes;
    UNUM8   *pDataBytes;
  };



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.14 Structure for version information
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32 MVCI_Part1StandardVersion;
    UNUM32 MVCI_Part2StandardVersion;
    UNUM32 HwSerialNumber;
    CHAR8 HwName[64];
    UNUM32 HwVersion;
    UNUM32 HwDate;
    UNUM32 HwInterface;
    CHAR8 FwName[64];
    UNUM32 FwVersion;
    UNUM32 FwDate;
    CHAR8 VendorName[64];
    CHAR8 PDUApiSwName[64];
    UNUM32 PDUApiSwVersion;
    UNUM32 PDUApiSwDate;
  } PDU_VERSION_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.18 Structure for expected response 
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32  ResponseType;
    UNUM32  AcceptanceId;
    UNUM32  NumMaskPatternBytes;
    UNUM8   *pMaskData;
    UNUM8   *pPatternData;
    UNUM32  NumUniqueRespIds;
    UNUM32  *pUniqueRespIds;
  } PDU_EXP_RESP_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// 11.1.4.17 Structure to control a ComPrimitive's operation
  ///////////////////////////////////////////////////////////////////////////////

  struct PDU_COP_CTRL_DATA
  {
    UNUM32 Time;
    SNUM32 NumSendCycles;
    SNUM32 NumReceiveCycles;
    UNUM32 TempParamUpdate;
    PDU_FLAG_DATA TxFlag;
    UNUM32 NumPossibleExpectedResponses;
    PDU_EXP_RESP_DATA *pExpectedResponseArray;
  };



  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.3.1 ComParam BYTEFIELD data type
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32   ParamMaxLen;
    UNUM32   ParamActLen;
    UNUM8    *pDataArray;
  } PDU_PARAM_BYTEFIELD_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.3.3 ComParam LONGFIELD data type
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32 ParamMaxLen;
    UNUM32 ParamActLen;
    UNUM32 *pDataArray;
  } PDU_PARAM_LONGFIELD_DATA;



  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.3.2 ComParam STRUCTFIELD data type
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    T_PDU_CPST	ComParamStructType;
    UNUM32		ParamMaxEntries;
    UNUM32		ParamActEntries;
    void		*pStructArray;
  } PDU_PARAM_STRUCTFIELD_DATA;

  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.3.2.1 ComParam STRUCTFIELD Session timing
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM16 session;
    UNUM8 P2Max_high;
    UNUM8 P2Max_low;
    UNUM8 P2Star_high;
    UNUM8 P2Star_low;
  } PDU_PARAM_STRUCT_SESS_TIMING;

  ///////////////////////////////////////////////////////////////////////////////
  /// B.3.3.2.2 ComParam STRUCTFIELD Access timing
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM8 P2Min;
    UNUM8 P2Max;
    UNUM8 P3Min;
    UNUM8 P3Max;
    UNUM8 P4Min;
    UNUM8 TimingSet;
  } PDU_PARAM_STRUCT_ACCESS_TIMING;

  ///////////////////////////////////////////////////////////////////////////////
  /// DoIP/6.4.5.1 Structures for IOCTL PDU_IOCTL_VEHICLE_ID_REQUEST
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32	IpVersion;		// the IP version to be used for DoIP communication: 4=IPv4, 6=IPv6 
    UNUM8	*pAddress;		// IPv4: 4 Byte broadcast address, IPv6: 16 Byte multicast address 
  } PDU_IP_ADDR_INFO;


  typedef struct
  {
    UNUM32	PreselectionMode;					// Preselection mode: 0=no preselection 
                          // 1= select DoIP entities with given VIN 

    CHAR8*	PreselectionValue;					// pointer to NULL terminated ASCII string 
                          // containing optional VIN (depending on 
                          // PreselectionMode) 

    UNUM32	CombinationMode;					// Combination mode: 
                          // 0= no combination 
                          // 1= combine DoIP entities with common VIN 
                          //    into MVCI of type 'DoIP-Vehicle'
                          // 2= combine DoIP entities with common GroupID 
                          //    into MVCI of type 'DoIP-Group' 
                          // 3= combine all DoIP entities 
                          //    into MVCI of type 'DoIP-Collection'

    UNUM32	VehicleDiscoveryTime;				// Time-out to wait for vehicle identification 	responses. 
                          // 0=return immediately, or time in milliseconds. 

    UNUM32	NumDestinationAddresses;			// Number of broadcast/multicast addresses in the destination 
                          // address array. May be 0 for default 

    PDU_IP_ADDR_INFO *pDestinationAddresses;	// pointer to an array of IP addresses on which 
                          // broadcast/multicast should be performed 

  } PDU_IO_VEHICLE_ID_REQUEST;

  ///////////////////////////////////////////////////////////////////////////////
  /// DoIP/6.4.6.1 Structures for IOCTL PDU_IOCTL_SET_ETH_SWITCH_STATE
  ///////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32	EthernetSenseState;			// 0 = Ethernet activation pin off
                      // 1 = Ethernet activation pin on
    UNUM32	EthernetActPinNumber;		// Pin number on DLC of the ethernet activation pin. Default shall be 8 as defined in ISO13400-2 for OBD-connector 
  } PDU_IO_ETH_SWITCH_STATE;

  ///////////////////////////////////////////////////////////////////////////////////////////
  // Volkswagen spezifische Ergänzungen der ISO 13400 Querschnittslastenheft LAH DUM 907 AQ
  ///////////////////////////////////////////////////////////////////////////////////////////

  typedef struct
  {
    UNUM32 LogicalAddress;		// logical address of DoIP entity to access
    UNUM32 DoIPCtrlTimeout;		// Timeout in milliseconds to wait for the response from the DoIP entity (corresponds to A_DoIP_Ctrl in ISO 13400)
  } PDU_IO_ENTITY_ADDRESS_DATA;

  typedef struct
  {
    UNUM32 EntityType;		// Type of DoIP entity: 0x0=gateway 0x1=node
    UNUM32 TcpClientsMax;	// Maximum number of concurrent TCP_DATA sockets allowed with this DoIP entity, excluding the reserve socket required for socket handling.
    UNUM32 TcpClients;		// Number of currently established sockets.
    UNUM32 MaxDataSize;		// Optional limit (in bytes) for the maximum size of a single DoIP request. This value will be 0 if no limits are reported by the DoIP entity.
  } PDU_IO_ENTITY_STATUS_DATA;


  // See PDU Specification for details
  T_PDU_ERROR  PDUConstruct(CHAR8* pszOption, void* pAPITag);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUDestruct();
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUModuleConnect(UNUM32 hMod);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUModuleDisconnect(UNUM32 hMod);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetModuleIds(PDU_MODULE_ITEM** pModuleIdList);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetResourceIds(UNUM32 hMod, PDU_RSC_DATA* pResourceIdData, PDU_RSC_ID_ITEM** pResourceIdList);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetResourceStatus(PDU_RSC_STATUS_ITEM* pResourceStatus);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUCreateComLogicalLink(UNUM32 hMod, PDU_RSC_DATA* pRscData, UNUM32 uiResourceId, void* pCllTag, UNUM32* phCll, PDU_FLAG_DATA* pCllCreateFlag);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUDestroyComLogicalLink(UNUM32 hMod, UNUM32 hCll);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDURegisterEventCallback(UNUM32 hMod, UNUM32 hCll, CALLBACKFNC fnCB);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetComParam(UNUM32 hMod, UNUM32 hCll, UNUM32 uiParamId, PDU_PARAM_ITEM** pParamItem);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUSetComParam(UNUM32 hMod, UNUM32 hCll, PDU_PARAM_ITEM* pParamItem);
  ////////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUConnect(UNUM32 hMod, UNUM32 hCll);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUDisconnect(UNUM32 hMod, UNUM32 hCll);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUStartComPrimitive(UNUM32 hMod, UNUM32 hCll, T_PDU_COPT uiCoPType, UNUM32 uiCoPDataSize, UNUM8* pCoPData, PDU_COP_CTRL_DATA* pCopCtrlData, void* pCoPTag, UNUM32* phCoP);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUCancelComPrimitive(UNUM32 hMod, UNUM32 hCll, UNUM32 hCoP);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetEventItem(UNUM32 hMod, UNUM32 hCll, PDU_EVENT_ITEM** pEventItem);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUDestroyItem(PDU_ITEM* pItem);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetVersion(UNUM32 hMod, PDU_VERSION_DATA *pVersionData);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetLastError(UNUM32 hMod, UNUM32 hCll, T_PDU_ERR_EVT *pErrorCode, UNUM32 *phCoP, UNUM32 *pTimestamp, UNUM32 *pExtraErrorInfo);
  //////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCll, PDU_UNIQUE_RESP_ID_TABLE_ITEM** pUniqueRespIdTable);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUSetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCll, PDU_UNIQUE_RESP_ID_TABLE_ITEM* pUniqueRespIdTable);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUIoCtl(UNUM32 hMod, UNUM32 hCll, UNUM32 uiIoCtlCommandId, PDU_DATA_ITEM* pInputData, PDU_DATA_ITEM** pOutputData);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetObjectId(UNUM32 uiPDUObjectType, CHAR8* pszShortName, UNUM32* pPDUObjectId);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetTimestamp(UNUM32 hMod, UNUM32* puiTimestamp);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetStatus(UNUM32 hMod, UNUM32 hCll, UNUM32 hCoP, T_PDU_STATUS* puiStatusCode, UNUM32* puiTimestamp, UNUM32* puiExtraInfo);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDUGetConflictingResources(UNUM32 uiResourceId, PDU_MODULE_ITEM* pModuleList, PDU_RSC_CONFLICT_ITEM** pConflictList);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details
  T_PDU_ERROR  PDULockResource(UNUM32 hMod, UNUM32 hCll, UNUM32 uiLockMask);
  ///////////////////////////////////////////////////////////////////////////////
  // See PDU Specification for details

  T_PDU_ERROR  PDUUnlockResource(UNUM32 hMod, UNUM32 hCll, UNUM32 uiLockMask);

}
#endif // PDU_API_H
