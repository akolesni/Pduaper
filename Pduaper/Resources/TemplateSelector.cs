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
    public override DataTemplate SelectTemplate(object item, DependencyObject container)
    {
      //получаем вызывающий контейнер
      FrameworkElement element = container as FrameworkElement;

      return element.FindResource("TextBlockTemplate") as DataTemplate;

      if (element != null && item != null && item is int)
      {
        int currentItem = 0;

        int.TryParse(item.ToString(), out currentItem);
        //в зависимости от того, какой вариант выбран, возвращаем конкретный шаблон
        if (currentItem == 0)
          return element.FindResource("ButtonTemplate") as DataTemplate;
        if (currentItem == 1)
          return element.FindResource("TextBlockTemplate") as DataTemplate;
        ////if (currentItem == 2)
        ////  return element.FindResource("RadioButtonsTemplate") as DataTemplate;
      }
      return null;
    }
  }
}
