/**
 * In this file, implement the methods from Jeans.h. The implementation is identical to Stress_ball
 * This file needs to be uploaded to Mimir
 */ 
#include "Jeans.h"

Jeans_colors Jeans::get_color() const {return color;} //"getters" that returns private value so that it can be used
Jeans_sizes Jeans::get_size() const {return size;}

Jeans::Jeans() //the default constructor uses "rand" to generate a random color and size
: color(static_cast<Jeans_colors>(std::rand() % 4)), size(static_cast<Jeans_sizes>(std::rand() % 4)) {} //used static_cast to convert to color or size

Jeans::Jeans(Jeans_colors c, Jeans_sizes s) //the copy constructor that initializes the values as given values
: color(c), size(s) {}

bool Jeans::operator==(const Jeans& Billie_Jean) { //comparison returns true if Jeans are the same and false if not the same
	if (this->color == Billie_Jean.color && this->size == Billie_Jean.size) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& o, const Jeans& Billie_Jean) { //outputs the Jeans as "(color, size)"
	std::string J_colors[4] = {"white", "black", "blue", "grey"};
	std::string J_sizes[4] = {"small", "medium", "large", "xlarge"};
	
	o << "(" << J_colors[static_cast<int>(Billie_Jean.get_color())] << ", " << J_sizes[static_cast<int>(Billie_Jean.get_size())] << ")" << endl;
	
	return o;
}