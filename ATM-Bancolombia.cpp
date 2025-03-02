//									Codigo C++ hecho por: Nicolas Ceballos Brito



//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
#include <windows.h>
#define color SetConsoleTextAttribute

using namespace std;

//-------------------------------------------------		Centrar los datos		-------------------------------------------------



void gotoxy (int x, int y){
	
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X= x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon, dwPos);
	
}



//-------------------------------------------------		Cuadro		-------------------------------------------------



void cuadro(int x1,int y1,int x2,int y2){
	int i;
	
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	
    gotoxy(x1,y1); cout<< "\332"; 
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}



//-------------------------------------------------		Pantalla Completa		-------------------------------------------------



void AltEnter(){
	
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    
    return;
    
}



//-------------------------------------------------		Estructura Cliente		-------------------------------------------------



struct cliente{

	long cedula;
	int numCuenta;
	string email;
	int celular;
	int contra;	
	double saldo;
	long pagos[10];
	double precioPagos[10];

};



//-------------------------------------------------		Validacion de Correo		-------------------------------------------------
	
	
	
bool validarCorreo(string correo){
	
	for (int i=0;i<correo.size();i++){
		
		if(correo[i]=='@'){
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(70, 14);cout<<"CORREO GUARDADO CON EXITO.\n";
			gotoxy(70, 15);system ("pause");
			return true;
				
		}
	}		
	
	if(correo.empty()){
		cuadro(1, 1, 170, 45);
		cuadro(35, 12, 135, 32);
		gotoxy(70, 14);cout<<"ESTA VACIO, ESCRIBE UN CORREO VALIDO.\n";
		gotoxy(70, 15);system ("pause");
		return false;
		
	}
	cuadro(1, 1, 170, 45);
	cuadro(35, 12, 135, 32);
	gotoxy(70, 14);cout<<"DATOS INVALIDOS.\n";
	gotoxy(70, 15);system ("pause");	
	return false;
}



//-------------------------------------------------		Validacion de un String		-------------------------------------------------



bool validarString(string nombre){

	for (int i=0;i<nombre.size();i++){
		
		if(nombre[i]==' '){
			
			return true;
			
		}
		if(nombre[i]>='A' && nombre[i]<='Z'){
			
			return true;
			
		}
		if(nombre[i]>='a' && nombre[i]<='z'){
			
			return true;
			
		}
	
	}
	cuadro(1, 1, 170, 45);
	cuadro(35, 12, 135, 32);
	gotoxy(70, 14);cout<<"RECUERDE INGRESAR SOLO LETRAS.\n\n";
	gotoxy(70, 15);system ("pause");
	return false;

}



//-------------------------------------------------		Validacion de un numero Entero/Long		-------------------------------------------------



bool validarNumE(string clave){

	for (int i=0;i<clave.size();i++){
	
		if(clave[i]<48 || clave[i]>57){
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(70, 14);cout<<"RECUERDE INGRESAR SOLO NUMEROS ENTEROS POSITIVOS.\n\n";
			gotoxy(70, 15);system ("pause");
			return false;
			
		}
	
	}

return true;

}



//-------------------------------------------------		Validacion de un numero Float/Double		-------------------------------------------------



bool validarFloat(string clave){

	int conta=0;
	
	for (int i=0;i<clave.size();i++){
		
		if(clave[i]=='/'){
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(70, 14);cout<<"RECUERDE INGRESAR SOLO NUMEROS ENTEROS O DECIMALES POSITIVOS. \n\n";
			gotoxy(70, 15);system ("pause");
			return false;
			break;
			
		}
		
		if(clave[i]==46){
			
			conta++;
			
		}
		
		if(clave[i]<46 || clave[i]>57 || conta>1){
			
			return false;
			
		}
	
	}
	
	return true;
	
}



//-------------------------------------------------		Validacion de !0		-------------------------------------------------



bool validaCero(long cedula){
	
	if(cedula==0){
		cuadro(1, 1, 170, 45);
		cuadro(35, 12, 135, 32);
		gotoxy(70, 14);cout<<"RECUERDE INGRESAR MAS DE CERO. \n\n";
		return false;
			
	}

return true;

}



//-------------------------------------------------		Validacion de Cedula		-------------------------------------------------



bool validarCed(cliente cuenta[], long &cedula){
	
	for(int i=0; cuenta[i].cedula!=0; i++){
		
		if(cuenta[i].cedula==cedula){
			
			return false;
			
		}
		
	}
	
return true;
	
}



//-------------------------------------------------		Contrasena		-------------------------------------------------



string recibirClave(){

	int cantletras=0;
	char contra;
	string clave="";
	
	system("cls");
	cuadro(1, 1, 170, 45);
	cuadro(35, 12, 135, 32);
	gotoxy(70, 14);cout<<"INGRESE UNA CLAVE DE 4 DIGITOS: ";
	gotoxy(70, 15);

	cantletras=1;
	
	do{
		contra=getch();
		
		if(contra>='0' && contra<='9'){
			
			cout<<"*";
			clave+=contra;
			cantletras++;
			
		}
		
		if (cantletras==5){
			
			if (validarNumE(clave)==false){
				
				cantletras=1;
				clave="";
				system("cls");
				cuadro(1, 1, 170, 45);
				cuadro(35, 12, 135, 32);
				gotoxy(70, 14);cout<<"INTENTE NUEVAMENTE INGRESAR LA CLAVE: \n";
				
			}
		}
		
	}while(cantletras<=4 || validarNumE(clave)==false) ;
	
	return clave;
}



