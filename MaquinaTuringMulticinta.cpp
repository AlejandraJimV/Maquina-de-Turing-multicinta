/*
*Elaborado por Alejandra Jiménez Venegas 
*Teoría de Autómatas
*Este código es un ejemplo de cómo implementar una máquina de Turing multicinta en C para realizar 
la suma de números binarios. La combinación de lógica de programación
 y gráficos permite visualizar el proceso de la máquina de Turing de manera interactiva.*/ 

#include<stdio.h>
#include<conio.h>
#include <graphics.h>
#include <windows.h>
#include <math.h>

#define color SetConsoleTextAttribute

void gotoxy(int x,int y);
void pantalla2();
void grafo();
void suma();
int q0(int cabezal,char cadena1[],char cadena2[],char cadena3[],char cadena4[]);
void bienvenida();
void mostrarMenu(); 
void q1(int cabezal,char cadena1[],char cadena2[],char cadena3[],char cadena4[],int acarreo);
void cuadros(int p,int q ,int c, int f);
void q2(int cabezal,char cadena1[],char cadena2[],char cadena3[],char cadena4[],int acarreo);
int margen(int x1, int y1, int x2, int y2);
void borrar();
void encabezado();

 int main(){
	int opc;
	bienvenida();
	borrar();
		do{
		mostrarMenu();
	    gotoxy(10, 2);
		scanf("%d%*c",&opc);
		system("cls");
		margen(1,1,115,29);
		switch(opc){
			case 1:
	    		//Diagrama y transiciones
	    		pantalla2();
				initwindow(1000, 600);
				grafo();
				borrar();
	    		closegraph();
	    		break;
	    	case 2: 
				//Realizar suma
				suma();
	    		borrar();
	    		break;
	    	case 3:
	    		gotoxy(40, 13);
	    		printf("Saliendo del programa....");
	    		Sleep(500);
	    		system("cls");
	    		return 0;
		}
		system("cls");
	}while(opc!=3); 
 }  

 void borrar()
 {
 	gotoxy(60, 29);
 	system("pause");
 	system("cls");
 }

void mostrarMenu() {
    margen(1, 1, 100, 25);
    margen(49, 1, 67, 3);
    gotoxy(50, 2);
    printf("1. Diagrama");
    margen(69, 1, 88, 3);
    gotoxy(70, 2);
    printf("2. Ingresar datos");
    margen(90, 1, 100, 3);
    gotoxy(90, 2);
    printf("3. Salir");
    margen(1, 1, 47, 3);
    gotoxy(2, 2);
    printf("Opcion:");
}

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 

void cuadros(int p,int q ,int c, int f){
	int i;
	int x;
	
	for(x=0; x<q; x++){
		gotoxy(c,f);
		printf("%c",218);  
		gotoxy(c,f+(x*2)+1); 
		printf("%c",179);
		gotoxy(c,f+(x*2)+2); 
		printf("%c",195);
		
		for(i=0; i<p-1; i++){
			gotoxy(c+((i+1)*4),f);
			printf("%c",194);
			gotoxy(c+(i*4)+1,f+(x*2));
			printf("%c%c%c",196,196,196);
			gotoxy(c+(i*4)+1,f+(x*2)+1);
			printf("   %c",179);
			gotoxy(c+(i*4)+1,f+(x*2)+2);
			printf("%c%c%c",196,196,196,197);
			gotoxy(c+((i+1)*4),f+(x*2)+2);
			printf("%c",197);
			}
			
		gotoxy(c+(i*4)+1,f); 
		printf("%c%c%c%c",196,196,196,191);
		gotoxy(c+(i*4)+1,f+(x*2)+1);
		printf("   %c",179);
		gotoxy(c+(i*4)+1,f+(x*2)+2); 
		printf("%c%c%c%c",196,196,196,180);
	}
	gotoxy(c,f+(x*2)); 
	printf("%c",192);
	gotoxy(c+(i*4)+4,f+(x*2)); 
	printf("%c",217);
	
	for(i=0; i<p-1; i++){
		gotoxy(c+((i+1)*4),f+(x*2));
		printf("%c",193);
		}
}

