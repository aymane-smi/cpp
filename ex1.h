#include<cmath>
#include<iostream>
using namespace std;
class complexe{
	double re, im;
	public:complexe(int a=0, int b=0){
		re = a;
		im = b;
	}
	~complexe(){}
	complexe(const complexe &z){
		re = z.re;
		im = z.im;
	}
	//=
	complexe operator=(complexe const &z){
		if(this != &z){
			re = z.re;
			im = z.im;
		}
		return *this;
	}
	// friend complexe& operator=(complexe &z1, complexe &z2){
	// 	if(z1 != z2){
	// 		z1.re = z2.re;
	// 		z1.im = z2.im;
	// 	}
	// 	return z1;
	// }
	//+
	complexe operator+(complexe &z){
		complexe tmp;
		tmp.re = re+z.re;
		tmp.im = im+z.im;
		return tmp;
	}
	// friend complexe& operator+(complexe &z1, complexe &z2){
	// 	complexe tmp;
	// 	tmp.re = z1.re+z2.re;
	// 	tmp.im = z2.re+z2.im;
	// 	return tmp;
	// }
	//-
	complexe operator-(complexe &z){
		complexe tmp;
		tmp.re = re-z.re;
		tmp.im = im-z.im;
		return tmp;
	}
	// friend complexe& operator-(complexe &z1, complexe &z2){
	// 	complexe tmp;
	// 	tmp.re = z1.re-z2.re;
	// 	tmp.im = z1.im-z2.im;
	// 	return tmp;
	// }
	//*
	complexe operator*(complexe &z){
		complexe tmp;
		tmp.re = re*z.re-im*z.im;
		tmp.im = im*z.re+re*z.im;
		return tmp;
	}
	// friend complexe& operator*(complexe &z1, complexe &z2){
	// 	complexe tmp;
	// 	tmp.re = z1.re*z2.re-z1.im*z2.im;
	// 	tmp.im = z1.im*z2.re+z1.re*z2.im;
	// 	return tmp;
	// }
	// /
	complexe operator/(complexe &z){
		complexe tmp;
		if(z.re!=0 || z.im!=0){
			tmp.re = (re*z.re+im*z.re)/(pow(z.re,2)+pow(z.im,2));
			z.im = (im*z.re-re*z.im)/(pow(z.re,2)+pow(z.im,2));
			return tmp;
		}
	}
	// friend complexe& operator/(complexe &z1, complexe &z2){
	// 	complexe tmp;
	// 	if(z2.re!=0 || z2.im!=0){
	// 		tmp.re = (z1.re*z2.re+z1.im*z2.re)/(pow(z2.re,2)+pow(z2.im,2));
	// 		z1.im = (z1.im*z2.re-z1.re*z2.im)/(pow(z2.re,2)+pow(z2.im,2));
	// 		return tmp;
	// 	}
	// }
	//+=
	complexe operator+=(complexe &z){
		*this = *this+z;
		return *this;
	}
	// friend complexe& operator+=(complexe &z1, complexe &z2){
	// 	z1 = z1+z2;
	// 	return z1;
	// }
	//-=
	complexe operator-=(complexe &z){
		*this=*this-z;
		return *this;
	}
	// friend complexe& operator-=(complexe &z1, complexe &z2){
	// 	z1 = z1-z2;
	// 	return z1;
	// }
	//*=
	complexe operator*=(complexe &z){
		*this=*this * z;
		return *this;
	}
	// friend complexe& operator*=(complexe &z1, complexe &z2){
	// 	z1 = z1*z2;
	// 	return z1;
	// }
	// /=
	complexe operator/=(complexe &z){
		*this=*this/z;
		return *this;
	}
	// friend complexe& operator/=(complexe &z1, complexe &z2){
	// 	z1=z1/z2;
	// 	return z1;
	// }
	void affichage(){
		cout<<re<<" "<<im<<endl;
	}
};