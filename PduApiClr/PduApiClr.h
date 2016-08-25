#pragma once
#include "E_PDU_ERROR.h"

class DPduApi;

using namespace System;

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


    private:
      DPduApi* m_pPduApi = nullptr;
  };
}
