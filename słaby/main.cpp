#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 50009
#define MOD 1000000009

using namespace std;

int n;
int tab[MAX];
char a[1];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",a);
        tab[(int)a[0]]++;
    }
    for(int i=(int)'Z';i>=(int)'A';--i){
        if(tab[i]==1){
            printf("%c",i);
        }else if(tab[i]>0){
            printf("%c%d",(char)i,(int)tab[i]);
        }
    }
    return 0;
}
