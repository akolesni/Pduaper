#include "stdafx.h"
#include "PDU_RSC_DATA.h"

PduApiClr::PDU_RSC_DATA::PDU_RSC_DATA()
{
  BusTypeId = -2;
  ProtocolId = -2;
  pDLCPinData = gcnew System::Collections::Generic::List<PduApiClr::PDU_PIN_DATA^>();
}
