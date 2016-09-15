// This is the main DLL file.

#include "stdafx.h"
#include "DPduApi.h"
#include "PduApiClr.h"

//using namespace System::Runtime::InteropServices;

PduApiClr::PduApi::PduApi()
{
  this->m_pPduApi = new DPduApi();
}

PduApiClr::PduApi::~PduApi()
{
  if (this->m_pPduApi != nullptr)
  {
    delete this->m_pPduApi;
  }
}

int PduApiClr::PduApi::Do()
{
  DPduApi* pdu = new DPduApi();
  return pdu->Do();
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::LoadDll(String^ strDllPath)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  if(this->m_pPduApi != nullptr)
  {
      //using namespace Runtime::InteropServices;
      const char* chars = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strDllPath)).ToPointer();

      result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->LoadDll(chars));

      Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)chars));
  }

  return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::UnloadDll()
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  if (this->m_pPduApi != nullptr)
  {
    result = PduApiClr::E_PDU_ERROR( this->m_pPduApi->UnloadDll());
  }

  return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUConstruct(String ^ pszOption, String ^ pAPITag)
{
	PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

	char* strOption = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(pszOption)).ToPointer();
	char* strAPITag = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(pAPITag)).ToPointer();

	result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUConstruct(strOption, strAPITag));

	Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)strOption));
	Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)strAPITag));

	return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUDestruct()
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

	if (this->m_pPduApi != nullptr)
	{
		result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUDestruct());
	}

	return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUGetModuleIds([Out] PduApiClr::PDU_MODULE_ITEM^ %pModuleIdList)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;
  
  if (this->m_pPduApi != nullptr)
  {
    native_api::PDU_MODULE_ITEM* item = nullptr;
    result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUGetModuleIds(&item));
    pModuleIdList = gcnew PduApiClr::PDU_MODULE_ITEM(item);
  }

  return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUDestroyItem(PduApiClr::PDU_ITEM^ pModuleIdList)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  if (this->m_pPduApi != nullptr)
  {
    native_api::PDU_ITEM* item = nullptr;
    System::UInt64 p =  pModuleIdList->GetNativePointer();

    item = reinterpret_cast <native_api::PDU_ITEM*> (pModuleIdList->GetNativePointer());

    result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUDestroyItem(item));
  }

  return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUModuleConnect(System::UInt32 hMod)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUModuleConnect(hMod));

  return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUModuleDisconnect(System::UInt32 hMod)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUModuleDisconnect(hMod));

  return result;
}


//native_api::T_PDU_ERROR PDUDestroyItem(native_api::PDU_ITEM *pItem);

