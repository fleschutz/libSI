/// @file     SI/conversions.h
/// @brief    Defines conversion functions, e.g. to_string(12_m).
/// @details  Provides from_string(), to_string(), to_equivalent(), and to_percentage().

#pragma once
#include <string>
#include <SI/literals.h>

namespace SI
{
	inline auto to_string_format     = "%.2Lf %s"; ///< configurable, SI standard formatting by default
	inline auto to_equivalent_format = "%.2Lf %s"; ///< configurable, SI standard formatting by default
	inline auto to_percentage_format = "%.0Lf %s"; ///< configurable

	/// @brief The from_string() function
	inline bool from_string(const std::string& str, length& result)
	{
		double value;
		char unit[1024];
		if (std::sscanf(str.c_str(), "%lf%s", &value, unit) != 2)
			return false; // not recognized

		if (unit == "Gm")
			result = 1_Gm * value;
		else if (unit == "Mm")
			result = 1_Mm * value;
		else if (unit == "km")
			result = 1_km * value;
		else if (unit == "m")
			result = 1_m * value;
		else if (unit == "dm")
			result = 1_dm * value;
		else if (unit == "cm")
			result = 1_cm * value;
		else if (unit == "mm")
			result = 1_mm * value;
		else if (unit == "um")
			result = 1_um * value;
		else if (unit == "nm")
			result = 1_nm * value;
		else if (unit == "pm")
			result = 1_pm * value;
		else
			return false; // unknown unit

		return true;
	}

	inline bool from_string(const std::string& str, time& result)
	{
		double value;
		char unit[1024];
		if (std::sscanf(str.c_str(), "%lf%s", &value, unit) != 2)
			return false; // not recognized

		if (unit == "day" || unit == "days")
			result = 1_day * value;
		else if (unit == "h" || unit == "hrs")
			result = 1_h * value;
		else if (unit == "m" || unit == "min")
			result = 1_min * value;
		else if (unit == "s" || unit == "sec" || unit == "seconds")
			result = 1_s * value;
		else if (unit == "ms")
			result = 1_ms * value;
		else if (unit == "us")
			result = 1_us * value;
		else if (unit == "ns")
			result = 1_ns * value;
		else if (unit == "ps")
			result = 1_ps * value;
		else
			return false; // unknown unit

		return true;
	}

	inline bool from_string(const std::string& str, mass& result)
	{
		double value;
		char unit[1024];
		if (std::sscanf(str.c_str(), "%lf%s", &value, unit) != 2)
			return false; // not recognized

		if (unit == "Gt")
			result = 1_Gt * value;
		else if (unit == "Mt")
			result = 1_Mt * value;
		else if (unit == "kt")
			result = 1_kt * value;
		else if (unit == "t")
			result = 1_t * value;
		else if (unit == "kg")
			result = 1_kg * value;
		else if (unit == "g")
			result = 1_g * value;
		else if (unit == "mg")
			result = 1_mg * value;
		else if (unit == "ug")
			result = 1_ug * value;
		else if (unit == "ng")
			result = 1_ng * value;
		else
			return false; // unknown unit

		return true;
	}

