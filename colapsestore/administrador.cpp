#include "administrador.h"
#include  "productos.h"
#include "librerias.h"
using namespace std;


administrador::administrador()
{
    sueldo_administrador = 0;
}


administrador::administrador(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _tipo_usuario, double _sueldo_administrador) : usuario(_nombre, _documentoIdentidad, _correo, _contrasena, _ID, _direccion, _telefono, _tipo_usuario)
{
    sueldo_administrador = _sueldo_administrador;
}


void administrador::setadmin(double _sueldo_administrador)
{
    sueldo_administrador = _sueldo_administrador;
}


void administrador::agregar_producto(arrays_objetos& arrays_producto)
{   
    //creamos un array axiliar para no perder los datos de nuestra array original 
    productos* auxiarrays_productos;
    auxiarrays_productos = new productos[arrays_producto.tamano_producto];

    //pasamos los elemento a nuestro nuevo array
    for (int i = 0; i < arrays_producto.tamano_producto; i++) {
        auxiarrays_productos[i] = arrays_producto.arrays_productos[i];
    }
    //limpiamos nuestro array original creamos nuestro arrays mas 1 lemento 
    delete[] arrays_producto.arrays_productos;
    arrays_producto.arrays_productos = new productos[(arrays_producto.tamano_producto)+1];

    //colocamos los productos dea nuestra array auxiliar a nuestro nuevo array de productos
    for (int i = 0; i < arrays_producto.tamano_producto; i++) {
        arrays_producto.arrays_productos[i] = auxiarrays_productos[i];
    }

    string _nombre, _marca, _tipo, _precios, _numeroserie, _categoria, _cantidad;
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
    cout << "Ingrese la cantidad del producto: ";
    getline(cin, _cantidad);

    while (true)
    {
        bool verifica;
        cout << "Ingrese el precio del producto: ";
        getline(cin, _precios);
        verifica = verifica_numero(_precios);
        if (verifica)
            break;
    }
    arrays_producto.arrays_productos[arrays_producto.tamano_producto].crear_objetos(_nombre, _marca, _categoria, _tipo, _precios, _numeroserie,_cantidad);
    delete[] auxiarrays_productos;
    arrays_producto.tamano_producto= arrays_producto.tamano_producto+1;

}

void administrador::ver_productos(arrays_objetos& arrays_producto)
{
    for (int i = 0; i < arrays_producto.tamano_producto; i++) {

        cout << "------------------------------------------" << endl;
        cout << "Numero de Serie-------------: " << arrays_producto.arrays_productos[i].numeroSerie << endl;
        cout << "Nombre del producto---------: " << arrays_producto.arrays_productos[i].nombre << endl;
        cout << "Marca del producto----------: " << arrays_producto.arrays_productos[i].marca << endl;
        cout << "Categoria del producto------: " << arrays_producto.arrays_productos[i].categoria << endl;
        cout << "Tipo del producto-----------: " << arrays_producto.arrays_productos[i].tipo << endl;
        cout << "Precio del producto---------: " << arrays_producto.arrays_productos[i].precio << endl;
        cout << "cantidad del producto---------: " << arrays_producto.arrays_productos[i].cantidad << endl;
        cout << "------------------------------------------" << endl;

    }
    system("pause");
}

//----------------------Adminstrador--------------------------------------

void administrador::ingresando_elementos_repetidos(arrays_objetos& arrays_producto)
{
    string busca_n_serie;
    cout << "Ingrese el numero de Serie: ";
    cin.ignore();
    getline(cin, busca_n_serie);
    for (int i = 0; i < arrays_producto.tamano_producto; i++) {
        if (busca_n_serie == arrays_producto.arrays_productos[i].numeroSerie) {
            int n_producto = 0;
            cout << "Cuantas productos mas agregara: ";
            cin>>n_producto;
            arrays_producto.arrays_productos[i].cantidad = to_string(stoi((arrays_producto.arrays_productos[i].cantidad)) + n_producto);
            
            return;
        }
        else if (i == (arrays_producto.tamano_producto)-1) {
            cout << "\n?El producto no fue encontrado!\n";            
        }
    }
    return;
}

void administrador::eliminar_inventario(arrays_objetos& arrays_producto){
    cout << "TEN EN CUENTA QUE ELIMINARAS EL PRODUCTO POR COMPPLETO\n";
    string n_serie;
    cout << "Ingrese en numero de serie del producto: ";
    cin.ignore();
    getline(cin, n_serie);
    for (int i = 0; i < arrays_producto.tamano_producto; i++) {
        if (n_serie == arrays_producto.arrays_productos[i].numeroSerie) {
            
            cout << "Si se encontro el producto se procedera a elminar de la base de datos\n";
            
            productos* auxiarrays_productos;
            auxiarrays_productos = new productos[(arrays_producto.tamano_producto)-1];
            int j = 0;
            for (int h = 0; h < (arrays_producto.tamano_producto); h++) {
                if (n_serie == arrays_producto.arrays_productos[h].numeroSerie) {
                    continue;
                }
                   
                else {
                    auxiarrays_productos[j] = arrays_producto.arrays_productos[h];
                    j++;
                }

            }
            delete[] arrays_producto.arrays_productos;
            arrays_producto.arrays_productos = new productos[(arrays_producto.tamano_producto)-1];
            
            for (int m = 0; m< (arrays_producto.tamano_producto)-1; m++) {
                arrays_producto.arrays_productos[m] = auxiarrays_productos[m];

            }
            delete[] auxiarrays_productos;
            arrays_producto.tamano_producto= arrays_producto.tamano_producto -1;
            return;
        }
        else if (i == arrays_producto.tamano_producto-1)
        {
            cout << "\n?El producto no fue encontrado!\n";
        }

    }
    return;
    
}
void administrador::elimina_unidadees_producto(arrays_objetos& arrays_producto) {
    string n_serie;
    int pregunta;
    cout << "Ingrese el numero de serie del producto: ";
    cin.ignore();
    getline(cin, n_serie);
    for (int i = 0; i < arrays_producto.tamano_producto; i++) {
        if (n_serie==arrays_producto.arrays_productos[i].numeroSerie) {
            int n_elementos = stoi(arrays_producto.arrays_productos[i].cantidad);
            
            cout << "Cuantos elementos deseas quitar:";
            cin >> pregunta;
            if ((stoi((arrays_producto.arrays_productos[i].cantidad)) - pregunta) <= 0) {
                arrays_producto.arrays_productos[i].cantidad = to_string(stoi((arrays_producto.arrays_productos[i].cantidad)) + pregunta);

            }
            else
                cout << "\nCANTIDAD NO PERMITIDA\n";
                system("pause");

        }
    }
}
void administrador::imprime() {
    usuario::imprime();
    cout << "Sueldo: " << sueldo_administrador << "\n";
}