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
using Sulakore.Protocol;
using Sulakore.Communication;

namespace FFBot
{
    public partial class Form1 : ExtensionForm
    {
		protected const int SPACE_SEL = 2570;
		protected const int FURNI_MOVE = 3267;
		protected const int FURNI_PUT = 551;

		private bool runFlag = false;
        private bool chooseFlag = false;

        private Tuple<int, int> space = new Tuple<int, int>(0, 0);

        public Form1()
        {
            // attach 
            Triggers.OutAttach(SPACE_SEL, OnSpaceSelected); // walk packet
            Triggers.InAttach(FURNI_MOVE, OnFurniPlaced); // move packet
            Triggers.InAttach(FURNI_PUT, OnFurniPlaced); // placed packet
            InitializeComponent();
        }

        // Choose Space
        private void button2_Click(object sender, EventArgs e)
        {
            chooseFlag = true;
            runFlag = false;
        }

        // Start Bot
        private void button3_Click(object sender, EventArgs e)
        {
            chooseFlag = false;
            runFlag = true;
        }

        // Stop Bot
        private void button4_Click(object sender, EventArgs e)
        {
            chooseFlag = false;
            runFlag = false;
        }

        protected void OnSpaceSelected(InterceptedEventArgs args)
        {
            if (chooseFlag)
            {
                //[0][0][0][10][7]Á[0][0][0][8][0][0][0][7]
                // block the packet
                chooseFlag = false;
                args.IsBlocked = true;

                // parse space
                byte[] data = args.Packet.ToBytes();
                space = new Tuple<int, int>(data[9], data[13]);

                // debug print space
                //string space_string = "(" + space.Item1 + ", " + space.Item2 + ")";
                //Connection.SendToServerAsync(3871, space_string, 4, 0);
            }
        }

        protected void OnFurniPlaced(InterceptedEventArgs args)
        {
            if (runFlag)
            {
                // packet ex.
                //[0][0][0]6[5]Ô {×C[0][0][0][0][0][8][0][0][0][3][0][0][0][0][0][3]0.0[0]

                // parse space
                byte[] data = args.Packet.ToBytes();
                Tuple<int, int> furni_space = new Tuple<int, int>(data[17], data[21]);

                // move to that space
                //if (space.Equals(furni_space))
                //{
                    Connection.SendToServerAsync(SPACE_SEL, furni_space.Item1, furni_space.Item2);
                //}

                // debug print space
                //string space_string = "(" + furni_space.Item1 + ", " + furni_space.Item2 + ")";
                //Connection.SendToServerAsync(3871, space_string, 4, 0);
            }
        }
    }
}
