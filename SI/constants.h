/// @file     SI/constants.h
/// @brief    Defines 78 type-safe constants based on libSI's datatypes and units
/// @details  Categories are: defined constants, universal constants, electromagnetic constants,
///                           atomic & nuclear constants, physico-chemical constants, physical constants,
///                           mathematical constants, astronomical constants, various constants, and references.

#pragma once
#include <SI/units.h>
#define SET(_name, _quantity, _unit) constexpr auto _name = _unit(_quantity)

namespace SI { namespace constant {

  // Defined Constants (CODATA 2022)
  // -----------------
  SET(caesium_frequency,     9'192'631'770, hertz); // the unperturbed ground state hyperfine transition frequency of the ceesium-133 atom
  SET(delta_v_Cs,            9'192'631'770, hertz); // (the symbol)
  SET(speed_of_light_in_vacuum,299'792'458.0, meters_per_second); // the speed of light in vacuum
  SET(c,                     299'792'458.0, meters_per_second); // (the symbol)
  SET(planck,             6.626'070'15e-34, jouleseconds); // Planck constant (symbol: h)
  SET(elementary_charge, 1.602'176'634e-19, coulombs); // the elementary charge (symbol: e)
  SET(boltzmann,             1.380'649e-23, joules_per_kelvin); // Boltzmann constant (symbol: k)
  SET(avogadro,              6.02214076e23, per_mol); // Avogadro constant (symbol: N_A)
  SET(K_cd,                            683, lumens_per_watt); // the luminous efficacy of monochromatic radiation of frequency 540 THz
  SET(g_n,                        9.806'65, meters_per_second2); // standard acceleration of gravity
  SET(atm,                         101'325, pascals); // standard atmosphere
  SET(ssp,                         100'000, pascals); // standard-state pressure

  // Universal Constants (CODATA 2022)
  // -------------------
  SET(G,                       6.67430e-11, meters3_per_kilogram_per_second2); // Newtonian constant of gravitation
  SET(Z_0,                 376.730'313'412, ohms); // characteristic impedance of vacuum
  SET(epsilon_0,        8.854'187'8188e-12, farads_per_meter); // vacuum electric permittivity, symbol: ε_0
  SET(l_P,                    1.616255e-35, meters); // Planck length
  SET(m_P,                     2.176434e-8, kilograms); // Planck mass
  SET(T_P,                     1.416784e32, kelvins); // Planck temperature
  SET(t_P,                    5.391247e-44, seconds); // Planck time
  SET(h_bar,             1.054'571'817e-34, jouleseconds); // reduced Planck constant
  SET(mu_0,            1.256'637'061'27e-6, newtons_per_ampere2); // vacuum magnetic permeability

  // Electromagnetic Constants (CODATA 2022)
  // -------------------------
  SET(G_0,                7.748'091'729e-5, siemens); // conductance quantum
  SET(G_0_inv,                 12906.40372, ohms); // inverse conductance quantum
  SET(K_J,                 483'597.848'4e9, hertz_per_volt); // Josephson constant
  SET(mu_B,             9.274'010'0657e-24, joules_per_tesla); // Bohr magneton (symbol: µB)
  SET(mu_N,             5.050'783'7393e-27, joules_per_tesla); // nuclear magneton (symbol: μ_N)
  SET(Phi_0,               2.067833848e-15, webers); // magnetic flux quantum (symbol: Φ_0)
  SET(R_K,                   25'812.807'45, ohms); // von Klitzing constant
  SET(R_Km90,                    25812.807, ohms); // conventional value of von Klitzing constant

  // Atomic & Nuclear Constants (CODATA 2022)
  // --------------------------
  SET(a_0,            5.291'772'105'44e-11, meters);   // Bohr radius
  SET(alpha,                  7.2973525e-3, dimensionless); // fine-structure constant
  SET(alpha_inv,           137.035'999'177, dimensionless); // inverse fine-structure constant
  SET(E_h,                4.3597447222e-18, joules);    // Hartree energy
  SET(g_e,               -2.00231930436256, dimensionless); // electron g-factor
  SET(h_2me,                  3.6369475e-4, meters2_per_second); // quantum of circulation
  SET(m_e,              9.109'383'7139e-31, kilograms); // electron mass
  SET(m_d,              3.343'583'7768e-27, kilograms); // deuteron mass
  SET(m_h,              5.006'412'7862e-27, kilograms); // helion mass
  SET(m_mu,              1.883'531'627e-28, kilograms); // muon mass
  SET(m_n,            1.674'927'500'56e-27, kilograms); // neutron mass
  SET(m_p,            1.672'621'925'95e-27, kilograms); // proton mass
  SET(m_tau,                  3.167'54e-27, kilograms); // tau mass
  SET(m_t,              5.007'356'7512e-27, kilograms); // triton mass
  SET(r_e,              2.817'940'3205e-15, meters); // classical electron radius
  SET(R_inf,            10'973'731.568'157, per_meter); // Rydberg constant
  SET(sin2Theta_W,                 0.22290, dimensionless); // weak mixing angle
  SET(sigma_e,               6.6524587e-29, meters2); // Thomson cross section (symbol: σ_e)

  // Physico-chemical Constants (CODATA 2022)
  // --------------------------
  SET(b,                    2.897771955e-3, meter_kelvins); // Wien wavelength displacement law constant
  SET(c_1,                 3.741771852e-16, wattmeters2); // first radiation constant
  SET(c_1L,                1.191042972e-16, watts_per_meter2); // first radiation constant for spectral radiance
  SET(F,                     96'485.332'12, coulombs_per_mol); // Faraday constant
  SET(m_u,          1.660'539'068'9252e-27, kilograms); // atomic mass constant
  SET(M_u,             1.000'000'001'05e-3, kilograms_per_mol); // molar mass constant
  SET(R,                     8.314'462'618, joules_per_kelvin_per_mol); // molar gas constant
  SET(R_dry_air,              287.050'0676, joules_per_kilogram_per_kelvin); // specific gas constant for dry air
  SET(S_0_by_R,             -1.15170753706, dimensionless); // Sackur–Tetrode constant
  SET(V_m,                22.710'954'64e-3, meters3_per_mol); // molar volume of ideal gas (273.15K, 100kPa)

  // Physical Constants
  // ------------------
  SET(gravitational_constant,6.6743015e-11, meters3_per_kilogram_per_second2);
  SET(Earth_gravity,               9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).
  SET(speed_of_sound,                  343, meters_per_second); // speed of sound in dry air at 20°C (68°F)
  SET(speed_of_sound_in_fresh_water,  1481, meters_per_second); // at 20°C (68°F)
  SET(speed_of_sound_in_iron,         5120, meters_per_second);
  SET(speed_of_sound_in_diamonds,   12'000, meters_per_second);

  // Mathematical Constants (https://en.wikipedia.org/wiki/Mathematical_constant)
  // ----------------------
  SET(root_2,       1.41421356237309504880, dimensionless); // Pythagoras' constant (square root of 2)
  SET(tau,          6.28318530717958647692, radians); // 2π (symbol: τ)
  SET(pi,           3.14159265358979323846, radians); // Archimedes' constant (symbol: π)
  SET(half_pi,      1.57079632679489661923, radians); // π / 2
  SET(quarter_pi,   0.78539816339744830961, radians); // π / 4
  SET(e,            2.71828182845904523536, dimensionless); // Euler's number (symbol: e)
  SET(phi,          1.61803398874989484820, dimensionless); // golden ratio (symbol: φ)

  // Astronomical Constants (https://en.wikipedia.org/wiki/Astronomical_constant)
  // ----------------------
  SET(AU,                  149'597'870'700, meters); // one astronomical unit (symbol: au, IAU 2009)
  SET(parsec,       30'856'775'814'913'673, meters); // one Parsec (symbol: pc, IAU 2015)
  SET(lightyear,     9'460'730'472'580'800, meters); // one light-year (symbol: ly, IAU 2009)
  SET(F1AU,                         1366.1, watts_per_meter2);// total solar irradiance at 1 AU (solar constant)
  SET(H0,                           70'100, meters_per_second); // (per megaparsec, Hubble constant, symbol: H0)
  SET(Lsun,                       3.939e26, watts); // (Solar luminosity, symbol: L☉)

  // Various Constants
  // -----------------
  SET(T0,                                0, kelvins); // absolute zero (0K, the lowest possible temperature)
  SET(Marathon_distance,            42'195, meters);
  SET(quarter_mile,                 402.34, meters);
 
  // References
  // ----------
  // 1. https://en.wikipedia.org/wiki/International_System_of_Units
  // 2. https://en.wikipedia.org/wiki/List_of_physical_constants
  // 3. https://en.wikipedia.org/wiki/List_of_mathematical_constants
  // 4. https://en.wikipedia.org/wiki/Astronomical_constant
  // 5. https://codata.org - CODATA: the committee on data of the International Science Council (ISC)

} } // end of namespaces

#undef SET
