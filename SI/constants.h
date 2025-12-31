// SI/constants.h - type-safe constants based on SI units
#pragma once

#include "units.h"
#define CONST(_name, _value, _unit) const auto _name = _unit(_value)
#define UNICODE(_name, _value, _unit) // contains non-ASCII characters (not supported yet)
#define TODO(_name, _value, _unit)    // to be done

namespace SI
{
	namespace constant
	{
// The 7 defining constants of SI (as of 20 May 2019)
CONST( caesium_frequency,     9'192'631'770, hertz); // the unperturbed ground state hyperfine transition frequency of the ceesium-133 atom
CONST( delta_ν_Cs,            9'192'631'770, hertz); // (the symbol)
CONST( speed_of_light,          299'792'458, meters_per_second); // the speed of light in vacuum
CONST( c,                       299'792'458, meters_per_second); // (the symbol)
CONST( Planck,             6.626'070'15e-34, joulesecond); // the Planck constant
CONST( h,                  6.626'070'15e-34, joulesecond); // (the symbol)
CONST( elementary_charge, 1.602'176'634e-19, coulomb); // the elementary charge
CONST( e,                 1.602'176'634e-19, coulomb); // (the symbol)
CONST( Boltzmann,             1.380'649e-23, joules_per_kelvin); // the Boltzmann constant
CONST( k,                     1.380'649e-23, joules_per_kelvin); // (the symbol)
CONST( N_A,                   6.02214076e23, per_mol); // the Avogadro constant
CONST( K_cd,                            683, lumens_per_watt); // the luminous efficacy of monochromatic radiation of frequency 540 THz

// Universal constants
CONST( min_temperature,          0, kelvin); // the lowest possible temperature (Absolute zero)
CONST( Z_0,          376.730313667, ohm); // characteristic impedance of vacuum
CONST( epsilon_0,   8.854'187'817'620'39e-12, farads_per_meter); // electric constant (vacuum permittivity)
UNICODE( ε_0,       8.854'187'817'620'39e-12, farads_per_meter); // (the symbol)
TODO( mu_0,        1.256'637'06e-6, units::N / units::A2); // magnetic constant (vacuum permeability)
UNICODE( μ_0,      1.256'637'06e-6, units::N / units::A2); // (the symbol)
TODO( G,               6.67408e-11, units::m3 / units::kg / units::s2); // Newtonian constant of gravitation
CONST( h_bar,    1.054'571'817e-34, joulesecond); // reduced Planck constant

// Electromagnetic constants
CONST( mu_B,         9.2740100e-24, joules_per_tesla); // Bohr magneton
UNICODE( μ_B,        9.2740100e-24, joules_per_tesla); // (the symbol)
CONST( G_0,         7.748091729e-5, siemens); // conductance quantum
TODO( K_Jm90,              48359e9, units::Hz / units::V); // conventional value of Josephson constant
CONST( R_Km90,           25812.807, ohm); // conventional value of von Klitzing constant
CONST( G_0_inv,        12906.40372, ohm); // inverse conductance quantum
TODO( K_J,           483597.8484e9, units::Hz / units::V); // Josephson constant
CONST( Phi_0,      2.067833848e-15, weber); // magnetic flux quantum
UNICODE( Φ_0,      2.067833848e-15, weber); // (the symbol)
CONST( mu_N,         5.0507837e-27, joules_per_tesla); // nuclear magneton
UNICODE( μ_N,        5.0507837e-27, joules_per_tesla); // (the symbol)
CONST( R_K,            25812.80745, ohm); // von Klitzing constant
TODO( k_e,1.0 / (4*M_PI*epsilon_0), quantity);

// Atomic and nuclear constants
CONST( electron_mass, 9.1093837139e-31, kilogram);
CONST( m_e,           9.1093837139e-31, kilogram); // electron mass
CONST( muon_mass,      1.883531627e-28, kilogram);
CONST( tau_mass,           3.16754e-27, kilogram);
CONST( proton_mass,  1.67262192595e-27, kilogram);
CONST( m_p,          1.67262192595e-27, kilogram);
CONST( neutron_mass, 1.67492750056e-27, kilogram);
CONST( a_0,             5.29177210e-11, meter);    // Bohr radius
CONST( r_e,              2.8179403e-15, meter);    // classical electron radius
CONST( g_e,          -2.00231930436256, quantity); // electron g-factor
CONST( alpha,             7.2973525e-3, quantity); // fine-structure constant
CONST( alpha_inv,        137.035999084, quantity); // inverse fine-structure constant
CONST( E_h,           4.3597447222e-18, joule);    // Hartree energy
CONST( sin2Theta_W,            0.22290, quantity); // weak mixing angle
TODO( G0_F,                  1.1663e-5, / units::GeV  / units::GeV); // Fermi coupling constant
TODO( h_2me,              3.6369475e-4, units::m2 / units::s); // quantum of circulation
CONST( R_inf,          10973731.568160, per_meter); // Rydberg constant
CONST( sigma_e,          6.6524587e-29, meter2); // Thomson cross section

// Physico-chemical constants
CONST( m_u,       1.66053906e-27, kilogram); // Atomic mass constant
CONST( F,            96485.33212, coulombs_per_mol); // Faraday constant
TODO( c_1,       3.741771852e-16, units::W * units::m2); // first radiation constant
TODO( c_1L,      1.191042972e-16, units::W * units::m2 / units::sr); // first radiation constant for spectral radiance
TODO( n_0,        2.651645804e25, / units::m3); // Loschmidt constant
TODO( R,             8.314462618, units::J / units::mol / units::K); // gas constant
TODO( N_Ah,      3.990312712e-10, units::J / units::Hz / units::mol); // molar Planck constant
TODO( M_u,         0.99999999e-3, kilograms_per_mol); // molar mass constant
TODO( V_m,        22.71095464e-3, units::m3 / units::mol); // molar volume of an ideal gas
TODO( c_2,        1.438776877e-2, units::m * units::K); // second radiation constant
TODO( sigma,      5.670374419e-8, units::W / units::m2 / units::K2); // Stefan–Boltzmann constant
TODO( b,          2.897771955e-3, units::m * units::K); // Wien wavelength displacement law constant
TODO( b_prime,    5.878925757e10, units::Hz / units::K); // Wien frequency displacement law constant
CONST( S_0_by_R,  -1.15170753706, quantity); // Sackur–Tetrode constant

// Adopted values
CONST( atm,               101325, pascal_); // standard atmosphere
   
// Physical constants
CONST( standard_gravity,   9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).
CONST( g_0,                9.80665, meters_per_second2); // standard acceleration of gravity
TODO( Gravitational_constant,  /*6.6743015e−11*/, /*si::m3 / si::kilogram / si::s2*/);
CONST( speed_of_sound,         343, meters_per_second); // speed of sound in dry air at 20°C (68°F)
CONST( speed_of_sound_in_fresh_water, 1481, meters_per_second); // at 20°C (68°F)
CONST( speed_of_sound_in_iron, 5120, meters_per_second);
CONST( speed_of_sound_in_diamonds, 12'000, meters_per_second);

// Mathematical constants
CONST(   pi,            3.14159265358979323846, radian);
UNICODE( π,             3.14159265358979323846, radian); // (symbol for pi)
CONST(   half_pi,       1.57079632679489661923, radian);
CONST(   quarter_pi,    0.78539816339744830961, radian);
CONST(   tau,           6.28318530717958647692, radian);
UNICODE( τ,             6.28318530717958647692, radian); // (symbol for tau)
CONST(   phi,           1.61803398874989484820, quantity);
UNICODE( φ,             1.61803398874989484820, quantity); // (symbol for phi)
CONST(   Eulers_number, 2.71828182845904523536, quantity);

UNICODE( σ_e,         6.6524587e-29, meter2); // Thomson cross section
UNICODE( σ,          5.670374419e-8, units::W / units::m2 / units::K2); // Stefan–Boltzmann constant
UNICODE( α,         7.2973525e-3, quantity); // fine-structure constant
UNICODE( α_inv,    137.035999084, quantity); // inverse fine-structure constant
UNICODE( sin2θ_W,        0.22290, quantity); // weak mixing angle

// Astronomical constants
CONST( AU,              149'597'870'691, meter); // astronomical unit
CONST( parsec,   30'856'775'814'913'700, meter); // Parsec (symbol: pc)
CONST( lightyear, 9'460'730'777'119'564, meter); 
TODO( Hubble,                      70.1, /*km s−1 Mpc−1*/); // symbol: H0

// Various constants
CONST( Marathon_length,           42'195, meter);
CONST( quarter_mile,              402.34, meter);

	}
}

// Sources
// -------
// * https://en.wikipedia.org/wiki/International_System_of_Units
// * https://en.wikipedia.org/wiki/List_of_physical_constants
// * https://en.wikipedia.org/wiki/List_of_mathematical_constants
// * https://en.wikipedia.org/wiki/Astronomical_constant

#undef CONST
#undef UNICODE
#undef TODO
