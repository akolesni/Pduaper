#pragma once
#include "E_PDU_STATUS.h"
namespace native_api { struct PDU_MODULE_DATA; }



namespace PduApiClr
{
  public ref class PDU_MODULE_DATA
  {
    public:
      PDU_MODULE_DATA(native_api::PDU_MODULE_DATA* modile);
      property System::UInt32 ModuleTypeId;
      //{
      //  System::UInt32 get()
      //  {
      //    return moduleTypeId;
      //  }
      //  void set(System::UInt32 value)
      //  {
      //    moduleTypeId = value;
      //  }
      //}

      property System::UInt32 hMod;
      //{
      //  System::UInt32 get()
      //  {
      //    return hmod;
      //  }
      //  void set(System::UInt32 value)
      //  {
      //    hmod = value;
      //  }
      //}

      property System::String^ pVendorModuleName;
      property System::String^ pVendorAdditionalInfo;
      property E_PDU_STATUS ModuleStatus;
  private:
    //System::UInt32 moduleTypeId;
    //System::UInt32 hmod;
      //T_PDU_IT ItemType;

    //internal:
      //PDU_MODULE_ITEM(native_api::PDU_MODULE_ITEM* item);
  };
}
