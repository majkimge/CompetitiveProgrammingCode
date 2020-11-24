#include <bits/stdc++.h>
#define lld long long
#define ld double
#define MAX 1000
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n;
lld wand[MAX];
lld box[MAX];
bool tool=1;
int main()
{
    scanf("%lld",&n);

    for(int i=0;i<n;++i){
        scanf("%lld",&wand[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&box[i]);
    }
    sort(wand,wand+n);
    sort(box,box+n);
    for(int i=0;i<n;++i){
        if(wand[i]>box[i]){
            tool=0;
        }
    }
    if(tool){
        printf("DA");
    }else{
        printf("NE");
    }
    return 0;
}
