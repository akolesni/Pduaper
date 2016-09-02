using System;
using RMC_DF.Entities;

namespace RMC_DF
{
  public class DfFacade
  {
    public Rdf GetRdf(string v)
    {
      throw new NotImplementedException();
    }

    public Rdf GetRdf()
    {
      RdfManager rdfManager = new RdfManager();
      return rdfManager.GetRdf();
    }
  }
}
