using Microsoft.Win32;
using RMC_DF.Entities;
using System;
using System.Linq;
using System.Xml.Linq;

namespace RMC_DF
{
  using RMC_DF.Entities.RdfEntities;

  internal class RdfManager
  {
    private string GetRdfPath()
    {
      RegistryKey hklm = Registry.LocalMachine;
      RegistryKey software = hklm.OpenSubKey("SOFTWARE");
      RegistryKey pdu = software.OpenSubKey("D-PDU API");
      if (pdu == null)
      {
        RegistryKey wowKey = hklm.OpenSubKey("WOW6432Node");
        pdu = software.OpenSubKey("D-PDU API");
      }

      string v = pdu.GetValue("Root File") as string;

      return v;

    }

    internal Rdf GetRdf()
    {

      return GetRdf(GetRdfPath());

    }

    internal Rdf GetRdf(string rdfPath)
    {
      Rdf rdf = new Rdf();
      XDocument xdoc = XDocument.Load(rdfPath);


      var apis = from a in xdoc.Elements()
                 select a;

      foreach (var api in apis.Elements())
      {
        MVCI_PDU_API mvci = new MVCI_PDU_API
        {
          SHORT_NAME = api.Element("SHORT_NAME").Value,
          DESCRIPTION = api.Element("DESCRIPTION").Value,
          SUPPLIER_NAME = api.Element("SUPPLIER_NAME").Value,
          LIBRARY_FILE = api.Element("LIBRARY_FILE").Attribute("URI").Value,
          MODULE_DESCRIPTION_FILE =
            api.Element("MODULE_DESCRIPTION_FILE").Attribute("URI").Value,
          CABLE_DESCRIPTION_FILE =
            api.Element("CABLE_DESCRIPTION_FILE").Attribute("URI").Value
        };


        rdf.Add(mvci);
      }

      return rdf;
    }
  }
}
