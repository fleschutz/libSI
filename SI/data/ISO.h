// SI/data/ISO.h - data of International ISO standards as of 2025
#pragma once

#include "../../SI/literals.h"

namespace SI { namespace ISO {

// ISO 216 - international standard for paper sizes
const auto A0_paper_width = 841_mm;
const auto A0_paper_height = 1189_mm;
const auto A1_paper_width = 594_mm;
const auto A1_paper_height = 841_mm;
const auto A2_paper_width = 420_mm;
const auto A2_paper_height = 594_mm;
const auto A3_paper_width = 297_mm;
const auto A3_paper_height = 420_mm;
const auto A4_paper_width = 210_mm; // (A4 - the most commonly available paper size worldwide)
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

const auto B0_paper_width = 1000_mm;
const auto B0_paper_height = 1414_mm;
const auto B1_paper_width = 707_mm;
const auto B1_paper_height = 1000_mm;
const auto B2_paper_width = 500_mm;
const auto B2_paper_height = 707_mm;
const auto B3_paper_width = 353_mm;
const auto B3_paper_height = 500_mm;
const auto B4_paper_width = 250_mm;
const auto B4_paper_height = 353_mm;
const auto B5_paper_width = 176_mm;
const auto B5_paper_height = 250_mm;
const auto B6_paper_width = 125_mm;
const auto B6_paper_height = 176_mm;
const auto B7_paper_width = 88_mm;
const auto B7_paper_height = 125_mm;
const auto B8_paper_width = 62_mm;
const auto B8_paper_height = 88_mm;
const auto B9_paper_width = 44_mm;
const auto B9_paper_height = 62_mm;
const auto B10_paper_width = 31_mm;
const auto B10_paper_height = 44_mm;

const auto C0_paper_width = 917_mm;
const auto C0_paper_height = 1297_mm;
const auto C1_paper_width = 648_mm;
const auto C1_paper_height = 917_mm;
const auto C2_paper_width = 458_mm;
const auto C2_paper_height = 648_mm;
const auto C3_paper_width = 324_mm;
const auto C3_paper_height = 458_mm;
const auto C4_paper_width = 229_mm;
const auto C4_paper_height = 324_mm;
const auto C5_paper_width = 162_mm;
const auto C5_paper_height = 229_mm;
const auto C6_paper_width = 114_mm;
const auto C6_paper_height = 162_mm;
const auto C7_paper_width = 81_mm;
const auto C7_paper_height = 114_mm;
const auto C8_paper_width = 57_mm;
const auto C8_paper_height = 81_mm;
const auto C9_paper_width = 40_mm;
const auto C9_paper_height = 57_mm;
const auto C10_paper_width = 28_mm;
const auto C10_paper_height = 40_mm;

// ISO 668 - Series 1 freight containers
const auto container_1AA_ext_length = 12.192_m; // (aka 40-foot standard)
const auto container_1AA_ext_height =  2.591_m;
const auto container_1AA_ext_width  =  2.438_m;
const auto container_1AA_max_gross_mass = 36'000_kg;
//...

} } // SI::ISO

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_standard_paper_sizes
