// SI/data/ISO.h - data of International ISO standards as of 2025
#pragma once

#include "../../SI/literals.h"

namespace SI { namespace ISO {

// ISO 216 - Paper Sizes
const auto A0_paper_width = 841_mm;
const auto A0_paper_height = 1189_mm;
const auto A1_paper_width = 594_mm;
const auto A1_paper_height = 841_mm;
const auto A2_paper_width = 420_mm;
const auto A2_paper_height = 594_mm;
const auto A3_paper_width = 297_mm;
const auto A3_paper_height = 420_mm;
const auto A4_paper_width = 210_mm;
const auto A4_paper_height = 297_mm;
const auto A5_paper_width = 148_mm;
const auto A5_paper_height = 210_mm;
const auto A6_paper_width = 105_mm;
const auto A6_paper_height = 148_mm;
const auto A7_paper_width = 74_mm;
const auto A7_paper_height = 105_mm;
const auto A8_paper_width = 52_mm;
const auto A8_paper_height = 74_mm;
const auto A9_paper_width = 37_mm;
const auto A9_paper_height = 52_mm;
const auto A10_paper_width = 26_mm;
const auto A10_paper_height = 37_mm;
//...

// ISO 668 - Series 1 freight containers
const auto container_1AA_ext_length = 12.192_m; // (aka 40-foot standard)
const auto container_1AA_ext_height =  2.591_m;
const auto container_1AA_ext_width  =  2.438_m;
const auto container_1AA_max_gross_mass = 36'000_kg;
//...

} } // SI::ISO

// Sources
// -------
