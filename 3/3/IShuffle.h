#pragma once
#include <iostream>

class IShuffle {
public:
	virtual void shuffle() const = 0;
	virtual void shuffle(size_t i, size_t j) const = 0;
}; 
