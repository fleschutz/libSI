// SI/print.h - convenient print to the console functions (single values, equivalents, and multiple values).
#pragma once

#include <iostream>
#include "to_string.h"

namespace SI
{
	// Print arbitrary text:
	void print(const std::string& text)
	{
		std::cout << text;
	}

	// Print the 7 SI base units:
	void print(length d)
	{
		print(to_string(d));
	}

	void print(time t)
	{
		print(to_string(t));
	}

	void print(mass m)
	{
		print(to_string(m));
	}

	void print(temperature T)
	{
		print(to_string(T));
	}

	void print(electric_current I)
	{
		print(to_string(I));
	}

	// Print the 22 derived SI Units:
	void print(area a)
	{
		print(to_string(a));
	}

	void print(per_area a)
	{
		print(to_string(a));
	}

	void print(mass_per_area m)
	{
		print(to_string(m));
	}

	void print(volume v)
	{
		print(to_string(v));
	}

	void print(velocity v)
	{
		print(to_string(v));
	}

	void print(acceleration a)
	{
		print(to_string(a));
	}

	void print(frequency f)
	{
		print(to_string(f));
	}

	void print(frequency f, length d)
	{
		print(to_string(f)); print(", "); print(to_string(d));
	}

	void print(force F)
	{
		print(to_string(F));
	}

	void print(energy E)
	{
		print(to_string(E));
	}

	void print(power P)
	{
		print(to_string(P));
	}

	void print(power_intensity I)
	{
		print(to_string(I));
	}

	void print(pressure p)
	{
		print(to_string(p));
	}

	void print(electric_potential U)
	{
		print(to_string(U));
	}

	void print(electric_charge Q)
	{
		print(to_string(Q));
	}

	void print(angle a)
	{
		print(to_string(a));
	}

	void print(dimensionless value)
	{
		std::cout << value;
	}

	// Print equivalents:
	void print(dimensionless value, const std::string& unit)
	{
		std::cout << value << unit << " ";
	}

	void print_equivalent(energy E)
	{
		const auto one_kg_TNT = 4.184_MJ; // (explosion energy of 1kg Trinitrotoluol))
		const auto Hiroshima_bomb = 62_TJ; // (explosion energy of the Hiroshima bomb)

		print(" (=");
		auto TNT_mass = kilogram(E / one_kg_TNT);
		print(TNT_mass);
		print(" TNT, ");

		dimensionless factor = E / Hiroshima_bomb;
		print(factor, " Hiroshima bombs)");
	}

	void print_equivalent(power_intensity I)
	{
		dimensionless decibel = 10.0 * std::log10((I / 1_W_per_m²) / 1e-12);
		print(" (=");
		print(decibel, " dB)");
	}

	// Print multiple units:
	void print(length a, length b)
	{
		print(a); print(", "); print(b);
	}

	void print(length a, length b, time c)
	{
		print(a); print(", "); print(b); print(", "); print(c);
	}

	void print(area a, volume v, mass m)
	{
		print(a); print(", "); print(v); print(", "); print(m);
	}

	void print(area a, volume v, mass m, power p)
	{
		print(a); print(", "); print(v); print(", "); print(m); print(", "); print(p);
	}

	void print(volume v, mass m, energy e)
	{
		print(v); print(", "); print(m); print(", "); print(e);
	}

	void print(mass m, energy e)
	{
		print(m); print(", "); print(e);
	}

	void print(pressure p, time t)
	{
		print(p); print(", "); print(t);
	}
}
