// SI/constants.h - type-safe constants based on SI units
#pragma once

#include "units.h"
#define SET(_name, _value, _baseUnit) const auto _name = _baseUnit(_value##L)

namespace SI { namespace constant {

// The 7 defining constants of SI (as of 20 May 2019)
SET(caesium_frequency,     9'192'631'770, hertz); // the unperturbed ground state hyperfine transition frequency of the ceesium-133 atom
SET(delta_v_Cs,            9'192'631'770, hertz); // (the symbol)
SET(speed_of_light,          299'792'458, meters_per_second); // the speed of light in vacuum
SET(c,                       299'792'458, meters_per_second); // (the symbol)
SET(Planck,             6.626'070'15e-34, joulesecond); // the Planck constant
SET(h,                  6.626'070'15e-34, joulesecond); // (the symbol)
SET(elementary_charge, 1.602'176'634e-19, coulomb); // the elementary charge
SET(e,                 1.602'176'634e-19, coulomb); // (the symbol)
SET(Boltzmann,             1.380'649e-23, joules_per_kelvin); // the Boltzmann constant
SET(k,                     1.380'649e-23, joules_per_kelvin); // (the symbol)
SET(N_A,                   6.02214076e23, per_mol); // the Avogadro constant
SET(K_cd,                            683, lumens_per_watt); // the luminous efficacy of monochromatic radiation of frequency 540 THz

// Universal constants
SET(min_temperature,                   0, kelvin); // the lowest possible temperature (Absolute zero)
SET(Z_0,                   376.730313667, ohm); // characteristic impedance of vacuum
SET(epsilon_0,  8.854'187'817'620'39e-12, farads_per_meter); // electric constant (vacuum permittivity, symbol: ε_0)
//SET(mu_0,              1.256'637'06e-6, units::N / units::A2); // magnetic constant (vacuum permeability, symbol: μ_0)
//SET(G,                     6.67408e-11, units::m3 / units::kg / units::s2); // Newtonian constant of gravitation
SET(h_bar,             1.054'571'817e-34, joulesecond); // reduced Planck constant

// Electromagnetic constants
SET(mu_B,                  9.2740100e-24, joules_per_tesla); // Bohr magneton (symbol: µB)
SET(G_0,                  7.748091729e-5, siemens); // conductance quantum
//SET(K_Jm90,                    48359e9, units::Hz / units::V); // conventional value of Josephson constant
SET(R_Km90,                    25812.807, ohm); // conventional value of von Klitzing constant
SET(G_0_inv,                 12906.40372, ohm); // inverse conductance quantum
//SET(K_J,                 483597.8484e9, units::Hz / units::V); // Josephson constant
SET(Phi_0,               2.067833848e-15, weber); // magnetic flux quantum (symbol: Φ_0)
SET(mu_N,                  5.0507837e-27, joules_per_tesla); // nuclear magneton (symbol: μ_N)
SET(R_K,                     25812.80745, ohm); // von Klitzing constant
//SET(k_e,      1.0 / (4*M_PI*epsilon_0), dimensionless);

// Atomic and nuclear constants
SET(electron_mass,      9.1093837139e-31, kilogram);
SET(m_e,                9.1093837139e-31, kilogram); // electron mass
SET(muon_mass,           1.883531627e-28, kilogram);
SET(tau_mass,                3.16754e-27, kilogram);
SET(proton_mass,       1.67262192595e-27, kilogram);
SET(m_p,               1.67262192595e-27, kilogram);
SET(neutron_mass,      1.67492750056e-27, kilogram);
SET(a_0,                  5.29177210e-11, meter);    // Bohr radius
SET(r_e,                   2.8179403e-15, meter);    // classical electron radius
SET(g_e,               -2.00231930436256, dimensionless); // electron g-factor
SET(alpha,                  7.2973525e-3, dimensionless); // fine-structure constant
SET(alpha_inv,             137.035999084, dimensionless); // inverse fine-structure constant
SET(E_h,                4.3597447222e-18, joule);    // Hartree energy
SET(sin2Theta_W,                 0.22290, dimensionless); // weak mixing angle
//SET(G0_F,                    1.1663e-5, / units::GeV  / units::GeV); // Fermi coupling constant
SET(h_2me,                  3.6369475e-4, meter2_per_second); // quantum of circulation
SET(R_inf,               10973731.568160, per_meter); // Rydberg constant
SET(sigma_e,               6.6524587e-29, meter2); // Thomson cross section

// Physico-chemical constants
SET(m_u,                  1.66053906e-27, kilogram); // Atomic mass constant
SET(F,                       96485.33212, coulombs_per_mol); // Faraday constant
SET(c_1,                 3.741771852e-16, wattmeter2); // first radiation constant
SET(c_1L,                1.191042972e-16, watts_per_meter2); // first radiation constant for spectral radiance
//SET(n_0,                2.651645804e25, / units::m3); // Loschmidt constant
SET(R,                       8.314462618, joules_per_kelvin_per_mol); // gas constant
SET(R_dry_air,              287.050'0676, joules_per_kilogram_per_kelvin); // specific gas constant for dry air
//SET(N_Ah,              3.990312712e-10, units::J / units::Hz / units::mol); // molar Planck constant
//SET(M_u,                 0.99999999e-3, kilograms_per_mol); // molar mass constant
//SET(V_m,                22.71095464e-3, units::m3 / units::mol); // molar volume of an ideal gas
//SET(c_2,                1.438776877e-2, units::m * units::K); // second radiation constant
//SET(sigma,              5.670374419e-8, units::W / units::m2 / units::K2); // Stefan–Boltzmann constant
//SET(b,                  2.897771955e-3, units::m * units::K); // Wien wavelength displacement law constant
//SET(b_prime,            5.878925757e10, units::Hz / units::K); // Wien frequency displacement law constant
SET(S_0_by_R,             -1.15170753706, dimensionless); // Sackur–Tetrode constant

// Adopted values
SET(atm,                          101325, pascal_); // standard atmosphere
   
// Physical constants
SET(standard_gravity,            9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).
SET(g_0,                         9.80665, meters_per_second2); // (the symbol)
//SET(Gravitational_constant,   6.6743015e−11, si::m3 / si::kilogram / si::s2);
SET(speed_of_sound,                  343, meters_per_second); // speed of sound in dry air at 20°C (68°F)
SET(speed_of_sound_in_fresh_water,  1481, meters_per_second); // at 20°C (68°F)
SET(speed_of_sound_in_iron,         5120, meters_per_second);
SET(speed_of_sound_in_diamonds,   12'000, meters_per_second);

// Mathematical constants
SET(pi,           3.14159265358979323846, radian); // (symbol: π)
SET(half_pi,      1.57079632679489661923, radian);
SET(quarter_pi,   0.78539816339744830961, radian);
SET(tau,          6.28318530717958647692, radian); // (symbol: τ)
SET(phi,          1.61803398874989484820, dimensionless); // (symbol: φ)
SET(Eulers_number,2.71828182845904523536, dimensionless);

//SET(σ_e,                 6.6524587e-29, meter2); // Thomson cross section
//SET(σ,                  5.670374419e-8, units::W / units::m2 / units::K2); // Stefan–Boltzmann constant
//SET(α,                    7.2973525e-3, dimensionless); // fine-structure constant
//SET(α_inv,               137.035999084, dimensionless); // inverse fine-structure constant
//SET(sin2θ_W,                   0.22290, dimensionless); // weak mixing angle

// Astronomical constants
SET(AU,                  149'597'870'691, meter); // astronomical unit
SET(parsec,       30'856'775'814'913'700, meter); // Parsec (symbol: pc)
SET(lightyear,     9'460'730'777'119'564, meter); 
//SET(Hubble,                       70.1, /*km s−1 Mpc−1*/); // symbol: H0

// Various constants
SET(Marathon_length,              42'195, meter);
SET(quarter_mile,                 402.34, meter);

} } // SI::constant
#undef SET

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
// 2. https://en.wikipedia.org/wiki/List_of_physical_constants
// 3. https://en.wikipedia.org/wiki/List_of_mathematical_constants
// 4. https://en.wikipedia.org/wiki/Astronomical_constant

