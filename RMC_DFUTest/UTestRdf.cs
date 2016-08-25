using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RMC_DFUTest
{
  using RMC_DF;

  [TestClass]
  public class UTestRdf
  {
    [TestMethod]
    public void TestRegistry()
    {
      Rdf rdf = new Rdf();
      string s = rdf.GetPduPath();
    }
  }
}
