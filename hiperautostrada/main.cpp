#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int n,k;
int suma=0;
int main()
{
    scanf("%i",&n);
    scanf("%i",&k);
    int tab[n];
    for(int i=0;i<n;i++){
        scanf("%i",&tab[i]);
    }
    for(int i=0;i<n-1;i++){
        suma+=abs(tab[i]-tab[i+1]);
    }

    return 0;
}
int ile(int tab,int n, int k, int suma, int j){
    int najm;
    int sum;
    if(j!=0){
        for(int i=j+1;i<n;i++){
            tab[i-1]=tab[i];
        }
        for(int j=0;j<n-1;j++){

        }
    }

}
