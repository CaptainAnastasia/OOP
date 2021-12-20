#include <iostream>
#include <string>
#include "Airplane.h"
#include "Airfreighter.h"
#include "Airliner.h"
#include "ILoadable.h"

#include <conio.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
const size_t numOfAirplanes = 4;



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

    Airplane* airplane[4];
    Airplane* airfreighter1 = new Airfreighter("Airbus A320", "United Airlines", 2019, 190, 0, 0, 42, 17, 0);
    airplane[0] = airfreighter1;
    Airplane* airfreighter2 = new Airfreighter("Airbus A380-841", "Pan Am", 2017, 854, 0, 0, 280, 150, 0);
    airplane[1] = airfreighter2;
    Airplane* airline1 = new Airliner("Boeing 737-500", "South African Airways", 1995, 150, 0, 0, 31, 15, 0);
    airplane[2] = airline1;
    Airplane* airline2 = new Airliner("Boeing 747SP", "Korean Air", 2002, 331, 0, 0, 153, 70, 0);
    airplane[3] = airline2;


    airplane[0]->flightSimulation();
    airplane[1]->flightSimulation();
    airplane[2]->flightSimulation();
    airplane[3]->flightSimulation();


    airplane[0]->calculAvarageNumberOfPassengers();
    airplane[1]->calculAvarageNumberOfPassengers();
    airplane[2]->calculAvarageNumberOfPassengers();
    airplane[3]->calculAvarageNumberOfPassengers();


    cout << "\n  Имитация трех рейсов: " << endl;
    airplane[0]->printInfo();
    airplane[1]->printInfo();
    airplane[2]->printInfo();
    airplane[3]->printInfo();

    string pitaStr[numOfAirplanes];
    pitaStr[0] = airplane[0]->getModel();
    pitaStr[1] = airplane[1]->getModel();
    pitaStr[2] = airplane[2]->getModel();
    pitaStr[3] = airplane[3]->getModel();

    double pitaDoub[numOfAirplanes];
    pitaDoub[0] = airplane[0]->getPercentAvarage();
    pitaDoub[1] = airplane[1]->getPercentAvarage();
    pitaDoub[2] = airplane[2]->getPercentAvarage();
    pitaDoub[3] = airplane[3]->getPercentAvarage();

   /* for (int i = 0; i < 4; ++i)
    {
        ILoadable* ifc = dynamic_cast<ILoadable*>(airplane[i]);
        if (ifc)
            std::cout << "Ðàñõîä òîïëèâà íà êàæäûå 100 êì: " << airplane[i]->load(140) << endl << endl;
    }
    for (std::size_t i = 0; i < 4; ++i)
    {
        cout << typeid(*airplane[i]).name() << endl;

    }*/

    for (int i = 0, j = 3; i < 4 && j >= 0; i++, j--)
    {
        ILoadable* air = dynamic_cast<ILoadable*>(airplane[i]);
        std::string ILoadableToString(ILoadable);
        if (airplane != nullptr)
        {
           
            air->load(airplane[j]->getBaggage());
            airplane[i]->printInfo();
        }
    }

    cout << "\n\n  Отсортированные самолеты в порядке убывания среднего процента за 3 рейса : " << endl;
    sortArray(pitaDoub, pitaStr, numOfAirplanes);
    printSortArray(pitaDoub, pitaStr, numOfAirplanes);


    system("pause");
    return 0;
  
}
