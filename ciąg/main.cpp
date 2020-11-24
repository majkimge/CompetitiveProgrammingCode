#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define pii pair<lld,lld>
#define pdd pair<double,double>
#define C 1000

using namespace std;

int n;
lld tab[MAX],sum;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    for(int i=0;i<n-1;++i){
        sum+=max(tab[i],tab[i+1]);
    }
    printf("%lld",sum);
    return 0;
}
