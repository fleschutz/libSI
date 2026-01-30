// <SI/constants.h> - type-safe constants based on SI units, e.g. SI::constant::G
//                    (sorted by: defined, universal, electromagnetic, atomic and nuclear, physico-chemical,...)
#pragma once
#include <SI/units.h>

namespace SI { namespace constant {

#define CONSTANT(_name, _value, _base_unit) const auto _name = _base_unit(_value)

// +++ DEFINED CONSTANTS +++
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
CONSTANT(g_n,                        9.806'65, meters_per_second2); // standard acceleration of gravity (2022 CODATA)
CONSTANT(atm,                         101'325, pascals); // standard atmosphere (2022 CODATA)
CONSTANT(ssp,                         100'000, pascals); // standard-state pressure (2022 CODATA)

// +++ UNIVERSAL CONSTANTS +++
CONSTANT(G,                       6.67430e-11, meters3_per_kilogram_per_second2); // Newtonian constant of gravitation (2022 CODATA)
CONSTANT(Z_0,                 376.730'313'412, ohms); // characteristic impedance of vacuum (2022 CODATA)
CONSTANT(epsilon_0,        8.854'187'8188e-12, farads_per_meter); // vacuum electric permittivity, symbol: ε_0, 2022 CODATA)
CONSTANT(l_P,                    1.616255e-35, meters); // Planck length (2022 CODATA)
CONSTANT(m_P,                     2.176434e-8, kilograms); // Planck mass (2022 CODATA)
CONSTANT(T_P,                     1.416784e32, kelvins); // Planck temperature (2022 CODATA)
CONSTANT(t_P,                    5.391247e-44, seconds); // Planck time (2022 CODATA)
CONSTANT(h_bar,             1.054'571'817e-34, jouleseconds); // reduced Planck constant (2022 CODATA)
CONSTANT(mu_0,            1.256'637'061'27e-6, newtons_per_ampere2); // vacuum magnetic permeability (2022 CODATA)

// +++ ELECTROMAGNETIC CONSTANTS +++
CONSTANT(mu_B,                  9.2740100e-24, joules_per_tesla); // Bohr magneton (symbol: µB)
CONSTANT(G_0,                  7.748091729e-5, siemens); // conductance quantum
CONSTANT(R_Km90,                    25812.807, ohms); // conventional value of von Klitzing constant
CONSTANT(G_0_inv,                 12906.40372, ohms); // inverse conductance quantum
CONSTANT(Phi_0,               2.067833848e-15, webers); // magnetic flux quantum (symbol: Φ_0)
CONSTANT(mu_N,                  5.0507837e-27, joules_per_tesla); // nuclear magneton (symbol: μ_N)
CONSTANT(R_K,                     25812.80745, ohms); // von Klitzing constant

// +++ ATOMIC AND NUCLEAR CONSTANTS +++
CONSTANT(a_0,            5.291'772'105'44e-11, meters);   // Bohr radius (2022 CODATA)
CONSTANT(alpha,                  7.2973525e-3, dimensionless); // fine-structure constant
CONSTANT(alpha_inv,           137.035'999'177, dimensionless); // inverse fine-structure constant (2022 CODATA)
CONSTANT(E_h,                4.3597447222e-18, joules);    // Hartree energy
CONSTANT(g_e,               -2.00231930436256, dimensionless); // electron g-factor
CONSTANT(h_2me,                  3.6369475e-4, meters2_per_second); // quantum of circulation
CONSTANT(m_e,              9.109'383'7139e-31, kilograms); // electron mass (2022 CODATA)
CONSTANT(m_d,              3.343'583'7768e-27, kilograms); // deuteron mass (2022 CODATA)
CONSTANT(m_h,              5.006'412'7862e-27, kilograms); // helion mass (2022 CODATA)
CONSTANT(m_mu,              1.883'531'627e-28, kilograms); // muon mass (2022 CODATA)
CONSTANT(m_n,            1.674'927'500'56e-27, kilograms); // neutron mass (2022 CODATA)
CONSTANT(m_p,            1.672'621'925'95e-27, kilograms); // proton mass (2022 CODATA)
CONSTANT(m_tau,                  3.167'54e-27, kilograms); // tau mass (2022 CODATA)
CONSTANT(m_t,              5.007'356'7512e-27, kilograms); // triton mass (2022 CODATA)
CONSTANT(r_e,              2.817'940'3205e-15, meters); // classical electron radius (2022 CODATA)
CONSTANT(R_inf,            10'973'731.568'157, per_meter); // Rydberg constant (2022 CODATA)
CONSTANT(sin2Theta_W,                 0.22290, dimensionless); // weak mixing angle
CONSTANT(sigma_e,               6.6524587e-29, meters2); // Thomson cross section (symbol: σ_e)

// +++ PHYSICO-CHEMICAL CONSTANTS +++
CONSTANT(b,                    2.897771955e-3, meter_kelvins); // Wien wavelength displacement law constant
CONSTANT(c_1,                 3.741771852e-16, wattmeters2); // first radiation constant
CONSTANT(c_1L,                1.191042972e-16, watts_per_meter2); // first radiation constant for spectral radiance
CONSTANT(F,                     96'485.332'12, coulombs_per_mol); // Faraday constant (2022 CODATA)
CONSTANT(m_u,                  1.66053906e-27, kilograms); // Atomic mass constant
CONSTANT(M_u,             1.000'000'001'05e-3, kilograms_per_mol); // molar mass constant (2022 CODATA)
CONSTANT(R,                     8.314'462'618, joules_per_kelvin_per_mol); // molar gas constant (2022 CODATA)
CONSTANT(R_dry_air,              287.050'0676, joules_per_kilogram_per_kelvin); // specific gas constant for dry air
CONSTANT(S_0_by_R,             -1.15170753706, dimensionless); // Sackur–Tetrode constant
CONSTANT(V_m,                22.710'954'64e-3, meters3_per_mol); // molar volume of ideal gas (273.15K, 100kPa, 2022 CODATA)

// +++ PHYSICAL CONSTANTS +++
CONSTANT(standard_gravity,            9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).
CONSTANT(gravitational_constant,6.6743015e-11, meters3_per_kilogram_per_second2);
CONSTANT(speed_of_sound,                  343, meters_per_second); // speed of sound in dry air at 20°C (68°F)
CONSTANT(speed_of_sound_in_fresh_water,  1481, meters_per_second); // at 20°C (68°F)
CONSTANT(speed_of_sound_in_iron,         5120, meters_per_second);
CONSTANT(speed_of_sound_in_diamonds,   12'000, meters_per_second);

// +++ MATHEMATICAL CONSTANTS +++
CONSTANT(tau,          6.28318530717958647692, radians); // (symbol: τ)
CONSTANT(pi,           3.14159265358979323846, radians); // (symbol: π)
CONSTANT(half_pi,      1.57079632679489661923, radians); // (π / 2)
CONSTANT(quarter_pi,   0.78539816339744830961, radians); // (π / 4)
CONSTANT(phi,          1.61803398874989484820, dimensionless); // (symbol: φ)
CONSTANT(Eulers_number,2.71828182845904523536, dimensionless);

// +++ ASTRONOMICAL CONSTANTS +++
CONSTANT(AU,                  149'597'870'691, meters); // one astronomical unit (symbol: au)
CONSTANT(parsec,       30'856'775'814'913'700, meters); // one Parsec (symbol: pc)
CONSTANT(lightyear,     9'460'730'777'119'564, meters); // one light-year (symbol: ly)

// +++ VARIOUS CONSTANTS +++
CONSTANT(min_temperature,                   0, kelvins); // the lowest possible temperature (absolute zero)
CONSTANT(Marathon_distance,            42'195, meters);
CONSTANT(quarter_mile,                 402.34, meters);

#undef CONSTANT
} } // namespace SI::constant
 
// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
// 2. https://en.wikipedia.org/wiki/List_of_physical_constants
// 3. https://en.wikipedia.org/wiki/List_of_mathematical_constants
// 4. https://en.wikipedia.org/wiki/Astronomical_constant
// 5. https://codata.org - CODATA: the committee on data of the International Science Council (ISC)
