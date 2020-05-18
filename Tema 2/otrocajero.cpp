#include <iostream>
#include <cstdlib>
/* .Realizar un programa que permita escoger entre las siguientes transacciones en un cajero
automático utilizando la estructura casos (Switch).
1-Consignar
2-Retiro
3-Pago de servicios
4-Cambio de clave*/
using namespace std;
int main(int argc, char** argv)
 {
 	system("color f0");
 	int opc,clave,clavecajero=123,ser,cuenta,contador=3;
 	float vr,saldo=500000;
 	do
 	{
	 
 	cout<<"\t BIENVENIDO AL BANCO ATH _ _ _  "<<endl;
 	cout<<"\t DIGITE SU CLAVE PERSONAL _ _ _ "<<endl;
 	cin>>clave;
 	if(clave==clavecajero)
 	{
 		do
 		{
     system("cls");
 	cout<<endl;
 	cout<<"\t"<<"                        (O  O)   "<<endl;
 	cout<<"\t"<<"              ---o00---  (__) ---"<<endl;
 	cout<<"\t"<<"              +-----------------+"<<endl;
 	cout<<"\t"<<"              | BANCO ATH  CRA 7|"<<endl;
 	cout<<"\t"<<"              +-----------------+"<<endl;
 	cout<<"\t"<<"              +--------------00o+"<<endl;
 	cout<<"\t"<<"                      |__|__|    "<<endl;
 	cout<<"\t"<<"                       || ||     "<<endl;
 	cout<<"\t"<<"                      oOO OOo    "<<endl;
 	cout<<"\t"<<"              MENU PRINCIPAL     "<<endl;
 	cout<<"\t"<<"  SENIOR USUARIO GRACIAS POR  UTILIZAR NUESTROS SERVICIOS "<<endl;
	cout<<"\t"<<" *************** ELIJA SU OPCION ASI :********************"<<endl;
	cout<<"\t"<<"**********************************************************"<<endl;
	cout<<"\t"<<"**********CAJERO AUTOMATICO SU RED AMIGA******************"<<endl;
	cout<<"\t"<<" ******************1-CONSIGNAR******************"<<endl;
	cout<<"\t"<<"*******************2-RETIRAR********************"<<endl;
	cout<<"\t"<<"*******************3-PAGO SERVICIOS PUBLICOS****"<<endl;
	cout<<"\t"<<"*******************4-CAMBIO CLAVE***************"<<endl;
	cout<<"\t"<<"*******************5-SALIR**********************"<<endl;
	cout<<"ELIJA SU OPCION "<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1:	cout<<"\t"<<" ***********1-CONSIGNAR****************"<<endl;
				cout<<" Ingrese el vr a consignar "<<endl;
				cin>>vr;
				saldo=saldo+vr;
				cout<<" Su transaccion se realizo con exito su nuevo saldo es "<<saldo<<endl;
		         system("pause");
				break;
		case 2:	cout<<"\t"<<" ***********2-RETIRAR****************"<<endl;
					cout<<"\t DIGITE SU CLAVE PERSONAL _ _ _ "<<endl;
 					cin>>clave;
 					if(clave==clavecajero)
 					{
 					 cout<<" Ingrese el vr a retirar "<<endl;
				     cin>>vr;	
				     if(saldo-vr<0)
				     {
				      cout<<" Fondos insuficientes "<<endl;	
					 }
					 else
					 {
					saldo=saldo-vr;
					cout<<" Su transaccion se realizo con exito su nuevo saldo es "<<saldo<<endl;
					 }
 						
 					}
 					else
                     {
                    	cout<<" CLAVE ERRADA *** INTENTE DE NUEVO"<<endl;
                    	 system("pause");
	                     system("cls");
 				     }
 				      system("pause");
		        break;
		        
		case 3: do
		        {
				system("cls");
				cout<<"**********PAGO SERVICIOS PUBLIVOS****************"<<endl;
				cout<<"\t"<<" ******************1-AGUA******************"<<endl;
				cout<<"\t"<<"*******************2-TELEFONO**************"<<endl;
				cout<<"\t"<<"*******************3-CABLE*************E****"<<endl;
				cout<<"\t"<<"*******************4-REGRESAR MENU PRINCIPAL*"<<endl;
				cout<<"ELIJA SU OPCION "<<endl;
				cin>>ser;
				switch(ser)
				{   
				 case 1:cout<<"\t"<<" ************1-AGUA******************"<<endl;
				        cout<<" DIGITE VR A CANCELAR "<<endl;
						cin>>vr;
						cout<<" Su transaccion se realizo con exito vr cancelado es "<<vr<<endl;
					     system("pause");
					    break;
				 case 2:cout<<"\t"<<" ************2-TELEFONO******************"<<endl;
				        cout<<" DIGITE VR A CANCELAR "<<endl;
						cin>>vr;
						cout<<" Su transaccion se realizo con exito vr cancelado es "<<vr<<endl;
					     system("pause");
					    break;	
				case 3:cout<<"\t"<<" ************3-CABLE******************"<<endl;
				        cout<<" DIGITE VR A CANCELAR "<<endl;
						cin>>vr;
						cout<<" Su transaccion se realizo con exito vr cancelado es "<<vr<<endl;
					     system("pause");
					    break;
						default: cout<<" REGRESAR MENU PRINCIPAL"<<endl;					 
						}
			    		}while(ser!=4);
						break;
				case 4:cout<<"\t"<<"**************4-CAMBIO CLAVE***************"<<endl;
				        cout<<"\t DIGITE SU CLAVE PERSONAL _ _ _ "<<endl;
 						cin>>clave;
 						if(clave==clavecajero)
 						{
 					 	cout<<" Ingrese su nueva clave  "<<endl;
				     	cin>>clave;
						clavecajero=clave;
						cout<<" Su transaccion se realizo con exito "<<endl;
					   }
					   else
					   {
					   	cout<<" CLAVE ERRADA *** INTENTE DE NUEVO"<<endl;
                    	 
	                    
 				     }
					  system("pause");
 				      break;
					   
		
	}
}while(opc !=5);
	
 }
 else
 {
 	cout<<" CLAVE ERRADA *** INTENTE DE NUEVO"<<endl;
 	contador=contador-1;
 	if(contador ==0)
 	{
 	 cout<<" SU CLAVE FUE BLOQUEADA COMUNIQUESE CON UN ASESOR DE SERVICIOS "<<endl;	
	 }
	 system("pause");
	 system("cls");
	 
 }
}while(clave!=clavecajero && contador >0);
 	
 	system("PAUSE");
	return EXIT_SUCCESS;
}
