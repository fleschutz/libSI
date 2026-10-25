/// @file     SI/conversions.h
/// @brief    Provides conversion functions, e.g. to_string(12_m).
/// @details  Contains from_string(), to_string(), to_equivalent(), and to_percentage().

#pragma once
#include <iostream>
#include <string>
#include <SI/literals.h>
#define FUNC [[nodiscard]] inline

namespace SI
{
	inline auto to_string_format     = "%.2Lf %s"; ///< configurable, SI standard formatting by default
	inline auto to_equivalent_format = "%.2Lf %s"; ///< configurable, SI standard formatting by default
	inline auto to_percentage_format = "%.0Lf%s";  ///< configurable

	// Function from_string()
	// ----------------------
	/// @brief The from_string() function
	FUNC bool from_string(const std::string& str, length& result)
	{
		double value = 0.0;
		char unit[100] = "";
		if (std::sscanf(str.c_str(), "%lf%99s", &value, unit) != 2)
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

	FUNC bool from_string(const std::string& str, time& result)
	{
		double value = 0.0;
		char unit[100] = "";
		if (std::sscanf(str.c_str(), "%lf%99s", &value, unit) != 2)
			return false; // not recognized

		if (unit == "day" || unit == "days")
			result = 1_d * value;
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

	FUNC bool from_string(const std::string& str, mass& result)
	{
		double value = 0.0;
		char unit[100] = "";
		if (std::sscanf(str.c_str(), "%lf%99s", &value, unit) != 2)
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

	/// @brief Internal function to format quantity and unit into a string by using a format string.
	FUNC std::string _fmt(long double quantity, const char* unit, const char* formatString = to_string_format)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), formatString, quantity, unit);
		return std::string(buf);
	}

	// Function to_string()
	// --------------------

	/// @brief Returns the given length as string using SI units.
	FUNC std::string to_string(const length d)
	{
		if (d <= -1_Gpc || d >= 1_Gpc)
			return _fmt(d / 1_Gpc, "Gpc"); // gigaparsec
		if (d <= -1_Mpc || d >= 1_Mpc)
			return _fmt(d / 1_Mpc, "Mpc"); // megaparsec
		if (d <= -1_kpc || d >= 1_kpc)
			return _fmt(d / 1_kpc, "kpc"); // kiloparsec
		if (d <= -1_pc || d >= 1_pc)
			return _fmt(d / 1_pc, "pc");   // parsec
		if (d <= -1_ly || d >= 1_ly)
			return _fmt(d / 1_ly, "ly");   // light-year
		if (d <= -0.1_au || d >= 0.1_au)
			return _fmt(d / 1_au, "au");   // astronomical unit
		if (d <= -1_km || d >= 1_km)
			return _fmt(d / 1_km, "km");
		if (d <= -1_m || d >= 1_m || d == 0.0_m)
			return _fmt(d / 1_m, "m");
		if (d <= -1_cm || d >= 1_cm)
			return _fmt(d / 1_cm, "cm");
		if (d <= -1_mm || d >= 1_mm)
			return _fmt(d / 1_mm, "mm");
		if (d <= -1_um || d >= 1_um)
			return _fmt(d / 1_um, "μm");
		if (d <= -1_nm || d >= 1_nm)
			return _fmt(d / 1_nm, "nm");
		return _fmt(d / 1_pm, "pm");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const length d)
	{
		os << to_string(d);
		return os;
	}

	/// @brief Returns the given time as string using SI units.
	FUNC std::string to_string(const time t)
	{
		if (t <= -365.25_d || t >= 365.25_d)
			return _fmt(t / 365.25_d, "y");
		if (t <= -1_w || t >= 1_w)
			return _fmt(t / 1_w, "w");
		if (t <= -1_d || t >= 1_d)
			return _fmt(t / 1_d, "d");
		if (t <= -1_h || t >= 1_h)
			return _fmt(t / 1_h, "h");
		if (t <= -1_min || t >= 1_min)
			return _fmt(t / 1_min, "min");
		if (t <= -1_s || t >= 1_s || t == 0.0_s)
			return _fmt(t / 1_s, "s");
		if (t <= -1_ms || t >= 1_ms)
			return _fmt(t / 1_ms, "ms");
		if (t <= -1_us || t >= 1_us)
			return _fmt(t / 1_us, "μs");
		if (t <= -1_ns || t >= 1_ns)
			return _fmt(t / 1_ns, "ns");
		return _fmt(t / 1_ps, "ps");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const time t)
	{
		os << to_string(t);
		return os;
	}

