/// @file     datasets/ISO216.h
/// @brief    Contains the international standard for paper sizes (ISO 216)
/// @details  Source: https://en.wikipedia.org/wiki/International_standard_paper_sizes (as of 2026)

#pragma once
#include <SI/literals.h>
using namespace SI;

constexpr struct {

   length A0_width   = 841_mm;
   length A0_height  = 1189_mm;
   length A1_width   = 594_mm;
   length A1_height  = 841_mm;
   length A2_width   = 420_mm;
   length A2_height  = 594_mm;
   length A3_width   = 297_mm;
   length A3_height  = 420_mm;
   length A4_width   = 210_mm; ///< A4 - the most commonly available paper size worldwide
   length A4_height  = 297_mm;
   length A5_width   = 148_mm;
   length A5_height  = 210_mm;
   length A6_width   = 105_mm;
   length A6_height  = 148_mm;
   length A7_width   = 74_mm;
   length A7_height  = 105_mm;
   length A8_width   = 52_mm;
   length A8_height  = 74_mm;
   length A9_width   = 37_mm;
   length A9_height  = 52_mm;
   length A10_width  = 26_mm;
   length A10_height = 37_mm;

   length B0_width   = 1000_mm;
   length B0_height  = 1414_mm;
   length B1_width   = 707_mm;
   length B1_height  = 1000_mm;
   length B2_width   = 500_mm;
   length B2_height  = 707_mm;
   length B3_width   = 353_mm;
   length B3_height  = 500_mm;
   length B4_width   = 250_mm;
   length B4_height  = 353_mm;
   length B5_width   = 176_mm;
   length B5_height  = 250_mm;
   length B6_width   = 125_mm;
   length B6_height  = 176_mm;
   length B7_width   = 88_mm;
   length B7_height  = 125_mm;
   length B8_width   = 62_mm;
   length B8_height  = 88_mm;
   length B9_width   = 44_mm;
   length B9_height  = 62_mm;
   length B10_width  = 31_mm;
   length B10_height = 44_mm;

   length C0_width   = 917_mm;
   length C0_height  = 1297_mm;
   length C1_width   = 648_mm;
   length C1_height  = 917_mm;
   length C2_width   = 458_mm;
   length C2_height  = 648_mm;
   length C3_width   = 324_mm;
   length C3_height  = 458_mm;
   length C4_width   = 229_mm;
   length C4_height  = 324_mm;
   length C5_width   = 162_mm;
   length C5_height  = 229_mm;
   length C6_width   = 114_mm;
   length C6_height  = 162_mm;
   length C7_width   = 81_mm;
   length C7_height  = 114_mm;
   length C8_width   = 57_mm;
   length C8_height  = 81_mm;
   length C9_width   = 40_mm;
   length C9_height  = 57_mm;
   length C10_width  = 28_mm;
   length C10_height = 40_mm;

} ISO216;
