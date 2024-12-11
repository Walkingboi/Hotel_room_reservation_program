// t�m� ali-ohjelma suorittaa huone varaukset

#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "algorithm"

#include "arvonnat.h"
#include "structit.h"
#include "tarkistus.h"



int huone_varaus()
{
	// t�m� ali-ohjelma tekee huonevarauksen mik� tallentuu hotelli.txt tiedostoon

	using namespace std;
	string vastaus;

	cout << "sy�t� varaajan nimi: " << endl;

	cin.ignore();

	getline(cin, Varaus.varaajan_nimi); // ett� v�li ly�nnit ei katkaise string arvoa


	do  // sy�te tarkistus
	{
		cout << endl << "Mink� kokoisen huoneen varaaja haluaa (1 hh tai 2 hh)" << endl;
		cin >> Hotelli.moneenko_hengen_huone;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
		
		}
	} while (Hotelli.moneenko_hengen_huone != 1 && Hotelli.moneenko_hengen_huone != 2);


	do // sy�te tarkistus
	{
		cout << "Montako huonetta varaaja tahtoo" << endl;
		cin >> Hotelli.montako_huonetta;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
		}

	} while (Hotelli.montako_huonetta==0);


	if (Hotelli.moneenko_hengen_huone == 1)
	{
		Hotelli.huone_hinta = 100;

		if (onko_huoneita_vapaana_1hh())
			mik�_huone_arvonta();
		else
		{
			while (!onko_huoneita_vapaana_1hh())
			{
				cout << "Valitettavasti yhden hengen huoneita ei ole tarpeeksi\nYhden hengen huoneita vapaana on ";
				cout << Hotelli.vapaat_arvotut_huoneet.size() << "kappaletta" << endl;
				do
				{
					cout << "Tahdotko palata takaisin p�� valikkoon ?" << endl;
					cout << "vastaus (k tai e): ";
					cin >> vastaus;

					if (vastaus == "k")
					{
						cout << "Palaat p�� valikkoon";
						return 0;
					}

				} while (vastaus != "k" && vastaus != "e");
				
				cout << "Valitse huone m��r� uudelleen" << endl;
				cin >> Hotelli.montako_huonetta;
			}

			mik�_huone_arvonta();
		}
	}
	

	if (Hotelli.moneenko_hengen_huone == 2)
	{	
		Hotelli.huone_hinta = 150;

		if (onko_huoneita_vapaana_2hh() == true)
			mik�_huone_arvonta();
		else
		{
			while (!onko_huoneita_vapaana_2hh())
			{
				cout << "Valitettavasti kahden hengen huoneita ei ole tarpeeksi\nKahden hengen huoneita vapaana on " << endl;
				cout << Hotelli.vapaat_arvotut_huoneet.size() << " kappaletta" << endl;
				do
				{
					cout << "Tahdotko palata takaisin p�� valikkoon ?" << endl;
					cout << "vastaus (k tai e): ";
					cin >> vastaus;

					if (vastaus == "k")
					{
						cout << "Palaat p�� valikkoon";
						return 0;
					}

				} while (vastaus != "k" && vastaus != "e");
				
				cout << "Valitse huone m��r� uudelleen" << endl;
				cin >> Hotelli.montako_huonetta;
			}

			mik�_huone_arvonta();
		}

	}

	cout << "Montako y�t� varaaja haluaa varata huoneet" << endl;
	cin >> Hotelli.montako_y�t�;
	
	alennus_arvonta();

	int loppu_summa = round(Hotelli.alennus_m��r� * Hotelli.montako_huonetta * Hotelli.huone_hinta * Hotelli.montako_y�t�);

	cout << "Loppusummasi on " << loppu_summa << " euroa  " << "saitte " << 100-Hotelli.alennus_m��r�*100 << "% alennusta" << endl;

	do
	{
		cout << "Tahdotko tehd� varauksen ?" << endl;
		cout << "vastaus (k tai e): ";
		cin >> vastaus;

		if (vastaus == "e")
		{
			cout << "Palaat p�� valikkoon";
			return 0;
		}
	
	} while (vastaus != "k" && vastaus !="e");


	fstream tiedosto_vektoriksi("hotelli.txt");
	string tiedosto_line;

	Hotelli.kaikki_huoneet.clear(); // ett� voi tehd� monta varausta per sessio

	while (getline(tiedosto_vektoriksi, tiedosto_line)) // antaa tiedostosta huoneiden si�ll�t vektoriin
	{
		Hotelli.kaikki_huoneet.push_back(tiedosto_line);
	}
	
	tiedosto_vektoriksi.close();

	string varattu;
	string formatointi = "    ";
	Varaus.lasku = to_string(loppu_summa);

	uniikki_varausnumero(); // luo uniikin varausnumeron

	if (Hotelli.moneenko_hengen_huone == 1) 
		varattu = "1_hh_varattu";
	
	if(Hotelli.moneenko_hengen_huone==2)
		varattu = "2_hh_varattu";

	varattu = varattu + formatointi + "Varaus numero: " + Varaus.varaus_numero+ formatointi + Varaus.varaajan_nimi + formatointi 
		+ "Varauksen hinta: " + Varaus.lasku + " euroa";


	for (int n = 0; n < Hotelli.varaajan_arvotut_huoneet.size(); n++) // antaa vektorille varaajan tiedot arvotuille kohdille
		Hotelli.kaikki_huoneet[Hotelli.varaajan_arvotut_huoneet[n]-1] = varattu;


	fstream vektori_tiedostoon("hotelli.txt");

	for (int n = 0; n < Hotelli.kaikki_huoneet.size()-1; n++)
		vektori_tiedostoon << Hotelli.kaikki_huoneet[n] << endl;

	vektori_tiedostoon << Hotelli.kaikki_huoneet[Hotelli.kaikki_huoneet.size()-1]; // ett� ei j�isi tyhj� rivi tiedostoon

	vektori_tiedostoon.close();

	cout << "Varaus on tallenettu j�rjestelm��n. varaus tiedot ovat" << endl << endl;
	cout << "varaajan nimi: " << Varaus.varaajan_nimi << endl;
	cout << "Varaus numero: " << Varaus.varaus_numero << endl;
	cout << "Huone numerot: ";
	
	sort(Hotelli.varaajan_arvotut_huoneet.begin(), Hotelli.varaajan_arvotut_huoneet.end());
	for (int n = 0; n < Hotelli.varaajan_arvotut_huoneet.size(); n++)
		cout << Hotelli.varaajan_arvotut_huoneet[n] << " ";

	cout << endl;

	return 0;

	

}

