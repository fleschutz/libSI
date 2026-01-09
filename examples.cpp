#include <SI/all.h>
using namespace SI;

int main()
{ 
	print("1. What's the potential energy of just 1g mass? ");
	auto m = 1_g;
	auto c = constant::speed_of_light;
	auto E = m * c * c;
	print(E);

	print("\n2. What's the free fall time from Burj Khalifa tower in Dubai? ");
	auto tower_height = 828_m;
	auto time = formula::time_of_free_fall(tower_height, Earth::surface_gravity);
	print(time);

	print("\n3. What's the average speed of Kiptum's world record in Marathon? ");
	auto Marathon_length = 42.195_km;
	auto Kiptums_time = 2_h;
	auto avg_speed = Marathon_length / Kiptums_time;
	print(avg_speed);

 	print("\n4. What's the kinetic energy of a car at 50 km/h? ");
	auto car_mass = 1300_kg;
	auto speed_limit = 50_km_per_h;
	auto KE = formula::kinetic_energy(car_mass, speed_limit);
	print(KE);

	print("\n5. What's the wavelength of H2 in vacuum? ");
	auto H2_frequency = 1420.4057517682_MHz;
	auto H2_wavelength = formula::wavelength(constant::speed_of_light, H2_frequency);
	print(H2_wavelength);

	print("\n6. What's the frequency and wavelength of the high 'c' music note? ");
	auto high_c_frequency = 1046.5_Hz;
	auto wavelength = formula::wavelength(constant::speed_of_sound, high_c_frequency);
	print(high_c_frequency, wavelength);

	print("\n7. What's the population density on Earth (people per km² of land area)? ");
	auto density = Earth::human_population / Earth::land_area;
	print(density);

	print("\n8. How much land area would be available for each person on Earth? ");
	auto per_person = Earth::land_area / Earth::human_population;
	print(per_person);

	print("\n9. What's Donald Trump's body-mass index (BMI)? ");
	auto Donalds_weight = 102_kg;
	auto Donalds_height = 190_cm;
	auto Donalds_BMI = formula::BMI(Donalds_weight, Donalds_height);
	print(Donalds_BMI);
{
	print("\n10. What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? ");
	auto average = (0_degC + 32_degF + 491.67_degR + 273.15_K) / 4;
	print(average);
} {
	print("\n11. What's the average speed here? ");
	auto average = (278_m_per_s + 1000_km_per_h + 540_kn + 621_mph + 0.85_Mach) / 5.0;
	print(average);
} {
	print("\n12. What's a radar's geometrical horizon (the distance it can see)? ");
	auto Earth_radius = 6371.009_km;
	auto Radar_station_height = 30_ft;
	auto distance = sqrt((Earth_radius + Radar_station_height) * (Earth_radius + Radar_station_height) - Earth_radius * Earth_radius);
	print(distance);
} {
	print("\n13. What's the time needed to fly non-stop around the Earth at Mach 1? ");
	auto distance = Earth::equatorial_circumference;
	auto speed = 1_Mach;
	auto time = distance / speed;
	print(time);
} {
	print("\n14. What's the travel time of sun light to Earth? ");
	auto distance = constant::AU;
	auto speed = constant::speed_of_light;
	auto time = distance / speed;
	print(time);
} {
	print("\n15. What's the sum of 1 byte + 1kB + 1GB...(and so on)? ");
	auto sum = 1_byte + 1_kB + 1_MB + 1_GB + 1_TB + 1_PB + 1_EB + 1_ZB + 1_YB + 1_RB + 1_QB;
	print(sum);
} {
	print("\n16. What's the sum of 1m + 1NM + 1ft? ");
	auto sum = 1_m + 1_NM + 1_ft;
	print(sum);
} {
	print("\n17. What's the surface area of a soccer ball? ");
	auto circumference = 70_cm; // (69-71cm for FIFA ball size 5)
	auto radius = formula::radius_of_circumference(circumference);
	auto area = formula::area_of_sphere(radius);
	print(area);
} {
	print("\n18. What's the volume of a soccer ball? ");
	auto circumference = 70_cm; // (69-71cm for FIFA ball size 5)
	auto radius = formula::radius_of_circumference(circumference);
	auto volume = formula::volume_of_sphere(radius);
	print(volume);
} {
	print("\n19. What's the surface area of a 30cm pizza? ");
	auto diameter = 30_cm;
	auto area = formula::area_of_circle(diameter / 2);
	print(area);
} {
	print("\n20. What's the volume of a 30cm x 1cm pizza? ");
	auto diameter = 30_cm; 
	auto height = 1_cm;
	auto volume = formula::volume_of_cylinder(diameter / 2, height);
	print(volume);
} {
	print("\n21. What's the distance the Earth has travelled so far? ");
	auto distance_Earth_to_Sun = constant::AU;
	auto distance_per_year = formula::circumference_of_circle(distance_Earth_to_Sun);
	auto distance_total = distance_per_year * (Earth::age / Earth::year);
	print(distance_total);
} {
	print("\n22. What's a car's braking distance on dry asphalt from 100km/h? ");
	auto deceleration = 8_m_per_s²; // on dry asphalt
	auto distance = formula::braking_distance(100_km_per_h, 0_km_per_h, deceleration);
	print(distance);
} {
	print("\n23. What's a car's braking distance on wet asphalt from 100km/h? ");
	auto deceleration = 6_m_per_s²; // on wet asphalt
	auto distance = formula::braking_distance(100_km_per_h, 0_km_per_h, deceleration);
	print(distance);
} {
	print("\n24. How long takes a 1TB download at 100MBit speed? ");
	auto download_size  = 1_TB;
	auto download_speed = 100_Mbps;
	auto time = download_size / download_speed;
	print(time);
} {
	print("\n25. What's the aircraft's glide path on final at 10NM distance in 3000ft height? ");
	auto distance_on_final = 10_NM;
	auto height_on_final = 3000_ft;
	auto glide_path = formula::glide_path(distance_on_final, height_on_final);
	print(glide_path);
} {
	print("\n26. What are the details of a 10m x 1m oak timber log? ");
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
	print("\n27. What's the min cable wire size for 100m copper, 230V, 30A max? ");
	auto conductor_resistivity = 1.7241e-8_Ohm_m; // for copper
	auto cable_length = 100_m;
	auto max_current = 30_A;
	auto allowable_voltage_drop = 10_V; 
	auto A = (2.0 * conductor_resistivity * cable_length * max_current) / allowable_voltage_drop;
	print(A);
} {
	print("\n28. What's the windchill temperature of 5°C air temperature at 55km/h wind? ");
	auto air_temperature = 5_degC;
	auto wind_speed = 55_km_per_h;
	auto result = formula::windchill_temperature(air_temperature, wind_speed);
	print(result);
} {
	print("\n29. What's the lift force of an A380 wing on sea level at 284km/h rotation speed? ");
	auto wing_surface = 845_m²;
	dimensionless lift_coefficient = 1.3939;
	auto air_density = 1.2250_kg_per_m³; // at sea level at 15°C (59°F)
	auto air_speed = 284_km_per_h;
	auto force = formula::lift_force_of_wing(lift_coefficient, wing_surface, air_density, air_speed);
	print(force);
} {
	print("\n30. What's the impact energy of a 50m asteroid at 50,000km/h? ");
	auto diameter = 50_m;
	auto density = 2500_kg_per_m³; // mostly estimated only 
	auto speed = 50'000_km_per_h; // range is usually 50,000..100.000km/h
	auto volume = formula::volume_of_sphere(diameter / 2.0);
	auto mass = volume * density;
	auto energy = formula::kinetic_energy(mass, speed);
	print(energy);
	print_equivalent(energy);
} {
	print("\n31. What's the sound intensity of a 1W loudspeaker at 1m distance? ");
	auto power = 1_W;
	auto distance = 1_m;
	auto intensity = formula::sound_intensity(power, distance);
	print(intensity);
	print_equivalent(intensity);
} {
	print("\n32. What's the voltage of a capacitor (5V, 0.47µF, 4.7KOhm) after 10ms? ");
	auto CC = 0.47_uF;
	auto V0 = 5_V;
	auto RR = 4.7_kOhm;
	auto time = 10_ms;
	auto V1 = V0 * exp(-time / (RR * CC));
	print(V1);
} {
	print("\n33. What's the filament length of a 750g PLA roll with 2.85mm diameter? ");
	auto net_filament_weight = 750_g;
	auto filament_diameter = 2.85_mm;
	auto filament_density = 1.24_g_per_cm³; // for PLA
	volume V = net_filament_weight / filament_density;
	length L = V / (constant::pi * square(filament_diameter / 2));
	print(L);
} {
	print("\n34. What's the max diving time in 10m salt water using a 10l bottle? ");
	auto average_breathing = 20_l_per_min;
	auto bottle_volume = 10_l;
	auto bottle_pressure = 150_bar;
	auto dive_depth = 10_m;
	auto salt_water_density = 1033.23_kg_per_m³;
	auto air_pressure = 1013.25_hPa;
	auto water_pressure = salt_water_density * constant::g_0 * dive_depth + air_pressure;
	auto max_time = (bottle_volume * bottle_pressure) / (average_breathing * water_pressure);
	print(max_time);
} {
	print("\n35. What's the ballistic max height/range/flight time of a bullet fired 45° on Moon's surface? ");
	auto muzzle_velocity = 1000_m_per_s;
	auto altitude = 0_m;
	auto launch_angle = 45_deg;
	auto max_height = formula::ballistic_max_height(muzzle_velocity, altitude, launch_angle, Moon::surface_gravity);
	auto max_range = formula::ballistic_max_range(muzzle_velocity, altitude, launch_angle, Moon::surface_gravity);
	auto flight_time = formula::ballistic_travel_time(muzzle_velocity, altitude, launch_angle, Moon::surface_gravity);
	print(max_height, max_range, flight_time);
} {
	print("\n36. What's the average speed to travel around the Earth in 80 days? ");
	auto distance = Earth::equatorial_circumference;
	auto time = 80_days;
	auto avg_speed = distance / time;
	print(avg_speed);
} {
	print("\n37. What's the min speed to escape from the Moon? ");
	auto speed = formula::gravitational_escape_speed(Moon::mass, Moon::mean_radius);
	print(speed);
} {
	for (const auto& material : data::materials)
	{
		print("\n");
		print(material.name);
		print(": ");
		print(material.density);
	}
	print("\nAlu: ");
	print(data::Aluminium.density);
} {
	// Here's the basic principle:
	dimensionless x = 42;        // <- x contains a dimensionless number (no unit)
	SI::time t = x * 1_sec;      // <- t is now 42 seconds
	dimensionless y = t / 1_sec; // <- y again contains a dimensionless number (no unit)
	// NOTE: this does not work for celsius and fahrenheit due to the offset!
}
	return 0;
}
