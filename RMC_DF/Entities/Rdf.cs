namespace RMC_DF.Entities
{
  using System.Collections.Generic;

  public class Rdf
  {
    public List<MVCI_PDU_API> MVCI_PDU_APIS { get; private set; }
    public Rdf()
    {
      MVCI_PDU_APIS = new List<MVCI_PDU_API>();
    }

    internal void AddPduApi(MVCI_PDU_API pduApi)
    {
      MVCI_PDU_APIS.Add(pduApi);
    }

  }
}
