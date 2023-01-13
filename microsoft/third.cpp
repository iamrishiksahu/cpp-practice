#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
int NP, NE, *VO,*VTP, T, pop, stok,st, nonam, iter, it, nb_am;
struct et
{
	int id, s, NM, *VT, *VA, **M, cmax;
};
struct sol
{
 int *VSO, **aff,ValOrd, cmax;
};
et *FSH;
sol *SL;
void init();
void gener_sol();
void Aff();
void Matrice(et);
bool exist(int, int*);
int id(int, int[]);
int som(int **);
int MAX(sol);
void aff_sol(sol);
void permut(int&, int&);
int nbrNA(sol*, int);
sol best (sol*);
void genetic(sol*);
//---------------------------------------------------------------------------
int main() 
{
	  int V[10], i;   
	  srand(time(0));
	  init();
 	  Aff();
 	  cout << "\nSol initiale avant simulation : \n";
 	  aff_sol(SL[0]);
 	  genetic(SL);
 	  cout << "\nSol optimale apres simulation : \n";
 	  aff_sol(best(SL));
 	  cout << "\nnombre des iterations : "<< it<<"\n";
 	  cout << "\nnombre de non ameliores : "<< nb_am<<"\n";
	  return 0;
}
//----------------------------------------------------------------------------
void init()
{
  int i,j,k,a;
  cout << "Donner le NBR des Pieces : ";
  cin >> NP;	
  cout << "Donner le NBR des Etages : ";
  cin >> NE;
  cout << "Donner la position du stockage \n(1-Par Machine, 2-Par Etage, 3-Par Systeme):";
  cin >> stok;
  cout << "Donner la taille de pop : ";
  cin >> pop; 
  cout << "Donner le nombre d'iterations pour Genetic :";
  cin >> iter;
  cout << "Donner le nombre de non ameliores pour Genetic :";
  cin >> nonam;
  VO = new int[NP];
  VTP = new int[NP];
  for(a=0;a<NP;a++)for(i=0;i<NP;i++) {VO[i]=i+1; VTP[i] = rand()%30+10;}
  FSH = new et[NE];
  for(i=0;i<NE;i++)
   {
   	FSH[i].id=i+1;
   	//cout << "Donner le Stockage de l'etage "<< i+1 << " :";
	//cin >> FSH[i].s;
	if(stok==1) st = 5;
	else if(stok==2) st = 10;
	else st = 30;
	cout << "Donner le nbr des machines de l'etage "<< i+1 << " :";
	cin >> FSH[i].NM;
	FSH[i].VT = new int[FSH[i].NM];
	for(j=0;j<FSH[i].NM;j++) for(a=0;a<NP;a++)FSH[i].VT[j] = rand()%5+1;
	FSH[i].VA = new int[NP];
	for(j=0;j<NP;j++)
 	  for(k=0;k<3;k++) {FSH[i].VA[j] = rand()%(FSH[i].NM)+1;} 
 	FSH[i].M = new int*[NP];
	for(j=0;j<NP;j++)FSH[i].M[j] = new int[NP];
    Matrice(FSH[i]);
	FSH[i].cmax=0;
   }  
  gener_sol();
}

void Aff()
{
  int i,j,k;
  cout << "le Nbr des pieces = " << NP << ".\n";
  cout << "le Nbr des etages = " << NE << ".\n";
  cout << "L'Ordonnancement des pieces : {";
  for(i=0;i<NP;i++) cout << VO[i] <<"  ";
  cout <<"}.\n";
  cout << "Temps de traitement de chaque pieces : {";
  for(i=0;i<NP;i++) cout << VTP[i] <<"  ";
  cout <<"}.\n";
  for(i=0;i<NE;i++)
   {
   	cout << "\nL'etage "<< i+1 << " :\n";
   	//cout << "      Capacite de stockage: "<< FSH[i].s<<".\n";
	cout << "      le nbr des machines de l'etage "<< FSH[i].NM<<".\n";
	cout << "      Affectation des pieces: {";
	for(j=0;j<NP;j++) cout << FSH[i].VA[j] <<" ";
	cout << "}.\n";
	cout << "      Vitesse de traitement des machines: {";
	for(j=0;j<FSH[i].NM;j++) cout << FSH[i].VT[j] <<" ";
	cout << "}.\n";
	/*cout << "      La Matrice de correspondance :\n";
	for(j=0;j<NP;j++)
	  {
	  	cout << "      ";
	  	for(k=0;k<NP;k++) cout << setw(3) << FSH[i].M[j][k] << setw(3);
	  	cout << "\n";
	  }*/
   } 
}

