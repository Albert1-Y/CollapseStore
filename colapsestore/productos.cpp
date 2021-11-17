#include "productos.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

productos::productos()
{
    string numeroSerie = "";
    string nombre = "";
	string marca = "";
	string tipo = "";
    string precio = "";
}
void productos::crear_objetos(string _nombre, string _marca, string _tipo, string _precios, string _numeroserie)
{   
    nombre =_nombre;
    marca =_marca;
    tipo =_tipo;
    precio =_precios;
    numeroSerie = _numeroserie;
}





