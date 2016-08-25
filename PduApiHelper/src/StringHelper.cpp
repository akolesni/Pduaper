#include "StdAfx.h"
//#include <boost/algorithm/string.hpp>
#include "StringHelper.h"
//#include "PDULogger.h"


namespace dpduapi
{
  const char* PDU_IOCTL_RESET                      = "PDU_IOCTL_RESET";
  const char* PDU_IOCTL_CLEAR_TX_QUEUE             = "PDU_IOCTL_CLEAR_TX_QUEUE";
  const char* PDU_IOCTL_SUSPEND_TX_QUEUE           = "PDU_IOCTL_SUSPEND_TX_QUEUE";
  const char* PDU_IOCTL_RESUME_TX_QUEUE            = "PDU_IOCTL_RESUME_TX_QUEUE";
  const char* PDU_IOCTL_CLEAR_RX_QUEUE             = "PDU_IOCTL_CLEAR_RX_QUEUE";
  const char* PDU_IOCTL_READ_VBATT                 = "PDU_IOCTL_READ_VBATT";
  const char* PDU_IOCTL_SET_PROG_VOLTAGE           = "PDU_IOCTL_SET_PROG_VOLTAGE";
  const char* PDU_IOCTL_READ_PROG_VOLTAGE          = "PDU_IOCTL_READ_PROG_VOLTAGE";
  const char* PDU_IOCTL_GENERIC                    = "PDU_IOCTL_GENERIC";
  const char* PDU_IOCTL_SET_BUFFER_SIZE            = "PDU_IOCTL_SET_BUFFER_SIZE";
  const char* PDU_IOCTL_START_MSG_FILTER           = "PDU_IOCTL_START_MSG_FILTER";
  const char* PDU_IOCTL_STOP_MSG_FILTER            = "PDU_IOCTL_STOP_MSG_FILTER";
  const char* PDU_IOCTL_CLEAR_MSG_FILTER           = "PDU_IOCTL_CLEAR_MSG_FILTER";
  const char* PDU_IOCTL_SET_EVENT_QUEUE_PROPERTIES = "PDU_IOCTL_SET_EVENT_QUEUE_PROPERTIES";
  const char* PDU_IOCTL_GET_CABLE_ID               = "PDU_IOCTL_GET_CABLE_ID";
  const char* PDU_IOCTL_SEND_BREAK                 = "PDU_IOCTL_SEND_BREAK";
  const char* PDU_IOCTL_READ_IGNITION_SENSE_STATE  = "PDU_IOCTL_READ_IGNITION_SENSE_STATE";
  const char* PDU_IOCTL_SET_ETH_SWITCH_STATE       = "PDU_IOCTL_SET_ETH_SWITCH_STATE";
  const char* PDU_IOCTL_FORCE_STMIN                = "PDU_IOCTL_FORCE_STMIN";
}


/**
*\brief Constructor
*/
StringHelper::StringHelper()
{
}

/**
*\brief Destructor
*/
StringHelper::~StringHelper()
{
}

/**
*@brief - Checks if string has value 'NULL'
*
*@param strInInputSting - The string to testing
 *
*@return true - if inpit has value 'NULL'
*/
//bool StringHelper::IsNull(std::string _strInInputSting)
//{
//  bool bResult = false;
//
//  _strInInputSting.erase(
//    std::remove(_strInInputSting.begin(), _strInInputSting.end(), ' '), _strInInputSting.end());
//  _strInInputSting.erase(
//    std::remove(_strInInputSting.begin(), _strInInputSting.end(), '\t'), _strInInputSting.end());
//  _strInInputSting.erase(
//    std::remove(_strInInputSting.begin(), _strInInputSting.end(), '\n'), _strInInputSting.end());
//
//  if (_strInInputSting == "NULL")
//  {
//    bResult = true;
//  }
//
//  return bResult;
//}

//bool StringHelper::Check_hModeText(const std::string& _strInInputSting)
//{
//  bool bResult = false;
//
//  if (!(StringHelper::IsNullOrEmpty(_strInInputSting)))
//  {
//    if(_strInInputSting != std::string( "INVALID_MODULE_HANDLE" ) && _strInInputSting != std::string( "PDU_HANDLE_UNDEF" ))
//    {
//      bResult = true;
//    }
//  }
//
//  return bResult;
//}

/**
 *@brief  - Casts string to boolean. Allowed only '1', '0', 'true' and 'false' case insensitive.
 *
 *@param - IN - _strInput - Input string.
 *
 *@return - true or false
 */