void Matrice(et e)
{
	int i,j;
	for(i=0;i<NP;i++)
	  for(j=i;j<NP;j++)
	   {	    
	    if(i==j)
	      e.M[i][j]=0;
	    else
		  if(e.VA[i]==e.VA[j])
		    if(id(i+1,VO)<id(j+1,VO))
			  e.M[i][j]=1;
			else
			  e.M[i][j]=-1;
		  else
		    if(id(i+1,VO)<id(j+1,VO))
			  e.M[i][j]=2;
			else
			  e.M[i][j]=-2;
		 e.M[j][i]=-e.M[i][j];	  	  
	   }
}
int id(int v, int A[])
{
	int i=0;
	while(v!=A[i])i++;
	return i;	
}
int som(int **M)
{
	int i,j,s=0;
	for(i=0;i<NP;i++)
	  for(j=i;j<NP;j++)
	   s += abs(M[i][j]); 
	return s*2;
}
void permut (int &a, int &b)
{
	int c = a; a = b; b = c;
}
void gener_sol()
{
	int k,i,j,k1,k2;
	SL = new sol[pop];
	for (k=0;k<pop;k++)
	{	
	     SL[k].VSO= new int[NP];
	     SL[k].aff= new int*[NP];
	     for(j=0;j<NP;j++)
	     SL[k].aff[j]= new int[NE];
		 if(k==0)
		  {
		  	for(i=0;i<NP;i++) SL[k].VSO[i] = VO[i];
		  	SL[k].ValOrd = (rand()%20+50)*(NP+NE/2);
		  	for(i=0;i<NP;i++) 
		  	  for(j=0;j<NE;j++) 
			  SL[k].aff[i][j]=FSH[j].VA[i];
		  }
		 else
		  {
		  	for(i=0;i<NP;i++) SL[k].VSO[i] = VO[i];
		  	k1 = rand()%NP; k2 = rand()%NP;
		  	permut (SL[k].VSO[k1], SL[k].VSO[k2]);
		  	SL[k].ValOrd = (rand()%20+50)*(NP+NE/2);
		  	for(j=0;j<NE;j++) 
		  	  for(i=0;i<NP;i++) 
			  SL[k].aff[i][j]=rand()%(FSH[j].NM)+1;
			 
		  } 
	      SL[k].cmax = MAX(SL[k]);  
	}	  
}

void aff_sol(sol S)
{
   int i,j;
   	cout <<"\nOrdonnancement : "; 
   	for (i=0;i<NP;i++)cout << S.VSO[i] <<" ";
   	//cout << " \nLa valeur "<< S.ValOrd<<"\n";
   	cout << "\nAffectation : \n";
   	for (j=0;j<NE;j++)
   	{
	   for (i=0;i<NP;i++)cout << S.aff[i][j] <<" ";
	   cout << "\n";
	}
    cout << "\nCmax = " << S.cmax <<"\n";	
}

int MAX(sol S)
{
  int f=0,i,j,m=0;
  for(j=0;j<NE;j++) 
    {	
	  for(i=0;i<NP;i++)
	     m += st*0,01*VTP[S.VSO[i]-1]/FSH[j].VT[S.aff[i][j]-1];   
	  m += S.ValOrd;  
    }
  for(i=0;i<NE;i++) f+=FSH[i].NM;
  f = f*NP;  
  return m+f; 	 
}

int nbrNA(sol *S, int max)
{
	int i, nb=0;
	for(i=0;i<pop;i++)
	   if(MAX(S[i])==max)nb++;
	return nb;   
}
sol best (sol *S)
{
	int i;
	sol B = S[0];
	for(i=1;i<pop;i++)
	  if(MAX(S[i])<MAX(B))B = S[i];
	return B;  
}
void genetic(sol *S)
{
 it=0; nb_am=0; int i,j,k1,k2,v,t;
 sol S1, S2;
 while (it<iter && nb_am<nonam)
 { 
   i = rand()%pop;   j = rand()%pop;
   S1 = S[i];   S2 = S[j];
   k1 = rand()%NP;   k2 = rand()%NP;
   permut(S1.VSO[k1], S1.VSO[k2]);
   permut(S2.VSO[k1], S2.VSO[k2]);
   for(t=0;t<NE;t++)
   {
   	v = rand()%NP;
   	S1.aff[v][t] = S2.aff[v][t];
   	v = rand()%NP;
   	S2.aff[v][t] = S1.aff[v][t];
   }
   if(MAX(S1)<MAX(S[i]))S[i]=S1;
   if(MAX(S2)<MAX(S[j]))S[j]=S2;
   it++;
   nb_am = nbrNA(S, MAX(best(S)));
 }	
}