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

namespace WindowsExplorer
{
  using Telerik.Windows.Controls;

  /// <summary>
  /// Interaction logic for MainWindow.xaml
  /// </summary>
  public partial class MainWindow : UserControl
  {
    public MainWindow()
    {
      InitializeComponent();
    }
    private void RadTreeView_LoadOnDemand(object sender, Telerik.Windows.RadRoutedEventArgs e)
    {
      e.Handled = true;
      RadTreeViewItem expandedItem = e.OriginalSource as RadTreeViewItem;
      if (expandedItem == null)
        return;

      Drive drive = expandedItem.Item as Drive;
      if (drive != null)
      {
        ServiceFacade.Instance.LoadChildren(drive);
        return;
      }

      Directory directory = expandedItem.Item as Directory;
      if (directory != null)
      {
        ServiceFacade.Instance.LoadChildren(directory);
      }
    }
    private void RadTreeView_ItemPrepared(object sender, RadTreeViewItemPreparedEventArgs e)
    {
      if (e.PreparedItem.DataContext is File)
      {
        e.PreparedItem.IsLoadOnDemandEnabled = false;
      }
    }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            RadTreeViewItem s = radTreeView.Items[0] as RadTreeViewItem;

            s.IsSelected = true;
            s.IsExpanded = true;
            //var v = s.Items[0] as RadTileViewItem;
            //v.IsSelected = true;

            //radTreeView.BringPathIntoView(this.textBox.Text);
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            ////radTreeView.BringPathIntoView("MyComputer\\C:\\");
            RadTreeViewItem s = radTreeView.Items[0] as RadTreeViewItem;
            var v = s.Items[0] as Drive;
            v.IsSelected = true;
            v.IsExpanded = true;
            //radTreeView.BringPathIntoView("MyComputer\\C:\\");
        }
    }
}
