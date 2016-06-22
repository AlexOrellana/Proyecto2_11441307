
#include "luchadores.h"
#include "espadachin.h"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Espadachin::Espadachin(int vida,int fuerza_base,int money,string nombre):Luchadores(vida,fuerza_base,money,nombre){

}
Espadachin::~Espadachin(){

}
int Espadachin::ataquar(int numero){
	srand(time(NULL));
	int  pegar=rand()%2+1;
	if (numero==1)
	{
		if (pegar==1)
		{
			return 30+fuerza_base;
		}else{
			return 30+10+fuerza_base;
		}
	}else if (numero==2)
	{
		if (pegar==1)
		{
			return 60+fuerza_base;
		}else{
			return 60+10+fuerza_base;
		}
	}else if (numero==3)
	{
		if (pegar==1)
		{
			return 100+fuerza_base;
		}else{
			return 100+10+fuerza_base;
		}
	}else if (numero==4)
	{
		if (pegar==1)
		{
			return 200+fuerza_base;
		}else{
			return 200+10+fuerza_base;
		}
	}
}
void Espadachin::LevelUp(int numero){
	if (numero==1)
	{
		fuerza_base++;
	}else if (numero==2)
	{
		vida++;
	}
}
void Espadachin::UseMoney(int numero){
	int temp=money-numero;
	money=temp;
}
string Espadachin::toString(){
	stringstream ss;
	ss << "Espadachin"<<"----"<<"vida="<<vida<<" "<<"fuerza base="<<fuerza_base<<" "<<"dinero="<<money<<" "<<"nombre="<<nombre;
	return ss.str();
}
int Espadachin::herir(int dano){
	int nueva_vida=vida-dano;
	vida = nueva_vida;
	int vida;
}
void Espadachin::Cambiar_nombre(string name){
	nombre = name;
}
int Espadachin::GetMoney(){
	return money;
}
void Espadachin::WinMoney(){
	int win=10;
	money +=10;
}
int Espadachin::GetVida(){
	return vida;
}
string Espadachin::GetNombre(){
	return nombre;
}
