#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 250009

using namespace std;

int n;
lld dost[MAX],kli[MAX];
priority_queue<pair<lld,lld> >q;
lld zost;
vector<lld> wyn;

int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;++i){
        scanf("%lld",&dost[i]);
    }

    for(int i=0;i<n;++i){
        scanf("%lld",&kli[i]);
    }

    for(int i=0;i<n;++i){
        zost+=dost[i];
        if(zost>=kli[i]){
            q.push(mp(kli[i],i+1));
            zost-=kli[i];
        }else{
            if(kli[i]<q.top().f){
                zost+=q.top().f-kli[i];
                q.pop();
                q.push(mp(kli[i],i+1));

            }
        }
    }
    while(!q.empty()){
        wyn.pb(q.top().s);
        q.pop();
    }
    sort(wyn.begin(),wyn.end());
    printf("%d\n",wyn.size());
    for(int i=0;i<wyn.size();++i){
        printf("%d ",wyn[i]);
    }
    return 0;
}
