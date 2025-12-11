#pragma once

#include <iostream>

namespace si
{
	void print(si::length d, const char* description)
	{
		if (d >= si::kilometer(1))
			std::cout << "-> " << kilometer(d) << " km " << description << std::endl;
		else if (d >= si::meter(1))
			std::cout << "-> " << meter(d) << "m " << description << std::endl;
		else
			std::cout << "-> " << centimeter(d) << " cm " << description << std::endl;
	}

	void print(si::time t, const char* description)
	{
		if (t >= si::hour(1))
			std::cout << "-> " << hour(t) << "h " << description << std::endl;
		else if (t >= si::minute(1))
			std::cout << "-> " << minute(t) << " min " << description << std::endl;
		else
			std::cout << "-> " << second(t) << " sec " << description << std::endl;
	}

	void print(si::speed v, const char* description)
	{
		std::cout << "-> " << kilometers_per_hour(v) << " km/h " << description << std::endl;
	}

	void print(si::energy E, const char* description)
	{
		if (E >= si::gigajoule(1))
			std::cout << "-> " << megajoule(E) << " GJ " << description << std::endl;
		else if (E >= si::megajoule(1))
			std::cout << "-> " << megajoule(E) << " MJ " << description << std::endl;
		else if (E >= si::kilojoule(1))
			std::cout << "-> " << kilojoule(E) << " kJ " << description << std::endl;
		else
			std::cout << "-> " << joule(E) << " Joule " << description << std::endl;
	}

	void print(si::temperature T, const char* description)
	{
		std::cout << "-> " << celsius(T) << "°C " << description << std::endl;
	}
}
