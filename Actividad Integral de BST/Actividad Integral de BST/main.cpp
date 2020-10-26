#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include <conio.h>
#include "Bitacora.h"

using namespace std;

void printLista(vector<Bitacora> lista, int a) {
	cout << lista[a].mes << " " << lista[a].dia << " " << lista[a].hr << ":" << lista[a].min << ":" << lista[a].sec << " " << lista[a].ip << lista[a].message << endl;
}
int main() {
	vector<Bitacora> lista;
	string dirIP, errorMessage, mes, dia, hh = "", mm, ss;
	ifstream bitacora;
	ofstream outBitacora;
	bitacora.open("bitacora.txt");
	while (!bitacora.eof()) {
		getline(bitacora, mes, ' ');
		getline(bitacora, dia, ' ');
		getline(bitacora, hh, ':');
		getline(bitacora, mm, ':');
		getline(bitacora, ss, ':');
		bitacora >> dirIP;
		getline(bitacora, errorMessage);
		int hr = stoi(hh);
		int min = stoi(mm);
		int sec = stoi(ss);
		int diaInt = stoi(dia);
		lista.push_back(Bitacora(mes, diaInt, hr, min, sec, dirIP, errorMessage));
	}
	int comp;
	clock_t start = clock();
	lista = ordenaQuick(lista, comp, 0, lista.size() - 1);
	cout << "Tiempo: " << (float)(clock() - start) << " ms" << endl;
	int z = 1, contador = 0;

	cout << "ingresar fecha y hora " << endl;
	string mesI, mesF;
	int diaI, hrI, minI, secI, diaF, hrF, minF, secF;
	cout << "Mes Inicio (Ex. Jun): ";
	cin >> mesI;
	cout << endl;
	cout << "Dia Inicio: ";
	cin >> diaI;
	cout << endl;
	cout << "Hora Inicio: ";
	cin >> hrI;
	cout << endl;
	cout << "Minuto Inicio: ";
	cin >> minI;
	cout << endl;
	cout << "Segundo Inicio: ";
	cin >> secI;
	cout << endl;
	Bitacora fechaInicio(mesI, diaI, hrI, minI, secI, "", "");
	cout << "ingresar fecha y hora de fin con el mismo formato << endl" << endl;
	cout << "Mes final(Ex. Jun): ";
	cin >> mesF;
	cout << endl;
	cout << "Dia final: ";
	cin >> diaF;
	cout << endl;
	cout << "Hora final: ";
	cin >> hrF;
	cout << endl;
	cout << "Minuto final: ";
	cin >> minF;
	cout << endl;
	cout << "Segundo final: ";
	cin >> secF;
	cout << endl;
	Bitacora fechaFinal(mesF, diaF, hrF, minF, secF, "", "");

	int inicio = binaria(lista, fechaInicio);
	int final = binaria(lista, fechaFinal);
	int cont = 0;
	int i = inicio;
	while (i <= final) {
		printLista(lista, i);
		if (cont % 20 == 0) {
			cout << "<-(flecha izquierda para volver a la pagina pasada) ->(flecha izquierda para seguir)" << endl;
			cout << "si preciona x termina" << endl;
			int arrow = _getch();
			arrow = _getch();
			cout << arrow << endl;
			if (arrow == 75 && cont > 20) {
				cont -= 20;
			}
			else if (arrow == 120) {
				i = final + 1;
			}
		}
		cont++;
		i++;

	}
	ofstream out("bitacoraOut.out");
	for (int l = 0; l < lista.size(); l++) {
		out << lista[l].mes << " " << lista[l].dia << " " << lista[l].hr << ":" << lista[l].min << ":" << lista[l].sec << " " << lista[l].ip << lista[l].message << endl;
	}
	out.close();
}
