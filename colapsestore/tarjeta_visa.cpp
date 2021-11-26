#include "tarjeta_visa.h"


tarjeta_visa::tarjeta_visa(){
		saldo = 0;
		numeroTarjeta  = "";
		fechaVencimiento  = "";
		CVV = "";
}

void tarjeta_visa::set_tarjeta_visa(double _saldo, string _numeroTarjeta, string _fechaVencimiento, string _CVV){
		saldo = _saldo;
		numeroTarjeta = _numeroTarjeta;
		fechaVencimiento = _fechaVencimiento;
		CVV = _CVV;
}

/*
void descontar(){

}
*/