using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Sulakore.Extensions;
using Sulakore.Protocol;
using Sulakore.Communication;
using System.Collections;

namespace TanjiExtension1
{
    public partial class Form1 : ExtensionForm
    {
		// data headers
		protected const int DANCE = 2628;
		protected const int SAY_OUT = 1403;

		private int dance = 1;
        private int msg_idx = 0;
        private bool mimicFlag = false;

		public Form1()
        {
			// start up the extension form

            Triggers.InAttach(1231, OnChatIncoming);
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // send a wave and msg packet
            string msg = "Get rekt bro!!!";
            Connection.SendToServerAsync(DANCE, 1); // dance
            for (int i = 0; i < 20; i++)
            {
                Connection.SendToServerAsync(SAY_OUT, msg, 4, 0);
                System.Threading.Thread.Sleep(750);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 400; i++)
            {
                Connection.SendToServerAsync(DANCE, dance * (i % 2)); // dance
                System.Threading.Thread.Sleep(50);
            }
            Connection.SendToServerAsync(DANCE, dance); // dance
            System.Threading.Thread.Sleep(50);
            Connection.SendToServerAsync(DANCE, dance); // dance

        }

        private void button3_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 200; i++)
            {
                if (i % 2 == 1)
                {
                    Connection.SendToServerAsync(2363, 0); // stand
                    //Connection.SendToServerAsync(3634, 1); // dance
                }
                else
                {
                    Connection.SendToServerAsync(2363, 1); // sit
                }
                System.Threading.Thread.Sleep(200);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            
            for (int i = 0; i < 50; i++)
            {
                if (i % 2 == 1)
                {
                    Connection.SendToServerAsync(3228, 127093914, 0); // candy tree
                }
                else
                {
                    Connection.SendToServerAsync(1265, 61929848); // pass candy
                }
                System.Threading.Thread.Sleep(600);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            msg_idx = 0;
            mimicFlag = true;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            mimicFlag = false;
        }

        protected void OnChatIncoming(InterceptedEventArgs obj)
        {

            if (mimicFlag)
            {
                HMessage hmsg = obj.Packet;

                // parse msg length
                byte[] data = hmsg.ToBytes();
                int n = data[11];

                // parse msg string
                List<byte> strlist = data.ToList();
                strlist = strlist.GetRange(12, n + 12);
                string char_string = Encoding.UTF8.GetString(strlist.ToArray());

                // print msg string
                Connection.SendToServerAsync(SAY_OUT, char_string, 4, msg_idx);
            }

        }

		protected void numericUpDown2_ValueChanged(object sender, EventArgs e) {
			dance = (int)numericUpDown2.Value;
            string char_string = dance.ToString();
			//Connection.SendToServerAsync(SAY_OUT, char_string, 4, msg_idx);
		}
	}
}
