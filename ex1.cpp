#include<iostream>
#include"ex1.h"
using namespace std;
main(){
	complexe z1(1, 1), z2(2, 2), z(2, 2);
	z = (z1+z2);
	z +=z2;
	z.affichage();
}