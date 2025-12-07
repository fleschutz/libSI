#pragma once

#include <iostream>

namespace si
{
	void print(si::length d, const char* description)
	{
		std::cout << meter(d) << "m " << description << std::endl;
	}

	void print(si::time t, const char* description)
	{
		std::cout << second(t) << "s " << description << std::endl;
	}

	void print(si::speed v, const char* description)
	{
		std::cout << miles_per_hour(v) << "MPH " << description << std::endl;
	}

	void print(si::energy E, const char* description)
	{
		std::cout << joule(E) << "Joule " << description << std::endl;
	}
}
