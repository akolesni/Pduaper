using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pduaper.Command
{
  using System.Windows;
  using System.Windows.Input;

  class SelectionChangedCommand : ICommand
  {
    public bool CanExecute(object parameter)
    {
      return true;
    }

    public void Execute(object parameter)
    {
      MessageBox.Show(parameter.ToString());
      //throw new NotImplementedException();
    }

    public event EventHandler CanExecuteChanged;
  }
}
