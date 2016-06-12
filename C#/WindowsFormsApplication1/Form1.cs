using System;
using System.Threading;
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

namespace WindowsFormsApplication1 {
	public partial class Form1: ExtensionForm {
		
		// packet headers
		protected const int MOVE = 845;
		protected const int THEY_MOVE = 3748;

		private int circleID, x, y;

		public Form1() {
			// init coordinate vals
			circleID = x = y = 0;

			Triggers.InAttach(THEY_MOVE, OnPersonMove);
			InitializeComponent();
		}

		private void circle_Click(object sender, EventArgs e) {
			Thread newThread = new Thread(this.CirclePerson);
			newThread.Start();
		}

		protected void OnPersonMove(InterceptedEventArgs obj) {
			// byteify the packet
			HMessage hmsg = obj.Packet;
			byte[] data = hmsg.ToBytes();

			// parse msg length and sender key
			int sender = data[9] + (data[8] << 8);

			if(sender == circleID) {
				// set new center
				x = data[13];
				y = data[17];
			}
		}

		private void CirclePerson() {
			circleID = (int)numericUpDown4.Value;
			x = (int)numericUpDown3.Value;
			y = (int)numericUpDown2.Value;
			int n = (int)numericUpDown1.Value;
			for(int i = 0; i < n * 4; i++) {
				switch(i % 4) {
					case 0:
						//Console.WriteLine((x - 1).ToString() + " " + (y + 1).ToString());
						Connection.SendToServerAsync(MOVE, x - 1, y + 1); // move 0
						break;
					case 1:
						//Console.WriteLine((x + 1).ToString() + " " + (y + 1).ToString());
						Connection.SendToServerAsync(MOVE, x + 1, y + 1); // move 1
						break;
					case 2:
						//Console.WriteLine((x + 1).ToString() + " " + (y - 1).ToString());
						Connection.SendToServerAsync(MOVE, x + 1, y - 1); // move 2
						break;
					case 3:
						//Console.WriteLine((x - 1).ToString() + " " + (y - 1).ToString());
						Connection.SendToServerAsync(MOVE, x - 1, y - 1); // move 3
						break;
				}
				System.Threading.Thread.Sleep(1000);
			}
		}

	}
}
