
#include "luchadores.h"
#include "melee.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Melee::Melee(int vida,int fuerza_base,int money,string nombre):Luchadores(vida,fuerza_base,money,nombre){

}
Melee::~Melee(){

}
int Melee::ataquar(int numero){

}
void Melee::LevelUp(int numero){
	if (numero==1)
	{
		fuerza_base++;
	}else if (numero==2)
	{
		vida++;
	}
}
void Melee::UseMoney(int numero){
	int temp=money-numero;
	money=temp;
}
string Melee::toString(){
	stringstream ss;
	ss << "Melee"<<"----"<<"vida="<<vida<<" "<<"fuerza base="<<fuerza_base<<" "<<"dinero="<<money<<" "<<"nombre="<<nombre;
	return ss.str();
}
int Melee::herir(int dano){
	int nueva_vida=vida-dano;
	vida = nueva_vida;
	return vida;
}
void Melee::Cambiar_nombre(string name){
	nombre = name;
}
int Melee::GetMoney(){
	return money;
}
void Melee::WinMoney(){
	int win=10;
	money +=10;
}