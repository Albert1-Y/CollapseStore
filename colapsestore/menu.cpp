#include "menu.h"
#include "productos.h"
#include "usuario.h"
#include "librerias.h"
#include "arrays_objetos.h"
#include "administrador.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void menu()
{
    double inig;
    ofstream EXP;
    ifstream Lec;
    arrays_objetos productos1;
    productos1.set_crea_arrays_productos(Lec);
    productos1.setarrays_objetos(Lec);
    carrito_compras carrito1;
    int tamano_producto = contdor_productos(Lec);
    int tamano_usuario = contador_usuario(Lec);
    
    tarjeta_visa tarjeta1;
    int m = 0;
    int opcion = 0;

    do
    {
        opcion = menu_inicial();
        cliente cliente_unico;
        administrador admin;
        switch (opcion)
        {
        case 1:
            
            inciar_sesion(Lec, cliente_unico, admin);


            if (cliente_unico.codigocliente == "CLIENTE")
            {
                cliente_unico.inicializarCarrito(productos1);
                cout << cliente_unico.carrito.ID;
                system("pause");
                clienteMetodos(cliente_unico, productos1, Lec, EXP, tarjeta1);
               

            }
            else if (admin.codigoAministrador == "ADMINISTRADOR")
            {
                adminMetodos(productos1, admin, productos1, tamano_usuario);
                
            }

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            cout << contdor_productos(Lec);
            system("pause");
            /*for (int i = 0; i < productos1.tamano_producto; i++) {
                cout << "\n";
                cout << productos1.arrays_productos[i].precio;
            }*/
            break;
        case 5:

            break;
        default:
            cout << "Por favor seleccione una opción valida";
            break;
        }
    } while (opcion != 5);

}
