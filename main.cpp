#include "SI/everything.hpp"
using namespace si;

int main()
{
	// Example 1: 
	auto Marathon = 42.195_km;
	auto Kiptums_time = 2_h;
	auto average_speed = Marathon / Kiptums_time;
	print(average_speed, "was Kiptum's average speed");

	// Example 2:
	mass m = 1_kg;
	speed c = constant::speed_of_light;
	energy E = m * c*c;
	print(E, "is the potential energy of 1kg mass");

	// Example 3:
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light, H2_frequency);
	print(H2_wavelength, "is the wavelength of H2 in vacuum");

	// Example 4:
	height Eiffel_Tower = 330_m;
	auto time_to_fall = sqrt((2.0 * Eiffel_Tower) / constant::gravity_of_Earth);
	print(time_to_fall, "is the free fall time from Eiffel Tower");

	// Example 5:
	auto Markus_height = 190_cm;
	auto Markus_weight = 84_kg;
	auto BMI = Markus_weight / (Markus_height * Markus_height);
	// std::cout << "Markus' BMI is " << BMI.quantity() << "." << std::endl;

	return 0;
}
