using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Pduaper
{
  using Telerik.Windows.Controls;

  /// <summary>
  /// Interaction logic for MainWindow.xaml
  /// </summary>
  public partial class MainWindow : RadRibbonWindow
  {
    public MainWindow()
    {
      InitializeComponent();
    }

    private void UIElement_OnLostFocus(object sender, RoutedEventArgs e)
    {
      //throw new NotImplementedException();
    }
  }
}
