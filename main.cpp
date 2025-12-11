#include "SI/everything.hpp"
using namespace si;

int main()
{
	// Example 1:
	auto m = 1_kg;
	auto c = constant::speed_of_light;
	auto E = m * c * c;
	print(E, "is the potential energy of 1 kg mass");

	// Example 2: 
	auto Marathon_distance = 42.195_km;
	auto Kiptums_time = 2_h;
	auto Kiptums_average_speed = Marathon_distance / Kiptums_time;
	print(Kiptums_average_speed, "was Kiptum's average speed");

	// Example 3:
	auto car = 1500_kg;
	auto normal_speed = 30_mph;
	auto KE = formula::kinetic_energy(car, normal_speed);
	print(KE, "is the kinetic energy of a normal car at 30MPH");

	// Example 4:
	auto avg_length = (1_m + 10_dm + 100_cm + 1000_mm + 0.001_km + 3.28084_ft) / 6;
	print(avg_length, "average length");

	// Example 5:
	auto avg_speed = (10_kmh + 3_kn + 7_mph + 5.5_Mach) / 4;
	print(avg_speed, "average speed");

	// Example 6:
	auto avg_temperature = (0_degC + 32_degF + 273.15_K) / 3;
	print(avg_temperature, "average temperature");

	// Example 7:
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light, H2_frequency);
	print(H2_wavelength, "is the wavelength of H2 in vacuum");

	// Example 8:
	height Eiffel_Tower_height = 330_m;
	auto time_falling = formula::free_fall_time(Eiffel_Tower_height, Earth::gravity);
	print(time_falling, "is the Eiffel Tower's free fall time");

	// Example 9:
	auto Markus_height = 190_cm;
	auto Markus_weight = 84_kg;
	auto BMI = Markus_weight / (Markus_height * Markus_height);
	// std::cout << "is Markus' BMI" << BMI.quantity() << "." << std::endl;

	// Example 9:
	auto Earth_radius = 6371.009_km;
	auto Radar_station_height = 30_ft;
	auto distance = sqrt((Earth_radius + Radar_station_height) * (Earth_radius + Radar_station_height) - Earth_radius * Earth_radius);
	print(distance, "radar's geometrical horizon (the distance it can see)");

	// Example 10:
	auto fly_distance = Earth::equatorial_circumference;
	auto fly_speed = 1_Mach;
	auto time_needed = fly_distance / fly_speed;
	print(time_needed, "is needed to fly non-stop around the Earth at Mach 1");

	return 0;
}
