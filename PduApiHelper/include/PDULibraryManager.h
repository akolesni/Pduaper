#ifndef __PDU_LIBRARY_MANAGER_H_
#define __PDU_LIBRARY_MANAGER_H_
#include <map>
#include <string>
#include <Windows.h>
#include "pdu_api.h"

#define PDU_API_CALL_CONV __stdcall

typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUConstruct(CHAR8* OptionStr, void *pAPITag);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUDestruct();
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUIoCtl(UNUM32 hMod, UNUM32 hCLL, UNUM32 IoCtlCommandId,
//                                                              native_api::PDU_DATA_ITEM *pInputData, native_api::PDU_DATA_ITEM **pOutputData);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetVersion( UNUM32 hMod, native_api::PDU_VERSION_DATA *pVersionData );
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetStatus( UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP,
//                                                                   native_api::T_PDU_STATUS *pStatusCode, UNUM32 *pTimestamp, UNUM32 *pExtraInfo);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetLastError( UNUM32 hMod, UNUM32 hCLL, native_api::T_PDU_ERR_EVT
//  *pErrorCode, UNUM32 *phCoP, UNUM32 *pTimestamp, UNUM32 *pExtraErrorInfo);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetResourceStatus(native_api::PDU_RSC_STATUS_ITEM *pResourceStatus);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUCreateComLogicalLink(UNUM32 hMod, native_api::PDU_RSC_DATA *pRscData,
  UNUM32 resourceId, void *pCllTag, UNUM32 *phCLL, native_api::PDU_FLAG_DATA *pCllCreateFlag );
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUDestroyComLogicalLink(UNUM32 hMod, UNUM32 hCLL );
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUConnect(UNUM32 hMod, UNUM32 hCLL);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUDisconnect(UNUM32 hMod, UNUM32 hCLL );
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDULockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUUnlockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetComParam( UNUM32 hMod, UNUM32 hCLL, UNUM32 ParamId,
//                                                                     native_api::PDU_PARAM_ITEM **pParamItem);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUSetComParam( UNUM32 hMod, UNUM32 hCLL, native_api::PDU_PARAM_ITEM
//  *pParamItem);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUStartComPrimitive(UNUM32 hMod, UNUM32 hCLL, native_api::T_PDU_COPT
//  CoPType, UNUM32 CoPDataSize, UNUM8 *pCoPData, native_api::PDU_COP_CTRL_DATA *pCopCtrlData,
//  void *pCoPTag, UNUM32 *phCoP );
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUCancelComPrimitive(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetEventItem(UNUM32 hMod, UNUM32 hCLL,
//                                                                     native_api::PDU_EVENT_ITEM **pEventItem);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUDestroyItem(native_api::PDU_ITEM *pItem);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDURegisterEventCallback(UNUM32 hMod, UNUM32 hCLL,
                                                                              native_api::CALLBACKFNC EventCallbackFunction );
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetObjectId(native_api::T_PDU_OBJT pduObjectType, CHAR8* pShortname,
  UNUM32 *pPduObjectId);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetModuleIds(native_api::PDU_MODULE_ITEM **pModuleIdList);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetResourceIds(UNUM32 hMod, native_api::PDU_RSC_DATA *pResourceIdData,
//                                                                       native_api::PDU_RSC_ID_ITEM **pResourceIdList);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetConflictingResources(UNUM32 resourceId,
//                                                                                native_api::PDU_MODULE_ITEM *pInputModuleList, native_api::PDU_RSC_CONFLICT_ITEM **pOutputConflictList);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL,
//                                                                             native_api::PDU_UNIQUE_RESP_ID_TABLE_ITEM **pUniqueRespIdTable);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUSetUniqueRespIdTable (UNUM32 hMod, UNUM32 hCLL,
//                                                                              native_api::PDU_UNIQUE_RESP_ID_TABLE_ITEM *pUniqueRespIdTable);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUModuleConnect (UNUM32 hMod);
typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUModuleDisconnect(UNUM32 hMod);
//typedef native_api::T_PDU_ERROR PDU_API_CALL_CONV FctPDUGetTimestamp(UNUM32 hMod, UNUM32 *pTimestamp);

class PDULibraryManager
{
public:
  PDULibraryManager(void);
  virtual ~PDULibraryManager(void);

  void LoadPDULibrary(const char* _strDllPath);
  void FreeLibrary(void);
  void* GetFunction(const std::string& _strFunctionName);

private:
  //std::string GetDllPath(void)const;
  template <typename Function>
  void InstantiateFunction(const HINSTANCE _hModule, const std::string& _strFunctionName);
  void InitPointerMap();

  HINSTANCE m_PduApi;
  std::map<std::string, void*> m_PointerMap ;
};
#endif