//-------------------------------------------------		Validar posicion de Ipagos		-------------------------------------------------



int validarIpagos(cliente cuenta[],int tam,long c1){
	
	if(validarCed(cuenta, c1)==false){
		
		for(int i=0;i<tam;i++){
		
			if(cuenta[i].cedula==c1){
				
				return i;
				
			}
		
		}
		
	}
	
	return 2000;
	
}



//-------------------------------------------------		Consignacion		-------------------------------------------------



void consignar(cliente cuenta[],int tam){
	
	string p="";
	double p1=0;
	
	string c="";
	long c1=0;
	
	double cuatroxmil=0;
	double cons=0;
	
	int clave=0;
	
	int opcion=0;
	string opcion1="";
	
	string nombre="";
	
	system("cls");
	cuadro(1, 1, 170, 45);
	cuadro(35, 12, 135, 32);
	gotoxy(60, 14);cout<<"SE LE COBRARA EL GRAVAMEN DE MOVIMIENTOS FINANCIEROS (4X1000).";
	gotoxy(60, 15);cout<<"QUIERE CONTINUAR CON LA CONSIGNACION?";
	do{
		
		gotoxy(70, 17);cout<<"1. SI\n";
		gotoxy(70, 18);cout<<"2. NO\n";
		
		do{
			gotoxy(70, 20);cout<<"INGRESA UNA OPCION ---> ";
			fflush(stdin);
			getline(cin,opcion1);
						
		}while(validarNumE(opcion1)==false);
					
		istringstream(opcion1)>>opcion;
					
		switch(opcion){
	
			case 1:{
				
				do{
					
					system("cls");
					cuadro(1, 1, 170, 45);
					cuadro(35, 12, 135, 32);
					gotoxy(55, 14);cout<<"INGRESE EL NUMERO DE LA CUENTA A LA QUE SE VA A CONSIGNAR:";
					gotoxy(55, 15);
					fflush(stdin);
					getline(cin,c);
					
				}while(validarNumE(c)==false);
					
				istringstream(c)>>c1;
				
				int i=0;
				i=validarIpagos(cuenta,tam,c1);	
				
				if(i<tam){
						
					system("cls");
					cuadro(1, 1, 170, 45);
					cuadro(35, 12, 135, 32);
					gotoxy(70, 14);cout<<"CUENTA ENCONTRADA.\n";
					gotoxy(70, 15);system ("pause");
						
					do{
					
						system("cls");
						cuadro(1, 1, 170, 45);
						cuadro(35, 12, 135, 32);
						gotoxy(70, 14);cout<<"INGRESE SU NOMBRE O EL DE SU EMPRESA:";
						gotoxy(70, 15);
						fflush(stdin);
						getline(cin,nombre);
							
					}while(validarString(nombre)==false);
						
					system("cls");
					cuadro(1, 1, 170, 45);
					cuadro(35, 12, 135, 32);
					gotoxy(70, 14);cout<<"NOMBRE REGISTRADO.\n";
					gotoxy(70, 15);system ("pause");
												
					do{
							
						system("cls");
						cuadro(1, 1, 170, 45);
						cuadro(35, 12, 135, 32);
						gotoxy(70, 14);cout<<"INGRESE UN VALOR A CONSIGNAR:";
						gotoxy(70, 15);
						fflush(stdin);
						getline(cin,p);
							
					}while(validarFloat(p)==false);
						
					istringstream(p)>>p1;
						
					if(p1>=1000){
						
						cuatroxmil=(p1*4)/1000;
						cons=p1-cuatroxmil;
						cuenta[i].saldo=cuenta[i].saldo+cons;
								
						system("cls");
						cuadro(1, 1, 170, 45);
						cuadro(35, 12, 135, 32);
						gotoxy(60, 14);cout<<"CONSIGNACION REALIZADA CON EXITO A NOMBRE DE: "<<nombre<<".\n";
//						cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
						return;
						
					}
					if(p1<1000){
							
						cuenta[i].saldo=cuenta[i].saldo+p1;
								
						system("cls");
						cuadro(1, 1, 170, 45);
						cuadro(35, 12, 135, 32);
						gotoxy(60, 14);cout<<"A LA CONSIGNACION NO SE LE APLICO EL IMPUESTO, EL VALOR INGRESADO ES MENOR A $1000";
						gotoxy(60, 15);cout<<"CONSIGNACION REALIZADA CON EXITO A NOMBRE DE: "<<nombre<<".";
//						cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
						return;
							
					}
					if(p1<=0){
							
						system("cls");
						cuadro(1, 1, 170, 45);
						cuadro(35, 12, 135, 32);
						gotoxy(70, 14);cout<<"A LA CONSIGNACION NO SE REALIZO, EL VALOR INGRESADO ES MENOR O IGUAL A $0\n";
//						cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
						return;
							
					}
					
				}
				else{
					
					system("cls");
					cuadro(1, 1, 170, 45);
					cuadro(35, 12, 135, 32);
					gotoxy(70, 14);cout<<"NO EXISTE LA CUENTA, REVISE SUS DATOS.\n\n";
					return;
					
				}
				
			}
			
			default:{
				
				system("cls");
				cuadro(1, 1, 170, 45);
				cuadro(35, 12, 135, 32);
				gotoxy(70, 14);cout<<"VOLVIENDO AL MENU.\n\n";
				return;
				
			}
			
		}
	
	}while(opcion!=1);
	
	return;
	
}



