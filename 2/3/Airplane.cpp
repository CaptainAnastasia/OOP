#include "Airplane.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static char numOfAirplane = 49; 
static char numOfAirplaneRead = 49;

//конструкторы
Airplane::Airplane()
{
	model = "";
	airlines = "";
	year_of_manufacture = 0;
	capacity = 0;
	number_of_passengers = 0;
    percent_avarage = 0;
}

Airplane::Airplane(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _number_of_passengers, double _percent_avarage)
{
	model = _model;
	airlines = _airlines;
	year_of_manufacture = _year_of_manufacture;
	capacity = _capacity;
    number_of_passengers = _number_of_passengers;
	percent_avarage = _percent_avarage;
}
//сеттеры
void Airplane::setModel(const string _model)
{
	model = _model;
}

void Airplane::setAirlines(const string _airlines)
{
	airlines = _airlines;
}

void Airplane::setYearOfManufacture(const size_t _year_of_manufacture)
{
	year_of_manufacture = _year_of_manufacture;
}

void Airplane::setCapacity(const int _capacity)
{
	capacity = _capacity;
}

void Airplane::setNumberOfPassengers(const double _number_of_passengers)
{
	number_of_passengers = _number_of_passengers;
}

void Airplane::setPercentAvarage(const double _percent_avarage)
{
	percent_avarage = _percent_avarage;
}
//геттеры
string Airplane::getModel()const
{
	return model;
}
string Airplane::getAirlines()const
{
	return airlines;
}
size_t Airplane::getYearOfManufacture()const
{
	return year_of_manufacture;
}
int Airplane::getCapacity()const
{
	return capacity;
}
double Airplane::getNumberOfPassengers()const
{
	return number_of_passengers;
}
double Airplane::getPercentAvarage()const
{
	return percent_avarage;
}


//методы
void Airplane::serialize()
{
	string txt = ".txt";
	string filename = numOfAirplane + txt;

	ofstream outf(filename); 
	outf << "  Модель:  " << getModel() << endl;
	outf << "  Авиалиния: " << getAirlines() << endl;
	outf << "  Год выпуска: " << getYearOfManufacture() << endl;
	outf << "  Вместимость: " << getCapacity() << endl;
	outf << "  Количество пассажиров: " << getNumberOfPassengers() << endl;
	outf << "  Процент: " << getPercentAvarage() << endl;
	std::cout << std::endl;

	numOfAirplane++;

}

void Airplane::serialize(const string& filename)
{
	ofstream outf(filename);
	
	outf << "  Модель:  " << getModel() << endl;
	outf << "  Авиалиния: " << getAirlines() << endl;
	outf << "  Год выпуска: " << getYearOfManufacture() << endl;
	outf << "  Вместимость: " << getCapacity() << endl;
	outf << "  Количество пассажиров: " << getNumberOfPassengers() << endl;
	outf << "  Процент: " << getPercentAvarage() << endl;


}
 

void Airplane::deserialize()
{
	string txt = ".txt";
	string filename = numOfAirplane + txt;

	ifstream inf(filename);
	while (inf) {
		string strInput;
		getline(inf, strInput);
		cout << strInput << endl;
	}
	numOfAirplaneRead++;
}

void Airplane::deserialize(const string& filename)
{
	ifstream inf(filename);
	while (inf) {
		string strInput;
		getline(inf, strInput);
		cout << strInput << endl;
	}
	
}
//my metods
double Airplane::flightSimulation() 
{
	if (number_of_passengers == 0) {
		number_of_passengers = (size_t) (round( rand() % (capacity + 1)));
	}
	return getNumberOfPassengers();

}
double Airplane::calculAvarageNumberOfPassengers() {

	percent_avarage = (round( 100 * getNumberOfPassengers() / capacity));
	return getPercentAvarage();
} 
	
void Airplane::printInfo() {
	cout << "  " << getModel() << " - "<< getNumberOfPassengers() << " - "  << getPercentAvarage() << "%" << endl;
}
