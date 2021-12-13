#pragma once
#include "Airplane.h";
#include "ILoadable.h";

class Airfreighter : public ILoadable, public Airplane
{
public:
	Airfreighter();
	Airfreighter(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity);

	void load(int _kilograms) const override;
	
};