//bool StringHelper::StringToBool(std::string _strInput)
//{
//  bool bResult = false;
//
//  boost::trim_left(_strInput);
//  boost::trim_right(_strInput);
//  boost::algorithm::to_lower(_strInput);
//
//  if (_strInput == std::string("1") ||
//    _strInput == std::string("true"))
//  {
//    bResult = true;
//  }
//  else if (_strInput == std::string("0") ||
//    _strInput == std::string("false"))
//  {
//    bResult = false;
//  }
//  else
//  {
//    throw std::string(
//      "Error in StringHelper::StringToBool(). Input parametr not allowed :" +
//      _strInput + "'. Must be '1', '0', 'true' or 'false'.");
//  }
//
//  return bResult;
//}

/**
 * @brief   - The function converts one PDU API function result value to one string.
 * 
 * @param   - IN   - p_value    The value to be translated to one string.
            - OUT  - p_outValue - result as string
 * @return  - true - if succeeds
 */

//bool StringHelper::PduApiResultString(T_PDU_ERROR p_value, std::string& p_outValue)
//{
//  // reset value to empty string
//  p_outValue = std::string();
//
//  // search for error value in map
//  PDU_STATUS_MAP_ELEMENT_TYPE l_element;
//  unsigned int l_pos = 0;
//  do
//  {
//    l_element = l_pduErrorMap[l_pos];
//
//    if (l_element.error == p_value)
//    {
//      if (l_element.name == nullptr)
//      {
//        // this is one error
//        std::string strError = std::string("Something wrong in table for error " +
//          std::to_string(static_cast<unsigned long long>(p_value)));
//        XML_TST_LOG_ERROR(strError.c_str());
//
//        return false;
//      }
//      else
//      {
//        p_outValue = std::string(l_element.name);
//        return true;
//      }
//    }
//
//    l_pos++;
//  }
//  while (l_element.name != nullptr);
//
//  p_outValue = std::string("PDU_ERR_FCT_FAILED");
//
//  return false;
//}

/**
 * @brief   - The function converts input string to ComParam data type.
 * 
 *@param   - IN   - _strInput - Input string to convert.
 *
 *@return  - ComParam data type.
 */
//
//T_PDU_PT StringHelper::StringToComParamDataType(std::string _strInput)
//{
//  T_PDU_PT eResult = PDU_PT_UNDEFINED;
//
//  if (_strInput == std::string("UNUM8"))
//  {
//    eResult = PDU_PT_UNUM8;
//  }
//  else if (_strInput == std::string("SNUM8"))
//  {
//    eResult = PDU_PT_SNUM8;
//  }
//  else if (_strInput == std::string("UNUM16"))
//  {
//    eResult = PDU_PT_UNUM16;
//  }
//  else if (_strInput == std::string("SNUM16"))
//  {
//    eResult = PDU_PT_SNUM16;
//  }
//  else if (_strInput == std::string("UNUM32"))
//  {
//    eResult = PDU_PT_UNUM32;
//  }
//  else if (_strInput == std::string("SNUM32"))
//  {
//    eResult = PDU_PT_SNUM32;
//  }
//  else if (_strInput == std::string("BYTEFIELD"))
//  {
//    eResult = PDU_PT_BYTEFIELD;
//  }
//  else if (_strInput == std::string("LONGFIELD"))
//  {
//    eResult = PDU_PT_LONGFIELD;
//  }
//  else if (_strInput == std::string("STRUCTFIELD"))
//  {
//    eResult = PDU_PT_STRUCTFIELD;
//  }
//
//  return eResult;
//}
//
//std::string StringHelper::ComParamDataTypeToString(const T_PDU_PT _eComParamDataType)
//{
//  std::string strResult;
//  switch (_eComParamDataType)
//  {
//  case PDU_PT_UNUM8:
//    {
//      strResult = "PDU_PT_UNUM8";
//      break;
//    }
//  case PDU_PT_SNUM8:
//    {
//      strResult = "PDU_PT_SNUM8";
//      break;
//    }
//  case PDU_PT_UNUM16:
//    {
//      strResult = "PDU_PT_UNUM16";
//      break;
//    }
//  case PDU_PT_SNUM16:
//    {
//      strResult = "PDU_PT_SNUM16";
//      break;
//    }
//  case PDU_PT_UNUM32:
//    {
//      strResult = "PDU_PT_UNUM32";
//      break;
//    }
//  case PDU_PT_SNUM32:
//    {
//      strResult = "PDU_PT_SNUM32";
//      break;
//    }
//  case PDU_PT_BYTEFIELD:
//    {
//      strResult = "PDU_PT_BYTEFIELD";
//      break;
//    }
//  case PDU_PT_STRUCTFIELD:
//    {
//      strResult = "PDU_PT_STRUCTFIELD";
//      break;
//    }
//  case PDU_PT_LONGFIELD:
//    {
//      strResult = "PDU_PT_LONGFIELD";
//      break;
//    }
//  }
//  return strResult;
//}
//
//std::string StringHelper::ComParamToString(const PDU_PARAM_ITEM& _comParam)
//{
//  std::stringstream strim;
//  strim.setf(std::ios::hex, std::ios::basefield);
//  strim.setf(std::ios::showbase);
//  switch (_comParam.ComParamDataType)
//  {
//  case PDU_PT_UNUM8:
//    {
//      UNUM8* value = reinterpret_cast<UNUM8*>(_comParam.pComParamData);
//      strim << *value;
//      break;
//    }
//  case PDU_PT_SNUM8:
//    {
//      SNUM8* value = reinterpret_cast<SNUM8*>(_comParam.pComParamData);
//      strim << *value;
//      break;
//    }
//  case PDU_PT_UNUM16:
//    {
//      UNUM16* value = reinterpret_cast<UNUM16*>(_comParam.pComParamData);
//      strim << *value;
//      break;
//    }
//  case PDU_PT_SNUM16:
//    {
//      SNUM16* value = reinterpret_cast<SNUM16*>(_comParam.pComParamData);
//      strim << *value;
//      break;
//    }
//  case PDU_PT_UNUM32:
//    {
//      UNUM32* value = reinterpret_cast<UNUM32*>(_comParam.pComParamData);
//      strim << *value;
//      break;
//    }
//  case PDU_PT_SNUM32:
//    {
//      SNUM32* value = reinterpret_cast<SNUM32*>(_comParam.pComParamData);
//      strim << *value;
//      break;
//    }
//  case PDU_PT_BYTEFIELD:
//    {
//      //PDU_PARAM_BYTEFIELD_DATA* value = reinterpret_cast<PDU_PARAM_BYTEFIELD_DATA*>(
//      //  _comParam.pComParamData);
//      strim << "PDU_PT_BYTEFIELD";
//      break;
//    }
//  case PDU_PT_STRUCTFIELD:
//    {
//      //PDU_PARAM_STRUCTFIELD_DATA* value = reinterpret_cast<PDU_PARAM_STRUCTFIELD_DATA*>(
//      //  _comParam.pComParamData);
//      strim << "PDU_PT_STRUCTFIELD";
//      break;
//    }
//  case PDU_PT_LONGFIELD:
//    {
//      //PDU_PARAM_LONGFIELD_DATA* value = reinterpret_cast<PDU_PARAM_LONGFIELD_DATA*>(
//      //  _comParam.pComParamData);
//      strim << "PDU_PT_LONGFIELD";
//      break;
//    }
//  }
//
//  return strim.str();
//}

