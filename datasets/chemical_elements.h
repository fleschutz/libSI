// DO NOT EDIT! Data source is chemical_elements.csv (converted by github.com/fleschutz/csv2hpp 0.3 on 2026-02-04)
#pragma once
#include <SI/literals.h>
using namespace SI;

namespace dataset { 

struct chemical_element_data {
	unsigned char atomic_number;             // column  1 (byte) in CSV file
	char symbol[4];                          // column  2 (4chars) in CSV file
	const char* name;                        // column  3 (string) in CSV file
	unsigned char group;                     // column  4 (byte) in CSV file
	unsigned char period;                    // column  5 (byte) in CSV file
	char block[4];                           // column  6 (4chars) in CSV file
	unsigned char category;                  // column  7 (byte) in CSV file
	SI::mass atomic_mass;                    // column  8 (_Da) in CSV file
	unsigned char standard_state;            // column 11 (byte) in CSV file
	double density;                          // column 12 (double) in CSV file
	SI::temperature melting_point;           // column 13 (_degC) in CSV file
	SI::temperature boiling_point;           // column 14 (_degC) in CSV file
	double heat_capacity;                    // column 15 (double) in CSV file
	double heat_of_fusion;                   // column 16 (double) in CSV file
	double heat_of_vaporization;             // column 17 (double) in CSV file
	SI::length atomic_radius;                // column 18 (_pm) in CSV file
	SI::length covalent_radius;              // column 19 (_pm) in CSV file
	SI::length VanDerWaals_radius;           // column 20 (_pm) in CSV file
	SI::energy_per_mol ionization_energy;    // column 23 (_kJ_per_mol) in CSV file
	bool radioactive;                        // column 29 (bool) in CSV file
};

const chemical_element_data chemical_elements[] { // NOTE: 00=empty or unknown field
{1,"H","Hydrogen",1,1,"s",0,1.008_Da,0,0.00008988,14.01_degC,20.28_degC,14.304,0.117,0.904,53_pm,38_pm,120_pm,1312_kJ_per_mol,false,},
{2,"He","Helium",18,1,"s",7,4.002602_Da,0,0.0001785,00_degC,4.22_degC,5.193,0.0138,0.0829,31_pm,32_pm,140_pm,2372.3_kJ_per_mol,false,},
{3,"Li","Lithium",1,2,"s",1,6.94_Da,2,0.534,453.69_degC,1560_degC,3.582,3,136,167_pm,134_pm,182_pm,520.2_kJ_per_mol,false,},
{4,"Be","Beryllium",2,2,"s",2,9.0121831_Da,2,1.85,1560_degC,2742_degC,1.825,7.895,292,112_pm,90_pm,153_pm,899.5_kJ_per_mol,false,},
{5,"B","Boron",13,2,"p",5,10.81_Da,2,2.34,2349_degC,4200_degC,1.026,50.2,508,87_pm,82_pm,192_pm,800.6_kJ_per_mol,false,},
{6,"C","Carbon",14,2,"p",0,12.011_Da,2,2.267,3800_degC,4300_degC,0.709,117,00,67_pm,77_pm,170_pm,1086.5_kJ_per_mol,false,},
{7,"N","Nitrogen",15,2,"p",0,14.007_Da,0,0.0012506,63.15_degC,77.36_degC,1.04,0.72,5.57,56_pm,75_pm,155_pm,1402.3_kJ_per_mol,false,},
{8,"O","Oxygen",16,2,"p",0,15.999_Da,0,0.001429,54.36_degC,90.2_degC,0.918,0.444,6.82,48_pm,73_pm,152_pm,1313.9_kJ_per_mol,false,},
{9,"F","Fluorine",17,2,"p",6,18.99840316_Da,0,0.001696,53.53_degC,85.03_degC,0.824,0.51,6.62,42_pm,71_pm,147_pm,1681_kJ_per_mol,false,},
{10,"Ne","Neon",18,2,"p",7,20.1797_Da,0,0.0008999,24.56_degC,27.07_degC,1.03,0.335,1.71,38_pm,69_pm,154_pm,2080.7_kJ_per_mol,false,},
{11,"Na","Sodium",1,3,"s",1,22.98976928_Da,2,0.971,370.87_degC,1156_degC,1.228,2.6,97.42,190_pm,154_pm,227_pm,495.8_kJ_per_mol,false,},
{12,"Mg","Magnesium",2,3,"s",2,24.305_Da,2,1.738,923_degC,1363_degC,1.023,8.48,128,145_pm,130_pm,173_pm,737.7_kJ_per_mol,false,},
{13,"Al","Aluminium",13,3,"p",4,26.9815385_Da,2,2.698,933.47_degC,2792_degC,0.897,10.71,284,118_pm,118_pm,184_pm,577.5_kJ_per_mol,false,},
{14,"Si","Silicon",14,3,"p",5,28.085_Da,2,2.3296,1687_degC,3538_degC,0.705,50.21,359,111_pm,111_pm,210_pm,786.5_kJ_per_mol,false,},
{15,"P","Phosphorus",15,3,"p",0,30.973762_Da,2,1.82,317.3_degC,550_degC,0.769,0.66,12.4,98_pm,106_pm,180_pm,1011.8_kJ_per_mol,false,},
{16,"S","Sulfur",16,3,"p",0,32.06_Da,2,2.067,388.36_degC,717.87_degC,0.71,1.727,45,88_pm,102_pm,180_pm,999.6_kJ_per_mol,false,},
{17,"Cl","Chlorine",17,3,"p",6,35.45_Da,0,0.003214,171.6_degC,239.11_degC,0.479,6.406,20.41,79_pm,99_pm,175_pm,1251.2_kJ_per_mol,false,},
{18,"Ar","Argon",18,3,"p",7,39.948_Da,0,0.0017837,83.8_degC,87.3_degC,0.52,1.18,6.53,71_pm,97_pm,188_pm,1520.6_kJ_per_mol,false,},
{19,"K","Potassium",1,4,"s",1,39.0983_Da,2,0.862,336.53_degC,1032_degC,0.757,2.321,76.9,243_pm,196_pm,275_pm,418.8_kJ_per_mol,false,},
{20,"Ca","Calcium",2,4,"s",2,40.078_Da,2,1.54,1115_degC,1757_degC,0.647,8.54,154.7,194_pm,174_pm,231_pm,589.8_kJ_per_mol,false,},
{21,"Sc","Scandium",3,4,"d",3,44.955908_Da,2,2.989,1814_degC,3109_degC,0.568,14.1,332.7,184_pm,144_pm,211_pm,633.1_kJ_per_mol,false,},
{22,"Ti","Titanium",4,4,"d",3,47.867_Da,2,4.54,1941_degC,3560_degC,0.523,14.15,425,176_pm,136_pm,00_pm,658.8_kJ_per_mol,false,},
{23,"V","Vanadium",5,4,"d",3,50.9415_Da,2,6.11,2183_degC,3680_degC,0.489,21.5,444,171_pm,125_pm,00_pm,650.9_kJ_per_mol,false,},
{24,"Cr","Chromium",6,4,"d",3,51.9961_Da,2,7.15,2180_degC,2944_degC,0.449,21,339.5,166_pm,127_pm,00_pm,652.9_kJ_per_mol,false,},
{25,"Mn","Manganese",7,4,"d",3,54.938044_Da,2,7.44,1519_degC,2334_degC,0.479,12.91,221,161_pm,139_pm,00_pm,717.3_kJ_per_mol,false,},
{26,"Fe","Iron",8,4,"d",3,55.845_Da,2,7.874,1811_degC,3134_degC,0.449,13.81,340,156_pm,125_pm,00_pm,762.5_kJ_per_mol,false,},
{27,"Co","Cobalt",9,4,"d",3,58.933194_Da,2,8.86,1768_degC,3200_degC,0.421,16.06,377,152_pm,126_pm,00_pm,760.4_kJ_per_mol,false,},
{28,"Ni","Nickel",10,4,"d",3,58.6934_Da,2,8.912,1728_degC,3186_degC,0.444,17.48,379,149_pm,121_pm,163_pm,737.1_kJ_per_mol,false,},
{29,"Cu","Copper",11,4,"d",3,63.546_Da,2,8.96,1357.77_degC,2835_degC,0.385,13.26,300.4,145_pm,138_pm,140_pm,745.5_kJ_per_mol,false,},
{30,"Zn","Zinc",12,4,"d",3,65.38_Da,2,7.134,692.88_degC,1180_degC,0.388,7.32,115,142_pm,131_pm,139_pm,906.4_kJ_per_mol,false,},
{31,"Ga","Gallium",13,4,"p",4,69.723_Da,2,5.907,302.9146_degC,2673_degC,0.371,5.59,256,136_pm,126_pm,187_pm,578.8_kJ_per_mol,false,},
{32,"Ge","Germanium",14,4,"p",5,72.63_Da,2,5.323,1211.4_degC,3106_degC,0.32,36.94,334,125_pm,122_pm,211_pm,762_kJ_per_mol,false,},
{33,"As","Arsenic",15,4,"p",5,74.921595_Da,2,5.776,1090_degC,887_degC,0.329,24.44,32.4,114_pm,119_pm,185_pm,947_kJ_per_mol,false,},
{34,"Se","Selenium",16,4,"p",0,78.971_Da,2,4.809,453_degC,958_degC,0.321,6.69,95.48,103_pm,116_pm,190_pm,941_kJ_per_mol,false,},
{35,"Br","Bromine",17,4,"p",6,79.904_Da,1,3.122,265.8_degC,332_degC,0.474,10.57,29.96,94_pm,114_pm,185_pm,1139.9_kJ_per_mol,false,},
{36,"Kr","Krypton",18,4,"p",7,83.798_Da,0,0.003733,115.79_degC,119.93_degC,0.248,1.64,9.08,88_pm,110_pm,202_pm,1350.8_kJ_per_mol,false,},
{37,"Rb","Rubidium",1,5,"s",1,85.4678_Da,2,1.532,312.46_degC,961_degC,0.363,2.19,75.77,265_pm,211_pm,303_pm,403_kJ_per_mol,false,},
{38,"Sr","Strontium",2,5,"s",2,87.62_Da,2,2.64,1050_degC,1655_degC,0.301,7.43,141,219_pm,192_pm,249_pm,549.5_kJ_per_mol,false,},
{39,"Y","Yttrium",3,5,"d",3,88.90584_Da,2,4.469,1799_degC,3609_degC,0.298,11.42,390,212_pm,162_pm,00_pm,600_kJ_per_mol,false,},
{40,"Zr","Zirconium",4,5,"d",3,91.224_Da,2,6.506,2128_degC,4682_degC,0.278,14,573,206_pm,148_pm,00_pm,640.1_kJ_per_mol,false,},
{41,"Nb","Niobium",5,5,"d",3,92.90637_Da,2,8.57,2750_degC,5017_degC,0.265,30,689.9,198_pm,137_pm,00_pm,652.1_kJ_per_mol,false,},
{42,"Mo","Molybdenum",6,5,"d",3,95.95_Da,2,10.22,2896_degC,4912_degC,0.251,37.48,617,190_pm,145_pm,00_pm,684.3_kJ_per_mol,false,},
{43,"Tc","Technetium",7,5,"d",3,98_Da,2,11.5,2430_degC,4538_degC,00,33.29,585.2,183_pm,156_pm,00_pm,702_kJ_per_mol,true,},
{44,"Ru","Ruthenium",8,5,"d",3,101.07_Da,2,12.37,2607_degC,4423_degC,0.238,38.59,619,178_pm,126_pm,00_pm,710.2_kJ_per_mol,false,},
{45,"Rh","Rhodium",9,5,"d",3,102.9055_Da,2,12.41,2237_degC,3968_degC,0.243,26.59,494,173_pm,135_pm,00_pm,719.7_kJ_per_mol,false,},
{46,"Pd","Palladium",10,5,"d",3,106.42_Da,2,12.02,1828.05_degC,3236_degC,0.244,16.74,358,169_pm,131_pm,163_pm,804.4_kJ_per_mol,false,},
{47,"Ag","Silver",11,5,"d",3,107.8682_Da,2,10.501,1234.93_degC,2435_degC,0.235,11.28,254,165_pm,153_pm,172_pm,731_kJ_per_mol,false,},
{48,"Cd","Cadmium",12,5,"d",3,112.414_Da,2,8.69,594.22_degC,1040_degC,0.232,6.21,99.87,161_pm,148_pm,158_pm,867.8_kJ_per_mol,false,},
{49,"In","Indium",13,5,"p",4,114.818_Da,2,7.31,429.75_degC,2345_degC,0.233,3.281,231.8,156_pm,144_pm,193_pm,558.3_kJ_per_mol,false,},
{50,"Sn","Tin",14,5,"p",4,118.71_Da,2,7.287,505.08_degC,2875_degC,0.228,7.03,296.1,145_pm,141_pm,217_pm,708.6_kJ_per_mol,false,},
{51,"Sb","Antimony",15,5,"p",5,121.76_Da,2,6.685,903.78_degC,1860_degC,0.207,19.79,193.43,133_pm,138_pm,206_pm,834_kJ_per_mol,false,},
{52,"Te","Tellurium",16,5,"p",5,127.6_Da,2,6.232,722.66_degC,1261_degC,0.202,17.49,114.1,123_pm,135_pm,206_pm,869.3_kJ_per_mol,false,},
{53,"I","Iodine",17,5,"p",6,126.90447_Da,2,4.93,386.85_degC,457.4_degC,0.214,15.52,41.57,115_pm,133_pm,198_pm,1008.4_kJ_per_mol,false,},
{54,"Xe","Xenon",18,5,"p",7,131.293_Da,0,0.005887,161.4_degC,165.03_degC,0.158,2.27,12.64,108_pm,130_pm,216_pm,1170.4_kJ_per_mol,false,},
{55,"Cs","Caesium",1,6,"s",1,132.905452_Da,2,1.873,301.59_degC,944_degC,0.242,2.09,63.9,298_pm,225_pm,343_pm,375.7_kJ_per_mol,false,},
{56,"Ba","Barium",2,6,"s",2,137.327_Da,2,3.594,1000_degC,2170_degC,0.204,7.12,140.3,253_pm,198_pm,268_pm,502.9_kJ_per_mol,false,},
{57,"La","Lanthanum",3,6,"d",8,138.90547_Da,2,6.145,1193_degC,3737_degC,0.195,6.2,400,195_pm,169_pm,00_pm,538.1_kJ_per_mol,false,},
{58,"Ce","Cerium",00,6,"f",8,140.116_Da,2,6.77,1068_degC,3716_degC,0.192,5.46,398,158_pm,00_pm,00_pm,534.4_kJ_per_mol,false,},
{59,"Pr","Praseodymium",00,6,"f",8,140.90766_Da,2,6.773,1208_degC,3793_degC,0.193,6.89,331,247_pm,00_pm,00_pm,527_kJ_per_mol,false,},
{60,"Nd","Neodymium",00,6,"f",8,144.242_Da,2,7.007,1297_degC,3347_degC,0.19,7.14,289,206_pm,00_pm,00_pm,533.1_kJ_per_mol,false,},
{61,"Pm","Promethium",00,6,"f",8,145_Da,2,7.26,1315_degC,3273_degC,00,7.13,289,205_pm,00_pm,00_pm,540_kJ_per_mol,true,},
{62,"Sm","Samarium",00,6,"f",8,150.36_Da,2,7.52,1345_degC,2067_degC,0.197,8.62,192,238_pm,00_pm,00_pm,544.5_kJ_per_mol,false,},
{63,"Eu","Europium",00,6,"f",8,151.964_Da,2,5.243,1099_degC,1802_degC,0.182,9.21,176,231_pm,00_pm,00_pm,547.1_kJ_per_mol,false,},
{64,"Gd","Gadolinium",00,6,"f",8,157.25_Da,2,7.895,1585_degC,3546_degC,0.236,10.05,301.3,233_pm,00_pm,00_pm,593.4_kJ_per_mol,false,},
{65,"Tb","Terbium",00,6,"f",8,158.92535_Da,2,8.229,1629_degC,3503_degC,0.182,10.15,391,225_pm,00_pm,00_pm,565.8_kJ_per_mol,false,},
{66,"Dy","Dysprosium",00,6,"f",8,162.5_Da,2,8.55,1680_degC,2840_degC,0.17,11.06,280,228_pm,00_pm,00_pm,573_kJ_per_mol,false,},
{67,"Ho","Holmium",00,6,"f",8,164.93033_Da,2,8.795,1734_degC,2993_degC,0.165,17,251,226_pm,00_pm,00_pm,581_kJ_per_mol,false,},
{68,"Er","Erbium",00,6,"f",8,167.259_Da,2,9.066,1802_degC,3141_degC,0.168,19.9,280,226_pm,00_pm,00_pm,589.3_kJ_per_mol,false,},
{69,"Tm","Thulium",00,6,"f",8,168.93422_Da,2,9.321,1818_degC,2223_degC,0.16,16.84,191,222_pm,00_pm,00_pm,596.7_kJ_per_mol,false,},
{70,"Yb","Ytterbium",00,6,"f",8,173.045_Da,2,6.965,1097_degC,1469_degC,0.155,7.66,129,222_pm,00_pm,00_pm,603.4_kJ_per_mol,false,},
{71,"Lu","Lutetium",00,6,"f",8,174.9668_Da,2,9.84,1925_degC,3675_degC,0.154,22,414,217_pm,160_pm,00_pm,523.5_kJ_per_mol,false,},
{72,"Hf","Hafnium",4,6,"d",3,178.49_Da,2,13.31,2506_degC,4876_degC,0.144,27.2,648,208_pm,150_pm,00_pm,658.5_kJ_per_mol,false,},
{73,"Ta","Tantalum",5,6,"d",3,180.94788_Da,2,16.654,3290_degC,5731_degC,0.14,36.57,732.8,200_pm,138_pm,00_pm,761_kJ_per_mol,false,},
{74,"W","Tungsten",6,6,"d",3,183.84_Da,2,19.25,3695_degC,5828_degC,0.132,52.31,806.7,193_pm,146_pm,00_pm,770_kJ_per_mol,false,},
{75,"Re","Rhenium",7,6,"d",3,186.207_Da,2,21.02,3459_degC,5869_degC,0.137,60.43,704,188_pm,159_pm,00_pm,760_kJ_per_mol,false,},
{76,"Os","Osmium",8,6,"d",3,190.23_Da,2,22.61,3306_degC,5285_degC,0.13,57.85,678,185_pm,128_pm,00_pm,840_kJ_per_mol,false,},
{77,"Ir","Iridium",9,6,"d",3,192.217_Da,2,22.56,2719_degC,4701_degC,0.131,41.12,564,180_pm,137_pm,00_pm,880_kJ_per_mol,false,},
{78,"Pt","Platinum",10,6,"d",3,195.084_Da,2,21.46,2041.4_degC,4098_degC,0.133,22.17,510,177_pm,128_pm,175_pm,870_kJ_per_mol,false,},
{79,"Au","Gold",11,6,"d",3,196.966569_Da,2,19.282,1337.33_degC,3129_degC,0.129,12.55,342,174_pm,144_pm,166_pm,890.1_kJ_per_mol,false,},
{80,"Hg","Mercury",12,6,"d",3,200.592_Da,1,13.5336,234.43_degC,629.88_degC,0.14,2.29,59.11,171_pm,149_pm,155_pm,1007.1_kJ_per_mol,false,},
{81,"Tl","Thallium",13,6,"p",4,204.38_Da,2,11.85,577_degC,1746_degC,0.129,4.14,165,156_pm,148_pm,196_pm,589.4_kJ_per_mol,false,},
{82,"Pb","Lead",14,6,"p",4,207.2_Da,2,11.342,600.61_degC,2022_degC,0.129,4.77,179.5,154_pm,147_pm,202_pm,715.6_kJ_per_mol,false,},
{83,"Bi","Bismuth",15,6,"p",4,208.9804_Da,2,9.807,544.7_degC,1837_degC,0.122,11.3,179,143_pm,146_pm,207_pm,703_kJ_per_mol,false,},
{84,"Po","Polonium",16,6,"p",5,209_Da,2,9.32,527_degC,1235_degC,00,13,102.91,135_pm,00_pm,197_pm,812.1_kJ_per_mol,true,},
{85,"At","Astatine",17,6,"p",6,210_Da,2,7,575_degC,610_degC,00,00,54.39,127_pm,00_pm,202_pm,899.003_kJ_per_mol,true,},
{86,"Rn","Radon",18,6,"p",7,222_Da,0,0.00973,202_degC,211.3_degC,0.094,3.247,18.1,120_pm,145_pm,220_pm,1037_kJ_per_mol,true,},
{87,"Fr","Francium",1,7,"s",1,223_Da,2,1.87,300_degC,950_degC,00,2,65,00_pm,00_pm,348_pm,380_kJ_per_mol,true,},
{88,"Ra","Radium",2,7,"s",2,226_Da,2,5.5,973_degC,2010_degC,0.094,8.5,113,00_pm,00_pm,283_pm,509.3_kJ_per_mol,true,},
{89,"Ac","Actinium",3,7,"d",9,227_Da,2,10.07,1323_degC,3471_degC,0.12,14,400,00_pm,00_pm,00_pm,499_kJ_per_mol,true,},
{90,"Th","Thorium",00,7,"f",9,232.0377_Da,2,11.72,2115_degC,5061_degC,0.113,13.81,514,00_pm,00_pm,00_pm,587_kJ_per_mol,true,},
{91,"Pa","Protactinium",00,7,"f",9,231.03588_Da,2,15.37,1841_degC,4300_degC,00,12.34,481,00_pm,00_pm,00_pm,568_kJ_per_mol,true,},
{92,"U","Uranium",00,7,"f",9,238.02891_Da,2,18.95,1405.3_degC,4404_degC,0.116,9.14,417.1,00_pm,00_pm,186_pm,597.6_kJ_per_mol,true,},
{93,"Np","Neptunium",00,7,"f",9,237_Da,2,20.45,917_degC,4273_degC,00,3.2,336,00_pm,00_pm,00_pm,604.5_kJ_per_mol,true,},
{94,"Pu","Plutonium",00,7,"f",9,244_Da,2,19.84,912.5_degC,3501_degC,00,2.82,333.5,00_pm,00_pm,00_pm,584.7_kJ_per_mol,true,},
{95,"Am","Americium",00,7,"f",9,243_Da,2,13.69,1449_degC,2880_degC,00,14.39,00,00_pm,00_pm,00_pm,578_kJ_per_mol,true,},
{96,"Cm","Curium",00,7,"f",9,247_Da,2,13.51,1613_degC,3383_degC,00,00,00,00_pm,00_pm,00_pm,581_kJ_per_mol,true,},
{97,"Bk","Berkelium",00,7,"f",9,247_Da,2,14.79,1259_degC,2900_degC,00,00,00,00_pm,00_pm,00_pm,601_kJ_per_mol,true,},
{98,"Cf","Californium",00,7,"f",9,251_Da,2,15.1,1173_degC,1743_degC,00,00,00,00_pm,00_pm,00_pm,608_kJ_per_mol,true,},
{99,"Es","Einsteinium",00,7,"f",9,252_Da,2,8.84,1133_degC,1269_degC,00,00,00,00_pm,00_pm,00_pm,619_kJ_per_mol,true,},
{100,"Fm","Fermium",00,7,"f",9,257_Da,2,9.7,1125_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,627_kJ_per_mol,true,},
{101,"Md","Mendelevium",00,7,"f",9,258_Da,2,10.3,1100_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,635_kJ_per_mol,true,},
{102,"No","Nobelium",00,7,"f",9,259_Da,2,9.9,1100_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,642_kJ_per_mol,true,},
{103,"Lr","Lawrencium",00,7,"f",9,266_Da,2,15.6,1900_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,470_kJ_per_mol,true,},
{104,"Rf","Rutherfordium",4,7,"d",3,267_Da,2,23.2,2400_degC,5800_degC,00,00,00,00_pm,00_pm,00_pm,580_kJ_per_mol,true,},
{105,"Db","Dubnium",5,7,"d",3,268_Da,2,29.3,00_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{106,"Sg","Seaborgium",6,7,"d",3,269_Da,2,35,00_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{107,"Bh","Bohrium",7,7,"d",3,270_Da,2,37.1,00_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{108,"Hs","Hassium",8,7,"d",3,277_Da,2,40.7,00_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{109,"Mt","Meitnerium",9,7,"d",3,278_Da,2,37.4,00_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{110,"Ds","Darmstadtium",10,7,"d",3,281_Da,2,34.8,00_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{111,"Rg","Roentgenium",11,7,"d",3,282_Da,2,28.7,00_degC,00_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{112,"Cn","Copernicium",12,7,"d",3,285_Da,1,23.7,00_degC,357_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{113,"Nh","Nihonium",13,7,"p",4,286_Da,2,16,700_degC,1400_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{114,"Fl","Flerovium",14,7,"p",4,289_Da,2,14,00_degC,210_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{115,"Mc","Moscovium",15,7,"p",4,290_Da,2,13.5,700_degC,1400_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{116,"Lv","Livermorium",16,7,"p",4,293_Da,2,12.9,709_degC,1085_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{117,"Ts","Tennessine",17,7,"p",4,294_Da,2,7.2,723_degC,883_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
{118,"Og","Oganesson",18,7,"p",7,294_Da,0,5,00_degC,350_degC,00,00,00,00_pm,00_pm,00_pm,00_kJ_per_mol,true,},
}; // (20 columns x 118 rows = 2360 cells)

} // namespace dataset

