#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MAX 1000009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

lld m,n,a,kt,odp,wyn;
int bony[MAX];
lld kon[MAX];
int odw[MAX];
vector<lld> wynik;

int main()
{
    scanf("%lld",&m);
    for(int i=0;i<m;++i){
        scanf("%lld",&a);
        bony[a]=1;
    }
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a);
        odp=0;
        for(int j=1;j<=a;++j){
            kon[a]+=a;
            kt++;
            odp++;
            while(kon[a]<MAX&&odw[kon[a]]){
                kon[a]+=a;
            }

            if(kon[a]<MAX){
                odw[kon[a]]=1;
                if(bony[kon[a]]){
                    wyn++;
                    wynik.pb(kt);
                    bony[kon[a]]=0;
                }

            }else{
                kt+=(a-odp);
                break;
            }
        }
    }
    printf("%lld\n",wyn);
    for(int i=0;i<wynik.size();++i){
        printf("%lld\n",wynik[i]);
    }
    return 0;
}
