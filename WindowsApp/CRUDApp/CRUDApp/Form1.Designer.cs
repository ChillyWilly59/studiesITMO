using System;
using System.Data;
using System.Windows.Forms;
using Npgsql;

namespace CRUDApp
{
    public partial class Form1 : Form
    {
        private DataGridView dgvData;
        private TextBox txtHost, txtUser, txtPass, txtDb, txtId, txtName, txtPrice;
        private Button btnConnect, btnLoad, btnInsert, btnUpdate, btnDelete;
        private Label lblStatus;

        private string connectionString = "Host=localhost;Username=postgres;Password=postgres;Database=crudApp";
        private bool isConnected = false;


        private void InitializeComponent()
        {
            SetupUI();
        }

        private void SetupUI()
        {
            this.Size = new System.Drawing.Size(800, 600);
            this.Text = "PostgreSQL CRUD Client";

            int y = 10;
            CreateLabel("Хост:", 10, y); txtHost = CreateInput("localhost", 60, y);
            CreateLabel("User:", 170, y); txtUser = CreateInput("postgres", 210, y);
            CreateLabel("Pass:", 320, y); txtPass = CreateInput("1234", 360, y); txtPass.PasswordChar = '*';
            CreateLabel("DB:", 470, y); txtDb = CreateInput("postgres", 500, y);

            btnConnect = new Button() { Text = "Подключиться", Location = new System.Drawing.Point(620, y - 2), Width = 100 };
            btnConnect.Click += BtnConnect_Click;
            this.Controls.Add(btnConnect);

            dgvData = new DataGridView()
            {
                Location = new System.Drawing.Point(10, 50),
                Size = new System.Drawing.Size(760, 300),
                ReadOnly = true,
                AllowUserToAddRows = false,
                SelectionMode = DataGridViewSelectionMode.FullRowSelect
            };
            this.Controls.Add(dgvData);
            dgvData.SelectionChanged += DgvData_SelectionChanged;

            y = 370;
            CreateLabel("ID:", 10, y); txtId = CreateInput("", 130, y); txtId.ReadOnly = true;
            CreateLabel("Название:", 250, y); txtName = CreateInput("", 320, y);
            CreateLabel("Цена:", 440, y); txtPrice = CreateInput("", 490, y);

            y = 410;
            btnLoad = CreateButton("Обновить", 10, y, BtnLoad_Click);
            btnInsert = CreateButton("Добавить", 150, y, BtnInsert_Click);
            btnUpdate = CreateButton("Изменить", 260, y, BtnUpdate_Click);
            btnDelete = CreateButton("Удалить", 370, y, BtnDelete_Click);

            SetButtonsEnabled(false);

            lblStatus = new Label()
            {
                Location = new System.Drawing.Point(10, 530),
                Size = new System.Drawing.Size(760, 20),
                Text = "Статус: Не подключено",
                BorderStyle = BorderStyle.FixedSingle
            };
            this.Controls.Add(lblStatus);
        }

        private void SetButtonsEnabled(bool enabled)
        {
            btnLoad.Enabled = enabled;
            btnInsert.Enabled = enabled;
            btnUpdate.Enabled = enabled;
            btnDelete.Enabled = enabled;
            dgvData.Enabled = enabled;
            txtName.Enabled = enabled;
            txtPrice.Enabled = enabled;
        }

