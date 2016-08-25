#include "stdafx.h"
#include "pdu_api.h"


/**
 *@brief - Constructor
 */
PDU_ECU_UNIQUE_RESP_DATA::PDU_ECU_UNIQUE_RESP_DATA()
{
	UniqueRespIdentifier = PDU_ID_UNDEF;
	NumParamItems = 0;
	pParams = nullptr;
}



/**
 *@brief - Copy constructor
 */
PDU_ECU_UNIQUE_RESP_DATA::PDU_ECU_UNIQUE_RESP_DATA(const PDU_ECU_UNIQUE_RESP_DATA& _paramItem)
{
  throw;
}

/**
 *@brief - Destructor
 */
PDU_ECU_UNIQUE_RESP_DATA::~PDU_ECU_UNIQUE_RESP_DATA()
{
  if (pParams != nullptr)
  {
    delete[] pParams;
  }
}

/**
 *@brief - Assignment operator
 */
PDU_ECU_UNIQUE_RESP_DATA& PDU_ECU_UNIQUE_RESP_DATA::operator=(const PDU_ECU_UNIQUE_RESP_DATA& _paramItem)
{
  throw;
  return *this;
}
