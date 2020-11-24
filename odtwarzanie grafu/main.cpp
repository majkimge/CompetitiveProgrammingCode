#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009

using namespace std;

lld n,a,b,przyps;
lld sumy[MAX],st[MAX];
set<pair<lld,lld> >q;
vector<pair<lld,lld> >v;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld%lld",&st[i],&sumy[i]);
        q.insert(mp(st[i],i));
    }
    while(!q.empty()){
        pair<lld,lld> temp=*q.begin();
        //cout<<temp.f<<" "<<temp.s<<endl;
        if(temp.f==0){
            q.erase(q.begin());
        }else if(temp.f==1){
            q.erase(q.begin());

            st[sumy[temp.s]]--;
            sumy[sumy[temp.s]]-=temp.s;
            if(st[sumy[temp.s]]>=0&&sumy[sumy[temp.s]]>=0){
                set<pair<lld,lld> >::iterator temp1;
                temp1=q.find(mp(st[sumy[temp.s]]+1,sumy[temp.s]));
                q.erase(temp1);
                pair<lld,lld> temp2=*temp1;
                temp2.f--;
                //cout<<temp1.f;
                q.insert(temp2);
                v.pb(mp(sumy[temp.s],temp.s));
            }else{
                //cout<<"D";
                przyps=1;
                break;
            }
        }else{
            przyps=1;
            break;
        }
    }
    if(przyps){
        printf("NIEMOZLIWE");
    }else{
        printf("OK\n%d\n",v.size());
        for(int i=0;i<v.size();++i){
            printf("%lld %lld\n",v[i].f,v[i].s);
        }
    }
    return 0;
}
