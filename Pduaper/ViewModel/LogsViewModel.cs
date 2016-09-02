using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pduaper.ViewModel
{
  using System.Collections.ObjectModel;

  public class LogsViewModel
  {

    public ObservableCollection<Log> Logs { get; set; }

    public LogsViewModel()
    {
      this.Logs = new ObservableCollection<Log>();


      Log log = new Log();
      log.Message = "jsjs";

      this.Logs.Add(log);
    }
  }
}