	/// @brief Returns the given mass as string using SI units.
	FUNC std::string to_string(const mass m)
	{
		if (m <= -1_Pt || m >= 1_Pt)
			return _fmt(m / 1_Pt, "Pt");
		if (m <= -1_Tt || m >= 1_Tt)
			return _fmt(m / 1_Tt, "Tt");
		if (m <= -1_Gt || m >= 1_Gt)
			return _fmt(m / 1_Gt, "Gt");
		if (m <= -1_Mt || m >= 1_Mt)
			return _fmt(m / 1_Mt, "Mt");
		if (m <= -1_kt || m >= 1_kt)
			return _fmt(m / 1_kt, "kt");
		if (m <= -1_t || m >= 1_t)
			return _fmt(m / 1_t, "t");
		if (m <= -1_kg || m >= 1_kg || m == 0.0_kg)
			return _fmt(m / 1_kg, "kg");
		if (m <= -1_g || m >= 1_g)
			return _fmt(m / 1_g, "g");
		if (m <= -1_mg || m >= 1_mg)
			return _fmt(m / 1_mg, "mg");
		if (m <= -1_ug || m >= 1_ug)
			return _fmt(m / 1_ug, "µg");
		return _fmt(m / 1_ng, "ng");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const mass m)
	{
		os << to_string(m);
		return os;
	}

	/// @brief Returns the given temperature as string using SI units.
	FUNC std::string to_string(const temperature T)
	{
		if (T >= 1_GK)
			return _fmt(T / 1_GK, "GK");
		if (T >= 1_MK)
			return _fmt(T / 1_MK, "MK");
		if (T >= -150_degC && T <= 150_degC) // human temperature range
			return _fmt(celsius(T), "°C");
		if (T >= 1_K || T == 0.0_K)
			return _fmt(T / 1_K, "K");
		if (T >= 1_mK)
			return _fmt(T / 1_mK, "mK");
		if (T >= 1_uK)
			return _fmt(T / 1_uK, "μK");
		return _fmt(T / 1_nK, "nK");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const temperature T)
	{
		os << to_string(T);
		return os;
	}

	/// @brief Returns the electric current (I) as string using SI units.
	inline std::string to_string(const current I)
	{
		if (I <= -1_GA || I >= 1_GA)
			return _fmt(I / 1_GA, "GA");
		if (I <= -1_MA || I >= 1_MA)
			return _fmt(I / 1_MA, "MA");
		if (I <= -1_kA || I >= 1_kA)
			return _fmt(I / 1_kA, "kA");
		if (I <= -1_A || I >= 1_A || I == 0.0_A)
			return _fmt(I / 1_A, "A");
		if (I <= -1_mA || I >= 1_mA)
			return _fmt(I / 1_mA, "mA");
		if (I <= -1_uA || I >= 1_uA)
			return _fmt(I / 1_uA, "μA");
		if (I <= -1_nA || I >= 1_nA)
			return _fmt(I / 1_nA, "nA");
		return _fmt(I / 1_pA, "pA");
	}

	// Convert the 22 derived SI units:

	/// @brief Returns the given area as string using SI units.
	FUNC std::string to_string(const area a)
	{
		if (a <= -1_km² || a >= 1_km²)
			return _fmt(a / 1_km², "km²");
		if (a <= -1_hm² || a >= 1_hm²)
			return _fmt(a / 1_hm², "hm²");
		if (a <= -1_m² || a >= 1_m² || a == 0.0_m²)
			return _fmt(a / 1_m², "m²");
		if (a <= -1_cm² || a >= 1_cm²)
			return _fmt(a / 1_cm², "cm²");
		if (a <= -1_mm² || a >= 1_mm²)
			return _fmt(a / 1_mm², "mm²");
		return _fmt(a / 1_um², "μm²");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const area a)
	{
		os << to_string(a);
		return os;
	}

