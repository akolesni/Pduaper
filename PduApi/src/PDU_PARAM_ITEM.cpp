#include "stdafx.h"
#include "pdu_api.h"
#include <string>

/**
 *@brief - Constructor
 */
native_api::PDU_PARAM_ITEM::PDU_PARAM_ITEM()
{
  this->ItemType         = PDU_IT_PARAM;
  this->ComParamId       = PDU_ID_UNDEF;
  this->ComParamDataType = PDU_PT_UNDEFINED;
  this->ComParamClass    = PDU_PC_UNDEFINED;
  this->pComParamData    = nullptr;
}

native_api::PDU_PARAM_ITEM::PDU_PARAM_ITEM(UNUM32 _paramId, T_PDU_PC _paramClass, UNUM32 _value)
{
  this->ItemType         = PDU_IT_PARAM;
  this->ComParamId       = _paramId;
  this->ComParamDataType = PDU_PT_UNUM32;
  this->ComParamClass    = _paramClass;
  this->pComParamData    = new UNUM32(_value);
}

/**
 *@brief - Copy constructor
 */
native_api::PDU_PARAM_ITEM::PDU_PARAM_ITEM(const PDU_PARAM_ITEM& _paramItem)
{
    //throw std::string("Copy constructor not implemented");
  this->ComParamClass    = _paramItem.ComParamClass;
  this->ComParamDataType = _paramItem.ComParamDataType;
  this->ComParamId       = _paramItem.ComParamId;
  this->ItemType         = _paramItem.ItemType;

  switch (this->ComParamDataType)
  {
    case PDU_PT_UNUM8:
    {
      UNUM8* value = reinterpret_cast<UNUM8*>(_paramItem.pComParamData);
      this->pComParamData = new UNUM8(*value);
      break;
    }
    case PDU_PT_SNUM8:
    {
      SNUM8* value = reinterpret_cast<SNUM8*>(_paramItem.pComParamData);
      this->pComParamData = new SNUM8(*value);
      break;
    }
    case PDU_PT_UNUM16:
    {
      UNUM16* value = reinterpret_cast<UNUM16*>(_paramItem.pComParamData);
      this->pComParamData = new UNUM16(*value);
      break;
    }
    case PDU_PT_SNUM16:
    {
      SNUM16* value = reinterpret_cast<SNUM16*>(_paramItem.pComParamData);
      this->pComParamData = new SNUM16(*value);
      break;
    }
    case PDU_PT_UNUM32:
    {
      UNUM32* value = reinterpret_cast<UNUM32*>(_paramItem.pComParamData);
      this->pComParamData = new UNUM32(*value);
      break;
    }
    case PDU_PT_SNUM32:
    {
      SNUM32* value = reinterpret_cast<SNUM32*>(_paramItem.pComParamData);
      this->pComParamData = new SNUM32(*value);
      break;
    }
    case PDU_PT_BYTEFIELD:
    {
      // TODO copyconstructor for PDU_PARAM_BYTEFIELD_DATA
      PDU_PARAM_BYTEFIELD_DATA* value = reinterpret_cast<PDU_PARAM_BYTEFIELD_DATA*>(_paramItem.pComParamData);
      PDU_PARAM_BYTEFIELD_DATA* copyData = new PDU_PARAM_BYTEFIELD_DATA;

      copyData->ParamMaxLen = value->ParamMaxLen;
      copyData->ParamActLen = value->ParamActLen;
      
      if (value->ParamActLen > 0)
      {
        UNUM8* pDataCopy = new UNUM8[value->ParamActLen];
        std::copy(&value->pDataArray[0], &value->pDataArray[value->ParamActLen], &pDataCopy[0]);
        copyData->pDataArray = pDataCopy;
      }
      else
      {
        copyData->pDataArray = nullptr;
      }
      this->pComParamData = copyData;
      break;
    }
    case PDU_PT_LONGFIELD:
    {
      // TODO copyconstructor for PDU_PT_LONGFIELD
      PDU_PARAM_LONGFIELD_DATA* value = reinterpret_cast<PDU_PARAM_LONGFIELD_DATA*>(_paramItem.pComParamData);
      PDU_PARAM_LONGFIELD_DATA* copyData = new PDU_PARAM_LONGFIELD_DATA;

      copyData->ParamMaxLen = value->ParamMaxLen;
      copyData->ParamActLen = value->ParamActLen;
      
      if (value->ParamActLen > 0)
      {
        UNUM32* pDataCopy = new UNUM32[value->ParamActLen];
        std::copy(&(value->pDataArray[0]), &(value->pDataArray[value->ParamActLen]), &pDataCopy[0]);
        copyData->pDataArray = pDataCopy;
      }
      else
      {
        copyData->pDataArray = nullptr;
      }
      this->pComParamData = copyData;
      break;
    }
    case PDU_PT_STRUCTFIELD:
    {
      // TODO copyconstructor for PDU_PT_STRUCTFIELD
      PDU_PARAM_STRUCTFIELD_DATA* value = reinterpret_cast<PDU_PARAM_STRUCTFIELD_DATA*>(_paramItem.pComParamData);
      PDU_PARAM_STRUCTFIELD_DATA* copyData = new PDU_PARAM_STRUCTFIELD_DATA;

      copyData->ComParamStructType = value->ComParamStructType;
      copyData->ParamMaxEntries    = value->ParamMaxEntries;
      copyData->ParamActEntries    = value->ParamActEntries;

      if (value->ParamActEntries > 0)
      {
        if (value->ComParamStructType == PDU_CPST_SESSION_TIMING)
        {
          PDU_PARAM_STRUCT_SESS_TIMING* pSessTimingCopy = new PDU_PARAM_STRUCT_SESS_TIMING[value->ParamActEntries];
          PDU_PARAM_STRUCT_SESS_TIMING* pStructArray = reinterpret_cast<PDU_PARAM_STRUCT_SESS_TIMING*>(value->pStructArray);
          std::copy(&(pStructArray[0]), &(pStructArray[value->ParamActEntries]), &pSessTimingCopy[0]);
          copyData->pStructArray = pSessTimingCopy;
        }
        else if (value->ComParamStructType == PDU_CPST_ACCESS_TIMING)
        {
          PDU_PARAM_STRUCT_ACCESS_TIMING* pAccessTimingCopy = new PDU_PARAM_STRUCT_ACCESS_TIMING[value->ParamActEntries];
          PDU_PARAM_STRUCT_ACCESS_TIMING* pStructArray = reinterpret_cast<PDU_PARAM_STRUCT_ACCESS_TIMING*>(value->pStructArray);
          std::copy(&(pStructArray[0]), &(pStructArray[value->ParamActEntries]), &pAccessTimingCopy[0]);
          copyData->pStructArray = pAccessTimingCopy;
        }
        else
        {
          throw std::string("Error in ComParamManager::CopyParamItem() : ComParamStructType unknown.");
        }
      }
      else
      {
        copyData->pStructArray = nullptr;
      }
      this->pComParamData = copyData;
      break;
    }

    case PDU_PT_UNDEFINED:
    {
      this->pComParamData = nullptr;
    }
    break;
  }
}

