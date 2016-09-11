#include "stdafx.h"
#include "DPduApi.h"


DPduApi::DPduApi()
{
  m_pLibraryManager = new PDULibraryManager();
}


DPduApi::~DPduApi()
{
  if(m_pLibraryManager != nullptr)
  {
    delete m_pLibraryManager;
  }
}


native_api::T_PDU_ERROR DPduApi::LoadDll(const char* _strDllPath)
{
  native_api::T_PDU_ERROR result = native_api::T_PDU_ERROR::PDU_ERR_FCT_FAILED;
  try
  {
    if (m_pLibraryManager != nullptr)
    {
      m_pLibraryManager->LoadPDULibrary(_strDllPath);
      this->InitFunctors(m_pLibraryManager);
      result = native_api::T_PDU_ERROR::PDU_STATUS_NOERROR;
    }
  }
  catch (...)
  {

  }



  return result;
}


native_api::T_PDU_ERROR DPduApi::UnloadDll()
{
  native_api::T_PDU_ERROR result = native_api::T_PDU_ERROR::PDU_ERR_FCT_FAILED;
  try
  {
    if (m_pLibraryManager != nullptr)
    {
      m_pLibraryManager->FreeLibrary();
      result = native_api::T_PDU_ERROR::PDU_STATUS_NOERROR;
    }
  }
  catch (...)
  {
  }

  return result;
}

native_api::T_PDU_ERROR DPduApi::PDUConstruct(CHAR8* pszOption, void* pAPITag)
{
  return (*s_fPDUConstruct)(pszOption, pAPITag);
}

native_api::T_PDU_ERROR DPduApi::PDUDestruct()
{
  return (*s_fPDUDestruct)();
}

native_api::T_PDU_ERROR DPduApi::PDUGetModuleIds(native_api::PDU_MODULE_ITEM** pModuleIdList)
{
	return (*s_fPDUGetModuleIds)(pModuleIdList);
}

native_api::T_PDU_ERROR DPduApi::PDUDestroyItem(native_api::PDU_ITEM* pItem)
{
  return (*s_fPDUDestroyItem)(pItem);
}

int DPduApi::Do()
{
	return 22;
}

void DPduApi::InitFunctors(PDULibraryManager* _pLibraraManager)
{
  s_fPDUConstruct = reinterpret_cast<FctPDUConstruct*>(
    _pLibraraManager->GetFunction("PDUConstruct"));
  s_fPDUDestruct = reinterpret_cast<FctPDUDestruct*>(
    _pLibraraManager->GetFunction("PDUDestruct"));
  s_fPDUIoCtl = reinterpret_cast<FctPDUIoCtl*>(
    _pLibraraManager->GetFunction("PDUIoCtl"));
  s_fPDUGetVersion = reinterpret_cast<FctPDUGetVersion*>(
    _pLibraraManager->GetFunction("PDUGetVersion"));
  s_fPDUGetStatus = reinterpret_cast<FctPDUGetStatus*>(
    _pLibraraManager->GetFunction("PDUGetStatus"));
  s_fPDUGetLastError = reinterpret_cast<FctPDUGetLastError*>(
    _pLibraraManager->GetFunction("PDUGetLastError"));
  s_fPDUGetResourceStatus = reinterpret_cast<FctPDUGetResourceStatus*>(
    _pLibraraManager->GetFunction("PDUGetResourceStatus"));
  s_fPDUCreateComLogicalLink = reinterpret_cast<FctPDUCreateComLogicalLink*>(
    _pLibraraManager->GetFunction("PDUCreateComLogicalLink"));
  s_fPDUDestroyComLogicalLink = reinterpret_cast<FctPDUDestroyComLogicalLink*>(
    _pLibraraManager->GetFunction("PDUDestroyComLogicalLink"));
  s_fPDUConnect = reinterpret_cast<FctPDUConnect*>(
    _pLibraraManager->GetFunction("PDUConnect"));
  s_fPDUDisconnect = reinterpret_cast<FctPDUDisconnect*>(
    _pLibraraManager->GetFunction("PDUDisconnect"));
  s_fPDULockResource = reinterpret_cast<FctPDULockResource*>(
    _pLibraraManager->GetFunction("PDULockResource"));
  s_fPDUUnlockResource = reinterpret_cast<FctPDUUnlockResource*>(
    _pLibraraManager->GetFunction("PDUUnlockResource"));
  s_fPDUGetComParam = reinterpret_cast<FctPDUGetComParam*>(
    _pLibraraManager->GetFunction("PDUGetComParam"));
  s_fPDUSetComParam = reinterpret_cast<FctPDUSetComParam*>(
    _pLibraraManager->GetFunction("PDUSetComParam"));
  s_fPDUStartComPrimitive = reinterpret_cast<FctPDUStartComPrimitive*>(
    _pLibraraManager->GetFunction("PDUStartComPrimitive"));
  s_fPDUCancelComPrimitive = reinterpret_cast<FctPDUCancelComPrimitive*>(
    _pLibraraManager->GetFunction("PDUCancelComPrimitive"));
  s_fPDUGetEventItem = reinterpret_cast<FctPDUGetEventItem*>(
    _pLibraraManager->GetFunction("PDUGetEventItem"));
  s_fPDUDestroyItem = reinterpret_cast<FctPDUDestroyItem*>(
    _pLibraraManager->GetFunction("PDUDestroyItem"));
  s_fPDURegisterEventCallback = reinterpret_cast<FctPDURegisterEventCallback*>(
    _pLibraraManager->GetFunction("PDURegisterEventCallback"));
  s_fPDUGetObjectId = reinterpret_cast<FctPDUGetObjectId*>(
    _pLibraraManager->GetFunction("PDUGetObjectId"));
  s_fPDUGetModuleIds = reinterpret_cast<FctPDUGetModuleIds*>(
    _pLibraraManager->GetFunction("PDUGetModuleIds"));
  s_fPDUGetResourceIds = reinterpret_cast<FctPDUGetResourceIds*>(
    _pLibraraManager->GetFunction("PDUGetResourceIds"));
  s_fPDUGetConflictingResources = reinterpret_cast<FctPDUGetConflictingResources*>(
    _pLibraraManager->GetFunction("PDUGetConflictingResources"));
  s_fPDUGetUniqueRespIdTable = reinterpret_cast<FctPDUGetUniqueRespIdTable*>(
    _pLibraraManager->GetFunction("PDUGetUniqueRespIdTable"));
  s_fPDUSetUniqueRespIdTable = reinterpret_cast<FctPDUSetUniqueRespIdTable*>(
    _pLibraraManager->GetFunction("PDUSetUniqueRespIdTable"));
  s_fPDUModuleConnect = reinterpret_cast<FctPDUModuleConnect*>(
    _pLibraraManager->GetFunction("PDUModuleConnect"));
  s_fPDUModuleDisconnect = reinterpret_cast<FctPDUModuleDisconnect*>(
    _pLibraraManager->GetFunction("PDUModuleDisconnect"));
  s_fPDUGetTimestamp = reinterpret_cast<FctPDUGetTimestamp*>(
    _pLibraraManager->GetFunction("PDUGetTimestamp"));
}