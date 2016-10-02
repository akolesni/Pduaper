#pragma once
#include "PduApiClr/E_PDU_ERROR.h"
#include "PduApiClr/PDU_MODULE_ITEM.h"
#include "PduApiClr/T_PDU_OBJT.h"
#include "PduApiClr/PDU_RSC_DATA.h"
#include "PduApiClr/PDU_FLAG_DATA.h"

class DPduApi;

using namespace System;
using namespace System::Runtime::InteropServices;

namespace PduApiClr
{
  public ref class PduApi
  {
    public:
      PduApi();
      ~PduApi();

      E_PDU_ERROR LoadDll(String^ strDllPath);
      E_PDU_ERROR UnloadDll();

      // D-PDU API
      E_PDU_ERROR PDUConstruct(String^ pszOption, String^ pAPITag);
      E_PDU_ERROR PDUDestruct();
      E_PDU_ERROR PDUGetModuleIds([Out] PDU_MODULE_ITEM^ %pModuleIdList);
      E_PDU_ERROR PDUDestroyItem(PDU_ITEM^ pModuleIdList);
      E_PDU_ERROR PDUModuleConnect(UInt32 hMod);
      E_PDU_ERROR PDUModuleDisconnect(UInt32 hMod);
      E_PDU_ERROR PDUGetObjectId(T_PDU_OBJT pduObjectType, String^ pShortname, UInt32% pPduObjectId);
      E_PDU_ERROR PDURegisterEventCallback(UInt32 hMod, UInt32 hCLL, Action<UInt32 , UInt32, UInt32, IntPtr, IntPtr>^EventCallbackFunction);
      E_PDU_ERROR PDUCreateComLogicalLink(UInt32 hMod, PDU_RSC_DATA^ pRscData, UInt32 resourceId, String^ pCllTag, UInt32% phCLL, PDU_FLAG_DATA^ pCllCreateFlag);
      E_PDU_ERROR PDUDestroyComLogicalLink(UInt32 hMod, UInt32 phCLL);
      E_PDU_ERROR PDUConnect(UInt32 hMod, UInt32 phCLL);
      E_PDU_ERROR PDUDisconnect(UInt32 hMod, UInt32 phCLL);
    private:
      DPduApi* m_pPduApi = nullptr;
  };
}
