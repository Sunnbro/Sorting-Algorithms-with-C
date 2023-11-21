#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h> //pow func

//var globale
int booli=0;
////////////////////////////////////////////////////////////////////////////////////////////////////
/*tri rapide */
 
 int partition(int *T[], int g, int d)
 {
 /*declaration*/
 int* ipiv;
 int i,j;
int* temp;
 /*debut du sous-programme*/
 ipiv=T[d];
 i=g-1;
 j=d;
 while(i<=j)
 {
 /*while(T[++i]<ipiv);
 while(T[--j]>ipiv);
 */
do{i++;}while(T[i]<ipiv && i<=d ); //tant que T[i]< pivot et mazal mawslnach le pivot: ++i
do{j--;}while (T[j]>ipiv && j>=g ); //tant que T[i]< pivot et mazal mawslnach le pivot: --j
if(i<j)         //si tla9aw= trie, condition majozch, sinon i<j ca veut dire pas trie 1 2 8 4 9 11 7 hna i=2 inf j=3 i<j permute
 {
 /*echange des cases*/
 temp=T[i];
 T[i]=T[j];
 T[j]=temp;
 }
 }
 /*echange final avec le piv*/ //pcq le pivot n'etait pas compte en dessus
 temp=T[i];
 T[i]=T[d];
 T[d]=temp;
 return i;

 }


 
 void tri_rapide (int *T[], int g, int d)
 {
 int piv; //pivot
 if(g < d)  
 {
 piv= partition(T, g, d);// trie le tab de g a d et renvoie le pivot 
 tri_rapide(T,g,piv-1); //appel sur la partie gauche du dernier tab
 tri_rapide(T,piv+1,d);  //appel sur la partie droite du dernier tab
 }
 }

 ///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Tri gnome /////////////////////////////////////////////////////////

void tri_gnome (long int* tab, long b) {
    long pos=1; // 1 et pas 0 pour pouvoir comparer avec celui d'avant
    while(pos<b){ // tant que pos < fin de tableau
    if(tab[pos] >= tab[pos-1]) // si val inf a la val suivante,on continue
             pos++;
    else{                       //sinon
        long t = tab[pos-1];    //on les permute
        tab[pos-1]= tab[pos];   
        tab[pos] = t;

        if (pos > 1){pos--;}    // si pos >1 on fait pos--(recule), sinon si pos=1 on peut pas faire pos-- car pos devient la premiere val du tab
                                // donc on pourra plus permuter ni comparer avec le precedent
        }
                }
                                    }
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////Tri pas tas/////////////////////////////////////////////////////////
void permuter ( int* tab [], long i, long j)//permute :)
{
        int* T[1];
        T[0]=tab[i];
        tab[i]=tab[j];
        tab[j]=T[0];
}

void redescendre ( int* tab[], const long n, long i) //apres permut, il est > aux fils donc il faut le redescendre
{   
    for (int rs=0;rs<n;rs++){printf("T[%d]=%ld \t",rs,tab[rs]);}  // print le tab stv
    printf("\n \n \n");    
    long min;

        if (2*i+1>=n) return; //si il n'as pas de fils il quitte, il ne peut plus redescendre
       
       if(i==0 && booli==1){  // cas ou racine n'as plus qu'un seul fils: gauche (avant derniere etape ou il reste 2 elements dans le tas)
        min=1;
       }
       else if(i==0 && booli==0){   //si on est a la racine est il a 2 fils
        if(tab[1]<tab[2]) //minimum entre les 2 fils de la racine
        min=1;
        else
        min=2;
       }
       //0 1 2 3 4 5 6 7 8 9 10 11 12
       else{    if(2*i+2>=n && 2*i+1<n) //cas ou fils droit existe pas, fils gauche existe
                 min=2*i+1;

                else if (tab[2*i+2]<tab[2*i+1]) //les 2 fils existent: on choisi le minimum entre les 2 fils de l'indice i
                     min=2*i+2;
                     else
                     min=2*i+1;
        
       }
        if (tab[min]<tab[i]) // si fils min inferieur a pere, on permute
        {
                permuter (tab, min, i);
                printf(" permute %ld avec %ld \n",tab[min],tab[i]);
                redescendre (tab, n, min);//min est la nouvelle position de lancien pere, on vas continuer de redescendre tant que > a ses fils
        }
}
void remonter ( int* tab[], long n, long i) //remonter les vals les plus petits en haut du tas
{
        if (i==0) return;   // si on est a la racine on quitte, on peut plus remonter
        if (tab[i]<tab[(i-1)/2]) //tester si noeud inferieur au pere (noeud =i , pere = i-1/2) , si oui on va le remonter jusqu'a fils > pere
        {
                permuter (tab, i, (i-1)/2); //permuter le noeud avec son pere
                remonter (tab, n, (i-1)/2); //rappeler la fonction pour i=pere, ceci pour remonter jusqu'a le fils > pere
        }
 
}
void organiser(  int *tab[], long n )
{
        long i;
        for(i = 1 ; i < n ; i++)    //pour chaque valeur du tab initial, on le remonte a sa position
        remonter(tab, n, i);
}


