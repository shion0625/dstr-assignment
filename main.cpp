#include<iostream>
#include "lecture_struct.h"
#include <fstream>
#include <vector>

using namespace std;

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
//    string filename("lecture.txt");
    vector<string> lines;
    string line;
    const char *path = "/Users/kokubunryuuji/Devspace/dstr-assignment/lecture.txt";

    ifstream ifs(path);
    if ( !ifs.is_open() ) {
        cout << "hirakisou?" << endl;
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(ifs, line)){
        lines.push_back(line);
    }

    for (const auto &i : lines)
        cout << i << endl;

    ifs.close();
    return EXIT_SUCCESS;


//    return 0;
//    Car car1;
//    car1.Model ="Persona";
//    car1.EngineCapacity =1.6;
//    car1.Price = 60000;
//    Car car2;
//    car2.Model ="Honda City";
//    car2.EngineCapacity =1.5;
//    car2.Price = 89000;
//    Car car3;
//    car3.Model ="Saga";
//    car3.EngineCapacity =1.3;
//    car3.Price = 45000;
//    int totalPrice = car1.Price + car2.Price + car3.Price;
//    cout <<" Total Price: "<< totalPrice << endl;
//    Car * myCar = new Car;
//    readOneModel(myCar);
//    displayOneModel(myCar);

}

