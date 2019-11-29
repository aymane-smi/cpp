#include<iostream>
#include"ex0.h"
main(){
	vect V(1,2,3), test;
	int t[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8,9 };
	matrice M(t);
	test = prod(M, V);
}