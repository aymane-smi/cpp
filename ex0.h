using namespace std;
class matrice;
class vect{
	int v[3];
	public:vect(int a=0, int b=0, int c=0){
		                     v[0] = a;
		                     v[1] = b;
		                     v[2] = c;
	}
		  ~vect(){}
		  vect(vect &t){
		  	for(int i=0;i<3;i++)
		  		v[i] = t.v[i];
		  }
		  friend vect prod(matrice, vect);
};
class matrice{
	int m[3][3];
	public:matrice(int t[3][3]){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				m[i][j] = t[3][3];
	}
		   ~matrice(){}
		   matrice(matrice &t){
		   	for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					m[i][j] = t.m[i][j];
		   }
		   friend vect prod(matrice, vect);
};
vect prod(matrice M, vect V){
	vect tmp;
	int s;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			s += M.m[i][j]*V.v[i];
		tmp.v[i] = s;
	}
	return tmp;
}