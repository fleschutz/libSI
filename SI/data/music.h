// SI/data/music.h - data of Western music notes as of 2025
#pragma once

#include "../../SI/units.h"
#define SET(_name, _value, _unit) const auto _name = _unit(_value ## L)

namespace SI { namespace music {

// The human hearing range is from 20Hz to 20,000Hz.
// There are 9 octaves from 0 to 8.
// And 12 notes per octave: C, C#, D, D#, E, F, F#, G, G#, A, A#, B (Scientific Pitch Notation format)
SET( C0,     16.351, hertz); // MIDI note # 12
SET( Db0,    17.324, hertz);
SET( D0,     18.354, hertz);
SET( Eb0,    19.445, hertz);
SET( F0,     21.827, hertz);
SET( Gb0,    23.124, hertz);
SET( G0,     24.499, hertz);
SET( Ab0,    25.956, hertz);
SET( A0,     27.500, hertz); // lowest note of piano
SET( Bb0,    29.135, hertz);
SET( B0,     30.868, hertz); // lowest note of 5 string bass

SET( C1,     32.703, hertz); // lowest note of double bass with C extension
SET( Db1,    34.648, hertz);
SET( D1,     36.708, hertz);
SET( Eb1,    38.891, hertz);
SET( E1,     41.203, hertz); // lowest note of bass
// ...
SET( Bb9, 14917.240, hertz);
SET( B9,  15804.264, hertz);

} } // SI::music
#undef SET

// Sources
// -------
// 1. https://www.liutaiomottola.com/formulae/freqtab.htm