	/// @brief Returns the per area as string using SI units.
	FUNC std::string to_string(const per_area a)
	{
		if (a <= -1_per_km² || a >= 1_per_km²)
			return _fmt(a / 1_per_km², "/km²");
		if (a <= -1_per_hm² || a >= 1_per_hm²)
			return _fmt(a / 1_per_hm², "/hm²");
		if (a <= -1_per_m² || a >= 1_per_m² || a == 0.0_per_m²)
			return _fmt(a / 1_per_m², "/m²");
		if (a <= -1_per_cm² || a >= 1_per_cm²)
			return _fmt(a / 1_per_cm², "/cm²");
		if (a <= -1_per_mm² || a >= 1_per_mm²)
			return _fmt(a / 1_per_mm², "/mm²");
		return _fmt(a / 1_per_μm², "/μm²");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const per_area a)
	{
		os << to_string(a);
		return os;
	}

	/// @brief Returns the given volume as string using SI units.
	FUNC std::string to_string(const volume v)
	{
		if (v <= -1_km³ || v >= 1_km³)
			return _fmt(v / 1_km³, "km³");
		if (v <= -1_m³ || v >= 1_m³)
			return _fmt(v / 1_m³, "m³");
		if (v <= -1_l || v >= 1_l || v == 0.0_l)
			return _fmt(v / 1_l, "l");
		if (v <= -1_ml || v >= 1_ml)
			return _fmt(v / 1_ml, "ml");
		if (v <= -1_ul || v >= 1_ul)
			return _fmt(v / 1_ul, "μl");
		if (v <= -1_nl || v >= 1_nl)
			return _fmt(v / 1_nl, "nl");
		return _fmt(v / 1_pl, "pl");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const volume v)
	{
		os << to_string(v);
		return os;
	}

	/// @brief Returns velocity as string using SI units.
	FUNC std::string to_string(const velocity v)
	{
		if (v <= -1_km_per_s || v >= 1_km_per_s)
			return _fmt(v / 1_km_per_s, "km/s");
		if (v <= -1_km_per_h || v >= 1_km_per_h)
			return _fmt(v / 1_km_per_h, "km/h");
		if (v <= -1_m_per_s || v >= 1_m_per_s || v == 0.0_m_per_s)
			return _fmt(v / 1_m_per_s, "m/s");
		return _fmt(v / 1_mm_per_h, "mm/h");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const velocity v)
	{
		os << to_string(v);
		return os;
	}

	/// @brief Returns the acceleration as string using SI units.
	FUNC std::string to_string(const acceleration a)
	{
		if (a <= -1_km_per_s² || a >= 1_km_per_s²)
			return _fmt(a / 1_km_per_s², "km/s");
		return _fmt(a / 1_m_per_s², "m/s²");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const acceleration a)
	{
		os << to_string(a);
		return os;
	}

	/// @brief Returns the frequency as string using SI units.
	FUNC std::string to_string(const frequency f)
	{
		if (f <= -1_THz || f >= 1_THz)
			return _fmt(f / 1_THz, "THz");
		if (f <= -1_GHz || f >= 1_GHz)
			return _fmt(f / 1_GHz, "GHz");
		if (f <= -1_MHz || f >= 1_MHz)
			return _fmt(f / 1_MHz, "MHz");
		if (f <= -1_kHz || f >= 1_kHz)
			return _fmt(f / 1_kHz, "kHz");
		if (f <= -1_Hz || f >= 1_Hz || f == 0.0_Hz)
			return _fmt(f / 1_Hz, "Hz");
		if (f <= -1_mHz || f >= 1_mHz)
			return _fmt(f / 1_mHz, "mHz");
		return _fmt(f / 1_uHz, "uHz");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const frequency f)
	{
		os << to_string(f);
		return os;
	}

	/// @brief Returns the force as string using SI units.
	FUNC std::string to_string(const force F)
	{
		if (F <= -1_ZN || F >= 1_ZN)
			return _fmt(F / 1_ZN, "ZN");
		if (F <= -1_EN || F >= 1_EN)
			return _fmt(F / 1_EN, "EN");
		if (F <= -1_PN || F >= 1_PN)
			return _fmt(F / 1_PN, "PN");
		if (F <= -1_TN || F >= 1_TN)
			return _fmt(F / 1_TN, "TN");
		if (F <= -1_GN || F >= 1_GN)
			return _fmt(F / 1_GN, "GN");
		if (F <= -1_MN || F >= 1_MN)
			return _fmt(F / 1_MN, "MN");
		if (F <= -1_kN || F >= 1_kN)
			return _fmt(F / 1_kN, "kN");
		if (F <= -1_N || F >= 1_N || F == 0.0_N)
			return _fmt(F / 1_N, "N");
		if (F <= -1_mN || F >= 1_mN)
			return _fmt(F / 1_mN, "mN");
		if (F <= -1_uN || F >= 1_uN)
			return _fmt(F / 1_uN, "µN");
		return _fmt(F / 1_pN, "pN");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const force F)
	{
		os << to_string(F);
		return os;
	}

