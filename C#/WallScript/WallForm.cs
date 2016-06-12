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


namespace WallScript {
	public partial class WallForm: ExtensionForm {

		// window data
		protected int windowID;
		protected string windowFace;

		// move packet headers
		protected const int SAY_OUT = 1403;
		protected const int CLICK_WINDOW = 853;
		protected const int MOVE_WINDOW = 3492;

		public WallForm() {
			// window init
			windowID = 0;
			windowFace = "r";

			InitializeComponent();
			Triggers.OutAttach(CLICK_WINDOW, OnWindowClicked);
		}

		// Intercept the window ID on double click
		protected void OnWindowClicked(InterceptedEventArgs obj) {

			// byteify the packet
			HMessage hmsg = obj.Packet;
			byte[] data = hmsg.ToBytes();

			// parse-set the windowID 
			windowID = 0;
			windowID += (data[9] << 0);
			windowID += (data[8] << 8);
			windowID += (data[7] << 16);
			windowID += (data[6] << 24);

			Connection.SendToServerAsync(SAY_OUT, (windowID / 10000).ToString(), 0, 0);
		}

		private void faceLeft_Click(object sender, EventArgs e) {
			windowFace = "l";
		}

		private void faceRight_Click(object sender, EventArgs e) {
			windowFace = "r";
		}

		private void moveWindow_Click(object sender, EventArgs e) {
			// window params
			int w_x = (int)widthX.Value;
			int w_y = (int)widthY.Value;
			int l_x = (int)lengthX.Value;
			int l_y = (int)lengthY.Value;

			// build move string
			string move_string = ":w=" + w_x + "," + w_y + " ";
			move_string += "l=" + l_x + "," + l_y + " " + windowFace;

			// packet length
			int length = 2 + 4 + 2 + 4 + move_string.Length;
			byte[] packet = new byte[length];

			// packet length and header
			packet[0] = packet[1] = packet[2] = 0; packet[3] = (byte)(length - 4);
			packet[4] = (MOVE_WINDOW >> 8); packet[5] = (MOVE_WINDOW & 0xFF);

			// encode window ID
			packet[6] = (byte)((windowID >> 24) & 0xFF);
			packet[7] = (byte)((windowID >> 16) & 0xFF);
			packet[8] = (byte)((windowID >> 8) & 0xFF);
			packet[9] = (byte)((windowID >> 0) & 0xFF);

			// build string length encode string
			int pdx = 12, idx = 0;
			packet[10] = 0; packet[11] = (byte)(move_string.Length & 0xFF);
			while(pdx < length) {
				packet[pdx++] = (byte)move_string[idx++];
			}

			// debug print packet
			foreach(Byte b in packet) {
                Console.Write(b.ToString() + " ");
			} Console.Write("\n" + windowID + "\n");

			// test packet send by byte arr
			Connection.SendToServerAsync(packet);
		}

	}
}
