// t‰ss‰ tiedostossa on kaikki tarkistukseen liittyv‰t ali-ohjelmat ja alku toimet ali-ohjelma

#include "iostream"
#include "fstream"
#include "vector"
#include "string"

#include "arvonnat.h"
#include "structit.h"


void alku_tarkistus_ja_toimet()
{
	using namespace std;

	string hotelli_huone;

	ifstream tiedosto_tarkistus; // t‰m‰ osio tarkistaa onko huoneiden m‰‰r‰ tiedosto olemassa
	tiedosto_tarkistus.open("hotelli.txt");
	
	if (tiedosto_tarkistus) {}
	else
	{
		huoneiden_m‰‰r‰n_arvonta(); // t‰m‰ ali-ohjelmaa luo arvotun m‰‰r‰n huoneita
	}
	tiedosto_tarkistus.close();

}

bool onko_huoneita_vapaana_1hh()
{

	// T‰m‰ ali-ohjelma tarkistaa onko kahden henkilˆn huoneita vapaana

	using namespace std;

	Hotelli.vapaat_arvotut_huoneet.clear(); // ett‰ voi varata monta kertaa per sessio

	string vapaa_1_hh_huone="1_hh_vapaa";
	string hotelli_huone;
	int huone_numero=0;

	fstream onko_huoneita_vapaana("hotelli.txt");

	// while loop k‰y l‰pi kaikki tiedoston rivit, jos lˆyt‰‰ vapaan huoneen niin huone numero (rivi numero) lis‰t‰‰n vektoriin yhdeksi arvoista

	while (getline(onko_huoneita_vapaana, hotelli_huone)) 
	{
		huone_numero++;

		if (hotelli_huone.find(vapaa_1_hh_huone) != string::npos)
			Hotelli.vapaat_arvotut_huoneet.push_back(huone_numero);
	}
	onko_huoneita_vapaana.close();

	if (Hotelli.montako_huonetta <= Hotelli.vapaat_arvotut_huoneet.size())
		return true;
	else
		return false;
}

bool onko_huoneita_vapaana_2hh()
{

	// T‰m‰ ali-ohjelma tarkistaa onko kahden henkilˆn huoneita vapaana

	using namespace std;

	Hotelli.vapaat_arvotut_huoneet.clear(); // ett‰ voi varata monta kertaa per sessio

	string vapaa_2_hh_huone = "2_hh_vapaa";
	string hotelli_huone;
	int huone_numero = 0;

	fstream onko_huoneita_vapaana("hotelli.txt");

	// while loop k‰y l‰pi kaikki tiedoston rivit, jos lˆyt‰‰ vapaan huoneen niin huone numero (rivi numero) lis‰t‰‰n vektoriin yhdeksi arvoista

	while (getline(onko_huoneita_vapaana, hotelli_huone))
	{
		huone_numero++;

		if (hotelli_huone.find(vapaa_2_hh_huone) != string::npos)
			Hotelli.vapaat_arvotut_huoneet.push_back(huone_numero);
	}

	onko_huoneita_vapaana.close();

	if (Hotelli.montako_huonetta <= Hotelli.vapaat_arvotut_huoneet.size())
		return true;
	else
		return false;
}

void uniikki_varausnumero()
{
	// T‰m‰ ali-ohjelma tarkistaa onko generoitu varaus numero uniikki jos ei ole, niin generoi uuden kunnes se on uniikki

	varaus_numero_arvonta();

	using namespace std;

	fstream onko_sama_varausnumero("hotelli.txt");

	string hotelli_huone;

	while (getline(onko_sama_varausnumero, hotelli_huone))
	{
		if (hotelli_huone.find(Varaus.varaus_numero) != string::npos)
			uniikki_varausnumero();

	}
	onko_sama_varausnumero.close();
}
