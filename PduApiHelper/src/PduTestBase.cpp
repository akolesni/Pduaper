#include "stdafx.h"
#include "PduTestBase.h"

/**
 *@brief - Constructor
 */
PduTestBase::PduTestBase()
{
  //m_Timer.stop();
}

/**
 *@brief - Destructor
 */
PduTestBase::~PduTestBase()
{
}

void PduTestBase::InitFunctor(PDULibraryManager* _pLibraraManager)
{
  s_fPDUConstruct              = reinterpret_cast<FctPDUConstruct*>(
    _pLibraraManager->GetFunction("PDUConstruct"));
  s_fPDUDestruct               = reinterpret_cast<FctPDUDestruct*>(
    _pLibraraManager->GetFunction("PDUDestruct"));
  s_fPDUIoCtl                  = reinterpret_cast<FctPDUIoCtl*>(
    _pLibraraManager->GetFunction("PDUIoCtl"));
  s_fPDUGetVersion             = reinterpret_cast<FctPDUGetVersion*>(
    _pLibraraManager->GetFunction("PDUGetVersion"));
  s_fPDUGetStatus              = reinterpret_cast<FctPDUGetStatus*>(
    _pLibraraManager->GetFunction("PDUGetStatus"));
  s_fPDUGetLastError           = reinterpret_cast<FctPDUGetLastError*>(
    _pLibraraManager->GetFunction("PDUGetLastError"));
  s_fPDUGetResourceStatus      = reinterpret_cast<FctPDUGetResourceStatus*>(
    _pLibraraManager->GetFunction("PDUGetResourceStatus"));
  s_fPDUCreateComLogicalLink   = reinterpret_cast<FctPDUCreateComLogicalLink*>(
    _pLibraraManager->GetFunction("PDUCreateComLogicalLink"));
  s_fPDUDestroyComLogicalLink  = reinterpret_cast<FctPDUDestroyComLogicalLink*>(
    _pLibraraManager->GetFunction("PDUDestroyComLogicalLink"));
  s_fPDUConnect                = reinterpret_cast<FctPDUConnect*>(
    _pLibraraManager->GetFunction("PDUConnect"));
  s_fPDUDisconnect             = reinterpret_cast<FctPDUDisconnect*>(
    _pLibraraManager->GetFunction("PDUDisconnect"));
  s_fPDULockResource           = reinterpret_cast<FctPDULockResource*>(
    _pLibraraManager->GetFunction("PDULockResource"));
  s_fPDUUnlockResource         = reinterpret_cast<FctPDUUnlockResource*>(
    _pLibraraManager->GetFunction("PDUUnlockResource"));
  s_fPDUGetComParam            = reinterpret_cast<FctPDUGetComParam*>(
    _pLibraraManager->GetFunction("PDUGetComParam"));
  s_fPDUSetComParam            = reinterpret_cast<FctPDUSetComParam*>(
    _pLibraraManager->GetFunction("PDUSetComParam"));
  s_fPDUStartComPrimitive      = reinterpret_cast<FctPDUStartComPrimitive*>(
    _pLibraraManager->GetFunction("PDUStartComPrimitive"));
  s_fPDUCancelComPrimitive     = reinterpret_cast<FctPDUCancelComPrimitive*>(
    _pLibraraManager->GetFunction("PDUCancelComPrimitive"));
  s_fPDUGetEventItem           = reinterpret_cast<FctPDUGetEventItem*>(
    _pLibraraManager->GetFunction("PDUGetEventItem"));
  s_fPDUDestroyItem            = reinterpret_cast<FctPDUDestroyItem*>(
    _pLibraraManager->GetFunction("PDUDestroyItem"));
  s_fPDURegisterEventCallback  = reinterpret_cast<FctPDURegisterEventCallback*>(
    _pLibraraManager->GetFunction("PDURegisterEventCallback"));
  s_fPDUGetObjectId            = reinterpret_cast<FctPDUGetObjectId*>(
    _pLibraraManager->GetFunction("PDUGetObjectId"));
  s_fPDUGetModuleIds            = reinterpret_cast<FctPDUGetModuleIds*>(
    _pLibraraManager->GetFunction("PDUGetModuleIds"));
  s_fPDUGetResourceIds          = reinterpret_cast<FctPDUGetResourceIds*>(
    _pLibraraManager->GetFunction("PDUGetResourceIds"));
  s_fPDUGetConflictingResources = reinterpret_cast<FctPDUGetConflictingResources*>(
    _pLibraraManager->GetFunction("PDUGetConflictingResources"));
  s_fPDUGetUniqueRespIdTable    = reinterpret_cast<FctPDUGetUniqueRespIdTable*>(
    _pLibraraManager->GetFunction("PDUGetUniqueRespIdTable"));
  s_fPDUSetUniqueRespIdTable    = reinterpret_cast<FctPDUSetUniqueRespIdTable*>(
    _pLibraraManager->GetFunction("PDUSetUniqueRespIdTable"));
  s_fPDUModuleConnect           = reinterpret_cast<FctPDUModuleConnect*>(
    _pLibraraManager->GetFunction("PDUModuleConnect"));
  s_fPDUModuleDisconnect        = reinterpret_cast<FctPDUModuleDisconnect*>(
    _pLibraraManager->GetFunction("PDUModuleDisconnect"));
  s_fPDUGetTimestamp            = reinterpret_cast<FctPDUGetTimestamp*>(
    _pLibraraManager->GetFunction("PDUGetTimestamp"));
}

