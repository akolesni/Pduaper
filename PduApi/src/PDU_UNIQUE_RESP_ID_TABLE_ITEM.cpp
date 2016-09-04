#include "stdafx.h"
#include "pdu_api.h"



/**
 *@brief - Constructor
 */
native_api::PDU_UNIQUE_RESP_ID_TABLE_ITEM::PDU_UNIQUE_RESP_ID_TABLE_ITEM()
{
  ItemType = PDU_IT_UNIQUE_RESP_ID_TABLE;
  NumEntries = 0;
  pUniqueData = nullptr;
}



/**
 *@brief - Copy constructor
 */
native_api::PDU_UNIQUE_RESP_ID_TABLE_ITEM::PDU_UNIQUE_RESP_ID_TABLE_ITEM(const PDU_UNIQUE_RESP_ID_TABLE_ITEM& _paramItem)
{
  throw;
}

/**
 *@brief - Destructor
 */
native_api::PDU_UNIQUE_RESP_ID_TABLE_ITEM::~PDU_UNIQUE_RESP_ID_TABLE_ITEM()
{
  if (pUniqueData != nullptr)
  {
    delete[] pUniqueData;
  }
}

/**
 *@brief - Assignment operator
 */
native_api::PDU_UNIQUE_RESP_ID_TABLE_ITEM& native_api::PDU_UNIQUE_RESP_ID_TABLE_ITEM::operator=(const PDU_UNIQUE_RESP_ID_TABLE_ITEM& _paramItem)
{
  throw;
  return *this;
}
