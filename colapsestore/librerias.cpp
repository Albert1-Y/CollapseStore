#include "librerias.h"
#include "productos.h"



void arreaglo_de_objetos(productos *&producto,ifstream &inventario)
{
    int m = 0;
    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;
    inventario.open("inventario.txt", ios::in);

    if (inventario.is_open())
    {
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;
            producto[m].crear_objetos(nombre, marca, tipo, precio, numeroSerie);
            
            cout << "\n" << producto[m].numeroSerie;

            m= m + 1;
            inventario >> numeroSerie;
        }
        inventario.close();
    }
}


int contdor_productos(ifstream &inventario)
{

    int n = 0;
    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;

    inventario.open("inventario.txt", ios::in);
    if (inventario.is_open())
    {
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;
            n = n + 1;
            inventario >> numeroSerie;
        }
        inventario.close();
    }
    return n;
}

  
int menu()
{
    system("cls");
    int x;
    cout << "----------bienvenido-------------" << endl;
    cout << "1. Registrar producto" << endl;
    cout << "2. Ver Productos" << endl;
    cout << "3. Ver Producto del Arrays" << endl;
    cout << "4. Modificar producto" << endl;
    cout << "5. Eliminar producto" << endl;
    cout << "6. Salir" << endl;
    cin >> x;
    return x;
}

void modificar_arrays(productos*& producto, int nuevo_tamaño, ifstream& inventario) {
    delete[] producto;
    producto = new productos[nuevo_tamaño];
    arreaglo_de_objetos(producto, inventario);
}
void imprime_objeto(productos*& producto, int nuevo_tamaño) {
    system("cls");
    for (int i = 0; i < nuevo_tamaño;i++) {
        cout<<"\n"<<producto[i].nombre;
    }
    cout << "\n";
    system("pause");
}