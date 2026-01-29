// <SI/IO.h> - I/O functions to print single and multiple SI datatypes, equivalents, and text.
#pragma once

#include <iostream>
#include <SI/conversion.h>

namespace SI
{
	// the internal print function
	void _print(const std::string& text)
	{
		std::cout << text;
	}

	// print a single SI datatype
	template <typename T>
	void print(T x)
	{
		_print(to_string(x));
	}

	// print two SI datatypes
	template <typename T1, typename T2>
	void print(T1 val1, T2 val2)
	{
		_print(to_string(val1)); _print(", "); _print(to_string(val2));
	}

	// print three SI datatypes
	template <typename T1, typename T2, typename T3>
	void print(T1 val1, T2 val2, T3 val3)
	{
		_print(to_string(val1)); _print(", "); _print(to_string(val2)); _print(", "); _print(to_string(val3));
	}

	// print four SI datatypes
	template <typename T1, typename T2, typename T3, typename T4>
	void print(T1 val1, T2 val2, T3 val3, T4 val4)
	{
		_print(to_string(val1)); _print(", "); _print(to_string(val2)); _print(", "); _print(to_string(val3)); _print(", "); _print(to_string(val4));
	}

	// print five SI datatypes
	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	void print(T1 val1, T2 val2, T3 val3, T4 val4, T5 val5)
	{
		_print(to_string(val1)); _print(", "); _print(to_string(val2)); _print(", "); _print(to_string(val3)); _print(", "); _print(to_string(val4)); _print(", "); _print(to_string(val5));
	}

	// print equivalent information
	void print_equivalent(energy E)
	{
		const auto one_kg_TNT = 4.184_MJ; // (explosion energy of 1kg Trinitrotoluol))
		const auto Hiroshima_bomb = 62_TJ; // (explosion energy of the Hiroshima bomb)
		mass TNT = kilograms(E / one_kg_TNT);
		dimensionless factor = E / Hiroshima_bomb;

		_print(" (=");
		print(TNT);
		_print(" TNT, ");
		print(factor);
		_print(" Hiroshima bombs)");
	}

	void print_equivalent(power_intensity I)
	{
		dimensionless decibel = 10.0 * std::log10((I / 1_W_per_m²) / 1e-12);
		_print(" (=");
		print(decibel);
		_print("dB)");
	}

} // namespace SI

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