void pantalla2(){
	int a=35;
	margen(30, 11, 80, 27);
	gotoxy(49,3);printf("DEFINICION FORMAL Y");
	gotoxy(45,4);printf("DIAGRAMA DE TRANSICIONES:");
	
	gotoxy(30,6);printf("Q=  {q0,q1,q2,q3}");
	gotoxy(30,7);printf("%c=  {1, 0}",156);
	gotoxy(30,8);printf("r=  {1, 0, _}");
	gotoxy(70,6);printf("F=  {q3}");
	gotoxy(70,7);printf("s=  {q0}");
	gotoxy(70,8); printf("%c= simbolo en blanco", 231);
//Transiciones 
	
//q0	
	gotoxy(a,12);printf("S(q0,(0,0,_,_))->(q0,(0,0,_,_),(R,R,R,S))");
	gotoxy(a,13);printf("S(q0,(0,1,_,_))->(q0,(0,1,_,_),(R,R,R,S))");
    gotoxy(a,14);printf("S(q0,(1,0,_,_))->(q0,(1,0,_,_),(R,R,R,S))");
    gotoxy(a,15);printf("S(q0,(1,1,_,_))->(q0,(1,1,_,_),(R,R,R,S))");
    gotoxy(a,16);printf("S(q0,(_,_,_,_))->(q1,(_,_,_,_),(L,L,L,S))");

//q1
    gotoxy(a,17);printf("S(q1,(0,0,_,_))->(q1,(0,0,0,_),(L,L,L,S))");
    gotoxy(a,18);printf("S(q1,(0,1,_,_))->(q1,(0,1,1,_),(L,L,L,S))");
    gotoxy(a,19);printf("S(q1,(1,0,_,_))->(q1,(1,0,1,_),(L,L,L,S))");
    gotoxy(a,20);printf("S(q1,(1,1,_,_))->(q2,(1,1,0,1),(L,L,L,S))");
    gotoxy(a,21);printf("S(q1,(_,_,_,_))->(q3,(_,_,_,_),(S,S,S,S))");
    
//q2
    gotoxy(a,22);printf("S(q2,(0,0,_,1))->(q1,(0,0,1,_),(L,L,L,S))");
    gotoxy(a,23);printf("S(q2,(0,1,_,1))->(q2,(0,1,0,1),(L,L,L,S))");
    gotoxy(a,24);printf("S(q2,(1,0,_,1))->(q2,(1,0,0,1),(L,L,L,S))");
    gotoxy(a,25);printf("S(q2,(1,1,_,1))->(q2,(1,1,1,1),(L,L,L,S))");
    gotoxy(a,26);printf("S(q2,(_,_,_,1))->(q3,(_,_,1,_),(S,S,L,S))");

    borrar();
}

