// SI/data/music.h - data of music notes as of 2025
#pragma once

#include "../../SI/units.h"
#define SET(_name, _value, _unit) const auto _name = _unit(_value)

namespace SI { namespace music {

// Human hearing range is 20 Hz to 20,000 Hz.
// 9 octaves from 0 to 8
// 12 notes per octave: C, C#, D, D#, E, F, F#, G, G#, A, A#, B
SET( C0,     16.351, hertz); // MIDI note # 12
SET( Db0,    17.324, hertz);
SET( D0,     18.354, hertz);
// ...
SET( Bb9, 14917.240, hertz);
SET( B9,  15804.264, hertz);

}	}
#undef SET

// Sources
// -------
// 1. https://www.liutaiomottola.com/formulae/freqtab.htm
