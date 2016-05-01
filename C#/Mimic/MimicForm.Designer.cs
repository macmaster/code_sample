namespace Mimic
{
    partial class MimicForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MimicForm));
            this.start = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.stop = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.IDBox = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.IDBox)).BeginInit();
            this.SuspendLayout();
            // 
            // start
            // 
            this.start.BackColor = System.Drawing.Color.Green;
            this.start.Font = new System.Drawing.Font("Comic Sans MS", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.start.Location = new System.Drawing.Point(148, 118);
            this.start.Name = "start";
            this.start.Size = new System.Drawing.Size(113, 31);
            this.start.TabIndex = 0;
            this.start.Text = "start mimic";
            this.start.UseVisualStyleBackColor = false;
            this.start.Click += new System.EventHandler(this.start_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Comic Sans MS", 20.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(24, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(255, 38);
            this.label1.TabIndex = 2;
            this.label1.Text = "Habbo Mimic v1.0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.Control;
            this.label2.Font = new System.Drawing.Font("Comic Sans MS", 10F, System.Drawing.FontStyle.Bold);
            this.label2.ForeColor = System.Drawing.SystemColors.MenuText;
            this.label2.Location = new System.Drawing.Point(39, 130);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 19);
            this.label2.TabIndex = 3;
            this.label2.Text = "Chat ID:";
            // 
            // stop
            // 
            this.stop.BackColor = System.Drawing.Color.Red;
            this.stop.Font = new System.Drawing.Font("Comic Sans MS", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.stop.Location = new System.Drawing.Point(148, 161);
            this.stop.Name = "stop";
            this.stop.Size = new System.Drawing.Size(113, 31);
            this.stop.TabIndex = 4;
            this.stop.Text = "stop mimic";
            this.stop.UseVisualStyleBackColor = false;
            this.stop.Click += new System.EventHandler(this.stop_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Control;
            this.label3.Font = new System.Drawing.Font("Comic Sans MS", 10F, System.Drawing.FontStyle.Bold);
            this.label3.ForeColor = System.Drawing.SystemColors.MenuText;
            this.label3.Location = new System.Drawing.Point(74, 47);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(157, 19);
            this.label3.TabIndex = 5;
            this.label3.Text = "By: Ronny Macmaster";
            // 
            // IDBox
            // 
            this.IDBox.Location = new System.Drawing.Point(59, 152);
            this.IDBox.Maximum = new decimal(new int[] {
            2147483647,
            0,
            0,
            0});
            this.IDBox.Name = "IDBox";
            this.IDBox.Size = new System.Drawing.Size(37, 20);
            this.IDBox.TabIndex = 6;
            // 
            // MimicForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(301, 301);
            this.Controls.Add(this.IDBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.stop);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.start);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MimicForm";
            this.Text = "Habbo Mimic v1.0";
            ((System.ComponentModel.ISupportInitialize)(this.IDBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button start;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button stop;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown IDBox;
    }
}

