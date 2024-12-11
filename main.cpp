//  Kadar Kaasik arvosana 4-5 hotelli varaus tehtävä
// uskon itse että työ on 4 arvosanan arvoinen

#include "iostream"
#include "fstream"

// ali-ohjelmien kutsua varten headerit

#include "arvonnat.h"
#include "structit.h"
#include "varaaminen.h"
#include "tarkistus.h"
#include "haku.h"

Globaali_hotelli Hotelli;
Globaali_varaus Varaus;

// " cout << "\033[2J\033[1;1H"; " Tämä komento tyhentää komento ikkunoiden ylijäämät tekstit näkyviltä 

int main()
{
	using namespace std;

	setlocale(LC_ALL, "FI_fi"); // suomen-kielen aakkoset näkyviin
	
	int valinta;

	alku_tarkistus_ja_toimet();
	
	while (true)
	{
		cout << "Tervetuloa hotelli varaus ohjelmaan" << endl << endl;
		cout << "Huoneiden generaatio (luo uudet huoneet) tyhjentää myös varaukset = 1" << endl;
		cout << "Varaa huone = 2" << endl;
		cout << "haku = 3" << endl;
		cout << "Sulje ohjelma = 4" << endl;

		cin.clear();

		cout << "Valintasi: ";
		cin >> valinta;

		cout << "\033[2J\033[1;1H";

		switch (valinta)
		{

		case 1:
			huoneiden_määrän_arvonta();
			break;
		
		case 2:
			huone_varaus();
			break;

		case 3:
			haku();
			break;

		case 4:
			return 0;

		}
		cout << "Paina mitä tahansa nappia jatkaaksesi....." << endl;

		cin.clear();
		cin.get();
		cin.ignore(),

		cout << "\033[2J\033[1;1H";
	}
}