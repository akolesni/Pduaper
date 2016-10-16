
namespace PduApiClrUTest
{
  using Microsoft.VisualStudio.TestTools.UnitTesting;

  using PduApiClr;

  using PduApiClrUTest.Properties;

  using RMC_DF;

  /// <summary>
  /// Summary description for UTestIoCtl
  /// </summary>
  [TestClass]
  public class UTestIoCtl
  {
    private PduApi pduApi= null;

    private E_PDU_ERROR pduError= 0;

    public UTestIoCtl()
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
    public void TestModuleConnect()
    {
      this.pduError = this.pduApi.PDUConstruct(@"LogFilename='.\logs\UTestModuleConnect_TestModuleConnect.log' LogLevel='Debug'", "tag01");

      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUConstruct");
      PDU_MODULE_ITEM module;

      this.pduError = this.pduApi.PDUGetModuleIds(out module);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR,"PDUGetModuleIds");

      Assert.AreEqual(module.Count,1, "1 modile");

      PDU_MODULE_DATA data = module[0];

      uint hMod = data.hMod;

      this.pduError = this.pduApi.PDUModuleConnect(hMod);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUModuleConnect");

      this.pduError = this.pduApi.PDUModuleDisconnect(hMod);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUModuleDisconnect");

      this.pduError = this.pduApi.PDUDestroyItem(module);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUDestroyItem");

      this.pduError = this.pduApi.PDUDestruct();
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUDestruct");
      //
    }
  }
}
