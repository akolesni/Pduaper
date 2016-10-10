#pragma once

namespace PduApiClr
{
  public interface class PDU_IP_ADDR_INFO
  {
  public:
    property System::Byte default[int]
    {
      System::Byte get(int index);
      void set(int index, System::Byte value);
    }
    System::UInt32 GetLength();
  };
}
