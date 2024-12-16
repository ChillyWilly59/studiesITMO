using System;
using System.Windows;

namespace CalculatorApp
{
    public partial class EquationDialog : Window
    {
        public double A { get; set; }
        public double B { get; set; }
        public double C { get; set; }

        public EquationDialog()
        {
            InitializeComponent();
        }

        private void SolveButton_Click(object sender, RoutedEventArgs e)
        {
            if (double.TryParse(AInput.Text, out double a) &&
                double.TryParse(BInput.Text, out double b) &&
                double.TryParse(CInput.Text, out double c))
            {
                A = a;
                B = b;
                C = c;
                this.DialogResult = true;
                this.Close();
            }
            else
            {
                MessageBox.Show("Введите корректные значения для коэффициентов.");
            }
        }
    }
}
