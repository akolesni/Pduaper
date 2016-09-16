namespace RMC_DF.Entities
{
  using System.Collections.Generic;
  using System.Linq;

  using RMC_DF.Entities.RdfEntities;

  public class Rdf : List<MVCI_PDU_API>
  {
    public MVCI_PDU_API GetVci(string shortName)
    {
      return this.Single(l => l.SHORT_NAME == shortName);
    }

    public string GetLibraryPath(string shortName)
    {
      const int StartIndex = 7; // wo file://
      return this.GetVci(shortName).LIBRARY_FILE.Substring(StartIndex);
    }

  }
}
