#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;
public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    void startEngine() const { cout << brand << " (" << year << ") is starting...\n"; }
    void showVehicleInfo() const { cout << "Brand: " << brand << ", Year: " << year << "\n"; }
};

class Car : public Vehicle {
protected:
    int doors;
    int seats;
public:
    Car(string b, int y, int d, int s) : Vehicle(b, y), doors(d), seats(s) {}
    void openBoot() const { cout << brand << ": boot opened.\n"; }
    void showCarInfo() const { cout << "Doors: " << doors << ", Seats: " << seats << "\n"; }
};

class ElectricCar : public Car {
private:
    int batteryKWh;
    int batteryPercent;
public:
    ElectricCar(string b, int y, int d, int s, int kwh, int pct)
        : Car(b, y, d, s), batteryKWh(kwh), batteryPercent(pct) {}
    void charge(int amount) {
        batteryPercent = (batteryPercent + amount > 100) ? 100 : batteryPercent + amount;
        cout << brand << " charged. Battery now " << batteryPercent << "%\n";
    }
    void showElectricInfo() const {
        cout << "Battery: " << batteryKWh << " kWh, Charge: " << batteryPercent << "%\n";
    }
};

int main() {
    cout << "--- Vehicle object ---\n";
    Vehicle v("Toyota", 2015);
    v.showVehicleInfo();
    v.startEngine();

    cout << "\n--- Car object (inherits from Vehicle) ---\n";
    Car c("Honda", 2020, 4, 5);
    c.showVehicleInfo();   
    c.startEngine();   
    c.showCarInfo();       
    c.openBoot();         

    cout << "\n--- ElectricCar object (inherits from Car and Vehicle) ---\n";
    ElectricCar e("Tesla", 2024, 4, 5, 75, 40);
    e.showVehicleInfo();   
    e.startEngine();       
    e.showCarInfo();       
    e.openBoot();          
    e.showElectricInfo();  
    e.charge(30);          
    return 0;
}
