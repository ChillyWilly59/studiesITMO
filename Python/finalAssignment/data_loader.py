import psycopg2
import csv
import sys
from config import DB_CONFIG, AIRPORTS_DATA_FILE, AIRLINES_DATA_FILE, ROUTES_DATA_FILE


def create_all_tables_if_not_exists(conn):
    print("-> Подготовка базы данных: удаление старых таблиц...")

    drop_tables_sql = """
    DROP TABLE IF EXISTS routes;
    DROP TABLE IF EXISTS airlines;
    DROP TABLE IF EXISTS airports;
    """

    create_airports_sql = """
    CREATE TABLE IF NOT EXISTS airports (
        airport_id INTEGER PRIMARY KEY,
        name VARCHAR(255) NOT NULL,
        city VARCHAR(100),
        country VARCHAR(100),
        iata_code VARCHAR(3),
        icao_code VARCHAR(4),
        latitude NUMERIC(10, 6) NOT NULL,
        longitude NUMERIC(10, 6) NOT NULL,
        altitude INTEGER,
        timezone_offset NUMERIC(3, 1),
        dst CHAR(1),
        timezone_name VARCHAR(100),
        type VARCHAR(50),
        source VARCHAR(50)
    );
    CREATE INDEX IF NOT EXISTS idx_city_country ON airports (city, country);
    CREATE INDEX IF NOT EXISTS idx_lat_lon ON airports (latitude, longitude);
    CREATE INDEX IF NOT EXISTS idx_codes ON airports (iata_code, icao_code);
    """

    create_airlines_sql = """
    CREATE TABLE IF NOT EXISTS airlines (
        airline_id INTEGER PRIMARY KEY,
        name VARCHAR(255) NOT NULL,
        alias VARCHAR(255),
        iata_code CHAR(2),
        icao_code CHAR(3),
        callsign VARCHAR(100),
        country VARCHAR(100),
        active CHAR(1)
    );
    CREATE INDEX IF NOT EXISTS idx_airline_codes ON airlines (iata_code, icao_code);
    CREATE INDEX IF NOT EXISTS idx_airline_name ON airlines (name);
    """

    create_routes_sql = """
        CREATE TABLE IF NOT EXISTS routes (
            route_id SERIAL PRIMARY KEY,
            airline_iata CHAR(2) NOT NULL,
            airline_id INTEGER,
            source_airport_iata CHAR(3) NOT NULL,
            source_airport_id INTEGER,
            destination_airport_iata CHAR(3) NOT NULL,
            destination_airport_id INTEGER,
            codeshare CHAR(1),
            stops INTEGER,
            equipment VARCHAR(255),

            -- Оставляем только зависимость от airlines, т.к. она заработала!
            FOREIGN KEY (airline_id) REFERENCES airlines (airline_id) ON DELETE SET NULL
            -- УДАЛЯЕМ строки для airports:
            -- FOREIGN KEY (source_airport_id) REFERENCES airports (airport_id) ON DELETE CASCADE,
            -- FOREIGN KEY (destination_airport_id) REFERENCES airports (airport_id) ON DELETE CASCADE
        );
        CREATE INDEX IF NOT EXISTS idx_route_source ON routes (source_airport_id);
        CREATE INDEX IF NOT EXISTS idx_route_dest ON routes (destination_airport_id);
        """

    try:
        with conn.cursor() as cur:
            cur.execute(drop_tables_sql)
            cur.execute(create_airports_sql)
            cur.execute(create_airlines_sql)
            cur.execute(create_routes_sql)
        conn.commit()
        print("   Все таблицы пересозданы.")
    except psycopg2.Error as e:
        print(f"   Ошибка при создании таблиц: {e}")
        conn.rollback()


