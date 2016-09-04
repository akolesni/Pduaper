using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pduaper.Resources
{
  using System.Windows;
  using System.Windows.Controls;

  public class TemplateSelector : DataTemplateSelector
  {
        //public DataTemplate DefaultnDataTemplate { get; set; }
        public DataTemplate BooleanDataTemplate { get; set; }
        public DataTemplate EnumDataTemplate { get; set; }
        public override DataTemplate SelectTemplate(object item, DependencyObject container)
    {
      //получаем вызывающий контейнер
      // FrameworkElement element = container as FrameworkElement;
      Window win = Application.Current.MainWindow;
      DataTemplate rasult = BooleanDataTemplate;

      
      if (item != null)
            {
                string s = item as string;

                if (s != "Log")
                {

          //return win.FindResource("ButtonTemplate") as DataTemplate;
          //DataTemplate dt = new DataTemplate();
          //dt.Template = new LogView();
          rasult = EnumDataTemplate;
        }
        else
                {
          //return win.FindResource("TextBlockTemplate") as DataTemplate;
          rasult = BooleanDataTemplate;
        }

            }

          if (rasult == null)
          {
        //MessageBox.Show("NULL");
      }
            else
            {
        //MessageBox.Show(rasult.GetType().ToString());
      }

      


      return rasult;
            

           

      //return element.FindResource("TextBlockTemplate") as DataTemplate;

      //if (element != null && item != null && item is int)
      //{
      //  int currentItem = 0;

      //  int.TryParse(item.ToString(), out currentItem);
      //  //в зависимости от того, какой вариант выбран, возвращаем конкретный шаблон
      //  if (currentItem == 0)
      //    return element.FindResource("ButtonTemplate") as DataTemplate;
      //  if (currentItem == 1)
      //    return element.FindResource("TextBlockTemplate") as DataTemplate;
      //  ////if (currentItem == 2)
      //  ////  return element.FindResource("RadioButtonsTemplate") as DataTemplate;
      //}
      //return null;
    }
  }
}
