#include "Airplane.h"
#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
const size_t numOfAirplanes = 4;

/*Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде инкапсуляцию данных, применение конструкторов без параметров и с параметрами
для инициализации данных. Класс должен содержать метод serialize() для сохранения данных класса в файл и метод deserialize() для чтения данных классаиз файла 
по умолчанию в текущей директории, а также перегруженные методы serialize(const std::string& filename) и deserialize(const std::string& filename) для работы 
с файлом с указанным в параметре именем.
Вариант 9  Класс САМОЛЕТ.*/

void sortArray(double* arr1, string* arr2, size_t n) {
    for (int i = 0; i < n; i++) {
        double zamenaDoub;
        string zamenaStr;
        for (int j = i + 1; j < n; j++) {
            if (arr1[i] < arr1[j]) {
                zamenaDoub = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = zamenaDoub;

                zamenaStr = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = zamenaStr;
            }
        }
    }
}

void printSortArray(double* arr1, string* arr2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << "  " << i + 1 << " - " << arr2[i] << " - " << arr1[i] << endl;
    }
    cout << "\n\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Airplane airplane1, airplane2, airplane3; //stack
    Airplane* airplane4 = new Airplane("Boeing 747SP", "Korean Air", 2002, 331, 0, 0); //heap

    airplane1.setModel("Boeing 737-500");
    airplane1.setAirlines("South African Airways");
    airplane1.setYearOfManufacture(1995);
    airplane1.setCapacity(150);
    airplane1.setNumberOfPassengers(0);
    airplane1.setPercentAvarage(0);

    airplane2.setModel("Airbus A380-841");
    airplane2.setAirlines("Pan Am");
    airplane2.setYearOfManufacture(2017);
    airplane2.setCapacity(854);
    airplane2.setNumberOfPassengers(0);
    airplane2.setPercentAvarage(0);

    airplane3.setModel("Airbus A320");
    airplane3.setAirlines("United Airlines");
    airplane3.setYearOfManufacture(2019);
    airplane3.setCapacity(190);
    airplane3.setNumberOfPassengers(0);
    airplane3.setPercentAvarage(0);


    airplane1.flightSimulation();
    airplane2.flightSimulation();
    airplane3.flightSimulation();
    airplane4->flightSimulation();

  
    airplane1.calculAvarageNumberOfPassengers();
    airplane2.calculAvarageNumberOfPassengers();
    airplane3.calculAvarageNumberOfPassengers();
    airplane4->calculAvarageNumberOfPassengers();



  
    airplane1.deserialize();
    airplane2.deserialize();
    airplane3.deserialize();
    airplane4->deserialize();

    airplane1.deserialize(" Airplane1.txt");
    airplane2.deserialize("Airplane2.txt");
    airplane3.deserialize("Airplane3.txt");
    airplane4->deserialize("Airplane4.txt");


    airplane1.serialize();
    airplane2.serialize();
    airplane3.serialize();
    airplane4->serialize();

    airplane1.serialize("Airplane1.txt");
    airplane2.serialize("Airplane2.txt");
    airplane3.serialize("Airplane3.txt");
    airplane4->serialize("Airplane4.txt");

    cout << "\n  Имитация трех рейсов: " << endl;
    airplane1.printInfo();
    airplane2.printInfo();
    airplane3.printInfo();
    airplane4->printInfo();

  
    string pitaStr[numOfAirplanes];
    pitaStr[0] = airplane1.getModel();
    pitaStr[1] = airplane2.getModel();
    pitaStr[2] = airplane3.getModel();
    pitaStr[3] = airplane4->getModel();

    double pitaDoub[numOfAirplanes];
    pitaDoub[0] = airplane1.getPercentAvarage();
    pitaDoub[1] = airplane2.getPercentAvarage();
    pitaDoub[2] = airplane3.getPercentAvarage();
    pitaDoub[3] = airplane4->getPercentAvarage();

    cout << "\n\n  Отсортированные самолеты в порядке убывания среднего процента за 3 рейса : " << endl;
    sortArray(pitaDoub, pitaStr, numOfAirplanes);
    printSortArray(pitaDoub, pitaStr, numOfAirplanes);
    delete airplane4;
    system("pause");
    return 0;
}