void grafo(){
	//circulos de estados 
	circle(200,150,25); //q0
	circle(600,150,25); //q1
	circle(600,500,25); //q2
	circle(200,500,25); //q3
	circle(200,500,20); //q3 doble
	
	//Estados
	outtextxy(195, 145,const_cast<char*>("q0"));
	outtextxy(595, 145,const_cast<char*> ("q1"));
	outtextxy(595, 495, const_cast<char*>("q2"));
	outtextxy(195, 495, const_cast<char*>("q3"));

	//Retornos
	ellipse(200, 130, 0, 180, 20, 30); //q0
	ellipse(600, 130, 0, 180, 20, 30); //q1
	ellipse(600, 480, 0, 180, 20, 30); //q2

	//Aristas
	line(225,150,575,150);//q0-q1
	line(590,175,590,475);//q1-q2
	line(610,175,610,475);//q2-q1
	line(590,170,200,475);//q1-q3
	line(575,500,225,500);//q2-q3

	//Flecha para q0
	line(165,155,170,150);//m1
	line(165,145,170,150);//m2
	line(150,150,170,150); //medio
	
	//Flechas
	//q0-q1
	line(565,155,575,150);//m1
	line(565,145,575,150);//m2
	
	//q1-q2
	line(585,470,590,475);//m1
	line(590,475,595,470);//m2
	
	//q2-q1
	line(605,180,610,175);//m1
	line(610,175,615,180);//m2
	
	//q1-q3
	line(200,470,205,475);//m1
	line(205,475,210,472);//m2
	
	//q0-q1
	line(225,500,235,495);//m1
	line(225,500,235,505);//m2

	//Texto de transiciones
	//q0
	outtextxy(100,10, const_cast<char*>("0;0,R | 0;0;R | _;_;R | _;_;S")); //q0
	outtextxy(100,30, const_cast<char*>("0;0,R | 1;1;R | _;_;R | _;_;S")); //q0
	outtextxy(100,50, const_cast<char*>("1;1,R | 0;0;R | _;_;R | _;_;S")); //q0
	outtextxy(100,70, const_cast<char*>("1;1,R | 1;1;R | _;_;R | _;_;S")); //q0
	outtextxy(300,125, const_cast<char*>("_;_;L | _;_;L | _;_;L | _;_;S")); //q0-q1
	
	//q1
	outtextxy(500,30, const_cast<char*>("0;0,L | 0;0;L | _;0;L | _;_;S")); //q1
	outtextxy(500,50, const_cast<char*>("0;0,L | 1;1;L | _;1;L | _;_;S")); //q1
	outtextxy(500,70, const_cast<char*>("1;1,L | 0;0;L | _;1;L | _;_;S")); //q1
	outtextxy(420,350, const_cast<char*>("1;1,L | 1;1;L | _;0;L | _;1;S")); //q1- q2
	outtextxy(200,300, const_cast<char*>("_;_;S | _;_;S | _;_;S | _;_;S")); //q1-q3
	
	//q2
	outtextxy(620,350, const_cast<char*>("0;0,L | 0;0;L | _;1;L | 1;_;S")); //q2-q1
	outtextxy(650,480, const_cast<char*>("0;0,L | 1;1;L | _;0;L | 1;1;S")); //q2
	outtextxy(650,500, const_cast<char*>("1;1,L | 0;0;L | _;0;L | 1;1;S")); //q2
	outtextxy(650,520, const_cast<char*>("1;1,L | 1;1;L | _;1;L | 1;1;S")); //q2
	outtextxy(300,470, const_cast<char*>("_;_;S | _;_;S | _;1;L | 1;_;S")); //q2-q3
}
void encabezado()
{
	margen(30, 2, 70, 4);
	gotoxy(40, 3);
	printf("SUMA DE BINARIOS");
}
void suma(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	encabezado();
	int cabezal=1,i,j,bandera;
    char cadena1[20], cadena2[20], cadena3[20], cadena4[20], aux_1[20],aux_2[20];
    do{
    	i=0;
    	
    	cadena3[1]='\0';
    	cadena4[1]='\0';
    	bandera=0;
    	gotoxy(80,8);printf("Cadena 1: ");
    	gets(aux_1);
    	gotoxy(80,9);printf("Cadena 2: ");
    	gets(aux_2);
    	cadena1[0]='x';
		cadena2[0]='x';
		for(i=0; aux_1[i]!='\0'; i++){
			cadena1[i+1]=aux_1[i];
			cadena2[i+1]=aux_2[i];
		}
		cadena1[i+1]='\0';
		cadena2[i+1]='\0';
		
		for(i=0; i<4; i++){
			cuadros(12,1,20,7+(i*4));
			for(j=0; j<12; j++){
				gotoxy(22+(j*4),8+(i*4));printf("%c",231);// simbolo en blanco
			}		
		}
		gotoxy(2, 8);
		printf("Cadena 1 ->");
		gotoxy(2, 12);
		printf("Cadena 2 ->");
		gotoxy(2, 16);
		printf("Resultado ->");
		gotoxy(2, 20);
		printf("Acarreo ->");
		
		for(i=0; cadena1[i]!='\0'; i++){
			gotoxy(26+((i+1)*4),8);printf("%c",aux_1[i]);//cadena 1
		}
		j=2;
		for(i=0; cadena2[i]!='\0'; i++){
			gotoxy(26+((i+1)*4),8+4);printf("%c",aux_2[i]);//cadena2
		}
		color(hConsole, 11);
		gotoxy(30,10); printf("%c",94);
		gotoxy(30,10+4); printf("%c",94);
		gotoxy(30,10+8); printf("%c",94);
		gotoxy(30,10+12); printf("%c",94);//cabezal
		color(hConsole, 7);
		gotoxy(80, 15); printf("Estado actual -> ");
		bandera=q0(cabezal,cadena1,cadena2,cadena3,cadena4);
	}while(bandera!=0);
}

