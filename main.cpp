#include <iostream>
#include "SI/all.hpp"
using namespace si;

int main()
{
	// Example 1: 
	auto Marathon = 42.195_km;
	auto Kiptums_time = 2_h;
	auto average_speed = Marathon / Kiptums_time;
	std::cout << "Kiptum's average speed was: " << miles_per_hour(average_speed) << " MPH" << std::endl;

	// Example 2:
	mass m = 1_kg;
	speed c = constant::speed_of_light;
	energy E = m * c*c;
	std::cout << "Energy of 1kg mass is: " << joule(E) << " Joule" << std::endl;

	// Example 3:
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light, H2_frequency);
	std::cout << "H2 wavelength in vacuum is: " << centimeter(H2_wavelength) << " cm" << std::endl;

	return 0;
}