/**
 *@brief - Destructor
 */
native_api::PDU_PARAM_ITEM::~PDU_PARAM_ITEM()
{
  this->DeleteComParamData();
}

/**
 *@brief - Assignment operator
 */
native_api::PDU_PARAM_ITEM& native_api::PDU_PARAM_ITEM::operator=(const PDU_PARAM_ITEM& _paramItem)
{
  this->ComParamClass    = _paramItem.ComParamClass;
  this->ComParamDataType = _paramItem.ComParamDataType;
  this->ComParamId       = _paramItem.ComParamId;
  this->ItemType         = _paramItem.ItemType;

  switch (this->ComParamDataType)
  {
    case PDU_PT_UNUM8:
    {
      UNUM8* value = reinterpret_cast<UNUM8*>(_paramItem.pComParamData);
      this->pComParamData = new UNUM8(*value);
      break;
    }
    case PDU_PT_SNUM8:
    {
      SNUM8* value = reinterpret_cast<SNUM8*>(_paramItem.pComParamData);
      this->pComParamData = new SNUM8(*value);
      break;
    }
    case PDU_PT_UNUM16:
    {
      UNUM16* value = reinterpret_cast<UNUM16*>(_paramItem.pComParamData);
      this->pComParamData = new UNUM16(*value);
      break;
    }
    case PDU_PT_SNUM16:
    {
      SNUM16* value = reinterpret_cast<SNUM16*>(_paramItem.pComParamData);
      this->pComParamData = new SNUM16(*value);
      break;
    }
    case PDU_PT_UNUM32:
    {
      UNUM32* value = reinterpret_cast<UNUM32*>(_paramItem.pComParamData);
      this->pComParamData = new UNUM32(*value);
      break;
    }
    case PDU_PT_SNUM32:
    {
      SNUM32* value = reinterpret_cast<SNUM32*>(_paramItem.pComParamData);
      this->pComParamData = new SNUM32(*value);
      break;
    }
    case PDU_PT_BYTEFIELD:
    {
      // TODO copyconstructor for PDU_PARAM_BYTEFIELD_DATA
      PDU_PARAM_BYTEFIELD_DATA* value = reinterpret_cast<PDU_PARAM_BYTEFIELD_DATA*>(_paramItem.pComParamData);
      PDU_PARAM_BYTEFIELD_DATA* copyData = new PDU_PARAM_BYTEFIELD_DATA;

      copyData->ParamMaxLen = value->ParamMaxLen;
      copyData->ParamActLen = value->ParamActLen;
      
      if (value->ParamActLen > 0)
      {
        UNUM8* pDataCopy = new UNUM8[value->ParamActLen];
        std::copy(&(value->pDataArray[0]), &(value->pDataArray[value->ParamActLen]), &pDataCopy[0]);
        copyData->pDataArray = pDataCopy;
      }
      else
      {
        copyData->pDataArray = nullptr;
      }
      this->pComParamData = copyData;
      break;
    }
    case PDU_PT_LONGFIELD:
    {
      // TODO copyconstructor for PDU_PT_LONGFIELD
      PDU_PARAM_LONGFIELD_DATA* value = reinterpret_cast<PDU_PARAM_LONGFIELD_DATA*>(_paramItem.pComParamData);
      PDU_PARAM_LONGFIELD_DATA* copyData = new PDU_PARAM_LONGFIELD_DATA;

      copyData->ParamMaxLen = value->ParamMaxLen;
      copyData->ParamActLen = value->ParamActLen;
      
      if (value->ParamActLen > 0)
      {
        UNUM32* pDataCopy = new UNUM32[value->ParamActLen];
        std::copy(&(value->pDataArray[0]), &(value->pDataArray[value->ParamActLen]), &pDataCopy[0]);
        copyData->pDataArray = pDataCopy;
      }
      else
      {
        copyData->pDataArray = nullptr;
      }
      this->pComParamData = copyData;
      break;
    }
    case PDU_PT_STRUCTFIELD:
    {
      // TODO copyconstructor for PDU_PT_STRUCTFIELD
      PDU_PARAM_STRUCTFIELD_DATA* value = reinterpret_cast<PDU_PARAM_STRUCTFIELD_DATA*>(_paramItem.pComParamData);
      PDU_PARAM_STRUCTFIELD_DATA* copyData = new PDU_PARAM_STRUCTFIELD_DATA;

      copyData->ComParamStructType = value->ComParamStructType;
      copyData->ParamMaxEntries    = value->ParamMaxEntries;
      copyData->ParamActEntries    = value->ParamActEntries;

      if (value->ParamActEntries > 0)
      {
        if (value->ComParamStructType == PDU_CPST_SESSION_TIMING)
        {
          PDU_PARAM_STRUCT_SESS_TIMING* pSessTimingCopy = new PDU_PARAM_STRUCT_SESS_TIMING[value->ParamActEntries];
          PDU_PARAM_STRUCT_SESS_TIMING* pStructArray = reinterpret_cast<PDU_PARAM_STRUCT_SESS_TIMING*>(value->pStructArray);
          std::copy(&(pStructArray[0]), &(pStructArray[value->ParamActEntries]), &pSessTimingCopy[0]);
          copyData->pStructArray = pSessTimingCopy;
        }
        else if (value->ComParamStructType == PDU_CPST_ACCESS_TIMING)
        {
          PDU_PARAM_STRUCT_ACCESS_TIMING* pAccessTimingCopy = new PDU_PARAM_STRUCT_ACCESS_TIMING[value->ParamActEntries];
          PDU_PARAM_STRUCT_ACCESS_TIMING* pStructArray = reinterpret_cast<PDU_PARAM_STRUCT_ACCESS_TIMING*>(value->pStructArray);
          std::copy(&pStructArray[0], &pStructArray[value->ParamActEntries], &pAccessTimingCopy[0]);
          copyData->pStructArray = pAccessTimingCopy;
        }
        else
        {
          throw std::string("Error in ComParamManager::CopyParamItem() : ComParamStructType unknown.");
        }
      }
      else
      {
        copyData->pStructArray = nullptr;
      }
      this->pComParamData = copyData;
      break;
    }
    case PDU_PT_UNDEFINED:
    {
      this->pComParamData = nullptr;
    }
    break;
  }
  return *this;
}

