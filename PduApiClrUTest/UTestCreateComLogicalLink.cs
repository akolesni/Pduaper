
namespace PduApiClrUTest
{
  using Microsoft.VisualStudio.TestTools.UnitTesting;

  using PduApiClr;

  using PduApiClrUTest.Properties;

  using RMC_DF;
  using System;

  /// <summary>
  /// Summary description for UTestCreateComLogicalLink
  /// </summary>
  [TestClass]
  public class UTestCreateComLogicalLink
  {
    private PduApi pduApi= null;

    private E_PDU_ERROR pduError= 0;

    public UTestCreateComLogicalLink()
    {
      //
      // TODO: Add constructor logic here
      //
    }


    [TestInitialize]
    public void TestInitialize()
    {
      pduApi = new PduApi();
      DfFacade dfFacade = new DfFacade();
      string pathIme114 = dfFacade.GetRdf().GetLibraryPath(Settings.Default.ShortName);
      pduError = this.pduApi.LoadDll(pathIme114);
      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
    }

    [TestCleanup]
    public void TestCleanup()
    {
      this.pduError = this.pduApi.UnloadDll();
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
    }

    [TestMethod]
    public void TestCreateUds()
    {
      //Assert.AreEqual(0, 1, "not implemented");
      this.pduError = this.pduApi.PDUConstruct(@"LogFilename='.\logs\UTestCreateComLogicalLink_TestCreateUDS.log' LogLevel='Debug'", "tag01");
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUConstruct");
      PDU_MODULE_ITEM module;
      this.pduError = this.pduApi.PDUGetModuleIds(out module);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUGetModuleIds");
      Assert.AreEqual(module.Count, 1, "1 modile");
      PDU_MODULE_DATA data = module[0];
      uint hMod = data.hMod;
      this.pduError = this.pduApi.PDUModuleConnect(hMod);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUModuleConnect");
      // --------------------------------
      //PDU_RSC_DATA pduRscData = new PDU_RSC_DATA();
      PDU_FLAG_DATA pduFlagData = new PDU_FLAG_DATA(false, false);
      uint hCll;

      UInt32 resId;
      this.pduError = this.pduApi.PDUGetObjectId(T_PDU_OBJT.PDU_OBJT_RESOURCE, "ECOM_UDS_ON_CAN1_HS", out resId);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUGetObjectId");

      //uint resId = 0xFFFFFFFF;

      this.pduError = this.pduApi.PDUCreateComLogicalLink(hMod, null, resId, "cll", out hCll, pduFlagData);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUCreateComLogicalLink");

      this.pduError = this.pduApi.PDUDestroyComLogicalLink(hMod, hCll);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUDestroyComLogicalLink");

      // --------------------------------
      this.pduError = this.pduApi.PDUModuleDisconnect(hMod);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUModuleDisconnect");
      this.pduError = this.pduApi.PDUDestroyItem(module);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUDestroyItem");
      this.pduError = this.pduApi.PDUDestruct();
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUDestruct");
    }
  }
}
