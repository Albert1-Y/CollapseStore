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

	int tamano_producto = contdor_productos(Lec);
    int tamano_usuario = contador_usuario(Lec);
	productos *registro_productos= new productos[tamano_producto];
    cliente * registro_usuario = new cliente[tamano_usuario];
    cliente cliente_unico;
    administrador admin;
    //cout << tamano_usuario;

    
    /*admin.setUsuario("NombrePepito", "DNI7030", "pepito@gmail.com", "contra123456781", "ID1234", "Arequipa", "telefono123545");*/
    arreaglo_de_objetos(registro_productos,Lec);

    
    int m = 0;
	int opcion = 0;
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
                clienteMetodos(cliente_unico, registro_productos, Lec, EXP);
            }
            else if (admin.codigoAministrador == "ADMINISTRADOR")
            {
                adminMetodos(registro_productos,registro_usuario,admin,Lec,EXP,tamano_usuario);
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
            //admin.modificar_inventario(Lec);
            //n = contdor_productos(Lec);
            //modificar_arrays(registro_productos, n, Lec);
            break;
         case 5: //Eliminar producto
            //admin.eliminar_inventario(Lec);
            //n = contdor_productos(Lec);
            //modificar_arrays(registro_productos, n, Lec);
            break;
        default:
            cout << "Por favor seleccione una opción valida";
            break;
        }
    }
    while (opcion != 4);
    
	return 0;
}