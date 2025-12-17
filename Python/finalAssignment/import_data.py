import psycopg2
import csv
from config import DB_CONFIG

AIRPORTS_FILE = "airports.dat"
AIRLINES_FILE = "airlines.dat"
ROUTES_FILE = "routes.dat"


def get_connection():
    return psycopg2.connect(**DB_CONFIG)


def create_tables(conn):
    print("Recreating tables...")
    commands = [
        "DROP TABLE IF EXISTS routes CASCADE;",
        "DROP TABLE IF EXISTS airlines CASCADE;",
        "DROP TABLE IF EXISTS airports CASCADE;",
        """
        CREATE TABLE airports (
            airport_id INT PRIMARY KEY,
            name VARCHAR(255),
            city VARCHAR(100),
            country VARCHAR(100),
            iata_code VARCHAR(10),
            icao_code VARCHAR(10),
            latitude FLOAT,
            longitude FLOAT,
            altitude INT,
            timezone FLOAT,
            dst CHAR(1),
            tz_name VARCHAR(100),
            type VARCHAR(50),
            source VARCHAR(50)
        )
        """,
        """
        CREATE TABLE airlines (
            airline_id INT PRIMARY KEY,
            name VARCHAR(255),
            alias VARCHAR(50),
            iata VARCHAR(10),
            icao VARCHAR(10),
            callsign VARCHAR(100),
            country VARCHAR(100),
            active CHAR(1)
        )
        """,
        """
        CREATE TABLE routes (
            route_id SERIAL PRIMARY KEY,
            airline_id INT,
            source_airport_id INT,
            destination_airport_id INT,
            codeshare CHAR(1),
            stops INT,
            equipment VARCHAR(100)
        )
        """
    ]

    try:
        with conn.cursor() as cur:
            for command in commands:
                cur.execute(command)
        conn.commit()
        print("Tables recreated with larger columns.")
    except Exception as e:
        conn.rollback()
        print(f"Error creating tables: {e}")
        raise e


def clean_row(row):
    return [None if x == '\\N' else x for x in row]


def import_airports(conn):
    print("Importing airports...")
    try:
        with open(AIRPORTS_FILE, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            data = []
            for row in reader:
                row = clean_row(row)
                if len(row) >= 12:
                    try:
                        aid = int(row[0])
                        lat = float(row[6])
                        lon = float(row[7])
                        alt = int(row[8]) if row[8] else 0

                        data.append((
                            aid, row[1], row[2], row[3], row[4], row[5],
                            lat, lon, alt, row[9], row[10], row[11], row[12], row[13]
                        ))
                    except ValueError:
                        continue

            with conn.cursor() as cur:
                sql = """
                    INSERT INTO airports (airport_id, name, city, country, iata_code, icao_code, latitude, longitude, altitude, timezone, dst, tz_name, type, source)
                    VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)
                    ON CONFLICT (airport_id) DO NOTHING;
                """
                cur.executemany(sql, data)
                conn.commit()
                print(f"Airports imported: {len(data)}")
    except FileNotFoundError:
        print(f"File {AIRPORTS_FILE} not found.")
    except Exception as e:
        conn.rollback()
        print(f"Error importing airports: {e}")


def import_airlines(conn):
    print("Importing airlines...")
    try:
        with open(AIRLINES_FILE, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            data = []
            for row in reader:
                row = clean_row(row)
                if not row[0].isdigit(): continue

                if len(row) >= 7:
                    data.append((
                        int(row[0]), row[1], row[2], row[3], row[4], row[5], row[6], row[7]
                    ))

            with conn.cursor() as cur:
                sql = """
                    INSERT INTO airlines (airline_id, name, alias, iata, icao, callsign, country, active)
                    VALUES (%s, %s, %s, %s, %s, %s, %s, %s)
                    ON CONFLICT (airline_id) DO NOTHING;
                """
                cur.executemany(sql, data)
                conn.commit()
                print(f"Airlines imported: {len(data)}")
    except FileNotFoundError:
        print(f"File {AIRLINES_FILE} not found.")
    except Exception as e:
        conn.rollback()
        print(f"Error importing airlines: {e}")


def import_routes(conn):
    print("Importing routes...")
    try:
        with open(ROUTES_FILE, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            data = []
            for row in reader:
                row = clean_row(row)
                if len(row) >= 8 and str(row[1]).isdigit() and str(row[3]).isdigit() and str(row[5]).isdigit():
                    data.append((
                        int(row[1]), int(row[3]), int(row[5]), row[6], int(row[7]) if row[7] else 0, row[8]
                    ))

            with conn.cursor() as cur:
                sql = """
                    INSERT INTO routes (airline_id, source_airport_id, destination_airport_id, codeshare, stops, equipment)
                    VALUES (%s, %s, %s, %s, %s, %s);
                """
                cur.executemany(sql, data)
                conn.commit()
                print(f"Routes imported: {len(data)}")
    except FileNotFoundError:
        print(f"File {ROUTES_FILE} not found.")
    except Exception as e:
        conn.rollback()
        print(f"Error importing routes: {e}")


if __name__ == "__main__":
    connection = None
    try:
        connection = get_connection()

        create_tables(connection)
        import_airports(connection)
        import_airlines(connection)
        import_routes(connection)

        print("Done.")

    except Exception as e:
        print(f"Critical error: {e}")
    finally:
        if connection:
            connection.close()