void PduTestBase::SimpleCheck()
{
  if (PDUConstruct(static_cast<CHAR*>("LogFilename='.\\logs\\simpleCheck.log'"), nullptr) != PDU_STATUS_NOERROR)
  {
    throw std::string("PDU API not constructed");
  }
	if (PDUDestruct() != PDU_STATUS_NOERROR)
  {
    throw std::string("PDU API not destructed");
  }
}

void PduTestBase::TimerStart()
{
  //m_Timer.start();
}

long long PduTestBase::TimerElapsed()
{
  //return m_Timer.elapsed().wall;
	return 0;
}

UNUM32 PduTestBase::CreateLogicalLinkUDS(UNUM32 hMod)
{
	UNUM32 result = PDU_HANDLE_UNDEF;

	UNUM32 unISO_11898_2_DWCAN;
	UNUM32 unISO_15765_3_on_ISO_15765_2;
	UNUM32 unHi, unLow;
	PDU_PIN_DATA pins[2];
	PDUGetObjectId(PDU_OBJT_BUSTYPE, "ISO_11898_2_DWCAN", &unISO_11898_2_DWCAN);
	PDUGetObjectId(PDU_OBJT_PROTOCOL, "ISO_15765_3_on_ISO_15765_2", &unISO_15765_3_on_ISO_15765_2);
	PDUGetObjectId(PDU_OBJT_PINTYPE, "HI", &unHi);
	PDUGetObjectId(PDU_OBJT_PINTYPE, "LOW", &unLow);

	pins[0].DLCPinNumber = 6;
	pins[0].DLCPinTypeId = unHi;
	pins[1].DLCPinNumber = 14;
	pins[1].DLCPinTypeId = unLow;

	PDU_RSC_DATA rscData;
	rscData.BusTypeId = unISO_11898_2_DWCAN;
	rscData.ProtocolId = unISO_15765_3_on_ISO_15765_2;
	rscData.NumPinData = 2;
	rscData.pDLCPinData = pins;

	char* pCllTag = "";

	PDU_FLAG_DATA* flagData = new PDU_FLAG_DATA(false, true);

	PDUCreateComLogicalLink(hMod,&rscData,PDU_ID_UNDEF,pCllTag,&result, flagData);

	delete flagData;

	return result;
}


T_PDU_ERROR PduTestBase::PDUConstruct(CHAR8* pszOption, void* pAPITag)
{
  return (*s_fPDUConstruct)(pszOption, pAPITag);
}

T_PDU_ERROR PduTestBase::PDUDestruct()
{
  return (*s_fPDUDestruct)();
}

T_PDU_ERROR PduTestBase::PDUIoCtl(UNUM32 hMod, UNUM32 hCLL, UNUM32 IoCtlCommandId, PDU_DATA_ITEM* pInputData, PDU_DATA_ITEM** pOutputData)
{
  return (*s_fPDUIoCtl)(hMod, hCLL, IoCtlCommandId, pInputData, pOutputData);
}

T_PDU_ERROR PduTestBase::PDUGetVersion(UNUM32 hMod, PDU_VERSION_DATA* pVersionData)
{
  return (*s_fPDUGetVersion)(hMod, pVersionData);
}

T_PDU_ERROR PduTestBase::PDUGetStatus(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP, T_PDU_STATUS* pStatusCode, UNUM32* pTimestamp, UNUM32* pExtraInfo)
{
  return (*s_fPDUGetStatus)(hMod, hCLL, hCoP, pStatusCode, pTimestamp, pExtraInfo);
}

