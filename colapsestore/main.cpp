#include "productos.h"
#include "usuario.h"
#include "librerias.h"
//#include "cliente.h"
#include "arrays_objetos.h"
#include "administrador.h"
//#include "carrito_compras.h"
//#include "tarjeta_visa.h"
#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>
using namespace std;
int main()
{   double inig;
    ofstream EXP;
	ifstream Lec;
    arrays_objetos productos1;

    productos1.set_crea_arrays_productos(Lec);
    productos1.setarrays_objetos(Lec);
    carrito_compras carrito1;
	int tamano_producto = contdor_productos(Lec);
    int tamano_usuario = contador_usuario(Lec);
    cliente cliente_unico;
    administrador admin;
    tarjeta_visa tarjeta1;
    int m = 0;
	int opcion = 0;
   
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1: 
            inciar_sesion(Lec,cliente_unico,admin);
           
            
            if (cliente_unico.codigocliente == "CLIENTE")  
            {
                carrito1.setcarritoCompra(cliente_unico.ID, cliente_unico.direccion);
                carrito1.productos_carritod(Lec, productos1);
                
                clienteMetodos(cliente_unico, productos1, Lec, EXP,carrito1,tarjeta1);
                cliente_unico.codigocliente = "";
                
            }
            else if (admin.codigoAministrador == "ADMINISTRADOR")
            {
                adminMetodos(productos1,admin,productos1,tamano_usuario);
                admin.codigoAministrador = "";
            }

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            system("pause");
            for (int i = 0; i<productos1.tamano_producto; i++) {
                cout << "\n";
                cout << productos1.arrays_productos[i].precio;}
            break;
         case 5: 
            
            break;
        default:
            cout << "Por favor seleccione una opci�n valida";
            break;
        }
    }
    while (opcion != 5);
    
	return 0;
}