	// internal function to join and format both quantity and unit into a string.
	inline std::string _join(long double quantity, const char* unit, const char* formatString)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), formatString, quantity, unit);
		return std::string(buf);
	}

	// convert the 7 SI base units:

	/// @brief Returns the given length as string using SI units.
	inline std::string to_string(const length d)
	{
		if (d <= -1_Gpc || d >= 1_Gpc)
			return _join(d / 1_Gpc, "Gpc", to_string_format); // gigaparsec
		if (d <= -1_Mpc || d >= 1_Mpc)
			return _join(d / 1_Mpc, "Mpc", to_string_format); // megaparsec
		if (d <= -1_kpc || d >= 1_kpc)
			return _join(d / 1_kpc, "kpc", to_string_format); // kiloparsec
		if (d <= -1_pc || d >= 1_pc)
			return _join(d / 1_pc, "pc", to_string_format);   // parsec
		if (d <= -1_ly || d >= 1_ly)
			return _join(d / 1_ly, "ly", to_string_format);   // light-years
		if (d <= -0.1_au || d >= 0.1_au)
			return _join(d / 1_au, "au", to_string_format);   // astronomical unit
		if (d <= -1_km || d >= 1_km)
			return _join(d / 1_km, "km", to_string_format);
		if (d <= -1_m || d >= 1_m || d == 0.0_m)
			return _join(d / 1_m, "m", to_string_format);
		if (d <= -1_cm || d >= 1_cm)
			return _join(d / 1_cm, "cm", to_string_format);
		if (d <= -1_mm || d >= 1_mm)
			return _join(d / 1_mm, "mm", to_string_format);
		if (d <= -1_um || d >= 1_um)
			return _join(d / 1_um, "μm", to_string_format);
		if (d <= -1_nm || d >= 1_nm)
			return _join(d / 1_nm, "nm", to_string_format);
		return _join(d / 1_pm, "pm", to_string_format);
	}

	/// @brief Returns a length equivalent as string, e.g. in Imperial units.
	inline std::string to_equivalent(const length d)
	{
		if (d <= -1_ly || d >= 1_ly)
			return _join(d / 1_ly, "light-years", to_equivalent_format);
		if (d <= -1_ls || d >= 1_ls)
			return _join(d / 1_ls, "light-seconds", to_equivalent_format);
		if (d <= -1_mi || d >= 1_mi)
			return _join(d / 1_mi, "miles", to_equivalent_format);
		if (d <= -1_yd || d >= 1_yd)
			return _join(d / 1_yd, "yards", to_equivalent_format);
		if (d <= -1_ft || d >= 1_ft)
			return _join(d / 1_ft, "feet", to_equivalent_format);
		return _join(d / 1_in, "inch", to_equivalent_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const length d)
	{
		os << to_string(d);
		return os;
	}

	/// @brief Returns the given time as string using SI units.
	inline std::string to_string(const time t)
	{
		if (abs(t) > 365.25_days)
			return _join(t / 365.25_days, "y", to_string_format);
		if (abs(t) > 10_days)
			return _join(t / 7_days, "w", to_string_format);
		if (abs(t) > 2_day)
			return _join(t / 1_day, "d", to_string_format);
		if (t <= -1_h || t >= 1_h)
			return _join(t / 1_h, "h", to_string_format);
		if (t <= -1_min || t >= 1_min)
			return _join(t / 1_min, "min", to_string_format);
		if (t <= -1_s || t >= 1_s || t == 0.0_s)
			return _join(t / 1_s, "s", to_string_format);
		if (t <= -1_ms || t >= 1_ms)
			return _join(t / 1_ms, "ms", to_string_format);
		if (t <= -1_us || t >= 1_us)
			return _join(t / 1_us, "μs", to_string_format);
		if (t <= -1_ns || t >= 1_ns)
			return _join(t / 1_ns, "ns", to_string_format);
		return _join(t / 1_ps, "ps", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const time t)
	{
		os << to_string(t);
		return os;
	}

	/// @brief Returns the given mass as string using SI units.
	inline std::string to_string(const mass m)
	{
		if (m <= -1_Pt || m >= 1_Pt)
			return _join(m / 1_Pt, "Pt", to_string_format);
		if (m <= -1_Tt || m >= 1_Tt)
			return _join(m / 1_Tt, "Tt", to_string_format);
		if (m <= -1_Gt || m >= 1_Gt)
			return _join(m / 1_Gt, "Gt", to_string_format);
		if (m <= -1_Mt || m >= 1_Mt)
			return _join(m / 1_Mt, "Mt", to_string_format);
		if (m <= -1_kt || m >= 1_kt)
			return _join(m / 1_kt, "kt", to_string_format);
		if (m <= -1_t || m >= 1_t)
			return _join(m / 1_t, "t", to_string_format);
		if (m <= -1_kg || m >= 1_kg || m == 0.0_kg)
			return _join(m / 1_kg, "kg", to_string_format);
		if (m <= -1_g || m >= 1_g)
			return _join(m / 1_g, "g", to_string_format);
		if (m <= -1_mg || m >= 1_mg)
			return _join(m / 1_mg, "mg", to_string_format);
		if (m <= -1_ug || m >= 1_ug)
			return _join(m / 1_ug, "µg", to_string_format);
		return _join(m / 1_ng, "ng", to_string_format);
	}

	/// @brief Returns a mass equivalent as string, e.g. in Imperial units.
	inline std::string to_equivalent(const mass m)
	{
		if (m <= -1_Msun || m >= 1_Msun)
			return _join(m / 1_Msun, "solar masses", to_equivalent_format);
		if (m <= -1_Mjup || m >= 1_Mjup)
			return _join(m / 1_Mjup, "Jupiter masses", to_equivalent_format);
		if (m <= -1_Mearth || m >= 1_Mearth)
			return _join(m / 1_Mearth, "Earth masses", to_equivalent_format);
		if (m <= -1_Mmoon || m >= 1_Mmoon)
			return _join(m / 1_Mmoon, "Moon masses", to_equivalent_format);
		if (m <= -1_lb || m >= 1_lb)
			return _join(m / 1_lb, "lb", to_equivalent_format);
		return _join(m / 1_oz, "oz", to_equivalent_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const mass m)
	{
		os << to_string(m);
		return os;
	}

	/// @brief Returns the given temperature as string using SI units.
	inline std::string to_string(const temperature T)
	{
		if (T >= 1_GK)
			return _join(T / 1_GK, "GK", to_string_format);
		if (T >= 1_MK)
			return _join(T / 1_MK, "MK", to_string_format);
		if (T >= -150_degC && T <= 150_degC) // human temperature range
			return _join(celsius(T), "°C", to_string_format);
		if (T <= -1_K || T >= 1_K || T == 0.0_K)
			return _join(T / 1_K, "K", to_string_format);
		if (T <= -1_mK || T >= 1_mK)
			return _join(T / 1_mK, "mK", to_string_format);
		if (T <= -1_uK || T >= 1_uK)
			return _join(T / 1_uK, "μK", to_string_format);
		return _join(T / 1_nK, "nK", to_string_format);
	}

	/// @brief Returns a temperature equivalent as string, e.g. in Fahrenheit.
	inline std::string to_equivalent(const temperature T)
	{
		return _join(fahrenheit(T), "°F", to_equivalent_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const temperature T)
	{
		os << to_string(T);
		return os;
	}

	/// @brief Returns the electric current (I) as string using SI units.
	inline std::string to_string(const electric_current I)
	{
		if (I <= -1_GA || I >= 1_GA)
			return _join(I / 1_GA, "GA", to_string_format);
		if (I <= -1_MA || I >= 1_MA)
			return _join(I / 1_MA, "MA", to_string_format);
		if (I <= -1_kA || I >= 1_kA)
			return _join(I / 1_kA, "kA", to_string_format);
		if (I <= -1_A || I >= 1_A || I == 0.0_A)
			return _join(I / 1_A, "A", to_string_format);
		if (I <= -1_mA || I >= 1_mA)
			return _join(I / 1_mA, "mA", to_string_format);
		if (I <= -1_uA || I >= 1_uA)
			return _join(I / 1_uA, "μA", to_string_format);
		if (I <= -1_nA || I >= 1_nA)
			return _join(I / 1_nA, "nA", to_string_format);
		return _join(I / 1_pA, "pA", to_string_format);
	}

	// Convert the 22 derived SI units:

	/// @brief Returns the given area as string using SI units.
	inline std::string to_string(const area a)
	{
		if (a <= -1_km² || a >= 1_km²)
			return _join(a / 1_km², "km²", to_string_format);
		if (a <= -1_hm² || a >= 1_hm²)
			return _join(a / 1_hm², "hm²", to_string_format);
		if (a <= -1_m² || a >= 1_m² || a == 0.0_m²)
			return _join(a / 1_m², "m²", to_string_format);
		if (a <= -1_cm² || a >= 1_cm²)
			return _join(a / 1_cm², "cm²", to_string_format);
		if (a <= -1_mm² || a >= 1_mm²)
			return _join(a / 1_mm², "mm²", to_string_format);
		return _join(a / 1_um², "μm²", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const area a)
	{
		os << to_string(a);
		return os;
	}

	/// @brief Returns the per area as string using SI units.
	inline std::string to_string(const per_area a)
	{
		if (a <= -1_per_km² || a >= 1_per_km²)
			return _join(a / 1_per_km², "/km²", to_string_format);
		if (a <= -1_per_hm² || a >= 1_per_hm²)
			return _join(a / 1_per_hm², "/hm²", to_string_format);
		if (a <= -1_per_m² || a >= 1_per_m² || a == 0.0_per_m²)
			return _join(a / 1_per_m², "/m²", to_string_format);
		if (a <= -1_per_cm² || a >= 1_per_cm²)
			return _join(a / 1_per_cm², "/cm²", to_string_format);
		if (a <= -1_per_mm² || a >= 1_per_mm²)
			return _join(a / 1_per_mm², "/mm²", to_string_format);
		return _join(a / 1_per_μm², "/μm²", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const per_area a)
	{
		os << to_string(a);
		return os;
	}

	/// @brief Returns the given volume as string using SI units.
	inline std::string to_string(const volume v)
	{
		if (v <= -1_km³ || v >= 1_km³)
			return _join(v / 1_km³, "km³", to_string_format);
		if (v <= -1_m³ || v >= 1_m³)
			return _join(v / 1_m³, "m³", to_string_format);
		if (v <= -1_l || v >= 1_l || v == 0.0_l)
			return _join(v / 1_l, "l", to_string_format);
		if (v <= -1_ml || v >= 1_ml)
			return _join(v / 1_ml, "ml", to_string_format);
		if (v <= -1_ul || v >= 1_ul)
			return _join(v / 1_ul, "μl", to_string_format);
		if (v <= -1_nl || v >= 1_nl)
			return _join(v / 1_nl, "nl", to_string_format);
		return _join(v / 1_pl, "pl", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const volume v)
	{
		os << to_string(v);
		return os;
	}

	/// @brief Returns velocity as string using SI units.
	inline std::string to_string(const velocity v)
	{
		if (v <= -1_km_per_s || v >= 1_km_per_s)
			return _join(v / 1_km_per_s, "km/s", to_string_format);
		if (v <= -1_km_per_h || v >= 1_km_per_h)
			return _join(v / 1_km_per_h, "km/h", to_string_format);
		if (v <= -1_m_per_s || v >= 1_m_per_s || v == 0.0_m_per_s)
			return _join(v / 1_m_per_s, "m/s", to_string_format);
		return _join(v / 1_mm_per_h, "mm/h", to_string_format);
	}

	/// @brief Returns a velocity equivalent as string, e.g. in Imperial units.
	inline std::string to_equivalent(const velocity V)
	{
		if (V <= -1_Mach || V >= 1_Mach)
			return _join(V / 1_Mach, "Mach", to_equivalent_format);
		return _join(V / 1_mph, "mph", to_equivalent_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const velocity v)
	{
		os << to_string(v);
		return os;
	}

	/// @brief Returns the acceleration as string using SI units.
	inline std::string to_string(const acceleration a)
	{
		if (a <= -1_km_per_s² || a >= 1_km_per_s²)
			return _join(a / 1_km_per_s², "km/s", to_string_format);
		return _join(a / 1_m_per_s², "m/s²", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const acceleration a)
	{
		os << to_string(a);
		return os;
	}

	/// @brief Returns the frequency as string using SI units.
	inline std::string to_string(const frequency f)
	{
		if (f <= -1_THz || f >= 1_THz)
			return _join(f / 1_THz, "THz", to_string_format);
		if (f <= -1_GHz || f >= 1_GHz)
			return _join(f / 1_GHz, "GHz", to_string_format);
		if (f <= -1_MHz || f >= 1_MHz)
			return _join(f / 1_MHz, "MHz", to_string_format);
		if (f <= -1_kHz || f >= 1_kHz)
			return _join(f / 1_kHz, "kHz", to_string_format);
		if (f <= -1_Hz || f >= 1_Hz || f == 0.0_Hz)
			return _join(f / 1_Hz, "Hz", to_string_format);
		return _join(f / 1_mHz, "mHz", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const frequency f)
	{
		os << to_string(f);
		return os;
	}

	/// @brief Returns the force as string using SI units.
	inline std::string to_string(const force F)
	{
		if (F <= -1_ZN || F >= 1_ZN)
			return _join(F / 1_ZN, "ZN", to_string_format);
		if (F <= -1_EN || F >= 1_EN)
			return _join(F / 1_EN, "EN", to_string_format);
		if (F <= -1_PN || F >= 1_PN)
			return _join(F / 1_PN, "PN", to_string_format);
		if (F <= -1_TN || F >= 1_TN)
			return _join(F / 1_TN, "TN", to_string_format);
		if (F <= -1_GN || F >= 1_GN)
			return _join(F / 1_GN, "GN", to_string_format);
		if (F <= -1_MN || F >= 1_MN)
			return _join(F / 1_MN, "MN", to_string_format);
		if (F <= -1_kN || F >= 1_kN)
			return _join(F / 1_kN, "kN", to_string_format);
		if (F <= -1_N || F >= 1_N || F == 0.0_N)
			return _join(F / 1_N, "N", to_string_format);
		if (F <= -1_mN || F >= 1_mN)
			return _join(F / 1_mN, "mN", to_string_format);
		if (F <= -1_uN || F >= 1_uN)
			return _join(F / 1_uN, "µN", to_string_format);
		return _join(F / 1_pN, "pN", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const force F)
	{
		os << to_string(F);
		return os;
	}

	/// @brief Returns the energy as string using SI units.
	inline std::string to_string(const energy E)
	{
		if (E <= -1_PJ || E >= 1_PJ)
			return _join(E / 1_PJ, "PJ", to_string_format);
		if (E <= -1_TJ || E >= 1_TJ)
			return _join(E / 1_TJ, "TJ", to_string_format);
		if (E <= -1_GJ || E >= 1_GJ)
			return _join(E / 1_GJ, "GJ", to_string_format);
		if (E <= -1_MJ || E >= 1_MJ)
			return _join(E / 1_MJ, "MJ", to_string_format);
		if (E <= -1_kJ || E >= 1_kJ)
			return _join(E / 1_kJ, "kJ", to_string_format);
		if (E <= -1_J || E >= 1_J || E == 0.0_J)
			return _join(E / 1_J, "J", to_string_format);
		return _join(E / 1_mJ, "mJ", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const energy E)
	{
		os << to_string(E);
		return os;
	}

	/// @brief Returns the power as string using SI units.
	inline std::string to_string(const power P)
	{
		if (P <= -1_TW || P >= 1_TW)
			return _join(P / 1_TW, "TW", to_string_format);
		if (P <= -1_GW || P >= 1_GW)
			return _join(P / 1_GW, "GW", to_string_format);
		if (P <= -1_MW || P >= 1_MW)
			return _join(P / 1_MW, "MW", to_string_format);
		if (P <= -1_kW || P >= 1_kW)
			return _join(P / 1_kW, "kW", to_string_format);
		return _join(P / 1_W, "W", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const power P)
	{
		os << to_string(P);
		return os;
	}

	/// @brief Returns the power intensity as string using SI units.
	inline std::string to_string(const power_intensity I)
	{
		if (I <= -1_MW_per_m² || I >= 1_MW_per_m²)
			return _join(I / 1_MW_per_m², "MW/m²", to_string_format);
		if (I <= -1_kW_per_m² || I >= 1_kW_per_m²)
			return _join(I / 1_kW_per_m², "kW/m²", to_string_format);
		if (I <= -1_W_per_m² || I >= 1_W_per_m²)
			return _join(I / 1_W_per_m², "W/m²", to_string_format);
		return _join(I / 1_mW_per_m², "mW/m²", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const power_intensity I)
	{
		os << to_string(I);
		return os;
	}

	/// @brief Returns the pressure as string using SI units.
	inline std::string to_string(const pressure p)
	{
		if (p <= -1_MPa || p >= 1_MPa)
			return _join(p / 1_MPa, "MPa", to_string_format);
		if (p <= -1_kPa || p >= 1_kPa)
			return _join(p / 1_kPa, "kPa", to_string_format);
		if (p <= -1_hPa || p >= 1_hPa)
			return _join(p / 1_hPa, "hPa", to_string_format);
		if (p <= -1_Pa || p >= 1_Pa || p == 0.0_Pa)
			return _join(p / 1_Pa, "Pa", to_string_format);
		if (p <= -1_mPa || p >= 1_mPa)
			return _join(p / 1_mPa, "mPa", to_string_format);
		return _join(p / 1_uPa, "µPa", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const pressure p)
	{
		os << to_string(p);
		return os;
	}

	/// @brief Returns the electric potential as string using SI units.
	inline std::string to_string(const electric_potential U)
	{
		if (U <= -1_GV || U >= 1_GV)
			return _join(U / 1_GV, "GV", to_string_format);
		if (U <= -1_MV || U >= 1_MV)
			return _join(U / 1_MV, "MV", to_string_format);
		if (U <= -1_kV || U >= 1_kV)
			return _join(U / 1_kV, "kV", to_string_format);
		if (U <= -1_V || U >= 1_V || U == 0.0_V)
			return _join(U / 1_V, "V", to_string_format);
		if (U <= -1_mV || U >= 1_mV)
			return _join(U / 1_mV, "mV", to_string_format);
		if (U <= -1_uV || U >= 1_uV)
			return _join(U / 1_uV, "μV", to_string_format);
		if (U <= -1_nV || U >= 1_nV)
			return _join(U / 1_nV, "nV", to_string_format);
		return _join(U / 1_pV, "pV", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const electric_potential U)
	{
		os << to_string(U);
		return os;
	}

	/// @brief Returns the electric charge as string using SI units.
	inline std::string to_string(const electric_charge Q)
	{
		if (Q <= -1_GAh || Q >= 1_GAh)
			return _join(Q / 1_MAh, "MAh", to_string_format);
		if (Q <= -1_MAh || Q >= 1_MAh)
			return _join(Q / 1_MAh, "MAh", to_string_format);
		if (Q <= -1_kAh || Q >= 1_kAh)
			return _join(Q / 1_kAh, "kAh", to_string_format);
		if (Q <= -1_Ah || Q >= 1_Ah || Q == 0.0_Ah)
			return _join(Q / 1_Ah, "Ah", to_string_format);
		if (Q <= -1_mAh || Q >= 1_mAh)
			return _join(Q / 1_mAh, "mAh", to_string_format);
		return _join(Q / 1_uAh, "µAh", to_string_format);
	}

	inline std::string to_string(const mass_per_area m)
	{
		if (m <= -1_t_per_m² || m >= 1_t_per_m²)
			return _join(m / 1_t_per_m², "t/m²", to_string_format);
		return _join(m / 1_kg_per_m², "kg/m²", to_string_format);
	}

	/// @brief Returns the mass per power as string using SI units.
	inline std::string to_string(const mass_per_power m)
	{
		if (m <= -1_kg_per_kW || m >= 1_kg_per_kW)
			return _join(m / 1_kg_per_kW, "kg/kW", to_string_format);
		return _join(m / 1_kg_per_W, "kg/W", to_string_format);
	}

	inline std::ostream& operator<<(std::ostream& os, const mass_per_power m)
	{
		os << to_string(m);
		return os;
	}

	/// @brief Returns density as string using SI units.
	inline std::string to_string(const density d)
	{
		if (d <= -1_t_per_m³ || d >= 1_t_per_m³)
			return _join(d / 1_t_per_m³, "t/m³", to_string_format);
		return _join(d / 1_kg_per_m³, "kg/m³", to_string_format);
	}

	/// @brief Returns the angle as string in degree.
	inline std::string to_string(const angle a)
	{
		return _join(a / 1_deg, "°", to_string_format);
	}

	inline std::string to_string(const dimensionless value)
	{
		return _join(value, "", to_string_format);
	}

	inline std::string to_string(const unsigned char byte)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), "%u", byte);
		return std::string(buf);
	}

	inline std::string to_string(const char glyph)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), "%c", glyph);
		return std::string(buf);
	}

	inline std::string to_string(const std::string& text)
	{
		return text;
	}

	/// @brief Returns a power intensity equivalent as string, e.g. in dB.
	inline std::string to_equivalent(const power_intensity I)
	{
		return _join(10.0 * std::log10((I / 1_W_per_m²) / 1e-12), "dB", to_equivalent_format);
	}

	/// @brief Returns an energy equivalent as string, e.g. kg TNT.
	inline std::string to_equivalent(const energy E)
	{
		const auto Hiroshima_bomb = 62_TJ; // (explosion energy of the Hiroshima bomb)
		if (E >= Hiroshima_bomb)
			return _join(E / Hiroshima_bomb, "Hiroshima bombs", to_equivalent_format);

		const auto one_kg_TNT = 4.184_MJ; // (explosion energy of 1kg Trinitrotoluol)
		mass kgTNT = kilograms(E / one_kg_TNT);
		return to_string(kgTNT) + " TNT";
	}

	/// @brief Returns the percentage as string, e.g. 50.0%
	inline std::string to_percentage(length part, length total)
	{
		return _join((total / part) * 100.0, "%", to_percentage_format);
	}

} // end of namespace SI

// References
// ----------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