/**
 * @brief   - The function converts input string to ComParam data type.
* typedef enum E_PDU_IT
* {
* PDU_IT_IO_UNUM32 = 0x1000,         	IOCTL UNUM32 item. 
* PDU_IT_IO_PROG_VOLTAGE = 0x1001,         IOCTL Program Voltage item. 
* PDU_IT_IO_BYTEARRAY = 0x1002,         IOCTL Byte Array item. 
* PDU_IT_IO_FILTER = 0x1003,         IOCTL Filter item. 
* PDU_IT_IO_EVENT_QUEUE_PROPERTY   = 0x1004,         IOCTL Event Queue Property item. 
* PDU_IT_RSC_STATUS = 0x1100,         Resource Status item 
* PDU_IT_PARAM = 0x1200,         ComParam item 
* PDU_IT_RESULT = 0x1300,         Result item 
* PDU_IT_STATUS = 0x1301,         Status notification item 
* PDU_IT_ERROR = 0x1302,         Error notification item 
* PDU_IT_INFO = 0x1303,         Information notification item 
* PDU_IT_RSC_ID = 0x1400,         Resource ID item 
* PDU_IT_RSC_CONFLICT = 0x1500,         Resource Conflict Item 
* PDU_IT_MODULE_ID = 0x1600,         Module ID item 
* PDU_IT_UNIQUE_RESP_ID_TABLE = 0x1700          Unique Response Id Table Item 
* } T_PDU_IT;
 * 
 *@param   - IN   - _strInput - Input string to convert.
 *
 *@return  - ComParam data type.
 */
