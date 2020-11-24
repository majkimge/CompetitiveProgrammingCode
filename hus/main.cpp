#include <bits/stdc++.h>
#define lld long long
#define MAX 100009

using namespace std;

int n,wyn,last,w,temp=1,last1;
int tab[MAX];


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    while(tab[temp]==tab[0]){
        temp++;
    }
    last=tab[temp];
    last1=tab[0];
    if(last>tab[0]){
        w=1;
    }
    if(n>=2){
        wyn=2;
    }else{
        wyn=n;
    }
    //cout<<temp;
    for(int i=temp+1;i<n;++i){
            //cout<<last<<endl;
        if(tab[i]==last){

        }else if(w==1){
            if(tab[i]<last){

                w=0;
                wyn++;

            }
            //cout<<"G";
            last=tab[i];
        }else{
            if(tab[i]>last){
                w=1;
                wyn++;

            }
            last=tab[i];
        }
    }
    printf("%d",wyn);
    return 0;
}
