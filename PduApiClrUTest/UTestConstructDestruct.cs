using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace PduApiClrUTest
{
    using PduApiClr;

    using PduApiClrUTest.Properties;

    using RMC_DF;

  [TestClass]
    public class UTestConstructDestruct
    {
        private PduApi pduApi;

      private E_PDU_ERROR pduError;

    //    public TestConstructDestruct()
    //    {
    //      this.pduApi = new PduApi();
    //      string pathIme118 = Settings.Default.DllPath;
    //      string pathIme114 = @"c:\Program Files (x86)\I+ME Actia GmbH\XS D PDU API\PDUAPI_I+ME_ACTIA_XS.dll";
    //      pduError = this.pduApi.LoadDll(pathIme114);
    //      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);


    //}


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
      pduError = this.pduApi.UnloadDll();
      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
    }

      //public ~TestConstructDestruct

      [TestMethod]
      public void TestConstruct()
      {
        pduError =
          this.pduApi.PDUConstruct(
            @"LogFilename='.\logs\UTestConstructDestruct_TestConstruct.log' LogLevel='Debug'",
            "tag01");

        Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
        pduError = this.pduApi.PDUDestruct();
        Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
      }

      [TestMethod]
      public void TestDestruct()
      {
        //string pathIme118 = Settings.Default.DllPath;
        pduError = this.pduApi.PDUDestruct();
        Assert.AreEqual(pduError, E_PDU_ERROR.PDU_ERR_PDUAPI_NOT_CONSTRUCTED);
        //pduError = this.pduApi.UnloadDll();
        //Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
      }
    }
}
