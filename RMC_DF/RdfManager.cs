using Microsoft.Win32;
using RMC_DF.Entities;
using System;
using System.Linq;
using System.Xml.Linq;

namespace RMC_DF
{
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
        MVCI_PDU_API mvci            = new MVCI_PDU_API();
        mvci.SHORT_NAME              = api.Element("SHORT_NAME").Value;
        mvci.DESCRIPTION             = api.Element("DESCRIPTION").Value;
        mvci.SUPPLIER_NAME           = api.Element("SUPPLIER_NAME").Value;
        mvci.LIBRARY_FILE            = api.Element("LIBRARY_FILE").Attribute("URI").Value;
        mvci.MODULE_DESCRIPTION_FILE = api.Element("MODULE_DESCRIPTION_FILE").Attribute("URI").Value;
        mvci.CABLE_DESCRIPTION_FILE  = api.Element("CABLE_DESCRIPTION_FILE").Attribute("URI").Value;


        rdf.AddPduApi(mvci);
      }
      //Console.WriteLine(p);


      //foreach (var a in xdoc.Elements())
      //{
      //  var s = a;


      //}

      return rdf;
  
    }

  }
}
