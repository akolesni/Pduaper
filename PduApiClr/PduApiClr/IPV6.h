#pragma once

#include "PDU_IP_ADDR_INFO.h"

namespace PduApiClr
{

  public ref class IPV6 : public PDU_IP_ADDR_INFO
  {
  public:
    IPV6()
    {
      ipAddr = gcnew array<System::Byte>(6);
    }

    virtual property System::Byte default[int]
    {
      System::Byte get(int index)
    {
      return ipAddr[index];
    }
    void set(int index, System::Byte value)
    {
      ipAddr[index] = value;
    }
    }

      virtual  System::UInt32 GetLength()
    {
      return 6;
    }

  private:
    array<System::Byte>^ ipAddr;
  };
}