T_PDU_ERROR PduTestBase::PDUGetLastError(UNUM32 hMod, UNUM32 hCLL, T_PDU_ERR_EVT* pErrorCode, UNUM32* phCoP, UNUM32* pTimestamp, UNUM32* pExtraErrorInfo)
{
  return (*s_fPDUGetLastError)(hMod, hCLL, pErrorCode, phCoP, pTimestamp, pExtraErrorInfo);
}

T_PDU_ERROR PduTestBase::PDUGetResourceStatus(PDU_RSC_STATUS_ITEM* pResourceStatus)
{
  return (*s_fPDUGetResourceStatus)(pResourceStatus);
}

T_PDU_ERROR PduTestBase::PDUCreateComLogicalLink(UNUM32 hMod, PDU_RSC_DATA* pRscData, UNUM32 resourceId, void* pCllTag, UNUM32* phCLL, PDU_FLAG_DATA* pCllCreateFlag)
{
  return (*s_fPDUCreateComLogicalLink)(hMod, pRscData, resourceId, pCllTag, phCLL, pCllCreateFlag);
}

T_PDU_ERROR PduTestBase::PDUDestroyComLogicalLink(UNUM32 hMod, UNUM32 hCLL)
{
  return (*s_fPDUDestroyComLogicalLink)(hMod, hCLL);
}

T_PDU_ERROR PduTestBase::PDUConnect(UNUM32 hMod, UNUM32 hCLL)
{
  return (*s_fPDUConnect)(hMod, hCLL);
}

T_PDU_ERROR PduTestBase::PDUDisconnect(UNUM32 hMod, UNUM32 hCLL)
{
  return (*s_fPDUDisconnect)(hMod, hCLL);
}

T_PDU_ERROR PduTestBase::PDULockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask)
{
  return (*s_fPDULockResource)(hMod, hCLL, LockMask);
}

T_PDU_ERROR PduTestBase::PDUUnlockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask)
{
  return (*s_fPDUUnlockResource)(hMod, hCLL, LockMask);
}

T_PDU_ERROR PduTestBase::PDUGetComParam(UNUM32 hMod, UNUM32 hCLL, UNUM32 ParamId, PDU_PARAM_ITEM** pParamItem)
{
  return (*s_fPDUGetComParam)(hMod, hCLL, ParamId, pParamItem);
}

T_PDU_ERROR PduTestBase::PDUSetComParam(UNUM32 hMod, UNUM32 hCLL, PDU_PARAM_ITEM* pParamItem)
{
  return (*s_fPDUSetComParam)(hMod, hCLL, pParamItem);
}

T_PDU_ERROR PduTestBase::PDUStartComPrimitive(UNUM32 hMod, UNUM32 hCLL, T_PDU_COPT CoPType, UNUM32 CoPDataSize, UNUM8* pCoPData, PDU_COP_CTRL_DATA* pCopCtrlData, void* pCoPTag, UNUM32* phCoP)
{
  return (*s_fPDUStartComPrimitive)(hMod, hCLL, CoPType, CoPDataSize, pCoPData, pCopCtrlData, pCoPTag, phCoP);
}

T_PDU_ERROR PduTestBase::PDUCancelComPrimitive(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP)
{
  return (*s_fPDUCancelComPrimitive)(hMod, hCLL, hCoP);
}

T_PDU_ERROR PduTestBase::PDUGetEventItem(UNUM32 hMod, UNUM32 hCLL, PDU_EVENT_ITEM** pEventItem)
{
  return (*s_fPDUGetEventItem)(hMod, hCLL, pEventItem);
}

T_PDU_ERROR PduTestBase::PDUDestroyItem(PDU_ITEM* pItem)
{
  return (*s_fPDUDestroyItem)(pItem);
}

T_PDU_ERROR PduTestBase::PDURegisterEventCallback(UNUM32 hMod, UNUM32 hCLL, CALLBACKFNC EventCallbackFunction)
{
  return (*s_fPDURegisterEventCallback)(hMod, hCLL, EventCallbackFunction);
}

T_PDU_ERROR PduTestBase::PDUGetObjectId(T_PDU_OBJT pduObjectType, CHAR8* pShortname, UNUM32* pPduObjectId)
{
  return (*s_fPDUGetObjectId)(pduObjectType, pShortname, pPduObjectId);
}

T_PDU_ERROR PduTestBase::PDUGetModuleIds(PDU_MODULE_ITEM** pModuleIdList)
{
  return (*s_fPDUGetModuleIds)(pModuleIdList);
}

