#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class productos
{
	public:

		string nombre; // numeder serie
		string numeroSerie;
		string marca;		
		string categoria; // periferico o componente
		string tipo; // mause, teclado, procesador		
		string precio;
		string cantidad;

		productos();

		void crear_objetos(string _nombre, string _marca,string categoria , string _tipo, string _precios, string _numeroserie, string _cantidad);
};



