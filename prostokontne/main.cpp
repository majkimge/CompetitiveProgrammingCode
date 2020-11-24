#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,wyn;
lld zroby[MAX];
lld ilex[MAX];
lld iley[MAX];
pair<lld,lld> wsp[MAX];
lld a,b;

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        wsp[i]=mp(a,b);
        ilex[a]++;
        iley[b]++;
    }
    for(int i=0;i<n;++i){
        //if(!zroby[wps[i].f]){
            wyn+=(ilex[wsp[i].f]-1)*(iley[wsp[i].s]-1);
            //zroby[wps[i].f]
        //}
    }
    printf("%lld",wyn);
    return 0;
}
