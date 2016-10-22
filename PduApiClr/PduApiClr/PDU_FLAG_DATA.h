#pragma once

namespace PduApiClr
{

  public ref class PDU_FLAG_DATA : System::Collections::Generic::List<System::Byte>
  {
    public:
      PDU_FLAG_DATA(bool bRawMode, bool bChecksumMode);
      //PDU_PIN_DATA(System::UInt32 DLCPinNumber, System::UInt32 DLCPinTypeId);
  };
}
