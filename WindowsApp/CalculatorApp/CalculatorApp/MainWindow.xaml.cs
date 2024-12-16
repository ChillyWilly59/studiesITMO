using System;
using System.Windows;
using System.Windows.Input;

namespace CalculatorApp
{
    public partial class MainWindow : Window
    {
        private string _input = string.Empty; // Текущий ввод
        private string _operator = string.Empty; // Последний оператор
        private double _result = 0; // Результат вычислений

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var button = sender as System.Windows.Controls.Button;
            string value = button.Content.ToString();

            if (double.TryParse(value, out _))
            {
                _input += value;
                Display.Text = _input;
            }
            else 
            {
                if (_operator != string.Empty && _input != string.Empty)
                {
                    Calculate();
                }

                _operator = value;
                _result = double.TryParse(_input, out _) ? double.Parse(_input) : _result;
                _input = string.Empty;
            }
        }

        private void Button_Equals(object sender, RoutedEventArgs e)
        {
            if (_input != string.Empty)
            {
                Calculate();
                Display.Text = _result.ToString();
                _operator = string.Empty;
                _input = string.Empty;
            }
        }

        private void Button_Clear(object sender, RoutedEventArgs e)
        {
            _input = string.Empty;
            _operator = string.Empty;
            _result = 0;
            Display.Text = "0";
        }

        private void Calculate()
        {
            double secondOperand = double.TryParse(_input, out _) ? double.Parse(_input) : 0;

            try
            {
                switch (_operator)
                {
                    case "+":
                        _result += secondOperand;
                        break;
                    case "-":
                        _result -= secondOperand;
                        break;
                    case "*":
                        _result *= secondOperand;
                        break;
                    case "/":
                        if (secondOperand == 0)
                        {
                            throw new DivideByZeroException("Деление на ноль невозможно.");
                        }
                        _result /= secondOperand;
                        break;
                }

                _input = string.Empty; 
            }
            catch (Exception ex)
            {
                Display.Text = "Ошибка: " + ex.Message;  
                _input = string.Empty;
                _operator = string.Empty;
                _result = 0;
            }
        }

        private void Window_PreviewKeyDown(object sender, System.Windows.Input.KeyEventArgs e)
        {
            string key = e.Key.ToString();

            if ((key.StartsWith("D") && key.Length == 2 && char.IsDigit(key[1])) ||
                (key.StartsWith("NumPad") && key.Length == 7 && char.IsDigit(key[6])))
            {
                string number = key.StartsWith("D") ? key[1].ToString() : key[6].ToString();
                _input += number;
                Display.Text = _input;
            }
            else if (e.Key == Key.Add)
            {
                ProcessOperator("+");
            }
            else if (e.Key == Key.Subtract) 
            {
                ProcessOperator("-");
            }
            else if (e.Key == Key.Multiply) 
            {
                ProcessOperator("*");
            }
            else if (e.Key == Key.Divide)
            {
                ProcessOperator("/");
            }
            else if (e.Key == Key.Return || e.Key == Key.Enter)
            {
                Button_Equals(null, null);
            }
            else if (e.Key == Key.Back)
            {
                if (_input.Length > 0)
                {
                    _input = _input.Substring(0, _input.Length - 1);
                    Display.Text = _input.Length > 0 ? _input : "0";
                }
            }
            else if (e.Key == Key.Escape)
            {
                Button_Clear(null, null);
            }
            else if (e.Key == Key.Decimal || e.Key == Key.OemPeriod || e.Key == Key.OemComma)
            {
                if (!_input.Contains(",") && !_input.Contains("."))
                {
                    string separator = System.Globalization.CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator;
                    _input += separator;
                    Display.Text = _input;
                }
            }
        }
        private void ProcessOperator(string operatorSymbol)
        {
            if (_operator != string.Empty && _input != string.Empty)
            {
                Calculate();
            }

            _operator = operatorSymbol;
            _result = double.TryParse(_input, out _) ? double.Parse(_input) : _result;
            _input = string.Empty;
        }

    }
}
