#include <bits/stdc++.h>

#define MAX 1000000
#define INF 10000000000
using namespace std;

int tab[MAX];
int drzewo[MAX];
int n;
int a,b;
int j=0;
int pow1(int a1,int b1){
    for(int i=0;i<b1;++i){
        a1*=a1;
    }
    return a1;
}
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        scanf("%i",&tab[i]);
    }
    while(pow1(2,j)<n){
        j++;

    }
    for(int i=pow1(2,j-1);i<pow1(2,j);i++){
        if(i<n){
            drzewo[pow1(2,j)+i]=tab[i];
        }else{
            drzewo[pow1(2,j)+i]=INF;
        }
    }
    int k=j/2;
    while(k>0){//cout<<j;
        for(int i=pow1(2,j-1);i<pow1(2,k);i++){
            drzewo[pow1(2,k)]=min(drzewo[pow1(2,k)]*2,drzewo[pow1(2,k)]*2+1);
        }
        k=k/2;
    }
    for(int i=1;i<pow1(2,j+1);++i){
        printf("%i",drzewo[i]);
    }

    return 0;
}
