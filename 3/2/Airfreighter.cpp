#pragma once
#include "Airfreighter.h";
#include <string>

Airfreighter::Airfreighter():Airfreighter
(
	"", "", 0, 0, 0, 0, 0, 0, 0
)
{}




Airfreighter::Airfreighter(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity, double _baggage) : Airplane
(
	_model, _airlines, _year_of_manufacture, _capacity, _fullness, _percent_avarage, _weight, _cargocapacity, _baggage
)
{}

double Airfreighter::load(double kilograms)
{
	
	if (baggage == 0) {
		
		if (baggage < cargocapacity) {
			baggage = (100 * cargocapacity) / (double)getFullness();
		}
		else if (baggage = cargocapacity) {
			baggage = (100 * cargocapacity) / (double)getFullness();
		}
		else {
			cout << "\n\n   Превышен лимит груза! " << endl;
			
		}
		
	}
	return (100 * cargocapacity) / (double)getFullness();
}

