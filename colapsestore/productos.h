#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class productos
{
	public:

		string nombre; // numeder serie
		string numeroSerie;
		string marca;
		// string categoria; // periferico o componente
		// string tipo; // mause, teclado, procesador		
		string precio;

		productos();

		//void crear_objetos(string _nombre, string _marca,string categoria , string _tipo, string _precios, string _numeroserie);

		void crear_objetos(string _nombre, string _marca, string _precios, string _numeroserie);

};


class perifericos:public productos
{
	public:
		string categoria;
		string tipo;

		perifericos();
		void set_perifericos(string _tipo);

		//void crear_objetos(string _nombre, string _marca, string categoria, string _tipo, string _precios, string _numeroserie);
};


class componentes:public productos
{
	public:
		string categoria;
		string tipo;
		
		componentes();
		void set_componetes(string);
		// void crear_objetos(string _nombre, string _marca, string categoria, string _tipo, string _precios, string _numeroserie);
};
