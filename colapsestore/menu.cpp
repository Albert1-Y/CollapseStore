#include "menu.h"
#include "productos.h"
#include "librerias.h"
#include "arrays_objetos.h"
#include "administrador.h"
#include"arrays_usuarios.h"
//#include <iostream>
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
    int tamano_producto = contdor_productos(Lec);
    int tamano_usuario = contador_usuario();
    tarjeta_visa tarjeta1;
    int m = 0;
    int opcion = 0;
    
    do
    {
        administrador admin;
        cliente cliente_unico;
        opcion = menu_inicial();
       
        switch (opcion)
        {
        case 1:
            
            inciar_sesion(Lec, cliente_unico, admin);


            if (cliente_unico.tipo_usuario == "CLIENTE")
            {
                cliente_unico.inicializarCarrito(productos1);
                
                clienteMetodos(cliente_unico, productos1, Lec, EXP, tarjeta1);
                
               
            
            }
            else if (admin.tipo_usuario == "ADMINISTRADOR")
            {   
                adminMetodos(productos1, admin, productos1,Lec);
                admin.~administrador();
            }
            break;
        case 2:
            crea_cuenta_cliente(cliente_unico);
            cliente_unico.inicializarCarrito(productos1);
            clienteMetodos(cliente_unico, productos1, Lec, EXP, tarjeta1);
            
      
            break;
        case 3:
            
            system("pause");
            break;
        default:
            if (opcion !=4) {
                cout << "\nPor favor seleccione una opción valida";
            }
            break;
        }

    } while (opcion != 4);
   ;
    actulizar_inventario(productos1);
    
    return;
}
