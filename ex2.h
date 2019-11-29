#include<iostream>
#include<cstdlib>
using namespace std;
class matrice{
	int m[3][3];
	public:matrice(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				m[i][j] = rand()%11;
	}
	void affiche(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				cout<<m[i][j]<<endl;
	}
	matrice(int n){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				m[i][j] = rand()%(n+1);
	}
	matrice(char c){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				cout<<"donne une valeur:";
				cin>>m[i][j];
			}
	}
	~matrice(){}
	matrice(matrice const &M){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				m[i][j] = M.m[i][j];
	}
	matrice operator=(matrice const &M){
		if(this != &M){
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					m[i][j] = M.m[i][j];
		}
		return *this;
	}
	matrice operator+(const matrice &M){
		matrice T;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				T.m[i][j] = m[i][j]+M.m[i][j];
		return T;
	}
	matrice operator-(const matrice &M){
		matrice T;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				T.m[i][j] = m[i][j]-M.m[i][j];
		return T;
	}
	matrice operator*(matrice const &M){
		matrice T;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					T.m[i][j] += m[i][k]*M.m[k][i];
		return T;
	}
	friend matrice transpose(matrice const &M){
		matrice T;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				T.m[i][j]=M.m[j][i];
		return T;
	}
	friend int det(matrice const &M){
		return M.m[0][0]*(M.m[1][1]*M.m[1][2]-M.m[2][1]*M.m[2][2])-M.m[0][1]*(M.m[1][0]*M.m[1][2]-M.m[2][0]*M.m[2][2])+M.m[0][2]*(M.m[1][0]*M.m[1][1]-M.m[2][0]*M.m[2][1]);
	}
	friend int comatrice(matrice const &M, int p, int q){
		int t[2][2], k=0, l=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i!=p && j!=q){
					if(l == 2){
						k++;
						l=0;
					}
					t[k][l++]=M.m[i][j];
				}
		return t[0][0]*t[1][1]-t[0][1]*t[1][0];
	}
	friend matrice inverse(matrice const &M){
		matrice T;
		int tmp=det(T);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				T.m[i][j] = comatrice(M, i, j);
		T=transpose(T);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				T.m[i][j]*=tmp;
		return T;
	}
	matrice operator/(matrice const &M){
		matrice T;
		T = *this * inverse(M);
		return T;
	}
	matrice operator+=(matrice const &M){
		*this = *this + M;
		return *this;
	}
	matrice operator-=(matrice const &M){
		*this = *this - M;
		return *this;
	}
	matrice operator*=(matrice const &M){
		*this = *this * M;
		return *this;
	}
	matrice operator/=(matrice const &M){
		*this = *this / M;
		return M;
	}
	matrice operator++(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i==j)
					*this.m[i][j] +=1;
		return *this; 
	}
	matrice operator--(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i==j)
					*this.m[i][j] -=1;
		return *this; 
	}
};