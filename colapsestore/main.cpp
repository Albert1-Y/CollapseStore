#include "productos.h"
#include "usuario.h"
#include "librerias.h"
#include "cliente.h"

#include <iostream>
#include <string>
#include <fstream>

int main()
{   
    ofstream EXP;
	ifstream Lec;
	int n= 0;
	n = contdor_productos(Lec);
	productos *registro_productos= new productos[n];
    cliente cliente_unico;
    administrador admin;
    /*admin.setUsuario("NombrePepito", "DNI7030", "pepito@gmail.com", "contra123456781", "ID1234", "Arequipa", "telefono123545");
    arreaglo_de_objetos(registro_productos,Lec);*/

    int m = 0;
	int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1: //Registrar producto
            inciar_sesion(Lec,cliente_unico,admin);
            cout << admin.codigoAministrador;
            system("pause");

            if (cliente_unico.codigocliente == "CLIENTE")
            {

            }
            else if (admin.codigoAministrador == "ADMINISTRADOR")
            {
                adminMetodos(admin,Lec,EXP);
            }
            //admin.agregar_producto(EXP);
            //n = contdor_productos(Lec);
            //modificar_arrays(registro_productos,n,Lec);

            
            break;
        case 2: //
            crea_cuenta_cliente(EXP);
            //crea_cuenta_cliente( EXP);
            break;
        case 3: //Buscar producto
            break;

        case 4: //Modificar producto
            /*admin.modificar_inventario(Lec);
            n = contdor_productos(Lec);
            modificar_arrays(registro_productos, n, Lec);*/
            break;
        /* case 5: //Eliminar producto
            admin.eliminar_inventario(Lec);
            n = contdor_productos(Lec);
            modificar_arrays(registro_productos, n, Lec);
            break;*/
        default:
            cout << "Por favor seleccione una opción valida";
            break;
        }
    }
    while (opcion != 4);


	return 0;
}