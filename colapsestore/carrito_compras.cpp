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

    if (productos_carrito != nullptr) {

        delete[] productos_carrito;
        
        contador_productos = 0;
    }
}

void carrito_compras::setcarritoCompra(string _ID, string _direccion)
{
    ID = _ID;
    direccion = _direccion;
}

void carrito_compras::productos_carritod(arrays_objetos& _arrays_productos)
{
    ifstream productos_carritoh;
    
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

                for (int i = 0; i < tamano; i++)
                {
                    if (AUX_productos_carrito[i] == '-')
                    {
                        string* auxi = nullptr;
                        f = "";
                        for (int j = inicio; j < i; j++)
                        {
                            f = f + AUX_productos_carrito[j];
                        }
                        inicio = i + 1;
                        contador_productos++;
                        //cout << f << "\n";
                        if (contador_productos == 1)
                        {
                            origi = new string[contador_productos];
                            origi[0] = f;
                        }
                        else
                        {
                            auxi = new string[contador_productos];
                            for (int g = 0; g < contador_productos - 1; g++)
                            {
                                auxi[g] = origi[g];
                            }
                            auxi[contador_productos - 1] = f;
                            delete[]origi;
                            origi = new string[contador_productos];
                            for (int g = 0; g < contador_productos; g++)
                            {
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
    if (contador_productos > 0) {
        productos_carrito = new productos[contador_productos];

        int contador_entradas = 0;

        for (int i = 0; i < contador_productos; i++)
        {
            for (int j = 0; j < _arrays_productos.tamano_producto; j++)
            {
                if (origi[i] == _arrays_productos.arrays_productos[j].numeroSerie)
                {
                    productos_carrito[i] = _arrays_productos.arrays_productos[j];

                }
            }
        }
    }

    delete[] origi;
}

bool carrito_compras::verificar_carrito(arrays_objetos& productos1,productos& propudcto_particular) {
    
    for (int j = 0; j < productos1.tamano_producto; j++) {
        if (propudcto_particular.numeroSerie == productos1.arrays_productos[j].numeroSerie) {
            if (stoi(productos1.arrays_productos[j].cantidad) <= 0) {
                cout << "\nEl prodcto se encuentra agotado\n";
                cout << "\nPodria elejir otro producto\n";
                return false;
            }
            else
                return true;

            }
        }
    


}
void carrito_compras::agregarProducto(productos &_producto1)
{
    productos* auxiproducto = new productos[ contador_productos + 1 ];
    for (int i = 0; i < contador_productos; i++)
    {
        auxiproducto[i] = productos_carrito[i];
    }

    auxiproducto[contador_productos] = _producto1;

    if (contador_productos != 0) {
        delete[] productos_carrito;
    }
    productos_carrito = new productos[(contador_productos )+ 1];

    for (int i = 0; i < contador_productos+1; i++)
    {
        productos_carrito[i] = auxiproducto[i];
    }
    contador_productos++;

    delete[] auxiproducto;
}


void carrito_compras::eliminarProducto(int _producto_eliminar)
{
    productos* auxiproducto = new productos[ contador_productos - 1 ];
    int m = 0;

    for (int i = 0; i < contador_productos; i++)
    {
        if (i != _producto_eliminar - 1)
        {
            auxiproducto[m] = productos_carrito[i];
            m++;
        }
    }
    
    delete[] productos_carrito;

    productos_carrito = new productos[contador_productos - 1];

    for(int j = 0; j < contador_productos - 1; j++)
    {
        productos_carrito[j] = auxiproducto[j];
    }

    contador_productos--;

    delete[] auxiproducto;
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

void carrito_compras::cancelarCompra(tarjeta_visa& tarjeta_1)
{
    if (contador_productos != 0)
    {

        cout << "Tu saldo antes de hacer la compra : " << tarjeta_1.saldo << "\n";

        tarjeta_1.saldo = tarjeta_1.saldo - sumaTotal;

        cout << "Tu saldo actual : " << tarjeta_1.saldo << "\n";


    }


    else {
        cout << "\nNo hya productos que comprar\n";
    }
}




