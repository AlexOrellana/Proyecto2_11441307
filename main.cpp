#include "luchadores.h"
#include "mago.h"
#include "melee.h"
#include "priest.h"
#include "tirador.h"
#include "espadachin.h"

#include <curses.h>
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h> 
#include <vector>

using namespace std;

int menu_JuegoNuevo();
int menu_principal();
int menu_tienda();
int menu_atacar(int);
void dibujar_clase(int,int,int);
void dibujo_mago(int,int);
void dibujo_melee(int,int);
void dibujo_priest(int,int);
void dibujo_tirador(int,int);
void dibujo_espadachin(int,int);

int main(int argc, char* argv[]){

	initscr();
	(void)echo();
	srand(time(NULL));
	string name;
	char nombre[1000]; 
	char* temp= new char[200];//pasar string a char
	Luchadores* player;
	char cargar;
	int opcion;
	int opc;
	move(15,50);
	printw("Desea cargar[s/n]:       ");
	refresh();
	cargar = getch();
	if(cargar=='s' || cargar=='S'){
		int dinero,vida;
		///////////cargar
		ifstream traer("dinero.txt");
		while(!traer.eof()){
			traer>>dinero;
		}
		traer.close();

		///////////cargar
		ifstream traer2("vida.txt");
		while(!traer.eof()){
			traer>>vida;
		}
		traer2.close();

		///////////cargar
		ifstream traer3("nombre.txt");
		while(!traer.eof()){
			traer>>name;
		}
		traer3.close();

		///////////cargar
		ifstream traer4("opc.txt");
		while(!traer.eof()){
			traer>>opc;
		}
		traer4.close();


		Mago mago(vida,0,dinero,"BOT",10);
		Melee melee(vida,0,dinero,"BOT");
		Priest priest(vida,0,dinero,"BOT");
		Tirador tirador(vida,0,dinero,"BOT",30);
		Espadachin espadachin(vida,0,dinero,"BOT");
		//crear player
		if (opc==1)
		{
			move(5,5);
			printw("Elejiste mago");
			dibujo_mago(7,5);
			getch();
			mago.Cambiar_nombre(name);
			player=&mago;
		}else if (opc==2)
		{
			move(5,5);
			printw("Elejiste melee");
			dibujo_melee(7,5);
			getch();
			melee.Cambiar_nombre(name);
			player=&melee;	
		}else if (opc==3)
		{
			move(5,5);
			printw("Elejiste priest");
			dibujo_priest(7,5);
			getch();
			priest.Cambiar_nombre(name);
			player=&priest;
		}else if (opc==4)
		{
			move(5,5);
			printw("Elejiste tirador");
			dibujo_tirador(7,5);
			getch();
			tirador.Cambiar_nombre(name);
			player=&tirador;	
		}else if (opc==5)
		{
			move(5,5);
			printw("Elejiste espadachin");
			dibujo_espadachin(7,5);
			getch();
			espadachin.Cambiar_nombre(name);
			player=&espadachin;
		}
	}else{

		Mago mago(500,0,500,"BOT",10);
		Melee melee(500,0,500,"BOT");
		Priest priest(500,0,500,"BOT");
		Tirador tirador(500,0,500,"BOT",30);
		Espadachin espadachin(500,0,500,"BOT");

		opc=menu_JuegoNuevo();

		move(15,50);
		addstr("Ingrese nombre: ");
		refresh();
		getnstr(nombre, sizeof(nombre) - 1);
		refresh();
		name = string(nombre);
		refresh();
		clear();

		//crear player
		if (opc==1)
		{
			move(5,5);
			printw("Elejiste mago");
			dibujo_mago(7,5);
			getch();
			mago.Cambiar_nombre(name);
			player=&mago;
		}else if (opc==2)
		{
			move(5,5);
			printw("Elejiste melee");
			dibujo_melee(7,5);
			getch();
			melee.Cambiar_nombre(name);
			player=&melee;	
		}else if (opc==3)
		{
			move(5,5);
			printw("Elejiste priest");
			dibujo_priest(7,5);
			getch();
			priest.Cambiar_nombre(name);
			player=&priest;
		}else if (opc==4)
		{
			move(5,5);
			printw("Elejiste tirador");
			dibujo_tirador(7,5);
			getch();
			tirador.Cambiar_nombre(name);
			player=&tirador;	
		}else if (opc==5)
		{
			move(5,5);
			printw("Elejiste espadachin");
			dibujo_espadachin(7,5);
			getch();
			espadachin.Cambiar_nombre(name);
			player=&espadachin;
		}

		//interface
		while(opcion!=4){
			opcion=menu_principal();
			if (opcion==1)//pelear
			{
				//dibujar player
				move(29,5);	
				printw("TU");
				move(30,5);	
				strcpy(temp, player->toString().c_str());
				printw(temp);
				dibujar_clase(opc,32,5);

				//elejir y dibujar enemigo
				Mago BOT1(500,0,500,"BOT",10);
				Melee BOT2(500,0,500,"BOT");
				Priest BOT3(500,0,500,"BOT");
				Tirador BOT4(500,0,500,"BOT",30);
				Espadachin BOT5(500,0,500,"BOT");

				int  enemy=rand()%5+1;

				move(4,80);	
				printw("ENEMIGO");
				if (enemy==1)
				{
					//dibujar enemigo
					move(5,80);	
					strcpy(temp, BOT1.toString().c_str());
					printw(temp);
					dibujar_clase(1,7,80);

					while(BOT1.GetVida()>0 && player->GetVida()>0){
						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT1.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);

						int  enemy_ataque=rand()%4+1;

						BOT1.herir(player->ataquar(menu_atacar(opc)));
						player->herir(BOT1.ataquar(enemy_ataque));

						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT1.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);
					}	

					if (BOT1.GetVida()<player->GetVida())
					{
						clear();
						move(15,30);
						printw("Ganaste [cada ves que ganas te dan dinero]--recuerda ir a la tienda a curarte");
						player->WinMoney();
						getch();
					}else{
						clear();
						move(15,30);
						printw("GAME OVER");
						opcion=4;
						getch();
					}
				}else if (enemy==2)
				{
					move(5,80);	
					strcpy(temp, BOT2.toString().c_str());
					printw(temp);
					dibujar_clase(2,7,80);

					while(BOT2.GetVida()>0 && player->GetVida()>0){
						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT2.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);

						int  enemy_ataque=rand()%4+1;

						BOT2.herir(player->ataquar(menu_atacar(opc)));
						player->herir(BOT2.ataquar(enemy_ataque));

						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT2.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);
					}
					if (BOT2.GetVida()<player->GetVida())
					{
						clear();
						move(15,30);
						printw("Ganaste [cada ves que ganas te dan dinero]--recuerda ir a la tienda a curarte");
						player->WinMoney();
						getch();
					}else{
						clear();
						move(15,30);
						printw("GAME OVER");
						opcion=4;
						getch();
					}
				}else if (enemy==3)
				{
					move(5,80);	
					strcpy(temp, BOT3.toString().c_str());
					printw(temp);
					dibujar_clase(3,7,80);

					while(BOT3.GetVida()>0 && player->GetVida()>0){
						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT3.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);

						int  enemy_ataque=rand()%4+1;

						BOT3.herir(player->ataquar(menu_atacar(opc)));
						player->herir(BOT3.ataquar(enemy_ataque));

						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT3.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);
					}
					if (BOT3.GetVida()<player->GetVida())
					{
						clear();
						move(15,30);
						printw("Ganaste [cada ves que ganas te dan dinero]--recuerda ir a la tienda a curarte");
						player->WinMoney();
						getch();
					}else{
						clear();
						move(15,30);
						printw("GAME OVER");
						opcion=4;
						getch();
					}
				}else if (enemy==4)
				{
					move(5,80);	
					strcpy(temp, BOT4.toString().c_str());
					printw(temp);
					dibujar_clase(4,7,80);

					while(BOT4.GetVida()>0 && player->GetVida()>0){
						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT4.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);

						int  enemy_ataque=rand()%4+1;

						BOT4.herir(player->ataquar(menu_atacar(opc)));
						player->herir(BOT4.ataquar(enemy_ataque));

						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT4.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);
					}
					if (BOT4.GetVida()<player->GetVida())
					{
						clear();
						move(15,30);
						printw("Ganaste [cada ves que ganas te dan dinero]--recuerda ir a la tienda a curarte");
						player->WinMoney();
						getch();
					}else{
						clear();
						move(15,30);
						printw("GAME OVER");
						opcion=4;
						getch();
					}
				}else if (enemy==5)
				{
					move(5,80);	
					strcpy(temp, BOT5.toString().c_str());
					printw(temp);
					dibujar_clase(5,7,80);

					while(BOT5.GetVida()>0 && player->GetVida()>0){
						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT5.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);

						int  enemy_ataque=rand()%4+1;

						BOT5.herir(player->ataquar(menu_atacar(opc)));
						player->herir(BOT5.ataquar(enemy_ataque));

						clear();
						//dibujar player
						move(29,5);	
						printw("TU");
						move(30,5);	
						strcpy(temp, player->toString().c_str());
						printw(temp);
						dibujar_clase(opc,32,5);
						//dibujar enemy
						move(5,80);	
						strcpy(temp, BOT5.toString().c_str());
						printw(temp);
						dibujar_clase(1,7,80);
					}
					if (BOT5.GetVida()<player->GetVida())
					{
						clear();
						move(15,30);
						printw("Ganaste [cada ves que ganas te dan dinero]--recuerda ir a la tienda a curarte");
						player->WinMoney();
						getch();
					}else{
						clear();
						move(15,30);
						printw("GAME OVER");
						opcion=4;
						getch();
					}
				}
				getch();
			}else if (opcion==2)//tienda
			{
				int opcion_tienda=0;
				while(opcion_tienda!=3){
					opcion_tienda=menu_tienda();
					if (opcion_tienda==1 && player->GetMoney()>=200)
					{
						player->UseMoney(200);
						for (int i = 0; i < 50; ++i)
						{
							player->LevelUp(2);
						}
					}else if (opcion_tienda==2 && player->GetMoney()>=300)
					{
						player->UseMoney(200);
						for (int i = 0; i < 20; ++i)
						{
							player->LevelUp(1);
						}
					}else{
						if (opcion_tienda!=3)
						{
							clear();
							move(15,50);
							printw("Dinero insuficiente");
							getch();
						}
					}
				}	
			}else if (opcion==3)//info de player
			{
				move(15,50);	
				strcpy(temp, player->toString().c_str());
				printw(temp);
				getch();
			}
	}	
	}
	clear();
	move(18,60);
	printw("Desea guardar[s/n]: ");
	refresh();
	cargar = getch();
	if(cargar=='s'||cargar=='S'){
		//guardar partidas
		int guardar;
		string save;

		guardar = player->GetMoney();

		ofstream escribir("dinero.txt");
		escribir  << guardar; 
		escribir.close();	

		guardar = player->GetVida();

		ofstream escribir2("vida.txt");
		escribir  << guardar; 
		escribir.close();

		save = player->GetNombre();

		ofstream escribir3("nombre.txt");
		escribir  << save; 
		escribir.close();	

		guardar = opc;

		ofstream escribir4("opc.txt");
		escribir  << guardar; 
		escribir.close();
	}
	getch();
	

	delete temp;
	return 0;
}

