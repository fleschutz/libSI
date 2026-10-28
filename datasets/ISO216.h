/// @file     datasets/ISO216.h
/// @brief    Contains ISO 216: The international standard for paper sizes
/// @details  Source: https://en.wikipedia.org/wiki/International_standard_paper_sizes (as of 2026)

#pragma once
#include <SI/literals.h>

namespace ISO216 {
  using namespace SI;

  constexpr length A0_width   = 841_mm;
  constexpr length A0_height  = 1189_mm;
  constexpr length A1_width   = 594_mm;
  constexpr length A1_height  = 841_mm;
  constexpr length A2_width   = 420_mm;
  constexpr length A2_height  = 594_mm;
  constexpr length A3_width   = 297_mm;
  constexpr length A3_height  = 420_mm;
  constexpr length A4_width   = 210_mm; ///< A4 - the most commonly available paper size worldwide
  constexpr length A4_height  = 297_mm;
  constexpr length A5_width   = 148_mm;
  constexpr length A5_height  = 210_mm;
  constexpr length A6_width   = 105_mm;
  constexpr length A6_height  = 148_mm;
  constexpr length A7_width   = 74_mm;
  constexpr length A7_height  = 105_mm;
  constexpr length A8_width   = 52_mm;
  constexpr length A8_height  = 74_mm;
  constexpr length A9_width   = 37_mm;
  constexpr length A9_height  = 52_mm;
  constexpr length A10_width  = 26_mm;
  constexpr length A10_height = 37_mm;

  constexpr length B0_width   = 1000_mm;
  constexpr length B0_height  = 1414_mm;
  constexpr length B1_width   = 707_mm;
  constexpr length B1_height  = 1000_mm;
  constexpr length B2_width   = 500_mm;
  constexpr length B2_height  = 707_mm;
  constexpr length B3_width   = 353_mm;
  constexpr length B3_height  = 500_mm;
  constexpr length B4_width   = 250_mm;
  constexpr length B4_height  = 353_mm;
  constexpr length B5_width   = 176_mm;
  constexpr length B5_height  = 250_mm;
  constexpr length B6_width   = 125_mm;
  constexpr length B6_height  = 176_mm;
  constexpr length B7_width   = 88_mm;
  constexpr length B7_height  = 125_mm;
  constexpr length B8_width   = 62_mm;
  constexpr length B8_height  = 88_mm;
  constexpr length B9_width   = 44_mm;
  constexpr length B9_height  = 62_mm;
  constexpr length B10_width  = 31_mm;
  constexpr length B10_height = 44_mm;

  constexpr length C0_width   = 917_mm;
  constexpr length C0_height  = 1297_mm;
  constexpr length C1_width   = 648_mm;
  constexpr length C1_height  = 917_mm;
  constexpr length C2_width   = 458_mm;
  constexpr length C2_height  = 648_mm;
  constexpr length C3_width   = 324_mm;
  constexpr length C3_height  = 458_mm;
  constexpr length C4_width   = 229_mm;
  constexpr length C4_height  = 324_mm;
  constexpr length C5_width   = 162_mm;
  constexpr length C5_height  = 229_mm;
  constexpr length C6_width   = 114_mm;
  constexpr length C6_height  = 162_mm;
  constexpr length C7_width   = 81_mm;
  constexpr length C7_height  = 114_mm;
  constexpr length C8_width   = 57_mm;
  constexpr length C8_height  = 81_mm;
  constexpr length C9_width   = 40_mm;
  constexpr length C9_height  = 57_mm;
  constexpr length C10_width  = 28_mm;
  constexpr length C10_height = 40_mm;

} // end of namespace
