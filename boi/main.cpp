#include <bits/stdc++.h>

using namespace std;
long long z;
//int n;
long long tab[20];
unsigned long long suma;
bool p = false;
long long pier;
int main()
{
   cin>>z;
    for(long long i=0;i<z;i++){
        cin>>tab[i];
    }
    for(long long i=0;i<z;i++){
        suma=0;
        p=false;
        /*if(tab[i]<1){
    for(int j=1;j<(tab[i]+1)/2;j++){
        suma+=(double)(tab[i]%j);
    }
    suma+=(double)(((tab[i]+1)/2)*((tab[i]+1)/2-1)/2);
    printf("%.0f\n",suma);
        }else*///{
            pier=(int)sqrt((double)tab[i]);

            if(pier*pier<tab[i]){
                pier++;
                p=true;
            }

            for(long long j=1;j<=pier;j++){
        suma+=(tab[i]%j);
    }
    if(p){
        pier--;
    }
    for(long long k=2;k<=pier;k++){
                if(tab[i]%((tab[i]+k-2)/(k-1))==0){
                if(k>2){
                suma+=((((tab[i])/(k-1)-(tab[i])/k)*((tab[i])/(k-1)-(tab[i])/k-1)/2)*(k-1));
                }else{
                    suma+=(((tab[i]-(tab[i])/k)*((tab[i])-(tab[i])/k-1)/2)*(k-1));
                }
                }else{
                    if(k>2){
                    suma+=(((tab[i])/(k-1)-(tab[i])/k-1)*(tab[i]%((tab[i])/(k-1)-1))+(((tab[i])/(k-1)-(tab[i])/k-2)*((tab[i])/(k-1)-(tab[i])/k-1))/2*(k-1)+tab[i]%((tab[i])/(k-1)));
                    }else{
                        suma+=(((tab[i]-(tab[i])/k)*((tab[i])-(tab[i])/k-1)/2)*(k-1));
                    }
                }
    }
    cout<<suma<<endl;
        //}
    }
    return 0;
}