//
//T_PDU_IT StringHelper::StringToDataItemType(std::string _strInput)
//{
//  T_PDU_IT eResult;
//
//  if (_strInput == std::string("PDU_IT_IO_UNUM32"))
//  {
//    eResult = PDU_IT_IO_UNUM32;
//  }
//  else if (_strInput == std::string("PDU_IT_IO_PROG_VOLTAGE"))
//  {
//    eResult = PDU_IT_IO_PROG_VOLTAGE;
//  }
//  else if (_strInput == std::string("PDU_IT_IO_BYTEARRAY"))
//  {
//    eResult = PDU_IT_IO_BYTEARRAY;
//  }
//  else if (_strInput == std::string("PDU_IT_IO_FILTER"))
//  {
//    eResult = PDU_IT_IO_FILTER;
//  }
//  else if (_strInput == std::string("PDU_IT_IO_EVENT_QUEUE_PROPERTY"))
//  {
//    eResult = PDU_IT_IO_EVENT_QUEUE_PROPERTY;
//  }
//  else if (_strInput == std::string("PDU_IT_RSC_STATUS"))
//  {
//    eResult = PDU_IT_RSC_STATUS;
//  }
//  else if (_strInput == std::string("PDU_IT_PARAM"))
//  {
//    eResult = PDU_IT_PARAM;
//  }
//  else if (_strInput == std::string("PDU_IT_RESULT"))
//  {
//    eResult = PDU_IT_RESULT;
//  }
//  else if (_strInput == std::string("PDU_IT_STATUS"))
//  {
//    eResult = PDU_IT_STATUS;
//  }
//  else if (_strInput == std::string("PDU_IT_ERROR"))
//  {
//    eResult = PDU_IT_ERROR;
//  }
//  else if (_strInput == std::string("PDU_IT_INFO"))
//  {
//    eResult = PDU_IT_INFO;
//  }
//  else if (_strInput == std::string("PDU_IT_RSC_ID"))
//  {
//    eResult = PDU_IT_RSC_ID;
//  }
//  else if (_strInput == std::string("PDU_IT_RSC_CONFLICT"))
//  {
//    eResult = PDU_IT_RSC_CONFLICT;
//  }
//  else if (_strInput == std::string("PDU_IT_MODULE_ID"))
//  {
//    eResult = PDU_IT_MODULE_ID;
//  }
//  else if (_strInput == std::string("PDU_IT_UNIQUE_RESP_ID_TABLE"))
//  {
//    eResult = PDU_IT_UNIQUE_RESP_ID_TABLE;
//  }
//  else
//  {
//    throw std::string("T_PDU_IT - type not defined for :" + _strInput);
//  }
//  return eResult;
//}

/**
 * @brief   - The function converts DPDU data type to string.
 *
 *@param   - IN   - _ePduItemType - DPDU data type to convert.
 *
 *@return  - DPDU data type as string.
 */