int menu_atacar(int tipo){
	if (tipo==1)
	{
		int opc;
		char opcion[3];
		int x=30;
		int y=80;
		move(x,y);
		x++;
		printw("Atques:");
		move(x,y);
		x++;
		printw("1-Bola oscura(-2 magia).............30 Daño");
		move(x,y);
		x++;
		printw("2-Fantas(-5 magia)..................60 Daño");
		move(x,y);
		x++;
		printw("3-Pesadilla(-10 magia)..............100 Daño");
		move(x,y);
		x++;
		printw("4-Recargar........................0 Daño");

		move(x,y);
		x++;
		addstr("Ingrese la opcion: ");
		refresh();
		getnstr(opcion, sizeof(opcion) - 1);
		refresh();
		opc=atoi(opcion);
		refresh();
		return opc;
	}else if (tipo==2)
	{
		int opc;
		char opcion[3];
		int x=30;
		int y=80;
		move(x,y);
		x++;
		printw("Atques:");
		move(x,y);
		x++;
		printw("1-Puñetaso.............50 Daño");
		move(x,y);
		x++;
		printw("2-Patada..................100 Daño");
		move(x,y);
		x++;
		printw("3-Derribo..............150 Daño");
		move(x,y);
		x++;
		printw("4-Doble puño..............200 Daño");

		move(x,y);
		x++;
		addstr("Ingrese la opcion: ");
		refresh();
		getnstr(opcion, sizeof(opcion) - 1);
		refresh();
		opc=atoi(opcion);
		refresh();
		return opc;	
	}else if (tipo==3)
	{
		int opc;
		char opcion[3];
		int x=30;
		int y=80;
		move(x,y);
		x++;
		printw("Atques:");
		move(x,y);
		x++;
		printw("1-Purificar.............30 Daño");
		move(x,y);
		x++;
		printw("2-Iluminar..................60 Daño");
		move(x,y);
		x++;
		printw("3-Destello..............100 Daño");
		move(x,y);
		x++;
		printw("4-Curar(+50 vida)..............0 Daño");

		move(x,y);
		x++;
		addstr("Ingrese la opcion: ");
		refresh();
		getnstr(opcion, sizeof(opcion) - 1);
		refresh();
		opc=atoi(opcion);
		refresh();
		return opc;
	}else if (tipo==4)
	{
		int opc;
		char opcion[3];
		int x=30;
		int y=80;
		move(x,y);
		x++;
		printw("Atques:");
		move(x,y);
		x++;
		printw("1-Disparo(-1 tiros).............10 Daño");
		move(x,y);
		x++;
		printw("2-Tiro a al pecho (-5 tiros)..................30 Daño");
		move(x,y);
		x++;
		printw("3-Rafaga(-10 tiros)..............100 Daño");
		move(x,y);
		x++;
		printw("4-Recargar(+10 tiros)..............0 Daño");

		move(x,y);
		x++;
		addstr("Ingrese la opcion: ");
		refresh();
		getnstr(opcion, sizeof(opcion) - 1);
		refresh();
		opc=atoi(opcion);
		refresh();
		return opc;
	}else if (tipo==5)
	{
		int opc;
		char opcion[3];
		int x=30;
		int y=80;
		move(x,y);
		x++;
		printw("Atques:");
		move(x,y);
		x++;
		printw("1-Corte.............30 Daño");
		move(x,y);
		x++;
		printw("2-Golpe rapido..................60 Daño");
		move(x,y);
		x++;
		printw("3-Ataque doble..............100 Daño");
		move(x,y);
		x++;
		printw("4-Corte Dragon..............200 Daño");

		move(x,y);
		x++;
		addstr("Ingrese la opcion: ");
		refresh();
		getnstr(opcion, sizeof(opcion) - 1);
		refresh();
		opc=atoi(opcion);
		refresh();
		return opc;
	}
}
void dibujar_clase(int clase,int x,int y){
	if (clase==1)
		{
			dibujo_mago(x,y);
		}else if (clase==2)
		{
			dibujo_melee(x,y);
		}else if (clase==3)
		{
			dibujo_priest(x,y);
		}else if (clase==4)
		{
			dibujo_tirador(x,y);	
		}else if (clase==5)
		{
			dibujo_espadachin(x,y);
		}
}
int menu_tienda(){
	clear();
	int opc;
	char opcion[3];
	int x=15;
	int y=50;
	move(x,y);
	x++;
	printw("-------------------------MENU---------------------------");
	move(x,y);
	x++;
	printw("                      1- VIDA [ costo-> 200 ]      +50                  ");
	move(x,y);
	x++;
	printw("                      2- FUERZA (esta siempre hace daño por turno a tu enemigo) [ costo-> 300 ]      +20                       ");
	move(x,y);
	x++;
	printw("                      3- Salir                          ");

	move(x,y);
	x++;
	addstr("Ingrese la opcion: ");
	refresh();
	getnstr(opcion, sizeof(opcion) - 1);
	refresh();
	opc=atoi(opcion);
	refresh();
	clear();
	return opc;
}
int menu_principal(){
	clear();
	int opc;
	char opcion[3];
	int x=15;
	int y=50;
	move(x,y);
	x++;
	printw("-------------------------MENU---------------------------");
	move(x,y);
	x++;
	printw("                      1- Pelear                         ");
	move(x,y);
	x++;
	printw("                      2- Tienda                         ");
	move(x,y);
	x++;
	printw("                      3- Status de tu personaje         ");
	move(x,y);
	x++;
	printw("                      4- Salir                          ");

	move(x,y);
	x++;
	addstr("Ingrese la opcion: ");
	refresh();
	getnstr(opcion, sizeof(opcion) - 1);
	refresh();
	opc=atoi(opcion);
	refresh();
	clear();
	return opc;
}

