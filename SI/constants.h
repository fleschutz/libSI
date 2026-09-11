/// @file     SI/constants.h
/// @brief    Defines 77 type-safe constants, e.g. speed_of_light (source: 2022 CODATA).
/// @details  Categories are: Defined Constants, Universal Constants, Electromagnetic Constants,
///           Atomic & Nuclear Constants, Physico-chemical Constants, Physical Constants,
///           Mathematical Constants, Astronomical Constants, Various Constants, and References.

#pragma once
#include <SI/units.h>
#define CONST(_name, _value, _base_unit) const auto _name = _base_unit(_value)

namespace SI { namespace constant {

	// 1. Defined Constants
	// --------------------
	CONST(caesium_frequency,     9'192'631'770, hertz); // the unperturbed ground state hyperfine transition frequency of the ceesium-133 atom
	CONST(delta_v_Cs,            9'192'631'770, hertz); // (the symbol)
	CONST(speed_of_light,          299'792'458, meters_per_second); // the speed of light in vacuum
	CONST(c,                       299'792'458, meters_per_second); // (the symbol)
	CONST(Planck,             6.626'070'15e-34, jouleseconds); // the Planck constant
	CONST(h,                  6.626'070'15e-34, jouleseconds); // (the symbol)
	CONST(elementary_charge, 1.602'176'634e-19, coulombs); // the elementary charge
	CONST(e,                 1.602'176'634e-19, coulombs); // (the symbol)
	CONST(Boltzmann,             1.380'649e-23, joules_per_kelvin); // the Boltzmann constant
	CONST(k,                     1.380'649e-23, joules_per_kelvin); // (the symbol)
	CONST(N_A,                   6.02214076e23, per_mol); // the Avogadro constant
	CONST(K_cd,                            683, lumens_per_watt); // the luminous efficacy of monochromatic radiation of frequency 540 THz
	CONST(g_n,                        9.806'65, meters_per_second2); // standard acceleration of gravity (2022 CODATA)
	CONST(atm,                         101'325, pascals); // standard atmosphere (2022 CODATA)
	CONST(ssp,                         100'000, pascals); // standard-state pressure (2022 CODATA)

	// 2. Universal Constants
	// ----------------------
	CONST(G,                       6.67430e-11, meters3_per_kilogram_per_second2); // Newtonian constant of gravitation (2022 CODATA)
	CONST(Z_0,                 376.730'313'412, ohms); // characteristic impedance of vacuum (2022 CODATA)
	CONST(epsilon_0,        8.854'187'8188e-12, farads_per_meter); // vacuum electric permittivity, symbol: ε_0, 2022 CODATA)
	CONST(l_P,                    1.616255e-35, meters); // Planck length (2022 CODATA)
	CONST(m_P,                     2.176434e-8, kilograms); // Planck mass (2022 CODATA)
	CONST(T_P,                     1.416784e32, kelvins); // Planck temperature (2022 CODATA)
	CONST(t_P,                    5.391247e-44, seconds); // Planck time (2022 CODATA)
	CONST(h_bar,             1.054'571'817e-34, jouleseconds); // reduced Planck constant (2022 CODATA)
	CONST(mu_0,            1.256'637'061'27e-6, newtons_per_ampere2); // vacuum magnetic permeability (2022 CODATA)

	// 3. Electromagnetic Constants
	// ----------------------------
	CONST(G_0,                7.748'091'729e-5, siemens); // conductance quantum (2022 CODATA)
	CONST(G_0_inv,                 12906.40372, ohms); // inverse conductance quantum
	CONST(K_J,                 483'597.848'4e9, hertz_per_volt); // Josephson constant (2022 CODATA)
	CONST(mu_B,             9.274'010'0657e-24, joules_per_tesla); // Bohr magneton (symbol: µB, 2022 CODATA)
	CONST(mu_N,             5.050'783'7393e-27, joules_per_tesla); // nuclear magneton (symbol: μ_N, 2022 CODATA))
	CONST(Phi_0,               2.067833848e-15, webers); // magnetic flux quantum (symbol: Φ_0)
	CONST(R_K,                   25'812.807'45, ohms); // von Klitzing constant (2022 CODATA)
	CONST(R_Km90,                    25812.807, ohms); // conventional value of von Klitzing constant

	// 4. Atomic & Nuclear Constants
	// -----------------------------
	CONST(a_0,            5.291'772'105'44e-11, meters);   // Bohr radius (2022 CODATA)
	CONST(alpha,                  7.2973525e-3, dimensionless); // fine-structure constant
	CONST(alpha_inv,           137.035'999'177, dimensionless); // inverse fine-structure constant (2022 CODATA)
	CONST(E_h,                4.3597447222e-18, joules);    // Hartree energy
	CONST(g_e,               -2.00231930436256, dimensionless); // electron g-factor
	CONST(h_2me,                  3.6369475e-4, meters2_per_second); // quantum of circulation
	CONST(m_e,              9.109'383'7139e-31, kilograms); // electron mass (2022 CODATA)
	CONST(m_d,              3.343'583'7768e-27, kilograms); // deuteron mass (2022 CODATA)
	CONST(m_h,              5.006'412'7862e-27, kilograms); // helion mass (2022 CODATA)
	CONST(m_mu,              1.883'531'627e-28, kilograms); // muon mass (2022 CODATA)
	CONST(m_n,            1.674'927'500'56e-27, kilograms); // neutron mass (2022 CODATA)
	CONST(m_p,            1.672'621'925'95e-27, kilograms); // proton mass (2022 CODATA)
	CONST(m_tau,                  3.167'54e-27, kilograms); // tau mass (2022 CODATA)
	CONST(m_t,              5.007'356'7512e-27, kilograms); // triton mass (2022 CODATA)
	CONST(r_e,              2.817'940'3205e-15, meters); // classical electron radius (2022 CODATA)
	CONST(R_inf,            10'973'731.568'157, per_meter); // Rydberg constant (2022 CODATA)
	CONST(sin2Theta_W,                 0.22290, dimensionless); // weak mixing angle
	CONST(sigma_e,               6.6524587e-29, meters2); // Thomson cross section (symbol: σ_e)

	// 5. Physico-chemical Constants
	// -----------------------------
	CONST(b,                    2.897771955e-3, meter_kelvins); // Wien wavelength displacement law constant
	CONST(c_1,                 3.741771852e-16, wattmeters2); // first radiation constant
	CONST(c_1L,                1.191042972e-16, watts_per_meter2); // first radiation constant for spectral radiance
	CONST(F,                     96'485.332'12, coulombs_per_mol); // Faraday constant (2022 CODATA)
	CONST(m_u,          1.660'539'068'9252e-27, kilograms); // atomic mass constant (2022 CODATA)
	CONST(M_u,             1.000'000'001'05e-3, kilograms_per_mol); // molar mass constant (2022 CODATA)
	CONST(R,                     8.314'462'618, joules_per_kelvin_per_mol); // molar gas constant (2022 CODATA)
	CONST(R_dry_air,              287.050'0676, joules_per_kilogram_per_kelvin); // specific gas constant for dry air
	CONST(S_0_by_R,             -1.15170753706, dimensionless); // Sackur–Tetrode constant
	CONST(V_m,                22.710'954'64e-3, meters3_per_mol); // molar volume of ideal gas (273.15K, 100kPa, 2022 CODATA)

	// 6. Physical Constants
	// ---------------------
	CONST(gravitational_constant,6.6743015e-11, meters3_per_kilogram_per_second2);
	CONST(Earth_gravity,               9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).
	CONST(speed_of_sound,                  343, meters_per_second); // speed of sound in dry air at 20°C (68°F)
	CONST(speed_of_sound_in_fresh_water,  1481, meters_per_second); // at 20°C (68°F)
	CONST(speed_of_sound_in_iron,         5120, meters_per_second);
	CONST(speed_of_sound_in_diamonds,   12'000, meters_per_second);

	// 7. Mathematical Constants
	// -------------------------
	CONST(tau,          6.28318530717958647692, radians); // (symbol: τ)
	CONST(pi,           3.14159265358979323846, radians); // (symbol: π)
	CONST(half_pi,      1.57079632679489661923, radians); // (π / 2)
	CONST(quarter_pi,   0.78539816339744830961, radians); // (π / 4)
	CONST(phi,          1.61803398874989484820, dimensionless); // (symbol: φ)
	CONST(Eulers_number,2.71828182845904523536, dimensionless);

	// 8. Astronomical Constants
	// -------------------------
	CONST(AU,                  149'597'870'691, meters); // one astronomical unit (symbol: au)
	CONST(parsec,       30'856'775'814'913'700, meters); // one Parsec (symbol: pc)
	CONST(lightyear,     9'460'730'777'119'564, meters); // one light-year (symbol: ly)

	// 9. Various Constants
	// --------------------
	CONST(T0,                                0, kelvins); // absolute zero (-273.15°C, the lowest possible temperature)
	CONST(Marathon_distance,            42'195, meters);
	CONST(quarter_mile,                 402.34, meters);
 
	// 10. References
	// --------------
	// 1. https://en.wikipedia.org/wiki/International_System_of_Units
	// 2. https://en.wikipedia.org/wiki/List_of_physical_constants
	// 3. https://en.wikipedia.org/wiki/List_of_mathematical_constants
	// 4. https://en.wikipedia.org/wiki/Astronomical_constant
	// 5. https://codata.org - CODATA: the committee on data of the International Science Council (ISC)

} } // namespace SI::constant

#undef CONST
