#pragma once
namespace PduApiClr
{
  public enum class T_PDU_IT
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
    PDU_I2S_IT_FLAG = 0x2008, // PDU_FLAG_DATA
    PDU_I2S_IT_EXTRA_INFO = 0x2009,
    PDU_I2S_IT_RSC_ID_ITEM_DATA = 0x200A,
    PDU_I2S_IT_RSC_CONFLICT_DATA = 0x200B,
    PDU_I2S_IT_MODULE_DATA = 0x200C, // PDU_MODULE_DATA
    PDU_I2S_IT_COP_CTRL = 0x200D,
    PDU_I2S_IT_EXP_RESP_DATA = 0x200E,
    PDU_I2S_IT_RSC_DATA = 0x200F, // PDU_RSC_DATA
    PDU_I2S_IT_PIN_DATA = 0x2010,
    PDU_I2S_IT_RESOURCE_TABLE_ENTRY = 0x2011, // PDU_RESOURCE_TABLE_ENTRY
    PDU_I2S_IT_ECU_UNIQUE_RESP_DATA = 0x2012, // PDU_ECU_UNIQUE_RESP_DATA
    PDU_I2S_IT_IO_UNUM32_DATA = 0x2013, // PDU_IO_UNUM32_DAT
  };
}