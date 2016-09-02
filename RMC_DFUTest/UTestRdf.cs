
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RMC_DFUTest
{
  using RMC_DF;
  using RMC_DF.Entities;

  [TestClass]
  public class UTestRdf
  {
    [TestMethod]
    public void TestRegistry()
    {
      DfFacade dfFacade = new DfFacade();
      Rdf rdf = dfFacade.GetRdf();


      //Rdf Rdf = new Rdf();
      //string s = rdf.GetRdfPath();
    }
  }
}
