using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pduaper.Command
{
  using System.Windows;
  using System.Windows.Input;

  using Pduaper.Resources;
  using Pduaper.ViewModel;

  using Telerik.Windows.Controls;

    public class SelectionChangedCommand : ICommand
    {
        private MainWindowViewModel mvm;
      public SelectionChangedCommand(MainWindowViewModel mvm)
      {
          this.mvm = mvm;

      }

    public bool CanExecute(object parameter)
    {
      return true;
    }

    public void Execute(object parameter)
    {
      if (parameter != null)
      {
        Tuple<object, object> tuple = parameter as Tuple<object, object>;
        if (tuple.Item1 != null)
        {
          string s = (tuple.Item1 as RadRibbonTab).Header as string;
          TemplateSelector templateSelector = tuple.Item2 as TemplateSelector;
          templateSelector.SelectTemplate(s, null);
        }
      }
      //MessageBox.Show(parameter.ToString());

      //      RadRibbonTab radRibbonTab = parameter as RadRibbonTab;

      //  if (radRibbonTab.Header != "Log")
      //  {
      //          mvm.SelectedViewModel = mvm.LogsViewModel;
      //      }

   

        //TemplateSelector templateSelector = parameter as TemplateSelector;

        //  templateSelector.SelectTemplate(null, null);

        //throw new NotImplementedException();
    }

    public event EventHandler CanExecuteChanged;
  }
}
