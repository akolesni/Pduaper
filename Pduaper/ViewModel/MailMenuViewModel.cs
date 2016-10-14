using RMC_DF;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Telerik.Windows.Controls;

namespace Pduaper.ViewModel
{
    using RMC_DF.Entities;

    public class MailMenuViewModel : ViewModelBase
  {
    public ObservableCollection<MenuItemBase> MenuItems { get; set; }

    private MenuItemBase selectedItem;
    public MenuItemBase SelectedItem
    {
      get { return this.selectedItem; }
      set
      {
        if (this.selectedItem != value)
        {
          this.selectedItem = value;
          this.OnPropertyChanged("SelectedItem");
        }
      }
    }

    public MailMenuViewModel()
    {
      this.MenuItems = new ObservableCollection<MenuItemBase>();

      PopulateMenuItems();

      this.selectedItem = this.MenuItems[0];
    }

    private void PopulateMenuItems()
    {
      // ContactsMenuItem
      var contactsMenuItem = new ContactsMenuItem() { Content = "Contacts content", Header = "RDF", IconSource = "../Images/rdf_32x32.png", IconSourceSmall = "../Images/rdf_16x16.png" };

      DfFacade dfFacade = new DfFacade();
      Rdf rdf = dfFacade.GetRdf();


      contactsMenuItem.ContactsList = new ObservableCollection<Person>();

      foreach (var VARIABLE in rdf)
      {
        contactsMenuItem.ContactsList.Add(new Person() { Name = VARIABLE.SHORT_NAME, IconSource = "../Images/contact.png" });
      }

      this.MenuItems.Add(contactsMenuItem);

      // MailMenuItem
      var mailMenuItem = new MailMenuItem() { Content = "Mails content", Header = "Mail", IconSource = "../Images/mailBig.png", IconSourceSmall = "../Images/mailSmall.png" };

      mailMenuItem.MailDirectories.Add(new MailDirectoryItem()
      {
        Header = "Personal Folders",
        IconSource = "Images/1PersonalFolders.png",
        Children = new ObservableCollection<MailDirectoryItem>()
                {
                    new MailDirectoryItem { Header = "Deleted Items", IconSource = "Images/2DeletedItems.png", },
                    new MailDirectoryItem { Header = "Drafts", IconSource = "Images/3Drafts.png", },
                    new MailDirectoryItem()
                    {
                        Header = "Inbox", IconSource = "Images/4Inbox.png",
                        Children = new ObservableCollection<MailDirectoryItem>()
                        {
                            new MailDirectoryItem() { Header = "Nancy Davolio", IconSource = "Images/letter.png" },
                            new MailDirectoryItem() { Header = "Janer Leverling", IconSource = "Images/letter.png" },
                            new MailDirectoryItem() { Header = "Robert King", IconSource = "Images/letter.png" },
                        }
                    },
                    new MailDirectoryItem { Header = "Junk Emails", IconSource = "Images/junk.png", },
                    new MailDirectoryItem { Header = "Outbox", IconSource = "Images/outbox.png", },
                    new MailDirectoryItem { Header = "Sent Items", IconSource = "Images/sent.png", }
                }
      });

      this.MenuItems.Add(mailMenuItem);
      // CalendarMenuItem
      var calendarMenuItem = new CalendarMenuItem() { Content = "Calendar content", Header = "Calendar", IconSource = "../Images/calendarBig.png", IconSourceSmall = "../Images/calendarSmall.png" };
      this.MenuItems.Add(calendarMenuItem);
    }
  }
}
