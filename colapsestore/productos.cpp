#include "productos.h"
#include <fstream>
#include <Windows.h>


using namespace std;

productos::productos()
{
    nombre = "";
    numeroSerie = "";    
	marca = "";
    // categoria = "";
	// tipo = "";
    precio = "";
}

void productos::crear_objetos(string _nombre, string _marca, string _precio, string _numeroserie)
{   
    nombre = _nombre;
    numeroSerie = _numeroserie;
    marca = _marca;
    precio = _precio;        
}

perifericos::perifericos()
{
    categoria = "periferico";
    tipo = "";
}

void perifericos::set_perifericos(string _tipo)
{
    tipo = _tipo;
}

componentes::componentes(){

    categoria = "componente";
    tipo = "";
}

void componentes::set_componetes(string _tipo){
    tipo = _tipo;
}
