#include<iostream>
using namespace std;

struct Car{
    string Model;
    double EngineCapacity;
    int Price;
};

void readOneModel(Car* data){
    string model;
    double capacity;
    int price;
    cout << "\nEnter model: ";
    cin >> model;
    cout << "Enter engine: ";
    cin >> capacity;
    cout << "Enter price: ";
    cin >> price;

    data->Model =model;
    data->EngineCapacity = capacity;
    data->Price = price;
}
void displayOneModel(Car* data){
    printf("model: %s, capacity: %f, price: %i \n", data -> Model.c_str(), data -> EngineCapacity, data -> Price);
}

int main() {
    Car car1;
    car1.Model ="Persona";
    car1.EngineCapacity =1.6;
    car1.Price = 60000;
    Car car2;
    car2.Model ="Honda City";
    car2.EngineCapacity =1.5;
    car2.Price = 89000;
    Car car3;
    car3.Model ="Saga";
    car3.EngineCapacity =1.3;
    car3.Price = 45000;
    int totalPrice = car1.Price + car2.Price + car3.Price;
    cout <<" Total Price: "<< totalPrice << endl;
    Car * myCar = new Car;
    readOneModel(myCar);
    displayOneModel(myCar);
    return 0;
}

