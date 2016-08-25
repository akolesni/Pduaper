#ifndef PDU_TEST_BASE_H
#define PDU_TEST_BASE_H

#ifdef VLD
  #include "vld.h"
#endif
//#include <boost/timer/timer.hpp>
#include "PDULibraryManager.h"


class PDULibraryManager;

class PduTestBase
{
public:
  PduTestBase();
  virtual ~PduTestBase();
  static void InitFunctor(PDULibraryManager* _pLibraraManager);
	static void SimpleCheck();

protected:
  void TimerStart();
  __int64 TimerElapsed();
  // PDU API Helper
  UNUM32 CreateLogicalLinkUDS(UNUM32 hMod);

  // PDU API
  static T_PDU_ERROR PDUConstruct(CHAR8* pszOption,void* pAPITag );
  static T_PDU_ERROR PDUDestruct();
  static T_PDU_ERROR PDUIoCtl(UNUM32 hMod, UNUM32 hCLL, UNUM32 IoCtlCommandId,
  PDU_DATA_ITEM *pInputData, PDU_DATA_ITEM **pOutputData);
  static T_PDU_ERROR PDUGetVersion( UNUM32 hMod, PDU_VERSION_DATA *pVersionData );
  static T_PDU_ERROR PDUGetStatus( UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP,
  T_PDU_STATUS *pStatusCode, UNUM32 *pTimestamp, UNUM32 *pExtraInfo);
  static T_PDU_ERROR PDUGetLastError( UNUM32 hMod, UNUM32 hCLL, T_PDU_ERR_EVT
  *pErrorCode, UNUM32 *phCoP, UNUM32 *pTimestamp, UNUM32 *pExtraErrorInfo);
  static T_PDU_ERROR PDUGetResourceStatus(PDU_RSC_STATUS_ITEM *pResourceStatus);
  static T_PDU_ERROR PDUCreateComLogicalLink(UNUM32 hMod, PDU_RSC_DATA *pRscData,
  UNUM32 resourceId, void *pCllTag, UNUM32 *phCLL, PDU_FLAG_DATA *pCllCreateFlag );
  static T_PDU_ERROR PDUDestroyComLogicalLink(UNUM32 hMod, UNUM32 hCLL );
  static T_PDU_ERROR PDUConnect(UNUM32 hMod, UNUM32 hCLL);
  static T_PDU_ERROR PDUDisconnect(UNUM32 hMod, UNUM32 hCLL );
  static T_PDU_ERROR PDULockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
  static T_PDU_ERROR PDUUnlockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
  static T_PDU_ERROR PDUGetComParam( UNUM32 hMod, UNUM32 hCLL, UNUM32 ParamId,
  PDU_PARAM_ITEM **pParamItem);
  static T_PDU_ERROR PDUSetComParam( UNUM32 hMod, UNUM32 hCLL, PDU_PARAM_ITEM
  *pParamItem);
  static T_PDU_ERROR PDUStartComPrimitive(UNUM32 hMod, UNUM32 hCLL, T_PDU_COPT
  CoPType, UNUM32 CoPDataSize, UNUM8 *pCoPData, PDU_COP_CTRL_DATA *pCopCtrlData,
  void *pCoPTag, UNUM32 *phCoP );
  static T_PDU_ERROR PDUCancelComPrimitive(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP);
  static T_PDU_ERROR PDUGetEventItem(UNUM32 hMod, UNUM32 hCLL,
  PDU_EVENT_ITEM **pEventItem);
  static T_PDU_ERROR PDUDestroyItem( PDU_ITEM *pItem);
  static T_PDU_ERROR PDURegisterEventCallback(UNUM32 hMod, UNUM32 hCLL,
  CALLBACKFNC EventCallbackFunction );
  static T_PDU_ERROR PDUGetObjectId(T_PDU_OBJT pduObjectType, CHAR8* pShortname,
  UNUM32 *pPduObjectId);
  static T_PDU_ERROR PDUGetModuleIds(PDU_MODULE_ITEM **pModuleIdList);
  static T_PDU_ERROR PDUGetResourceIds(UNUM32 hMod, PDU_RSC_DATA *pResourceIdData,
  PDU_RSC_ID_ITEM **pResourceIdList);
  static T_PDU_ERROR PDUGetConflictingResources(UNUM32 resourceId,
  PDU_MODULE_ITEM *pInputModuleList, PDU_RSC_CONFLICT_ITEM **pOutputConflictList);
  static T_PDU_ERROR PDUGetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL,
  PDU_UNIQUE_RESP_ID_TABLE_ITEM **pUniqueRespIdTable);
  static T_PDU_ERROR PDUSetUniqueRespIdTable (UNUM32 hMod, UNUM32 hCLL,
  PDU_UNIQUE_RESP_ID_TABLE_ITEM *pUniqueRespIdTable);
  static T_PDU_ERROR PDUModuleConnect (UNUM32 hMod);
  static T_PDU_ERROR PDUModuleDisconnect(UNUM32 hMod);
  static T_PDU_ERROR PDUGetTimestamp(UNUM32 hMod, UNUM32 *pTimestamp);

  //boost::timer::cpu_timer m_Timer;
  static FctPDUConstruct* s_fPDUConstruct;
  static FctPDUDestruct* s_fPDUDestruct;
  static FctPDUIoCtl* s_fPDUIoCtl;
  static FctPDUGetVersion* s_fPDUGetVersion;
  static FctPDUGetStatus* s_fPDUGetStatus;
  static FctPDUGetLastError* s_fPDUGetLastError;
  static FctPDUGetResourceStatus* s_fPDUGetResourceStatus;
  static FctPDUCreateComLogicalLink* s_fPDUCreateComLogicalLink;
  static FctPDUDestroyComLogicalLink* s_fPDUDestroyComLogicalLink;
  static FctPDUConnect* s_fPDUConnect;
  static FctPDUDisconnect* s_fPDUDisconnect;
  static FctPDULockResource* s_fPDULockResource;
  static FctPDUUnlockResource* s_fPDUUnlockResource;
  static FctPDUGetComParam* s_fPDUGetComParam;
  static FctPDUSetComParam* s_fPDUSetComParam;
  static FctPDUStartComPrimitive* s_fPDUStartComPrimitive;
  static FctPDUCancelComPrimitive* s_fPDUCancelComPrimitive;
  static FctPDUGetEventItem* s_fPDUGetEventItem;
  static FctPDUDestroyItem* s_fPDUDestroyItem;
  static FctPDURegisterEventCallback* s_fPDURegisterEventCallback;
  static FctPDUGetObjectId* s_fPDUGetObjectId;
  static FctPDUGetModuleIds* s_fPDUGetModuleIds;
  static FctPDUGetResourceIds* s_fPDUGetResourceIds;
  static  FctPDUGetConflictingResources* s_fPDUGetConflictingResources;
  static FctPDUGetUniqueRespIdTable* s_fPDUGetUniqueRespIdTable;
  static FctPDUSetUniqueRespIdTable* s_fPDUSetUniqueRespIdTable;
  static FctPDUModuleConnect* s_fPDUModuleConnect;
  static FctPDUModuleDisconnect* s_fPDUModuleDisconnect;
  static FctPDUGetTimestamp* s_fPDUGetTimestamp;

//private:
//	PDU_FLAG_DATA* GetPDUFlagData();
};
#endif // __PDU_TEST_BASE_H__

