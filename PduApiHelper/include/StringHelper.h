#ifndef STRING_HELPER_H
#define STRING_HELPER_H

#include <limits>
#include <string>
#include <list>
#include <sstream>
#include <vector>

//#include <boost/algorithm/string/trim.hpp>
//#include <boost/algorithm/string/split.hpp>
//
//#include "PDU_Standard.h"
/**
 *@author ako
 *
 *@copyright 2015 by ACTIA I + ME GmbH
 */
#ifdef max
#pragma push_macro("max")
#undef max
#define _restore_max_
#endif

//struct PDU_STATUS_MAP_ELEMENT_TYPE
//{
//  T_PDU_ERROR error;
//  char* name;
//};
//
//static PDU_STATUS_MAP_ELEMENT_TYPE l_pduErrorMap[] =
//{
//  {
//    PDU_STATUS_NOERROR, "PDU_STATUS_NOERROR"
//  },
//  {
//    PDU_ERR_FCT_FAILED, "PDU_ERR_FCT_FAILED"
//  },
//  {
//    PDU_ERR_DEVICE_NOT_CONNECTED, "PDU_ERR_DEVICE_NOT_CONNECTED"
//  },
//  {
//    PDU_ERR_COMM_PC_TO_VCI_FAILED, "PDU_ERR_COMM_PC_TO_VCI_FAILED"
//  },
//  {
//    PDU_ERR_PDUAPI_NOT_CONSTRUCTED, "PDU_ERR_PDUAPI_NOT_CONSTRUCTED"
//  },
//  {
//    PDU_ERR_SHARING_VIOLATION, "PDU_ERR_SHARING_VIOLATION"
//  },
//  {
//    PDU_ERR_RESOURCE_BUSY, "PDU_ERR_RESOURCE_BUSY"
//  },
//  {
//    PDU_ERR_RESOURCE_TABLE_CHANGED, "PDU_ERR_RESOURCE_TABLE_CHANGED"
//  },
//  {
//    PDU_ERR_RESOURCE_ERROR, "PDU_ERR_RESOURCE_ERROR"
//  },
//  {
//    PDU_ERR_CLL_NOT_CONNECTED, "PDU_ERR_CLL_NOT_CONNECTED"
//  },
//  {
//    PDU_ERR_CLL_NOT_STARTED, "PDU_ERR_CLL_NOT_STARTED"
//  },
//  {
//    PDU_ERR_INVALID_PARAMETERS, "PDU_ERR_INVALID_PARAMETERS"
//  },
//  {
//    PDU_ERR_INVALID_HANDLE, "PDU_ERR_INVALID_HANDLE"
//  },
//  {
//    PDU_ERR_VALUE_NOT_SUPPORTED, "PDU_ERR_VALUE_NOT_SUPPORTED"
//  },
//  {
//    PDU_ERR_ID_NOT_SUPPORTED, "PDU_ERR_ID_NOT_SUPPORTED"
//  },
//  {
//    PDU_ERR_COMPARAM_NOT_SUPPORTED, "PDU_ERR_COMPARAM_NOT_SUPPORTED"
//  },
//  {
//    PDU_ERR_COMPARAM_LOCKED, "PDU_ERR_COMPARAM_LOCKED"
//  },
//  {
//    PDU_ERR_TX_QUEUE_FULL, "PDU_ERR_TX_QUEUE_FULL"
//  },
//  {
//    PDU_ERR_EVENT_QUEUE_EMPTY, "PDU_ERR_EVENT_QUEUE_EMPTY"
//  },
//  {
//    PDU_ERR_VOLTAGE_NOT_SUPPORTED, "PDU_ERR_VOLTAGE_NOT_SUPPORTED"
//  },
//  {
//    PDU_ERR_MUX_RSC_NOT_SUPPORTED, "PDU_ERR_MUX_RSC_NOT_SUPPORTED"
//  },
//  {
//    PDU_ERR_CABLE_UNKNOWN, "PDU_ERR_CABLE_UNKNOWN"
//  },
//  {
//    PDU_ERR_NO_CABLE_DETECTED, "PDU_ERR_NO_CABLE_DETECTED"
//  },
//  {
//    PDU_ERR_CLL_CONNECTED, "PDU_ERR_CLL_CONNECTED"
//  },
//  {
//    PDU_ERR_TEMPPARAM_NOT_ALLOWED, "PDU_ERR_TEMPPARAM_NOT_ALLOWED"
//  },
//  {
//    PDU_ERR_RSC_LOCKED, "PDU_ERR_RSC_LOCKED"
//  },
//  {
//    PDU_ERR_RSC_LOCKED_BY_OTHER_CLL, "PDU_ERR_RSC_LOCKED_BY_OTHER_CLL"
//  },
//  {
//    PDU_ERR_RSC_NOT_LOCKED, "PDU_ERR_RSC_NOT_LOCKED"
//  },
//  {
//    PDU_ERR_MODULE_NOT_CONNECTED, "PDU_ERR_MODULE_NOT_CONNECTED"
//  },
//  {
//    PDU_ERR_API_SW_OUT_OF_DATE, "PDU_ERR_API_SW_OUT_OF_DATE"
//  },
//  {
//    PDU_ERR_MODULE_FW_OUT_OF_DATE, "PDU_ERR_MODULE_FW_OUT_OF_DATE"
//  },
//  {
//    PDU_ERR_DOIP_RESPONSE_TIMEOUT, "PDU_ERR_DOIP_RESPONSE_TIMEOUT"
//  },
//  {
//    PDU_ERR_IP_PROTOCOL_NOT_SUPPORTED, "PDU_ERR_IP_PROTOCOL_NOT_SUPPORTED"
//  },
//  {
//    PDU_ERR_DOIP_ROUTING_ACTIVATION_FAILED, "PDU_ERR_DOIP_ROUTING_ACTIVATION_FAILED"
//  },
//  {
//    PDU_ERR_DOIP_ROUTING_ACTIVATION_AUTHENTICATION_FAILED,
//    "PDU_ERR_DOIP_ROUTING_ACTIVATION_AUTHENTICATION_FAILED"
//  },
//  {
//    PDU_ERR_DOIP_AMBIGUOUS_LOGICAL_ADDRESS, "PDU_ERR_DOIP_AMBIGUOUS_LOGICAL_ADDRESS"
//  },
//  {
//    PDU_ERR_NO_VALID_LICENSE, "PDU_ERR_NO_VALID_LICENSE"
//  },
//  {
//    PDU_ERR_FCT_FAILED, NULL
//  }
//};
//
//namespace dpduapi
//{
//  extern const char* PDU_IOCTL_RESET;
//  extern const char* PDU_IOCTL_CLEAR_TX_QUEUE;
//  extern const char* PDU_IOCTL_SUSPEND_TX_QUEUE;
//  extern const char* PDU_IOCTL_RESUME_TX_QUEUE;
//  extern const char* PDU_IOCTL_CLEAR_RX_QUEUE;
//  extern const char* PDU_IOCTL_READ_VBATT;
//  extern const char* PDU_IOCTL_SET_PROG_VOLTAGE;
//  extern const char* PDU_IOCTL_READ_PROG_VOLTAGE;
//  extern const char* PDU_IOCTL_GENERIC;
//  extern const char* PDU_IOCTL_SET_BUFFER_SIZE;
//  extern const char* PDU_IOCTL_START_MSG_FILTER;
//  extern const char* PDU_IOCTL_STOP_MSG_FILTER;
//  extern const char* PDU_IOCTL_CLEAR_MSG_FILTER;
//  extern const char* PDU_IOCTL_SET_EVENT_QUEUE_PROPERTIES;
//  extern const char* PDU_IOCTL_GET_CABLE_ID;
//  extern const char* PDU_IOCTL_SEND_BREAK;
//  extern const char* PDU_IOCTL_READ_IGNITION_SENSE_STATE;
//  extern const char* PDU_IOCTL_SET_ETH_SWITCH_STATE;
//  extern const char* PDU_IOCTL_FORCE_STMIN;
//}
//
class StringHelper
{
public:
  StringHelper();
  virtual ~StringHelper();
//
//  static bool IsNull(std::string _strInInputSting);
//  static bool StringToBool(std::string _strInInputSting);
//  static bool PduApiResultString(T_PDU_ERROR p_value, std::string& p_outValue);
//
//  static T_PDU_PT StringToComParamDataType(std::string _strInput);
//  static std::string ComParamDataTypeToString(const T_PDU_PT _eComParamDataType);
//  static std::string ComParamToString(const PDU_PARAM_ITEM& _comParam);
//
//  static T_PDU_IT    StringToDataItemType(std::string _strInput);
//  static std::string DataItemTypeToString(T_PDU_IT _ePduItemType);
//
//  static T_PDU_STATUS StringToPduStatus(const std::string& _strInput);
//  static std::string  PduStatusToString(T_PDU_STATUS _ePduStatus);
//
//  static T_PDU_FILTER StringToPduFilter(const std::string& _strInput);
//  static std::string  PduFilterToString(T_PDU_FILTER _ePduStatus);
//
//  static T_PDU_ERR_EVT StringToEventError(const std::string& _strInput);
//  static std::string   EventErrorToString(T_PDU_ERR_EVT& _eEventError);
//
//  static T_PDU_PC    StringToComparamClass(std::string _strComParamClassr);
//  static std::string HandlerToString(const UNUM32& _unHandler);
//
//  static std::string UniqueRespIdTableToString(
//    const PDU_UNIQUE_RESP_ID_TABLE_ITEM* _pUniqueRespIdTable);
//  static std::string EventItemToString(const PDU_EVENT_ITEM* const _pEventItem);
//
//  static std::string ResourceStatusToString(UNUM32 _strResourceStatus);
//
  template <typename DataType>
  static DataType StringToNumber(const std::string& _strInput);
//  template <typename DataType>
//  void static StringToNumberList(std::list<DataType>* _outputList, const std::string& _strInput);
};
//
//
//**
// * @brief   - The function converts input string to 'DataType' data type.
// *
// *@param   - IN   - _strInput - Input string to convert.
// *
// *@return  - Converted value
// */
template <typename DataType>
DataType StringHelper::StringToNumber(const std::string& _strInput)
{
  long long lResult;
  auto minValue = std::numeric_limits<DataType>::min;
  try
  {
    if (minValue < 0)
    {
      lResult = stoll(_strInput, nullptr, 0);
    }
    else
    {
      lResult =  stoull(_strInput, nullptr, 0);
    }

  }
  catch (std::invalid_argument&)
  {
    throw std::string("Error in StringToNumber. Invalid input string '" + _strInput + "'.");
  }
  catch (std::out_of_range&)
  {
    throw std::string("Error in StringToNumber. Input string out of range '" + _strInput + "'.");
  }

  DataType maxValue = std::numeric_limits<DataType>::max();

  if (lResult > maxValue)
  {
    throw std::string("Error in 'StringToNumber'. Value :'"+ _strInput +
      "' is greater than data-type Max.");
  }

  return static_cast<DataType>(lResult);
}
//
///**
// * @brief   - The function converts input string to 'DataType'-Liste.
// *
// *@param   - OUT   - _outputList - Liste to output
// *
// *@param   - IN   - _strInput - Input string to convert.
// */
//template <typename DataType>
//void StringHelper::StringToNumberList(
//  std::list<DataType>* _outputList,
//  const std::string& _strInput)
//{
//  const char* DELIMS = " ,;";
//  std::vector<std::string> splitVector;
//
//  boost::algorithm::split(splitVector, _strInput, boost::is_any_of(DELIMS));
//
//  for (auto iterator = splitVector.begin(); iterator != splitVector.end(); ++iterator)
//  {
//    DataType ulResult = StringHelper::StringToNumber<DataType>(*iterator);
//    _outputList->push_back(ulResult);
//  }
//}
//
//class ToStr
//{
//public:
//  template<class T>
//  ToStr& operator<< (const T& arg)
//  {
//    m_stream << arg;
//    return *this;
//  }
//  operator std::string() const
//  {
//    return m_stream.str();
//  }
//
//protected:
//  std::stringstream m_stream;
//};
#endif
