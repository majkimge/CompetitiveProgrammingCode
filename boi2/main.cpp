#include <bits/stdc++.h>

using namespace std;
long long z;
//int n;
long long tab[20];
unsigned long long suma;

long long pier;
int main()
{
   cin>>z;
    for(long long i=0;i<z;i++){
        cin>>tab[i];
    }
    for(long long i=0;i<z;i++){
        suma=0;


            pier=(int)sqrt((double)tab[i]);

            if(pier*pier<tab[i]){
                pier++;

            }

    for(long long j=1;j<=pier;j++){
        suma+=(tab[i]%j);
    }

    for(long long k=2;k<=pier;k++){

                if(((tab[i]+k-1)/k)>=pier){
                if(k>2){

                if(((tab[i]+k-2)/(k-1)-(tab[i]+k-1)/k-1)>=2){

                if(((tab[i]+k-2)/(k-1)-(tab[i]+k-1)/k-1)%2==0){
                    suma+=(tab[i]%((tab[i]+k-2)/(k-1)-1)+tab[i]%((tab[i]+k-1)/k+1))*((tab[i]+k-2)/(k-1)-(tab[i]+k-1)/k-1)/2+tab[i]%((tab[i]+k-2)/(k-1));
                }else{
                    suma+=(tab[i]%((tab[i]+k-2)/(k-1)-1)+tab[i]%((tab[i]+k-1)/k+1))/2*((tab[i]+k-2)/(k-1)-(tab[i]+k-1)/k-1)+tab[i]%((tab[i]+k-2)/(k-1));
                }
                }else if(((tab[i]+k-2)/(k-1)-(tab[i]+k-1)/k-1)==1){

                    suma+=tab[i]%((tab[i]+k-2)/(k-1)-1)+tab[i]%((tab[i]+k-2)/(k-1));
                }else if(((tab[i]+k-2)/(k-1)-(tab[i]+k-1)/k-1)<1){

                    suma+=tab[i]%((tab[i]+k-2)/(k-1));
                }

                }else{
                    suma+=(((tab[i]-(tab[i]+k-1)/k)*((tab[i])-(tab[i]+k-1)/k-1)/2)*(k-1));
                }
                }else{
                    if(k>2){

                if(((tab[i]+k-2)/(k-1)-pier-1)>=2){

                if(((tab[i]+k-2)/(k-1)-pier-1)%2==0){
                    suma+=(tab[i]%((tab[i]+k-2)/(k-1)-1)+tab[i]%(pier+1))*((tab[i]+k-2)/(k-1)-pier-1)/2+tab[i]%((tab[i]+k-2)/(k-1));
                }else{
                    suma+=(tab[i]%((tab[i]+k-2)/(k-1)-1)+tab[i]%(pier+1))/2*((tab[i]+k-2)/(k-1)-pier-1)+tab[i]%((tab[i]+k-2)/(k-1));
                }
                }else if(((tab[i]+k-2)/(k-1)-pier-1)==1){

                    suma+=tab[i]%((tab[i]+k-2)/(k-1)-1)+tab[i]%((tab[i]+k-2)/(k-1));
                }else if(((tab[i]+k-2)/(k-1)-pier-1)<1){

                    if(pier<((tab[i]+k-2)/(k-1)))
                    suma+=tab[i]%((tab[i]+k-2)/(k-1));
                }

                }else{
                    suma+=(((tab[i]-pier)*((tab[i])-pier-1)/2)*(k-1));
                }
                }

                }
   cout<<suma<<endl; }


        //}

    return 0;
}
