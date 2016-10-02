#include "stdafx.h"
#include "PDULibraryManager.h"

/**
 *@brief - Constructor
 */
PDULibraryManager::PDULibraryManager(void)
{
  m_PduApi = nullptr;
}

/**
 *@brief - Destructor
 */
PDULibraryManager::~PDULibraryManager(void)
{
  if (m_PduApi == nullptr)
  {
    ::FreeLibrary(m_PduApi);
  }
}

/**
 *@brief - Loads D-PDU API dll and initialised all API-Functions
 */
void PDULibraryManager::LoadPDULibrary(const char* _strDllPath)
{
  ////std::string strDllPath = this->GetDllPath();
  //std::string strDllPath = _strDllPath;
  
  m_PduApi = ::LoadLibraryExA(_strDllPath, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
  if (m_PduApi == nullptr)
  {
    throw std::string("Error in PDULibraryManager::LoadPDULibrary(): Call LoadLibraryExA.");
  }
  this->InitPointerMap();
}

void PDULibraryManager::FreeLibrary()
{
  if (m_PduApi == nullptr)
  {
    ::FreeLibrary(m_PduApi);
    m_PduApi = nullptr;
  }
}

/**
 *@brief - Gets functionpointer
 *
 *@param - IN- _strFunctionName Functionname
 *
 *@return void* as functionpointer. Must be cated
 */
void* PDULibraryManager::GetFunction(const std::string& _strFunctionName)
{
  return m_PointerMap[_strFunctionName];
}

/**
 *@brief - Finds the functionpointer for entered functionname and saved in the poinermap.
 *
 *@param - IN - _hModule        A handle to the DLL module that contains the function.
 *@param - IN- _strFunctionName Functionname
 */
template <typename Function>
void PDULibraryManager::InstantiateFunction(const HINSTANCE _hModule, const std::string& _strFunctionName)
{
  Function* p_outFunction = reinterpret_cast<Function*>(GetProcAddress(_hModule,_strFunctionName.c_str()));

  if (p_outFunction == nullptr)
  {
    throw std::string("Error in GetProcAddress() for '" + _strFunctionName + "'.");
  }

  m_PointerMap[_strFunctionName] = p_outFunction;
}

/**
 *@brief - Gets path to the D-PDU API dll.
 *
 *@return dll-path as std string.
 */
//std::string PDULibraryManager::GetDllPath(void)const
//{
//  std::unique_ptr <PDUEnvironment> pPDUEnvironment(new PDUEnvironment());
//  return pPDUEnvironment->GetDllPath();
//}

/**
 *@brief - Initialises all API functionspointers
 */
void PDULibraryManager::InitPointerMap()
{
  InstantiateFunction<FctPDUConstruct>(m_PduApi, "PDUConstruct");
  InstantiateFunction<FctPDUDestruct>(m_PduApi, "PDUDestruct");
  //InstantiateFunction<FctPDUIoCtl>(m_PduApi, "PDUIoCtl");
  //InstantiateFunction<FctPDUGetVersion>(m_PduApi, "PDUGetVersion");
  //InstantiateFunction<FctPDUGetStatus>(m_PduApi, "PDUGetStatus");
  //InstantiateFunction<FctPDUGetLastError>(m_PduApi, "PDUGetLastError");
  //InstantiateFunction<FctPDUGetResourceStatus>(m_PduApi, "PDUGetResourceStatus");
  InstantiateFunction<FctPDUCreateComLogicalLink>(m_PduApi, "PDUCreateComLogicalLink");
  InstantiateFunction<FctPDUDestroyComLogicalLink>(m_PduApi, "PDUDestroyComLogicalLink");
  InstantiateFunction<FctPDUConnect>(m_PduApi, "PDUConnect");
  InstantiateFunction<FctPDUDisconnect>(m_PduApi, "PDUDisconnect");
  //InstantiateFunction<FctPDULockResource>(m_PduApi, "PDULockResource");
  //InstantiateFunction<FctPDUUnlockResource>(m_PduApi, "PDUUnlockResource");
  //InstantiateFunction<FctPDUGetComParam>(m_PduApi, "PDUGetComParam");
  //InstantiateFunction<FctPDUSetComParam>(m_PduApi, "PDUSetComParam");
  //InstantiateFunction<FctPDUStartComPrimitive>(m_PduApi, "PDUStartComPrimitive");
  //InstantiateFunction<FctPDUCancelComPrimitive>(m_PduApi, "PDUCancelComPrimitive");
  //InstantiateFunction<FctPDUGetEventItem>(m_PduApi, "PDUGetEventItem");
  InstantiateFunction<FctPDUDestroyItem>(m_PduApi, "PDUDestroyItem");
  InstantiateFunction<FctPDURegisterEventCallback>(m_PduApi, "PDURegisterEventCallback");
  //InstantiateFunction<FctPDUGetObjectId>(m_PduApi, "PDUGetObjectId");
  InstantiateFunction<FctPDUGetModuleIds>(m_PduApi, "PDUGetModuleIds");
  //InstantiateFunction<FctPDUGetResourceIds>(m_PduApi, "PDUGetResourceIds");
  //InstantiateFunction<FctPDUGetConflictingResources>(m_PduApi, "PDUGetConflictingResources");
  //InstantiateFunction<FctPDUGetUniqueRespIdTable>(m_PduApi, "PDUGetUniqueRespIdTable");
  //InstantiateFunction<FctPDUSetUniqueRespIdTable>(m_PduApi, "PDUSetUniqueRespIdTable");
  InstantiateFunction<FctPDUModuleConnect>(m_PduApi, "PDUModuleConnect");
  InstantiateFunction<FctPDUModuleDisconnect>(m_PduApi, "PDUModuleDisconnect");
  //InstantiateFunction<FctPDUGetTimestamp>(m_PduApi, "PDUGetTimestamp");
}
