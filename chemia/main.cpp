#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,m1,a,b,wyn,ile;

map<pair<int,int>,int>m;

vector<pair<int,int> >v;

int main()
{
    scanf("%d",&n);
    scanf("%d",&m1);
    wyn=m1;
    for(int i=0;i<m1;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        v.pb(mp(a,b));
        m[mp(a,b)]=1;
    }
    int czy=1;
    while(czy){
        czy=0;
        for(int i=0;i<v.size();++i){
        for(int j=0;j<v.size();++j){
            if(i!=j){
                //cout<<v[i].s<<v[j].f<<endl;
                if(v[i].s==v[j].f&&m[mp(v[j].s,v[i].f)]==0){
                    v.pb(mp(v[j].s,v[i].f));

                    ile++;
                    wyn++;
                    m[mp(v[j].s,v[i].f)]=1;
                    czy=1;
                }
            }
        }
    }
    }
    printf("%d",wyn);
    return 0;
}
