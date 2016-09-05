#pragma once
namespace PduApiClr
{
  public enum class E_PDU_STATUS
  {
    //  ComPrimitive status
    PDU_COPST_IDLE = 0x8010,
    PDU_COPST_EXECUTING = 0x8011,
    PDU_COPST_FINISHED = 0x8012,
    PDU_COPST_CANCELLED = 0x8013,
    PDU_COPST_WAITING = 0x8014,
    //  ComLogicalLink status   
    PDU_CLLST_OFFLINE = 0x8050,
    PDU_CLLST_ONLINE = 0x8051,
    PDU_CLLST_COMM_STARTED = 0x8052,
    PDU_CLLST_DISCONNECTING = 0x8053,
    //  Module status
    PDU_MODST_READY = 0x8060,
    PDU_MODST_NOT_READY = 0x8061,
    PDU_MODST_NOT_AVAIL = 0x8062,
    PDU_MODST_AVAIL = 0x8063

  };
}