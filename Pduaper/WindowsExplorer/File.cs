using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsExplorer
{
  public class File
  {
    public File(string fullPath, string name)
    {
      this.FullPath = fullPath;
      this.Name = name;
    }
    public string FullPath
    {
      get;
      set;
    }
    public string Name
    {
      get;
      set;
    }
  }
}