//
//std::string StringHelper::DataItemTypeToString(T_PDU_IT _ePduItemType)
//{
//  std::string strResult;
//
//  if (_ePduItemType == PDU_IT_RESULT)
//  {
//    strResult = "PDU_IT_RESULT";
//  }
//  else if (_ePduItemType == PDU_IT_STATUS)
//  {
//    strResult = "PDU_IT_STATUS";
//  }
//  else if (_ePduItemType == PDU_IT_ERROR)
//  {
//    strResult = "PDU_IT_ERROR";
//  }
//  else if (_ePduItemType == PDU_IT_INFO)
//  {
//    strResult = "PDU_IT_INFO";
//  }
//  else if (_ePduItemType == PDU_IT_IO_UNUM32)
//  {
//    strResult = "PDU_IT_IO_UNUM32";
//  }
//  else if (_ePduItemType == PDU_IT_IO_PROG_VOLTAGE)
//  {
//    strResult = "PDU_IT_IO_PROG_VOLTAGE";
//  }
//  else if (_ePduItemType == PDU_IT_IO_BYTEARRAY)
//  {
//    strResult = "PDU_IT_IO_BYTEARRAY";
//  }
//  else if (_ePduItemType == PDU_IT_IO_FILTER)
//  {
//    strResult = "PDU_IT_IO_FILTER";
//  }
//  else if (_ePduItemType == PDU_IT_IO_EVENT_QUEUE_PROPERTY)
//  {
//    strResult = "PDU_IT_IO_EVENT_QUEUE_PROPERTY";
//  }
//  else if (_ePduItemType == PDU_IT_RSC_STATUS)
//  {
//    strResult = "PDU_IT_RSC_STATUS";
//  }
//  else if (_ePduItemType == PDU_IT_PARAM)
//  {
//    strResult = "PDU_IT_PARAM";
//  }
//  else if (_ePduItemType == PDU_IT_RSC_ID)
//  {
//    strResult = "PDU_IT_RSC_ID";
//  }
//  else if (_ePduItemType == PDU_IT_RSC_CONFLICT)
//  {
//    strResult = "PDU_IT_RSC_CONFLICT";
//  }
//  else if (_ePduItemType == PDU_IT_MODULE_ID)
//  {
//    strResult = "PDU_IT_MODULE_ID";
//  }
//  else if (_ePduItemType == PDU_IT_UNIQUE_RESP_ID_TABLE)
//  {
//    strResult = "PDU_IT_UNIQUE_RESP_ID_TABLE";
//  }
//  else if (_ePduItemType == PDU_IT_IO_VEHICLE_ID_REQUEST)
//  {
//    strResult = "PDU_IT_IO_VEHICLE_ID_REQUEST";
//  }
//  else if (_ePduItemType == PDU_IT_IO_ENTITY_ADDRESS)
//  {
//    strResult = "PDU_IT_IO_ENTITY_ADDRESS";
//  }
//  else if (_ePduItemType == PDU_IT_IO_ENTITY_STATUS)
//  {
//    strResult = "PDU_IT_IO_ENTITY_STATUS";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_UNUM8_ARY)
//  {
//    strResult = "PDU_I2S_IT_UNUM8_ARY";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_UNUM32_ARY)
//  {
//    strResult = "PDU_I2S_IT_UNUM32_ARY";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_CHAR8_ARY)
//  {
//    strResult = "PDU_I2S_IT_CHAR8_ARY";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_IO_PROG_VOLTAGE_DATA)
//  {
//    strResult = "PDU_I2S_IT_IO_PROG_VOLTAGE_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_IO_BYTEARRAY_DATA)
//  {
//    strResult = "PDU_I2S_IT_IO_BYTEARRAY_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_IO_FILTER_LIST)
//  {
//    strResult = "PDU_I2S_IT_IO_FILTER_LIST";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_IO_FILTER_LIST_DATA)
//  {
//    strResult = "PDU_I2S_IT_IO_FILTER_LIST_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_RSC_STATUS_DATA)
//  {
//    strResult = "PDU_I2S_IT_RSC_STATUS_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_FLAG)
//  {
//    strResult = "PDU_I2S_IT_FLAG";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_EXTRA_INFO)
//  {
//    strResult = "PDU_I2S_IT_EXTRA_INFO";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_RSC_ID_ITEM_DATA)
//  {
//    strResult = "PDU_I2S_IT_RSC_ID_ITEM_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_RSC_CONFLICT_DATA)
//  {
//    strResult = "PDU_I2S_IT_RSC_CONFLICT_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_MODULE_DATA)
//  {
//    strResult = "PDU_I2S_IT_MODULE_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_COP_CTRL)
//  {
//    strResult = "PDU_I2S_IT_COP_CTRL";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_EXP_RESP_DATA)
//  {
//    strResult = "PDU_I2S_IT_EXP_RESP_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_RSC_DATA)
//  {
//    strResult = "PDU_I2S_IT_RSC_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_PIN_DATA)
//  {
//    strResult = "PDU_I2S_IT_PIN_DATA";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_RESOURCE_TABLE_ENTRY)
//  {
//    strResult = "PDU_I2S_IT_RESOURCE_TABLE_ENTRY";
//  }
//  else if (_ePduItemType == PDU_I2S_IT_ECU_UNIQUE_RESP_DATA)
//  {
//    strResult = "PDU_I2S_IT_ECU_UNIQUE_RESP_DATA";
//  }
//
//  return strResult;
//}

/**
 * @brief   - Converts input string to PDU-Status (T_PDU_STATUS).
 *
 *@param   - IN   - _strInput - Input string to convert.
 *
 *@return  - PDU-Status (T_PDU_STATUS).
 */