int ** tri_tas(int* tab[], long n )
{
        long i=n-1,j=0;
        long int* tab2=( long int *)malloc(n * sizeof(long int*));
        organiser(tab, n); //creation du tas min
       printf("tableau organise: \n");
       for (int rs=0;rs<n;rs++){printf("T[%d]=%ld \t ",rs,tab[rs]);}
       printf("\n \n \n");
       printf("Debut redes \n");
       // apres la creation du tas, le minimum est dans la racine, on vas donc le permuter avec le dernier element du tas
             while (i>=0)
             {  
                permuter(tab, 0, i);// permute
                if (i==2)
                {  booli=1;
                }
                
                printf("le min %ld est au sommet, on l'extrait \n",tab[i]);
                tab2[j]=tab[i];
                redescendre(tab, i, 0); //redescendre la tete qui est sup > fils apres la permut
                i--;j++;
             }
             return tab2;
       
}
//////////////////////////////////////////////////////////////////////////////////////

/////////////////// TRI Reverse ////////////////////////////////////////////////////
void tri_reverse(long int *t,long n){
int i, max, j , k;
for(i =0; i < n; i++)
    {max = i;
    /*localisation du minimum*/
for(j = i+1; j < n ; j++)
{if(t[j] > t[max])
    max = j;
}
/*inversion*/
k = t[i];
t[i] = t[max];
t[max] =k;
}}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////*tri_base*///////////////////////////////////////////
int cle(int x, int i){ //1er arg la valeur, 2eme la cle: 0=chiffre 1 , 1=chiffre 2 etc
   
  int x1=pow(10,i); 
   return (x/x1)%10;
}

void triAux(int *tab,int nb,int k){ //proced comparaison des cles
int i,j,val;

for(i=0;i<nb;i++)
{
    val=tab[i]; // on stocke t[i] car on vas l'ecraser si ya permutation
    
    j=i;
    while((j>0) && (cle(val,k)<cle(tab[j-1],k))) // tant que la cle de val< cle de la case d'avant, T[j]=T[j-1] et j-- et on continue
    {
      tab[j]=tab[j-1];
      j--;
    }
    tab[j]=val; // ici la cle de la val est soit superieure a celle d'avant, ou bien on est dans la premiere case du tableau, 
                // T[j]=val(position finale)
    }
}

void tribase(int *tab,int nb,int k){
    
    for(int j=0;j<=k;j++){  //trier le tableau k fois, k=le nombre de chiffres dans la valeur max du tableau
        triAux(tab,nb,j);
        
    }

}

