#include "Airplane.h"
#include "ILoadable.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static char numOfAirplane = 49;
static char numOfAirplaneRead = 49;
int Airplane::count = 0;
//конструкторы
Airplane::Airplane()
{
	model = "";
	airlines = "";
	year_of_manufacture = 0;
	capacity = 0;
	fullness = 0;
	percent_avarage = 0;
	weight = 0;
	cargocapacity = 0;
	baggage = 0;
	count++;
}

Airplane::Airplane(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity, double _baggage)
{
	model = _model;
	airlines = _airlines;
	year_of_manufacture = _year_of_manufacture;
	capacity = _capacity;
	fullness = _fullness;
	percent_avarage = _percent_avarage;
	weight = _weight;
	cargocapacity = _cargocapacity;
	baggage = _baggage;
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

void Airplane::setFullness(const double _fullness)
{
	fullness = _fullness;
}

void Airplane::setPercentAvarage(const double _percent_avarage)
{
	percent_avarage = _percent_avarage;
}

void Airplane::setWeight(const int _weight)
{
	weight = _weight;
}

void Airplane::setCargocapacity(const double _cargocapacity)
{
	cargocapacity = _cargocapacity;
}
void Airplane::setBaggage(double _baggage) {
	baggage = _baggage;
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
double Airplane::getFullness()const
{
	return fullness;
}
double Airplane::getPercentAvarage()const
{
	return percent_avarage;
}

int Airplane::getWeight()const
{
	return weight;
}

 double Airplane::getCargocapacity()const
 {
	 return cargocapacity;
 }

 double Airplane::getBaggage()
 {
	 return baggage;
 }
//сеттеры:


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
	outf << "  Количество пассажиров: " << getFullness() << endl;
	outf << "  Процент: " << getPercentAvarage() << endl;
	outf << "  Вес: " << getWeight() << endl;
	outf << "  Грузовместимость: " << getCargocapacity() << endl;
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
	outf << "  Количество пассажиров: " << getFullness() << endl;
	outf << "  Процент: " << getPercentAvarage() << endl;
	outf << "  Вес: " << getWeight() << endl;
	outf << "  Грузовместимость: " << getCargocapacity() << endl;


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
	if (fullness == 0) {
		fullness += (size_t)(round(rand() % (capacity + 1)));
}
	return getFullness();

}
double Airplane::calculAvarageNumberOfPassengers() {

	percent_avarage = (round(100 * getFullness() / capacity));
	return getPercentAvarage();
}

double Airplane::load(double kilograms) {
	//baggage = kilograms;
	return getBaggage();
}


void Airplane::printInfo() {
	cout << "  " << getModel() << " — " << getFullness() << " - " << getPercentAvarage() << "%" " - " << getWeight() << " т" << " - " << getCargocapacity() << "т" << endl;
	cout << "  " << "Заполненность груза на самолете " << " — " << getBaggage() << "т" << endl;
}