//
//T_PDU_STATUS StringHelper::StringToPduStatus(const std::string& _strInput)
//{
//  T_PDU_STATUS eResult;
//
//  if (_strInput == std::string("PDU_COPST_IDLE"))
//  {
//    eResult = PDU_COPST_IDLE;
//  }
//  else if (_strInput == std::string("PDU_COPST_EXECUTING"))
//  {
//    eResult = PDU_COPST_EXECUTING;
//  }
//  else if (_strInput == std::string("PDU_COPST_FINISHED"))
//  {
//    eResult = PDU_COPST_FINISHED;
//  }
//  else if (_strInput == std::string("PDU_COPST_CANCELLED"))
//  {
//    eResult = PDU_COPST_CANCELLED;
//  }
//  else if (_strInput == std::string("PDU_COPST_WAITING"))
//  {
//    eResult = PDU_COPST_WAITING;
//  }
//  else if (_strInput == std::string("PDU_CLLST_OFFLINE"))
//  {
//    eResult = PDU_CLLST_OFFLINE;
//  }
//  else if (_strInput == std::string("PDU_CLLST_ONLINE"))
//  {
//    eResult = PDU_CLLST_ONLINE;
//  }
//  else if (_strInput == std::string("PDU_CLLST_COMM_STARTED"))
//  {
//    eResult = PDU_CLLST_COMM_STARTED;
//  }
//  else if (_strInput == std::string("PDU_MODST_READY"))
//  {
//    eResult = PDU_MODST_READY;
//  }
//  else if (_strInput == std::string("PDU_MODST_NOT_READY"))
//  {
//    eResult = PDU_MODST_NOT_READY;
//  }
//  else if (_strInput == std::string("PDU_MODST_NOT_AVAIL"))
//  {
//    eResult = PDU_MODST_NOT_AVAIL;
//  }
//  else if (_strInput == std::string("PDU_MODST_AVAIL"))
//  {
//    eResult = PDU_MODST_AVAIL;
//  }
//  else
//  {
//    throw std::string("PDU-Status unknown for :'" + _strInput + "'.");
//  }
//
//  return eResult;
//}
//
//std::string StringHelper::PduStatusToString(T_PDU_STATUS _ePduStatus)
//{
//  std::string strResult;
//
//  if (_ePduStatus == PDU_COPST_IDLE)
//  {
//    strResult = "PDU_COPST_IDLE";
//  }
//  else if (_ePduStatus == PDU_COPST_EXECUTING)
//  {
//    strResult = "PDU_COPST_EXECUTING";
//  }
//  else if (_ePduStatus == PDU_COPST_FINISHED)
//  {
//    strResult = "PDU_COPST_FINISHED";
//  }
//  else if (_ePduStatus == PDU_COPST_CANCELLED)
//  {
//    strResult = "PDU_COPST_CANCELLED";
//  }
//  else if (_ePduStatus == PDU_COPST_WAITING)
//  {
//    strResult = "PDU_COPST_WAITING";
//  }
//  else if (_ePduStatus == PDU_CLLST_OFFLINE)
//  {
//    strResult = "PDU_CLLST_OFFLINE";
//  }
//  else if (_ePduStatus == PDU_CLLST_ONLINE)
//  {
//    strResult = "PDU_CLLST_ONLINE";
//  }
//  else if (_ePduStatus == PDU_CLLST_COMM_STARTED)
//  {
//    strResult = "PDU_CLLST_COMM_STARTED";
//  }
//  else if (_ePduStatus == PDU_MODST_READY)
//  {
//    strResult = "PDU_MODST_READY";
//  }
//  else if (_ePduStatus == PDU_MODST_NOT_READY)
//  {
//    strResult = "PDU_MODST_NOT_READY";
//  }
//  else if (_ePduStatus == PDU_MODST_NOT_AVAIL)
//  {
//    strResult = "PDU_MODST_NOT_AVAIL";
//  }
//  else if (_ePduStatus == PDU_MODST_AVAIL)
//  {
//    strResult = "PDU_MODST_AVAIL";
//  }
//  else
//  {
//    throw std::string("StringHelper::PduStatusToString - PDU-Status unknown.");
//  }
//
//  return strResult;
//}

/**
 * @brief   - Converts input string to PDU-Status (T_PDU_STATUS).
 *
 *@param   - IN   - _strInput - Input string to convert.
 *
 *@return  - PDU-Status (T_PDU_STATUS).
 */

