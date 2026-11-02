/// @file     SI/constants.h
/// @brief    Defines 78 type-safe constants based on libSI's datatypes and units
/// @details  Categories are: defined constants, universal constants, electromagnetic constants,
///                           atomic & nuclear constants, physico-chemical constants, physical constants,
///                           mathematical constants, astronomical constants, various constants, and references.

#pragma once
#include <SI/units.h>

namespace SI { 

  constexpr struct { // CODATA 2022 constants

    // Defined Constants
    // -----------------
    frequency caesium_frequency =                   hertz(9'192'631'770); // the unperturbed ground state hyperfine transition frequency of the ceesium-133 atom
    velocity speed_of_light_in_vacuum = meters_per_second(299'792'458.0); // the speed of light in vacuum (symbol: c)
    velocity c =                        meters_per_second(299'792'458.0); // the speed of light in vacuum (symbol: c)
    //TBD: planck,             6.626'070'15e-34, jouleseconds); // Planck constant (symbol: h)
    electric_charge elementary_charge      = coulombs(1.602'176'634e-19); // the elementary charge (symbol: e)
    //TBD: boltzmann,             1.380'649e-23, joules_per_kelvin); // Boltzmann constant (symbol: k)
    per_substance avogadro =                      per_mol(6.02214076e23); // Avogadro constant (symbol: N_A)
    //TBD: K_cd,                            683, lumens_per_watt); // the luminous efficacy of monochromatic radiation of frequency 540 THz
    acceleration g_n  =                     meters_per_second2(9.806'65); // standard acceleration of gravity
    pressure atm =                                      pascals(101'325); // standard atmosphere
    pressure ssp =                                      pascals(100'000); // standard-state pressure

    // Universal Constants
    // -------------------
    //TBD: Z_0,                376.730'313'412, ohms); // characteristic impedance of vacuum
    //TBD: epsilon_0,       8.854'187'8188e-12, farads_per_meter); // vacuum electric permittivity, symbol: ε_0
    length l_P =          meters(1.616255e-35); // Planck length
    mass m_P =          kilograms(2.176434e-8); // Planck mass
    temperature T_P =     kelvins(1.416784e32); // Planck temperature
    SI::time t_P =       seconds(5.391247e-44); // Planck time
    //TBD:h_bar,             1.054'571'817e-34, jouleseconds); // reduced Planck constant
    //TBD:mu_0,            1.256'637'061'27e-6, newtons_per_ampere2); // vacuum magnetic permeability

    // Electromagnetic Constants
    // -------------------------
    //TBD: G_0,                7.748'091'729e-5, siemens); // conductance quantum
    //TBD: G_0_inv,                 12906.40372, ohms); // inverse conductance quantum
    //TBD: K_J,                 483'597.848'4e9, hertz_per_volt); // Josephson constant
    //TBD: mu_B,             9.274'010'0657e-24, joules_per_tesla); // Bohr magneton (symbol: µB)
    //TBD: mu_N,             5.050'783'7393e-27, joules_per_tesla); // nuclear magneton (symbol: μ_N)
    //TBD: Phi_0,               2.067833848e-15, webers); // magnetic flux quantum (symbol: Φ_0)
    //TBD: R_K,                   25'812.807'45, ohms); // von Klitzing constant
    //TBD: R_Km90,                    25812.807, ohms); // conventional value of von Klitzing constant

    // Atomic & Nuclear Constants
    // --------------------------
    length        a_0 =   meters(5.291'772'105'44e-11); // Bohr radius
    dimensionless alpha =                 7.2973525e-3; // fine-structure constant
    dimensionless alpha_inv =          137.035'999'177; // inverse fine-structure constant
    energy        E_h =       joules(4.3597447222e-18); // Hartree energy
    dimensionless g_e =              -2.00231930436256; // electron g-factor
    mass          m_e =  kilograms(9.109'383'7139e-31); // electron mass
    mass          m_d =  kilograms(3.343'583'7768e-27); // deuteron mass
    mass          m_h =  kilograms(5.006'412'7862e-27); // helion mass
    mass          m_mu =  kilograms(1.883'531'627e-28); // muon mass
    mass          m_n =kilograms(1.674'927'500'56e-27); // neutron mass
    mass          m_p =kilograms(1.672'621'925'95e-27); // proton mass
    mass          m_tau =      kilograms(3.167'54e-27); // tau mass
    mass          m_t =  kilograms(5.007'356'7512e-27); // triton mass
    length        r_e =     meters(2.817'940'3205e-15); // classical electron radius
    dimensionless sin2Theta_W =                0.22290; // weak mixing angle
    area          sigma_e =     meters2(6.6524587e-29); // Thomson cross section (symbol: σ_e)

    // Physico-chemical Constants
    // --------------------------
    //TBD: b,                    2.897771955e-3, meter_kelvins); // Wien wavelength displacement law constant
    //TBD: c_1,                 3.741771852e-16, wattmeters2); // first radiation constant
    //TBD: c_1L,                1.191042972e-16, watts_per_meter2); // first radiation constant for spectral radiance
    //TBD: F,                     96'485.332'12, coulombs_per_mol); // Faraday constant
    mass m_u = kilograms(1.660'539'068'9252e-27); // atomic mass constant
    //TBD: M_u,             1.000'000'001'05e-3, kilograms_per_mol); // molar mass constant
    dimensionless S_0_by_R =     -1.15170753706; // Sackur–Tetrode constant
    //TBD: V_m,                22.710'954'64e-3, meters3_per_mol); // molar volume of ideal gas (273.15K, 100kPa)
  } CODATA;

  // Mathematical Constants 
  // ----------------------
  constexpr struct { 
    dimensionless root_2 =     1.41421356237309504880; // Pythagoras' constant (square root of 2)
    dimensionless tau =        6.28318530717958647692; // 2π (symbol: τ)
    dimensionless pi =         3.14159265358979323846; // Archimedes' constant (symbol: π)
    dimensionless half_pi =    1.57079632679489661923; // π / 2
    dimensionless quarter_pi = 0.78539816339744830961; // π / 4
    dimensionless e =          2.71828182845904523536; // Euler's number (symbol: e)
    dimensionless phi =        1.61803398874989484820; // golden ratio (symbol: φ)
  } Math;

  // Astronomical Constants
  // ----------------------
  constexpr struct { 
    length AU =              meters(149'597'870'700); // one astronomical unit (symbol: au, IAU 2009)
    length parsec   = meters(30'856'775'814'913'673); // one Parsec (symbol: pc, IAU 2015)
    length lightyear = meters(9'460'730'472'580'800); // one light-year (symbol: ly, IAU 2009)
    velocity H0 =          meters_per_second(70'100); // (per megaparsec, Hubble constant, symbol: H0)
    power Lsun =                     watts(3.939e26); // (Solar luminosity, symbol: L☉)
    power_intensity F1AU =  watts_per_meter2(1366.1); // total solar irradiance at 1 AU (solar constant)
  } IAU;

  // Various Constants
  // -----------------
  constexpr struct {
    temperature T0 =                      kelvins(0); // absolute zero (0K, the lowest possible temperature)
    length Marathon_distance =        meters(42'195);
    length quarter_mile =             meters(402.34);
    velocity speed_of_sound  = meters_per_second(343); // speed of sound in dry air at 20°C (68°F)
    velocity speed_of_sound_in_fresh_water = meters_per_second(1481); // at 20°C (68°F)
    velocity speed_of_sound_in_iron = meters_per_second(5120);
    velocity speed_of_sound_in_diamonds = meters_per_second(12'000);
    // TBD:gravitational_constant,6.6743015e-11, meters3_per_kilogram_per_second2);
  } Const;

  // Obsolete
  // --------
#define SET(_name, _quantity, _unit) inline constexpr auto _name = _unit(_quantity)
  namespace constant {
  // Universal Constants
  SET(G,                       6.67430e-11, meters3_per_kilogram_per_second2); // Newtonian constant of gravitation
  // Physico-chemical Constants
  SET(R,                     8.314'462'618, joules_per_kelvin_per_mol); // molar gas constant
  SET(R_dry_air,              287.050'0676, joules_per_kilogram_per_kelvin); // specific gas constant for dry air
  }
#undef SET
 
  // References
  // ----------
  // 1. https://codata.org - CODATA: the committee on data of the International Science Council (ISC)
  // 2. https://en.wikipedia.org/wiki/List_of_physical_constants
  // 3. https://en.wikipedia.org/wiki/Mathematical_constant
  // 4. https://en.wikipedia.org/wiki/Astronomical_constant

} // end of namespace
