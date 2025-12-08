#include "SI/everything.hpp"
using namespace si;

int main()
{
	// Example 1: 
	auto Marathon_distance = 42.195_km;
	auto Kiptums_time = 2_h;
	auto average_speed = Marathon_distance / Kiptums_time;
	print(average_speed, "was Kiptum's average speed");

	// Example 2:
	mass m = 1_kg;
	speed c = constant::speed_of_light;
	energy E = m * (c*c);
	print(E, "is the potential energy of 1kg mass");

	// Example 3:
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light, H2_frequency);
	print(H2_wavelength, "is the wavelength of H2 in vacuum");

	// Example 4:
	height Eiffel_Tower_height = 330_m;
	auto time_falling = formula::free_fall_time(Eiffel_Tower_height, constant::gravity_of_Earth);
	print(time_falling, "is the Eiffel Tower's free fall time");

	// Example 5:
	auto Markus_height = 190_cm;
	auto Markus_weight = 84_kg;
	auto BMI = Markus_weight / (Markus_height * Markus_height);
	// std::cout << "is Markus' BMI" << BMI.quantity() << "." << std::endl;

	// Example 6:
	auto Earth_radius = 6371.009_km;
	auto Radar_station_height = 30_ft;
	auto distance = sqrt((Earth_radius + Radar_station_height) * (Earth_radius + Radar_station_height) - Earth_radius * Earth_radius);
	print(distance, "radar's geometrical horizon (the distance it can see)");

	// Example 7:
	double MachSpeed = 5.5;
	auto speed = MachSpeed * constant::speed_of_sound;
	print(speed, "is M5.5 speed");

	// Example 8:
	auto average_temp = (7_degC + 30_degF + 200_K) / 3;
	print(average_temp, "average temperature");

	return 0;
}
