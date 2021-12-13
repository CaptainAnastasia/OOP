#pragma once
#include "Airfreighter.h";
#include <string>

Airfreighter::Airfreighter():Airfreighter
(
	"", "", 0, 0, 0, 0, 0, 0
)
{}




Airfreighter::Airfreighter(string _model, string _airlines, size_t _year_of_manufacture, int _capacity, double _fullness, double _percent_avarage, int _weight, double _cargocapacity) : Airplane
(
	_model, _airlines, _year_of_manufacture, _capacity, _fullness, _percent_avarage, _weight, _cargocapacity
)
{}

void Airfreighter::load(int _kilograms) const
{
	if ( _kilograms <  (int)_weight) {
		

	}
	else {
		cout << "\n\n   Превышен лимит груза! " << endl;
	}
	
	return ;
	//int cargocapacity <= int weight;
}

