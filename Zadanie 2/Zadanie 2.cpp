#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
/*bool czy_graf_jest_spojny(vector<vector<int>> graf) {
	int n = graf.size();

	for ()
}*/
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
	for (int x = 0; x < liczba_wierzcholkow; x++) {
		sort(graf[x].begin(), graf[x].end());
		graf[x].erase(unique(graf[x].begin(), graf[x].end()), graf[x].end());
	}
	return 0;

}