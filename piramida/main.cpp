#include <bits/stdc++.h>
#define lld int
#define MAX 200009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n;
int tab[MAX];

int suma;
int sumy[1000009];
int temp[MAX];
int tur;

int med(){
    sort(temp,temp+3);
    return temp[1];
}

int check(int od){
    for(int i=0;i<n*2-1;++i){
        if(tab[i]>=od){
            temp[i]=1;
        }else{
            temp[i]=0;
        }
    }
    int last=temp[0];
    int odl=INF;
    int wyn=-1;
    for(int i=1;i<n*2-1;++i){
        if(temp[i]==last){
            if(abs((n*2-1)/2-i)<odl||abs((n*2-1)/2-i+1)<odl){
               odl=min(abs((n*2-1)/2-i),abs((n*2-1)/2-i+1));
                wyn=last;
               }
        }else{
            last=temp[i];
        }
    }
    if(wyn!=-1){
            //cout<<"BOI";
        return wyn;
    }else{
        if(n%2==1){
            return temp[n-1];
        }else{
            return !temp[n-1];
        }
    }
}

int bin(){
    int l=0;
    int p=1000000;
    int s=(l+p)/2;
    int wyn;
    while(l<=p){
        s=(l+p)/2;
        if(check(s)==1){
            //cout<<s;
            l=s+1;
            wyn=s;
        }else{
            p=s-1;
        }

    }
    return wyn;
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n-1;++i){
        scanf("%d",&tab[i]);
    }
    printf("%d",bin());


    return 0;
}