//-------------------------------------------------		Validar posicion		-------------------------------------------------



int validarPos(cliente cuenta[],int tam){
	
	for(int i=0;i<tam;i++){
		
		if(cuenta[i].cedula==0 && cuenta[i].numCuenta==0 && cuenta[i].email=="" && cuenta[i].celular==0 && cuenta[i].contra==0 && cuenta[i].saldo==0){
			
			return i;
		
		}
		
	}
	
	return 2000;
}



//-------------------------------------------------		Crear cuenta		-------------------------------------------------



void crearCuenta(cliente cuenta[],int tam){
	
	int i=0;
	i=validarPos(cuenta, tam);
	
	string aux1="";
	long cedula=0;
	
	string correo="";
	
	string aux2="";
	
	string opcion1="";
	int opcion=0;

	
	system("cls");
	cuadro(1, 1, 170, 45);
	cuadro(35, 12, 135, 32);
	gotoxy(60, 14);cout<<"GRACIAS POR DEPOSITAR TU CONFIANZA EN NOSOTROS.";
	gotoxy(70, 15);cout<<"AHORA VAMOS A CREAR UNA CUENTA.";
	gotoxy(60, 17);system("pause");
	
	if(i<tam){
		
		do{
			system("cls");
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
//			cout<<"GUARDANDO EN POSICION: "<<i<<" \n";
			gotoxy(60, 14);cout<<"INGRESE SU CEDULA SIN PUNTUACION: ";
			gotoxy(94, 14);
			fflush(stdin);
			getline(cin,aux1);
			
		}while(validarNumE(aux1)==false);
			
		istringstream(aux1)>>cedula;	
			
		if(validarCed(cuenta, cedula)==true && validaCero(cedula)==true){
			
			cuenta[i].cedula=cedula;
			cuenta[i].numCuenta=cuenta[i].cedula;	
			system("cls");
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(65, 14);cout<<"SU NUMERO DE CUENTA ES : "<<cuenta[i].numCuenta<<"\n";
			gotoxy(65, 15);system("pause");
				
			do{
				system("cls");
				cuadro(1, 1, 170, 45);
				cuadro(35, 12, 135, 32);
				gotoxy(70, 14);cout<<"INGRESE SU E-MAIL: ";
				gotoxy(70, 15);
				fflush(stdin);
				getline(cin,correo);
					
			}while(validarCorreo(correo)==false);
			cuenta[i].email=correo;
				
			do{
				system("cls");
				cuadro(1, 1, 170, 45);
				cuadro(35, 12, 135, 32);
				gotoxy(70, 14);cout<<"INGRESE SU NUMERO DE CELULAR: ";
				gotoxy(70, 15);
				fflush(stdin);
				getline(cin,aux2);
				
			}while(validarNumE(aux2)==false);
			istringstream(aux2)>>cuenta[i].celular;
			gotoxy(70, 17);cout<<"CELULAR GUARDADO CON EXITO.\n"<<cuenta[i].celular;
			gotoxy(70, 18);system("pause");
			
			system("cls");
			istringstream(recibirClave())>>cuenta[i].contra;
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(70, 17);cout<<"CLAVE GUARDADA CON EXITO.";
			gotoxy(70, 18);system("pause");
				
			system("cls");
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(70, 14);cout<<"¡CUENTA CREADA CON EXITO!"<<endl;
				
/*			cout<<"SU CEDULA ES: "<<cuenta[i].cedula<<"\n";
			cout<<"SU NUMERO DE CUENTA ES: "<<cuenta[i].numCuenta<<"\n";
			cout<<"SU E-MAIL REGISTRADO ES: "<<cuenta[i].email<<"\n";
			cout<<"SU CELULAR ES: "<<cuenta[i].celular<<"\n";
			cout<<"SU CLAVE: "<<cuenta[i].contra<<"\n";
			cout<<"SU SALDO: "<<cuenta[i].saldo<<"\n";			*/
			gotoxy(70, 16);system("pause");
			
			system("cls");
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(70, 14);cout<<"EL SALDO ACTUAL DE LA CUENTA ES DE: "<<cuenta[i].saldo;
			gotoxy(70, 15);cout<<"QUIERE REALIZAR UNA CONSIGNACION?\n";
			do{
					
				gotoxy(70, 17);cout<<"1. SI\n";
				gotoxy(70, 18);cout<<"2. NO\n";
					
				do{
					gotoxy(70, 20);cout<<"INGRESA UNA OPCION ---> ";
					fflush(stdin);
					getline(cin,opcion1);
						
				}while(validarNumE(opcion1)==false);
					
				istringstream(opcion1)>>opcion;
					
				switch(opcion){
	
					case 1:{
						system("cls");
						cuadro(1, 1, 170, 45);
						cuadro(35, 12, 135, 32);
						consignar(cuenta,tam);
						return;
					}
					
					default:{
						system("cls");
						cuadro(1, 1, 170, 45);
						cuadro(35, 12, 135, 32);
						gotoxy(70, 14);cout<<"GRACIAS POR CREAR UNA CUENTA CON NOSOTROS.\n";	
						gotoxy(70, 15);cout<<"VOLVIENDO AL MENU.\n\n";
						return;
						
					}
						
				}
					
			}while(opcion!=1);
				
			return;
		}
		
		else{
			
			system("cls");
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(70, 14);cout<<"SU CEDULA ESTA REPETIDA, POR FAVOR REVISE SUS DATOS.\n";
			return;
			
		}
		
	}
	
	else{
		
		system("cls");
		cuadro(1, 1, 170, 45);
		cuadro(35, 12, 135, 32);
		gotoxy(70, 14);cout<<"NO HAY ESPACIO PARA CREAR MAS CUENTAS.\n";
		return;
	}

}



