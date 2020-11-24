#include <bits/stdc++.h>

#define MAX 2000
using namespace std;

int n;
int tab[10];
int fi[MAX];
int suma=0;
int nwd(int a, int b){
    do{
        if(a>b) a=a-b;
        else b=b-a;

    }
    while(a!=b);
    return a;
}
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        scanf("%i",&tab[i]);
    }
    for(int i=1;i<MAX;i++){
        suma=0;
        for(int j=1;j<i;j++){
            if(nwd(i,j)==1){
                suma++;
            }
        }
        fi[i]=suma;

    }
    for(int i=0;i<n;i++){
        bool jest=false;
        for(int j=1;j<MAX;j++){

            if(fi[j]==tab[i]){
                printf("%i\n",j);
                jest=true;
                break;
            }
        }
        if(!jest){
            printf("NIE MA\n");
        }
    }
    //printf("%i",fi[15]);
    return 0;
}
