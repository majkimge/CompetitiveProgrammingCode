#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

lld n,wynik;
lld tab[MAX][3];
lld xyz[3];
priority_queue<lld > q[3][3];

int check(int wier){
    if(tab[wier][0]>=tab[wier][1]&&tab[wier][0]>=tab[wier][2]){
        return 0;
    }else if(tab[wier][1]>=tab[wier][0]&&tab[wier][1]>=tab[wier][2]){
        return 1;
    }else{
        return 2;
    }



}

int main()
{
    scanf("%lld",&xyz[0]);
    scanf("%lld",&xyz[1]);
    scanf("%lld",&xyz[2]);
    n=xyz[0]+xyz[1]+xyz[2];
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[0]);
        scanf("%lld",&tab[1]);
        scanf("%lld",&tab[2]);
        int wiel=check(i);
        if(xyz[wiel]){
            wynik+=tab[wiel];
            xyz[wiel]--;
            q[(wiel+1)%3][wiel].push(tab[(wiel+1)%3]-tab[wiel]);
            q[(wiel-1+3)%3][wiel].push(tab[(wiel-1+3)%3]-tab[wiel]);
        }else{
            lld maxi=0;
            lld maxig=0;
            if(xyz[(wiel+1)%3]){
                if(q[(wiel+1)%3][wiel].top()>=tab[(wiel+1)%3]-tab[wiel]){
                    maxi=q[(wiel+1)%3][wiel].top();
                    maxig=0;
                }else{
                    maxi=tab[(wiel+1)%3]-tab[wiel];
                    maxig=1;
                }

            }
            if(xyz[(wiel-1+3)%3]){
                if(q[(wiel-1+3)%3][wiel].top()>=tab[(wiel-1+3)%3]-tab[wiel]){
                    maxi=q[(wiel-1+3)%3][wiel].top();
                    maxig=2;
                }else{
                    maxi=tab[(wiel-1+3)%3]-tab[wiel];
                    maxig=3;
                }
            }
            if(maxig==0){
                wynik+=tab[wiel]+q[(wiel+1)%3][wiel].top();
                xyz[(wiel+1)%3]--;
                q[(wiel+1)%3][wiel].pop();
                q[(wiel+1)%3][wiel].push(tab[(wiel+1)%3]-tab[wiel]);
                q[(wiel-1+3)%3][wiel].push(tab[(wiel-1+3)%3]-tab[wiel]);
            }
        }
    }
    return 0;
}
