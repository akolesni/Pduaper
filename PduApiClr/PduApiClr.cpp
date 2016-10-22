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

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::LoadDll(String^ strDllPath)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  if(this->m_pPduApi != nullptr)
  {
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

PduApiClr::E_PDU_ERROR

PduApiClr::PduApi::PDUConstruct(String ^ pszOption, String ^ pAPITag)
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
    //System::UInt64 p =  pModuleIdList->GetNativePointer();

    item = reinterpret_cast <native_api::PDU_ITEM*> (pModuleIdList->GetNativePointer());

    result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUDestroyItem(item));
  }

  return result;
}

PduApiClr::E_PDU_ERROR
PduApiClr::PduApi::PDUModuleConnect(System::UInt32 hMod)
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
// ------------------------------------------------------------------------------------------------
/*
PDUGetObjectId
*/
// ------------------------------------------------------------------------------------------------
PduApiClr::E_PDU_ERROR

PduApiClr::PduApi::PDUGetObjectId(
  T_PDU_OBJT pduObjectType,
  String ^ pShortname,
  [Out]  UInt32 % pPduObjectId)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  char* strShortname = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(pShortname)).ToPointer();
  UNUM32 unObjectId = 0xFFFFFFFE;

  result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUGetObjectId(native_api::T_PDU_OBJT(pduObjectType), strShortname, &unObjectId));
  pPduObjectId = unObjectId;

  Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)strShortname));

  return result;
}
// ------------------------------------------------------------------------------------------------
/*
PDURegisterEventCallback
*/
// ------------------------------------------------------------------------------------------------
PduApiClr::E_PDU_ERROR

PduApiClr::PduApi::PDURegisterEventCallback(
  UInt32 hMod,
  UInt32 hCLL,
  Action<UInt32, UInt32, UInt32, IntPtr, IntPtr>^ EventCallbackFunction)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  result = PduApiClr::E_PDU_ERROR(
    this->m_pPduApi->PDURegisterEventCallback(
      hMod,
      hCLL,
      static_cast<native_api::CALLBACKFNC>(Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(EventCallbackFunction).ToPointer())));

  return result;
}
// ------------------------------------------------------------------------------------------------
/*
PDUCreateComLogicalLink
*/
// ------------------------------------------------------------------------------------------------

PduApiClr::E_PDU_ERROR

PduApiClr::PduApi::PDUCreateComLogicalLink(
  UInt32 hMod,
  PDU_RSC_DATA^ pRscData,
  UInt32 resourceId,
  String ^ pCllTag,
  [Out] UInt32 % phCLL,
  PDU_FLAG_DATA ^ pCllCreateFlag)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;
  UNUM32 unhCLL = 0xFFFFFFFE;
  char* strCllTag = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(pCllTag)).ToPointer();

  // ----------------------------------------------------------------------------------------------
  native_api::PDU_RSC_DATA* pNpRscData = nullptr;
  native_api::PDU_PIN_DATA* pPinData = nullptr;
  if (pRscData != nullptr)
  {
    native_api::PDU_RSC_DATA npRscData;
    npRscData.BusTypeId = pRscData->BusTypeId;
    npRscData.ProtocolId = pRscData->ProtocolId;
    npRscData.NumPinData = pRscData->pDLCPinData->Count;
    pPinData = new native_api::PDU_PIN_DATA[npRscData.NumPinData];
    npRscData.pDLCPinData = pPinData;
    for (size_t count = 0; count < npRscData.NumPinData; count++)
    {
      npRscData.pDLCPinData[count].DLCPinNumber = pRscData->pDLCPinData[count]->DLCPinNumber;
      npRscData.pDLCPinData[count].DLCPinTypeId = pRscData->pDLCPinData[count]->DLCPinTypeId;
    }

    pNpRscData = &npRscData;
  }

  // ----------------------------------------------------------------------------------------------
  native_api::PDU_FLAG_DATA pFlagData;
  pFlagData.NumFlagBytes = pCllCreateFlag->Count;
  pFlagData.pFlagData = new UINT8[4]{ pCllCreateFlag[0], pCllCreateFlag[1], pCllCreateFlag[2], pCllCreateFlag[3] };

  // ----------------------------------------------------------------------------------------------
  result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUCreateComLogicalLink(hMod, pNpRscData, resourceId, strCllTag, &unhCLL, &pFlagData));

  //-----------------------------------------------------------------------------------------------
  phCLL = unhCLL;
  Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)strCllTag));

  if (pRscData != nullptr)
  {
    delete[] pPinData;
  }

  delete[] pFlagData.pFlagData;

  return result;
}

PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUDestroyComLogicalLink(UInt32 hMod, UInt32 phCLL)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUDestroyComLogicalLink(hMod, phCLL));

  return result;
}
PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUConnect(UInt32 hMod, UInt32 phCLL)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUConnect(hMod, phCLL));

  return result;
}
PduApiClr::E_PDU_ERROR PduApiClr::PduApi::PDUDisconnect(UInt32 hMod, UInt32 phCLL)
{
  PduApiClr::E_PDU_ERROR result = PduApiClr::E_PDU_ERROR::PDU_ERR_FCT_FAILED;

  result = PduApiClr::E_PDU_ERROR(this->m_pPduApi->PDUDisconnect(hMod, phCLL));

  return result;
}

PduApiClr::E_PDU_ERROR

PduApiClr::PduApi::PDUIoCtl(
  UInt32 hMod,
  UInt32 phCLL,
  UInt32 IoCtlCommandId,
  PDU_DATA_ITEM ^ pInputData,
  PDU_DATA_ITEM ^% pOutputData)
{
  return E_PDU_ERROR();
}
// ------------------------------------------------------------------------------------------------