//
//T_PDU_FILTER StringHelper::StringToPduFilter(const std::string& _strInput)
//{
//  T_PDU_FILTER eResult;
//
//  if (_strInput == std::string("PDU_FLT_PASS"))
//  {
//    eResult = PDU_FLT_PASS;
//  }
//  else if (_strInput == std::string("PDU_FLT_BLOCK"))
//  {
//    eResult = PDU_FLT_BLOCK;
//  }
//  else if (_strInput == std::string("PDU_FLT_PASS_UUDT"))
//  {
//    eResult = PDU_FLT_PASS_UUDT;
//  }
//  else if (_strInput == std::string("PDU_FLT_BLOCK_UUDT"))
//  {
//    eResult = PDU_FLT_BLOCK_UUDT;
//  }
//  else
//  {
//    throw std::string("PDU filter unknown for :'" + _strInput + "'.");
//  }
//
//  return eResult;
//}
//
//std::string StringHelper::PduFilterToString(T_PDU_FILTER _ePduStatus)
//{
//  std::string strResult;
//
//  if (_ePduStatus == PDU_FLT_PASS)
//  {
//    strResult = "PDU_FLT_PASS";
//  }
//  else if (_ePduStatus == PDU_FLT_BLOCK)
//  {
//    strResult = "PDU_FLT_BLOCK";
//  }
//  else
//  {
//    throw std::string("StringHelper::PduFilterToString - PDU-filter unknown.");
//  }
//
//  return strResult;
//}
//
//
//T_PDU_ERR_EVT StringHelper::StringToEventError(const std::string& _strInput)
//{
//  T_PDU_ERR_EVT eResult;
//  if (_strInput == std::string("PDU_ERR_EVT_NOERROR"))
//  {
//    eResult = PDU_ERR_EVT_NOERROR;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_FRAME_STRUCT"))
//  {
//    eResult = PDU_ERR_EVT_FRAME_STRUCT;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_TX_ERROR"))
//  {
//    eResult = PDU_ERR_EVT_TX_ERROR;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_TESTER_PRESENT_ERROR"))
//  {
//    eResult = PDU_ERR_EVT_TESTER_PRESENT_ERROR;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_RX_TIMEOUT"))
//  {
//    eResult = PDU_ERR_EVT_RX_TIMEOUT;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_RX_ERROR"))
//  {
//    eResult = PDU_ERR_EVT_RX_ERROR;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_PROT_ERR"))
//  {
//    eResult = PDU_ERR_EVT_PROT_ERR;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_LOST_COMM_TO_VCI"))
//  {
//    eResult = PDU_ERR_EVT_LOST_COMM_TO_VCI;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_VCI_HARDWARE_FAULT"))
//  {
//    eResult = PDU_ERR_EVT_VCI_HARDWARE_FAULT;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_INIT_ERROR"))
//  {
//    eResult = PDU_ERR_EVT_INIT_ERROR;
//  }
//  else if (_strInput == std::string("PDU_ERR_EVT_RSC_LOCKED"))
//  {
//    eResult = PDU_ERR_EVT_RSC_LOCKED;
//  }
//  else
//  {
//    throw std::string("Event error unknown for :'" + _strInput + "'.");
//  }
//
//  return eResult;
//}
//
//std::string StringHelper::EventErrorToString(T_PDU_ERR_EVT& _eEventError)
//{
//  std::string strResult;
//
//  if (_eEventError == PDU_ERR_EVT_NOERROR)
//  {
//    strResult = "PDU_ERR_EVT_NOERROR";
//  }
//  else if (_eEventError == PDU_ERR_EVT_FRAME_STRUCT)
//  {
//    strResult = "PDU_ERR_EVT_FRAME_STRUCT";
//  }
//  else if (_eEventError == PDU_ERR_EVT_TX_ERROR)
//  {
//    strResult = "PDU_ERR_EVT_TX_ERROR";
//  }
//  else if (_eEventError == PDU_ERR_EVT_TESTER_PRESENT_ERROR)
//  {
//    strResult = "PDU_ERR_EVT_TESTER_PRESENT_ERROR";
//  }
//  else if (_eEventError == PDU_ERR_EVT_RX_TIMEOUT)
//  {
//    strResult = "PDU_ERR_EVT_RX_TIMEOUT";
//  }
//  else if (_eEventError == PDU_ERR_EVT_RX_ERROR)
//  {
//    strResult = "PDU_ERR_EVT_RX_ERROR";
//  }
//  else if (_eEventError == PDU_ERR_EVT_PROT_ERR)
//  {
//    strResult = "PDU_ERR_EVT_PROT_ERR";
//  }
//  else if (_eEventError == PDU_ERR_EVT_LOST_COMM_TO_VCI)
//  {
//    strResult = "PDU_ERR_EVT_LOST_COMM_TO_VCI";
//  }
//  else if (_eEventError == PDU_ERR_EVT_VCI_HARDWARE_FAULT)
//  {
//    strResult = "PDU_ERR_EVT_VCI_HARDWARE_FAULT";
//  }
//  else if (_eEventError == PDU_ERR_EVT_INIT_ERROR)
//  {
//    strResult = "PDU_ERR_EVT_INIT_ERROR";
//  }
//  else if (_eEventError == PDU_ERR_EVT_RSC_LOCKED)
//  {
//    strResult = "PDU_ERR_EVT_RSC_LOCKED";
//  }
//  else
//  {
//    throw std::string("EventErrorToString - event-error unknown.");
//  }
//
//  return strResult;
//}
//
//
//std::string StringHelper::EventItemToString(const PDU_EVENT_ITEM* const _pEventItem)
//{
//  std::stringstream strim;
//  if (_pEventItem != nullptr)
//  {
//    strim << "PDU_EVENT_ITEM : " << StringHelper::DataItemTypeToString(_pEventItem->ItemType);
//
//
//    switch (_pEventItem->ItemType)
//    {
//    case PDU_IT_STATUS:
//      {
//        T_PDU_STATUS state = *(reinterpret_cast<T_PDU_STATUS*>(_pEventItem->pData));
//        strim << " - " << StringHelper::PduStatusToString(state);
//
//        break;
//      }
//    case PDU_IT_RESULT:
//      {
//        strim << " DataBytes(";
//        strim.setf(std::ios::hex, std::ios::basefield);
//        strim.setf(std::ios::showbase);
//
//        PDU_RESULT_DATA result = *(reinterpret_cast<PDU_RESULT_DATA*>(_pEventItem->pData));
//        std::for_each(
//          &result.pDataBytes[0],
//          &result.pDataBytes[result.NumDataBytes],
//          [&](UNUM8 value)
//          {
//            strim << int(value) << " ";
//          }
//        );
//        strim << ") RxFlag(";
//
//        std::for_each(
//          &result.RxFlag.pFlagData[0],
//          &result.RxFlag.pFlagData[result.RxFlag.NumFlagBytes],
//          [&](UNUM8 value)
//          {
//            strim << int(value) << " ";
//          }
//        );
//        strim << ")";
//        break;
//      }
//    case PDU_IT_ERROR:
//      {
//        PDU_ERROR_DATA error = *(reinterpret_cast<PDU_ERROR_DATA*>(_pEventItem->pData));
//        strim << " - " << StringHelper::EventErrorToString(error.ErrorCodeId);
//
//        if (error.ExtraErrorInfoId != PDU_ID_UNDEF)
//        {
//          strim << " ExtraErrorInfoId - " << error.ExtraErrorInfoId;
//        }
//        break;
//      }
//    case PDU_IT_INFO:
//      {
//        break;
//      }
//    }
//    strim << ". hCop '" << StringHelper::HandlerToString(_pEventItem->hCop) << "'.";
//  }
//  else
//  {
//    strim << "PDU_EVENT_ITEM is NULL";
//  }
//  return strim.str();
//}
//
//std::string StringHelper::ResourceStatusToString(UNUM32 _strResourceStatus)
//{
//  std::stringstream strResult;
//  strResult << "Usage Status :" << ((_strResourceStatus & 1) ? "1" : "0");
//  strResult << " Availability Status :" << ((_strResourceStatus & (1 << 1)) ? "1" : "0");
//  strResult << " Transmit Queue Lock Status :" << ((_strResourceStatus & (1 << 2)) ? "1" : "0");
//  strResult << " Physical ComParam Lock Status :" << ((_strResourceStatus & (1 << 3)) ? "1" : "0");
//
//  return strResult.str();
//}
//
//std::string StringHelper::HandlerToString(const UNUM32& _unHandler)
//{
//  std::stringstream strim;
//  if (_unHandler == PDU_HANDLE_UNDEF)
//  {
//    strim << "PDU_HANDLE_UNDEF";
//  }
//  else
//  {
//    strim << _unHandler;
//  }
//
//  return strim.str();
//}
//
//std::string StringHelper::UniqueRespIdTableToString(
//  const PDU_UNIQUE_RESP_ID_TABLE_ITEM* _pUniqueRespIdTable)
//{
//  std::stringstream strim;
//  strim << "PDU_UNIQUE_RESP_ID_TABLE_ITEM : NumEntries - " <<
//    _pUniqueRespIdTable->NumEntries << std::endl;
//
//  for (size_t tableCount = 0; tableCount < _pUniqueRespIdTable->NumEntries; tableCount++)
//  {
//    strim << "\tTable " << tableCount + 1;
//    PDU_ECU_UNIQUE_RESP_DATA table = _pUniqueRespIdTable->pUniqueData[tableCount];
//    strim << ", UniqueRespIdentifier " << table.UniqueRespIdentifier << std::endl;
//    for (size_t itemCount = 0; itemCount < table.NumParamItems; itemCount++)
//    {
//      PDU_PARAM_ITEM paramItem = table.pParams[itemCount];
//      strim << "ComParamId " << paramItem.ComParamId <<
//        ", ComParamDataType " << ComParamDataTypeToString(paramItem.ComParamDataType) <<
//        ", ComParamData " << StringHelper::ComParamToString(paramItem) << std::endl;
//    }
//  }
//
//  return strim.str();
//}
//
//T_PDU_PC StringHelper::StringToComparamClass(std::string _strComParamClassr)
//{
//  T_PDU_PC eResult;
//  if (_strComParamClassr == "PDU_PC_TIMING")
//  {
//    eResult = PDU_PC_TIMING;
//  }
//  else if (_strComParamClassr == "PDU_PC_INIT")
//  {
//    eResult = PDU_PC_INIT;
//  }
//  else if (_strComParamClassr == "PDU_PC_COM")
//  {
//    eResult = PDU_PC_COM;
//  }
//  else if (_strComParamClassr == "PDU_PC_ERRHDL")
//  {
//    eResult = PDU_PC_ERRHDL;
//  }
//  else if (_strComParamClassr == "PDU_PC_BUSTYPE")
//  {
//    eResult = PDU_PC_BUSTYPE;
//  }
//  else if (_strComParamClassr == "PDU_PC_UNIQUE_ID")
//  {
//    eResult = PDU_PC_UNIQUE_ID;
//  }
//  else if (_strComParamClassr == "PDU_PC_TESTER_PRESENT")
//  {
//    eResult = PDU_PC_TESTER_PRESENT;
//  }
//  else
//  {
//    eResult = PDU_PC_UNDEFINED;
//  }
//
//  return eResult;
//}
