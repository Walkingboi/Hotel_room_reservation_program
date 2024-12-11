Tämä tehtävä tosiaan on minun loppu työ c++ ohjelmoinnin perusteet kurssille.
Ohjelman toteutus seuraa 4-5 arvosanan tehtävä antoa.
Ohjelmassa on 3 toimintoa.
huoneiden arvonta, huone varaus ja varauksien haku.
ominaisuudet suoritetaan pää valikon kautta mikä sijaitsee main funktiossa. itse toimitojen suorittaminen tapahtuu switch case avulla

huoneiden arvonta toimii siten että ali-ohjelma  arpoo 40 ja 300 väliltä parillisen määrän huoneita mitkä on nimetty puoliksi 1_hh_vapaa
ja toiseksi puoleksi 2_hh_vapaa. Nämä tallenetaan tiedostoon. sama ali-ohjelma luo myös tiedoston jos sitä ei ole.
main alussa myös tarkistetaan onko tiedostoa olemassa. jos ei ole niin tämä ali-ohjelma kutsutaan.

huone varaus aloitta kysymyllä varaajan nimen mikä otetaan getline komennolla, sen jälkeen otetaan talteen että moneenko_hengen_huonetta varataan tämä on syöte tarkistettu.
sitten kysytään montako huonetta varataan myöskin syöte tarkistettu. Näiden kahden edellisen tiedon pohjalta tarkistetaan onko huone tyyppiä valitseman määrän mukaisesti vapaana varattavaksi. tämä suoritetaan bool tyylisellä ali ohjelmalla. Jos huoneita ei ole valitsema määrä vapaana ohjelma antaa valita uuden määrän tai palata pää valikkoon.
jos bool on true niin käynistyy ali-ohjelma mikä arpoo vapaiden huoneiden joukoista valitun määrän huoneita. valitun huone tyypin mukaan myös määritellään yhden huoneen hinta
seuraavaksi ohjelma kysyy ilta määrän ja antaa lasku määrän. Ohjelma tämän jälkeen kysyy haluatko suorittaa itse varauksen. jos valinta on ei niin ohjelma palaa pää valikkoon. Jos vastaus on positiivinen annetut arvot lisätään teksti tiedostoon vektoreiden avulla. Ohjelma lopulta piirtää ruudulle varaajan tiedot kuten varaus numero mikä arvottiiin kun varauksen teko hyväksyttiin. myöskin huone numerot piiretään.

haku toiminto on simppeli ohjelma käy läpi jokaisen rivin tiedostosta while loopin avulla. joka iteraatiossa muuttuja saa +1 arvoonsa. jos if lause whilin sisällä aktivoituu mikä siis tarkistaa että onko käyttäjän syöttämä arvo rivillä (joko varaus numero tai nimi) niin string arvo saa rivin arvon (mikä on yksi iso string arvo itsessäään) myöskin vectori saa arvon huone_numero. Lopulta keräämät arvot piiretään käyttäjälle.

pari muuta asiaa koodista. Käytin runsaasti structin arvoja että voin käyttää muutujia eri tiedostoissa. Myöskin jokainen arvonta mikä ohjelmassa tapahtuu on arvottu tietokone aikaa seedinä.






