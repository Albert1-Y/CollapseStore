#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class productos
{
	public:

		string nombre;
		string marca;
		string precio;
		string tipo;
		string numeroSerie;

		productos();

		void crear_objetos(string _nombre, string _marca, string _tipo, string _precios, string _numeroserie);
};



