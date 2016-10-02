#pragma once

namespace PduApiClr
{

  public ref class PDU_PIN_DATA
  {
    public:
      PDU_PIN_DATA();
      PDU_PIN_DATA(System::UInt32 DLCPinNumber, System::UInt32 DLCPinTypeId);

      property System::UInt32 DLCPinNumber;
      property System::UInt32 DLCPinTypeId;
  };
}
