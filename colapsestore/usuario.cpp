#include "usuario.h"
#include "librerias.h"
#include "productos.h"
#include "arrays_objetos.h"

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

usuario::usuario()
{
	nombre = "";
	documentoIdentidad = "";
	correo = "";
	contrasena = "";
    ID = "";
	direccion = "";
    telefono = "";
}

void usuario::setUsuario(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono)
{
    nombre = _nombre;
    documentoIdentidad = _documentoIdentidad;
    correo = _correo;
    contrasena = _contrasena;
    ID = _ID;
    direccion = _direccion;
    telefono = _telefono;
}


//----------------------Adminstrador--------------------------------------

administrador::administrador()
{
    codigoAministrador = "";
}


void administrador::setadmin(string _codigoAministrador)
{
    codigoAministrador = _codigoAministrador;
}

void administrador::agregar_producto(arrays_objetos & arrays_producto)

{   //creamos un array axiliar para no perder los datos de nuestra array original 
    productos* auxiarrays_productos;
    auxiarrays_productos = new productos[arrays_producto.tamano_producto];
    
    //pasamos los elemento a nuestro nuevo array
    for (int i = 0; i < arrays_producto.tamano_producto; i++)
    {
        auxiarrays_productos[i] = arrays_producto.arrays_productos[i];
    }

    //limpiamos nuestro array original creamos nuestro arrays mas 1 lemento 
    delete[] arrays_producto.arrays_productos;
    arrays_producto.arrays_productos = new productos[arrays_producto.tamano_producto + 1];

    for (int i = 0; i < arrays_producto.tamano_producto; i++)
    {
        arrays_producto.arrays_productos[i] = auxiarrays_productos[i];
    }
    
    string _nombre, _marca, _tipo, _precios, _numeroserie, _categoria;
    system("cls");

    cout << "Ingrese el numero de serie del producto: ";
    cin.ignore();
    getline(cin, _numeroserie);
    
    cout << "Ingrese el nombre del producto: ";
    getline(cin, _nombre);
    
    cout << "Ingrese la marca del producto: ";
    getline(cin, _marca);
    
    cout << "Ingrese la categoria del producto: ";
    getline(cin, _categoria);

    cout << "Ingrese el tipo del producto: ";
    getline(cin, _tipo);
    
    while (true)
    {
        bool verifica;
        cout << "Ingrese el precio del producto: ";
        getline(cin, _precios);
        verifica = verifica_numero(_precios);
        if (verifica)
            break;
    }

    arrays_producto.arrays_productos[arrays_producto.tamano_producto].crear_objetos(_nombre, _marca,/* _categoria, _tipo,*/ _precios, _numeroserie);
    delete[] auxiarrays_productos;
    arrays_producto.tamano_producto++;
}
	
void administrador::ver_productos(arrays_objetos& arrays_producto)
{
    for (int i = 0; i < arrays_producto.tamano_producto; i++) {

        cout << "------------------------------------------" << endl;
        cout << "Numero de Serie-------------: " << arrays_producto.arrays_productos[i].numeroSerie << endl;
        cout << "Nombre del producto---------: " << arrays_producto.arrays_productos[i].nombre<< endl;
        cout << "Marca del producto----------: " << arrays_producto.arrays_productos[i].marca << endl;
        //cout << "Categoria del producto------: " << arrays_producto.arrays_productos[i].categoria << endl;
        //cout << "Tipo del producto-----------: " << arrays_producto.arrays_productos[i].tipo << endl;
        cout << "Precio del producto---------: " << arrays_producto.arrays_productos[i].precio << endl;
        cout << "------------------------------------------" << endl;

    }
    system("pause");
}


/*void administrador::modificar_inventario(arrays_objetos& arrays_producto)
{
    system("cls");

    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;
    
    string aux_nombre;
    string aux_marca;
    string aux_tipo;
    string aux_precio;
   
    string auxNumeroSerie;

    inventario.open("inventario.txt", ios::in);

    ofstream aux("auxiliar_inventario.txt", ios::out | ios::app);

    if (inventario.is_open())
    {
        bool omg = false;
        cout << "Numero de serie:  ";
        cin >> auxNumeroSerie;
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;

            if (numeroSerie == auxNumeroSerie)
            {
                cout << "Digite el nuevo nombre del producto: ";
                cin >> aux_nombre;
                cout << "Digite la marca del proucto: ";
                cin >> aux_marca;
                cout << "Digite el tipo del proucto: ";
                cin >> aux_tipo;
                cout << "Digite el precio del proucto: ";
                cin >> aux_precio;

                aux << numeroSerie << " " << aux_nombre << " " << aux_marca << " " << aux_tipo << " " << aux_precio << "\n";
                omg = true;
            }
            else
            {
                aux << numeroSerie << " " << nombre << " " << marca << " " << tipo << " " << precio << "\n";
            }
            
            inventario >> numeroSerie;
        }
        inventario.close();
        aux.close();
        if (omg == false)
        {
            cout << "Dato no encontrado\n";
            Sleep(1500);
        }
    }
    else
    {
        cout << "ERROR\n";
        Sleep(1500);
    }
    remove("inventario.txt");
    rename("auxiliar_inventario.txt", "inventario.txt");
}

void administrador::eliminar_inventario(ifstream& inventario)
{
    system("cls");

    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;

    string aux_nombre;
    string aux_marca;
    string aux_tipo;
    string aux_precio;

    string auxNumeroSerie;

    inventario.open("inventario.txt", ios::in);

    ofstream aux("auxiliar_inventario.txt", ios::out | ios::app);

    if (inventario.is_open())
    {
        bool omg = false;
        cout << "Numero de serie: ";
        cin >> auxNumeroSerie;
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;
            if (numeroSerie == auxNumeroSerie)
            {
                cout << "Eliminado ok ";
                Sleep(1500);
                omg = true;
            }
            else
            {
                aux << numeroSerie << " " << nombre << " " << marca << " " << tipo << " " << precio << "\n";
            }
            inventario >> numeroSerie;
        }
        inventario.close();
        aux.close();
        if (omg == false)
        {
            cout << "Dato no encontrado\n";
            Sleep(1500);
        }
    }
    else
    {
        cout << "ERROR\n";
        Sleep(1500);
    }
    remove("inventario.txt");
    rename("auxiliar_inventario.txt", "inventario.txt");
}
*/