//-------------------------------------------------		Consultar saldo		-------------------------------------------------



void saldo(cliente cuenta[],int tam){
	
	double aux=0;
	
	string c="";
	long c1=0;
	int clave=0;
	
	int opcion=0;
	string opcion1="";
	
	system("cls");
//	cuadro(1, 1, 170, 45);
//	cuadro(35, 12, 135, 32);
	cout<<"SE LE COBRARA $1500 POR LA CONSULTA DEL SALDO.\nQUIERE CONTINUAR CON LA CONSULTA?\n";
				
	do{
					
		cout<<"1. SI\n";
		cout<<"2. NO\n";
					
		do{
			cout<<"INGRESA UNA OPCION ---> ";
			fflush(stdin);
			getline(cin,opcion1);
						
		}while(validarNumE(opcion1)==false);
					
		istringstream(opcion1)>>opcion;
					
		switch(opcion){
	
			case 1:{
				
				do{
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"INGRESE SU NUMERO DE CUENTA: ";
					fflush(stdin);
					getline(cin,c);
				
				}while(validarNumE(c)==false);
				
				istringstream(c)>>c1;
				
				int i=0;
				i=validarIpagos(cuenta,tam,c1);
				
				if(i<tam){
						
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"CUENTA ENCONTRADA.\n";
					cout<<"CONFIRME POR FAVOR SU CLAVE: \n";
					system ("pause");
						
					istringstream(recibirClave())>>clave;
						
					if(c1==cuenta[i].numCuenta && clave==cuenta[i].contra){
							
						system("cls");
					//	cuadro(1, 1, 170, 45);
					//	cuadro(35, 12, 135, 32);
						cout<<"CLAVE CORRECTA.\n";
						system ("pause");
							
						aux=cuenta[i].saldo-1500;
							
						if(aux>=1500){
						
							system("cls");
							//cuadro(1, 1, 170, 45);
							//cuadro(35, 12, 135, 32);
							cuenta[i].saldo=cuenta[i].saldo-1500;
							cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
							return;
								
						}
						if(aux<1500){
							system("cls");
							//cuadro(1, 1, 170, 45);
							//cuadro(35, 12, 135, 32);
							cout<<"El SALDO DE LA CUENTA ES INSUFICIENTE. \n";
							return;
								
						}
						if(aux<=0){
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"El SALDO DE LA CUENTA ES INSUFICIENTE. \n";
							return;
						
						}
					
					}
						
					else{
							
						system("cls");
						//cuadro(1, 1, 170, 45);
					//	cuadro(35, 12, 135, 32);
						cout<<"LA CLAVE ES INCORRECTA, VUELVE A INTENTARLO.\n";
						return;
							
					}
						
				}
					
				else{
						
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"NO EXISTE LA CUENTA, REVISE SUS DATOS.\n\n";
					return;
					
				}
				
			}
					
			default:{
				system("cls");
			//	cuadro(1, 1, 170, 45);
			//	cuadro(35, 12, 135, 32);
				cout<<"VOLVIENDO AL MENU.\n\n";
				return;
						
			}
						
		}
					
	}while(opcion!=1);
	
}



//-------------------------------------------------		Retiros		-------------------------------------------------



