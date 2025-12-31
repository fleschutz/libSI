// SI/print.h - print text, quantities, and SI values to the console
#pragma once

#include <iostream>
#include "to_string.h"

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

	// Internal print function.
	void _print(const std::string& text)
	{
		std::cout << text;
	}

	// The 7 SI Base Units
	// -------------------
	void print(length d)
	{
		_print(to_string(d));
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
		else if (abs(t) >= 1_μs)
			print(t / 1_μs, "μs");
		else
			print(t / 1_ns, "ns");
	}

	void print(mass m)
	{
		if (abs(m) >= 1_Gt)
			print(m / 1_Gt, "Gt (gigatons)");
		else if (abs(m) >= 1_Mt)
			print(m / 1_Mt, "Mt (megatons)");
		else if (abs(m) >= 1_kt)
			print(m / 1_kt, "kt (kilotons)");
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

	void print(temperature T)
	{
		if (T >= 250_K && T <= 470_K) // temperature range for humans
		{
			print(celsius(T), "°C");
			_print("/ ");
			print(fahrenheit(T), "°F");
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

	void print(electric_current I)
	{
		if (abs(I) >= 1_A)
			print(I / 1_A, "A");
		else if (abs(I) >= 1_mA)
			print(I / 1_mA, "mA");
		else if (abs(I) >= 1_μA)
			print(I / 1_μA, "μA");
		else if (abs(I) >= 1_nA)
			print(I / 1_nA, "nA");
		else
			print(I / 1_pA, "pA");
	}

	// The 22 Derived SI Units
	// -----------------------
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
		else if (abs(v) >= 1_l)
			print(v / 1_l, "l");
		else if (abs(v) >= 1_cm³)
			print(v / 1_cm³, "cm³");
		else if (abs(v) >= 1_mm³)
			print(v / 1_mm³, "mm³");
		else
			print(v / 1_μm³, "μm³");
	}

	void print(velocity v)
	{
		_print(to_string(v));
	}

	void print(acceleration a)
	{
		print(a / 1_m_per_s², "m/s²");
	}

	void print(frequency f)
	{
		if (abs(f) >= 1_THz)
			print(f / 1_THz, "THz");
		else if (abs(f) >= 1_GHz)
			print(f / 1_GHz, "GHz");
		else if (abs(f) >= 1_MHz)
			print(f / 1_MHz, "MHz");
		else if (abs(f) >= 1_kHz)
			print(f / 1_kHz, "kHz");
		else
			print(f / 1_Hz, "Hz");
	}

	void print(force F)
	{
		if (abs(F) >= 1_GN)
			print(F / 1_GN, "GN");
		else if (abs(F) >= 1_MN)
			print(F / 1_MN, "MN");
		else if (abs(F) >= 1_kN)
			print(F / 1_kN, "kN");
		else if (abs(F) >= 1_N)
			print(F / 1_N, "N");
		else if (abs(F) >= 1_mN)
			print(F / 1_mN, "mN");
		else
			print(F / 1_μN, "μN");
	}

	void print(energy E)
	{
		if (abs(E) >= 1_PJ)
			print(E / 1_PJ, "PJ (petajoules)");
		else if (abs(E) >= 1_TJ)
			print(E / 1_TJ, "TJ (terajoules)");
		else if (abs(E) >= 1_GJ)
			print(E / 1_GJ, "GJ");
		else if (abs(E) >= 1_MJ)
			print(E / 1_MJ, "MJ");
		else if (abs(E) >= 1_kJ)
			print(E / 1_kJ, "kJ");
		else
			print(E / 1_J, "J");
	}

	void print_as_TNT_equivalent(energy E)
	{
		const auto one_kg_TNT = 4.184_MJ; // (explosion energy of 1kg Trinitrotoluol))
		auto TNT_mass = kilogram(E / one_kg_TNT);
		print(TNT_mass);
		_print("TNT ");
	}

	void print_as_Hiroshima_equivalent(energy E)
	{
		const auto Hiroshima_bomb = 62_TJ; // (explosion energy of the Hiroshima bomb)
		quantity factor = E / Hiroshima_bomb;
		print(factor);
		_print("Hiroshima bombs ");
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

	void print(pressure p)
	{
		if (abs(p) >= 1_MPa)
			print(p / 1_MPa, "MPa");
		else if (abs(p) >= 1_kPa)
			print(p / 1_kPa, "kPa");
		else if (abs(p) >= 1_hPa)
			print(p / 1_hPa, "hPa");
		else
			print(p / 1_Pa, "Pa");
	}

	void print(electric_charge Q)
	{
		if (abs(Q) >= 1_Ah)
			print(Q / 1_Ah, "Ah");
		else
			print(Q / 1_mAh, "mAh");
	}

	void print(angle a)
	{
		print(a / 1_deg, "°");
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

	void print(volume v, mass m, energy e)
	{
		print(v); print(m); print(e);
	}

	void print(mass m, energy e)
	{
		print(m); print(e);
	}
}
