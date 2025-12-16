// SI/constants.hpp - contains constants in SI units
#pragma once
#include "types.hpp"
#define CONST(_name, _value, _unit)  static constexpr auto _name = _unit(_value)

namespace si
{
	namespace constant
	{
// The 7 defining constants of SI:
CONST( speed_of_light, 299'792'458, meters_per_second); // speed of light in vacuum
CONST( c,              299'792'458, meters_per_second);
//CONST( h,            6.62607e-34, units::J * units::s); // Planck constant
//CONST( e,           1.602176e-19, units::C); // elementary charge
CONST( Δν_Cs,        9'192'631'770, hertz); // hyperfine transition frequency of cesium-133 (defines the SI second)
CONST( k,            1.380'649e-23, joules_per_kelvin); // Boltzmann constant
//CONST( N_A,          6.02214076e23, 1 / units::mol; // Avogadro constant
CONST( K_cd,                   683, lumens_per_watt); // luminous efficacy of 540 THz monochromatic radiation

// Universal constants
//CONST( Z_0,          376.730313667, units::Ohm); // characteristic impedance of vacuum
//CONST( epsilon_0    8.854'187'817'620'39e-12, units::F / units::m); // electric constant (vacuum permittivity)
//CONST( mu_0        1.256'637'06e-6, units::N / units::A2); // magnetic constant (vacuum permeability)
//CONST( G               6.67408e-11, units::m3 / units::kg / units::s2); // Newtonian constant of gravitation
//CONST( h_bar     1.054'571'817e-34, units::J * units::s); // reduced Planck constant

// Electromagnetic constants
//CONST( mu_B,         9.2740100e-24, units::J / units::T); // Bohr magneton
//CONST( G_0,         7.748091729e-5, units::S); // conductance quantum
//CONST( K_Jm90,             48359e9, units::Hz / units::V); // conventional value of Josephson constant[30]
//CONST( R_Km90,           25812.807, units::Ohm); // conventional value of von Klitzing constant[32]
//CONST( G_0_inv,        12906.40372, units::Ohm); // inverse conductance quantum
//CONST( K_J,          483597.8484e9, units::Hz / units::V); // Josephson constant
//CONST( Phi_0,      2.067833848e-15, units::Wb); // magnetic flux quantum
//CONST( mu_N,         5.0507837e-27, units::J / units::T); // nuclear magneton
//CONST( R_K,            25812.80745, units::Ohm); // von Klitzing constant
//CONST( k_e,    1.0 / (4*M_PI*epsilon_0);

// Atomic and nuclear constants
CONST( electron_mass, 9.1093837139e-31, kilogram);
CONST( m_e,           9.1093837139e-31, kilogram); // electron mass
CONST( muon_mass,      1.883531627e-28, kilogram);
CONST( tau_mass,           3.16754e-27, kilogram);
CONST( proton_mass,  1.67262192595e-27, kilogram);
CONST( m_p,          1.67262192595e-27, kilogram);
CONST( neutron_mass, 1.67492750056e-27, kilogram);
CONST( a_0,             5.29177210e-11, meter); // Bohr radius
CONST( r_e,              2.8179403e-15, meter); // classical electron radius
CONST( g_e,          -2.00231930436256, quantity); // electron g-factor
CONST( alpha,             7.2973525e-3, quantity); // fine-structure constant
CONST( alpha_inv,        137.035999084, quantity); // inverse fine-structure constant
CONST( E_h,           4.3597447222e-18, joule); // Hartree energy
CONST( sin2Theta_W,            0.22290, quantity); // weak mixing angle
//CONST( G0_F,               1.1663e-5, / units::GeV  / units::GeV); // Fermi coupling constant
//CONST( h_2me,           3.6369475e-4, units::m2 / units::s); // quantum of circulation
//CONST( R_inf,        10973731.568160, / units::m); // Rydberg constant
CONST( sigma_e,          6.6524587e-29, meter2); // Thomson cross section

// Physico-chemical constants
const auto m_u = kilogram(1.66053906e-27); // Atomic mass constant
//CONST( F, 96485.33212 * units::C / units::mol; // Faraday constant
//CONST( c_1,   3.741771852e-16 * units::W * units::m2; // first radiation constant
//CONST( c_1L,    1.191042972e-16 * units::W * units::m2 / units::sr; // first radiation constant for spectral radiance
//CONST( n_0,    2.651645804e25 / units::m3; // Loschmidt constant
//CONST( R,   8.314462618 * units::J / units::mol / units::K; // gas constant
//CONST( N_Ah,   3.990312712e-10 * units::J / units::Hz / units::mol; // molar Planck constant
//CONST( M_u,   0.99999999e-3 * units::kg / units::mol; // molar mass constant
//CONST( V_m,   22.71095464e-3 * units::m3 / units::mol; // molar volume of an ideal gas
//CONST( c_2,   1.438776877e-2 * units::m * units::K; // second radiation constant
//CONST( sigma,   5.670374419e-8 * units::W / units::m2 / units::K2; // Stefan–Boltzmann constant
//CONST( b,   2.897771955e-3 * units::m * units::K; // Wien wavelength displacement law constant
//CONST( b_prime,  5.878925757e10 * units::Hz / units::K; // Wien frequency displacement law constant
CONST( S_0_by_R,    -1.15170753706,  quantity); // Sackur–Tetrode constant

// Adopted values
//CONST( atm,    101325 * units::Pa; // standard atmosphere
   
// Physical constants: (source: https://en.wikipedia.org/wiki/List_of_physical_constants)
CONST( speed_of_sound, 343,  meters_per_second); // speed of sound in air at 20 °C (68 °F)
CONST( standard_gravity, 9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).
CONST( g_0,              9.80665, meters_per_second2); // standard acceleration of gravity
//CONST( Gravitational_constant, 6.6743015e−11, * si::m3 / si::kilogram / si::s2);

// Mathematical constants:  (source: https://en.wikipedia.org/wiki/List_of_mathematical_constants)
CONST( half_pi,             90, degree);
CONST( pi,                 180, degree);
CONST( π,                  180, degree);
CONST( tau,                360, degree);

#if defined(__clang__) || defined(_MSC_VER)
CONST( ε_0,      8.8541878e-12, units::F / units::m); // electric constant (vacuum permittivity)
CONST( μ_0,      1.25663706e-6, units::N / units::A2); // magnetic constant (vacuum permeability)
CONST( auto ℏ, 1.054571817e-34, units::J * units::s); // reduced Planck constant
CONST( μ_B,      9.2740100e-24, units::J / units::T); // Bohr magneton
CONST( Φ_0,    2.067833848e-15, units::Wb); // magnetic flux quantum
CONST( μ_N,      5.0507837e-27, units::J / units::T); // nuclear magneton
CONST( σ_e,      6.6524587e-29, units::m2); // Thomson cross section
CONST( σ,       5.670374419e-8, units::W / units::m2 / units::K2); // Stefan–Boltzmann constant
#endif
CONST( α,         7.2973525e-3, quantity); // fine-structure constant
CONST( α_inv,    137.035999084, quantity); // inverse fine-structure constant
CONST( sin2θ_W,        0.22290, quantity); // weak mixing angle

// Astronomical constants:
CONST( AU,         149.5978707e6,   kilometer);
CONST( lightyear,  9460730472580.8, kilometer); 
CONST( parsec,     3.2 * lightyear, meter); // symbol: pc

// Various constants:
CONST( Marathon_length, 42195, meter);
CONST( min_temperature,     0, kelvin);

	}
}

#undef CONST