void retiro(cliente cuenta[],int tam){

	string p="";
	double p1=0;
	
	string c="";
	long c1=0;
	
	int clave=0;
	
	double aux=0;
	double aux2=0;
	
	int opcion=0;
	string opcion1="";
	
	double ret=0;
	
	system("cls");
//	cuadro(1, 1, 170, 45);
//	cuadro(35, 12, 135, 32);
	cout<<"SE LE COBRARAN $2000 POR UN RETIRO.\nQUIERE CONTINUAR CON EL RETIRO?\n";
				
	do{
		
		cout<<"1. SI\n";
		cout<<"2. NO\n";
		
		do{
			cout<<"INGRESA UNA OPCION ---> ";
			fflush(stdin);
			getline(cin,opcion1);
						
		}while(validarNumE(opcion1)==false);
					
		istringstream(opcion1)>>opcion;
					
		switch(opcion){
	
			case 1:{
				
				do{
					
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"INGRESE SU NUMERO DE CUENTA:\n";
					fflush(stdin);
					getline(cin,c);
					
				}while(validarNumE(c)==false);
					
				istringstream(c)>>c1;
				
				int i=0;
				i=validarIpagos(cuenta,tam,c1);	
				
				if(i<tam){
					
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"CUENTA ENCONTRADA\n";
					cout<<"CONFIRME ACONTINUACION SU CLAVE...\n";
					system ("pause");
						
					istringstream(recibirClave())>>clave;
						
					if(c1==cuenta[i].numCuenta && clave==cuenta[i].contra){
							
						cout<<"\nCLAVE CORRECTA.\n";
						system ("pause");
							
						do{
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"INGRESE UN VALOR A RETIRAR:\n";
							fflush(stdin);
							getline(cin,p);
								
						}while(validarFloat(p)==false);
						
						istringstream(p)>>p1;
						
						aux=cuenta[i].saldo-p1;
						aux2=aux-2000;
							
						if(aux2>=2000){
						
							ret=cuenta[i].saldo-p1;
							cuenta[i].saldo=ret-2000;
									
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"EL RETIRO SE REALIZO CON EXITO\n";
//							cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
							return;
								
						}
							
						if(aux2<2000){
							
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"El SALDO DE LA CUENTA ES INSUFICIENTE. \n";
							return;
								
						}
						if(aux2<=0){
							
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"El SALDO DE LA CUENTA ES INSUFICIENTE. \n";
							return;
								
						}
						
					}
					
					else{
						
						system("cls");
					//	cuadro(1, 1, 170, 45);
					//	cuadro(35, 12, 135, 32);
						cout<<"CLAVE INCORRECTA.\n";
						return;
						
					}
					
				}
				else{
					
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"NO EXISTE LA CUENTA, REVISE SUS DATOS.\n\n";
					return;
					
				}
				
			}
			
			default:{
				
				system("cls");
			//	cuadro(1, 1, 170, 45);
			//	cuadro(35, 12, 135, 32);
				cout<<"VOLVIENDO AL MENU.\n\n";
				return;
				
			}
			
			return;
			
		}
	
	}while(opcion!=1);
	
	return;
	
}



//-------------------------------------------------		Inscripcion de pagos		-------------------------------------------------



void ipagos(cliente cuenta[],int tam){
	
	int conta=0;
	
	string c="";
	long c1=0;
	int clave=0;
	
	string p="";
	string p2="";
	
	long aux=0;
	double aux2=0;
				
	do{
					
		system("cls");
	//	cuadro(1, 1, 170, 45);
	//	cuadro(35, 12, 135, 32);
		cout<<"INGRESE SU NUMERO DE CUENTA:\n";
		fflush(stdin);
		getline(cin,c);
					
	}while(validarNumE(c)==false);
	
	istringstream(c)>>c1;
	
	int i=0;
	i=validarIpagos(cuenta,tam,c1);	
	
	if(i<tam){

		system("cls");
	//	cuadro(1, 1, 170, 45);
	//	cuadro(35, 12, 135, 32);
		cout<<"CUENTA ENCONTRADA\n";
		cout<<"CONFIRME ACONTINUACION SU CLAVE.\n";
		system ("pause");
		
		istringstream(recibirClave())>>clave;
			
			if(c1==cuenta[i].numCuenta && clave==cuenta[i].contra){
				
				system("cls");
			//	cuadro(1, 1, 170, 45);
			//	cuadro(35, 12, 135, 32);
//				cout<<"GUARDANDO EN POSICION: "<<i<<" \n";
				cout<<"CLAVE CORRECTA.\n";
				system ("pause");
				
				int j=0;
				
				do{
				
					if(cuenta[i].pagos[j]==0 && cuenta[i].precioPagos[j]==0){
							
						do{
										
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"INGRESE EL NUMERO DE PAGO:\n";
							fflush(stdin);
							getline(cin,p);
							
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"INGRESE EL PRECIO DEl PAGO:\n";
							fflush(stdin);
							getline(cin,p2);
												
						}while(validarNumE(p)==false && validarFloat(p2)==false);
								
						istringstream(p)>>aux;
						istringstream(p2)>>aux2;
								
						if(validaCero(aux)==true && validaCero(aux2)==true){
									
							cuenta[i].pagos[j]=aux;
							cuenta[i].precioPagos[j]=aux2;
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"PAGO INSCRITO CON EXITO.\n";
							return;
									
						}
						else{
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"PAGO FALLIDO, NO SE PUEDE INSCRIBIR UN PAGO EN $0.\n";
							return;
									
						}
							
					}
					
					
					j++;
					
					conta++;
					
				}while(j<10);
				
				
				if(conta==10){
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"NO HAY MAS ESPACIOS PARA INCRIBIR PAGOS\n";
					return;
							
				}
			}
			else{
			
				system("cls");
			//	cuadro(1, 1, 170, 45);
			//	cuadro(35, 12, 135, 32);
				cout<<cuenta[i].contra;
				cout<<"CLAVE INCORRECTA.\n";
				return;
					
			}	
	}
	else{
		
		system("cls");
	//	cuadro(1, 1, 170, 45);
	//	cuadro(35, 12, 135, 32);
		cout<<"NO EXISTE LA CUENTA, REVISE SUS DATOS.\n\n";
		return;
	}		
	
		
}



//-------------------------------------------------		Pagos		-------------------------------------------------