//////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Tri Bulle/////////////////////////////////////////////
void TriBulleOpt (long int *T, int n) { 

int m=n-1; 

int Changement = 1; //(variable booléenne) 

while (Changement==1) { Changement=0;  // tant qu'il ya une permutation on refait le parcours du tableau des le debut,

       for(int i=0;i<=m;i++){ //on parcourt le tableau

if (T[i] > T[i+1]) { //si T[i]<suiv on permute , changem =1,
int a;
        a=T[i];
        T[i]=T[i+1];
        T[i+1]=a;
Changement=1; 

   	     } 

} 

       m=m-1; //seule chose qui change, a chaque parcours du tab on reduit la taille du tab a parcourir car le dernier element est toujours a sa place

    } //dernier parcours 0 permutations donc changement =0, on sort de la boucle, fin.

} 


void TriBulle (long int *T, int n) { 

int Changement = 1; //(variable booléenne) 

while (Changement==1) { Changement=0; // tant qu'il ya une permutation on refait le parcours du tableau des le debut,

       for(int i=0;i<=n-1;i++){ //on parcourt le tableau

if (T[i] > T[i+1]) { //si T[i]<suiv on permute , changem =1, 
 int a;
      a=T[i];
        T[i]=T[i+1];
        T[i+1]=a;
Changement=1; 

   	     } 
                    //dernier parcours 0 permutations donc changement =0, on sort de la boucle
} 

    } 

} 
///////////////////////////////////////////////////////////////////////////////////////


int main()
{
double dd;
long int *tab;
int i;

long b;
clock_t t1,t2;
int j2z;
printf("\n");
double tr21[14];
long tr2[14];

//tr2[0]=5;tr2[1]=20000;tr2[2]=70000;tr2[3]=80000;tr2[4]=90000;tr2[5]=100000;tr2[6]=120000;tr2[7]=140000;tr2[8]=160000;tr2[9]=180000;tr2[10]=200000;tr2[11]=250000;tr2[12]=300000;
//tr2[0]=50000;tr2[1]=70000;tr2[2]=100000;tr2[3]=8000000;tr2[4]=9000000;tr2[5]=1000000;tr2[6]=1200000;tr2[7]=9400000;tr2[8]=1600000;tr2[9]=1800000;tr2[10]=2000000;tr2[11]=2500000;tr2[12]=3000000;
tr2[0]=8;tr2[1]=100000;tr2[2]=200000;tr2[3]=400000;tr2[4]=800000;tr2[5]=3200000;//tr2[6]=6400000;tr2[7]=12800000;tr2[8]=25600000;tr2[9]=51200000;tr2[10]=102400000;tr2[11]=204800000;tr2[12]=69;

for (size_t j2z = 0; j2z < 1; j2z++) // 
{
    /* code */
tab=( long int *)malloc(tr2[j2z]* sizeof(long int*));

for (i=0;i<tr2[j2z];i++){tab[i]=rand()%180;}//tr2[j2z];}

//tri_rapide(tab,0,tr2[j2z]);       // meilleur cas : tab deja trie
//tri_reverse(tab,tr2[j2z]);        //pire cas: tab trie inversement
for (int rs=0;rs<tr2[j2z];rs++){printf("T[%d]=%ld \t \t",rs,tab[rs]);}  // print le tab stv
printf("\n \n \n");
t1=clock();
//tri_rapide(tab,0,tr2[j2z]);
//tri_gnome(tab,tr2[j2z]);
//TriBulle(tab,tr2[j2z]);
//TriBulleOpt(tab,tr2[j2z]);
tab=tri_tas(tab,tr2[j2z]);
//tribase(tab,tr2[j2z],4); // NE PAS OUBLIER DE CHANGER LE 3EME PARAMETRE = nb digits du max de tab 
 t2=clock();
for (int rs=0;rs<tr2[j2z];rs++){printf("T[%d]=%ld \t",rs,tab[rs]);} // print le tab stv
//printf("\n \n \n");

tr21[j2z]=(double)(t2-t1)/CLOCKS_PER_SEC;
printf("tri %d termine \n",j2z);
}
for (size_t j2z = 0; j2z < 1; j2z++) //boucle pour afficher tt les deltas
{
 

printf("la valeur de delta avec la valeur %ld est : %lf\t \t",tr2[j2z],tr21[j2z]);
printf("fin du tri %d \n",j2z);
}
return 0;
}
