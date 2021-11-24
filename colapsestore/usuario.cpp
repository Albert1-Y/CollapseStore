#include "usuario.h"


using namespace std;

usuario::usuario(){
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