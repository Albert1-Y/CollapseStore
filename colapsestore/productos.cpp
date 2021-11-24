#include "productos.h"
#include <fstream>
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
}

void productos::crear_objetos(string _nombre, string _marca, string _tipo, string _precio, string _categoria, string _numeroserie)
{   
    nombre = _nombre;
    numeroSerie = _numeroserie;
    marca = _marca;
    categoria = _categoria;
    tipo = _tipo;
    precio = _precio;        
}

