#pragma once
//#include "T_PDU_IT.h"
////#include "PDU_MODULE_DATA.h"
//namespace native_api { struct PDU_MODULE_ITEM; }



namespace PduApiClr
{

  public interface class PDU_ITEM
  {
    public:
      //PDU_MODULE_ITEM();

      //T_PDU_IT ItemType;

    //internal:
      System::UInt64 GetNativePointer();
      //PDU_MODULE_ITEM(native_api::PDU_MODULE_ITEM* item);
    //private:
      //System::UInt64 m_Pointer = 0;

  };
}
