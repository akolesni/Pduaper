using System;
using System.Text;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace PduApiClrUTest
{
  using PduApiClr;

  using PduApiClrUTest.Properties;

  using RMC_DF;

  /// <summary>
  /// Summary description for UTestGetObjectId
  /// </summary>
  [TestClass]
  public class UTestGetObjectId
  {
    private PduApi pduApi = null;

    private E_PDU_ERROR pduError = 0;

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
      //this.pduError = this.pduApi.PDUDestruct();
      this.pduError = this.pduApi.UnloadDll();
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
    }



    #region Additional test attributes
    //
    // You can use the following additional attributes as you write your tests:
    //
    // Use ClassInitialize to run code before running the first test in the class
    // [ClassInitialize()]
    // public static void MyClassInitialize(TestContext testContext) { }
    //
    // Use ClassCleanup to run code after all tests in a class have run
    // [ClassCleanup()]
    // public static void MyClassCleanup() { }
    //
    // Use TestInitialize to run code before running each test 
    // [TestInitialize()]
    // public void MyTestInitialize() { }
    //
    // Use TestCleanup to run code after each test has run
    // [TestCleanup()]
    // public void MyTestCleanup() { }
    //
    #endregion

    [TestMethod]
    public void TestGetObjectId()
    {
      this.pduError = this.pduApi.PDUConstruct(@"LogFilename='.\logs\UTestGetObjectId_TestGetObjectId.log' LogLevel='Debug'", "tag01");

      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUConstruct");

      UInt32 objId;
      this.pduError = this.pduApi.PDUGetObjectId(T_PDU_OBJT.PDU_OBJT_COMPARAM, "CP_P2Max", out objId);
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUGetObjectId");

      Assert.AreEqual(objId, (UInt32)12, "ObjectId value != 12 :" + objId);

      this.pduError = this.pduApi.PDUDestruct();
      Assert.AreEqual(this.pduError, E_PDU_ERROR.PDU_STATUS_NOERROR, "PDUDestruct");
    }
  }
}
