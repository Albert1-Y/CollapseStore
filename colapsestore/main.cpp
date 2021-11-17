#include "productos.h"
#include "usuario.h"
#include "librerias.h"
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

    administrador admin("Pepito", "7030", "pepito@gmail.com", "123456781", "Arequipa", "ppt7030");

    arreaglo_de_objetos(registro_productos,Lec);
    cout <<"\n"<< n;
    int m = 0;

	int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1: //Registrar producto
            
            admin.agregar_producto(EXP);
            n = contdor_productos(Lec);
            modificar_arrays(registro_productos,n,Lec);
            break;
        case 2: //
            admin.ver_productos(Lec);
            break;
        case 3: //Buscar producto
            imprime_objeto(registro_productos, n);
            break;
        case 4: //Modificar producto
            admin.modificar_inventario(Lec);
            n = contdor_productos(Lec);
            modificar_arrays(registro_productos, n, Lec);
            break;
        case 5: //Eliminar producto
            admin.eliminar_inventario(Lec);
            n = contdor_productos(Lec);
            modificar_arrays(registro_productos, n, Lec);
            break;
        default:
            break;
        }
    }
    while (opcion != 6);

	return 0;
}