	/// @brief Returns the energy as string using SI units.
	FUNC std::string to_string(const energy E)
	{
		if (E <= -1_PJ || E >= 1_PJ)
			return _fmt(E / 1_PJ, "PJ");
		if (E <= -1_TJ || E >= 1_TJ)
			return _fmt(E / 1_TJ, "TJ");
		if (E <= -1_GJ || E >= 1_GJ)
			return _fmt(E / 1_GJ, "GJ");
		if (E <= -1_MJ || E >= 1_MJ)
			return _fmt(E / 1_MJ, "MJ");
		if (E <= -1_kJ || E >= 1_kJ)
			return _fmt(E / 1_kJ, "kJ");
		if (E <= -1_J || E >= 1_J || E == 0.0_J)
			return _fmt(E / 1_J, "J");
		return _fmt(E / 1_mJ, "mJ");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const energy E)
	{
		os << to_string(E);
		return os;
	}

	/// @brief Returns the power as string using SI units.
	FUNC std::string to_string(const power P)
	{
		if (P <= -1_TW || P >= 1_TW)
			return _fmt(P / 1_TW, "TW");
		if (P <= -1_GW || P >= 1_GW)
			return _fmt(P / 1_GW, "GW");
		if (P <= -1_MW || P >= 1_MW)
			return _fmt(P / 1_MW, "MW");
		if (P <= -1_kW || P >= 1_kW)
			return _fmt(P / 1_kW, "kW");
		if (P <= -1_W || P >= 1_W)
			return _fmt(P / 1_W, "W");
		if (P <= -1_mW || P >= 1_mW)
			return _fmt(P / 1_mW, "mW");
		return _fmt(P / 1_uW, "uW");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const power P)
	{
		os << to_string(P);
		return os;
	}

	/// @brief Returns the power intensity as string using SI units.
	FUNC std::string to_string(const power_intensity I)
	{
		if (I <= -1_MW_per_m² || I >= 1_MW_per_m²)
			return _fmt(I / 1_MW_per_m², "MW/m²");
		if (I <= -1_kW_per_m² || I >= 1_kW_per_m²)
			return _fmt(I / 1_kW_per_m², "kW/m²");
		if (I <= -1_W_per_m² || I >= 1_W_per_m²)
			return _fmt(I / 1_W_per_m², "W/m²");
		return _fmt(I / 1_mW_per_m², "mW/m²");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const power_intensity I)
	{
		os << to_string(I);
		return os;
	}

	/// @brief Returns the pressure as string using SI units.
	FUNC std::string to_string(const pressure p)
	{
		if (p <= -1_MPa || p >= 1_MPa)
			return _fmt(p / 1_MPa, "MPa");
		if (p <= -1_kPa || p >= 1_kPa)
			return _fmt(p / 1_kPa, "kPa");
		if (p <= -1_hPa || p >= 1_hPa)
			return _fmt(p / 1_hPa, "hPa");
		if (p <= -1_Pa || p >= 1_Pa || p == 0.0_Pa)
			return _fmt(p / 1_Pa, "Pa");
		if (p <= -1_mPa || p >= 1_mPa)
			return _fmt(p / 1_mPa, "mPa");
		return _fmt(p / 1_uPa, "µPa");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const pressure p)
	{
		os << to_string(p);
		return os;
	}

