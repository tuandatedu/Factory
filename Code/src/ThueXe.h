#pragma once
#include <vector>
#include <string>
using namespace std;

struct Time {
    int h = 0;
    int m = 0;
};

struct Date {
    int d = 0;
    int m = 0;
    int y = 0;
};

class Vehicle {
private:
    static vector<Vehicle*> prototypeList;
    string licensePlate;
    int seatCount;

public:
    Vehicle();
    Vehicle(const Vehicle& vehicle);
    virtual Vehicle* Clone() = 0;
    virtual string getVehicleType() = 0;
    static void addPrototype(Vehicle* vehicle);
    static Vehicle* createVehicle(string type);
    static void clearPrototypes();
    virtual ~Vehicle() {};
    void inputVehicle();
    void outputVehicle();
    void setLicensePlate(string licensePlate);
    void setSeatCount(int seatCount);
    string getLicensePlate() const;
    int getSeatCount() const;
};

class VehicleRental {
private:
    Vehicle* vehicle;
    Date rentalDate;
    Time startTime;
    Time endTime;
    string currentCity;

public:
    VehicleRental();
    VehicleRental(Vehicle* vehicle, Date date, Time start, Time end, string city);
    ~VehicleRental();

    void inputRentalInfo();
    void outputRentalInfo() const;
};

class Motorbike : public Vehicle {
public:
    Motorbike() : Vehicle() {}
    Motorbike(const Motorbike& vehicle) : Vehicle(vehicle) {}

    string getVehicleType() override {
        return "Motorbike";
    }

    Vehicle* Clone() override {
        return new Motorbike(*this);
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle() : Vehicle() {}
    Bicycle(const Bicycle& vehicle) : Vehicle(vehicle) {}

    string getVehicleType() override {
        return "Bicycle";
    }

    Vehicle* Clone() override {
        return new Bicycle(*this);
    }
};

class SelfDriveCar : public Vehicle {
public:
    SelfDriveCar() : Vehicle() {}
    SelfDriveCar(const SelfDriveCar& vehicle) : Vehicle(vehicle) {}

    string getVehicleType() override {
        return "Self-drive car";
    }

    Vehicle* Clone() override {
        return new SelfDriveCar(*this);
    }
};

class VehicleFactory {
public:
    static Vehicle* createVehicle(const string& type) {
        return Vehicle::createVehicle(type);
    }
};
