#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define lld long long
using namespace std;

lld n,k,a;
priority_queue<lld> q;
lld wyny[MAX];
lld monety[MAX];
pair<lld,lld> ryc[MAX];
vector<lld>temp;

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(int i=0;i<n;++i){
        scanf("%lld",&a);
        ryc[i]=mp(a,i);
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&a);
        monety[i]=a;
    }
    sort(ryc,ryc+n);
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            if(!q.empty()){
                lld tt=q.top();
                wyny[ryc[i].s]+=tt;
                temp.pb(tt);
                q.pop();
            }
        }
        wyny[ryc[i].s]+=monety[ryc[i].s];
        for(int j=0;j<temp.size();++j){
            q.push(temp[j]);
        }
        q.push(monety[ryc[i].s]);
        temp.clear();
    }
    for(int i=0;i<n;++i){
        printf("%lld ",wyny[i]);
    }
    return 0;
}
