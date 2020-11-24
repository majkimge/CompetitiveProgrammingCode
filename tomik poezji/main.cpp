#include <bits/stdc++.h>
#define MAX 1000009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>

using namespace std;

int n,s,a,ter;
vector<int> v[MAX];
priority_queue<pii> q;
vector<int> wyny;
int wynik;

int main()
{
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        v[(a+1)%s].pb(i+1);
    }
    for(int i=0;i<s;++i){
        if(v[i].size()>0)q.push(mp(v[i].size(),i));
    }
    while(!q.empty()){
        pii pier=q.top();
        pii sec=mp(-1,-1);
        q.pop();
        if(!q.empty()){
            sec=q.top();
            q.pop();
        }
        if((pier.s+ter)%s!=s-1){
            pier.f--;
            ter+=pier.s;
            ter%=s;
            wyny.pb(v[pier.s][v[pier.s].size()-1]);
            v[pier.s].pop_back();
            if(pier.f){
                q.push(pier);
            }
            if(sec.f>0)q.push(sec);

        }else if(sec.f>=0){
            sec.f--;
            ter+=sec.s;
            ter%=s;
            wyny.pb(v[sec.s][v[sec.s].size()-1]);
            v[sec.s].pop_back();
            if(sec.f){
                q.push(sec);
            }
            q.push(pier);
        }else{
            pier.f--;

            ter=0;
            wyny.pb(v[pier.s][v[pier.s].size()-1]);
            v[pier.s].pop_back();
            if(pier.f){
                q.push(pier);
            }
            if(sec.f>0)q.push(sec);
            if(pier.f<=0&&sec.f<=0)wynik--;
            wynik++;
        }
    }
    printf("%d\n",wynik);
    for(int i=0;i<n;++i){
        printf("%d ",wyny[i]);
    }
    return 0;
}
