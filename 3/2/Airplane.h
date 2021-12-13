#pragma once
#include <string>
#include "ILoadable.h"
using namespace std;

class Airplane {
private:
	string model;
	string airlines;
	size_t year_of_manufacture;
	int capacity;
	double fullness;
	double percent_avarage;
	int weight;
	double cargocapacity;


public:
	//static int count;
	Airplane();
	Airplane(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity);
	
	void load(int _kilograms);
	//сеттеры:
	void setModel(const string _model);
	void setAirlines(const string _airlines);
	void setYearOfManufacture(const size_t _year_of_manufacture);
	void setCapacity(const int _capacity);
	void setFullness(const double _fullness);
	void setPercentAvarage(const double _percent_avarage);
	void setWeight(const int _weight);
	void setCargocapacity(const double _cargocapacity);
	//геттеры:
	string getModel()const;
	string getAirlines()const;
	size_t getYearOfManufacture()const;
	int    getCapacity()const;
	double getFullness()const;
	double getPercentAvarage()const;
	int    getWeight()const;
	double getCargocapacity()const;

	//my metod
	double flightSimulation();
	double calculAvarageNumberOfPassengers();
	double load();
	//double percentANOP();
	
	void serialize();
	void serialize(const string& filename);

	void deserialize();
	void deserialize(const string& filename);

	void printInfo();

};