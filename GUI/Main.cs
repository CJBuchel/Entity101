using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using AForge.Video;
using MySql.Data.MySqlClient;

namespace GUI
{
    public partial class Main : Form
    {
        MySqlConnection cloudcon = new MySqlConnection("server=curtinfrc.duckdns.org;port=3306;user id=entity101;password=entity101;database=entity101");
        MySqlConnection localcon = new MySqlConnection("server=localhost;user id=root;database=entity101;port=3308;persistsecurityinfo=True");
        MySqlCommand cmd;
        MySqlDataAdapter adpt;
        DataTable dt;

        MJPEGStream entity101vision;
        public Main()
        {
            InitializeComponent();
            dataGridView1.Hide();
            dataGridView2.Hide();
            pictureBox1.Show();

            entity101vision = new MJPEGStream("http://entity101vision.local:1181/stream.mjpeg");
            entity101vision.NewFrame += entity101vision_NewFrame;
        }

        void entity101vision_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            Bitmap bmp = (Bitmap)eventArgs.Frame.Clone();
            pictureBox1.Image = bmp;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            
        }

        private void bunifuFlatButton1_Click(object sender, EventArgs e)
        {
            pictureBox1.Show();
            entity101vision.Start();

            dataGridView1.Hide();
            dataGridView2.Hide();
        }

        private void bunifuFlatButton2_Click(object sender, EventArgs e)
        {
            dataGridView1.Show();

            adpt = new MySqlDataAdapter("Select * from visiondata", localcon);
            dt = new DataTable();
            adpt.Fill(dt);
            dataGridView2.DataSource = dt;

            pictureBox1.Hide();
            dataGridView2.Hide();
        }

        private void bunifuFlatButton3_Click(object sender, EventArgs e)
        {
            dataGridView2.Show();

            adpt = new MySqlDataAdapter("Select * from visiondata", cloudcon);
            dt = new DataTable();
            adpt.Fill(dt);
            dataGridView2.DataSource = dt;

            dataGridView1.Hide();
            pictureBox1.Hide();
        }

        private void bunifuFlatButton4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
