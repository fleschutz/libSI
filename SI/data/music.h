// SI/data/music.h - type-safe data of music notes as of 2025
#pragma once

#include "../../SI/literals.h"

namespace SI { namespace music {

	// Human hearing range is 20 Hz to 20,000 Hz.
	// 9 octaves from 0 to 8
	// 12 notes per octave: C, C#, D, D#, E, F, F#, G, G#, A, A#, B
	const auto C0 = 16.351_Hz; // MIDI note # 12
	const auto Db0 = 17.324_Hz;
	const auto D0 = 18.354_Hz;
	// ...
	const auto Bb9 = 14917.24_Hz;
	const auto B9 = 15804.264_Hz;
}	}

// Sources
// -------
// 1. https://www.liutaiomottola.com/formulae/freqtab.htm
