// BAMI.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <complex>
#include <string.h>
#include <algorithm>
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
#define M_PI           3.14159265508979323846 
#define Tb 0.001
#define A1 0.0
#define A2 1.0
#define N 2
#define rozmiar11 42
#define rozmiar22 48
using namespace std;
string S2BS(int i[], int size) {
	fstream plik1;
	plik1.open("S2BS.txt", ios::out | ios::trunc);
	int j = 0;
	int slowo[100];
	//cout << size1;
	//std::vector<std::string> slowo1;
	string slowo1;
	char buffer[100];
	for (j; j < size; j++) {
		_itoa_s(i[j], buffer, 2);
		//printf("binary: %s\n", buffer);
		//slowo1.push_back(buffer);
		slowo1 = slowo1 + "0" + buffer;
	}
	for (int i = 0; i < size * 8; i++) {
		plik1 << slowo1[i] << endl;
	}
	plik1.close();
	return slowo1;
}
void clk(int size) {
	fstream plik;
	plik.open("clk.txt",ios::out | ios::trunc);
	double f = 0.0;
	int z = 1;
	int j;
	for (int i = 0; i < size*2;i++) {
		for (int j = 0; j < 50;j++) {
			plik << f << " " << z << endl;
			f += Tb;
		}
		if (z == 1) {
			z = 0;
		}
		else z = 1;
	}


	plik.close();
}
void mancherster(int size) {
	fstream plik;
	plik.open("manchester.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("manchesterinv.txt", ios::out | ios::trunc);
	fstream plik1;
	plik1.open("S2BS.txt", ios::in);
	double tab[3200];
	double tmp;
	int size1 = size  * 100;
	int size2 = size * 8;
	double wynik[3200];
	double f = 0.0;
	int j = 0;
	int c = 1;
	for (int i = 0; i < size1;i++) {
		plik1 >> tmp >> tab[i];
	}
	for (int i = 0; i < size1;i+=50) {
		if (i < 50) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = 0;
				plik << f << " " << wynik[z] << endl;
				f += Tb;
			}

		}
		else if (i< 100) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = -1;
				plik << f << " " << wynik[z] << endl;
				f += Tb;
			}
		}
		else {
			if (c % 2 == 1) {
				if (wynik[20] == 1) {
					for (int z = 0; z < 50; z++) {
						wynik[z] = -1;
						plik << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
				else if (wynik[20] == -1) {
					for (int z = 0; z < 50; z++) {
						wynik[z] = 1;
						plik << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
			}
			else if (c % 2 ==0) {
				if (tab[i+1] == 1) {
					for (int z = 0; z < 50; z++) {
						plik << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
				else if (tab[i+1] == 0) {
					if (wynik[20] == 1) {
						for (int z = 0; z < 50; z++) {
							wynik[z] = -1;
							plik << f << " " << wynik[z] << endl;
							f += Tb;
						}
					}
					else if (wynik[20] == -1) {
						for (int z = 0; z < 50; z++) {
							wynik[z] = 1;
							plik << f << " " << wynik[z] << endl;
							f += Tb;
						}
					}
				}
			}
			c = c + 1;
		}
	}
	c = 1;
	f = 0.0;
	for (int i = 0; i < size1; i += 50) {
		if (i < 50) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = 0;
				plik2 << f << " " << wynik[z] << endl;
				f += Tb;
			}

		}
		else if (i < 100) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = 1;
				plik2 << f << " " << wynik[z] << endl;
				f += Tb;
			}
		}
		else {
			if (c % 2 == 1) {
				if (wynik[20] == 1) {
					for (int z = 0; z < 50; z++) {
						wynik[z] = -1;
						plik2 << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
				else if (wynik[20] == -1) {
					for (int z = 0; z < 50; z++) {
						wynik[z] = 1;
						plik2 << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
			}
			else if (c % 2 == 0) {
				if (tab[i + 1] == 1) {
					for (int z = 0; z < 50; z++) {
						plik2 << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
				else if (tab[i + 1] == 0) {
					if (wynik[20] == 1) {
						for (int z = 0; z < 50; z++) {
							wynik[z] = -1;
							plik2 << f << " " << wynik[z] << endl;
							f += Tb;
						}
					}
					else if (wynik[20] == -1) {
						for (int z = 0; z < 50; z++) {
							wynik[z] = 1;
							plik2 << f << " " << wynik[z] << endl;
							f += Tb;
						}
					}
				}
			}
			c = c + 1;
		}
	}

	plik1.close();
	plik2.close();
	plik.close();
}
void nrzi(int size) {
	fstream plik;
	plik.open("nrzi.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("nrziinv.txt", ios::out | ios::trunc);
	fstream plik1;
	plik1.open("S2BS.txt", ios::in);
	double tab[3200];
	double tmp;
	int size1 = size * 100;
	int size2 = size * 8;
	double wynik[3200];
	double f = 0.0;
	int j = 0;
	int c = 1;
	bool check = false;
	for (int i = 0; i < size1; i++) {
		plik1 >> tmp >> tab[i];
	}
	for (int i = 0; i < size1; i += 50) {
		if (i < 50) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = 0;
				plik << f << " " << wynik[z] << endl;
				f += Tb;
			}

		}
		else if (i < 100) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = -1;
				plik << f << " " << wynik[z] << endl;
				f += Tb;
			}
		}
		}
	for (int i = 100; i < size1; i += 100) {
		if (i >= 100) {
			if (tab[i + 1] == 0) {
				for (int z = 0; z < 100; z++) {
					plik << f << " " << wynik[z] << endl;
					f += Tb;
				}
			}
			else if (tab[i + 1] == 1) {
				if (wynik[20] == 1) {
					for (int z = 0; z < 100; z++) {
						wynik[z] = -1;
						plik << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
			else if (wynik[20] == -1) {
				for (int z = 0; z < 100; z++) {
					wynik[z] = 1;
					plik << f << " " << wynik[z] << endl;
					f += Tb;
				}
			}
			}
		}
	}
	f = 0.0;

	for (int i = 0; i < size1; i += 50) {
		if (i < 50) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = 0;
				plik2 << f << " " << wynik[z] << endl;
				f += Tb;
			}

		}
		else if (i < 100) {
			for (int z = 0; z < 50; z++) {
				wynik[z] = 1;
				plik2 << f << " " << wynik[z] << endl;
				f += Tb;
			}
		}
	}
	for (int i = 100; i < size1; i += 100) {
		if (i >= 100) {
			if (tab[i + 1] == 0) {
				for (int z = 0; z < 100; z++) {
					plik2 << f << " " << wynik[z] << endl;
					f += Tb;
				}
			}
			else if (tab[i + 1] == 1) {
				if (wynik[20] == 1) {
					for (int z = 0; z < 100; z++) {
						wynik[z] = -1;
						plik2 << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
				else if (wynik[20] == -1) {
					for (int z = 0; z < 100; z++) {
						wynik[z] = 1;
						plik2 << f << " " << wynik[z] << endl;
						f += Tb;
					}
				}
			}
		}
	}
	plik.close();
	plik1.close();
	plik2.close();
}
void bami(int size) {
	fstream plik;
	plik.open("bami.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("bamiinv.txt", ios::out | ios::trunc);
	fstream plik1;
	plik1.open("S2BS.txt", ios::in);
	double tab[3200];
	double tmp;
	int size1 = size * 100;
	int size2 = size * 8;
	double wynik[3200];
	double f = 0.0;
	int j = 1;
	int c = 1;
	bool check = false;
	for (int i = 0; i < size1; i++) {
		plik1 >> tmp >> tab[i];
	}
	for (int i = 0; i < size1; i += 100) {
		if (i < 100) {
			for (int z = 0; z < 100; z++) {
				wynik[z] = 0;
				plik << f << " " << wynik[z] << endl;
				f += Tb;
			}
			//warunek jezeli zaczynamy od 1
			if (tab[i+1]==1) {
				j = 0;
			}
		}
	}
	for (int i = 100; i < size1;i+= 100) {
		c = tab[i + 1];
		if (c == 1) {
			if (j == 1) {
				for (int z = 0; z < 100; z++) {
					wynik[z] = 1;
					plik << f << " " << wynik[z] << endl;
					f += Tb;
				}
				j = 0;
			}
			else {
				for (int z = 0; z < 100; z++) {
					wynik[z] = -1;
					plik << f << " " << wynik[z] << endl;
					f += Tb;
				}
				j = 1;
			}
		}
		else if (c == 0) {
			for (int z = 0; z < 100; z++) {
				wynik[z] = 0;
				plik << f << " " << wynik[z] << endl;
				f += Tb;
			}
		}
	}



	plik.close();
	plik1.close();
	plik2.close();
}
void ttl_d(int size) {
	fstream plik1;
	plik1.open("S2BS.txt", ios::in);
	double tab[3200];
	double tmp;
	int size1 = size * 100;
	int size2 = size * 8;
	double wynik[3200];
	double f = 0.0;
	int j = 1;
	int c = 1;
	bool check = false;
	for (int i = 0; i < size1; i++) {
		plik1 >> tmp >> tab[i];
	}
	cout << endl;
	cout << endl << "ZDEKODOWANY TTL:" << endl;
	for (int i = 0; i < size1; i += 100) {
		cout << tab[i];
	}
}
void man_d(int size) {
	fstream plik1;
	plik1.open("manchester.txt", ios::in);
	int tab[3200];
	double tmp;
	int size1 = size * 100;
	int size2 = size * 8;
	double wynik[3200];
	double f = 0.0;
	int j = 1;
	int c = 1;
	bool check = false;
	for (int i = 0; i < size1; i++) {
		plik1 >> tmp >> tab[i];
	}
	cout << endl;
	cout << endl << "ZDEKODOWANY MANCHESTER('X' - bit utracony):" << endl;
	cout << "X";
	for (int i = 100; i < size1; i += 100) {
		if (tab[i + 60] == -1) {
			c = 0;
		}
		else {
			c = 1;
		}
		if (tab[i] == -1) {
			j = 0;
		}
		else {
			j = 1;
		}
		if (j==c) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
}

void nrzi_d(int size) {
	fstream plik1;
	plik1.open("nrzi.txt", ios::in);
	int tab[3200];
	double tmp;
	int size1 = size * 100;
	int size2 = size * 8;
	double wynik[3200];
	double f = 0.0;
	int j = 1;
	int c = 1;
	bool check = false;
	for (int i = 0; i < size1; i++) {
		plik1 >> tmp >> tab[i];
	}
	cout << endl;
	cout << endl << "ZDEKODOWANY NRZI('X' - bit utracony):" << endl;
	cout << "X";
	for (int i = 100; i < size1; i += 100) {
		if (tab[i - 20] == -1) {
			c = 0;
		}
		else {
			c = 1;
		}
		if (tab[i]==-1) {
			j = 0;
		}
		else {
			j = 1;
		}
		if ((j^c)==1) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	plik1.close();
}
void bami_d(int size) {
	fstream plik1;
	plik1.open("bami.txt", ios::in);
	int tab[3200];
	double tmp;
	int size1 = size * 100;
	int size2 = size * 8;
	double wynik[3200];
	double f = 0.0;
	int j = 1;
	int c = 1;
	bool check = false;
	for (int i = 0; i < size1; i++) {
		plik1 >> tmp >> tab[i];
	}
	cout << endl;
	cout << endl << "ZDEKODOWANY BAMI('X' - bit utracony):" << endl;
	cout << "X";
	for (int i = 100; i < size1; i += 100) {
		if (tab[i]==1 || tab[i]==-1) {
			cout << "1";
		}
		else {
			cout << "0";
		}
	}

	plik1.close();
}
int main()
{
	int i[] = { 'X','Y' };
	int size = my_sizeof(i) / my_sizeof(i[0]);
	int size1 = size * 8;
	int tmp[100];
	int z;
	int j = 1;
	int o;
	string slowo1 = S2BS(i, size);
	fstream plik;
	cout << "Dane wejsciowe: XY" << endl;

	plik.open("S2BS.txt", ios::in);
	for (int i = 0; i < size1; i++) {
		plik >> tmp[i];
	}
	plik.close();
	cout << "Strumien binarny:" << endl;
	for (int i = 0; i < size1; i++) {
		cout << tmp[i];
		if (j % 4 == 0) {
			cout << " ";
		}
		j++;
	}
	double f = 0.0;
	fstream plik1;
	plik1.open("S2BS.txt", ios::out | ios::trunc);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {
			plik1 << f << " " << tmp[i] << endl;
			f += Tb;
		}
	}
	plik1.close();
	clk(size1);
	mancherster(size1);
	nrzi(size1);
	bami(size1);
	ttl_d(size1);
	man_d(size1);
	nrzi_d(size1);
	bami_d(size1);
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
