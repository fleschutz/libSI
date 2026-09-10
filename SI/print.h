/// @file	SI/print.h
/// @brief	Contains simple print to console functions for SI datatypes and strings (similar to C++23).

#pragma once
#include <iostream>
#include <SI/conversions.h>

namespace SI
{
	/// @brief Prints a single value (without newline).
	template <typename T>
	void print(T value)
	{
		std::cout << to_string(value);
	}

	/// @brief Prints a single value and a newline.
	template <typename T>
	void println(T value)
	{
		std::cout << to_string(value) << std::endl;
	}

	/// @brief Print two values (without newline).
	template <typename T1, typename T2>
	void print(T1 v1, T2 v2)
	{
		std::cout << to_string(v1) << to_string(v2);
	}

	/// @brief Prints two values and a newline.
	template <typename T1, typename T2>
	void println(T1 v1, T2 v2)
	{
		std::cout << to_string(v1) << to_string(v2) << std::endl;
	}

	/// @brief Prints three values (without newline).
	template <typename T1, typename T2, typename T3>
	void print(T1 v1, T2 v2, T3 v3)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3);
	}

	/// @brief Prints three values and a newline.
	template <typename T1, typename T2, typename T3>
	void println(T1 v1, T2 v2, T3 v3)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << std::endl;
	}

	/// @brief Prints four values (without newline).
	template <typename T1, typename T2, typename T3, typename T4>
	void print(T1 v1, T2 v2, T3 v3, T4 v4)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4);
	}

	/// @brief Prints four values and a newline.
	template <typename T1, typename T2, typename T3, typename T4>
	void println(T1 v1, T2 v2, T3 v3, T4 v4)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4) << std::endl;
	}

	/// @brief Prints five values (without newline).
	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	void print(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4) << to_string(v5);
	}

	/// @brief Prints five values and a newline.
	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	void println(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4) << to_string(v5) << std::endl;
	}

	/// @brief Prints six values (without newline).
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	void print(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4) << to_string(v5) << to_string(v6);
	}

	/// @brief Prints six values and a newline.
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	void println(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4) << to_string(v5) << to_string(v6) << std::endl;
	}

	/// @brief Prints seven values (without a newline).
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	void print(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4) << to_string(v5) << to_string(v6) << to_string(v7);
	}

	/// @brief Prints seven values and a newline
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	void println(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7)
	{
		std::cout << to_string(v1) << to_string(v2) << to_string(v3) << to_string(v4) << to_string(v5) << to_string(v6) << to_string(v7) << std::endl;
	}

	// References
	// ----------
	// 1. https://en.wikipedia.org/wiki/International_System_of_Units

} // namespace SI
