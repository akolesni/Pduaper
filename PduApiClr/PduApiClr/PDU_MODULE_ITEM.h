#pragma once
#include "T_PDU_IT.h"
namespace native_api { struct PDU_MODULE_ITEM; }



namespace PduApiClr
{
  public ref class PDU_MODULE_ITEM
  {
    public:
      PDU_MODULE_ITEM();

      T_PDU_IT ItemType;

    internal:
      PDU_MODULE_ITEM(native_api::PDU_MODULE_ITEM* item);
  };
}
