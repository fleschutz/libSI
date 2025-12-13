#include "SI/everything.hpp"
using namespace si;

int main()
{
	si::unit_tests();

	// Let's calculate the average speed of Kiptum's world record in Marathon...
	auto Marathon_distance = 42.195_km;
	auto Kiptums_time = 2_h;
	auto Kiptums_average_speed = Marathon_distance / Kiptums_time;
	print(Kiptums_average_speed, "was Kiptum's average speed");

	// Let's calculate the potential energy of 1 kg mass...
	auto m = 1_kg;
	auto c = constant::speed_of_light_in_vacuum;
	auto E = m * c * c;
	print(E, "is the potential energy of 1 kg mass");

	// Let's calculate the kinetic energy of a normal car at 30MPH...
	auto car = 1500_kg;
	auto normal_speed = 30_mph;
	auto KE = formula::kinetic_energy(car, normal_speed);
	print(KE, "is the kinetic energy of a normal car at 30MPH");

	// Example 5:
	auto avg_speed = (330_mps + 1000_kmh + 300_kn + 300_kt + 7_mph + 1_Mach) / 6;
	print(avg_speed, "average speed");

	// Example 6:
	auto avg_temperature = (0_degC + 32_degF + 273.15_K) / 3;
	print(avg_temperature, "average temperature");

	// Example 7:
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light_in_vacuum, H2_frequency);
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

	// Let's calculate the Earth year:
	auto sunMass = Sun::mass;
	auto earthMass = Earth::mass;
	auto sun_to_earth = constant::AU;
#if 0
	auto year = formula::Kepler(sunMass + earthMass, a);
	print(year, "is a Earth year");
#endif

	// Let's calculate bytes:
	auto sum = 1_byte + 1_kB + 1_MB + 1_GB + 1_TB + 1_PB + 1_EB + 1_ZB;// + 1_YB + 1_RB + 1_QB;
	print(sum, "is the total number of bytes");

	return 0;
}
