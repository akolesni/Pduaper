

namespace PduApiClrUTest
{
  using System.IO;

  using Microsoft.VisualStudio.TestTools.UnitTesting;

  using PduApiClrUTest.Properties;

  [TestClass]
  public class UTestEnvironment
  {
    [TestMethod]
    public void TestPath()
    {
      string pathIme118 = Settings.Default.DllPath;

      Assert.IsTrue(File.Exists(pathIme118));
    }
  }
}
