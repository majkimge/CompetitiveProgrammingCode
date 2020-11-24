#include <bits/stdc++.h>
#define lld unsigned int
#define MAX 1000009
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second

using namespace std;

int n,l,k=1,m,wynik;
int tab[MAX];
int tree[2100000];

void add(int wh, int maxi){
    wh+=k;
    tree[wh]=max(tree[wh],maxi);
    wh>>=1;
    while(wh>0){
        tree[wh]=max(tree[wh*2],tree[wh*2+1]);
        wh>>=1;
    }
}

int check(int a, int b){
    a+=k;
    b+=k;
    int wyn=max(tree[a],tree[b]);
    while(a/2!=b/2){
        if(a%2==0){
            wyn=max(wyn,tree[a+1]);
        }
        if(b%2==1){
            wyn=max(wyn,tree[b-1]);
        }
        a>>=1;
        b>>=1;
    }
    return wyn;

}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }

    while(k<1000000){
        k<<=1;
    }
    scanf("%d",&m);

    add(tab[0],1);
    tab[0]=1;
    for(int i=1;i<n;++i){
        add(tab[i],check(0,max(0,tab[i]-m))+1);
        tab[i]=check(0,max(0,tab[i]-m))+1;
    }
    for(int i=0;i<n;++i){
        wynik=max(wynik,tab[i]);
    }
    printf("%d",wynik);
    return 0;
}