	/// @brief Returns the electric potential as string using SI units.
	FUNC std::string to_string(const electric_potential U)
	{
		if (U <= -1_GV || U >= 1_GV)
			return _fmt(U / 1_GV, "GV");
		if (U <= -1_MV || U >= 1_MV)
			return _fmt(U / 1_MV, "MV");
		if (U <= -1_kV || U >= 1_kV)
			return _fmt(U / 1_kV, "kV");
		if (U <= -1_V || U >= 1_V || U == 0.0_V)
			return _fmt(U / 1_V, "V");
		if (U <= -1_mV || U >= 1_mV)
			return _fmt(U / 1_mV, "mV");
		if (U <= -1_uV || U >= 1_uV)
			return _fmt(U / 1_uV, "μV");
		if (U <= -1_nV || U >= 1_nV)
			return _fmt(U / 1_nV, "nV");
		return _fmt(U / 1_pV, "pV");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const electric_potential U)
	{
		os << to_string(U);
		return os;
	}

	/// @brief Returns the electric charge as string using SI units.
	FUNC std::string to_string(const electric_charge Q)
	{
		if (Q <= -1_GAh || Q >= 1_GAh)
			return _fmt(Q / 1_MAh, "MAh");
		if (Q <= -1_MAh || Q >= 1_MAh)
			return _fmt(Q / 1_MAh, "MAh");
		if (Q <= -1_kAh || Q >= 1_kAh)
			return _fmt(Q / 1_kAh, "kAh");
		if (Q <= -1_Ah || Q >= 1_Ah || Q == 0.0_Ah)
			return _fmt(Q / 1_Ah, "Ah");
		if (Q <= -1_mAh || Q >= 1_mAh)
			return _fmt(Q / 1_mAh, "mAh");
		return _fmt(Q / 1_uAh, "µAh");
	}

	FUNC std::string to_string(const mass_per_area m)
	{
		if (m <= -1_t_per_m² || m >= 1_t_per_m²)
			return _fmt(m / 1_t_per_m², "t/m²");
		return _fmt(m / 1_kg_per_m², "kg/m²");
	}

	/// @brief Returns the mass per power as string using SI units.
	FUNC std::string to_string(const mass_per_power m)
	{
		if (m <= -1_kg_per_kW || m >= 1_kg_per_kW)
			return _fmt(m / 1_kg_per_kW, "kg/kW");
		return _fmt(m / 1_kg_per_W, "kg/W");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const mass_per_power m)
	{
		os << to_string(m);
		return os;
	}

	/// @brief Returns density as string using SI units.
	FUNC std::string to_string(const density d)
	{
		if (d <= -1_t_per_m³ || d >= 1_t_per_m³)
			return _fmt(d / 1_t_per_m³, "t/m³");
		return _fmt(d / 1_kg_per_m³, "kg/m³");
	}

	/// @brief Returns the data size as string in bits and bytes.
	FUNC std::string to_string(const data_size n)
	{
		if (n >= 1_EB)  return _fmt(n / 1_EB, "EB");
		if (n >= 1_PB)  return _fmt(n / 1_PB, "PB");
		if (n >= 1_TB)  return _fmt(n / 1_TB, "TB");
		if (n >= 1_GB)  return _fmt(n / 1_GB, "GB");
		if (n >= 1_MB)  return _fmt(n / 1_MB, "MB");
		if (n >= 1_kB)  return _fmt(n / 1_kB, "kB");
		if (n >= 8_bit) return _fmt(n / 8_bit, "bytes");
		if (n > 1_bit)  return _fmt(n / 1_bit, "bits");
		return _fmt(n / 1_bit, "bit");
	}

	FUNC std::ostream& operator<<(std::ostream& os, const data_size n)
	{
		os << to_string(n);
		return os;
	}

	/// @brief Returns the angle as string in degree.
	FUNC std::string to_string(const angle a)
	{
		return _fmt(a / 1_deg, "°");
	}

	FUNC std::string to_string(const dimensionless value)
	{
		return _fmt(value, "");
	}

