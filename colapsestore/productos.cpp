#include "productos.h"
#include <Windows.h>

using namespace std;

productos::productos()
{
    nombre = "";
    numeroSerie = "";    
	marca = "";
    categoria = "";
	tipo = "";
    precio = "";
    cantidad = 1;
}

void productos::crear_objetos(string _nombre, string _marca, string _categoria, string _tipo, string _precios, string _numeroserie, string _cantidad){   
    nombre = _nombre;
    numeroSerie = _numeroserie;
    marca = _marca;
    categoria = _categoria;
    tipo = _tipo;
    precio = _precios;   
    cantidad = _cantidad;
}

