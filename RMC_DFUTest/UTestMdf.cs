
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RMC_DFUTest
{
  using RMC_DF;
  using RMC_DF.Entities;
  using RMC_DF.Entities.RdfEntities;

  [TestClass]
  public class UTestMdf
  {
    [TestMethod]
    public void TestRegistry()
    {
      DfFacade dfFacade = new DfFacade();
      Rdf rdf = dfFacade.GetRdf();

      MVCI_PDU_API vci = rdf.GetVci("XS_D_PDU_API_1_18_1_0");



      Mdf mdf = dfFacade.GetMdf(vci.MODULE_DESCRIPTION_FILE);

      //Rdf Rdf = new Rdf();
      //string s = rdf.GetRdfPath();
    }
  }
}
