#include <bits/stdc++.h>
#define lld long long
#define MAX 300009
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;

map<lld,map<lld,lld> >row;
vector<pair<lld,lld> >temp;
lld n,a,b,c,wyn=1,cnt=2;
lld tr[MAX];

int main()
{
    scanf("%lld",&n);
    tr[1]=1;
    for(int i=2;i<MAX;++i){
        tr[i]=tr[i-1]+i;
        tr[i]%=MOD;
    }
    lld ccc=3;
    for(int i=0;i<ccc;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        //wyn+=tr[cnt]-row[a][b];
        //wyn%=MOD;
        if(row[a][b]>0){
            temp.pb(mp(a,b));
            ccc++;
        }else{
            row[a][b]++;
        }

    }

    for(int i=3;i<n;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        if(row[a][b]>0){
            temp.pb(mp(a,b));
        }else{
        wyn+=tr[cnt];
        wyn%=MOD;

        row[a][b]++;
        cnt++;
        }

    }
    for(int i=0;i<temp.size();++i){
            //cout<<tr[cnt-row[temp[i].f][temp[i].s]];
        wyn+=tr[cnt-row[temp[i].f][temp[i].s]];
        wyn%=MOD;

        row[temp[i].f][temp[i].s]++;
        cnt++;
    }
    printf("%lld",wyn);
    return 0;
}
