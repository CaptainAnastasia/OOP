#pragma once

#include "Airplane.h";
#include "ILoadable.h";

class Airliner : public ILoadable, public Airplane
{
public:
	Airliner();
	Airliner(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity, double _baggage);

	double load(double kilograms)  override;
	//double getBaggage();
};




