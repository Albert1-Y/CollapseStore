#include "tarjeta_visa.h"


tarjeta_visa::tarjeta_visa(){
		saldo = 0;
		numeroTarjeta  = "";
		fechaVencimiento  = "";
		CVV = "";
}

void tarjeta_visa::set_tarjeta_visa(string _numeroTarjeta, string _fechaVencimiento, string _CVV, double _saldo){
		saldo = _saldo;
		numeroTarjeta = _numeroTarjeta;
		fechaVencimiento = _fechaVencimiento;
		CVV = _CVV;
}


/*void tarjeta_visa::descontar(double _totalCompra) {

*/
