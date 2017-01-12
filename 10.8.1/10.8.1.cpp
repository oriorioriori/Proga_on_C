#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Vehicle
{

    protected:
        int passengers; 
        int max_speed; 

        bool is_crashed;

    public:

        Vehicle(int, int);
        Vehicle() {passengers = 0; max_speed = 0; is_crashed = false;}

        void crash();
        void repair();

        void info();

        void set_passengers(int p) {passengers = p;}
        void set_max_speed(int s) {max_speed = s;}

};

class Car : public Vehicle
{

    private:
        int patrol_capacity; //вместимость бензобака в литрах
        char* label; 
    public:

        Car(int, int, int, char*);
        Car() {patrol_capacity = 0; label = 0;}
        ~Car();

        void set_patrol_capacity(int c) {patrol_capacity = c;}
        void set_label(char* l) {label = new char[strlen(l) + 1]; strcpy(label, l);}

        void info();

};

Vehicle::Vehicle(int passengers, int max_speed)
{
    this->passengers = passengers;
    this->max_speed = max_speed;

    this->is_crashed = false;
}

void Vehicle::crash()
{

    if (is_crashed)
        cout << "Vehicle is crashed already!";

    is_crashed = true;
}

void Vehicle::repair()
{

    if (!is_crashed)
        cout << "Vehicle is repaired already!";

    is_crashed = false;
}

void Vehicle::info()
{

    cout << "Passengers number: " << passengers << "\nMaximum speed: " << max_speed << "\nState: " << ((is_crashed)?"crashed":"repaired") << endl;

}

Car::Car(int passengers, int max_speed, int patrol_capacity, char* label) : Vehicle(passengers, max_speed)
{
    this->patrol_capacity = patrol_capacity;

    this->label = new char[strlen(label) + 1]; // +1 для \0
    strcpy(this->label, label);

}

Car::~Car()
{
    delete [] label;
}

void Car::info()
{

    Vehicle::info();

    cout << "Patrol capacity: " << patrol_capacity << "\nLabel: " << label << endl;

}

void read_vehicle(ifstream& input, Vehicle& v)
{
    int p, ms; //ПМС АХАХАХАХ ну смешно же

    input >> p;
    input >> ms;

    v.set_passengers(p);
    v.set_max_speed(ms);

}

void read_car(ifstream& input, Car& c)
{
    int pc;
    char l[50];

    read_vehicle(input, c);

    input >> pc;
    input.getline(l, 50);

    c.set_patrol_capacity(pc);
    c.set_label(l);

}

int main()
{

    Vehicle v0;
    Vehicle v1;
    Car c0;
    Car c1;

    ifstream input("test.txt");

    read_vehicle(input, v0);
    read_vehicle(input, v1);
    read_car(input, c0);
    read_car(input, c1);

    cout << "Vehicle0:\n";
    v0.info();
    cout << "\n";

    cout << "Vehicle1:\n";
    v1.info();
    cout << "\n";

    cout << "Car0:\n";
    c0.info();
    cout << "\n";

    cout << "Car1:\n";
    c1.info();
    cout << "\n";

    c1.crash();

    cout << "Car1 after crash:\n";
    c1.info();
    cout << "\n";

    c1.repair();

    cout << "Car1 after repair:\n";
    c1.info();
    cout << "\n";

    cin.get();

    return 0;
}