int menu_JuegoNuevo(){
	int opc;
	char opcion[3];
	move(15,50);
	printw("Juego de pelea de Alex Orellana");
	move(16,50);
	printw("presione cualquier boton para continuar");
	getch();
	clear();

	move(15,50);
	printw("Antes de empezar debes elegir que tipo de clase deseas ser");
	move(16,50);
	printw("presione cualquier boton para continuar");
	getch();
	clear();

	int columna=1,fila=1;
	move(columna,fila);
	columna++;
	printw("Las clases son las siguientes:");
	move(columna,fila);
	columna++;
	printw("1-MAGO (su magia se gasta y ocupa recargar)");
	move(columna,fila);
	columna++;
	printw("2-MELEE (aveces falla sus golpes)");
	move(columna,fila);
	columna++;
	printw("3-PRIEST (no se cura siempre)");
	move(columna,fila);
	columna++;
	printw("4-TIRADOR (tiene limite de tiros[30])");
	move(columna,fila);
	columna++;
	printw("5-ESPADACHIN (su espada aveces hace daño extra)");
	move(columna,fila);
	columna++;
	printw("--------------------------------------------------------------------------");
	

	move(columna,fila);
	columna++;
	addstr("Ingrese la opcion: ");
	refresh();
	getnstr(opcion, sizeof(opcion) - 1);
	refresh();
	opc=atoi(opcion);
	refresh();
	clear();
	return opc;
}

