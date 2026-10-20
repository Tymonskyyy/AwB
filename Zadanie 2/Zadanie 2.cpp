#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream plik("graf.txt");
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
	//twoj staryu
	plik.close();
	cout << "Wczytany graf: " << endl;

	for (int i = 0; i < liczba_wierzcholkow; i++) {
		cout << "Wierzcholek " << i << ": ";
		for (int j = 0; j < graf[i].size(); j++) {
			cout << graf[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}