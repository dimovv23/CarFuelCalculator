#define GAS_PRICE 3

#include <iostream>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Car{
protected:
    string brand;
    string model;
    int year;
    int seats;
    double cargo;
    double fuel;

public:

    Car() {}

    Car(string brand, string model, int year, int seats, double cargo, double fuel) 
    {
        this->brand = brand;
        this->cargo = cargo;
        this->fuel = fuel;
        this->model = model;
        this->seats = seats;
        this->year = year;
    }

    string getBrand() 
    {
        return brand;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    int getSeats()
    {
        return seats;
    }

    double getCargo()
    {
        return cargo;
    }
    
    double getFuel()
    {
        return fuel;
    }

    void setBrand(string brand)
    {
        this->brand = brand;
    }

    void setModel(string model)
    {
        this->model = model;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    void setSeats(int seats)
    {
        this->seats = seats;
    }

    void setCargo(double cargo)
    {
        this->cargo = cargo;
    }

    void setFuel(double fuel)
    {
        this->fuel = fuel;
    }

    friend ostream& operator<<(ostream& os, const Car& taxi) {
        os << "Brand: " << taxi.brand << endl;
        os << "\tModel: " << taxi.model << endl;
        os << "\tYear: " << taxi.year << endl;
        os << "\tSeats: " << taxi.seats << endl;
        os << "\tCargo: " << taxi.cargo<< " kg" << endl;
        os << "\tFuel Concumption: " << taxi.fuel << " l/100km" << endl;
        return os;
    }
};

class Route {
protected:
    string start;
    string end;
    double lenght;
    int laps;

public:
    Route(){}
    Route(string start, string end, double lenght, int laps)
    {
        this->end = end;
        this->laps = laps;
        this->lenght = lenght;
        this->start = start;
    }

    string getStart()
    {
        return start;
    }

    string getEnd()
    {
        return end;
    }
    double getLenght()
    {
        return lenght;
    }
    int getLaps()
    {
        return laps;
    }
    void setStart(string start)
    {
        this->start = start;
    }
    void setEnd(string end)
    {
        this->end = end;
    }
    void setLenght(double lenght)
    {
        this->lenght = lenght;
    }
    void setLaps(int laps)
    {
        this->laps = laps;
    }
    friend ostream& operator<<(ostream& os, const Route& route) {
        os << "Start point: " << route.start << endl;
        os << "\tDestination: " << route.end << endl;
        os << "\tLenght: " << route.lenght << " km" << endl;
        os << "\tDaily frequency: " << route.laps << " time/s per day" << endl;
        return os;
    }
};

void inputCarData(Car& car) {
    string brand, model;
    double fuel, cargo;
    int year, seats;
    cout << "Input car brand: ";
    cin >> brand;
    cout << endl;
    cout << "Input car model: ";
    cin >> model;
    cout << endl;
    cout << "Input car year: ";
    cin >> year;
    cout << endl;
    cout << "Input car seats: ";
    cin >> seats;
    cout << endl;
    cout << "Input car cargo: ";
    cin >> cargo;
    cout << endl;
    cout << "Input car fuel: ";
    cin >> fuel;
    cout << endl;
    car.setBrand(brand);
    car.setModel(model);
    car.setYear(year);
    car.setSeats(seats);
    car.setCargo(cargo);
    car.setFuel(fuel);
}

void inputRouteData(Route& route) {
    string start, end;
    double length;
    int laps;
    cout << "Input start point: ";
    cin >> start;
    cout << endl;
    cout << "Input destination: ";
    cin >> end;
    cout << endl;
    cout << "Input length: ";
    cin >> length;
    cout << endl;
    cout << "Input daily frequency: ";
    cin >> laps;
    cout << endl;
    route.setStart(start);
    route.setEnd(end);
    route.setLenght(length);
    route.setLaps(laps);
}
void writeCarToFile(Car& car, string file_name) {
    ofstream carFile(file_name, ios::out | ios::app);
    carFile << car.getBrand() << ","
        << car.getModel() << ","
        << car.getYear() << ","
        << car.getSeats() << ","
        << car.getCargo() << ","
        << car.getFuel() << endl;
    carFile.close();
    cout << "Car saved successfully!\n" << endl;
}

void readCarFromFile(vector<Car>& cars, string file_name) {
    ifstream carFile(file_name);
    if (carFile.is_open()) {
        string line;
        while (getline(carFile, line)) {
            stringstream ss(line);
            string brand, model;
            int year, seats;
            double cargo, fuel;
            getline(ss, brand, ',');
            getline(ss, model, ',');
            ss >> year;
            ss.ignore();
            ss >> seats;
            ss.ignore();
            ss >> cargo;
            ss.ignore();
            ss >> fuel;
            cars.push_back(Car(brand, model, year, seats, cargo, fuel));
        }
        carFile.close();
        cout << "Cars loaded successfully!" << endl;
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void writeRouteToFile(Route& route, string file_name) {
    ofstream routeFile(file_name, ios::out | ios::app);
    routeFile << route.getStart() << ","
        << route.getEnd() << ","
        << route.getLenght() << ","
        << route.getLaps() << endl;
    routeFile.close();
    cout << "Route saved successfully!\n" << endl;
}

void readRouteFromFile(vector<Route>& routes, string file_name) {
    ifstream routeFile(file_name);
    if (routeFile.is_open()) {
        string line;
        while (getline(routeFile, line)) {
            stringstream ss(line);
            string start, end;
            int laps;
            double lenght;
            getline(ss, start, ',');
            getline(ss, end, ',');
            ss >> lenght;
            ss.ignore();
            ss >> laps;
            routes.push_back(Route(start, end, lenght, laps));
        }
        routeFile.close();
        cout << "Routes loaded successfully!" << endl;
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void displayMenu() {
    cout << "Please select an option:" << endl;
    cout << "1. Add 'CAR' data" << endl;
    cout << "2. Add 'ROUTE' data" << endl;
    cout << "3. Print all cars from the database" << endl;
    cout << "4. Print all routes from the database" << endl;
    cout << "5. Choose car and route" << endl;
    cout << "6. Exit" << endl;
    cout << "Option: ";
    cout << endl;
}

void printCarsFromVector(vector<Car>& cars) {
    for (int i = 0; i < cars.size(); i++) {
        cout << i+1 <<"| " << cars.at(i) << endl;
    }
}

void printRoutesFromVector(vector<Route>& routes) {
    for (int i = 0; i < routes.size(); i++) {
        cout << i+1 << "| " << routes.at(i) << endl;
    }
}

double neededFuelCalculation(Car& car, Route& route) {
    return (route.getLenght() * route.getLaps()) / car.getFuel();
}

void fuelMenu(vector<Route>& routes, vector<Car>& cars) {
    int car_id, route_id;
    cout << "Choose car by id: " << endl;
    cin >> car_id;
    cout << "Choose route by id: " << endl;
    cin >> route_id;
    cout << endl;
    cout << "You chose car number " << car_id << ":\n" << cars.at(car_id - 1) << endl;
    cout << "You chose route number " << route_id << ":\n" << routes.at(route_id - 1) << endl;
    cout << "For this road you will need " << neededFuelCalculation(cars.at(car_id - 1), routes.at(route_id - 1)) << " litters of gas.\n"
        << "With current price of " << GAS_PRICE << "BGN per liter for gas you will need "
        << neededFuelCalculation(cars.at(car_id - 1), routes.at(route_id - 1)) * GAS_PRICE
        << "BGN in total to take this route.\n\n" << endl;
    cars.clear();
    routes.clear();
}

int main() {
    vector<Car> cars;
    vector<Route> routes;
    int choice, car_id, route_id;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            Car car;
            inputCarData(car);
            writeCarToFile(car,"carData.txt");
        }
        else if (choice == 2) {
            Route route;
            inputRouteData(route);
            writeRouteToFile(route,"routeData.txt");
        }
        else if (choice == 3) {
            readCarFromFile(cars, "carData.txt");
            printCarsFromVector(cars);
            cars.clear();
        }
        else if (choice == 4) {
            readRouteFromFile(routes, "routeData.txt");
            printRoutesFromVector(routes);
            routes.clear();
        }
        else if (choice == 5) {
            readCarFromFile(cars, "carData.txt");
            printCarsFromVector(cars);
            readRouteFromFile(routes, "routeData.txt");
            printRoutesFromVector(routes);
            fuelMenu(routes, cars);
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "\tERROR\n Please enter a valid command!\n" << endl;
        }
    }

    return 0;
}
