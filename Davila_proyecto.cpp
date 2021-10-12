/*
PROGRAMACION DE COMPUTADORES 2019-1
GRUPO 6
PROYECTO INDIVIDUAL BUSCAMINAS
VICTOR MANUEL DAVILA CASTAÑEDA
1001218585
*/
#include <iostream> 
#include <stdio.h>
#include <string>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
//#include <wchar.h>
//#include <locale.h>

using namespace std;
//constantes globales que definen el tamaño de las cuadriculas  y la cantidad de puntajes (tienen que ser constantes para pasarlas como tamaños de los arreglos en las funciones)
const int tamanio_cuadricula=20;
const int tamanio_puntajes=10;

/*############################
#####################################################################################################################################
###################################################################################################################################
######################################################################################################################################
##################################################################################################################################
*/
//funcion que desarrolla la expansion de las minas
void revelar_casilla(char *matriz,bool *matrizbool,char matriz2[tamanio_cuadricula][tamanio_cuadricula], int matriz3[tamanio_cuadricula][tamanio_cuadricula],int x, int y){
	int a=tamanio_cuadricula-1;
	*(matriz+x*tamanio_cuadricula+y)=matriz2[x][y];
	*(matrizbool+x*tamanio_cuadricula+y)=false;
	for(int i=-1;i<=1;i++){
		for(int j=-1; j<=1; j++){
			if((x+i<0) || (y+j<0) || (x+i>=tamanio_cuadricula) || (y+j>=tamanio_cuadricula) || (i==0 && j==0)){
				//continue;
				//cout<<"salto"<<endl;
				//system("pause");
			}else{
				if(*(matrizbool+(x+i)*tamanio_cuadricula+y+j) && matriz3[x+i][y+j]==0){
					revelar_casilla(matriz, matrizbool, matriz2, matriz3,x+i,y+j);
					//cout<<"no salto1"<<endl;
					//system("pause");
				}
				*(matriz+(x+i)*tamanio_cuadricula+y+j)=matriz2[x+i][y+j];
				//cout<<"no salto2"<<endl;
				//system("pause");
			}
		}
	}
}

