// SI/print.h - print text, quantities, and SI values to the console
#pragma once

#include <iostream>
#include "literals.h"
#include "values/Earth.h"

namespace SI
{
	void print(const std::string& text)
	{
		std::cout << std::endl << text.c_str();
	}

	void print(quantity number)
	{
		std::cout << number << " ";
	}

	void print(quantity value, const std::string& unit)
	{
		std::cout << value << unit.c_str() << " ";
	}

	// The 7 SI Base Units
	// -------------------
	void print(length d)
	{
		if (abs(d) >= 1_Mly)
			print(d / 1_Mly, "Mly (megalight-years)");
		else if (abs(d) >= 1_pc)
			print(d / 1_pc, "pc (parsec)");
		else if (abs(d) >= 1_ly)
			print(d / 1_ly, "ly (light-years)");
		else if (abs(d) >= 1_au)
			print(d / 1_au, "au (astronomical unit)");
		else if (abs(d) >= 1_km)
			print(d / 1_km, "km");
		else if (abs(d) >= 1_m)
			print(d / 1_m, "m ");
		else if (abs(d) >= 1_cm)
			print(d / 1_cm, "cm");
		else if (abs(d) >= 1_mm)
			print(d / 1_mm, "mm");
		else
			print(d / 1_μm, "μm");
	}

	void print(time t)
	{
		if (abs(t) >= Earth::year)
			print(t / Earth::year, " year(s)");
		else if (abs(t) >= Earth::week)
			print(t / Earth::week, " week(s)");
		else if (abs(t) > Earth::day)
			print(t / Earth::day, " day(s)");
		else if (abs(t) >= 1_h)
		{
			print((int)(t / 1_h), "h");
			print((int)(t / 1_min) % 60, "min");
		}
		else if (abs(t) >= 1_min)
		{
			print((int)(t / 1_min), "min");
			print((int)(t / 1_sec) % 60, "sec");
		}
		else if (abs(t) >= 1_sec)
			print(t / 1_sec, "sec");
		else if (abs(t) >= 1_ms)
			print(t / 1_ms, "ms");
		else
			print(t / 1_μs, "μs");
	}

	void print(mass m)
	{
		if (abs(m) >= 1_mt)
			print(m / 1_mt, "mt");
		else if (abs(m) >= 1_kt)
			print(m / 1_kt, "kt");
		else if (abs(m) >= 1_t)
			print(m / 1_t, "t");
		else if (abs(m) >= 1_kg)
			print(m / 1_kg, "kg");
		else if (abs(m) >= 1_g)
			print(m / 1_g, "g");
		else if (abs(m) >= 1_mg)
			print(m / 1_mg, "mg");
		else
			print(m / 1_μg, "μg");
	}

	static void _print(const std::string& text)
	{
		std::cout << text;
	}

	void print(thermodynamic_temperature T)
	{
		if (T >= 250_K && T <= 470_K) // temperature range for humans
		{
			print(kelvin(T), "K"); _print("(");
			print(celsius(T), "°C"); _print(", ");
			print(fahrenheit(T), "°F"); _print(")");
		}
		else if (abs(T) >= 1_GK)
			print(T / 1_GK, "GK");
		else if (abs(T) >= 1_MK)
			print(T / 1_MK, "MK");
		else if (abs(T) >= 1_K)
			print(T / 1_K, "K");
		else if (abs(T) >= 1_mK)
			print(T / 1_mK, "mK");
		else if (abs(T) >= 1_μK)
			print(T / 1_μK, "μK");
		else 
			print(T / 1_nK, "nK");
	}
#if 0
	void print(amount_of_substance A)
	{
		print(A / 1_mol, "mol");
	}

	void print(luminous_intensity I)
	{
		print(I / 1_cd, "cd");
	}
#endif

	// The 22 SI derived units:
	void print(area a)
	{
		if (abs(a) >= 1_km²)
			print(a / 1_km², "km²");
		else if (abs(a) >= 1_hm²)
			print(a / 1_hm², "hm²");
		else if (abs(a) >= 1_m²)
			print(a / 1_m², "m²");
		else if (abs(a) >= 1_cm²)
			print(a / 1_cm², "cm²");
		else if (abs(a) >= 1_mm²)
			print(a / 1_mm², "mm²");
		else
			print(a / 1_μm², "μm²");
	}

	void print(volume v)
	{
		if (abs(v) >= 1_km³)
			print(v / 1_km³, "km³");
		else if (abs(v) >= 1_m³)
			print(v / 1_m³, "m³");
		else if (abs(v) >= 1_cm³)
			print(v / 1_cm³, "cm³");
		else if (abs(v) >= 1_mm³)
			print(v / 1_mm³, "mm³");
		else
			print(v / 1_μm³, "μm³");
	}

	void print(speed v)
	{
		if (abs(v) >= 1_kmh)
			print(v / 1_kmh, "km/h");
		else if (abs(v) >= 1_mps)
			print(v / 1_mps, "m/s");
		else
			print(v / 1_mmh, "mm/h");
	}

	void print(acceleration a)
	{
		print(a / 1_mps², "m/s²");
	}

	void print(energy E)
	{
		if (abs(E) >= 1_TJ)
			print(E / 1_TJ, "TJ");
		else if (abs(E) >= 1_GJ)
			print(E / 1_GJ, "GJ");
		else if (abs(E) >= 1_MJ)
			print(E / 1_MJ, "MJ");
		else if (abs(E) >= 1_kJ)
			print(E / 1_kJ, "kJ");
		else
			print(E / 1_J, "J");
	}

	void print(power P)
	{
		if (abs(P) >= 1_TWh)
			print(P / 1_TWh, "TWh");
		else if (abs(P) >= 1_GWh)
			print(P / 1_GWh, "GWh");
		else if (abs(P) >= 1_MWh)
			print(P / 1_MWh, "MWh");
		else if (abs(P) >= 1_kWh)
			print(P / 1_kWh, "kWh");
		else
			print(P / 1_Wh, "Wh");
	}

	void print(angle a)
	{
		print(degree(a), "°");
	}

#if 0
	void print(pascal_ p)
	{
		print(p / 1_Pa, "Pa");
	}

	void print(watt_per_meter2 w)
	{
		print(w / 1_W_per_m², "W/m²");
	}
#endif

	void print(BMI v)
	{
		print(v / 1_kg_per_m², " BMI");
	}

	void print(area a, volume v, mass m)
	{
		print(a); print(v); print(m);
	}

	void print(area a, volume v, mass m, power p)
	{
		print(a); print(v); print(m); print(p);
	}
}
