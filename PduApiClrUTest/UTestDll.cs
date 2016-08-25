namespace PduApiClrUTest
{
  using Microsoft.VisualStudio.TestTools.UnitTesting;

  using PduApiClr;

  using PduApiClrUTest.Properties;

  [TestClass]
  public class UTestDll
  {
      private readonly PduApi pduApi;

      public UTestDll()
      {
          this.pduApi = new PduApi();
      }

      [TestMethod]
    public void TestLoadDll()
    {
      string pathIme118 = Settings.Default.DllPath;

      E_PDU_ERROR pduError = this.pduApi.LoadDll(pathIme118);

      Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);

    }

        [TestMethod]
        public void TestUnloadDll()
        {
            E_PDU_ERROR pduError = this.pduApi.UnloadDll();

            Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);

        }
    }
}
