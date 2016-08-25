namespace RMC_DF
{
  using Microsoft.Win32;

  public class Rdf
  {
    public Rdf()
    {

    }

    public string GetPduPath()
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

  }
}
