// This is the main DLL file.

#include "stdafx.h"
#include "DPduApi.h"
#include "PduApiClr.h"

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
  return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUDestruct()
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;
  return result;
}

