#include "arrays_objetos.h"
#include "librerias.h"


arrays_objetos::arrays_objetos() {
    tamano_producto = 0;
    tamano_cliente = 0;
    arrays_productos=nullptr;
    arrays_cliente=nullptr;
}
arrays_objetos::~arrays_objetos()
{
    delete[] arrays_cliente;
    delete[] arrays_productos;
}

void arrays_objetos::set_crea_arrays_productos(ifstream & inventario)
{
    tamano_producto = contdor_productos(inventario);
    arrays_productos = new productos[tamano_producto];
}
void arrays_objetos::set_crea_arrays_clientes(ifstream & inventario) {
    tamano_cliente = contador_usuario(inventario);
    arrays_cliente = new cliente[tamano_cliente];
}



void arrays_objetos::setarrays_objetos(ifstream & inventario ){

    int m = 0;

    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;
    string categoria, cantidad; 

    inventario.open("inventario.txt", ios::in);

    
    
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            nombre = separa(nombre);
            inventario >> marca;
            marca = separa(marca);
            inventario >> categoria;
            categoria = separa(categoria);
            inventario >> tipo;
            tipo = separa(tipo);
            inventario >> tipo;
            tipo = separa(tipo);
            
            inventario >> precio;
            precio = separa(precio);
            inventario >> cantidad;
            cantidad = separa(cantidad);
            arrays_productos[m].crear_objetos(nombre, marca, categoria,tipo,precio, numeroSerie,cantidad);
            m = m + 1;
            inventario >> numeroSerie;
        }
        inventario.close();
    }



void arrays_objetos::setarrays_usuario(ifstream& inventario) {
    string nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario;
    int n = 0;
    inventario.open("usuario.txt", ios::in);

    if (inventario.is_open())
    {
        inventario >> nombre;

        while (!inventario.eof())
        {
            inventario >> documentoIdentidad;
            inventario >> correo,
            inventario >> contrasena;
            inventario >> id;
            inventario >> direccion;
            inventario >> telefono;
            inventario >> tipo_usuario;
            if (tipo_usuario == "CLIENTE") {
                arrays_cliente[n].setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono);
                arrays_cliente[n].setCliente(tipo_usuario);
                n = n + 1;
            }

            inventario >> nombre;
        }
        inventario.close();
    }
    else
    {
        cout << "ERROR" << endl;
        system("pause");
    }
}



