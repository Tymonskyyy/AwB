#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
bool czyGrafSprzezony(vector<vector<int>> graf) {
	int iloscwierzchołkow = graf.size();

	for (int i = 0; i < iloscwierzchołkow; i++) {
		for (int j = i + 1; j < iloscwierzchołkow; j++) {
			bool maja_wspolny_wierzcholek = false;
			for (int x = 0; x < graf[i].size(); x++) {
				for (int y = 0; y < graf[j].size(); y++) {
					if (graf[i][x] == graf[j][y]) {
						maja_wspolny_wierzcholek = true;
						break;
					}
				}
			}
			if (maja_wspolny_wierzcholek == true) {
				if (graf[i] != graf[j]) {
					return false;
				}
			}
		}
	}
	return true;
}

vector<vector<int>> przeksztalceniegrafu(vector<vector<int>> graf) {
	int liczba_starych_wierzcholkow = graf.size();

	vector<int> poczateklini(liczba_starych_wierzcholkow);
	vector<int> konieclini(liczba_starych_wierzcholkow);

	for (int i = 0; i < liczba_starych_wierzcholkow; i++) {
		poczateklini[i] = 2 * i;
		konieclini[i] = 2* i + 1;
	}
	cout << "Etap 1 Tworzenia H" << endl;
	for (int c = 0; c < liczba_starych_wierzcholkow; c++) {
		cout << "Wierzcholek " << c << ": " << poczateklini[c] << " " << konieclini[c] << endl;
	}
	vector<vector<int>> pusty_graf;
	return pusty_graf;
}

int main() {
	string nazwa_pliku;
	cout << "Podaj nazwe pliku z grafem: ";
	cin >> nazwa_pliku;


	ifstream plik(nazwa_pliku);

	if (!plik.is_open()) {
		cout << "Nie mozna otworzyc pliku!" << endl;
		return 1;
	}

	int liczba_wierzcholkow;
	plik >> liczba_wierzcholkow;

	vector<vector<int>> graf(liczba_wierzcholkow);

	int poczatek, koniec;
	while (plik >> poczatek >> koniec) {
		if (poczatek >= 0 && poczatek < liczba_wierzcholkow && koniec >= 0 && koniec < liczba_wierzcholkow) {
			graf[poczatek].push_back(koniec);
		}
		else {
			cout << "Nieprawidlowe dane w pliku!" << endl;
			return 1;

		}
	}

	plik.close();
	cout << "Wczytany graf: " << endl;

	for (int i = 0; i < liczba_wierzcholkow; i++) {
		cout << "Wierzcholek " << i << ": ";
		for (int j = 0; j < graf[i].size(); j++) {
			cout << graf[i][j] << " ";
		}
		cout << endl;
	}
	for (int x = 0; x < liczba_wierzcholkow; x++) {
		sort(graf[x].begin(), graf[x].end());
		graf[x].erase(unique(graf[x].begin(), graf[x].end()), graf[x].end());
	}
	if (czyGrafSprzezony(graf)) {
		cout << "Graf jest sprzezony." << endl;
		vector<vector<int>> przeksztalconyGraf = przeksztalceniegrafu(graf);
	}
	else {
		cout << "Graf nie jest sprzezony." << endl;
	}
	return 0;

}