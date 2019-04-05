using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace Entity101_GUI
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void bunifuCustomTextbox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void bunifuThinButton22_Click(object sender, EventArgs e)
        {

        }

        private void bunifuThinButton22_Click_1(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void bunifuThinButton21_Click(object sender, EventArgs e)
        {
            MySqlConnection con = new MySqlConnection("server=curtinfrc.duckdns.org;port=3306;user id=Entity101;Password=Brett&Sue141161422353;database=blitzen");
            con.Open();
            //MySqlCommand cmd = new MySqlCommand("select * from users where Username='" + textBox1.Text + "' and Password='" + textBox2.Text + "'", con);
            MySqlDataAdapter sda = new MySqlDataAdapter("Select Count(*) From users where Username='" + textBox1.Text + "' and Password='" + textBox2.Text + "'", con);
            DataTable dt = new DataTable();
            sda.Fill(dt);
            if (dt.Rows[0][0].ToString() == "1")
            {
                this.Hide();
                main ss = new main();
                ss.Show();
            }
            else
            {
                MessageBox.Show("Please Check your Username and Password");
            }
        }
    }
}
