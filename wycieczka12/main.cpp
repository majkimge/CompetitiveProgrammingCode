#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define MAX1 2100000

using namespace std;

int z,n,a,b,m,t,wynik,mini,kk=1;

int tab1[2100000];
int tree[MAX*4];
vector<int> wagi;

void bin(int ab,int siz){
    int l=0;
    int p=siz;
    int s=(l+p)/2;
    int wyn=0;
    while(l<=p){
        s=(l+p)/2;
        if(wagi[s]>ab){
            p=s-1;
        }else{
            wyn=s;
            l=s+1;
        }
    }
    if(wyn!=0){
        wagi[wyn]=MAX;
        wynik+=min(2*b,a);
    }else{
        wynik+=min(a,b);
    }

}

void ustaw(int gdzie,int na){
    //gdzie+=kk;
    tree[gdzie]=na;
    gdzie>>=1;
    while(gdzie>0){
        tree[gdzie]=max(tree[gdzie*2],tree[gdzie*2+1]);
        gdzie>>=1;
    }
}

void check(int co){
    co+=kk;
    bool high=false;
    if(tree[co]>0){
        ustaw(co,tree[co]-1);
        wynik+=min(2*b,a);
    }else if(co%2==0&&tab1[co]){
        wynik+=min(a,b);
    }else{
        if(co%2==0){
            co=co/2-1;
        }else{
            co>>=1;
        }
        while(co<kk){

            if(tree[co*2+1]){
                co=co*2+1;
            }else if(tree[co*2]){
                co=co*2;
            }else{
                if(tab1[co]){
                    wynik+=min(a,b);
                   // cout<<co-kk;
                    high=true;
                    break;
                }
                if(co%2==0){
                    co=co/2-1;
                }else{
                    co>>=1;
                }
            }
        }
        if(!high){
            ustaw(co,tree[co]-1);
            wynik+=min(2*b,a);
        }
    }
}

int main()
{
    while(kk<MAX){
        tab1[kk]=1;
        kk<<=1;
        tab1[kk]=1;
    }
    scanf("%d",&z);
    for(int xa=0;xa<z;++xa){
        scanf("%d",&n);
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&m);
        wynik=0;
        wagi.clear();
        for(int i=0;i<MAX1;++i){
            tree[i]=0;
        }
        for(int i=0;i<n;++i){
            scanf("%d",&t);
            //tab[t]++;
            wagi.pb(t);
            //tab1[i]=t;
            ustaw(t+kk,tree[t+kk]+1);
        }
        wagi.pb(-1);
        sort(wagi.begin(),wagi.end());
        //sort(tab1,tab1+n);
        //cout<<*war.begin();
        for(int i=wagi.size()-1;i>0;--i){//
            if(wagi[i]>m&&tree[wagi[i]+kk]){
                wynik+=b;
                //wagi[i]=MAX;
            }else{
                if(wagi[i]<=m&&tree[wagi[i]+kk]){

                    ustaw(wagi[i]+kk,tree[wagi[i]+kk]-1);
                    check(m-wagi[i]);
                }
            }
        }
        printf("%d\n",wynik);
    }



    return 0;
}

/*
1
5 1 3 10
9 2 6 5 4
*/
