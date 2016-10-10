#pragma once
#include "PreselectionMode.h"
#include "CombinationMode.h"
#include "PDU_IP_ADDR_INFO.h"

namespace PduApiClr
{

  public ref class PDU_IO_VEHICLE_ID_REQUEST
  {
    public:
      property PreselectionMode^ PreselectionMode;
      property System::String^ PreselectionValue;
      property CombinationMode^ CombinationMode;
      property System::UInt32 VehicleDiscoveryTime;
      property PDU_IP_ADDR_INFO^ pDestinationAddresses;
  };
}
