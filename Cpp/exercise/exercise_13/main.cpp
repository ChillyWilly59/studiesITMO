#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>

class Vehicle {
public:
    virtual void move() const = 0;
    virtual std::string type() const = 0;
    virtual ~Vehicle() = default;

    static int get_count() {
        return count;
    }

protected:
    static int count;
};

int Vehicle::count = 0;

class Car : public Vehicle {
public:
    Car() { count++; }
    ~Car() override { count--; }

    void move() const override {
        std::cout << "Car is driving on the road.";
    }

    std::string type() const override {
        return "Car";
    }
};

class Boat : public Vehicle {
public:
    Boat() { count++; }
    ~Boat() override { count--; }

    void move() const override {
        std::cout << "Boat is sailing on water.";
    }

    std::string type() const override {
        return "Boat";
    }
};

class Plane : public Vehicle {
public:
    Plane() { count++; }
    ~Plane() override { count--; }

    void move() const override {
        std::cout << "Plane is flying in the sky.";
    }

    std::string type() const override {
        return "Plane";
    }
};

class AmphibiousVehicle : public Vehicle {
public:
    AmphibiousVehicle() { count++; }
    ~AmphibiousVehicle() override { count--; }

    void move() const override {
        std::cout << "Amphibious vehicle is driving on road and sailing on water.";
    }

    std::string type() const override {
        return "AmphibiousVehicle";
    }
};

void serialize_to_file(const std::vector<Vehicle*>& vehicles, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto* v : vehicles) {
        file << v->type() << ";";
        if (v->type() == "Car") file << "driving on the road";
        else if (v->type() == "Boat") file << "sailing on water";
        else if (v->type() == "Plane") file << "flying in the sky";
        else if (v->type() == "AmphibiousVehicle") file << "driving on road and sailing on water";
        file << "\n";
    }
    file.close();
}

int main() {
    std::vector<Vehicle*> vehicles;

    vehicles.push_back(new Car());
    vehicles.push_back(new Boat());
    vehicles.push_back(new Plane());
    vehicles.push_back(new AmphibiousVehicle());
    vehicles.push_back(new Car());

    std::cout << "Vehicle count: " << Vehicle::get_count() << "\n\n";

    for (const auto* v : vehicles) {
        std::cout << v->type() << " (RTTI: " << typeid(*v).name() << "): ";
        v->move();
        std::cout << std::endl;
    }

    serialize_to_file(vehicles, "vehicles.txt");
    std::cout << "\nData serialized to vehicles.txt\n";

    for (auto* v : vehicles) {
        delete v;
    }

    std::cout << "\nVehicle count after cleanup: " << Vehicle::get_count() << std::endl;

    return 0;
}