void pagos(cliente cuenta[],int tam){
	
	int conta=0;
	
	string c="";
	long c1=0;
	int clave=0;
	
	string p="";
	string p2="";
	
	long aux=0;
	double aux2=0;
				
	do{
					
		system("cls");
	//	cuadro(1, 1, 170, 45);
	//	cuadro(35, 12, 135, 32);
		cout<<"INGRESE SU NUMERO DE CUENTA:\n";
		fflush(stdin);
		getline(cin,c);
					
	}while(validarNumE(c)==false);
	
	istringstream(c)>>c1;
	
	int i=0;
	i=validarIpagos(cuenta,tam,c1);	
	
	if(i<tam){

		system("cls");
	//	cuadro(1, 1, 170, 45);
	//	cuadro(35, 12, 135, 32);
		cout<<"CUENTA ENCONTRADA\n";
		cout<<"CONFIRME ACONTINUACION SU CLAVE.\n";
		system ("pause");
		
		istringstream(recibirClave())>>clave;
			
			if(c1==cuenta[i].numCuenta && clave==cuenta[i].contra){
				
				system("cls");
			//	cuadro(1, 1, 170, 45);
			//	cuadro(35, 12, 135, 32);
//				cout<<"GUARDANDO EN POSICION: "<<i<<" \n";
				cout<<"CLAVE CORRECTA.\n";
				system ("pause");
				
				for(int t=0;t<10;t++){
					
					if(cuenta[i].pagos[t]!=0){
					
						cout<<t+1<<". "<<cuenta[i].pagos[t]<<": "<<cuenta[i].precioPagos[t]<<"\n";
						
					}
					
				}
				
				do{
								

				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"INGRESE UN NUMERO DE PAGO:\n";
					fflush(stdin);
					getline(cin,p);
												
				}while(validarNumE(p)==false);
				
				istringstream(p)>>aux;
				
				if(validaCero(aux)==true){
									
					int j=0;
					do{
						
						if(aux==cuenta[i].pagos[j]){
								
							if(cuenta[i].precioPagos[j]<cuenta[i].saldo){
								
								system("cls");
							//	cuadro(1, 1, 170, 45);
							//	cuadro(35, 12, 135, 32);
								cout<<"SE PROCEDERA A REALIZAR EL PAGO.\n";
								system ("pause");
								
								cuenta[i].saldo=cuenta[i].saldo-cuenta[i].precioPagos[j];
								cuenta[i].pagos[j]=0;
								cuenta[i].precioPagos[j]=0;
								cout<<"PAGO REALIZADO CON EXITO.\n";
								return;
								
							}
							
							else{
								
								system("cls");
							//	cuadro(1, 1, 170, 45);
							//	cuadro(35, 12, 135, 32);
								cout<<"NO SE TIENE EL SALDO SUFICIENTE PARA PAGAR\n";
								return;
								
							}
								
						}
						
						j++;
						
						conta++;
						
					}while(j<10);
					
					if(conta==10){
						
						system("cls");
					//	cuadro(1, 1, 170, 45);
					//	cuadro(35, 12, 135, 32);
						cout<<"NO EXISTE EL NUMERO DE PAGO\n";
						return;
								
					}
									
				}
				else{
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"PAGO FALLIDO, NO EXISTE EL NUMERO DE PAGO 0.\n";
					return;
									
				}
				
			
			}
			else{
			
				system("cls");
			//	cuadro(1, 1, 170, 45);
			//	cuadro(35, 12, 135, 32);
				cout<<cuenta[i].contra;
				cout<<"CLAVE INCORRECTA.\n";
				return;
					
			}	
	}
	else{
		
		system("cls");
	//	cuadro(1, 1, 170, 45);
	//	cuadro(35, 12, 135, 32);
		cout<<"NO EXISTE LA CUENTA, REVISE SUS DATOS.\n\n";
		return;
	}		
	
		
}
	


//-------------------------------------------------		Cancelacion o cierre		-------------------------------------------------



