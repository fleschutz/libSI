// SI/print.h - simple print to console interface
#pragma once

#include <iostream>
#include "literals.h"

namespace si
{
	// The 7 SI base units:
	void print(time t)
	{
		if (abs(t) >= year(1.0))
			std::cout << year(t) << " year(s)" << std::endl;
		else if (abs(t) >= week(1.0))
			std::cout << week(t) << " week(s)" << std::endl;
		else if (abs(t) >= day(2.0))
			std::cout << day(t) << " day(s)" << std::endl;
		else if (abs(t) >= hour(1.0))
			std::cout << (int)hour(t) << "h " << ((int)minute(t)) % 60 << "min" << std::endl;
		else if (abs(t) >= minute(1.0))
			std::cout << minute(t) << "min" << std::endl;
		else
			std::cout << second(t) << "sec" << std::endl;
	}

	void print(length d)
	{
		if (abs(d) >= constant::lightyear)
			std::cout << (d / constant::lightyear) << " light-year(s)" << std::endl;
		else if (abs(d) >= 1_km)
			std::cout << (d / 1_km) << "km" << std::endl;
		else if (abs(d) >= 1_m)
			std::cout << (d / 1_m) << "m" << std::endl;
		else if (abs(d) >= 1_cm)
			std::cout << (d / 1_cm) << "cm" << std::endl;
		else
			std::cout << (d / 1_mm) << "mm" << std::endl;
	}

	void print(mass m)
	{
		if (abs(m) >= 1_t)
			std::cout << (m / 1_t) << "t" << std::endl;
		else if (abs(m) >= 1_kg)
			std::cout << (m / 1_kg) << "kg" << std::endl;
		else if (abs(m) >= 1_g)
			std::cout << (m / 1_g) << "g" << std::endl;
		else
			std::cout << (m / 1_mg) << "mg" << std::endl;
	}

	void print(temperature T)
	{
		if (abs(T) >= 1_GK)
			std::cout << (T / 1_GK) << " GK" << std::endl;
		else if (abs(T) >= 1_MK)
			std::cout << (T / 1_MK) << " MK" << std::endl;
		else if (abs(T) >= kelvin(1.0))
			std::cout << kelvin(T) << "K" << std::endl;
		else
			std::cout << (T / 1_mK) << "mK" << std::endl;
	}

	// The 22 SI derived units:
	void print(area a)
	{
		if (abs(a) >= kilometer2(1.0))
			std::cout << kilometer2(a) << "km²" << std::endl;
		else if (abs(a) >= meter2(1.0))
			std::cout << meter2(a) << "m²" << std::endl;
		else
			std::cout << centimeter2(a) << "cm²" << std::endl;
	}

	void print(volume v)
	{
		if (abs(v) >= kilometer3(1.0))
			std::cout << kilometer3(v) << "km³" << std::endl;
		else if (abs(v) >= meter3(1.0))
			std::cout << meter3(v) << "m³" << std::endl;
		else if (abs(v) >= centimeter3(1.0))
			std::cout << centimeter3(v) << "cm³" << std::endl;
		else
			std::cout << millimeter3(v) << "mm³" << std::endl;
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

	// Various:
	void print(quantity number)
	{
		std::cout << number << std::endl;
	}

	void print(const std::string& text)
	{
		std::cout << text;
	}
}
