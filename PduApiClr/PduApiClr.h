#pragma once
#include "E_PDU_ERROR.h"
#include "PduApiClr/PDU_MODULE_ITEM.h"

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

      int Do();
      E_PDU_ERROR LoadDll(String^ strDllPath);
      E_PDU_ERROR UnloadDll();

      E_PDU_ERROR PDUConstruct(String^ pszOption, String^ pAPITag);
      E_PDU_ERROR PDUDestruct();
      E_PDU_ERROR PDUGetModuleIds([Out] PDU_MODULE_ITEM^ %pModuleIdList);
      E_PDU_ERROR PDUDestroyItem(PDU_ITEM^ pModuleIdList);
      E_PDU_ERROR PDUModuleConnect(System::UInt32 hMod);
      E_PDU_ERROR PDUModuleDisconnect(System::UInt32 hMod);
    private:
      DPduApi* m_pPduApi = nullptr;
  };
}
