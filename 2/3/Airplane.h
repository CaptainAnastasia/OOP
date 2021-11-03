#include <string>
using namespace std;
#pragma once
class Airplane {
private:
	string model;
	string airlines;
	size_t year_of_manufacture;
	int capacity;
	double number_of_passengers;
	double percent_avarage;
public:
	Airplane();
	Airplane(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _number_of_passengers, double _percent_avarage);
	//сеттеры:
	void setModel(const string _model);
	void setAirlines(const string _airlines);
	void setYearOfManufacture(const size_t _year_of_manufacture);
	void setCapacity(const int _capacity);
	void setNumberOfPassengers(const double _number_of_passengers);
	void setPercentAvarage(const double _percent_avarage);
	//геттеры:
	string getModel()const;
	string getAirlines()const;
	size_t getYearOfManufacture()const;
	int    getCapacity()const;
	double getNumberOfPassengers()const;
	double getPercentAvarage()const;

	//my metod
	double flightSimulation();
	double calculAvarageNumberOfPassengers();
	//double percentANOP();
	void printInfo();

	void serialize();
	void serialize(const string& filename);

	void deserialize();
	void deserialize(const string& filename);
};