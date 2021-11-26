#include "carrito_compras.h"
#include <iostream>
#include<cstdlib>
using namespace std;

carrito_compras::carrito_compras()
{
    ID = "";
    sumaTotal = 0.0;
    direccion = "";
    contador_productos = 0;
    
}

carrito_compras::~carrito_compras()
{
    delete[] productos_carrito;
}

void carrito_compras::setcarritoCompra(string _ID, string _direccion)
{
    ID = _ID;
    direccion = _direccion;
    productos_carrito = new productos[contador_productos];
}

void carrito_compras::productos_carritod(ifstream &productos_carritoh, arrays_objetos _arrays_productos)
{
    string ID_busqueda, AUX_productos_carrito;

    string almacen = "";

    string *A = new string[contador_productos];

    productos_carritoh.open("productos_carrito.txt", ios::in);

    if (productos_carritoh.is_open())
    {
        productos_carritoh >> ID_busqueda;

        while (!productos_carritoh.eof())
        {
            productos_carritoh >> AUX_productos_carrito;

            if (ID == ID_busqueda)
            {
                int longitud = AUX_productos_carrito.length();
                
                for (int i = 0; i <= longitud; i++)
                {
                    char prueva = AUX_productos_carrito[i];
                    if ( prueva == '-' )
                    {
                        string* Auxiliar_lista_productos = new string[contador_productos + 1];
                        for (int j = 0; j < contador_productos; j++)
                        {
                            Auxiliar_lista_productos[j] = A[j];
                        }
                        Auxiliar_lista_productos[contador_productos] = almacen;

                        contador_productos++;
                        almacen = "";

                        A = Auxiliar_lista_productos;
                    }
                    else
                    {
                        almacen = almacen + AUX_productos_carrito[i];
                    }
                }
            }
            productos_carritoh >> ID_busqueda;
        }
        productos_carritoh.close();
    }

    productos_carrito = new productos[contador_productos];

    int contador_entradas = 0;

    for (int i = 0; i < contador_productos; i++)
    {
        for (int j = 0; i < _arrays_productos.tamano_producto; i++)
        {
            if ( A[i] == _arrays_productos.arrays_productos[j].numeroSerie )
            {
                productos_carrito[contador_entradas] = _arrays_productos.arrays_productos[j];
                contador_entradas++;
            }
        }
    }

}

void carrito_compras::agregarProducto(productos _producto)
{
    productos* auxiproducto = new productos[contador_productos+1];
    for (int i = 0; i < contador_productos; i++) {
        auxiproducto[i] = productos_carrito[i];
    }
    auxiproducto[contador_productos] = _producto;
    delete[] productos_carrito;
    productos_carrito = new productos[contador_productos + 1];
    for (int i = 0; i < contador_productos + 1; i++) {
        productos_carrito[i] = auxiproducto[i];
    }
    contador_productos++;
    
}

void carrito_compras::verProductos(arrays_objetos _arrays_productos)
{
    for (int i = 0; i <contador_productos; i++)
    {

        cout << "------------------------------------------" << endl;
        cout << "Nombre del producto---------: " << productos_carrito[i].nombre << endl;
        cout << "Marca del producto----------: " << productos_carrito[i].marca << endl;
        cout << "Categoria del producto------: " << productos_carrito[i].categoria << endl;
        cout << "Tipo del producto-----------: " << productos_carrito[i].tipo << endl;
        cout << "Precio del producto---------: " << productos_carrito[i].precio << endl;
        cout << "------------------------------------------" << endl;

        sumaTotal = sumaTotal + stod(productos_carrito[i].precio);

    }

    if (contador_productos == 0)
    {
        cout << "Carrito de compras vacio" << endl;
    }
}

void carrito_compras::cancelarCompra(tarjeta_visa &tarjeta_1)
{
    bool verifica = false;
    verifica=verifica_tarjeta(tarjeta_1);
    if (verifica) {
        tarjeta_1.saldo = tarjeta_1.saldo - sumaTotal;
    }
}

