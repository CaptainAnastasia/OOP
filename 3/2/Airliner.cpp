#pragma once
#include "Airliner.h";
#include <string>

Airliner::Airliner() :Airliner
(
	"", "", 0, 0, 0, 0, 0, 0, 0
)
{}




Airliner::Airliner(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity, double _baggage) : Airplane
(
	_model, _airlines, _year_of_manufacture, _capacity, _fullness, _percent_avarage, _weight, _cargocapacity, _baggage
)
{}


double Airliner::load(double kilograms)
{
	
	if (baggage == 0) {
		
		if (baggage < cargocapacity) {
			baggage = (4 * cargocapacity) / (double)getFullness();
		}//cargocapacity = (double)(round(rand() % ((40 * 100) / getFullness())));
		else {
			cout << "\n\n   Превышен лимит груза! " << endl;
			
		}
	}
	return (40 * cargocapacity) / (double)getFullness();
}