int q0(int cabezal,char cadena1[],char cadena2[],char cadena3[],char cadena4[]){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int bandera,acarreo;
	int a=26, b=22;
	do{
		color(hConsole, 11);
		gotoxy(97,15); printf("q0" );
		color(hConsole, 7);
		Sleep(1500);
		bandera=0;
		if(cadena1[cabezal]=='0' && cadena2[cabezal] == '0' && cadena3[cabezal]=='\0' && cadena4[cabezal]=='\0'){
			cadena3[cabezal+1]='\0';
			cadena4[cabezal+1]='\0';
			
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			gotoxy(b+(cabezal*4),10+12); printf(" ");
			cabezal++;
			//Indicador
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			gotoxy(b+(cabezal*4),10+12); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}
		else if(cadena1[cabezal]=='0' && cadena2[cabezal] == '1' && cadena3[cabezal]=='\0' && cadena4[cabezal]=='\0'){
			cadena3[cabezal+1]='\0';
			cadena4[cabezal+1]='\0';
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			gotoxy(b+(cabezal*4),10+12); printf(" ");
			cabezal++;
			color(hConsole, 11);
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			gotoxy(b+(cabezal*4),10+12); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}
		else if(cadena1[cabezal]=='1' && cadena2[cabezal] == '0' && cadena3[cabezal]=='\0' && cadena4[cabezal]=='\0'){
			cadena3[cabezal+1]='\0';
			cadena4[cabezal+1]='\0';
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			gotoxy(b+(cabezal*4),10+12); printf(" ");
			cabezal++;
			//Indicador
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			gotoxy(b+(cabezal*4),10+12); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}
		else if(cadena1[cabezal]=='1' && cadena2[cabezal] == '1' && cadena3[cabezal]=='\0' && cadena4[cabezal]=='\0'){
			cadena3[cabezal+1]='\0';
			cadena4[cabezal+1]='\0';
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			gotoxy(b+(cabezal*4),10+12); printf(" ");
			cabezal++;
			//Indicador
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			gotoxy(b+(cabezal*4),10+12); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}else if(cadena1[cabezal]=='\0' && cadena2[cabezal] == '\0' && cadena3[cabezal]=='\0' && cadena4[cabezal]=='\0'){
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			acarreo=cabezal;
			cabezal--;
			//Indicador
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			q1(cabezal,cadena1,cadena2,cadena3,cadena4,acarreo);
		}
		else{
			//No es cadena binaria
			color(hConsole, 11);
			gotoxy(80,20); printf("Cadena invalida");
		}
	}while(bandera!=0);
	return 0;
}


void q1(int cabezal,char cadena1[],char cadena2[],char cadena3[],char cadena4[],int acarreo){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int bandera;
	int a=26, b=22;
	do{
		Sleep(1500);
		color(hConsole, 11);
		gotoxy(97,15); printf("q1");
		color(hConsole, 7);
		bandera=0;
		if(cadena1[cabezal]=='0' && cadena2[cabezal] == '0' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='\0'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='0';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			color(hConsole, 11);
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
			
		}
		else if(cadena1[cabezal]=='0' && cadena2[cabezal] == '1' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='\0'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='1';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			color(hConsole, 11);
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}
		else if(cadena1[cabezal]=='1' && cadena2[cabezal] == '0' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='\0'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='1';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}
		else if(cadena1[cabezal]=='1' && cadena2[cabezal] == '1' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='\0'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='0';
			cadena4[acarreo]='1';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(b+(acarreo*4),8+12);printf("%c",cadena4[acarreo]);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			color(hConsole, 11);
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			q2(cabezal,cadena1,cadena2,cadena3,cadena4,acarreo);
		}else if(cadena1[cabezal]=='x' && cadena2[cabezal] == 'x' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='\0'){
			color(hConsole, 11);
			gotoxy(80, 20);
			printf("Suma terminada");
			gotoxy(97,15);
			printf("q3");
			color(hConsole, 7);
		}
	}while(bandera!=0);
}

