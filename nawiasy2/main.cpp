#include <bits/stdc++.h>
#define MAX 100009

using namespace std;

int n,suma,ile,k,a,b,wyn,ilebad;
int tab[MAX];
int pref[MAX];
int bady[MAX];
int prefbady[MAX];
char temp[MAX];
int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%s",temp);
    for(int i=0;i<n;++i){

        if(temp[i]=='('){
            tab[i]=1;
           }else{
            tab[i]=0;
           }
    }
    for(int i=0;i<n;++i){
        if(tab[i]==1){
            suma++;
            pref[i]=ile;
        }else{
            if(suma>0){
                suma--;
                ile+=2;
            }
            pref[i]=ile;
        }
        //cout<<pref[i]<<" ";
    }
    for(int i=n-1;i>=0;--i){
        if(tab[i]==1){
            if(ilebad>0){
                ilebad--;
                bady[i]=-2;
            }


        }else{
            ilebad++;
        }
        //cout<<pref[i]<<" ";
    }
    ilebad=0;
    prefbady[0]=bady[0];
    for(int i=1;i<n;++i){
        prefbady[i]=prefbady[i-1]+bady[i];
        //cout<<pref[i]<<" ";
    }
    for(int i=0;i<k;++i){
            wyn=0;
        scanf("%d",&a);
        scanf("%d",&b);
        wyn=pref[b-1];
        if(a!=1){
            wyn+=prefbady[a-2];
        }
        printf("%d\n",wyn);
    }

    return 0;
}
