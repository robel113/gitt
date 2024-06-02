#include<iostream>
#include<fstream>
using namespace std;

class Price {
public:
    int days_of_rent;
    float distance_travel;
    float car_price_for_days;
    float car_price_for_distance_travel;
    float total_price;

    Price() {
        days_of_rent = 0;
        distance_travel = 0;
        car_price_for_days = 0;
        car_price_for_distance_travel = 0;
        total_price = 0;
    }

    void addprice(float daily_rent) {
        cout << "Days of rent: ";
        cin >> days_of_rent;

        cout << "Distance travel: ";
        cin >> distance_travel;

        car_price_for_days = calculateCarPriceForDays(daily_rent);
        car_price_for_distance_travel = calculateCarPriceForDistance();
        total_price = calculateTotalPrice();

        ofstream FileWriter;
        FileWriter.open("jon_files.txt", ios::app);
        FileWriter << "Days of rent: " << days_of_rent << endl;
        FileWriter << "Distance travel: " << distance_travel << endl;
        FileWriter << "Car price for days: " << car_price_for_days << endl;
        FileWriter << "Car price for distance travel: " << car_price_for_distance_travel << endl;
        FileWriter << "Total price: " << total_price << endl;
    }

    float calculateCarPriceForDays(float daily_rent) {
        return daily_rent * days_of_rent;
    }

    float calculateCarPriceForDistance() {
        const float price_per_km = 0.5;
        return distance_travel * price_per_km;
    }

    float calculateTotalPrice() {
        return car_price_for_days + car_price_for_distance_travel;
    }
};

class Car : public Price {
    string make;
    string model;
    int year;
    double daily_rent;

public:
    Car() {
        make = "";
        model = "";
        year = 0;
        daily_rent = 0;
    }

    string get_make() { return make; }
    string get_model() { return model; }
    int get_year() { return year; }
    double get_daily_rent() { return daily_rent; }

    void assign_car(int x) {
        switch (x) {
            case 1:
                make = "Toyota";
                model = "Corolla";
                year = 2010;
                daily_rent = 200;
                break;
            case 2:
                make = "Honda";
                model = "Civic";
                year = 2018;
                daily_rent = 2500;
                break;
            case 3:
                make = "Ford";
                model = "Mustang";
                year = 2022;
                daily_rent = 4500;
                break;
            case 4:
                make = "Chevrolet";
                model = "Silverado";
                year = 2019;
                daily_rent = 4000;
                break;
            case 5:
                make = "Nissan";
                model = "Altima";
                year = 2021;
                daily_rent = 2000;
                break;
            default:
                cout << "Invalid choice" << endl;
                return;
        }
        ofstream FileWriter;
        FileWriter.open("jon_files.txt", ios::app);
        FileWriter << "Car make: " << make << endl;
        FileWriter << "Car model: " << model << endl;
        FileWriter << "Car manufacture year: " << year << endl;
        FileWriter << "Car daily rent: " << daily_rent << endl;
    }
};

class Customer {
    string customer_National_id;
    string customer_full_name;
    string customer_phone_number;

public:
    int numCars;
    Car* carTaking; // (has a)

    string get_national_ID() { return customer_National_id; }
    string get_fullName() { return customer_full_name; }
    string get_phone_number() { return customer_phone_number; }

    Customer() {
        customer_National_id = "";
        customer_full_name = "";
        customer_phone_number = "";
        numCars = 0;
        carTaking = nullptr;
    }
    Customer(string cid, string fn, int num) {
        customer_National_id = cid;
        customer_full_name = fn;
        numCars = num;
        carTaking = new Car[numCars];
        ofstream FileWriter;
        FileWriter.open("jon_files.txt", ios::app);
        FileWriter << "Customer National ID: " << customer_National_id << endl;
        FileWriter << "Customer full name: " << customer_full_name << endl;
    }

    ~Customer() {
        delete[] carTaking;
    }
};

int main() {
    system("color f0");

    string customer_id, customer_name;
    cout << "Enter customer ID: ";
    cin >> customer_id;
    cin.ignore(); // To ignore the newline character left in the buffer
    cout << "Enter customer name: ";
    getline(cin, customer_name);

    Customer* st = new Customer(customer_id, customer_name, 1);
    short choice;

    for (int i = 0; i < st->numCars; i++) {
        cout << "Choose a Car" << endl
             << "1. Toyota, Corolla, 2010, 200" << endl
             << "2. Honda, Civic, 2018, 2500" << endl
             << "3. Ford, Mustang, 2022, 4500" << endl
             << "4. Chevrolet, Silverado, 2019, 4000" << endl
             << "5. Nissan, Altima, 2021, 2000" << endl;

        cin >> choice;
       switch (choice) {
            case 1:
                st->carTaking[i].assign_car(1);
                break;
            case 2:
                st->carTaking[i].assign_car(2);
                break;
            case 3:
                st->carTaking[i].assign_car(3);
                break;
            case 4:
                st->carTaking[i].assign_car(4);
                break;
            case 5:
                st->carTaking[i].assign_car(5);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        system("cls");
    }

    cout << st->get_fullName() << endl
         << st->get_national_ID() << endl;

    for (int i = 0; i < st->numCars; i++) {
        cout << st->carTaking[i].get_make() << " (" << st->carTaking[i].get_model() << ")" << endl;
        st->carTaking[i].addprice(st->carTaking[i].get_daily_rent());
    }

    system("cls");

    ifstream FileReader;
    FileReader.open("jon_files.txt");
    string text;
    while (getline(FileReader, text)) {
        cout << text << endl;
    }

    system("pause");
    delete st;

    return 0;
}