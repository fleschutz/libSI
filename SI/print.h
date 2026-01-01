// SI/print.h - simple print to the console interface
#pragma once

#include <iostream>
#include "to_string.h"

namespace SI
{
	void print(const std::string& text)
	{
		std::cout << text;
	}

	void print(quantity number)
	{
		std::cout << number << " ";
	}

	void print(quantity number, const std::string& unit)
	{
		std::cout << number << unit << " ";
	}

	// The 7 SI Base Units
	// -------------------
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

	// The 22 Derived SI Units
	// -----------------------
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

	void print(force F)
	{
		print(to_string(F));
	}

	void print(energy E)
	{
		print(to_string(E));
	}

	void print_equivalent(energy E)
	{
		const auto one_kg_TNT = 4.184_MJ; // (explosion energy of 1kg Trinitrotoluol))
		const auto Hiroshima_bomb = 62_TJ; // (explosion energy of the Hiroshima bomb)
						  //
		print(" (=");
		auto TNT_mass = kilogram(E / one_kg_TNT);
		print(TNT_mass);
		print(" TNT, ");

		quantity factor = E / Hiroshima_bomb;
		print(factor, " Hiroshima bombs)");
	}

	void print(power P)
	{
		print(to_string(P));
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

	// Multiple Units
	// --------------
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
}