/*############################
#####################################################################################################################################
###################################################################################################################################
######################################################################################################################################
########################################################################################################################################
*/
void ganar(void){
	cout<<" #####   #####  #       #  #####   ####  #######  #####"<<endl;
	cout<<"#     # #     # ##      # #     # #    #    #    #     "<<endl;
	cout<<"#             # # #     #       # #         #    #     "<<endl;
	cout<<"#             # #  #    #       # #         #    #     "<<endl;
	cout<<"#        #####  #   #   #  #####   ####     #     #####"<<endl;
	cout<<"#  #### #     # #    #  # #     #      #    #    #     "<<endl;
	cout<<"#     # #     # #     # # #     #      #    #    #     "<<endl;
	cout<<"#     # #     # #      ## #     #      #    #    #"<<endl;
	cout<<" #####   ###### #       #  ######  ####     #     #####"<<endl;
}
/*############################
#####################################################################################################################################
###################################################################################################################################
######################################################################################################################################
########################################################################################################################################
*/
//esta es una funcion estetica en caso de perder
void animacion_game_over(void){
	int cant_expl=3;
	int a,b;
	a=45;
	b=15;
	for(int i=0; i<cant_expl; i++){
		//paso 1 
		for(int j=0; j<b; j++){
			cout<<endl;
		}
		cout<<setw(a)<<"##"<<endl;
		cout<<setw(a)<<"##"<<endl;
		system("cls");
		//paso 2
		a--;
		b--;
		for(int j=0; j<b; j++){
			cout<<endl;
		}
		cout<<setw(a)<<"#####"<<endl;
		cout<<setw(a)<<"#   #"<<endl;
		cout<<setw(a)<<"#   #"<<endl;
		cout<<setw(a)<<"#####"<<endl;
		system("cls");
		//paso 3
		a--;
		b--;
		for(int j=0; j<b; j++){
			cout<<endl;
		}
		cout<<setw(a)<<"########"<<endl;
		cout<<setw(a)<<"#      #"<<endl;
		cout<<setw(a)<<"#      #"<<endl;
		cout<<setw(a)<<"#      #"<<endl;
		cout<<setw(a)<<"#      #"<<endl;
		cout<<setw(a)<<"########"<<endl;
		system("cls");
		//paso 4
		a--;
		b--;
		for(int j=0; j<b; j++){
			cout<<endl;
		}
		cout<<setw(a)<<"###########"<<endl;
		cout<<setw(a)<<"#         #"<<endl;
		cout<<setw(a)<<"#         #"<<endl;
		cout<<setw(a)<<"#         #"<<endl;
		cout<<setw(a)<<"#         #"<<endl;
		cout<<setw(a)<<"#         #"<<endl;
		cout<<setw(a)<<"#         #"<<endl;
		cout<<setw(a)<<"###########"<<endl;
		system("cls");
		//paso 5
		a--;
		b--;
		for(int j=0; j<b; j++){
			cout<<endl;
		}
		cout<<setw(a)<<"############"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"############"<<endl;
		system("cls");
		//paso 6
		a--;
		b--;
		for(int j=0; j<b; j++){
			cout<<endl;
		}
		cout<<setw(a)<<"############"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"#          #"<<endl;
		cout<<setw(a)<<"############"<<endl;
		system("cls");
		//paso 5
		a--;
		b--;
		for(int j=0; j<b; j++){
			cout<<endl;
		}
		
		cout<<setw(a)<<"##############"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"#            #"<<endl;
		cout<<setw(a)<<"##############"<<endl;
		system("cls");
		
		a=45;
		b=15;
	}
	system("cls");
}
/*
##########################################################################################
############################################################################################
#################################################################
####################################################################
*/
//esta funcion revisa la cantidad de minas alrededor de una casilla
int revisar_casilla(int matriz[tamanio_cuadricula][tamanio_cuadricula],int x, int y){
	int a=tamanio_cuadricula-1;
	int minas_alrededor = 0;
	for(int i=-1;i<=1;i++){
		for(int j=-1; j<=1; j++){
			if((x+i<0) || (y+j<0) || (x+i>=tamanio_cuadricula) || (y+j>=tamanio_cuadricula) || (i==0 && j==0)){
				//continue;
				//cout<<"salto"<<endl;
				//system("pause");
			}else{
				if(matriz[x+i][y+j]==9){
					minas_alrededor++;
					//cout<<"no salto1"<<endl;
					//system("pause");
				}
				
			}
		}
	}
	return minas_alrededor;
}
/*
##########################################################################################
############################################################################################
#################################################################
####################################################################
*/
void mostrar_reglas(void){
	cout<<"reglas basicas del buscaminas en general:"<<endl;
	cout<<" al revelar una casilla se mostraran el total de minas que hay en las ocho casillas\n alrededor de esta misma\n si la casilla revelada tiene una mina esto significa que han perdido el juego"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"comandos del juego:"<<endl;
	cout<<" primero se debe escoger si se quiere revelar una casilla o colocar una bandera\n (una bandera es una advertencia que pone el jugador si cree que hay una mina en esa casilla)"<<endl;
	cout<<" para esto se oprime f(bandera) o r(revelar) y despues se oprime enter"<<endl;
	cout<<" luego se deciden las coordenadas en x(eje horizontal) y en y(eje veritical) \n que definen la posicion dejando un espacio entre cada coordenada y se oprime un enter"<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"reglas de puntaje"<<endl;
	cout<<" 1. si el jugador gana el puntaje(p) que se mostrara sera la cantidad de movimientos(m)\n realizados multiplicados por 10 (p=m*10)"<<endl;
	cout<<" 2. si el jugador gana el puntaje(p) sera de 5000 menos la cantidad de movimientos(m)\n que se han realizado multiplicados por diez (p=5000-(m*10))"<<endl;
}
/*
##########################################################################################
############################################################################################
#################################################################
####################################################################
*/
void gracias(void){
	cout<<endl<<endl<<endl;
	cout<<setw(20)<<"     ####    ##   ######    ####   ##  ######     #### "<<endl;
	cout<<setw(20)<<"    #    #  #  #        #  #    #  ##        #   #    #"<<endl;
	cout<<setw(20)<<"    #       #           #  #                 #   #     "<<endl;
	cout<<setw(20)<<"    #       #      #####   #       ##   #####    #     "<<endl;
	cout<<setw(20)<<"    #  ##   #     #     #  #       ##  #     #    #### "<<endl;
	cout<<setw(20)<<"    #    #  #     #     #  #       ##  #     #        #"<<endl;
	cout<<setw(20)<<"    #    #  #     #     #  #    #  ##  #     #        #"<<endl;
	cout<<setw(20)<<"     ####   #      ######   ####   ##   ######    #### "<<endl;
	Sleep(3000);
}
/*
##########################################################################################
############################################################################################
#################################################################
####################################################################
*/
//mostrar la matriz como la ve el usuario y la matriz de las minas
void mostrar_matriz(char matriz[tamanio_cuadricula][tamanio_cuadricula]){
	char a;
	int decenas;
	//parte superior del marco
	//esquina del marco
	a=201;
	cout<<setw(22)<<a;
	//inicio borde superior del marco
	a=205;

	cout<<a<<a<<a<<a;
	
	for(int i=0; i< tamanio_cuadricula; i++){
		cout<<a<<a;
	}

	a=187;
	cout<<a;
	cout<<endl;
	//final parte superior del marco
	a=186;
	//impresion coordenadas en x
	if(tamanio_cuadricula>=10){
		cout<<setw(22)<<a;
		cout<<setw(24);
		for(int i=10; i<tamanio_cuadricula;i++){
			decenas=i/10;
			cout<<decenas<<" ";
		}
		cout<<" "<<a;
		cout<<endl;
	}
	//marco lateral
	
	cout<<setw(22);
	cout<<a<<setw(4);
	for(int i=0; i<tamanio_cuadricula; i++){
		cout<<i%10<<" ";
	}
	cout<<" "<<a;
	cout<<endl;
	//parte superior marco interno
	cout<<setw(22)<<a;
	a=201;
	cout<<setw(3)<<a;
	a=205;
	for(int i=0; i<tamanio_cuadricula; i++){
		cout<<a<<a;
	}
	a=187;
	cout<<a;
	a=186;
	cout<<a<<endl;
	//fin parte superior marco interno
	//segunda parte del marco lateral y marco lateral interno
	a=186;
	for(int i =0; i<tamanio_cuadricula; i++){
		cout<<setw(22)<<a<<setw(2);
		cout<<i<<a;
		for(int j=0; j<tamanio_cuadricula; j++){
			cout<<matriz[j][i]<<" ";
		}
		cout<<a<<a;
		cout<<endl;
	}
	//marco inferior interno
	cout<<setw(22)<<a;
	a=200;
	cout<<setw(3)<<a;
	a=205;
	for(int i=0; i<tamanio_cuadricula; i++){
		cout<<a<<a;
	}
	a=188;
	cout<<a;
	a=186;
	cout<<a<<endl;
	//marco inferior externo
	a=200;
	cout<<setw(22)<<a;
	a=205;
	if(tamanio_cuadricula>10){
		cout<<a;
	}
	cout<<a<<a;
	for(int i=0; i< tamanio_cuadricula; i++){
		cout<<a<<a;
	}
	cout<<a;
	if(tamanio_cuadricula<=10){
		cout<<a;
	}
	a=188;
	cout<<a;
}

