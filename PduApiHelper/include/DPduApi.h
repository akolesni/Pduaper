#pragma once

#include "PDULibraryManager.h"

class DPduApi
{
public:
  DPduApi();
  ~DPduApi();

  native_api::T_PDU_ERROR LoadDll(const char* _strDllPath);
  native_api::T_PDU_ERROR UnloadDll();

  // PDU API
  native_api::T_PDU_ERROR PDUConstruct(CHAR8* pszOption, void* pAPITag);
  native_api::T_PDU_ERROR PDUDestruct();

   //T_PDU_ERROR PDUIoCtl(UNUM32 hMod, UNUM32 hCLL, UNUM32 IoCtlCommandId,
   // PDU_DATA_ITEM *pInputData, PDU_DATA_ITEM **pOutputData);
   //T_PDU_ERROR PDUGetVersion(UNUM32 hMod, PDU_VERSION_DATA *pVersionData);
   //T_PDU_ERROR PDUGetStatus(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP,
   // T_PDU_STATUS *pStatusCode, UNUM32 *pTimestamp, UNUM32 *pExtraInfo);
   //T_PDU_ERROR PDUGetLastError(UNUM32 hMod, UNUM32 hCLL, T_PDU_ERR_EVT
   // *pErrorCode, UNUM32 *phCoP, UNUM32 *pTimestamp, UNUM32 *pExtraErrorInfo);
   //T_PDU_ERROR PDUGetResourceStatus(PDU_RSC_STATUS_ITEM *pResourceStatus);
   //T_PDU_ERROR PDUCreateComLogicalLink(UNUM32 hMod, PDU_RSC_DATA *pRscData,
   // UNUM32 resourceId, void *pCllTag, UNUM32 *phCLL, PDU_FLAG_DATA *pCllCreateFlag);
   //T_PDU_ERROR PDUDestroyComLogicalLink(UNUM32 hMod, UNUM32 hCLL);
   //T_PDU_ERROR PDUConnect(UNUM32 hMod, UNUM32 hCLL);
   //T_PDU_ERROR PDUDisconnect(UNUM32 hMod, UNUM32 hCLL);
   //T_PDU_ERROR PDULockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
   //T_PDU_ERROR PDUUnlockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
   //T_PDU_ERROR PDUGetComParam(UNUM32 hMod, UNUM32 hCLL, UNUM32 ParamId,
   // PDU_PARAM_ITEM **pParamItem);
   //T_PDU_ERROR PDUSetComParam(UNUM32 hMod, UNUM32 hCLL, PDU_PARAM_ITEM
   // *pParamItem);
   //T_PDU_ERROR PDUStartComPrimitive(UNUM32 hMod, UNUM32 hCLL, T_PDU_COPT
   // CoPType, UNUM32 CoPDataSize, UNUM8 *pCoPData, PDU_COP_CTRL_DATA *pCopCtrlData,
   // void *pCoPTag, UNUM32 *phCoP);
   //T_PDU_ERROR PDUCancelComPrimitive(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP);
   //T_PDU_ERROR PDUGetEventItem(UNUM32 hMod, UNUM32 hCLL,
   // PDU_EVENT_ITEM **pEventItem);
   //T_PDU_ERROR PDUDestroyItem(PDU_ITEM *pItem);
   //T_PDU_ERROR PDURegisterEventCallback(UNUM32 hMod, UNUM32 hCLL,
   // CALLBACKFNC EventCallbackFunction);
   //T_PDU_ERROR PDUGetObjectId(T_PDU_OBJT pduObjectType, CHAR8* pShortname,
   // UNUM32 *pPduObjectId);
  native_api::T_PDU_ERROR PDUGetModuleIds(native_api::PDU_MODULE_ITEM **pModuleIdList);
   //T_PDU_ERROR PDUGetResourceIds(UNUM32 hMod, PDU_RSC_DATA *pResourceIdData,
   // PDU_RSC_ID_ITEM **pResourceIdList);
   //T_PDU_ERROR PDUGetConflictingResources(UNUM32 resourceId,
   // PDU_MODULE_ITEM *pInputModuleList, PDU_RSC_CONFLICT_ITEM **pOutputConflictList);
   //T_PDU_ERROR PDUGetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL,
   // PDU_UNIQUE_RESP_ID_TABLE_ITEM **pUniqueRespIdTable);
   //T_PDU_ERROR PDUSetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL,
   // PDU_UNIQUE_RESP_ID_TABLE_ITEM *pUniqueRespIdTable);
   //T_PDU_ERROR PDUModuleConnect(UNUM32 hMod);
   //T_PDU_ERROR PDUModuleDisconnect(UNUM32 hMod);
   //T_PDU_ERROR PDUGetTimestamp(UNUM32 hMod, UNUM32 *pTimestamp);

  int Do();

private:
  void InitFunctors(PDULibraryManager* _pLibraraManager);


  PDULibraryManager* m_pLibraryManager = nullptr;

   FctPDUConstruct* s_fPDUConstruct;
   FctPDUDestruct* s_fPDUDestruct;
   FctPDUIoCtl* s_fPDUIoCtl;
   FctPDUGetVersion* s_fPDUGetVersion;
   FctPDUGetStatus* s_fPDUGetStatus;
   FctPDUGetLastError* s_fPDUGetLastError;
   FctPDUGetResourceStatus* s_fPDUGetResourceStatus;
   FctPDUCreateComLogicalLink* s_fPDUCreateComLogicalLink;
   FctPDUDestroyComLogicalLink* s_fPDUDestroyComLogicalLink;
   FctPDUConnect* s_fPDUConnect;
   FctPDUDisconnect* s_fPDUDisconnect;
   FctPDULockResource* s_fPDULockResource;
   FctPDUUnlockResource* s_fPDUUnlockResource;
   FctPDUGetComParam* s_fPDUGetComParam;
   FctPDUSetComParam* s_fPDUSetComParam;
   FctPDUStartComPrimitive* s_fPDUStartComPrimitive;
   FctPDUCancelComPrimitive* s_fPDUCancelComPrimitive;
   FctPDUGetEventItem* s_fPDUGetEventItem;
   FctPDUDestroyItem* s_fPDUDestroyItem;
   FctPDURegisterEventCallback* s_fPDURegisterEventCallback;
   FctPDUGetObjectId* s_fPDUGetObjectId;
   FctPDUGetModuleIds* s_fPDUGetModuleIds;
   FctPDUGetResourceIds* s_fPDUGetResourceIds;
    FctPDUGetConflictingResources* s_fPDUGetConflictingResources;
   FctPDUGetUniqueRespIdTable* s_fPDUGetUniqueRespIdTable;
   FctPDUSetUniqueRespIdTable* s_fPDUSetUniqueRespIdTable;
   FctPDUModuleConnect* s_fPDUModuleConnect;
   FctPDUModuleDisconnect* s_fPDUModuleDisconnect;
   FctPDUGetTimestamp* s_fPDUGetTimestamp;
};