void cerrarCuenta(cliente cuenta[],int tam){
	
	string c="";
	long c1=0;
	
	int clave=0;
	
	int opcion=0;
	string opcion1="";
	
	system("cls");
//	cuadro(1, 1, 170, 45);
//	cuadro(35, 12, 135, 32);
	cout<<"SE EFECTUARA UN RETIRO DEL TOTAL DE SU SALDO.\nQUIERE CONTINUAR CON EL RETIRO?\n";
				
	do{
		
		cout<<"1. SI\n";
		cout<<"2. NO\n";
		
		do{
			cout<<"INGRESA UNA OPCION ---> ";
			fflush(stdin);
			getline(cin,opcion1);
						
		}while(validarNumE(opcion1)==false);
					
		istringstream(opcion1)>>opcion;
					
		switch(opcion){
	
			case 1:{
				
				do{
					
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"INGRESE SU NUMERO DE CUENTA:\n";
					fflush(stdin);
					getline(cin,c);
					
				}while(validarNumE(c)==false);
					
				istringstream(c)>>c1;
				
				int i=0;
				i=validarIpagos(cuenta,tam,c1);	
				
				if(i<tam){
					
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"CUENTA ENCONTRADA\n";
					cout<<"CONFIRME ACONTINUACION SU CLAVE: ";
					system ("pause");
						
					istringstream(recibirClave())>>clave;
						
					if(c1==cuenta[i].numCuenta && clave==cuenta[i].contra){
					//	cuadro(1, 1, 170, 45);
					//	cuadro(35, 12, 135, 32);
						cout<<"\nCLAVE CORRECTA.\n";
						system ("pause");
							
						if(cuenta[i].saldo>0){
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
							cout<<"SE PROCEDERA A RETIRAR EL DINERO DE SU CUENTA...\n";
							system ("pause");
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cuenta[i].saldo=cuenta[i].saldo-cuenta[i].saldo;
							cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
							cout<<"EL RETIRO SE REALIZO CON EXITO\n";
							system ("pause");
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"SE PROCEDERA A BORRAR SU CUENTA CON SUS DATOS...\n";
							system ("pause");
								
							int f=0;
								
							for(int i=0;f<1;i++){
									
								cuenta[i].cedula=0;
								cuenta[i].numCuenta=0; 
								cuenta[i].email="";
								cuenta[i].celular=0;
								cuenta[i].contra=0;
								cuenta[i].saldo=0;
										
								for(int j=0;j<10;j++){
										
									cuenta[i].pagos[j]=0;
									cuenta[i].precioPagos[j]=0;
										
								}
									
								f++;
							}
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"CUENTA BORRADA CON EXITO\n";
							return;
								
						}
						if(cuenta[i].saldo==0){
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"El SALDO DE LA CUENTA ES: "<<cuenta[i].saldo<<"\n";
							cout<<"ESTAS A PAZ Y SALVO\n";
							system ("pause");
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"SE PROCEDERA A BORRAR SU CUENTA CON SUS DATOS...\n";
							system ("pause");
								
							int f=0;
								
							for(int i=0;f<1;i++){
									
								cuenta[i].cedula=0;
								cuenta[i].numCuenta=0; 
								cuenta[i].email="";
								cuenta[i].celular=0;
								cuenta[i].contra=0;
								cuenta[i].saldo=0;
										
								for(int j=0;j<10;j++){
										
									cuenta[i].pagos[j]=0;
									cuenta[i].precioPagos[j]=0;
										
								}
									
								f++;
							}
								
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"CUENTA BORRADA CON EXITO\n";
							return;
								
						}	
						if(cuenta[i].saldo<0){
							
							system("cls");
						//	cuadro(1, 1, 170, 45);
						//	cuadro(35, 12, 135, 32);
							cout<<"El SALDO DE LA CUENTA ES NEGATIVO: "<<cuenta[i].saldo<<" POR FAVOR CONSIGNE PARA TENER SU SALDO EN 0";
							system ("pause");
							consignar(cuenta,tam);
							return;
							
						}
							
					}
						
					else{
							
						system("cls");
					//	cuadro(1, 1, 170, 45);
					//	cuadro(35, 12, 135, 32);
						cout<<"CLAVE INCORRECTA.\n";
						system ("pause");
						return;
							
					}
					
				}
				else{
					
					system("cls");
				//	cuadro(1, 1, 170, 45);
				//	cuadro(35, 12, 135, 32);
					cout<<"NO EXISTE LA CUENTA, REVISE SUS DATOS.\n\n";
					return;
					
				}
				
			}
			
			default:{
				
				system("cls");
			//	cuadro(1, 1, 170, 45);
			//	cuadro(35, 12, 135, 32);
				cout<<"VOLVIENDO AL MENU.\n\n";
				return;
				
			}
			
			return;
			
		}
	
	}while(opcion!=1);
	
	return;
	
}



//-------------------------------------------------		Main menu		-------------------------------------------------



