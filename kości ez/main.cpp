#include <bits/stdc++.h>


using namespace std;

double a,b;
double tab[6],tab1[6];

int main()
{
    for(int i=0;i<6;++i){
        cin>>tab[i];
    }
    for(int i=0;i<6;++i){
        cin>>tab1[i];
    }
    for(int i=0;i<6;++i){
        if(tab[i]>tab1[i]){
            a+=tab[i];
        }else if(tab[i]==tab1[i]){
            a+=tab[i]/(double)2.0;
            b+=tab[i]/(double)2.0;
        }else{
            b+=tab1[i];
        }
    }
    printf("%.10lf",min(a,b)/(double)100.0);
    return 0;
}
