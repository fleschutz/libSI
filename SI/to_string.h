// <SI/to_string.h> - convert a SI datatype into a string, e.g. std::string str = to_string(12_m); 
#pragma once

#include <string>
#include "literals.h"

namespace SI
{
	std::string format_of_to_string = "%.2Lf%s"; // <-- configurable (precision / whitespace)

	// internal function to join and convert both value and unit into a string.
	std::string _join(long double value, const std::string& unit)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), format_of_to_string.c_str(), value, unit.c_str());
		return std::string(buf);
	}

	// convert the 7 SI base units:
	std::string to_string(length d)
	{
		if (d <= -1_Gpc || d >= 1_Gpc)
			return _join(d / 1_Gpc, "Gpc (gigaparsec)");
		if (d <= -1_Mpc || d >= 1_Mpc)
			return _join(d / 1_Mpc, "Mpc (megaparsec)");
		if (d <= -1_kpc || d >= 1_kpc)
			return _join(d / 1_kpc, "kpc (kiloparsec)");
		if (d <= -1_pc || d >= 1_pc)
			return _join(d / 1_pc, "pc (parsec)");
		if (d <= -1_ly || d >= 1_ly)
			return _join(d / 1_ly, "ly (light-years)");
		if (d <= -1_au || d >= 1_au)
			return _join(d / 1_au, "au (astronomical unit)");
		if (d <= -1_km || d >= 1_km)
			return _join(d / 1_km, "km");
		if (d <= -1_m || d >= 1_m || d == 0.0_m)
			return _join(d / 1_m, "m");
		if (d <= -1_cm || d >= 1_cm)
			return _join(d / 1_cm, "cm");
		if (d <= -1_mm || d >= 1_mm)
			return _join(d / 1_mm, "mm");
		if (d <= -1_um || d >= 1_um)
			return _join(d / 1_um, "μm");
		if (d <= -1_nm || d >= 1_nm)
			return _join(d / 1_nm, "nm");

		return _join(d / 1_pm, "pm");
	}

	std::string to_string(time t)
	{
		if (abs(t) >= 365.25_days)
			return _join(t / 365.25_days, " year(s)");
		if (abs(t) >= 7_days)
			return _join(t / 7_days, " week(s)");
		if (abs(t) > 1_day)
			return _join(t / 1_day, "days");
		if (t <= -1_h || t >= 1_h)
			return _join(t / 1_h, "h");
		if (t <= -1_min || t >= 1_min)
			return _join(t / 1_min, "min");
		if (t <= -1_s || t >= 1_s || t == 0.0_s)
			return _join(t / 1_s, "s");
		if (t <= -1_ms || t >= 1_ms)
			return _join(t / 1_ms, "ms");
		if (t <= -1_us || t >= 1_us)
			return _join(t / 1_us, "μs");
		if (t <= -1_ns || t >= 1_ns)
			return _join(t / 1_ns, "ns");

		return _join(t / 1_ps, "ps");
	}

	std::string to_string(mass m)
	{
		if (m <= -1_Gt || m >= 1_Gt)
			return _join(m / 1_Gt, "Gt");
		if (m <= -1_Mt || m >= 1_Mt)
			return _join(m / 1_Mt, "Mt");
		if (m <= -1_kt || m >= 1_kt)
			return _join(m / 1_kt, "kt");
		if (m <= -1_t || m >= 1_t)
			return _join(m / 1_t, "t");
		if (m <= -1_kg || m >= 1_kg || m == 0.0_kg)
			return _join(m / 1_kg, "kg");
		if (m <= -1_g || m >= 1_g)
			return _join(m / 1_g, "g");
		if (m <= -1_mg || m >= 1_mg)
			return _join(m / 1_mg, "mg");
		if (m <= -1_ug || m >= 1_ug)
			return _join(m / 1_ug, "µg");

		return _join(m / 1_ng, "ng");
	}

	std::string to_string(temperature T)
	{
		if (T <= -1_GK || T >= 1_GK)
			return _join(T / 1_GK, "GK");
		if (T <= -1_MK || T >= 1_MK)
			return _join(T / 1_MK, "MK");
		if (T >= 250_K && T <= 470_K) // human temperature range
			return _join(celsius(T), "°C (") + _join(fahrenheit(T), "°F") + ")";
		if (T <= -1_K || T >= 1_K || T == 0.0_K)
			return _join(T / 1_K, "K");
		if (T <= -1_mK || T >= 1_mK)
			return _join(T / 1_mK, "mK");
		if (T <= -1_uK || T >= 1_uK)
			return _join(T / 1_uK, "μK");

		return _join(T / 1_nK, "nK");
	}

	std::string to_string(electric_current I)
	{
		if (I <= -1_GA || I >= 1_GA)
			return _join(I / 1_GA, "GA");
		if (I <= -1_MA || I >= 1_MA)
			return _join(I / 1_MA, "MA");
		if (I <= -1_kA || I >= 1_kA)
			return _join(I / 1_kA, "kA");
		if (I <= -1_A || I >= 1_A || I == 0.0_A)
			return _join(I / 1_A, "A");
		if (I <= -1_mA || I >= 1_mA)
			return _join(I / 1_mA, "mA");
		if (I <= -1_uA || I >= 1_uA)
			return _join(I / 1_uA, "μA");
		if (I <= -1_nA || I >= 1_nA)
			return _join(I / 1_nA, "nA");

		return _join(I / 1_pA, "pA");
	}

	// Convert the 22 derived SI units:
	std::string to_string(area a)
	{
		if (a <= -1_km² || a >= 1_km²)
			return _join(a / 1_km², "km²");
		if (a <= -1_hm² || a >= 1_hm²)
			return _join(a / 1_hm², "hm²");
		if (a <= -1_m² || a >= 1_m² || a == 0.0_m²)
			return _join(a / 1_m², "m²");
		if (a <= -1_cm² || a >= 1_cm²)
			return _join(a / 1_cm², "cm²");
		if (a <= -1_mm² || a >= 1_mm²)
			return _join(a / 1_mm², "mm²");

		return _join(a / 1_um², "μm²");
	}

	std::string to_string(per_area a)
	{
		if (a <= -1_per_km² || a >= 1_per_km²)
			return _join(a / 1_per_km², "/km²");
		if (a <= -1_per_hm² || a >= 1_per_hm²)
			return _join(a / 1_per_hm², "/hm²");
		if (a <= -1_per_m² || a >= 1_per_m² || a == 0.0_per_m²)
			return _join(a / 1_per_m², "/m²");
		if (a <= -1_per_cm² || a >= 1_per_cm²)
			return _join(a / 1_per_cm², "/cm²");
		if (a <= -1_per_mm² || a >= 1_per_mm²)
			return _join(a / 1_per_mm², "/mm²");

		return _join(a / 1_per_μm², "/μm²");
	}

	std::string to_string(volume v)
	{
		if (v <= -1_km³ || v >= 1_km³)
			return _join(v / 1_km³, "km³");
		if (v <= -1_m³ || v >= 1_m³)
			return _join(v / 1_m³, "m³");
		if (v <= -1_l || v >= 1_l || v == 0.0_l)
			return _join(v / 1_l, "l");
		if (v <= -1_ml || v >= 1_ml)
			return _join(v / 1_ml, "ml");
		if (v <= -1_ul || v >= 1_ul)
			return _join(v / 1_ul, "μl");
		if (v <= -1_nl || v >= 1_nl)
			return _join(v / 1_nl, "nl");

		return _join(v / 1_pl, "pl");
	}

	std::string to_string(velocity v)
	{
		if (v <= -1_km_per_h || v >= 1_km_per_h)
			return _join(v / 1_km_per_h, "km/h");
		if (v <= -1_m_per_s || v >= 1_m_per_s || v == 0.0_m_per_s)
			return _join(v / 1_m_per_s, "m/s");

		return _join(v / 1_mm_per_h, "mm/h");
	}

	std::string to_string(acceleration a)
	{
		if (a <= -1_km_per_s² || a >= 1_km_per_s²)
			return _join(a / 1_km_per_s², "km/s");

		return _join(a / 1_m_per_s², "m/s²");
	}

	std::string to_string(frequency f)
	{
		if (f <= -1_THz || f >= 1_THz)
			return _join(f / 1_THz, "THz");
		if (f <= -1_GHz || f >= 1_GHz)
			return _join(f / 1_GHz, "GHz");
		if (f <= -1_MHz || f >= 1_MHz)
			return _join(f / 1_MHz, "MHz");
		if (f <= -1_kHz || f >= 1_kHz)
			return _join(f / 1_kHz, "kHz");
		if (f <= -1_Hz || f >= 1_Hz || f == 0.0_Hz)
			return _join(f / 1_Hz, "Hz");

		return _join(f / 1_mHz, "mHz");
	}

	std::string to_string(force F)
	{
		if (F <= -1_GN || F >= 1_GN)
			return _join(F / 1_GN, "GN");
		if (F <= -1_MN || F >= 1_MN)
			return _join(F / 1_MN, "MN");
		if (F <= -1_kN || F >= 1_kN)
			return _join(F / 1_kN, "kN");
		if (F <= -1_N || F >= 1_N || F == 0.0_N)
			return _join(F / 1_N, "N");
		if (F <= -1_mN || F >= 1_mN)
			return _join(F / 1_mN, "mN");
		if (F <= -1_uN || F >= 1_uN)
			return _join(F / 1_uN, "µN");

		return _join(F / 1_pN, "pN");
	}

	std::string to_string(energy E)
	{
		if (E <= -1_PJ || E >= 1_PJ)
			return _join(E / 1_PJ, "PJ");
		if (E <= -1_TJ || E >= 1_TJ)
			return _join(E / 1_TJ, "TJ");
		if (E <= -1_GJ || E >= 1_GJ)
			return _join(E / 1_GJ, "GJ");
		if (E <= -1_MJ || E >= 1_MJ)
			return _join(E / 1_MJ, "MJ");
		if (E <= -1_kJ || E >= 1_kJ)
			return _join(E / 1_kJ, "kJ");
		if (E <= -1_J || E >= 1_J || E == 0.0_J)
			return _join(E / 1_J, "J");

		return _join(E / 1_mJ, "mJ");
	}

	std::string to_string(power P)
	{
		if (P <= -1_TWh || P >= 1_TWh)
			return _join(P / 1_TWh, "TWh");
		if (P <= -1_GWh || P >= 1_GWh)
			return _join(P / 1_GWh, "GWh");
		if (P <= -1_MWh || P >= 1_MWh)
			return _join(P / 1_MWh, "MWh");
		if (P <= -1_kWh || P >= 1_kWh)
			return _join(P / 1_kWh, "kWh");

		return _join(P / 1_Wh, "Wh");
	}

	std::string to_string(power_intensity I)
	{
		if (I <= -1_MW_per_m² || I >= 1_MW_per_m²)
			return _join(I / 1_MW_per_m², "MW/m²");
		if (I <= -1_kW_per_m² || I >= 1_kW_per_m²)
			return _join(I / 1_kW_per_m², "kW/m²");
		if (I <= -1_W_per_m² || I >= 1_W_per_m²)
			return _join(I / 1_W_per_m², "W/m²");

		return _join(I / 1_mW_per_m², "mW/m²");
	}

	std::string to_string(pressure p)
	{
		if (p <= -1_MPa || p >= 1_MPa)
			return _join(p / 1_MPa, "MPa");
		if (p <= -1_kPa || p >= 1_kPa)
			return _join(p / 1_kPa, "kPa");
		if (p <= -1_hPa || p >= 1_hPa)
			return _join(p / 1_hPa, "hPa");
		if (p <= -1_Pa || p >= 1_Pa || p == 0.0_Pa)
			return _join(p / 1_Pa, "Pa");
		if (p <= -1_mPa || p >= 1_mPa)
			return _join(p / 1_mPa, "mPa");

		return _join(p / 1_uPa, "µPa");
	}

	std::string to_string(electric_potential U)
	{
		if (U <= -1_GV || U >= 1_GV)
			return _join(U / 1_GV, "GV");
		if (U <= -1_MV || U >= 1_MV)
			return _join(U / 1_MV, "MV");
		if (U <= -1_kV || U >= 1_kV)
			return _join(U / 1_kV, "kV");
		if (U <= -1_V || U >= 1_V || U == 0.0_V)
			return _join(U / 1_V, "V");
		if (U <= -1_mV || U >= 1_mV)
			return _join(U / 1_mV, "mV");
		if (U <= -1_uV || U >= 1_uV)
			return _join(U / 1_uV, "μV");
		if (U <= -1_nV || U >= 1_nV)
			return _join(U / 1_nV, "nV");
		return _join(U / 1_pV, "pV");
	}

	std::string to_string(electric_charge Q)
	{
		if (Q <= -1_GAh || Q >= 1_GAh)
			return _join(Q / 1_MAh, "MAh");
		if (Q <= -1_MAh || Q >= 1_MAh)
			return _join(Q / 1_MAh, "MAh");
		if (Q <= -1_kAh || Q >= 1_kAh)
			return _join(Q / 1_kAh, "kAh");
		if (Q <= -1_Ah || Q >= 1_Ah || Q == 0.0_Ah)
			return _join(Q / 1_Ah, "Ah");
		if (Q <= -1_mAh || Q >= 1_mAh)
			return _join(Q / 1_mAh, "mAh");

		return _join(Q / 1_uAh, "µAh");
	}

	std::string to_string(mass_per_area v)
	{
		return _join(v / 1_kg_per_m², "kg/m²");
	}

	std::string to_string(density d)
	{
		return _join(d / 1_kg_per_m³, "kg/m³");
	}

	std::string to_string(angle a)
	{
		return _join(a / 1_deg, "°");
	}

	std::string to_string(dimensionless value)
	{
		return _join(value, "");
	}

	std::string to_string(char glyph)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), "%c", glyph);
		return std::string(buf);
	}

	std::string to_string(const std::string& text)
	{
		return text;
	}
}