T_PDU_ERROR PduTestBase::PDUGetResourceIds(UNUM32 hMod, PDU_RSC_DATA* pResourceIdData, PDU_RSC_ID_ITEM** pResourceIdList)
{
  return (*s_fPDUGetResourceIds)(hMod, pResourceIdData, pResourceIdList);
}

T_PDU_ERROR PduTestBase::PDUGetConflictingResources(UNUM32 resourceId, PDU_MODULE_ITEM* pInputModuleList, PDU_RSC_CONFLICT_ITEM** pOutputConflictList)
{
  return (*s_fPDUGetConflictingResources)(resourceId, pInputModuleList, pOutputConflictList);
}

T_PDU_ERROR PduTestBase::PDUGetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL, PDU_UNIQUE_RESP_ID_TABLE_ITEM** pUniqueRespIdTable)
{
  return (*s_fPDUGetUniqueRespIdTable)(hMod, hCLL, pUniqueRespIdTable);
}

T_PDU_ERROR PduTestBase::PDUSetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL, PDU_UNIQUE_RESP_ID_TABLE_ITEM* pUniqueRespIdTable)
{
  return (*s_fPDUSetUniqueRespIdTable)(hMod, hCLL, pUniqueRespIdTable);
}

T_PDU_ERROR PduTestBase::PDUModuleConnect(UNUM32 hMod)
{
  return (*s_fPDUModuleConnect)(hMod);
}

T_PDU_ERROR PduTestBase::PDUModuleDisconnect(UNUM32 hMod)
{
  return (*s_fPDUModuleDisconnect)(hMod);
}

T_PDU_ERROR PduTestBase::PDUGetTimestamp(UNUM32 hMod, UNUM32* pTimestamp)
{
  return (*s_fPDUGetTimestamp)(hMod, pTimestamp);
}

FctPDUConstruct*               PduTestBase::s_fPDUConstruct;
FctPDUDestruct*                PduTestBase::s_fPDUDestruct;  
FctPDUIoCtl*                   PduTestBase::s_fPDUIoCtl;
FctPDUGetVersion*              PduTestBase::s_fPDUGetVersion;
FctPDUGetStatus*               PduTestBase::s_fPDUGetStatus;
FctPDUGetLastError*            PduTestBase::s_fPDUGetLastError;
FctPDUGetResourceStatus*       PduTestBase::s_fPDUGetResourceStatus;
FctPDUCreateComLogicalLink*    PduTestBase::s_fPDUCreateComLogicalLink;
FctPDUDestroyComLogicalLink*   PduTestBase::s_fPDUDestroyComLogicalLink;
FctPDUConnect*                 PduTestBase::s_fPDUConnect;
FctPDUDisconnect*              PduTestBase::s_fPDUDisconnect;
FctPDULockResource*            PduTestBase::s_fPDULockResource;
FctPDUUnlockResource*          PduTestBase::s_fPDUUnlockResource;
FctPDUGetComParam*             PduTestBase::s_fPDUGetComParam;
FctPDUSetComParam*             PduTestBase::s_fPDUSetComParam;
FctPDUStartComPrimitive*       PduTestBase::s_fPDUStartComPrimitive;
FctPDUCancelComPrimitive*      PduTestBase::s_fPDUCancelComPrimitive;
FctPDUGetEventItem*            PduTestBase::s_fPDUGetEventItem;
FctPDUDestroyItem*             PduTestBase::s_fPDUDestroyItem;
FctPDURegisterEventCallback*   PduTestBase::s_fPDURegisterEventCallback;
FctPDUGetObjectId*             PduTestBase::s_fPDUGetObjectId;
FctPDUGetModuleIds*            PduTestBase::s_fPDUGetModuleIds;
FctPDUGetResourceIds*          PduTestBase::s_fPDUGetResourceIds;
FctPDUGetConflictingResources* PduTestBase::s_fPDUGetConflictingResources;
FctPDUGetUniqueRespIdTable*    PduTestBase::s_fPDUGetUniqueRespIdTable;
FctPDUSetUniqueRespIdTable*    PduTestBase::s_fPDUSetUniqueRespIdTable;
FctPDUModuleConnect*           PduTestBase::s_fPDUModuleConnect;
FctPDUModuleDisconnect*        PduTestBase::s_fPDUModuleDisconnect;
FctPDUGetTimestamp*            PduTestBase::s_fPDUGetTimestamp;
