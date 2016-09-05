
namespace PduApiClrUTest
{
  using Microsoft.VisualStudio.TestTools.UnitTesting;

  using PduApiClr;

  using PduApiClrUTest.Properties;


  /// <summary>
  /// Summary description for UTestGetModuleIds
  /// </summary>
  [TestClass]
  public class UTestGetModuleIds
  {
    private PduApi pduApi= null;

    private E_PDU_ERROR pduError= 0;

    public UTestGetModuleIds()
    {
      //
      // TODO: Add constructor logic here
      //
    }


    [TestInitialize]
    public void TestInitialize()
    {
      pduApi = new PduApi();
      string pathIme118 = Settings.Default.DllPath;
      string pathIme114 = @"c:\Program Files (x86)\I+ME Actia GmbH\XS D PDU API\PDUAPI_I+ME_ACTIA_XS.dll";
      pduError = this.pduApi.LoadDll(pathIme114);
      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
    }

    [TestCleanup]
    public void TestCleanup()
    {
      pduError = this.pduApi.UnloadDll();
      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
    }

    [TestMethod]
    public void TestGetModules()
    {
      pduError = this.pduApi.PDUConstruct(@"LogFilename='.\logs\TestGetModules.log' LogLevel='Debug'", "tag01");

      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUConstruct");
      PDU_MODULE_ITEM module;

      pduError = this.pduApi.PDUGetModuleIds(out module);
      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR,"PDUGetModuleIds");

      pduError = this.pduApi.PDUDestruct();
      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUDestruct");
      //
    }
  }
}
