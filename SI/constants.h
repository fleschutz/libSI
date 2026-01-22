// <SI/constants.h> - type-safe constants based on SI units
#pragma once

#include "units.h"

namespace SI { namespace constant {

#define CONSTANT(_name, _value, _base_unit) const auto _name = _base_unit(_value)

// The 7 defining constants of SI (as of 20 May 2019)
CONSTANT(caesium_frequency,     9'192'631'770, hertz); // the unperturbed ground state hyperfine transition frequency of the ceesium-133 atom
CONSTANT(delta_v_Cs,            9'192'631'770, hertz); // (the symbol)
CONSTANT(speed_of_light,          299'792'458, meters_per_second); // the speed of light in vacuum
CONSTANT(c,                       299'792'458, meters_per_second); // (the symbol)
CONSTANT(Planck,             6.626'070'15e-34, jouleseconds); // the Planck constant
CONSTANT(h,                  6.626'070'15e-34, jouleseconds); // (the symbol)
CONSTANT(elementary_charge, 1.602'176'634e-19, coulombs); // the elementary charge
CONSTANT(e,                 1.602'176'634e-19, coulombs); // (the symbol)
CONSTANT(Boltzmann,             1.380'649e-23, joules_per_kelvin); // the Boltzmann constant
CONSTANT(k,                     1.380'649e-23, joules_per_kelvin); // (the symbol)
CONSTANT(N_A,                   6.02214076e23, per_mol); // the Avogadro constant
CONSTANT(K_cd,                            683, lumens_per_watt); // the luminous efficacy of monochromatic radiation of frequency 540 THz

// Universal constants
CONSTANT(min_temperature,                   0, kelvins); // the lowest possible temperature (Absolute zero)
CONSTANT(Z_0,                   376.730313667, ohms); // characteristic impedance of vacuum
CONSTANT(epsilon_0,  8.854'187'817'620'39e-12, farads_per_meter); // electric constant (vacuum permittivity, symbol: ε_0)
//CONSTANT(mu_0,              1.256'637'06e-6, units::N / units::A2); // magnetic constant (vacuum permeability, symbol: μ_0)
CONSTANT(G,                       6.67408e-11, meters3_per_kilogram_per_second2); // Newtonian constant of gravitation
CONSTANT(h_bar,             1.054'571'817e-34, jouleseconds); // reduced Planck constant

// Electromagnetic constants
CONSTANT(mu_B,                  9.2740100e-24, joules_per_tesla); // Bohr magneton (symbol: µB)
CONSTANT(G_0,                  7.748091729e-5, siemens); // conductance quantum
//CONSTANT(K_Jm90,                    48359e9, units::Hz / units::V); // conventional value of Josephson constant
CONSTANT(R_Km90,                    25812.807, ohms); // conventional value of von Klitzing constant
CONSTANT(G_0_inv,                 12906.40372, ohms); // inverse conductance quantum
//CONSTANT(K_J,                 483597.8484e9, units::Hz / units::V); // Josephson constant
CONSTANT(Phi_0,               2.067833848e-15, webers); // magnetic flux quantum (symbol: Φ_0)
CONSTANT(mu_N,                  5.0507837e-27, joules_per_tesla); // nuclear magneton (symbol: μ_N)
CONSTANT(R_K,                     25812.80745, ohms); // von Klitzing constant
//CONSTANT(k_e,      1.0 / (4*M_PI*epsilon_0), dimensionless);

// Atomic and nuclear constants
CONSTANT(electron_mass,      9.1093837139e-31, kilograms);
CONSTANT(m_e,                9.1093837139e-31, kilograms); // electron mass
CONSTANT(muon_mass,           1.883531627e-28, kilograms);
CONSTANT(tau_mass,                3.16754e-27, kilograms);
CONSTANT(proton_mass,       1.67262192595e-27, kilograms);
CONSTANT(m_p,               1.67262192595e-27, kilograms);
CONSTANT(neutron_mass,      1.67492750056e-27, kilograms);
CONSTANT(a_0,                  5.29177210e-11, meters);   // Bohr radius
CONSTANT(r_e,                   2.8179403e-15, meters);   // classical electron radius
CONSTANT(g_e,               -2.00231930436256, dimensionless); // electron g-factor
CONSTANT(alpha,                  7.2973525e-3, dimensionless); // fine-structure constant
CONSTANT(alpha_inv,             137.035999084, dimensionless); // inverse fine-structure constant
CONSTANT(E_h,                4.3597447222e-18, joules);    // Hartree energy
CONSTANT(sin2Theta_W,                 0.22290, dimensionless); // weak mixing angle
CONSTANT(h_2me,                  3.6369475e-4, meters2_per_second); // quantum of circulation
CONSTANT(R_inf,               10973731.568160, per_meter); // Rydberg constant
CONSTANT(sigma_e,               6.6524587e-29, meters2); // Thomson cross section (symbol: σ_e)

// Physico-chemical constants
CONSTANT(m_u,                  1.66053906e-27, kilograms); // Atomic mass constant
CONSTANT(F,                       96485.33212, coulombs_per_mol); // Faraday constant
CONSTANT(c_1,                 3.741771852e-16, wattmeters2); // first radiation constant
CONSTANT(c_1L,                1.191042972e-16, watts_per_meter2); // first radiation constant for spectral radiance
//CONSTANT(n_0,                2.651645804e25, / units::m3); // Loschmidt constant
CONSTANT(R,                       8.314462618, joules_per_kelvin_per_mol); // gas constant
CONSTANT(R_dry_air,              287.050'0676, joules_per_kilogram_per_kelvin); // specific gas constant for dry air
//CONSTANT(N_Ah,              3.990312712e-10, units::J / units::Hz / units::mol); // molar Planck constant
//CONSTANT(M_u,                 0.99999999e-3, kilograms_per_mol); // molar mass constant
//CONSTANT(V_m,                22.71095464e-3, units::m3 / units::mol); // molar volume of an ideal gas
//CONSTANT(c_2,                1.438776877e-2, units::m * units::K); // second radiation constant
//CONSTANT(sigma,              5.670374419e-8, units::W / units::m2 / units::K2); // Stefan–Boltzmann constant
CONSTANT(b,                    2.897771955e-3, meter_kelvins); // Wien wavelength displacement law constant
//CONSTANT(b_prime,            5.878925757e10, units::Hz / units::K); // Wien frequency displacement law constant
CONSTANT(S_0_by_R,             -1.15170753706, dimensionless); // Sackur–Tetrode constant

// Adopted values
CONSTANT(atm,                          101325, pascals); // standard atmosphere
   
// Physical constants
CONSTANT(standard_gravity,            9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).
CONSTANT(g_0,                         9.80665, meters_per_second2); // (the symbol)
CONSTANT(gravitational_constant,6.6743015e-11, meters3_per_kilogram_per_second2);
CONSTANT(speed_of_sound,                  343, meters_per_second); // speed of sound in dry air at 20°C (68°F)
CONSTANT(speed_of_sound_in_fresh_water,  1481, meters_per_second); // at 20°C (68°F)
CONSTANT(speed_of_sound_in_iron,         5120, meters_per_second);
CONSTANT(speed_of_sound_in_diamonds,   12'000, meters_per_second);

// Mathematical constants
CONSTANT(pi,           3.14159265358979323846, radians); // (symbol: π)
CONSTANT(half_pi,      1.57079632679489661923, radians);
CONSTANT(quarter_pi,   0.78539816339744830961, radians);
CONSTANT(tau,          6.28318530717958647692, radians); // (symbol: τ)
CONSTANT(phi,          1.61803398874989484820, dimensionless); // (symbol: φ)
CONSTANT(Eulers_number,2.71828182845904523536, dimensionless);

// Astronomical constants
CONSTANT(AU,                  149'597'870'691, meters); // astronomical unit (symbol: au)
CONSTANT(parsec,       30'856'775'814'913'700, meters); // Parsec (symbol: pc)
CONSTANT(lightyear,     9'460'730'777'119'564, meters); 

// Various constants
CONSTANT(Marathon_length,              42'195, meters);
CONSTANT(quarter_mile,                 402.34, meters);

#undef CONSTANT
} } // SI::constant
 
// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
// 2. https://en.wikipedia.org/wiki/List_of_physical_constants
// 3. https://en.wikipedia.org/wiki/List_of_mathematical_constants
// 4. https://en.wikipedia.org/wiki/Astronomical_constant

