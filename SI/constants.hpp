#pragma once

#include "types.hpp"

namespace si
{
	namespace constant
	{
		// Universal constants
    		const auto c_0 = meters_per_second(299792458); // speed of light in vacuum
		const auto speed_of_light_in_vacuum = meters_per_second(299792458); // speed of light in vacuum (c)
#if 0
    static constexpr auto Z_0  = 376.730313667 * units::Ohm; // characteristic impedance of vacuum
    static constexpr auto epsilon_0  = 8.854'187'817'620'39e-12 * units::F / units::m; // electric constant (vacuum permittivity)
    static constexpr auto mu_0  = 1.256'637'06e-6 * units::N / units::A2; // magnetic constant (vacuum permeability)
    static constexpr auto G  = 6.67408e-11 * units::m3 / units::kg / units::s2; // Newtonian constant of gravitation
    static constexpr auto h  = 6.62607e-34 * units::J * units::s; // Planck constant
    static constexpr auto h_bar  = 1.054'571'817e-34 * units::J * units::s; // reduced Planck constant
#endif

		    // Electromagnetic constants
#if 0
    static constexpr auto mu_B  = 9.2740100e-24 * units::J / units::T; // Bohr magneton
    static constexpr auto G_0  = 7.748091729e-5 * units::S; // conductance quantum
    static constexpr auto K_Jm90  = 48359e9 * units::Hz / units::V; // conventional value of Josephson constant[30]
    static constexpr auto R_Km90  = 25812.807 * units::Ohm; // conventional value of von Klitzing constant[32]
    static constexpr auto e  = 1.602176e-19 * units::C; // elementary charge
    static constexpr auto G_0_inv  = 12906.40372 * units::Ohm; // inverse conductance quantum
    static constexpr auto K_J  = 483597.8484e9 * units::Hz / units::V; // Josephson constant
    static constexpr auto Phi_0  = 2.067833848e-15 * units::Wb; // magnetic flux quantum
    static constexpr auto mu_N  = 5.0507837e-27 * units::J / units::T; // nuclear magneton
    static constexpr auto R_K  = 25812.80745 * units::Ohm; // von Klitzing constant
    static constexpr double k_e = 1.0 / (4*M_PI*epsilon_0);
#endif

        	// Atomic and nuclear constants
		const auto electron_mass = kilogram(9.1093837139e-31);
    		const auto m_e  = kilogram(9.1093837e-31); // electron mass
		const auto muon_mass = kilogram(1.883531627e-28);
		const auto tau_mass = kilogram(3.16754e-27);
		const auto proton_mass = kilogram(1.67262192595e-27);
    		const auto m_p = kilogram(1.67262192e-27); // proton mass
		const auto neutron_mass = kilogram(1.67492750056e-27);
    		const auto a_0 = meter(5.29177210e-11); // Bohr radius
    		const auto r_e = meter(2.8179403e-15); // classical electron radius
    		const double g_e = -2.00231930436256; // electron g-factor
    		const auto alpha = 7.2973525e-3; // fine-structure constant
    		const auto alpha_inv = 137.035999084; // inverse fine-structure constant
    		const auto E_h  = joule(4.3597447222e-18); // Hartree energy
    		const auto sin2Theta_W  = 0.22290; // weak mixing angle
#if 0
    static constexpr auto G0_F = 1.1663e-5 / units::GeV  / units::GeV; // Fermi coupling constant
    static constexpr auto h_2me  = 3.6369475e-4 * units::m2 / units::s; // quantum of circulation
    static constexpr auto R_inf  = 10973731.568160 / units::m; // Rydberg constant
    static constexpr auto sigma_e  = 6.6524587e-29 * units::m2; // Thomson cross section
#endif

