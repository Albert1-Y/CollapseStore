#include "productos.h"

void arreaglo_de_objetos(productos*& producto, ifstream& inventario);
int contdor_productos(ifstream& inventario);
int menu();
void modificar_arrays(productos*& producto, int nuevo_tama�o, ifstream& inventario);
void imprime_objeto(productos*& producto, int nuevo_tama�o);