int main(){
	
	AltEnter();
//	cuadro(1, 1, 170, 45);
//	cuadro(10, 14, 160, 28);
	system( "Title Cajero Automatico: interfaz ATM (BANCOLOMBIA)                                                               Codigo C++ hecho por: Nicolas Ceballos Brito (1089096352)" );
	system("Color f4");
	
	int tam=2;
	cliente cuenta[tam];
	
	for(int i=0;i<tam;i++){
		
		cuenta[i].cedula=0;
		cuenta[i].numCuenta=0; 
		cuenta[i].email="";
		cuenta[i].celular=0;
		cuenta[i].contra=0;
		cuenta[i].saldo=0;
		
		for(int j=0;j<10;j++){
			
			cuenta[i].pagos[j]=0;
			cuenta[i].precioPagos[j]=0;
						
		}
		
	}
	
	int opcion=0;
	string opcion1="";
	
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	
/*	int conta=0;
	for(int i=0;i<300;i++){	
	
		color(hConsole, i);
		cout<<conta<<"INGRESA UNA OPCION ---> \n";
		conta++;
		
	}*/
		
		do{
			system("cls");
			cuadro(1, 1, 170, 45);
			cuadro(10, 14, 160, 28);
			gotoxy(36, 17);color(hConsole, 241);cout<<"########     ###    ##    ##  ######   #######  ##        #######  ##     ## ########  ####    ###    \n";Beep(100,150);Sleep(50);
			gotoxy(36, 18);color(hConsole, 241);cout<<"##     ##   ## ##   ###   ## ##    ## ##     ## ##       ##     ## ###   ### ##     ##  ##    ## ##   \n";Beep(200,150);Sleep(50);
			gotoxy(36, 19);color(hConsole, 246);cout<<"##     ##  ##   ##  ####  ## ##       ##     ## ##       ##     ## #### #### ##     ##  ##   ##   ##  \n";Beep(300,150);Sleep(50);	
			gotoxy(36, 20);color(hConsole, 246);cout<<"########  ##     ## ## ## ## ##       ##     ## ##       ##     ## ## ### ## ########   ##  ##     ## \n";Beep(400,150);Sleep(50);																																																																																																																																																																																																																				//				¡you are not supposed to be watching this!		:)			Codigo C++ hecho por: Nicolas Ceballos Brito (1089096352)
			gotoxy(36, 21);color(hConsole, 246);cout<<"##     ## ######### ##  #### ##       ##     ## ##       ##     ## ##     ## ##     ##  ##  ######### \n";Beep(500,150);Sleep(50);
			gotoxy(36, 22);color(hConsole, 244);cout<<"##     ## ##     ## ##   ### ##    ## ##     ## ##       ##     ## ##     ## ##     ##  ##  ##     ## \n";Beep(600,150);Sleep(50);
			gotoxy(36, 23);color(hConsole, 244);cout<<"########  ##     ## ##    ##  ######   #######  ########  #######  ##     ## ########  #### ##     ## \n";Beep(700,150);Sleep(50);
			Beep(800,400);
			gotoxy(36, 25);cout<<"TODOS LOS DERECHOS RESERVADOS.	";
//			cout<<"CODIGO C++ HECHO POR: NICOLAS CEBALLOS BRITO (1089096352)\n\n";
			system("pause");
			system("cls");
//			cout<<"CODIGO C++ HECHO POR: NICOLAS CEBALLOS BRITO (1089096352)\n\n";
			cuadro(1, 1, 170, 45);
			cuadro(35, 12, 135, 32);
			gotoxy(75, 14);cout<<"MENU PRINCIPAL\n";
			gotoxy(70, 16);cout<<" 1. CREAR DE CUENTA.";
			gotoxy(70, 17);cout<<" 2. CONSIGNACIONES.";
			gotoxy(70, 18);cout<<" 3. CONSULTAR SALDO.";
			gotoxy(70, 19);cout<<" 4. RETIROS.";
			gotoxy(70, 20);cout<<" 5. INSCRIBIR PAGOS.";
			gotoxy(70, 21);cout<<" 6. PAGOS.";
			gotoxy(70, 22);cout<<" 7. CANCELACION DE CUENTA.";
			gotoxy(70, 23);cout<<" 8. SALIR.";
			
			do{
				
				gotoxy(70, 26);cout<<"INGRESA UNA OPCION ---> ";
				fflush(stdin);
				getline(cin,opcion1);
			}while(validarNumE(opcion1)==false);
			
			istringstream(opcion1)>>opcion;
			
			switch(opcion){
				
/*				case 0:{
					cout<<"\t0. MOSTRAR TODOS LOS CLIENTES."<<endl;
					
					for(int i=0;i<tam;i++){
						
						cout<<"\n\n\nPOSICION: "<<i<<"\n\n";
						cout<<"SU CEDULA ES: "<<cuenta[i].cedula<<"\n";
						cout<<"SU NUMERO DE CUENTA ES: "<<cuenta[i].numCuenta<<"\n";
						cout<<"SU E-MAIL REGISTRADO ES: "<<cuenta[i].email<<"\n";
						cout<<"SU CELULAR ES: "<<cuenta[i].celular<<"\n";
						cout<<"SU CLAVE: "<<cuenta[i].contra<<"\n";
						cout<<"SU SALDO: "<<cuenta[i].saldo<<"\n";
						cout<<"\n";
						for(int j=0;j<10;j++){
							
							cout<<cuenta[i].pagos[j]<<": "<<cuenta[i].precioPagos[j]<<"\n";
						
						}
					}
					
					system ("pause");
					
					break;
				}// fin case 0*/
				
				
				
				case 1:{
					cout<<"\t1. CREAR DE CUENTA."<<endl;
					crearCuenta(cuenta, tam);
					gotoxy(70, 30);system ("pause");
					gotoxy(0, 90);
					break;
				}// fin case 1



				case 2:{
					cout<<"\t2. CONSIGNACIONES."<<endl;
					consignar(cuenta,tam);
					gotoxy(70, 30);system ("pause");
					gotoxy(0, 90);
					break;
				}// fin case 2



				case 3:{	
					cout<<"\t3. CONSULTAR SALDO."<<endl;
					saldo(cuenta,tam);
					gotoxy(70, 30);system ("pause");
					gotoxy(0, 90);
					break;
				}// fin case 3



				case 4:{
					cout<<"\t4. RETIROS."<<endl;
					retiro(cuenta,tam);
					gotoxy(70, 30);system ("pause");
					gotoxy(0, 90);
					break;
				}// fin case 4



				case 5:{
					cout<<"\t5. INSCRIBIR PAGOS."<<endl;
					ipagos(cuenta,tam);
					gotoxy(70, 30);system ("pause");
					gotoxy(0, 90);
					break;
				}// fin case 5



				case 6:{
					cout<<"\t6. PAGOS."<<endl;
					pagos(cuenta,tam);
					gotoxy(70, 30);system ("pause");
					gotoxy(0, 90);
					break;
				}// fin case 6



				case 7:{
					cout<<"\t7. CANCELACION DE CUENTA."<<endl;
					cerrarCuenta(cuenta,tam);
					gotoxy(70, 30);system ("pause");
					gotoxy(0, 90);
					break;
				}// fin case 7
				
				
				
				default:{
					gotoxy(70, 27);cout<<"SALIR.\n"<<endl;
					break;
				}//	fin del programa

			}// fin switch

		}while(opcion>=1 && opcion<=7); // fin do-while

	gotoxy(70, 30);system ("pause");
	gotoxy(0, 90);
	return 0;

}// fin main



//									Codigo C++ hecho por: Nicolas Ceballos Brito