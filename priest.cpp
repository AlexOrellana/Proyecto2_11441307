
#include "luchadores.h"
#include "priest.h"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Priest::Priest(int vida,int fuerza_base,int money,string nombre):Luchadores(vida,fuerza_base,money,nombre){

}
Priest::~Priest(){

}
int Priest::ataquar(int numero){
	srand(time(NULL));
	int  curar=rand()%2+1;
	if (numero==1)
	{
		return 30+fuerza_base;
	}else if (numero==2)
	{
		return 60+fuerza_base;
	}else if (numero==3)
	{
		return 100+fuerza_base;
	}else if (numero==4)
	{
		if (curar==1)
		{
			vida+=50;
		}
		return 0+fuerza_base;
	}
}
void Priest::LevelUp(int numero){
	if (numero==1)
	{
		fuerza_base++;
	}else if (numero==2)
	{
		vida++;
	}
}
void Priest::UseMoney(int numero){
	int temp=money-numero;
	money=temp;
}
string Priest::toString(){
	stringstream ss;
	ss << "Priest"<<"----"<<"vida="<<vida<<" "<<"fuerza base="<<fuerza_base<<" "<<"dinero="<<money<<" "<<"nombre="<<nombre;
	return ss.str();
}
int Priest::herir(int dano){
	int nueva_vida=vida-dano;
	vida = nueva_vida;
	return vida;
}
void Priest::Cambiar_nombre(string name){
	nombre = name;
}
int Priest::GetMoney(){
	return money;
}
void Priest::WinMoney(){
	int win=10;
	money +=10;
}
int Priest::GetVida(){
	return vida;
}
string Priest::GetNombre(){
	return nombre;
}