void native_api::PDU_PARAM_ITEM::DeleteComParamData()
{
  switch (this->ComParamDataType)
  {
    case PDU_PT_UNUM8:
      if (this->pComParamData)
      {
        delete (UNUM8*)this->pComParamData;
      }
      break;
    case PDU_PT_SNUM8:
      if (this->pComParamData)
      {
        delete (SNUM8*)this->pComParamData;
      }
      break;
    case PDU_PT_UNUM16:
      if (this->pComParamData)
      {
        delete (UNUM16*)this->pComParamData;
      }
      break;
    case PDU_PT_SNUM16:
      if (this->pComParamData)
      {
        delete (SNUM16*)this->pComParamData;
      }
      break;
    case PDU_PT_UNUM32:
      if (this->pComParamData)
      {
        delete (UNUM32*)this->pComParamData;
      }
      break;
    case PDU_PT_SNUM32:
    {
      if (this->pComParamData)
      {
        delete (SNUM32*)this->pComParamData;
      }
      break;
    }
    case PDU_PT_BYTEFIELD:
    {
      if (this->pComParamData)
      {
        PDU_PARAM_BYTEFIELD_DATA* pByteFieldData = reinterpret_cast<PDU_PARAM_BYTEFIELD_DATA*>(this->pComParamData);
        if (pByteFieldData->pDataArray)
        {
          delete [] pByteFieldData->pDataArray;
        }
        delete pByteFieldData;
      }
      break;
    }
    case PDU_PT_LONGFIELD:
    {
      if (this->pComParamData)
      {
        PDU_PARAM_LONGFIELD_DATA* pLongFieldData = reinterpret_cast<PDU_PARAM_LONGFIELD_DATA*>(this->pComParamData);
        if (pLongFieldData->pDataArray)
        {
          delete [] pLongFieldData->pDataArray;
        }
        delete pLongFieldData;
      }
      break;
    }
    case PDU_PT_STRUCTFIELD:
    {
      if (this->pComParamData)
      {
        PDU_PARAM_STRUCTFIELD_DATA* pStructFieldData = reinterpret_cast<PDU_PARAM_STRUCTFIELD_DATA*>(this->pComParamData);
        if (pStructFieldData->pStructArray)
        {
          delete [] pStructFieldData->pStructArray;
        }
        delete pStructFieldData;
      }
      break;
    }
    case PDU_PT_UNDEFINED:
    {
      this->pComParamData = nullptr;
    }
    break;
  }
}
