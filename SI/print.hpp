// SI/print.hpp - simple print to console interface
#pragma once

#include <iostream>

namespace si
{
	// SI BASE UNITS:
	void print(si::time t)
	{
		if (t >= year(1))
			std::cout << year(t) << " year(s)" << std::endl;
		else if (t >= week(1))
			std::cout << week(t) << " week(s)" << std::endl;
		else if (t >= day(1))
			std::cout << day(t) << " day(s)" << std::endl;
		else if (t >= hour(1))
			std::cout << hour(t) << " h" << std::endl;
		else if (t >= minute(1))
			std::cout << minute(t) << " min" << std::endl;
		else
			std::cout << second(t) << " sec" << std::endl;
	}

	void print(si::length d)
	{
		if (d >= constant::lightyear * 1000000)
			std::cout << (d / (constant::lightyear * 1000000)) << " megalight-year(s)" << std::endl;
		else if (d >= constant::lightyear * 1000)
			std::cout << (d / (constant::lightyear * 1000)) << " kilolight-year(s)" << std::endl;
		else if (d >= constant::lightyear)
			std::cout << (d / constant::lightyear) << " light-year(s)" << std::endl;
		else if (d >= kilometer(1))
			std::cout << kilometer(d) << " km" << std::endl;
		else if (d >= meter(1))
			std::cout << meter(d) << "m" << std::endl;
		else
			std::cout << centimeter(d) << " cm" << std::endl;
	}

	void print(si::mass m)
	{
		if (m >= kilogram(1))
			std::cout << kilogram(m) << " kg" << std::endl;
		else
			std::cout << gram(m) << " g" << std::endl;
	}

	void print(si::temperature T)
	{
		if (T >= celsius(0))
			std::cout << celsius(T) << "°C " << std::endl;
		else
			std::cout << kelvin(T) << "°K " << std::endl;
	}

	// SI DERIVED UNITS:
	void print(si::area a)
	{
		if (a >= kilometer2(1))
			std::cout << kilometer2(a) << " km²" << std::endl;
		else if (a >= meter2(1.0))
			std::cout << meter2(a) << " m²" << std::endl;
		else
			std::cout << centimeter2(a) << " cm²" << std::endl;
	}

	void print(si::volume v)
	{
		if (v >= meter3(1.0))
			std::cout << meter3(v) << " m³" << std::endl;
		else
			std::cout << centimeter3(v) << " cm³" << std::endl;
	}

	void print(si::speed v)
	{
		std::cout << kilometers_per_hour(v) << " km/h" << std::endl;
	}

	void print(si::acceleration a)
	{
		std::cout << meters_per_second2(a) << " m/s²" << std::endl;
	}

	void print(si::energy E)
	{
		if (E >= gigajoule(1))
			std::cout << gigajoule(E) << " GJ " << std::endl;
		else if (E >= megajoule(1))
			std::cout << megajoule(E) << " MJ " << std::endl;
		else if (E >= kilojoule(1))
			std::cout << kilojoule(E) << " kJ " << std::endl;
		else
			std::cout << joule(E) << " Joule " << std::endl;
	}

	void print(si::quantity number)
	{
		std::cout << number << std::endl;
	}

	void print(std::string text)
	{
		std::cout << text;
	}
}
