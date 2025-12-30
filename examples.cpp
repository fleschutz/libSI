#include "SI/all.h"
using namespace SI;

int main()
{ {	
	print("What's the potential energy of just 1g mass? It's... ");
	auto m = 1_g;
	auto c = constant::speed_of_light;
	auto E = m * c * c;
	print(E);
} {
	print("What's the average speed of Kiptum's world record in Marathon? It's...");
	auto distance = 42.195_km;
	auto Kiptums_time = 2_h;
	auto avg_speed = distance / Kiptums_time;
	print(avg_speed);
} {
	print("What's the free fall time from Burj Khalifa tower in Dubai? It's... ");
	auto tower_height = 828_m;
	auto time = formula::time_of_free_fall(tower_height, Earth::surface_gravity);
	print(time);
} {
 	print("What's the kinetic energy of a car at 50 km/h? It's... ");
	auto car_mass = 1300_kg;
	auto speed_limit = 50_km_per_h;
	auto KE = formula::kinetic_energy(car_mass, speed_limit);
	print(KE);
} {
	print("What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? It's... ");
	auto average = (0_degC + 32_degF + 491.67_degR + 273.15_K) / 4;
	print(average);
} {
	print("What's the average speed here? It's... ");
	auto average = (278_m_per_s + 1000_km_per_h + 540_kn + 621_mph + 0.85_Mach) / 5.0;
	print(average);
} {
	print("What's the wavelength of H2 in vacuum? It's... ");
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light, H2_frequency);
	print(H2_wavelength);
} {
	print("What's the wavelength of the high 'c' music note? It's... ");
	auto high_c_frequency = 1046.5_Hz;
	auto wavelength = formula::wavelength(constant::speed_of_sound, high_c_frequency);
	print(wavelength);
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
	auto speed = constant::speed_of_light;
	auto time = distance / speed;
	print(time);
} {
	print("What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... ");
	auto sum = 1_byte + 1_kB + 1_MB + 1_GB + 1_TB + 1_PB + 1_EB + 1_ZB + 1_YB + 1_RB + 1_QB;
	print(sum);
} {
	print("What's the sum of 1m + 1NM + 1ft? It's... ");
	auto sum = 1_m + 1_NM + 1_ft;
	print(sum);
} {
	print("What's the population density on Earth (people per km² of land area)? It's... ");
	auto population_density = Earth::human_population / kilometer2(Earth::land_area);
	print(population_density);
} {
	print("How much land area would be available for each person on Earth? It's... ");
	auto per_person = Earth::land_area / Earth::human_population;
	print(per_person);
} {
	print("What's the surface area of a soccer ball? It's... ");
	auto circumference = 70_cm; // (69-71cm for FIFA ball size 5)
	auto radius = formula::radius_of_circumference(circumference);
	auto area = formula::area_of_sphere(radius);
	print(area);
} {
	print("What's the volume of a soccer ball? It's... ");
	auto circumference = 70_cm; // (69-71cm for FIFA ball size 5)
	auto radius = formula::radius_of_circumference(circumference);
	auto volume = formula::volume_of_sphere(radius);
	print(volume);
} {
	print("What's the surface area of a 30cm pizza? It's... ");
	auto diameter = 30_cm;
	auto area = formula::area_of_circle(diameter / 2);
	print(area);
} {
	print("What's the volume of a 30cm x 1cm pizza? It's... ");
	auto diameter = 30_cm; 
	auto height = 1_cm;
	auto volume = formula::volume_of_cylinder(diameter / 2, height);
	print(volume);
} {
	print("What's the distance the Earth has travelled so far? It's... ");
	auto distance_Earth_to_Sun = constant::AU;
	auto distance_per_year = formula::circumference_of_circle(distance_Earth_to_Sun);
	auto distance_total = distance_per_year * (Earth::age / Earth::year);
	print(distance_total);
} {
	print("What's a car's braking distance on dry asphalt from 100km/h? It's... ");
	auto deceleration = 8_m_per_s²; // on dry asphalt
	auto distance = formula::braking_distance(100_km_per_h, 0_km_per_h, deceleration);
	print(distance);
} {
	print("What's a car's braking distance on wet asphalt from 100km/h? It's... ");
	auto deceleration = 6_m_per_s²; // on wet asphalt
	auto distance = formula::braking_distance(100_km_per_h, 0_km_per_h, deceleration);
	print(distance);
} {
	print("How long takes a 1TB download at 100MBit speed? It's... ");
	auto download_size  = 1_TB;
	auto download_speed = 100_Mbps;
	auto time = download_size / download_speed;
	print(time);
} {
	print("What's the aircraft's glide path on final at 10NM distance in 3000ft height? It's... ");
	auto distance_on_final = 10_NM;
	auto height_on_final = 3000_ft;
	auto glide_path = formula::glide_path(distance_on_final, height_on_final);
	print(glide_path);
} {
	print("What's Donald Trump's body-mass index (BMI)? It's... ");
	auto Donalds_weight = 102_kg;
	auto Donalds_height = 190_cm;
	auto Donalds_BMI = formula::BMI(Donalds_weight, Donalds_height);
	print(Donalds_BMI);
} {
	print("What are the details of a 10m x 1m oak timber log? It's... ");
	auto log_length = 10_m;
	auto log_diameter = 1_m;
	auto dry_oak_weight = 710_kg_per_m³; 
	auto dry_oak_power = 4.2_kWh_per_kg;
	auto area = formula::area_of_cylinder(log_diameter / 2, log_length);
	auto volume = formula::volume_of_cylinder(log_diameter / 2, log_length);
	auto weight = volume * dry_oak_weight;
	auto power = weight * dry_oak_power;
	print(area, volume, weight, power);
} {
	print("What's the min cable wire size for 100m copper, 230V, 30A max? It's... ");
	auto conductor_resistivity = 1.7241e-8_Ohm_m; // for copper
	auto cable_length = 100_m;
	auto max_current = 30_A;
	auto allowable_voltage_drop = 10_V; 
	auto A = (2.0 * conductor_resistivity * cable_length * max_current) / allowable_voltage_drop;
	print(A);
} {
	print("What's the windchill temperature of 5°C air temperature with 55km/h wind? It's... ");
	auto air_temperature = 5_degC;
	auto wind_speed = 55_km_per_h;
	auto result = formula::windchill_temperature(air_temperature, wind_speed);
	print(result);
} {
	print("What's the impact energy of a 50m asteroid at 50,000km/h? It's... ");
	auto diameter = 50_m;
	auto density = 2500_kg_per_m³; // mostly estimated only 
	auto speed = 50'000_km_per_h; // range is usually 50,000..100.000km/h
	auto volume = formula::volume_of_sphere(diameter / 2.0);
	auto mass = volume * density;
	auto energy = formula::kinetic_energy(mass, speed);
	print(energy);
	print_as_kg_TNT(energy);
} {
	// Here's the basic principle:
	quantity x = 42;        // <- x contains a dimensionless number (no unit)
	SI::time t = x * 1_sec; // <- t is now 42 seconds
	quantity y = t / 1_sec; // <- y again contains a dimensionless number (no unit)
}
	return 0;
}
