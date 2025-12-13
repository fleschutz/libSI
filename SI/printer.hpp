#pragma once

#include <iostream>

namespace si
{
	void H1(const char* text)
	{
		std::cout << "" << std::endl;
		std::cout << text << std::endl;
		std::cout << "===================" << std::endl;
		std::cout << "" << std::endl;
	}

	void H2(const char* text)
	{
		std::cout << "" << std::endl;
		std::cout << text << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "" << std::endl;
	}

	void P(const char* text)
	{
		std::cout << text << std::endl;
		std::cout << "" << std::endl;
	}

#define FORMULA(_cmds) \
	P(#_cmds); \
	_cmds

	void print(si::time t, const char* description)
	{
		if (t >= si::hour(1))
			std::cout << "-> " << hour(t) << "h " << description << std::endl;
		else if (t >= si::minute(1))
			std::cout << "-> " << minute(t) << " min " << description << std::endl;
		else
			std::cout << "-> " << second(t) << " sec " << description << std::endl;
	}

	void print(si::length d, const char* description)
	{
		if (d >= si::kilometer(1))
			std::cout << "-> " << kilometer(d) << " km " << description << std::endl;
		else if (d >= si::meter(1))
			std::cout << "-> " << meter(d) << "m " << description << std::endl;
		else
			std::cout << "-> " << centimeter(d) << " cm " << description << std::endl;
	}

	void print(si::speed v, const char* description)
	{
		std::cout << "-> " << kilometers_per_hour(v) << " km/h " << description << std::endl;
	}

	void print(si::acceleration a, const char* description)
	{
	}

	void print(si::mass m, const char* description)
	{
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

	void print(si::byte number, const char* description)
	{
		std::cout << "-> ";
		while (number > 0)
		{
			auto rest = number % 10;
			auto one_digit = (int)rest;
			std::cout << one_digit;
			number /= 10;
		}
		std::cout << " bytes " << description << std::endl;
	}
}
