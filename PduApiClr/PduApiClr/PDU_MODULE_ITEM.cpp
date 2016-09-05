#include "stdafx.h"
#include "pdu_api.h"
#include "PduApiClr/PDU_MODULE_ITEM.h"


PduApiClr::PDU_MODULE_ITEM::PDU_MODULE_ITEM()
{
}

PduApiClr::PDU_MODULE_ITEM::PDU_MODULE_ITEM(native_api::PDU_MODULE_ITEM* item)
{
  m_Pointer = (unsigned long)item;

  for(size_t count = 0; count < item->NumEntries; count++)
  {
    Add(gcnew PduApiClr::PDU_MODULE_DATA(&item->pModuleData[count]));
  }
}

