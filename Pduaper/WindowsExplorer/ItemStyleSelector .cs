namespace WindowsExplorer
{
  using System.Windows;
  using System.Windows.Controls;

  public class ItemStyleSelector : StyleSelector
  {
    public override Style SelectStyle(object item, DependencyObject container)
    {
      if (item is Drive)
        return this.DriveStyle;
      else if (item is Directory)
        return this.DirectoryStyle;
      else if (item is File)
        return this.FileStyle;
      return base.SelectStyle(item, container);
    }

    public Style DirectoryStyle
    {
      get;
      set;
    }
    public Style FileStyle
    {
      get;
      set;
    }
    public Style DriveStyle
    {
      get;
      set;
    }
  }
}