void bienvenida() {
    int opcion;
    margen(1, 1, 100, 25);
    margen(29, 9, 70, 11);
    margen(44, 5, 55, 7);

    gotoxy(30, 10);
    printf("MAQUINA DE TURING PARA SUMA DE BINARIOS");
    gotoxy(45, 6);
    printf("BIENVENIDO");
    
    margen(19, 14, 82, 18);
    gotoxy(25, 15);
    printf("Una maquina de Turing es un modelo computacional que ");
    gotoxy(23, 16);
    printf("realiza una lectura/escritura de manera automatica sobre ");
    gotoxy(20, 17);
    printf("una entrada llamada cinta, generando una salida en esta misma.");
}

void q2(int cabezal,char cadena1[],char cadena2[],char cadena3[],char cadena4[],int acarreo){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int bandera;
	int a=26, b=22;
	do{
		color(hConsole, 11);
		gotoxy(97,15); printf("q2");
		color(hConsole, 7);
		Sleep(1500);
		bandera=0;
		if(cadena1[cabezal]=='0' && cadena2[cabezal] == '0' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='1'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='1';
			cadena4[acarreo]='\0';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			color(hConsole, 7);
			gotoxy(b+(acarreo*4),8+12);printf("%c",231);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			//Indicador
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			q1(cabezal,cadena1,cadena2,cadena3,cadena4,acarreo);
			bandera=1;
			
		}
		else if(cadena1[cabezal]=='0' && cadena2[cabezal] == '1' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='1'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='0';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}
		else if(cadena1[cabezal]=='1' && cadena2[cabezal] == '0' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='1'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='0';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			bandera=1;
		}
		else if(cadena1[cabezal]=='1' && cadena2[cabezal] == '1' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='1'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='1';
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(a+(cabezal*4),10); printf(" ");
			gotoxy(a+(cabezal*4),10+4); printf(" ");
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			//Indicador
			gotoxy(a+(cabezal*4),10); printf("%c",94);
			gotoxy(a+(cabezal*4),10+4); printf("%c",94);
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 7);
			q2(cabezal,cadena1,cadena2,cadena3,cadena4,acarreo);
		}else if(cadena1[cabezal]=='x' && cadena2[cabezal] == 'x' && cadena3[cabezal]=='\0' && cadena4[acarreo]=='1'){
			cadena3[cabezal-1]='\0';
			cadena3[cabezal]='1';
			cadena4[acarreo]='\0';
			gotoxy(b+(acarreo*4),8+12);printf("%c",231);
			color(hConsole, 11);
			gotoxy(a+(cabezal*4),8+8);printf("%c",cadena3[cabezal]);
			gotoxy(a+(cabezal*4),10+8); printf(" ");
			cabezal--;
			gotoxy(a+(cabezal*4),10+8); printf("%c",94);
			color(hConsole, 11);
			gotoxy(97,15);
			printf("q3");
			gotoxy(80, 20);
			printf("Suma terminada");
			color(hConsole, 7);
		}
	}while(bandera!=0);
}

int margen(int a, int b, int c, int d) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 13);
    int j, k, i;
    j = a;
    gotoxy(a - 1, b);
    printf("%c", 201);
    gotoxy(a - 1, d);
    printf("%c", 200);
    for (a; a <= c; a++) {
        gotoxy(a, b);
        printf("%c", 205);
        gotoxy(a, d);
        printf("%c", 205);
    }
    gotoxy(a, b);
    printf("%c", 187);
    gotoxy(a, d);
    printf("%c", 188);
    k = b + 1;
    for (k; k <= (d - 1); k++) {
        gotoxy(j - 1, k);
        printf("%c", 186);
        gotoxy(a, k);
        printf("%c", 186);
    }
    color(hConsole, 7);
}