	FUNC std::string to_string(const unsigned char byte)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), "%u", byte);
		return std::string(buf);
	}

	FUNC std::string to_string(const char glyph)
	{
		char buf[256];
		std::snprintf(buf, sizeof(buf), "%c", glyph);
		return std::string(buf);
	}

	FUNC std::string to_string(const std::string& text)
	{
		return text;
	}

	// Function to_equivalent()
	// ------------------------

	/// @brief Returns a length equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(const length d)
	{
		if (d <= -1_ly || d >= 1_ly)
			return _fmt(d / 1_ly, "light-years", to_equivalent_format);
		if (d <= -1_ls || d >= 1_ls)
			return _fmt(d / 1_ls, "light-seconds", to_equivalent_format);
		if (d <= -1_mi || d >= 1_mi)
			return _fmt(d / 1_mi, "mi", to_equivalent_format);
		if (d <= -1_yd || d >= 1_yd)
			return _fmt(d / 1_yd, "yd", to_equivalent_format);
		if (d <= -1_ft || d >= 1_ft)
			return _fmt(d / 1_ft, "ft", to_equivalent_format);
		return _fmt(d / 1_in, "in", to_equivalent_format);
	}

	/// @brief Returns a mass equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(const mass m)
	{
		if (m <= -1_Msun || m >= 1_Msun)
			return _fmt(m / 1_Msun, "solar masses", to_equivalent_format);
		if (m <= -1_Mjup || m >= 1_Mjup)
			return _fmt(m / 1_Mjup, "Jupiter masses", to_equivalent_format);
		if (m <= -1_Mearth || m >= 1_Mearth)
			return _fmt(m / 1_Mearth, "Earth masses", to_equivalent_format);
		if (m <= -1_Mmoon || m >= 1_Mmoon)
			return _fmt(m / 1_Mmoon, "Moon masses", to_equivalent_format);
		if (m <= -1_lb || m >= 1_lb)
			return _fmt(m / 1_lb, "lb", to_equivalent_format);
		return _fmt(m / 1_oz, "oz", to_equivalent_format);
	}

	/// @brief Returns a temperature equivalent as string, e.g. in Fahrenheit.
	FUNC std::string to_equivalent(const temperature T)
	{
		return _fmt(fahrenheit(T), "°F", to_equivalent_format);
	}

	/// @brief Returns a velocity equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(const velocity V)
	{
		if (V <= -1_Mach || V >= 1_Mach)
			return _fmt(V / 1_Mach, "Mach", to_equivalent_format);
		return _fmt(V / 1_mph, "mph", to_equivalent_format);
	}

	/// @brief Returns a power intensity equivalent as string, e.g. in dB.
	FUNC std::string to_equivalent(const power_intensity I)
	{
		return _fmt(10.0 * std::log10((I / 1_W_per_m²) / 1e-12), "dB", to_equivalent_format);
	}

	/// @brief Returns an energy equivalent as string, e.g. kg TNT.
	FUNC std::string to_equivalent(const energy E)
	{
		const auto Hiroshima_bomb = 62_TJ; // (explosion energy of the Hiroshima bomb)
		if (E >= Hiroshima_bomb)
			return _fmt(E / Hiroshima_bomb, "Hiroshima bombs", to_equivalent_format);

		const auto one_kg_TNT = 4.184_MJ; // (explosion energy of 1kg Trinitrotoluol)
		mass kgTNT = kilograms(E / one_kg_TNT);
		return to_string(kgTNT) + " TNT";
	}

	/// @brief Returns a data size equivalent as string.
	FUNC std::string to_equivalent(const data_size n)
	{
		if (n >= 1_PiB)  return _fmt(n / 1_PiB, "PiB");
		if (n >= 1_TiB)  return _fmt(n / 1_TiB, "TiB");
		if (n >= 1_GiB)  return _fmt(n / 1_GiB, "GiB");
		if (n >= 1_MiB)  return _fmt(n / 1_MiB, "MiB");
		if (n >= 1_kiB)  return _fmt(n / 1_kiB, "kiB");
		if (n >= 8_bit) return _fmt(n / 8_bit, "bytes");
		if (n > 1_bit)  return _fmt(n / 1_bit, "bits");
		return _fmt(n / 1_bit, "bit");
	}

	// Function to_percentage()
	// ------------------------

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(const length part, const length total)
	{
		return _fmt((part / total) * 100.0, "%", to_percentage_format);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(const mass part, const mass total)
	{
		return _fmt((part / total) * 100.0, "%", to_percentage_format);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(const velocity part, const velocity total)
	{
		return _fmt((part / total) * 100.0, "%", to_percentage_format);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(const data_size part, const data_size total)
	{
		return _fmt((part / total) * 100.0, "%", to_percentage_format);
	}

	// References
	// ----------
	// 1. https://en.wikipedia.org/wiki/International_System_of_Units

} // end of namespace

#undef FUNC
