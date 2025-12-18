// SI/print.hpp - simple print to console interface
#pragma once

#include <iostream>
#include "units.hpp"

namespace si
{
	// SI BASE UNITS:
	void print(time t)
	{
		if (abs(t) >= year(1))
			std::cout << year(t) << " year(s)" << std::endl;
		else if (abs(t) >= week(1))
			std::cout << week(t) << " week(s)" << std::endl;
		else if (abs(t) >= day(2))
			std::cout << day(t) << " day(s)" << std::endl;
		else if (abs(t) >= hour(1))
			std::cout << (int)hour(t) << "h " << ((int)minute(t)) % 60 << "min" << std::endl;
		else if (abs(t) >= minute(1))
			std::cout << minute(t) << "min" << std::endl;
		else
			std::cout << second(t) << "sec" << std::endl;
	}

	void print(length d)
	{
		if (abs(d) >= constant::lightyear * 1000000)
			std::cout << (d / (constant::lightyear * 1000000)) << " megalight-year(s)" << std::endl;
		else if (abs(d) >= constant::lightyear * 1000)
			std::cout << (d / (constant::lightyear * 1000)) << " kilolight-year(s)" << std::endl;
		else if (abs(d) >= constant::lightyear)
			std::cout << (d / constant::lightyear) << " light-year(s)" << std::endl;
		else if (abs(d) >= kilometer(1))
			std::cout << kilometer(d) << "km" << std::endl;
		else if (abs(d) >= meter(1))
			std::cout << meter(d) << "m" << std::endl;
		else
			std::cout << centimeter(d) << "cm" << std::endl;
	}

	void print(mass m)
	{
		if (abs(m) >= kilogram(1))
			std::cout << kilogram(m) << "kg" << std::endl;
		else
			std::cout << gram(m) << "g" << std::endl;
	}

	void print(temperature T)
	{
		if (T >= celsius(0))
			std::cout << celsius(T) << "°C " << std::endl;
		else
			std::cout << kelvin(T) << "°K " << std::endl;
	}

	// SI DERIVED UNITS:
	void print(area a)
	{
		if (abs(a) >= kilometer2(1))
			std::cout << kilometer2(a) << "km²" << std::endl;
		else if (abs(a) >= meter2(1.0))
			std::cout << meter2(a) << "m²" << std::endl;
		else
			std::cout << centimeter2(a) << "cm²" << std::endl;
	}

	void print(volume v)
	{
		if (abs(v) >= meter3(1.0))
			std::cout << meter3(v) << "m³" << std::endl;
		else
			std::cout << centimeter3(v) << "cm³" << std::endl;
	}

	void print(speed v)
	{
		std::cout << kilometers_per_hour(v) << "km/h" << std::endl;
	}

	void print(acceleration a)
	{
		std::cout << meters_per_second2(a) << "m/s²" << std::endl;
	}

	void print(energy E)
	{
		if (abs(E) >= gigajoule(1))
			std::cout << gigajoule(E) << " GJ " << std::endl;
		else if (abs(E) >= megajoule(1))
			std::cout << megajoule(E) << " MJ " << std::endl;
		else if (abs(E) >= kilojoule(1))
			std::cout << kilojoule(E) << " kJ " << std::endl;
		else
			std::cout << joule(E) << " Joule " << std::endl;
	}

	void print(angle a)
	{
		std::cout << degree(a) << "° " << std::endl;
	}

#if 0
	void print(kilograms_per_meter2 v)
	{
		std::cout << kilograms_per_meter2(v) << "kg/m²" << std::endl;
	}
#endif

	void print(quantity number)
	{
		std::cout << number << std::endl;
	}

	void print(const std::string& text)
	{
		std::cout << text;
	}
}
