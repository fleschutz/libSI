// SI/music.hpp - contains music notes in SI units
#pragma once
#include "literals.hpp"
#define NOTE(_name, _octave, _frequency, _wavelength)  static constexpr auto _name##_octave = _frequency
// 9 octaves from 0 to 8
// 12 notes per octave: C, C#, D, D#, E, F, F#, G, G#, A, A#, B

namespace si
{
	namespace note // source: https://www.liutaiomottola.com/formulae/freqtab.htm
	{
		NOTE(C, 0, 16.351_Hz, 20.812_m); // MIDI note # 12
	}

	namespace rest
	{
	}
}

#undef NOTE