void dibujo_mago(int x,int y){
	move(x,y);
	x++;
	y++;
	printw("    ------------        ");
	move(x,y);
	x++;
	printw("  ---( )-------( )---   ");
	move(x,y);
	x++;
	printw(" ---------------------  ");
	move(x,y);
	x++;
	printw(" ---------------------  ");
	move(x,y);
	x++;
	printw(" -----------------------");
}
void dibujo_melee(int x,int y){
	move(x,y);
	x++;
	printw("________________++888_____+++88   ");
	move(x,y);
	x++;
	printw("________________++8888__+++8880++88    ");
	move(x,y);
	x++;
	printw("________________+++8888+++8880++8888     ");
	move(x,y);
	x++;
	printw("_________________++888++8888+++888888++8888   ");
	move(x,y);
	x++;
	printw("_________________++88++8888++8888888++888888      ");
	move(x,y);
	x++;
	printw("_________________++++++888888888888888888_+88        ");
	move(x,y);
	x++;
	printw("__________________++++++88888888888888888_++8       ");
	move(x,y);
	x++;
	printw("__________________++++++++000888888888888+88   ");
	move(x,y);
	x++;
	printw("___________________+++++++000088888888888_88    ");
	move(x,y);
	x++;
	printw("____________________+++++++00088888888888    ");
	move(x,y);
	x++;
	printw("_____________________+++++++088888888888     ");
	move(x,y);
	x++;
	printw("_____________________+++++++088888888888    ");
	move(x,y);
	x++;
	printw("______________________+++++++8888888888     ");
	move(x,y);
	x++;
	printw("______________________+++++++0088888888      ");
	move(x,y);
	x++;
	printw("______________________++++++0088888888          ");
	move(x,y);
	x++;
	printw("______________________++++++00888888l         ");

}
void dibujo_priest(int x,int y){
	move(x,y);
	x++;
	printw("         *****          ");
	move(x,y);
	x++;
	printw("   ******************   ");
		move(x,y);
	x++;
	printw("   ******************   ");
	move(x,y);
	x++;
	printw("         *****          ");
	move(x,y);
	x++;
	printw("         *****          ");
	move(x,y);
	x++;
	printw("         *****          ");
	move(x,y);
	x++;
	printw("         *****          ");
	move(x,y);
	x++;
	printw("         *****          ");
}
void dibujo_tirador(int x,int y){
	move(x,y);
	x++;
	printw("....._|____________________,,__               ");
	move(x,y);
	x++;
	printw("..../ `--|||||||||||----------------------_]         ");
	move(x,y);
	x++;
	printw(".../_==o ____________________|             ");
	move(x,y);
	x++;
	printw(".....),---.(_(__) /           ");
	move(x,y);
	x++;
	printw("....// () ),------   ");
	move(x,y);
	x++;
	printw("...//___// ");
	move(x,y);
	x++;
	printw("../`----' / ... ");
	move(x,y);
	x++;
	printw("./____ / ... . ");
}
void dibujo_espadachin(int x,int y){
	move(x,y);
	x++;
	printw("................ (_)                        ");
	move(x,y);
	x++;
	printw("................(___)                        ");
	move(x,y);
	x++;
	printw("................(___)                        ");
	move(x,y);
	x++;
	printw("......./_____/__/----__/_____/                        ");
	move(x,y);
	x++;
	printw("...............__°__ /                        ");
	move(x,y);
	x++;
	printw("...............|_°_/|                        ");
	move(x,y);
	x++;
	printw("...............|_°_/|                        ");
	move(x,y);
	x++;
	printw("...............|_°_/|                        ");
	move(x,y);
	x++;
	printw("...............|_°_/|                       ");
	move(x,y);
	x++;
	printw("...............|_°_/|                       ");
	move(x,y);
	x++;
	printw("...............|_°_/|                       ");
	move(x,y);
	x++;
	printw("...............|_°_/|                       ");
	move(x,y);
	x++;
	printw("...............|[#]|];;                        ");
	move(x,y);
	x++;
	printw("...............|[#]|];                         ");
	move(x,y);
	x++;
	printw("...............|[#]|]                         ");
	move(x,y);
	x++;
	printw(".................#//                         ");
	move(x,y);
	x++;
	printw("................../                         ");
}