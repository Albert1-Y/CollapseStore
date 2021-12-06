#include "arrays_objetos.h"
#include "librerias.h"
#include <fstream>
#include <iostream>
using namespace std;
arrays_objetos::arrays_objetos()
{
    tamano_producto = 0;
    
    arrays_productos=nullptr;
    
}
arrays_objetos::~arrays_objetos()
{
    //delete[] arrays_cliente;
    if (arrays_productos!=nullptr) 
        delete[] arrays_productos;
}

void arrays_objetos::set_crea_arrays_productos(ifstream & inventario)
{
    tamano_producto = contdor_productos(inventario);
    arrays_productos = new productos[tamano_producto];
}



void arrays_objetos::setarrays_objetos(ifstream & inventario ){

    int m = 0;
    int cantidad_total;
    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;
    string categoria, cantidad; 

    inventario.open("inventario.txt", ios::in);

    
        inventario >> cantidad_total;
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            nombre = separa(nombre);
            inventario >> marca;
            marca = separa(marca);
            inventario >> categoria;
            categoria = separa(categoria);
            inventario >> tipo;
            tipo = separa(tipo);
            inventario >> precio;
            precio = separa(precio);
            inventario >> cantidad;
            cantidad = separa(cantidad);
            arrays_productos[m].crear_objetos(nombre, marca, categoria,tipo,precio, numeroSerie,cantidad);
            m = m + 1;
            inventario >> numeroSerie;

        }
        inventario.close();
    }







