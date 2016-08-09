using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pduaper.ViewModel
{
  using System.Collections.ObjectModel;
  using System.IO;
  using System.Text.RegularExpressions;

  using Telerik.Windows.Controls;

    public class Log
    {
        public int Nr { get; set; }
        public string Datum { get; set; }

        public string Level { get; set; }
        public string Thread { get; set; }
        public string Message { get; set; }

        public bool IsApiCall { get; set; }
    }


    public class ThreadProp
    {
        public string Nr { get; set; }
        public bool IsSelected { get; set; }

    }

    class MainWindowViewModel
    {
        public ObservableCollection<Log> Logs { get; set; }
        public ObservableCollection<ThreadProp> Threads { get; set; }
        public MainWindowViewModel()
        {
            int nr = 1;
            Logs = new ObservableCollection<Log>();
            this.Threads = new ObservableCollection<ThreadProp>();
            Regex qariRegex = new Regex(@"(?<Datum>\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d\d\d) (?<Level>\w*)\s+(?<Thread>\[\w*\]) (?<Message>.+)");
            Regex apiRegex = new Regex(@"PDU\w+\s+call");



            using (StreamReader file = new StreamReader(@"c:\Temp\PDU_API_1.log"))
            {
                string line;
                while ((line = file.ReadLine()) != null)
                {

                    var match = qariRegex.Match(line);
                    Log log = new Log();
                    log.Nr = nr++;
                    log.Datum = match.Groups["Datum"].Value;
                    log.Level = match.Groups["Level"].Value;
                    log.Thread = match.Groups["Thread"].Value;
                    log.Message = match.Groups["Message"].Value;

                    //if (apiRegex.IsMatch(log.Message))
                    //{
                        //if (log.Thread == "[03472]")
                        //{
                            //this.Logs.Add(log);
                        //}

                    //}

                    this.Logs.Add(log);

                }

                foreach (var VARIABLE in this.Logs.GroupBy(l => l.Thread).Select(l => l.Key))
                {

                    this.Threads.Add(new ThreadProp() { IsSelected = true, Nr = VARIABLE });
                }

            }

            //Log log1 = new Log();
            //log1.Datum = "w";
            //log1.Level = "Debug";
            //log1.Thread = "12345";
            //log1.Message = "Messg";
            //Log log2 = new Log();
            //log2.Datum = "w2";
            //log2.Level = "Debug2";
            //log2.Thread = "123452";
            //log2.Message = "Messg2";


            //Logs.Add(log1);
            //Logs.Add(log2);
            //int counter = 0;
            //string line;
            //System.IO.StreamReader file = new System.IO.StreamReader(@"c:\Temp\PDU_API_1.log");

            //while ((line = file.ReadLine()) != null)
            //{
            //   counter++;
            //}

            //file.Close();
        }
        //public Logs Logs
    }
}
