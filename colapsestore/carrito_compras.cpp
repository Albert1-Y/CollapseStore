#include "carrito_compras.h"
#include "librerias.h"
#include <iostream>
#include <cstdlib>
using namespace std;

carrito_compras::carrito_compras()
{
    ID = "";
    sumaTotal = 0.0;
    direccion = "";
    contador_productos = 0;
    productos_carrito = nullptr;    
}

carrito_compras::~carrito_compras()
{
    delete[] productos_carrito;
}

void carrito_compras::setcarritoCompra(string _ID, string _direccion)
{
    ID = _ID;
    direccion = _direccion;
}

void carrito_compras::productos_carritod(ifstream& productos_carritoh, arrays_objetos& _arrays_productos)
{
    string ID_busqueda, AUX_productos_carrito;

    //string almacen = "";

    //string *A = new string[contador_productos];
    string* origi = nullptr;

    productos_carritoh.open("productos_carrito.txt", ios::in);

    if (productos_carritoh.is_open())
    {
        productos_carritoh >> ID_busqueda;

        while (!productos_carritoh.eof())
        {
            productos_carritoh >> AUX_productos_carrito;

            if (ID == ID_busqueda)

            {
                string f;
                int tamano = AUX_productos_carrito.length();
                int inicio = 0, fin = 0;

                for (int i = 0; i < tamano; i++) {
                    if (AUX_productos_carrito[i] == '-') {
                        string* auxi = nullptr;
                        f = "";
                        for (int j = inicio; j < i; j++) {
                            f = f + AUX_productos_carrito[j];
                        }
                        inicio = i + 1;
                        contador_productos++;
                        //cout << f << "\n";
                        if (contador_productos == 1) {
                            origi = new string[contador_productos];
                            origi[0] = f;
                        }
                        else {
                            auxi = new string[contador_productos];
                            for (int g = 0; g < contador_productos - 1; g++) {
                                auxi[g] = origi[g];
                            }
                            auxi[contador_productos - 1] = f;
                            delete[]origi;
                            origi = new string[contador_productos];
                            for (int g = 0; g < contador_productos; g++) {
                                origi[g] = auxi[g];
                            }
                            delete[]auxi;
                        }
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
        for (int j = 0;  j< _arrays_productos.tamano_producto; j++)
        {
            if (origi[i] == _arrays_productos.arrays_productos[j].numeroSerie)
            {
                productos_carrito[i] = _arrays_productos.arrays_productos[j];

            }
        }

    }
    
   
}

void carrito_compras::agregarProducto(productos &_producto1)
{
    productos* auxiproducto = new productos[(contador_productos)+1];
    for (int i = 0; i < contador_productos; i++) {
        auxiproducto[i] = productos_carrito[i];}
    auxiproducto[contador_productos] = _producto1;
    delete[] productos_carrito; 
    productos_carrito = new productos[(contador_productos )+ 1];
    for (int i = 0; i < contador_productos+1; i++) {
        productos_carrito[i] = auxiproducto[i];}
    contador_productos++;
    
}

void carrito_compras::verProductos()
{
    for (int i = 0; i <contador_productos; i++)
    {

        cout << productos_carrito[i].tipo <<" ";
        cout << productos_carrito[i].marca << " ";
        cout << productos_carrito[i].nombre << " ";
        cout << "s/" << productos_carrito[i].precio << "\n";
       
        sumaTotal = sumaTotal + stod(productos_carrito[i].precio);
    }
    if (contador_productos == 0)
    {
        cout << "Carrito de compras vacio" << endl;
    }
    system("pause");

}

void carrito_compras::cancelarCompra(tarjeta_visa &tarjeta_1)
{
    bool verifica = false;
    verifica=verifica_tarjeta(tarjeta_1);
    if (verifica) {
        cout << "Tu saldo actual: "<<tarjeta_1.saldo<<"\n";

        tarjeta_1.saldo = tarjeta_1.saldo - sumaTotal;

        cout << "Tu saldo actual: " << tarjeta_1.saldo << "\n";
        system("pause");
    }
    else
        cout << "Tarjeta no encontrada";
}

