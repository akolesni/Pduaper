using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RMC_DF.Entities
{
  using System.Xml.Linq;

  using RMC_DF.Entities.MdfEntities;

  public class Mdf
  {
    #region Fields
    private List<ErrorCode> errorCodes;
    #endregion

    #region Properties
    public string Description { get; private set; }
    public string SupplierName { get; private set; }
    #endregion

    #region Constructors
    internal Mdf()
    {
      this.errorCodes = new List<ErrorCode>();
    }
    #endregion

    #region Events
    #endregion

    #region Public Methods
    //static
    internal void Load(string path)
    {
      XDocument xdoc = XDocument.Load(path);
      this.Description = xdoc.Root.Element("DESCRIPTION").Value;
      this.SupplierName = xdoc.Root.Element("SUPPLIER_NAME").Value;
      


      foreach (XElement element in xdoc.Root.Elements("ERROR_CODE"))
      {
        this.errorCodes.Add(new ErrorCode(element)); 
      }
    }
    #endregion

    #region Private Methods
    //static

    #endregion

    #region Win32 imports
    #endregion



    #region Implement of 
    #endregion

    #region 
    #endregion
  }
}
