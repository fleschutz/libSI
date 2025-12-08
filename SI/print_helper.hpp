#pragma once

#include <iostream>

namespace si
{
	void print(si::length d, const char* description)
	{
		if (d >= si::kilometer(1))
			std::cout << kilometer(d) << "km " << description << std::endl;
		else if (d >= si::meter(1))
			std::cout << meter(d) << "m " << description << std::endl;
		else
			std::cout << centimeter(d) << "cm " << description << std::endl;
	}

	void print(si::time t, const char* description)
	{
		std::cout << second(t) << "s " << description << std::endl;
	}

	void print(si::speed v, const char* description)
	{
		std::cout << kilometers_per_hour(v) << "km/h " << description << std::endl;
	}

	void print(si::energy E, const char* description)
	{
		std::cout << joule(E) << "Joule " << description << std::endl;
	}

	void print(si::temperature T, const char* description)
	{
		std::cout << celsius(T) << "°C " << description << std::endl;
	}
}
