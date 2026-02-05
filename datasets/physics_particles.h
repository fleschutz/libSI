// DO NOT EDIT! Data source is physics_particles.csv (converted by github.com/fleschutz/csv2hpp 0.3 on 2026-02-04)
#pragma once
#include <SI/literals.h>
using namespace SI;

namespace dataset { 

struct particle_data {
	int pdg_id;                               // column  1 (int) in CSV file
	const char* pdg_name;                     // column  2 (string) in CSV file
	const char* name;                         // column  3 (string) in CSV file
	float charge;                             // column  4 (float) in CSV file
	float rank;                               // column  5 (float) in CSV file
	const char* quarks;                       // column  6 (string) in CSV file
	SI::mass mass;                            // column  7 (_Da) in CSV file
	SI::mass mass_lower;                      // column  8 (_kg) in CSV file
	SI::mass mass_upper;                      // column  9 (_kg) in CSV file
	SI::length width;                         // column 10 (_m) in CSV file
	SI::length width_lower;                   // column 11 (_m) in CSV file
	SI::length width_upper;                   // column 12 (_m) in CSV file
};

const particle_data particles[] { // NOTE: 00=empty or unknown field
{-2212,"p","anti_proton",-1.,4,"UUD",938.27208816_Da,2.9e-07_kg,2.9e-07_kg,0._m,0._m,0._m,},
{-2112,"n","anti_neutron",0.,4,"UDD",939.5654205_Da,5e-07_kg,5e-07_kg,7.493e-25_m,4e-28_m,4e-28_m,},
{-321,"K","kaon-",-1.,0,"Us",493.677_Da,0.016_kg,0.016_kg,5.317e-14_m,9e-17_m,9e-17_m,},
{-211,"pi","pion0",-1.,0,"Ud",139.57039_Da,0.00018_kg,0.00018_kg,2.5284e-14_m,5e-18_m,5e-18_m,},
{-24,"W","W-",-1.,0,"-",80379._Da,12._kg,12._kg,2080._m,40._m,40._m,},
{-16,"nu(tau)","anti_tau_neutrino",0.,0,"-",00_Da,00_kg,00_kg,0._m,0._m,0._m,},
{-15,"tau","anti_tau",1.,0,"-",1776.86_Da,0.12_kg,0.12_kg,2.267e-09_m,4e-12_m,4e-12_m,},
{-14,"nu(mu)","anti_muon_neutrino",0.,0,"-",00_Da,00_kg,00_kg,0._m,0._m,0._m,},
{-13,"mu","anti_muon",1.,0,"-",105.6583755_Da,2.3e-06_kg,2.3e-06_kg,2.9959836e-16_m,3e-22_m,3e-22_m,},
{-12,"nu(e)","anti_electron_neutrino",0.,0,"-",00_Da,00_kg,00_kg,0._m,0._m,0._m,},
{-11,"e","anti_electron (positron)",1.,0,"-",0.51099895_Da,1.5e-1_kg,1.5e-1_kg,0._m,0._m,0._m,},
{-6,"t","anti_top",-0.6666666666666666,0,"T",172500._Da,700._kg,700._kg,1420._m,150._m,190._m,},
{-5,"b","anti_bottom",0.3333333333333333,0,"B",4180._Da,20._kg,30._kg,00_m,00_m,00_m,},
{-4,"c","anti_charm",-0.6666666666666666,0,"C",1270._Da,20._kg,20._kg,00_m,00_m,00_m,},
{-3,"s","anti_strange",0.3333333333333333,0,"S",93.4_Da,3.4_kg,8.6_kg,00_m,00_m,00_m,},
{-2,"u","anti_up",-0.6666666666666666,0,"U",2.16_Da,0.3_kg,0.5_kg,00_m,00_m,00_m,},
{-1,"d","anti_down",0.3333333333333333,0,"D",4.67_Da,0.2_kg,0.5_kg,00_m,00_m,00_m,},
{1,"d","down",-0.3333333333333333,0,"d",4.67_Da,0.2_kg,0.5_kg,00_m,00_m,00_m,},
{2,"u","up",0.6666666666666666,0,"u",2.16_Da,0.3_kg,0.5_kg,00_m,00_m,00_m,},
{3,"s","strange",-0.3333333333333333,0,"s",93.4_Da,3.4_kg,8.6_kg,00_m,00_m,00_m,},
{4,"c","charm",0.6666666666666666,0,"c",1270._Da,20._kg,20._kg,00_m,00_m,00_m,},
{5,"b","bottom",-0.3333333333333333,0,"b",4180._Da,20._kg,30._kg,00_m,00_m,00_m,},
{6,"t","top",0.6666666666666666,0,"t",172500._Da,700._kg,700._kg,1420._m,150._m,190._m,},
{11,"e","electron",-1.,0,"-",0.51099895_Da,1.5e-1_kg,1.5e-1_kg,0._m,0._m,0._m,},
{12,"nu(e)","electron_neutrino",0.,0,"-",00_Da,00_kg,00_kg,0._m,0._m,0._m,},
{13,"mu","muon",-1.,0,"-",105.6583755_Da,2.3e-06_kg,2.3e-06_kg,2.9959836e-16_m,3e-22_m,3e-22_m,},
{14,"nu(mu)","muon_neutrino",0.,0,"-",00_Da,00_kg,00_kg,0._m,0._m,0._m,},
{15,"tau","tau",-1.,0,"-",1776.86_Da,0.12_kg,0.12_kg,2.267e-09_m,4e-12_m,4e-12_m,},
{16,"nu(tau)","tau_netrino",0.,0,"-",00_Da,00_kg,00_kg,0._m,0._m,0._m,},
{21,"g","gluon",0.,0,"-",0._Da,0._kg,0._kg,0._m,0._m,0._m,},
{22,"gamma","photon",0.,0,"-",0._Da,0._kg,0._kg,0._m,0._m,0._m,},
{23,"Z","Z0",0.,0,"-",91187.6_Da,2.1_kg,2.1_kg,2495.2_m,2.3_m,2.3_m,},
{24,"W","W+",1.,0,"-",80379._Da,12._kg,12._kg,2080._m,40._m,40._m,},
{25,"H","higgs",0.,0,"-",125250._Da,170._kg,170._kg,3.2_m,2.2_m,2.8_m,},
{111,"pi","pion-",0.,0,"(uU-dD)/sqrt(2)",134.9768_Da,0.0005_kg,0.0005_kg,7.81e-06_m,1.2e-07_m,1.2e-07_m,},
{211,"pi","pion+",1.,0,"uD",139.57039_Da,0.00018_kg,0.00018_kg,2.5284e-14_m,5e-18_m,5e-18_m,},
{321,"K","kaon+",1.,0,"uS",493.677_Da,0.016_kg,0.016_kg,5.317e-14_m,9e-17_m,9e-17_m,},
{2112,"n","neutron",0.,4,"udd",939.5654205_Da,5e-07_kg,5e-07_kg,7.493e-25_m,4e-28_m,4e-28_m,},
{2212,"p","proton",1.,4,"uud",938.27208816_Da,2.9e-07_kg,2.9e-07_kg,0._m,0._m,0._m,},
{3112,"Sigma","sigma-",-1.,4,"dds",1197.449_Da,0.03_kg,0.03_kg,4.45e-12_m,3.2e-14_m,3.2e-14_m,},
{3122,"Lambda","lambda0",0.,4,"uds",1115.683_Da,0.006_kg,0.006_kg,2.501e-12_m,1.9e-14_m,1.9e-14_m,},
{3212,"Sigma","sigma0",0.,4,"uds",1192.642_Da,0.024_kg,0.024_kg,0.0089_m,0.0008_m,0.0009_m,},
{3222,"Sigma","sigma+",1.,4,"uus",1189.37_Da,0.07_kg,0.07_kg,8.209e-12_m,2.7e-14_m,2.7e-14_m,},
{3312,"Xi","xi-",-1.,4,"dss",1321.71_Da,0.07_kg,0.07_kg,4.02e-12_m,4e-14_m,4e-14_m,},
{3322,"Xi","xi0",0.,4,"uss",1314.86_Da,0.2_kg,0.2_kg,2.27e-12_m,7e-14_m,7e-14_m,},
{3334,"Omega","omega-",-1.,4,"sss",1672.45_Da,0.29_kg,0.29_kg,8.02e-12_m,1.1e-13_m,1.1e-13_m,},
}; // (12 columns x 47 rows = 564 cells)

} // namespace dataset