        	// Physico-chemical constants
    		const auto m_u = kilogram(1.66053906e-27); // Atomic mass constant
#if 0
    static constexpr auto N_A  = 6.02214e23 / units::mol; // Avogadro constant
    static constexpr auto k_B  = 1.380'649e-23 * units::J / units::K; // Boltzmann constant
    static constexpr auto F  = 96485.33212 * units::C / units::mol; // Faraday constant
    static constexpr auto c_1  = 3.741771852e-16 * units::W * units::m2; // first radiation constant
    static constexpr auto c_1L  = 1.191042972e-16 * units::W * units::m2 / units::sr; // first radiation constant for spectral radiance
    static constexpr auto n_0  = 2.651645804e25 / units::m3; // Loschmidt constant
    static constexpr auto R  = 8.314462618 * units::J / units::mol / units::K; // gas constant
    static constexpr auto N_Ah  = 3.990312712e-10 * units::J / units::Hz / units::mol; // molar Planck constant
    static constexpr auto M_u  = 0.99999999e-3 * units::kg / units::mol; // molar mass constant
    static constexpr auto V_m  = 22.71095464e-3 * units::m3 / units::mol; // molar volume of an ideal gas
    static constexpr auto c_2  = 1.438776877e-2 * units::m * units::K; // second radiation constant
    static constexpr auto sigma  = 5.670374419e-8 * units::W / units::m2 / units::K2; // Stefan–Boltzmann constant
    static constexpr auto b  = 2.897771955e-3 * units::m * units::K; // Wien wavelength displacement law constant
    static constexpr auto b_prime = 5.878925757e10 * units::Hz / units::K; // Wien frequency displacement law constant
#endif
    		const auto S_0_by_R = -1.15170753706; // Sackur–Tetrode constant

	        // Adopted values
#if 0
    static constexpr auto g_0  = 9.80665 * units::m / units::s2; // standard acceleration of gravity
    static constexpr auto atm  = 101325 * units::Pa; // standard atmosphere
#endif
    		const auto Deltanu_Cs  = hertz(9192631770); // Caesium standard (defines the SI second)

		// Physical constants: (source: https://en.wikipedia.org/wiki/List_of_physical_constants)

		const auto speed_of_sound = meters_per_second(343); // speed of sound in air at 20 °C (68 °F)

		const auto standard_gravity = meters_per_second2(9.80665); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).

		const auto min_temperature = kelvin(0.0);

//		const auto Gravitational_constant = 6.6743015e−11 * si::m3 / si::kilogram / si::s2;

		const auto Marathon_length = kilometer(42.195);

		// Mathematical constants: (source: https://en.wikipedia.org/wiki/List_of_mathematical_constants)
		const auto pi = degree(180);
		const auto half_pi = degree(90);
		const auto tau = degree(360);

		// Astronomical constants:
		const auto AU = kilometer(149.5978707e6);
		const auto lightyear = kilometer(9460730472580.8); 
		const auto parsec = 3.2 * lightyear; // symbol: pc

#if defined(__clang__) || defined(_MSC_VER)
    static constexpr auto ε_0  = 8.8541878e-12 * units::F / units::m; // electric constant (vacuum permittivity)
    static constexpr auto μ_0  = 1.25663706e-6 * units::N / units::A2 ; // magnetic constant (vacuum permeability)
    static constexpr auto ℏ  = 1.054571817e-34 * units::J * units::s; // reduced Planck constant
    static constexpr auto μ_B  = 9.2740100e-24 * units::J / units::T; // Bohr magneton
    static constexpr auto Φ_0  = 2.067833848e-15 * units::Wb; // magnetic flux quantum
    static constexpr auto μ_N  = 5.0507837e-27 * units::J / units::T; // nuclear magneton
    static constexpr auto σ_e  = 6.6524587e-29 * units::m2; // Thomson cross section
    static constexpr auto σ  = 5.670374419e-8 * units::W / units::m2 / units::K2; // Stefan–Boltzmann constant
#endif
    		const auto α  = 7.2973525e-3; // fine-structure constant
    		const auto α_inv  = 137.035999084; // inverse fine-structure constant
    		const auto sin2θ_W  = 0.22290; // weak mixing angle
    		const auto Δν_Cs  = hertz(9192631770); // Caesium standard (defines the SI second)
	}
}	
