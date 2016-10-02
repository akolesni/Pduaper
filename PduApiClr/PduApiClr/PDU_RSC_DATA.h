#pragma once
#include "PDU_PIN_DATA.h"

namespace PduApiClr
{

  public ref class PDU_RSC_DATA
  {
    public:
      PDU_RSC_DATA();

      property System::UInt32 BusTypeId;
      property System::UInt32 ProtocolId;
      property System::Collections::Generic::List<PduApiClr::PDU_PIN_DATA^>^ pDLCPinData;
  };
}
