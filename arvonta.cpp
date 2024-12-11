// t‰ss‰ tiedostossa on kaikki arvontaan liittyv‰t ali-ohjelmat

#include "iostream"
#include "random"
#include "fstream"
#include "vector"
#include "chrono"
#include "algorithm"

#include "structit.h"
#include "tarkistus.h"



void huoneiden_m‰‰r‰n_arvonta()  
{
	// t‰m‰ ali-ohjelma arpoo huoneiden m‰‰r‰n uudestaan ja tallentaa huoneiden m‰‰r‰n ja tyypin (1_hh tai 2_hh) tiedostoon
	// voi myˆs mietti‰ t‰t‰ reset ohjelmana

	using namespace std;

	const int huone_m‰‰r‰_min = 40, huone_m‰‰r‰_max = 300;
	
	
	fstream huoneiden_m‰‰r‰_reset("hotelli.txt", fstream::out); // t‰m‰ tyhjent‰‰ tiedoston vanhan arvonnan
	huoneiden_m‰‰r‰_reset.close();

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
	default_random_engine arvonta_huoneet(seed);

	// kahdella jakamiset ja kertomiset on simppeli tapa varmistaa, ett‰ huoneiden arvottu m‰‰r‰ on aina parillinen m‰‰r‰

	uniform_int_distribution<int> jakautuma(huone_m‰‰r‰_min/2, huone_m‰‰r‰_max/2);
	int arvottujen_huoneiden_m‰‰r‰ = jakautuma(arvonta_huoneet)*2;

	// t‰st‰ osiosta alkaen arvotun m‰‰r‰n mukaan tiedostoon luodaan 1_hh_vapaa ja 2_hh_vapaa
	fstream huoneiden_m‰‰r‰_file("hotelli.txt");

	for (int n = 1; n <= arvottujen_huoneiden_m‰‰r‰/2 ; n++)
	{
		huoneiden_m‰‰r‰_file << "1_hh_vapaa" << endl;
	}

	for (int n = arvottujen_huoneiden_m‰‰r‰/2; n <= arvottujen_huoneiden_m‰‰r‰-2; n++)
	{
		huoneiden_m‰‰r‰_file << "2_hh_vapaa" << endl;
	}

	huoneiden_m‰‰r‰_file << "2_hh_vapaa"; // ett‰ tiedostoon ei j‰isi tyhj‰ rivi

	huoneiden_m‰‰r‰_file.close();

	cout << "huoneita luotiin: " << arvottujen_huoneiden_m‰‰r‰ << endl;

}

void varaus_numero_arvonta()
{
	// t‰m‰ ali-ohjelma arpoo varausnumeron

	using namespace std;

	const int varaus_numero_min = 10000, varaus_numero_max = 99999;
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine arvonta_varausnumerot(seed);
	uniform_int_distribution<int> jakautuma(varaus_numero_min, varaus_numero_max);

	Varaus.varaus_numero = to_string(jakautuma(arvonta_varausnumerot));

	
}

void alennus_arvonta()
{
	// t‰m‰ ali-ohjelma arpoo alennuksen m‰‰r‰n

	using namespace std;

	float alennukset[] = { 1,0.9,0.8 };

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine arvonta_alennukset(seed);

	uniform_int_distribution<int> jakautuma(0, 2);

	Hotelli.alennus_m‰‰r‰ = alennukset[jakautuma(arvonta_alennukset)];

	

}
void mik‰_huone_arvonta() 
{
	// t‰m‰ ali-ohjelma arpoo vapaista huoneista varaajalle huoneet valitun m‰‰r‰n mukaan ilman duplikaatteja

	Hotelli.varaajan_arvotut_huoneet.clear(); // ett‰ voi varata monta kertaa per sessio

	using namespace std;
	
	uniform_int_distribution<int> jakautuma(0, Hotelli.vapaat_arvotut_huoneet.size()-1); // 0:lla alkaa ja -1 koska vektorit alkaa 0:sta

		
	while (Hotelli.montako_huonetta > Hotelli.varaajan_arvotut_huoneet.size())
	{

		unsigned seed = chrono::system_clock::now().time_since_epoch().count();

		default_random_engine arvonta_mik‰_huone(seed);

		int mik‰_huone = jakautuma(arvonta_mik‰_huone);
		
		// t‰m‰ if lause toimii seuraavasti, jos find p‰‰se loppuun eli ei lˆyd‰ Varaus vektorista samaa arvoa
		// kuin Hotelli vektorista niin if lause toteutuu ja Varaus vektori saa mik‰ huone arvon 

		if (find(Hotelli.varaajan_arvotut_huoneet.begin(), Hotelli.varaajan_arvotut_huoneet.end(), Hotelli.vapaat_arvotut_huoneet[mik‰_huone])
			== Hotelli.varaajan_arvotut_huoneet.end())
			 
			Hotelli.varaajan_arvotut_huoneet.push_back(Hotelli.vapaat_arvotut_huoneet[mik‰_huone]);

	}

	
}