def load_data_from_airports(conn):
    insert_query = """
    INSERT INTO airports (
        airport_id, name, city, country, iata_code, icao_code, 
        latitude, longitude, altitude, timezone_offset, dst, 
        timezone_name, type, source
    ) VALUES (
        %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s
    ) ON CONFLICT (airport_id) DO NOTHING;
    """

    try:
        print(f"-> Загрузка данных из файла: {AIRPORTS_DATA_FILE}...")
        with open(AIRPORTS_DATA_FILE, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            with conn.cursor() as cur:
                rows_inserted = 0
                for row in reader:
                    if len(row) < 14:
                        continue
                    data = []
                    for i, value in enumerate(row):
                        clean_value = value.strip()

                        if clean_value == '\\N' or clean_value == '':
                            data.append(None)
                        else:
                            if i in [0, 8]:
                                try:
                                    data.append(int(clean_value))
                                except ValueError:
                                    data.append(None)
                            elif i in [6, 7, 9]:
                                try:
                                    data.append(float(clean_value))
                                except ValueError:
                                    data.append(None)
                            else:
                                data.append(clean_value)

                    cur.execute(insert_query, data[:14])
                    rows_inserted += 1
                conn.commit()
                print(f"   Успешно обработано и загружено {rows_inserted} строк.")
    except FileNotFoundError:
        print(f"!!! ОШИБКА: Файл '{AIRPORTS_DATA_FILE}' не найден.")
    except psycopg2.Error as e:
        print(f"!!! ОШИБКА PostgreSQL при вставке данных: {e}")
        conn.rollback()
    except Exception as e:
        print(f"!!! Непредвиденная ошибка: {e}")


def load_data_from_airlines(conn):
    insert_query = """
    INSERT INTO airlines (
        airline_id, name, alias, iata_code, icao_code, callsign, country, active
    ) VALUES (%s, %s, %s, %s, %s, %s, %s, %s) 
    ON CONFLICT (airline_id) DO NOTHING;
    """

    try:
        print(f"-> Загрузка данных из файла: {AIRLINES_DATA_FILE}...")
        with open(AIRLINES_DATA_FILE, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            with conn.cursor() as cur:
                rows_inserted = 0
                for row in reader:
                    if len(row) < 8:
                        continue

                    data = []
                    for i, value in enumerate(row):
                        clean_value = value.strip()

                        if clean_value == '\\N' or clean_value == '':
                            data.append(None)
                        else:
                            if i == 0:
                                # airline_id (INTEGER)
                                try:
                                    data.append(int(clean_value))
                                except ValueError:
                                    data.append(None)

                            # Принудительная обрезка строковых полей с ограничением длины
                            elif i == 3:  # IATA-код (CHAR(2))
                                data.append(clean_value[:2])
                            elif i == 4:  # ICAO-код (CHAR(3))
                                data.append(clean_value[:3])

                            else:
                                data.append(clean_value)

                    cur.execute(insert_query, data[:8])
                    rows_inserted += 1
                conn.commit()
                print(f"   Успешно загружено {rows_inserted} строк авиакомпаний.")
    except FileNotFoundError:
        print(f"!!! ОШИБКА: Файл '{AIRLINES_DATA_FILE}' не найден.")
    except psycopg2.Error as e:
        print(f"!!! ОШИБКА PostgreSQL при вставке данных: {e}")
        conn.rollback()
    except Exception as e:
        print(f"!!! Непредвиденная ошибка: {e}")


def load_data_from_routes(conn):
    insert_query = """
    INSERT INTO routes (
        airline_iata, airline_id, source_airport_iata, source_airport_id, 
        destination_airport_iata, destination_airport_id, codeshare, stops, equipment
    ) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s);
    """

    try:
        print(f"-> Загрузка данных из файла: {ROUTES_DATA_FILE}...")
        with open(ROUTES_DATA_FILE, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            with conn.cursor() as cur:
                rows_inserted = 0
                for row in reader:
                    if len(row) < 9:
                        continue

                    data = []
                    for i, value in enumerate(row):
                        clean_value = value.strip()

                        if clean_value == '\\N' or clean_value == '':
                            data.append(None)
                        else:
                            if i in [1, 3, 5, 7]:
                                try:
                                    data.append(int(clean_value))
                                except ValueError:
                                    data.append(None)
                            else:
                                if i == 0:
                                    data.append(clean_value[:2])
                                elif i == 6:
                                    data.append(clean_value[:1])
                                else:
                                    data.append(clean_value)

                    if len(data) == 9:
                        cur.execute(insert_query, data)
                        rows_inserted += 1
                conn.commit()
                print(f"   Успешно загружено {rows_inserted} строк маршрутов.")
    except FileNotFoundError:
        print(f"!!! ОШИБКА: Файл '{ROUTES_DATA_FILE}' не найден.")
    except psycopg2.Error as e:
        print(f"!!! ОШИБКА PostgreSQL при вставке данных: {e}")
        conn.rollback()
    except Exception as e:
        print(f"!!! Непредвиденная ошибка: {e}")

def main():
    conn = None
    try:
        print("--- Скрипт Загрузки ВСЕХ Данных ---")
        conn = psycopg2.connect(**DB_CONFIG)
        print("Соединение с PostgreSQL успешно установлено.")

        create_all_tables_if_not_exists(conn)

        load_data_from_airports(conn)
        load_data_from_airlines(conn)
        load_data_from_routes(conn)

    except psycopg2.OperationalError as e:
        print(f"\n!!! ОШИБКА ПОДКЛЮЧЕНИЯ: {e}")
    finally:
        if conn:
            conn.close()
            print("\nСоединение с БД закрыто.")


if __name__ == "__main__":
    main()