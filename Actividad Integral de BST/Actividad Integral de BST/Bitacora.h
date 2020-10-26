#ifndef Bitacora_h
#define Bitacora_h
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

struct Bitacora {
	string mes;
	int dia;
	int mesInt;
	int hr;
	int min;
	int sec;
	int hora;
	int fechaNum;
	string ip;
	string message;
	Bitacora();
	Bitacora(string mes, int dia, int hr, int min, int sec, string ip, string message);
	int mesToInt(string mm);
	int intFecha(int mes, int dia, int hr, int min, int sec);
	bool operator<(Bitacora bitacora);
	bool operator>(Bitacora bitacora);
	bool operator<=(Bitacora bitacora);
	bool operator>=(Bitacora bitacora);
	bool operator==(Bitacora bitacora);
};
Bitacora::Bitacora() {
	time_t fecha;
	struct tm infoFecha;
	string mes;
	int dia;
	int mesInt;
	int hr;
	int min;
	int sec;
	string ip;
	string message;
	int fechaNum;
}

Bitacora::Bitacora(string mes, int dia, int hr, int min, int sec, string ip, string message) {
	this->mes = mes;
	this->mesInt = mesToInt(mes);
	this->dia = dia;
	this->hr = hr;
	this->min = min;
	this->sec = sec;
	this->ip = ip;
	this->message = message;
	fechaNum = intFecha(mesInt, dia, hr, min, sec);
}
int Bitacora::mesToInt(string mes) {
	if (mes == "Jan") {
		return 1;
	}
	if (mes == "Feb") {
		return 2;
	}
	if (mes == "Mar") {
		return 3;
	}
	if (mes == "Apr") {
		return 4;
	}
	if (mes == "May") {
		return 5;
	}
	if (mes == "Jun") {
		return 6;
	}
	if (mes == "Jul") {
		return 7;
	}
	if (mes == "Aug") {
		return 8;
	}
	if (mes == "Sep") {
		return 9;
	}
	if (mes == "Oct") {
		return 10;
	}
	if (mes == "Nov") {
		return 11;
	}
	if (mes == "Dic") {
		return 12;
	}
	else {
		cout << "error" << endl;
		return -1;
	}
}
int Bitacora::intFecha(int mes, int dia, int hr, int min, int sec) {
	return mes * 100000000 + dia * 1000000 + hr * 10000 + min * 100 + sec;
}
int particion(vector<Bitacora>& lista, int& comp, int inicio, int fin) {
	Bitacora pivot = lista[fin];
	int j = inicio;
	for (int i = inicio; i <= fin; i++) {
		comp++;
		if (lista[i] <= pivot) {
			swap(lista[j++], lista[i]);
		}
	}
	return j - 1;
}
vector<Bitacora> ordenaQuick(vector<Bitacora>& lista, int& comp, int inicio, int fin) {
	if (inicio >= fin) {
		return lista;
	}
	int pivot_posicion = particion(lista, comp, inicio, fin);
	ordenaQuick(lista, comp, inicio, pivot_posicion - 1);
	ordenaQuick(lista, comp, pivot_posicion + 1, fin);
	return lista;
}



bool Bitacora::operator<(Bitacora bitacora) {
	return (fechaNum - bitacora.fechaNum) < 0;
}
bool Bitacora::operator>(Bitacora bitacora) {
	return (fechaNum - bitacora.fechaNum) > 0;
}
bool Bitacora::operator<=(Bitacora bitacora) {
	return (fechaNum - bitacora.fechaNum) <= 0;
}
bool Bitacora::operator>=(Bitacora bitacora) {
	return (fechaNum - bitacora.fechaNum) >= 0;
}
bool Bitacora::operator==(Bitacora bitacora) {
	return (fechaNum - bitacora.fechaNum) == 0;
}
int binaria(vector<Bitacora> lista, Bitacora dato) {
	int central = 0, bajo = 0, alto = lista.size() - 1, medio= (bajo + alto) / 2, counter = 0;
	while (bajo <= alto) {
		medio = (bajo + alto) / 2;
		if (lista[medio] > dato) {
			alto = medio - 1;
		}
		else if (lista[medio] < dato) {
			bajo = medio + 1;
		}
		else {
			return medio; // found
		}
	}
	return medio;
}

#endif // Bitacora_h
