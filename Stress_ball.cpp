#include <iostream>
#include "Stress_ball.h"


Stress_ball_colors Stress_ball::get_color() const {return color;} //"getters" that returns private value so that it can be used
Stress_ball_sizes Stress_ball::get_size() const {return size;}

Stress_ball::Stress_ball() //the default constructor uses "rand" to generate a random color and size
: color(static_cast<Stress_ball_colors>(std::rand() % 4)), size(static_cast<Stress_ball_sizes>(std::rand() % 3)) {} //used static_cast to convert to color or size

Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) //the copy constructor that initializes the values as given values
: color(c), size(s) {}

bool Stress_ball::operator==(const Stress_ball& sb) { //comparison returns true if stress balls are the same and false if not the same
	if (this->color == sb.color && this->size == sb.size) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb) { //outputs the stress ball as "(color, size)"
	std::string sb_colors[4] = {"red", "blue", "green", "yellow"};
	std::string sb_sizes[3] = {"small", "medium", "large"};
	
	o << "(" << sb_colors[static_cast<int>(sb.get_color())] << ", " << sb_sizes[static_cast<int>(sb.get_size())] << ")" << endl;
	
	return o;
}