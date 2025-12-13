import tkinter as tk
from tkinter import ttk, messagebox
import customtkinter as ctk
import psycopg2
from config import DB_CONFIG, EARTH_RADIUS_KM

ctk.set_appearance_mode("System")
ctk.set_default_color_theme("blue")


class AirportApp(ctk.CTk):
    def __init__(self):
        super().__init__()

        self.title("Приложение для работы с Аэропортами (Вариант 2)")
        self.geometry("1100x650")

        self.conn = None
        self.connect_db()

        self.grid_columnconfigure(0, weight=0)
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        self.create_widgets()
        self.load_initial_data()

    def connect_db(self):
        try:
            self.conn = psycopg2.connect(**DB_CONFIG)
            self.conn.autocommit = True
            print("Соединение с БД установлено.")
        except psycopg2.OperationalError as e:
            messagebox.showerror(
                "Ошибка БД",
                f"Не удалось подключиться к базе данных. Проверьте config.py и запуск PostgreSQL.\nДетали: {e}"
            )
            self.destroy()

    def on_closing(self):
        if self.conn:
            self.conn.close()
            print("Соединение с БД закрыто. Выход из приложения.")
        self.destroy()

    def create_widgets(self):

        self.sidebar_frame = ctk.CTkFrame(self, width=300, corner_radius=0)
        self.sidebar_frame.grid(row=0, column=0, sticky="nsew")
        self.sidebar_frame.grid_rowconfigure(9, weight=1)

        ctk.CTkLabel(self.sidebar_frame, text="🔍 Поиск и Фильтры",
                     font=ctk.CTkFont(size=18, weight="bold")).grid(row=0, column=0, padx=20, pady=(20, 10))

        ctk.CTkLabel(self.sidebar_frame, text="Город или Страна:", anchor="w").grid(row=1, column=0, padx=20,
                                                                                    pady=(10, 0), sticky="ew")
        self.city_country_entry = ctk.CTkEntry(self.sidebar_frame, placeholder_text="Например: London, United States")
        self.city_country_entry.grid(row=2, column=0, padx=20, pady=(0, 10), sticky="ew")

        ctk.CTkLabel(self.sidebar_frame, text="Диапазон координат:", anchor="w").grid(row=3, column=0, padx=20,
                                                                                      pady=(10, 0), sticky="ew")

        lat_frame = ctk.CTkFrame(self.sidebar_frame)
        lat_frame.grid(row=4, column=0, padx=20, pady=(0, 5), sticky="ew")
        ctk.CTkLabel(lat_frame, text="Широта (min/max):").pack(side="left", padx=(0, 5))
        self.lat_min_entry = ctk.CTkEntry(lat_frame, width=60, placeholder_text="-90")
        self.lat_min_entry.pack(side="left", fill="x", expand=True)
        self.lat_max_entry = ctk.CTkEntry(lat_frame, width=60, placeholder_text="90")
        self.lat_max_entry.pack(side="right", fill="x", expand=True, padx=(5, 0))

        lon_frame = ctk.CTkFrame(self.sidebar_frame)
        lon_frame.grid(row=5, column=0, padx=20, pady=(0, 10), sticky="ew")
        ctk.CTkLabel(lon_frame, text="Долгота (min/max):").pack(side="left", padx=(0, 5))
        self.lon_min_entry = ctk.CTkEntry(lon_frame, width=60, placeholder_text="-180")
        self.lon_min_entry.pack(side="left", fill="x", expand=True)
        self.lon_max_entry = ctk.CTkEntry(lon_frame, width=60, placeholder_text="180")
        self.lon_max_entry.pack(side="right", fill="x", expand=True, padx=(5, 0))

        self.filter_button = ctk.CTkButton(self.sidebar_frame, text="Применить Фильтр/Поиск",
                                           command=self.apply_filters)
        self.filter_button.grid(row=6, column=0, padx=20, pady=10, sticky="ew")

        self.reset_button = ctk.CTkButton(self.sidebar_frame, text="Сбросить Фильтры", command=self.load_initial_data,
                                          fg_color="gray50")
        self.reset_button.grid(row=7, column=0, padx=20, pady=(0, 20), sticky="ew")

        self.exit_button = ctk.CTkButton(self.sidebar_frame, text="Выход", command=self.on_closing, fg_color="red")
        self.exit_button.grid(row=10, column=0, padx=20, pady=(20, 20), sticky="ew")

        self.main_frame = ctk.CTkFrame(self)
        self.main_frame.grid(row=0, column=1, sticky="nsew", padx=10, pady=10)
        self.main_frame.grid_columnconfigure(0, weight=1)
        self.main_frame.grid_rowconfigure(1, weight=1)

        ctk.CTkLabel(self.main_frame, text="🛬 Результаты поиска Аэропортов",
                     font=ctk.CTkFont(size=20, weight="bold")).grid(row=0, column=0, padx=10, pady=(5, 5), sticky="w")

        style = ttk.Style(self)
        style.theme_use("default")
        style.configure("Treeview",
                        background="#2A2D2E",
                        foreground="white",
                        rowheight=25,
                        fieldbackground="#2A2D2E",
                        bordercolor="#3E444A",
                        borderwidth=1)
        style.map('Treeview', background=[('selected', '#1F6AA5')])

        self.tree = ttk.Treeview(self.main_frame, columns=("City", "Country", "IATA", "Lat", "Lon"), show="headings")
        self.tree.grid(row=1, column=0, sticky="nsew", padx=10, pady=10)

        self.tree.heading("City", text="Город", anchor=tk.W)
        self.tree.heading("Country", text="Страна", anchor=tk.W)
        self.tree.heading("IATA", text="IATA", anchor=tk.CENTER)
        self.tree.heading("Lat", text="Широта", anchor=tk.CENTER)
        self.tree.heading("Lon", text="Долгота", anchor=tk.CENTER)

        self.tree.column("City", width=200, anchor=tk.W)
        self.tree.column("Country", width=150, anchor=tk.W)
        self.tree.column("IATA", width=80, anchor=tk.CENTER)
        self.tree.column("Lat", width=100, anchor=tk.CENTER)
        self.tree.column("Lon", width=100, anchor=tk.CENTER)

        self.tree.bind("<Double-1>", self.show_details)

        vsb = ttk.Scrollbar(self.main_frame, orient="vertical", command=self.tree.yview)
        vsb.grid(row=1, column=1, sticky='ns', padx=(0, 10), pady=10)
        self.tree.configure(yscrollcommand=vsb.set)

        ctk.CTkLabel(self.main_frame, text="✈️ Поиск Маршрутов (Прямые рейсы)",
                     font=ctk.CTkFont(size=18, weight="bold")).grid(row=2, column=0, padx=10, pady=(15, 5), sticky="w")

        route_frame = ctk.CTkFrame(self.main_frame)
        route_frame.grid(row=3, column=0, sticky="ew", padx=10, pady=(0, 10))

        ctk.CTkLabel(route_frame, text="Из города:").pack(side="left", padx=(10, 5))
        self.city_from_entry = ctk.CTkEntry(route_frame, placeholder_text="Город отправления")
        self.city_from_entry.pack(side="left", fill="x", expand=True, padx=(0, 10))

        ctk.CTkLabel(route_frame, text="В город:").pack(side="left", padx=(10, 5))
        self.city_to_entry = ctk.CTkEntry(route_frame, placeholder_text="Город прибытия")
        self.city_to_entry.pack(side="left", fill="x", expand=True, padx=(0, 10))

        self.route_button = ctk.CTkButton(route_frame, text="Найти Рейсы", command=self.find_routes, width=150)
        self.route_button.pack(side="left", padx=(10, 10))

    def execute_query(self, query, params=None):
        if not self.conn:
            return None

        try:
            with self.conn.cursor() as cur:
                cur.execute(query, params)
                if query.strip().upper().startswith("SELECT"):
                    return cur.fetchall()
                return True
        except psycopg2.Error as e:
            messagebox.showerror("Ошибка SQL", f"Ошибка при выполнении запроса: {e}")
            return None

    def load_initial_data(self):
        self.city_country_entry.delete(0, tk.END)
        self.lat_min_entry.delete(0, tk.END)
        self.lat_max_entry.delete(0, tk.END)
        self.lon_min_entry.delete(0, tk.END)
        self.lon_max_entry.delete(0, tk.END)

        query = "SELECT city, country, iata_code, latitude, longitude, airport_id FROM airports LIMIT 50;"
        results = self.execute_query(query)

        self.update_treeview(results)

    def apply_filters(self):
        search_text = self.city_country_entry.get().strip()
        lat_min = self.lat_min_entry.get().strip()
        lat_max = self.lat_max_entry.get().strip()
        lon_min = self.lon_min_entry.get().strip()
        lon_max = self.lon_max_entry.get().strip()

        where_clauses = []
        params = []

        if search_text:
            search_pattern = f"%{search_text}%"
            where_clauses.append("(city ILIKE %s OR country ILIKE %s)")
            params.extend([search_pattern, search_pattern])

        if lat_min and lat_max:
            try:
                lat_min_val = float(lat_min)
                lat_max_val = float(lat_max)
                where_clauses.append("latitude BETWEEN %s AND %s")
                params.extend([lat_min_val, lat_max_val])
            except ValueError:
                messagebox.showwarning("Ошибка ввода", "Широта должна быть числом.")
                return

        if lon_min and lon_max:
            try:
                lon_min_val = float(lon_min)
                lon_max_val = float(lon_max)
                where_clauses.append("longitude BETWEEN %s AND %s")
                params.extend([lon_min_val, lon_max_val])
            except ValueError:
                messagebox.showwarning("Ошибка ввода", "Долгота должна быть числом.")
                return

        query = """
            SELECT city, country, iata_code, latitude, longitude, airport_id
            FROM airports
        """
        if where_clauses:
            query += " WHERE " + " AND ".join(where_clauses)

        query += " LIMIT 500;"

        results = self.execute_query(query, tuple(params))
        self.update_treeview(results)

    def show_details(self, event):
        selected_item = self.tree.focus()
        if not selected_item:
            return

        values = self.tree.item(selected_item, 'values')
        airport_id = self.tree.item(selected_item, 'text')

        query = "SELECT * FROM airports WHERE airport_id = %s;"
        details = self.execute_query(query, (airport_id,))

        if details:
            data = details[0]

            detail_text = (
                f"--- Подробная информация об Аэропорте ---\n"
                f"ID: {data[0]}\n"
                f"Название: {data[1]}\n"
                f"Город: {data[2]}\n"
                f"Страна: {data[3]}\n"
                f"Код IATA: {data[4]}\n"
                f"Код ICAO: {data[5]}\n"
                f"Широта: {data[6]}\n"
                f"Долгота: {data[7]}\n"
                f"Высота (футы): {data[8] or 'N/A'}\n"
                f"Часовой пояс: {data[11] or 'N/A'}\n"
                f"Тип: {data[12]}\n"
            )

            messagebox.showinfo(f"Детали: {data[1]}", detail_text)

    def find_routes(self):
        city_from = self.city_from_entry.get().strip()
        city_to = self.city_to_entry.get().strip()

        if not city_from or not city_to:
            messagebox.showwarning("Ввод", "Пожалуйста, введите оба города.")
            return

        sql = """
        SELECT 
            al.name AS airline_name,
            a_from.name AS from_airport, 
            a_to.name AS to_airport,
            r.stops
        FROM 
            routes r
        JOIN 
            airports a_from ON r.source_airport_id = a_from.airport_id
        JOIN 
            airports a_to ON r.destination_airport_id = a_to.airport_id
        JOIN 
            airlines al ON r.airline_id = al.airline_id
        WHERE 
            a_from.city ILIKE %s AND a_to.city ILIKE %s
        LIMIT 100;
        """

        params = (f"%{city_from}%", f"%{city_to}%")
        results = self.execute_query(sql, params)

        if results:
            route_list = []
            for i, row in enumerate(results[:10]):
                airline, from_ap, to_ap, stops = row
                stops_text = f"{stops} пересадка(и)" if stops is not None and stops > 0 else "Прямой"
                route_list.append(f"Авиакомпания: {airline}\n  -> Из: {from_ap}\n  -> В: {to_ap} ({stops_text})")

            total_found = len(results)

            header = f"✈️ Найдено {total_found} прямых маршрутов между {city_from} и {city_to}:"

            messagebox.showinfo(
                "Поиск Рейсов Успешен",
                f"{header}\n---\n" + "\n---\n".join(route_list) + (
                    f"\n\nПоказаны первые 10 из {total_found}." if total_found > 10 else "")
            )
        else:
            messagebox.showinfo(
                "Поиск Рейсов",
                f"❌ Прямые маршруты между городами '{city_from}' и '{city_to}' не найдены.\n\n"
                f"Возможно, нужно проверить точное написание города или поискать рейсы с пересадками."
            )

    def update_treeview(self, results):
        for item in self.tree.get_children():
            self.tree.delete(item)

        if not results:
            self.tree.insert("", "end", values=("Нет данных", "Нет данных", "N/A", "N/A", "N/A"), text="")
            return

        for row in results:
            city, country, iata, lat, lon, airport_id = row

            lat_str = f"{lat:.4f}" if lat is not None else "N/A"
            lon_str = f"{lon:.4f}" if lon is not None else "N/A"

            self.tree.insert("", "end",
                             values=(city, country, iata, lat_str, lon_str),
                             text=airport_id)


if __name__ == "__main__":
    app = AirportApp()
    app.protocol("WM_DELETE_WINDOW", app.on_closing)
    app.mainloop()