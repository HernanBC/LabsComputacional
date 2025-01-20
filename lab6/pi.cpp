#include <iostream>

double integrando(double x){

return 1/(1+x*x);
}


double SumaRiemann(double(*integrando)(double),double x_inf, double x_sup, int NumeroCuadrados){
	double h = (x_sup - x_inf)/NumeroCuadrados;

	double I =0;
	for (int i = 0; i <= NumeroCuadrados; ++i){
		I += integrando(x_inf+(i+0.5)*h)*h ;
	}
} 


int main(){
	double I = SumaRiemann(integrando, 0,1,100);
	return 0;
}