// USAGE:  #include "material_properties.h" ... for (auto& material_property : dataset::material_properties) { ...
// SOURCE: material_properties.csv
// NOTE:   Converted by csv2hpp 0.8 on Sep 05, 2026 (see https://github.com/fleschutz/csv2hpp)
#pragma once
#include <SI/literals.h>

namespace dataset {
using namespace SI;

struct material_property_details {
	const char* Name;                  // from column  1 (string)
	const char* Type;                  // from column  2 (string)
	float Cost;                        // from column  3 ($/kg)
	SI::density Density;               // from column  4 (mg/m³)
	SI::pressure Youngs_Modulus;       // from column  5 (GPa)
	SI::pressure Shear_Modulus;        // from column  6 (GPa)
	double Poissons_Ratio;             // from column  7 (double)
	SI::pressure Yield_Stress;         // from column  8 (MPa)
	SI::pressure UTS;                  // from column  9 (MPa)
	double Breaking_strain;            // from column 10 (%)
	double Fracture_Toughness;         // from column 11 (double)
	double Thermal_Expansion;          // from column 12 (double)
};

const material_property_details material_propertys[] { // HINT: 00=empty or unknown field
{"Alumina (Al2O3)","ceramic",1.90 ,3.9_g_per_m³,390_GPa,125_GPa,0.26,4800_MPa,35_MPa,0.,4.4,8.1},
{"Aluminum alloy (7075-T6)","metal",1.80 ,2.7_g_per_m³,70_GPa,28_GPa,0.34,500_MPa,570_MPa,12,28,33},
{"Beryllium alloy","metal",315.00 ,2.9_g_per_m³,245_GPa,110_GPa,0.12,360_MPa,500_MPa,6.,5.,14},
{"Bone (compact)","natural",1.90 ,2._g_per_m³,14_GPa,3.5_GPa,0.43,100_MPa,100_MPa,9.,5.,20},
{"Brass (70Cu30Zn, annealed)","metal",2.20 ,8.4_g_per_m³,130_GPa,39_GPa,0.33,75_MPa,325_MPa,70.,80,20},
{"Cermets (Co/WC)","composite",78.60 ,11.5_g_per_m³,470_GPa,200_GPa,0.3,650_MPa,1200_MPa,2.5,13,5.8},
{"CFRP Laminate (graphite)","composite",110.00 ,1.5_g_per_m³,1.5_GPa,53_GPa,0.28,200_MPa,550_MPa,2.,38,12},
{"Concrete","ceramic",0.05 ,2.5_g_per_m³,48_GPa,20_GPa,0.2,25_MPa,3._MPa,0.,0.75,11},
{"Copper alloys","metal",2.25 ,8.3_g_per_m³,135_GPa,50_GPa,0.35,510_MPa,720_MPa,0.3,94,18},
{"Cork","natural",9.95 ,0.18_g_per_m³,0.032_GPa,0.005_GPa,0.25,1.4_MPa,1.5_MPa,80,0.074,180},
{"Epoxy thermoset","polymer",5.50 ,1.2_g_per_m³,3.5_GPa,1.4_GPa,0.25,45_MPa,45_MPa,4.,0.5,60},
{"GFRP Laminate (glass)","composite",3.90 ,1.8_g_per_m³,26_GPa,10_GPa,0.28,125_MPa,530_MPa,2.,40,19},
{"Glass (soda)","ceramic",1.35 ,2.5_g_per_m³,65_GPa,26_GPa,0.23,3500_MPa,35_MPa,0.,0.71,8.8},
{"Granite","ceramic",3.15 ,2.6_g_per_m³,66_GPa,26_GPa,0.25,2500_MPa,60_MPa,0.1,1.5,6.5},
{"Ice (H2O)","ceramic",0.23 ,0.92_g_per_m³,9.1_GPa,3.6_GPa,0.28,85_MPa,6.5_MPa,0.,0.11,55},
{"Lead alloys","metal",1.20 ,11.1_g_per_m³,16_GPa,5.5_GPa,0.45,33_MPa,42_MPa,60,40,29},
{"Nickel alloys","metal",6.10 ,8.5_g_per_m³,180_GPa,70_GPa,0.31,900_MPa,1200_MPa,30,93,13},
{"Polyamide (nylon)","polymer",4.30 ,1.1_g_per_m³,3._GPa,0.76_GPa,0.42,40_MPa,55_MPa,5.,3.,103},
{"Polybutadiene elastomer","polymer",1.20 ,0.91_g_per_m³,0.0016_GPa,0.0005_GPa,0.5,2.1_MPa,2.1_MPa,500,0.087,140},
{"Polycarbonate","polymer",4.90 ,1.2_g_per_m³,2.7_GPa,0.97_GPa,0.42,70_MPa,77_MPa,60,2.6,70},
{"Polyester thermoset","polymer",3.00 ,1.3_g_per_m³,3.5_GPa,1.4_GPa,0.25,50_MPa,0.7_MPa,2.,0.7,150},
{"Polyethylene (HDPE)","polymer",1.00 ,0.95_g_per_m³,0.7_GPa,0.31_GPa,0.42,25_MPa,33_MPa,90,3.5,225},
{"Polypropylene","polymer",1.10 ,0.89_g_per_m³,0.9_GPa,0.42_GPa,0.42,35_MPa,45_MPa,90,3.,85},
{"Polyurethane elastomer","polymer",4.00 ,1.2_g_per_m³,0.025_GPa,0.0086_GPa,0.5,30_MPa,30_MPa,500,0.3,125},
{"Polyvinyl chloride (rigid PVC)","polymer",1.50 ,1.4_g_per_m³,1.5_GPa,0.6_GPa,0.42,53_MPa,60_MPa,50,0.54,75},
{"Silicon","ceramic",2.35 ,2.3_g_per_m³,110_GPa,44_GPa,0.24,3200_MPa,35_MPa,0.,1.5,6},
{"Silicon Carbide (SiC)","ceramic",36.00 ,2.8_g_per_m³,450_GPa,190_GPa,0.15,9800_MPa,35_MPa,0.,4.2,4.2},
{"Spruce (parallel to grain)","natural",1.00 ,0.6_g_per_m³,9_GPa,0.8_GPa,0.3,48_MPa,50_MPa,10,2.5,4},
{"Steel, high strength 4340","metal",0.25 ,7.8_g_per_m³,210_GPa,76_GPa,0.29,1240_MPa,1550_MPa,2.5,100,14},
{"Steel, mild 1020","metal",0.50 ,7.8_g_per_m³,210_GPa,76_GPa,0.29,200_MPa,380_MPa,25,140,14},
{"Steel, stainless austenitic 304","metal",2.70 ,7.8_g_per_m³,210_GPa,76_GPa,0.28,240_MPa,590_MPa,60,50,17},
{"Titanium alloy (6Al4V)","metal",16.25 ,4.5_g_per_m³,100_GPa,39_GPa,0.36,910_MPa,950_MPa,15,85,9.4},
{"Tungsten Carbide (WC)","ceramic",50.00 ,15.5_g_per_m³,550_GPa,270_GPa,0.21,6800_MPa,35_MPa,0.,3.7,5.8},
}; // (12 columns x 33 rows = 396 cells)

} // end of namespace 'dataset'