        private bool TestConnection(string connString)
        {
            try
            {
                using (var conn = new NpgsqlConnection(connString))
                {
                    conn.Open();
                    return true;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка тестирования подключения:\n{ex.Message}",
                    "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
        }

        private void BtnConnect_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtHost.Text) ||
                string.IsNullOrWhiteSpace(txtUser.Text) ||
                string.IsNullOrWhiteSpace(txtDb.Text))
            {
                MessageBox.Show("Заполните обязательные поля: Хост, User и DB",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            connectionString = $"Host={txtHost.Text};Username={txtUser.Text};Password={txtPass.Text};Database={txtDb.Text}";

            Cursor = Cursors.WaitCursor;
            lblStatus.Text = "Статус: Подключение...";
            Application.DoEvents();

            try
            {
                if (TestConnection(connectionString))
                {
                    isConnected = true;
                    lblStatus.Text = $"Статус: Подключено к {txtDb.Text}";
                    SetButtonsEnabled(true);
                    LoadData();
                    MessageBox.Show("Подключение успешно установлено!",
                        "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    isConnected = false;
                    SetButtonsEnabled(false);
                    lblStatus.Text = "Статус: Ошибка подключения";
                }
            }
            finally
            {
                Cursor = Cursors.Default;
            }
        }

        private void BtnLoad_Click(object sender, EventArgs e)
        {
            if (!isConnected)
            {
                MessageBox.Show("Сначала подключитесь к базе данных",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            LoadData();
        }

        private void LoadData()
        {
            if (!isConnected || string.IsNullOrEmpty(connectionString))
            {
                lblStatus.Text = "Статус: Нет подключения";
                return;
            }

            try
            {
                Cursor = Cursors.WaitCursor;
                lblStatus.Text = "Статус: Загрузка данных...";
                Application.DoEvents();

                using (var conn = new NpgsqlConnection(connectionString))
                {
                    conn.Open();
                    string sql = "SELECT * FROM products ORDER BY id";
                    using (var da = new NpgsqlDataAdapter(sql, conn))
                    {
                        DataTable dt = new DataTable();
                        da.Fill(dt);
                        dgvData.DataSource = dt;
                    }
                }
                lblStatus.Text = $"Статус: Загружено {dgvData.RowCount} записей";
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка чтения данных:\n{ex.Message}",
                    "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                lblStatus.Text = "Статус: Ошибка загрузки";
            }
            finally
            {
                Cursor = Cursors.Default;
            }
        }

        private bool ValidateInput()
        {
            if (string.IsNullOrWhiteSpace(txtName.Text))
            {
                MessageBox.Show("Введите название",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                txtName.Focus();
                return false;
            }

            if (!decimal.TryParse(txtPrice.Text, out decimal price) || price < 0)
            {
                MessageBox.Show("Введите корректную цену (положительное число)",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                txtPrice.Focus();
                txtPrice.SelectAll();
                return false;
            }

            return true;
        }

        private void BtnInsert_Click(object sender, EventArgs e)
        {
            if (!isConnected)
            {
                MessageBox.Show("Сначала подключитесь к базе данных",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            if (!ValidateInput()) return;

            ExecuteQuery("INSERT INTO products (name, price) VALUES (@p1, @p2)");
        }

        private void BtnUpdate_Click(object sender, EventArgs e)
        {
            if (!isConnected)
            {
                MessageBox.Show("Сначала подключитесь к базе данных",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            if (string.IsNullOrEmpty(txtId.Text))
            {
                MessageBox.Show("Выберите запись для изменения",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            if (!ValidateInput()) return;

            ExecuteQuery("UPDATE products SET name = @p1, price = @p2 WHERE id = @id", true);
        }

        private void BtnDelete_Click(object sender, EventArgs e)
        {
            if (!isConnected)
            {
                MessageBox.Show("Сначала подключитесь к базе данных",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            if (string.IsNullOrEmpty(txtId.Text))
            {
                MessageBox.Show("Выберите запись для удаления",
                    "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            var result = MessageBox.Show("Удалить выбранную запись?",
                "Подтверждение", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {
                ExecuteQuery("DELETE FROM products WHERE id = @id", isDelete: true);
            }
        }

        private void ExecuteQuery(string sql, bool useId = false, bool isDelete = false)
        {
            if (!isConnected || string.IsNullOrEmpty(connectionString)) return;

            try
            {
                using (var conn = new NpgsqlConnection(connectionString))
                {
                    conn.Open();
                    using (var cmd = new NpgsqlCommand(sql, conn))
                    {
                        if (!isDelete)
                        {
                            cmd.Parameters.AddWithValue("p1", txtName.Text);
                            decimal.TryParse(txtPrice.Text, out decimal price);
                            cmd.Parameters.AddWithValue("p2", price);
                        }

                        if (useId || isDelete)
                        {
                            int.TryParse(txtId.Text, out int id);
                            cmd.Parameters.AddWithValue("id", id);
                        }

                        int rowsAffected = cmd.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            LoadData();
                            ClearInputs();
                            lblStatus.Text = "Статус: Операция выполнена успешно";
                        }
                        else
                        {
                            lblStatus.Text = "Статус: Запись не найдена";
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка операции:\n{ex.Message}",
                    "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                lblStatus.Text = "Статус: Ошибка операции";
            }
        }

        private void DgvData_SelectionChanged(object sender, EventArgs e)
        {
            if (dgvData.SelectedRows.Count > 0)
            {
                var row = dgvData.SelectedRows[0];
                txtId.Text = row.Cells["id"].Value?.ToString() ?? "";
                txtName.Text = row.Cells["name"].Value?.ToString() ?? "";
                txtPrice.Text = row.Cells["price"].Value?.ToString() ?? "";
            }
        }

        private void ClearInputs()
        {
            txtId.Text = "";
            txtName.Text = "";
            txtPrice.Text = "";
        }

        private TextBox CreateInput(string text, int x, int y)
        {
            var t = new TextBox()
            {
                Text = text,
                Location = new System.Drawing.Point(x, y),
                Width = 100
            };
            this.Controls.Add(t);
            return t;
        }

        private void CreateLabel(string text, int x, int y)
        {
            this.Controls.Add(new Label()
            {
                Text = text,
                Location = new System.Drawing.Point(x, y),
                AutoSize = true
            });
        }

        private Button CreateButton(string text, int x, int y, EventHandler evt)
        {
            var b = new Button()
            {
                Text = text,
                Location = new System.Drawing.Point(x, y),
                Width = 100
            };
            b.Click += evt;
            this.Controls.Add(b);
            return b;
        }
    }
}