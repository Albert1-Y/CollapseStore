#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

#include "cliente.h"
#include "librerias.h"

using namespace std;



cliente::cliente(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _tipo_usuario, int _cantidad_productos_comprados) : usuario(_nombre, _documentoIdentidad, _correo, _contrasena, _ID, _direccion, _telefono, _tipo_usuario)
{
    cantidad_productos_comprados = _cantidad_productos_comprados;
}
cliente::cliente()
{
    cantidad_productos_comprados = 0;
}

void cliente::imprime() {
    usuario::imprime();
    cout << "Cantidad productos comprados: " <<cantidad_productos_comprados<<"\n";
    
}
void cliente::setCliente(int _cantidad_productos_comprados)
{
    cantidad_productos_comprados = _cantidad_productos_comprados;
    
}

void cliente::ver_productos(arrays_objetos& producto)
{
    for (int i = 0; i < producto.tamano_producto; i++)
    {   
        cout << i + 1 << " ";
        cout << producto.arrays_productos[i].marca << " ";
        cout << producto.arrays_productos[i].nombre << " ";
        cout << "$. "<< producto.arrays_productos[i].precio << " \n";
    }

    int opcion = 0;
    cout << "Que producto quieres agregar a tu carroto de compras (si deseas salir ingrase 0): ";
    cin >> opcion;
    bool comp=false;
    if (opcion != 0 && opcion <= producto.tamano_producto)
    {
        comp=carrito.verificar_carrito(producto, producto.arrays_productos[opcion - 1]);
        if (comp) {
            carrito.agregarProducto(producto.arrays_productos[opcion - 1]);
            cout << "se ha agragado con exito" << endl;
            system("pause");
        }
         
       
    }

}

void cliente::inicializarCarrito(arrays_objetos& producto)
{
    carrito.setcarritoCompra(ID, direccion);
    carrito.productos_carritod(producto);
}




void cliente::agregar_producto_carrito(arrays_objetos& producto)
{
    string escoge_producto;
    cout << "\nDigite el numero del producto: ";
    cin >> escoge_producto;

    bool esNumero = verifica_numero(escoge_producto);

    if (esNumero == true)
    {
        int numero = stoi(escoge_producto);
        if (numero > 0 && numero <= producto.tamano_producto)
        {
            carrito.agregarProducto(producto.arrays_productos[numero - 1]);
        }
        else
        {
            cout << "No existe el producto";
        }
    }
}

void cliente::boleta()
{
    //time_t t = time(0);   // get time now
    //struct tm* now = localtime(&t);
    cout << "***************************************************\n****************COLLAPSE STORE****************\n**************FECHA*********HORA**************\n*************" /* << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << (now->tm_mday) << " ******" << (now->tm_hour + 7) << ':' << (now->tm_min) << ':' << (now->tm_sec) << "*************\n***************************************************\n\n " << endl*/;
    cout << "***************************************************\n";
    cout << "-----------------Boleta de Venta------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "---------------------------------RUC: N0000418----" << endl;
    cout << "-Señor: "<< nombre << endl;
    cout << "-DNI: "<< documentoIdentidad << endl;
    cout << "-Direccion: "<< direccion<< endl;
    cout << "-Cantidad-------------Nombre--------------Importe-" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < carrito.contador_productos; i++)
    {
        cout << " -" << "1. " << carrito.productos_carrito[i].nombre << "------\t\t-------" << carrito.productos_carrito[i].precio << "-\n";
    }

    cout << "--------------------------------------------------" << endl;
    cout << "------------------------------Total------"<< carrito.sumaTotal << "---" << endl;
    cout << "-------------------Cancelado----------------------" << endl;

}

