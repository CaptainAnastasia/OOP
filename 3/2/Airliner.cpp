#pragma once
#include "Airliner.h";
#include <string>

Airliner::Airliner() :Airliner
(
	"", "", 0, 0, 0, 0, 0, 0
)
{}




Airliner::Airliner(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity) : Airplane
(
	_model, _airlines, _year_of_manufacture, _capacity, _fullness, _percent_avarage, _weight, _cargocapacity
)
{}
void Airliner::load(int _kilograms) const
{
	if ( int _kilograms = 0) {
		double cargocapacity = (40 * 100) / (double)getFullness();
		
	}
	else {
		cout << "\n\n   Превышен лимит груза! " << endl;
	}
	
	return getCargocapacity();
}