/*
##########################################################################################
############################################################################################
#################################################################
####################################################################
*/
void mostrar_matrizenteros(int matriz[tamanio_cuadricula][tamanio_cuadricula]){
	for(int i =0; i<tamanio_cuadricula; i++){
		cout<<setw(24);
		for(int j=0; j<tamanio_cuadricula; j++){
			cout<<matriz[j][i]<<" ";
		}
		cout<<endl;
	}
}
void mostrar_matrizpuntajes(string matriz[tamanio_puntajes], int matriz2[tamanio_puntajes]){
	for(int i =0; i<tamanio_puntajes; i++){
		cout<<setw(24);
		cout<<matriz[i]<<setw(10)<<matriz2[i];
		cout<<endl;
	}
}
/*
###########################################
#########################################
#############################################
*/
int main(){
	char flag;//208
	int opcflag;
	//Beep(440,2000);
	//variable para facilitar la escritura del programa
	int a=tamanio_puntajes-1;
	//predefinir un tamaño de consola
	//system("mode con: cols=140 lines=43");
	//variables para las funciones de los puntajes
	int puntaje;
	int movimientos=0;
	string nombre;
	int puntaje_buffer;
	string nombre_buffer;
	int puntajes[tamanio_puntajes];
	string nombres[tamanio_puntajes];
	//srand time para asegurar que la distribucion de las minas sea aleatorio
	srand(time(NULL));
	//variable para volver a la pantalla de inicio
	bool volver=false;
	char bandera;
	//cantminas= tamanio_cuadricula^2*0.15
	int cantidad_minas=60;
	int opcion;
	int minas_alrededor;
	bool jugar=false;
	int x,y;
	int coordx,coordy;
	int matriz_escondida[tamanio_cuadricula][tamanio_cuadricula];
	int arrx[tamanio_cuadricula];
	int arry[tamanio_cuadricula];
	bool ya_existe;
	int casillas_reveladas=0;
	char tablero_minas[tamanio_cuadricula][tamanio_cuadricula];
	char tablero_usuario[tamanio_cuadricula][tamanio_cuadricula];
	char *tablero_usuarioPtr=&tablero_usuario[0][0];
	bool matriz_revelada[tamanio_cuadricula][tamanio_cuadricula];
	bool *matriz_reveladaPtr=&matriz_revelada[0][0];
	//setlocale(LC_ALL, "");
	
	/* ##################################################################
	######################################################################
	######################################################################
	######################################################################
	#######################################################################
	################################################################
	########################################################################
	####################################################################
	*/
	//rellenar el arreglo de los nombres con los mejores puntajes
	for(int i =0; i<tamanio_puntajes; i++){
		nombres[i]="default";
		puntajes[i]=i;
	}
	//cada vez que alguien pierda vuelve a esta pantalla para una nueva partida
	INICIO:
	cout<<"#####  ##  #### #       # #     #  #### #       # ## #####   ##### "<<endl;
	cout<<"#    # ## #     ##      # #     # #     ##      # ## #    # #     #"<<endl;
	cout<<"#    #    #     # #     # #     # #     # #     #    #    # #     #"<<endl;
	cout<<"#    # ## #     #  #    # #     # #     #  #    # ## #    # #     #"<<endl;
	cout<<"#####  ##  #### #   #   # #     #  #### #   #   # ## #    # #     #"<<endl;
	cout<<"#    # ## #     #    #  # #     # #     #    #  # ## #    # #     #"<<endl;
	cout<<"#    # ## #     #     # #  #    # #     #     # # ## #    # #     #"<<endl;
	cout<<"#    # ## #     #      ##   # #   #     #      ## ## #    # #     #"<<endl;
	cout<<"#####  ##  #### #       #    #     #### #       # ## #####   #####"<<endl;
	cout<<"bienvenido a busca minas\n ¿Que quieres hacer?\n 1=jugar\n 2=ver mejores puntajes\n 3=ver reglas\n otro=salir\n";
	cin>>opcion;
	system("cls");
	/*
	########################################################
	#########################################################
	#########################################################
	###############################################
	################################################
	###############################################
	SETUP
	*/
	if(opcion==1){
		jugar=true;
		//rellenar cuadriculas

		for(int i=0; i<tamanio_cuadricula; i++){
			for(int j=0; j<tamanio_cuadricula; j++){
				tablero_minas[i][j]=' ';
				matriz_escondida[i][j]=0;
				tablero_usuario[i][j]='#';
				matriz_revelada[i][j]=true;
			}
		}
		
		for(int i=1; i<=cantidad_minas; i++){
			//comprobar que se generen la cantidad de minas que queremos y que no salgan dos minas en la misma casilla
			do{
				x=rand()%tamanio_cuadricula;
				y=rand()%tamanio_cuadricula;
				for(int j=0; j<tamanio_cuadricula; j++){
					if(x==arrx[j] && y==arry[j]){
						ya_existe=true;
					}else{
						ya_existe=false;
					}
				}
			}while(ya_existe);
			tablero_minas[x][y]='*';
			matriz_escondida[x][y]=9;
		}
		//logica de la cantidad de minas rodeando
		for(int i=0;i<tamanio_cuadricula;i++){
			for(int j=0; j<tamanio_cuadricula; j++){
				if(matriz_escondida[i][j]==9){
					//no se hace nada
				}else{
					minas_alrededor=revisar_casilla(matriz_escondida,i,j);
					matriz_escondida[i][j]=minas_alrededor;
					//emparejar con la matriz del tablero descubierto
					switch(minas_alrededor){
						case 0:{
							tablero_minas[i][j]=' ';
							break;
						}
						case 1:{
							tablero_minas[i][j]='1';
							break;
						}
						case 2:{
							tablero_minas[i][j]='2';
							break;
						}
						case 3:{
							tablero_minas[i][j]='3';
							break;
						}
						case 4:{
							tablero_minas[i][j]='4';
							break;
						}
						case 5:{
							tablero_minas[i][j]='5';
							break;
						}
						case 6:{
							tablero_minas[i][j]='6';
							break;
						}
						case 7:{
							tablero_minas[i][j]='7';
							break;
						}
						case 8:{
							tablero_minas[i][j]='8';
							break;
						}
					}
				}
			}
		}
		cout<<"escoge que bandera te gustaria usar, digita el codigo"<<endl;
		flag=208;
		cout<<flag<<" : 1"<<endl;
		flag=156;
		cout<<flag<<" : 2"<<endl;
		flag=157;
		cout<<flag<<" : 3"<<endl;
		flag=190;
		cout<<flag<<" : 4"<<endl;
		flag=244;
		cout<<flag<<" : 5"<<endl;
		cin>>opcflag;
		bool noseguir=true;
		while(noseguir){
			switch(opcflag){
				case 1:{
					flag=208;
					noseguir=false;
					break;
				}
				case 2:{
					flag=156;
					noseguir=false;
					break;
				}
				case 3:{
					flag=157;
					noseguir=false;
					break;
				}
				case 4:{
					flag=190;
					noseguir=false;
					break;
				}
				case 5:{
					flag=244;
					noseguir=false;
					break;
				}
				default :{
					cout<<"escogiste una opcion invalida vuelva a intentar"<<endl;
					cin>>opcflag;
					noseguir=true;
					break;
				}
			}
		}
		system("cls");
	}else if(opcion==2){
		//ordenar los puntajes de menor a mayor
		//bubblesort
		for(int i=0; i<tamanio_puntajes; i++){
			for(int j=a; j>0;j--){
				if(puntajes[j]>puntajes[j-1]){
					puntaje_buffer=puntajes[j];
					nombre_buffer=nombres[j];
					puntajes[j]=puntajes[j-1];
					nombres[j]=nombres[j-1];
					puntajes[j-1]=puntaje_buffer;
					nombres[j-1]=nombre_buffer;
				}
			}
		}
		mostrar_matrizpuntajes(nombres,puntajes);
		cout<<"quieres volver \n 1=si otro=salir \n";
		cin>>volver;
		if(volver){
			system("cls");
			goto INICIO;
		}else{
			gracias();
			return 0;
		}
	}else if(opcion==3){
		cout<<"reglas";
		mostrar_reglas();
		cout<<endl<<endl<<endl;
		cout<<"quieres volver 1=si otro=salir"<<endl;
		cin>>volver;
		if(volver){
			system("cls");
			goto INICIO;
		}else{
			gracias();
			return 0;
		}
	}else{
		gracias();
		return 0;
	}
	
	
	
	/*
	######################################################################################3
	#########################################################################################
	#####################################################################################3
	########################################################################################
	########################################################################################
	*/
	
	
	// CICLO PRINCIPAL DEL JUEGO
	while (jugar){
		cout<<"\n si quieres colocar una bandera escribe f y oprime enter, si quieres revelar una casilla escribe r y oprime enter\n las banderas son representedas con el simbolo "<<flag<<endl;
		mostrar_matriz(tablero_usuario);
		cout<<endl;
		//esta es la matriz trampa
		//mostrar_matriz(tablero_minas);
		cout<<endl;
		//esta es trampa pero mas dificil
		//mostrar_matrizenteros(matriz_escondida);
		cout<<"ingrese las coordenadas del punto que quiere revisar primero ingrese la coordenada de las columnas(horizontal), presione espacio o enter\n luego ingrese la coordenada de filas(vertical), luego presione enter"<<endl;
		cout<<"eliga bandera (f) o revelar (r)";
		cin>>bandera;
		while(!(bandera=='f' || bandera=='F' || bandera=='R' || bandera=='r')){
			cout<<"letra incorrecta vuelve a intentar"<<endl;
			cin>>bandera;
		}
		cout<<"COORD X: ";
		cin>>coordx;
		cout<<"COORD Y: ";
		cin>>coordy;
		//!((tablero_usuario[coordx][coordy]==tablero_minas[coordx][coordy]) || (tablero_usuario[coordx][coordy]==flag) || (coordx>=0 && coordx<tamanio_cuadricula && coordy>=0 && coordy<tamanio_cuadricula))
		while(coordx>=tamanio_cuadricula || coordy>=tamanio_cuadricula || coordx<0 || coordy<0 || (tablero_usuario[coordx][coordy]==tablero_minas[coordx][coordy]) || (tablero_usuario[coordx][coordy]==flag)){
			if((bandera=='f' || bandera=='F') && (tablero_usuario[coordx][coordy]==flag)){
				break;
			}
			cout<<"esta coordenada no es valida, talvez exediste los limites del tablero o escogiste una mina ya revelada \no escogiste una mina con una bandera \nINTENTA OTRA COORDENADA"<<endl;
			cout<<"COORD X: ";
			cin>>coordx;
			cout<<"COORD Y: ";
			cin>>coordy;
		}
		SIGUIENTE:
		//codigo que coloca una bandera
		if(bandera=='f' || bandera=='F'){
			if(tablero_usuario[coordx][coordy]==flag){
				tablero_usuario[coordx][coordy]='#';
			}else{
				tablero_usuario[coordx][coordy]=flag;
			}
			system("cls");
			continue;
		}else if(bandera=='r' || bandera=='R'){
			if(matriz_escondida[coordx][coordy]==9){
				animacion_game_over();
				system("cls");
				jugar==false;
				mostrar_matriz(tablero_minas);
				cout<<endl;
				cout<<" #####  ######  ##########   #####        #####  #     #  #### #####"<<endl;
				cout<<"#     #       # #    #    # #            #     # #     # #     #   #"<<endl;
				cout<<"#             # #    #    # #            #     # #     # #     #   #"<<endl;
				cout<<"#             # #    #    # #            #     # #     # #     #    "<<endl;
				cout<<"#        #####  #    #    #  #####       #     # #     #  #### #    "<<endl;
				cout<<"#  #### #     # #    #    # #            #     # #     # #     #    "<<endl;
				cout<<"#     # #     # #    #    # #            #     #  #   #  #     #    "<<endl;
				cout<<"#     # #     # #    #    # #            #     #   # #   #     #    "<<endl;
				cout<<" ######  ###### #    #    #  #####        #####     #     #### #    "<<endl<<endl<<endl;
				cout<<"en la coordenada "<<coordx<<","<<coordy<<" habia una mina"<<endl;
				//guaardar el puntaje si es del top
				puntaje=movimientos*10;
				cout<<"tu puntaje fue "<<puntaje<<endl;
				cout<<"ingresa tu nombre sin espacios ni caracteres especiales"<<endl;
				cin>>nombre;
				//funcian que revisa si entra en el top
				
				if(puntaje>=puntajes[a]){
					puntajes[a]=puntaje;
					nombres[a]=nombre;
					cout<<"tu puntaje si alcanzo el top, ve a la seccion de ranking para mas informacion"<<endl;
				}else{
					cout<<"tu puntaje no alcanzo el top"<<endl;
				}
				//para que los puntajes no se acumulen
				puntaje=0;
				movimientos=0;
				cout<<"\n quieres volver a intentarlo\n 1=si otro=salir del juego"<<endl;
				cin>>volver;
				if(volver){
					system("cls");
					goto INICIO;
				}else{
					gracias();
					return 0;
				}
			}else if(matriz_escondida[coordx][coordy]>0 && matriz_escondida[coordx][coordy]<9){
				tablero_usuario[coordx][coordy]=tablero_minas[coordx][coordy];
				movimientos++;
			}
			
			else if(matriz_escondida[coordx][coordy]==0){
				movimientos++;
				//tablero_usuario[coordx][coordy]=' ';
				revelar_casilla(tablero_usuarioPtr, matriz_reveladaPtr, tablero_minas, matriz_escondida, coordx, coordy);
			}
		}
		//revisar si ya gano
		int casillas_encontradas=0;
		for(int i=0; i< tamanio_cuadricula; i++){
			for(int j=0; j<tamanio_cuadricula; j++){
				if(tablero_usuario[i][j]==tablero_minas[i][j] && (tablero_usuario[i][j]!='#')){
					casillas_encontradas++;
				}
			}
		}
		if(casillas_encontradas==((pow(tamanio_cuadricula,2))-cantidad_minas)){
			puntaje=5000-(movimientos*10);
			ganar();
			mostrar_matriz(tablero_minas);
			cout<<"tu puntaje fue "<<puntaje<<endl;
			cout<<"ingresa tu nombre sin espacios ni caracteres especiales"<<endl;
			cin>>nombre;
			//funcian que revisa si entra en el top
			if(puntaje>=puntajes[a]){
				puntajes[a]=puntaje;
				nombres[a]=nombre;
				cout<<"tu puntaje si alcanzo el top, ve a la seccion de ranking para mas informacion"<<endl;
			}else{
				cout<<"tu puntaje no alcanzo el top"<<endl;
			}
			//para que los puntajes no se acumulen
			puntaje=0;
			movimientos=0;
			cout<<"\n quieres volver a jugar?\n 1=si otro=salir del juego"<<endl;
			cin>>volver;
			if(volver){
				system("cls");
				goto INICIO;
			}else{
				gracias();
				return 0;
			}
		}
		system("cls");
	}
	return 0;
}
