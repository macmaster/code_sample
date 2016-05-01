using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Sulakore.Extensions;
using Sulakore.Communication;
using Sulakore.Protocol;

namespace Mimic
{
    public partial class MimicForm : ExtensionForm
    {
        private bool mimicFlag = false;
        private int copyID;

        public MimicForm()
        {
            // init copy
            copyID = 0;

            // set triggers
            Triggers.InAttach(828, OnChatIncoming);
            Triggers.InAttach(3881, OnChatIncoming);
            InitializeComponent();
        }

        // flip the habbo chat string
        protected void OnChatIncoming(InterceptedEventArgs obj)
        {

            if (mimicFlag)
            {
                // byteify the packet
                HMessage hmsg = obj.Packet;
                byte[] data = hmsg.ToBytes();

                // parse msg length and sender key
                int sender = data[9] + (data[8] << 8);
                int len = data[11];

                if (sender == copyID)
                {
                    // parse msg string
                    List<byte> strlist = data.ToList();
                    strlist = strlist.GetRange(12, len + 12);
                    string char_string = Encoding.UTF8.GetString(strlist.ToArray());

                    // print msg string
                    Connection.SendToServerAsync(1143, char_string, 4, 0);
                }
            }
        }


        // shout incoming
        protected void OnShoutIncoming(InterceptedEventArgs obj)
        {

            if (mimicFlag)
            {
                // byteify the packet
                HMessage hmsg = obj.Packet;
                byte[] data = hmsg.ToBytes();

                // parse msg length and sender key
                int sender = data[9] + (data[8] << 8);
                int len = data[11];

                if (sender == copyID)
                {
                    // parse msg string
                    List<byte> strlist = data.ToList();
                    strlist = strlist.GetRange(12, len + 12);
                    string char_string = Encoding.UTF8.GetString(strlist.ToArray());

                    // print msg string
                    Connection.SendToServerAsync(1469, char_string, 4, 0);
                }
            }
        }

        private void start_Click(object sender, EventArgs e)
        {
            // clear text box and begin mimic
            copyID = (int)IDBox.Value;
            mimicFlag = true;

        }

        private void stop_Click(object sender, EventArgs e)
        {
            mimicFlag = false;
        }

    }
}
