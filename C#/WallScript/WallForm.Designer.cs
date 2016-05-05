namespace WallScript {
	partial class WallForm {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if(disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.widthX = new System.Windows.Forms.NumericUpDown();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.widthY = new System.Windows.Forms.NumericUpDown();
			this.label4 = new System.Windows.Forms.Label();
			this.lengthX = new System.Windows.Forms.NumericUpDown();
			this.label5 = new System.Windows.Forms.Label();
			this.lengthY = new System.Windows.Forms.NumericUpDown();
			this.faceRight = new System.Windows.Forms.Button();
			this.faceLeft = new System.Windows.Forms.Button();
			this.moveWindow = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.widthX)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.widthY)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.lengthX)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.lengthY)).BeginInit();
			this.SuspendLayout();
			// 
			// widthX
			// 
			this.widthX.Location = new System.Drawing.Point(69, 92);
			this.widthX.Name = "widthX";
			this.widthX.Size = new System.Drawing.Size(32, 20);
			this.widthX.TabIndex = 0;
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Font = new System.Drawing.Font("Comic Sans MS", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.ForeColor = System.Drawing.Color.Red;
			this.label2.Location = new System.Drawing.Point(12, 85);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(51, 27);
			this.label2.TabIndex = 3;
			this.label2.Text = "W.x";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Font = new System.Drawing.Font("Comic Sans MS", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
			this.label3.Location = new System.Drawing.Point(12, 114);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(51, 27);
			this.label3.TabIndex = 6;
			this.label3.Text = "W.y";
			// 
			// widthY
			// 
			this.widthY.Location = new System.Drawing.Point(69, 121);
			this.widthY.Name = "widthY";
			this.widthY.Size = new System.Drawing.Size(32, 20);
			this.widthY.TabIndex = 5;
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Font = new System.Drawing.Font("Comic Sans MS", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label4.ForeColor = System.Drawing.Color.Red;
			this.label4.Location = new System.Drawing.Point(177, 85);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(41, 27);
			this.label4.TabIndex = 8;
			this.label4.Text = "L.x";
			// 
			// lengthX
			// 
			this.lengthX.Location = new System.Drawing.Point(224, 91);
			this.lengthX.Name = "lengthX";
			this.lengthX.Size = new System.Drawing.Size(32, 20);
			this.lengthX.TabIndex = 7;
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Font = new System.Drawing.Font("Comic Sans MS", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label5.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
			this.label5.Location = new System.Drawing.Point(177, 114);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(41, 27);
			this.label5.TabIndex = 10;
			this.label5.Text = "L.y";
			// 
			// lengthY
			// 
			this.lengthY.Location = new System.Drawing.Point(224, 120);
			this.lengthY.Name = "lengthY";
			this.lengthY.Size = new System.Drawing.Size(32, 20);
			this.lengthY.TabIndex = 9;
			// 
			// faceRight
			// 
			this.faceRight.BackColor = System.Drawing.Color.Gray;
			this.faceRight.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.faceRight.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(0)))));
			this.faceRight.Location = new System.Drawing.Point(167, 147);
			this.faceRight.Name = "faceRight";
			this.faceRight.Size = new System.Drawing.Size(105, 32);
			this.faceRight.TabIndex = 11;
			this.faceRight.Text = "face right";
			this.faceRight.UseVisualStyleBackColor = false;
			this.faceRight.Click += new System.EventHandler(this.faceRight_Click);
			// 
			// faceLeft
			// 
			this.faceLeft.BackColor = System.Drawing.Color.Gray;
			this.faceLeft.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.faceLeft.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(0)))));
			this.faceLeft.Location = new System.Drawing.Point(12, 147);
			this.faceLeft.Name = "faceLeft";
			this.faceLeft.Size = new System.Drawing.Size(105, 32);
			this.faceLeft.TabIndex = 12;
			this.faceLeft.Text = "face left";
			this.faceLeft.UseVisualStyleBackColor = false;
			this.faceLeft.Click += new System.EventHandler(this.faceLeft_Click);
			// 
			// moveWindow
			// 
			this.moveWindow.BackColor = System.Drawing.Color.LimeGreen;
			this.moveWindow.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.moveWindow.ForeColor = System.Drawing.Color.Black;
			this.moveWindow.Location = new System.Drawing.Point(78, 217);
			this.moveWindow.Name = "moveWindow";
			this.moveWindow.Size = new System.Drawing.Size(129, 32);
			this.moveWindow.TabIndex = 13;
			this.moveWindow.Text = "move window";
			this.moveWindow.UseVisualStyleBackColor = false;
			this.moveWindow.Click += new System.EventHandler(this.moveWindow_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.ForeColor = System.Drawing.Color.Red;
			this.label1.Location = new System.Drawing.Point(13, 9);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(246, 23);
			this.label1.TabIndex = 14;
			this.label1.Text = "Ronny\'s Window Scripter v1.0";
			this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			// 
			// WallForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackgroundImage = global::WallScript.Properties.Resources._20150814_175703;
			this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
			this.ClientSize = new System.Drawing.Size(284, 261);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.moveWindow);
			this.Controls.Add(this.faceLeft);
			this.Controls.Add(this.faceRight);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.lengthY);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.lengthX);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.widthY);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.widthX);
			this.Name = "WallForm";
			this.Text = "Window Scripter";
			((System.ComponentModel.ISupportInitialize)(this.widthX)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.widthY)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.lengthX)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.lengthY)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.NumericUpDown widthX;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.NumericUpDown widthY;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.NumericUpDown lengthX;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.NumericUpDown lengthY;
		private System.Windows.Forms.Button faceRight;
		private System.Windows.Forms.Button faceLeft;
		private System.Windows.Forms.Button moveWindow;
		private System.Windows.Forms.Label label1;
	}
}

