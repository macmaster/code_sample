using System;
using System.Windows.Forms;
using System.Diagnostics;

namespace PictureViewer {
    public partial class PictureViewer : Form {
        public PictureViewer() {
            InitializeComponent();
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e) {

        }

        /** 
         * Show an "open file" popup.
         * Load the picture into the picture box if they hit OK.
         */
        private void pictureButton_Click(object sender, EventArgs e) {
            Debug.WriteLine("picture button handler...");
            if(openFileDialog.ShowDialog() == DialogResult.OK) {
                pictureBox.Load(openFileDialog.FileName);
            }
        }

        /** 
         * Erase the picture from the picture box
         */
        private void clearButton_Click(object sender, EventArgs e) {
            Debug.WriteLine("clear button handler...");
            pictureBox.Image = null;
        }

        /** 
         * Show a "choose color" popup.
         * Set the picture box background color if they hit OK.
         */
        private void backgroundButton_Click(object sender, EventArgs e) {
            Debug.WriteLine("background button handler...");
            if(colorDialog.ShowDialog() == DialogResult.OK) {
                pictureBox.BackColor = colorDialog.Color;
            }
        }

        /**
         * Close the application
         */
        private void closeButton_Click(object sender, EventArgs e) {
            Debug.WriteLine("close button handler...");
            this.Close();
        }

        /**
         * Toggle the picture's property between stretch and normal.
         */
        private void stretchCheckbox_CheckedChanged(object sender, EventArgs e) {
            Debug.WriteLine("stretch box handler...");
            if(stretchCheckbox.Checked) {
                pictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
            } else {
                pictureBox.SizeMode = PictureBoxSizeMode.Normal;
            }
        }
    }
}
