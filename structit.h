// varaus_struct.h

#include "string"
#include "vector"

#ifndef STRUCTIT_H
#define STRUCTIT_H


struct Globaali_hotelli
{
	int hotellin_huoneiden_m‰‰r‰=0;
	int temp_arvottu_huone;
	std::vector <int> vapaat_arvotut_huoneet;
	std::vector <std::string> kaikki_huoneet;
	float alennus_m‰‰r‰;
	float huone_hinta;
	int montako_huonetta;
	int moneenko_hengen_huone = 0;
	int montako_yˆt‰;
	std::vector <int> varaajan_arvotut_huoneet;



};

struct Globaali_varaus
{
	std::string varaajan_nimi;
	std::string varaus_numero;
	std::string lasku;
};

// t‰m‰ ett‰ voin k‰ytt‰‰ sama structin instanssia eri tiedostoissa

extern Globaali_hotelli Hotelli; 
extern Globaali_varaus Varaus;

#endif