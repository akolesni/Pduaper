using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace PduApiClrUTest
{
    using PduApiClr;

    using PduApiClrUTest.Properties;

    [TestClass]
    public class TestConstructDestruct
    {
        private readonly PduApi pduApi;

        public TestConstructDestruct()
        {
            this.pduApi = new PduApi();
        }
        [TestMethod]
        public void TestConstruct()
        {
            string pathIme118 = Settings.Default.DllPath;
            E_PDU_ERROR pduError = this.pduApi.LoadDll(pathIme118);
            Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);

            pduError = this.pduApi.PDUConstruct(@"LogFilename='.\logs\TestConstruct.log' LogLevel='Debug'", "tag01");

            Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
        }

        [TestMethod]
        public void TestDestruct()
        {
            string pathIme118 = Settings.Default.DllPath;
            E_PDU_ERROR pduError = this.pduApi.PDUDestruct();
            Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
            pduError = this.pduApi.UnloadDll();
            Assert.AreEqual(pduError, E_PDU_ERROR.PDU_STATUS_NOERROR);
        }
    }
}
