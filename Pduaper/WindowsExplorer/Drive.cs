using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsExplorer
{
  using System.Collections.ObjectModel;
  using System.ComponentModel;
  using System.Runtime.CompilerServices;

    public class Drive : INotifyPropertyChanged
  {
    public Drive(string name, bool isReady)
    {
      this.Name = name;
      this.IsReady = isReady;
        this.IsSelected = false;
        this.IsExpanded = true;
      this.Children = new ObservableCollection<object>();
    }
    public string Name
    {
      get;
      set;
    }
    public bool IsReady
    {
      get;
      set;
    }
        private bool isSelected;
        public bool IsSelected
        {
            get
            {
                return isSelected;
            }
            set
            {
                if (value != isSelected)
                {
                    isSelected = value;
                    OnPropertyChanged("IsSelected");
                }
            }
        }

        private bool isExpanded;
        public bool IsExpanded
        {
            get
            {
                return isExpanded;
            }
            set
            {
                if (value != isExpanded)
                {
                    isExpanded = value;
                    OnPropertyChanged("IsExpanded");
                }
            }
        }

        //public bool IsExpanded
        //{
        //    get;
        //    set;
        //}
        public ObservableCollection<object> Children
    {
      get;
      private set;
    }

        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
  }
}
