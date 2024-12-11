// tämä ali-ohjelma suorittaa haun

#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "structit.h"
#include "algorithm"

int haku()
{
	using namespace std;
	string tiedosto_line,varausnumero,nimi,tiedot;
	int vastaus,huone_numero=0;
	vector<int> huone_numero_vec;

	huone_numero_vec.clear();
	fstream tiedosto_haku("hotelli.txt");

	
	
	do
	{
		cout << "Tahdotko etsiä varauksen nimellä tai varausnumerolla" << endl;
		cout << "Varausnumerolla = 1" << endl;
		cout << "Nimellä = 2" << endl;
		cout << "Valintasi: ";
		cin >> vastaus;
		
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');

		}
		

	} while (vastaus != 1 && vastaus != 2);

	switch (vastaus)
	{

	case 1:
		
		cout << "syötä varausnumerosi: ";
		cin >> varausnumero;

		while (getline(tiedosto_haku, tiedosto_line))
		{
			huone_numero++;

			if (tiedosto_line.find(varausnumero) != string::npos)
			{
				huone_numero_vec.push_back(huone_numero);
				tiedot = tiedosto_line;
			
			}
		}
		
		break;


	case 2:
		cout << "syötä nimesi (tarkista että kirjotat sen kuin sen kirjoitit varaessasi): ";

		cin.ignore();
		getline(cin, nimi);

		while (getline(tiedosto_haku, tiedosto_line))
		{
			huone_numero++;

			if (tiedosto_line.find(nimi) != string::npos)
			{
				huone_numero_vec.push_back(huone_numero);
				tiedot = tiedosto_line;

			}
		
		}
			
		break;
	
	}

	if (huone_numero_vec.size() == 0)
	{
		cout << "hakemaasi varausta ei löytynyt" << endl;
		return 0;

	}



	tiedot.erase(0, 12);
	sort(huone_numero_vec.begin(), huone_numero_vec.end());

	cout << "Varauksia löytyi" << endl;
	cout << "Varauksen tiedot: " << tiedot << endl;
	cout << "Henkilön varaamat huoneet: ";
	for (int n = 0; n < huone_numero_vec.size(); n++)
		cout << huone_numero_vec[n] << " ";
	cout << endl;
	return 0;


}