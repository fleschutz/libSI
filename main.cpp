#include "SI/everything.hpp"
using namespace si;

int main()
{

{	
	print("What's the average speed of Kiptum's world record in Marathon? It's...");
	auto distance = 42.195_km;
	auto Kiptums_time = 2_h;
	auto average_speed = distance / Kiptums_time;
	print(average_speed);
} {
	print("What's the potential energy of 1kg mass? It's... ");
	auto m = 1_kg;
	auto c = constant::speed_of_light_in_vacuum;
	auto E = m * c * c;
	print(E);
} {
 	print("What's the kinetic energy of a car at 50 km/h? It's... ");
	auto car = 1300_kg;
	auto normal_speed = 50_kmh;
	auto KE = formula::kinetic_energy(car, normal_speed);
	print(KE);
} {
	print("What's the average speed here? It's... ");
	auto average = (330_mps + 1000_kmh + 300_kn + 300_kt + 7_mph + 1_Mach) / 6;
	print(average);
} {
	print("What's the average temperature here? It's... ");
	auto average = (0_degC + 32_degF + 273.15_K) / 3;
	print(average);
} {
	print("What's the wavelength of H2 in vacuum? It's... ");
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light_in_vacuum, H2_frequency);
	print(H2_wavelength);
} {
	print("What's the free fall time from Eiffel Tower in Paris? It's... ");
	height Eiffel_Tower_height = 330_m;
	auto result = formula::free_fall_time(Eiffel_Tower_height, Earth::gravity);
	print(result);
} {
	print("What's Markus BMI? OMG, it's... ");
	auto Markus_weight = 90_kg;
	auto Markus_height = 190_cm;
	auto BMI = Markus_weight / (Markus_height * Markus_height);
	print(kilograms_per_meter2(BMI));
} {
	print("What's a radar's geometrical horizon (the distance it can see)? It's... ");
	auto Earth_radius = 6371.009_km;
	auto Radar_station_height = 30_ft;
	auto distance = sqrt((Earth_radius + Radar_station_height) * (Earth_radius + Radar_station_height) - Earth_radius * Earth_radius);
	print(distance);
} {
	print("What's the time needed to fly non-stop around the Earth at Mach 1? It's... ");
	auto distance = Earth::equatorial_circumference;
	auto speed = 1_Mach;
	auto time = distance / speed;
	print(time);
} {
	print("What's the travel time of sun light to Earth? It's... ");
	auto distance = constant::AU;
	auto speed = constant::speed_of_light_in_vacuum;
	auto time = distance / speed;
	print(time);
} {
	print("What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... ");
	auto sum = 1_byte + 1_kB + 1_MB + 1_GB + 1_TB + 1_PB + 1_EB + 1_ZB + 1_YB + 1_RB + 1_QB;
	print(sum);
} {
	print("What's the population density on Earth (people per km² of land area)? It's... ");
	auto population_density = Earth::human_population / si::kilometer2(Earth::land_area);
	print(population_density);
} {
	print("How much land area would be available for each person on Earth? It's... ");
	auto per_person = Earth::land_area / Earth::human_population;
	print(per_person);
} {
	print("What's the surface area of a soccer ball (in FIFA size 5)? It's... ");
	auto circumference = 70_cm; // (69-71 cm)
	auto radius = formula::radius_of_circumference(circumference);
	auto area = formula::area_of_ball(radius);
	print(area);
} {
	print("What's the volume of a soccer ball (in FIFA size 5)? It's... ");
	auto circumference = 70_cm; // (69-71 cm)
	auto radius = formula::radius_of_circumference(circumference);
	auto volume = formula::volume_of_ball(radius);
	print(volume);
} {
	print("What's the surface area of a 30cm pizza? It's... ");
	auto diameter = 30_cm;
	auto area = formula::area_in_circle(diameter / 2);
	print(area);
} {
	print("What's the volume of a 30x1cm pizza? It's... ");
	auto diameter = 30_cm; 
	auto height = 1_cm;
	auto volume = formula::area_in_circle(diameter / 2) * height;
	print(volume);
} {
#if 0
	// Let's calculate the Earth year:
	auto sunMass = Sun::mass;
	auto earthMass = Earth::mass;
	auto sun_to_earth = constant::AU;
	auto year = formula::Kepler(sunMass + earthMass, a);
	print(year, "is a Earth year");
#endif
   }
	si::unit_tests();
	return 0;
}
