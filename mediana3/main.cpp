#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000009

using namespace std;

int n,co,suma;
int tab[909];
bitset<2097152> b1;


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        suma+=tab[i];
    }
    sort(tab,tab+n);
    b1[0]=1;
    for(int i=0;i<n;++i){
        b1=(b1|(b1<<tab[i]));
    }
    for(int i=(suma+1)/2;i<=suma;++i){
        if(b1[i]){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
