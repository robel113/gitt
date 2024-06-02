#include <iostream>
using namespace std;

struct Price {
    int days_of_rent;
    float distance_travel;
    float car_price_for_days;
    float car_price_for_distance_travel;
    float total_price;
};

struct Car {
    string make;
    string model;
    int year;
    double daily_rent;
    Price car_price;
};

struct Customer {
    string customer_National_id;
    string customer_full_name;
    string customer_phone_number;
    Car car_taking[1];
};

Car carList[5] = {
    {"Toyota", "Corolla", 2020, 50.0},
    {"Honda", "Civic", 2018, 45.0},
    {"Ford", "Mustang", 2022, 75.0},
    {"Chevrolet", "Silverado", 2019, 60.0},
    {"Nissan", "Altima", 2021, 55.0}
};

Customer addCustomer();
void assignCar(Customer&);
void addPrice(Customer&);
float calculateCarPriceForDays(float, int);
float calculateCarPriceForDistance(float);
float calculateTotalPrice(float, float);

int main() {
    Customer cust;
    cust = addCustomer();
    assignCar(cust);
    addPrice(cust);

    return 0;
}

Customer addCustomer() {
    Customer custo;
    cout << "Enter National_ID: ";
    cin >> custo.customer_National_id;

    cout << "Enter Full name: ";
    cin.ignore();
    getline(cin, custo.customer_full_name);

    cout << "Enter phone number: ";
    cin.ignore();
    getline(cin, custo.customer_phone_number);

    return custo;
}

void assignCar(Customer& tmpS) {
    short choice;

    cout << "List of available cars:\n---------------\n";

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". Make: " << carList[i].make << ", Model: " << carList[i].model << ", Year: " << carList[i].year << ", Daily rent: " << carList[i].daily_rent << endl;
    }

    cout << "---------------\nSelect a car: ";
    cin >> choice;

    tmpS.car_taking[0] = carList[choice - 1];
}

void addPrice(Customer& tmpS) {
    system("cls");

    cout << tmpS.customer_full_name << "( " << tmpS.customer_National_id << " )"<< "( "<< tmpS.customer_phone_number << " )\n";

    cout << "\n--------------\n"
         << "Make: " << tmpS.car_taking[0].make << ", Model: " << tmpS.car_taking[0].model << ", Year: " << tmpS.car_taking[0].year << ", Daily rent: " << tmpS.car_taking[0].daily_rent << endl;

    cout << "Days of rent: ";
    cin >> tmpS.car_taking[0].car_price.days_of_rent;

    tmpS.car_taking[0].car_price.car_price_for_days = calculateCarPriceForDays(tmpS.car_taking[0].daily_rent, tmpS.car_taking[0].car_price.days_of_rent);

    cout << "Distance traveled (in km): ";
    cin >> tmpS.car_taking[0].car_price.distance_travel;

    tmpS.car_taking[0].car_price.car_price_for_distance_travel = calculateCarPriceForDistance(tmpS.car_taking[0].car_price.distance_travel);

    tmpS.car_taking[0].car_price.total_price = calculateTotalPrice(tmpS.car_taking[0].car_price.car_price_for_days, tmpS.car_taking[0].car_price.car_price_for_distance_travel);

    cout << "Total price: $" << tmpS.car_taking[0].car_price.total_price << endl;
}

float calculateCarPriceForDays(float daily_rent, int days_of_rent) {
    return daily_rent * days_of_rent;
}

float calculateCarPriceForDistance(float distance_travel) {
    const float price_per_km = 0.5;
    return distance_travel * price_per_km;
}

float calculateTotalPrice(float car_price_for_days, float car_price_for_distance_travel) {
    return car_price_for_days + car_price_for_distance_travel;
}
