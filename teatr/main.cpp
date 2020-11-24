#include "message.h"
/*#include "teatr.h"*/
#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2100000
#define MOD 1000000007
#define MOD1 1000696969
#define lld long long

using namespace std;

int GetN() { return int(1e8); }
int GetElement(int i) { return (i * 1ll * i) % int(1e6) + 1; }

int main()
{
    lld n=GetN();
    lld id=MyNodeId();
    lld kk=1;
    lld ilek=NumberOfNodes();
    lld wynik=0;
    lld ile[MAX];
    lld prefy[MAX];
    lld ile1[MAX];
    lld prefy1[MAX];
    while(kk<1000001){
        kk<<=1;
    }
    lld tree[MAX];
    for(int i=0;i<MAX;++i){
        tree[i]=0;
        ile[i]=0;
    }
    lld tab[MAX];
    for(int i=0;i<n/ilek;++i){
        tab[i]=GetElement(id*n/ilek+i);
    }
    for(int i=0;i<n/ilek;++i){
        //wynik+=check
        lld l=tab[i]+1;
        lld p=1000001;
        l+=kk;
        p+=kk;
        lld wyn=0;
        if(l!=p){
            wyn+=tree[l];
            wyn+=tree[p];
        }else{
            wyn+=tree[l];
        }
        while(l/2!=p/2){
            if(l%2==0){
                wyn+=tree[l+1];
            }
            if(p%2==1){
                wyn+=tree[p-1];
            }
            l>>=1;
            p>>=1;
        }
        wynik+=wyn;
        lld gdzie=tab[i];
        gdzie+=kk;
        ile[tab[i]]++;
        while(gdzie>0){
            tree[gdzie]++;
            gdzie>>=1;
        }

    }
    prefy[0]=ile[0];
    for(int i=1;i<MAX/2;++i){
        prefy[i]=prefy[i-1]+ile[i];
    }
    for(int i=0;i<id*n/ilek;++i){
        ile1[GetElement(i)]++;
    }
    prefy1[0]=ile1[0];
    wynik+=prefy1[0]*(prefy[MAX/2]-prefy[0]);
    for(int i=1;i<MAX/2;++i){
        prefy1[i]=prefy1[i-1]+ile1[i];
        wynik+=prefy1[i]*(prefy[MAX/2]-prefy[i]);
    }
    if(id!=0){
        PutLL(0,wynik);
        Send(0);
    }else{
        for(int i=1;i<ilek;++i){
            Receive(i);
            wynik+=GetLL(i);
        }
        printf("%lld",wynik);
    }
    return 0;
}
