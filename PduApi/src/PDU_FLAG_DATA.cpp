#include "stdafx.h"
#include "pdu_api.h"


/**
 *@brief - Constructor
 */
native_api::PDU_FLAG_DATA::PDU_FLAG_DATA(bool _bRawMode, bool _bChecksumMode)
{
	this->NumFlagBytes = 4;
	this->pFlagData = new UNUM8 [4];

  this->pFlagData[0] = 0;
  this->pFlagData[1] = 0;
  this->pFlagData[2] = 0;
  this->pFlagData[3] = 0;

  if (_bRawMode == true)
  {
    // set bit 7 to 1
    this->pFlagData[0] |= 128;
  }
  if (_bChecksumMode == true)
  {
    // set bit 6 to 1
    this->pFlagData[0] |= 64;
  }
}


/**
 *@brief - Destructor
 */
native_api::PDU_FLAG_DATA::~PDU_FLAG_DATA()
{
  if (this->pFlagData != nullptr)
	{
		delete this->pFlagData;
	}
}
