#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2000009
#define lld long long

using namespace std;

lld n,a,wynik;
lld ile[MAX];
lld wiel[MAX];

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a);
        ile[a]++;
    }
    for(int i=1;i<MAX;++i){
        lld temp=0;
        for(int j=i*2;j<MAX;j+=i){
            if(ile[j])temp+=ile[j];
        }
        wiel[i]=temp;
    }
    for(int i=1;i<MAX;++i){
        wynik+=ile[i]*(ile[i]-1+wiel[i]);
    }
    printf("%lld",wynik);
    return 0;
}
