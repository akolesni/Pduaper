#include "stdafx.h"
#include "PDU_FLAG_DATA.h"

PduApiClr::PDU_FLAG_DATA::PDU_FLAG_DATA(bool bRawMode, bool bChecksumMode)
{
  System::Byte value;
  
  if (bRawMode == true)
  {
    // set bit 7 to 1
    value |= 128;
  }
  if (bChecksumMode == true)
  {
    // set bit 6 to 1
    value |= 64;
  }

  this->Add(value);
  this->Add(0);
  this->Add(0);
  this->Add(0);
}
