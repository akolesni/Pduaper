using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RMC_DF.Entities.MdfEntities
{
  using System.Xml.Linq;

  public class ErrorCode
  {
    #region Fields
    #endregion

    #region Properties
    public string ID { get; private set; }
    public string SHORT_NAME { get; private set; }
    public string DESCRIPTION { get; private set; }
    #endregion

    #region Constructors
    internal ErrorCode(XElement element)
    {
      this.ID = element.Element("ID").Value;
      this.SHORT_NAME = element.Element("SHORT_NAME").Value;
      this.DESCRIPTION = element.Element("DESCRIPTION").Value;
    }
    #endregion
  }
}
