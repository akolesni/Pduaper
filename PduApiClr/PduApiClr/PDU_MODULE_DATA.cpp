#include "stdafx.h"
#include "pdu_api.h"
#include "PduApiClr/PDU_MODULE_DATA.h"


//PduApiClr::PDU_MODULE_DATA::PDU_MODULE_DATA()
//{
//}

//PduApiClr::PDU_MODULE_ITEM::PDU_MODULE_ITEM(native_api::PDU_MODULE_ITEM* item)
//{
//}

PduApiClr::PDU_MODULE_DATA::PDU_MODULE_DATA(native_api::PDU_MODULE_DATA * module)
{
  ModuleTypeId = module->ModuleTypeId;
  hMod         = module->hMod;

  pVendorModuleName = gcnew System::String(module->pVendorModuleName);
  pVendorAdditionalInfo = gcnew System::String(module->pVendorAdditionalInfo);

  

  //const char* chars = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strDllPath)).ToPointer();

  //result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->LoadDll(chars));

  //Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)chars));

  ModuleStatus = (E_PDU_STATUS)module->ModuleStatus;
}
