#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009

using namespace std;

int n,m,a,b;
int deg[MAX];
vector<pair<int,int> >kraw[MAX];
int odw[MAX];
priority_queue<pair<pair<int,int>,int > >q;
priority_queue<pair<int,int> >xd;
int wyny[MAX];
int wynik;
int ilew[MAX];
int lilew[MAX];

int rob(int from,int dok){
    odw[from]=1;
    if(wyny[from]>dok)return 0;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i].f]){
            deg[kraw[from][i].f]--;
            xd.push(mp(-deg[kraw[from][i].f],kraw[from][i].f));
            q.push(mp(mp(deg[kraw[from][i].f],kraw[from][i].s),kraw[from][i].f));
        }
    }
    while(!q.empty()){
        if(wyny[from]<dok){
            wyny[from]++;
            if(q.top().f.s<0){
                ilew[-q.top().f.s]=0;
            }else{
                ilew[q.top().f.s]=1;
            }
        }else{
            wyny[q.top().s]++;
            //cout<<q.top().f;
            if(q.top().f.s<0){
                ilew[-q.top().f.s]=1;
            }else{
                ilew[q.top().f.s]=0;
            }
        }
        q.pop();
    }
    return 1;
}

int check(int dok){
    int sum=0;
    for(int i=1;i<=n;++i){
        sum+=min(dok,deg[i]);
    }
    if(sum<m)return 0;
    return 1;
}

int bin(){
    int l=0;
    int p=m;
    int s=(l+p)/2;
    while(l<=p){
        s=(l+p)/2;
        for(int i=1;i<=n;++i){
            wyny[i]=0;
            odw[i]=0;
            deg[i]=kraw[i].size();
        }
        if(check(s)){
            for(int i=0;i<m;++i){
                lilew[i]=ilew[i];

            }
            wynik=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    return wynik;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(mp(b,i));
        kraw[b].pb(mp(a,-i));
        //deg[a]++;
        //deg[b]++;
    }
    printf("%d\n",bin());
    for(int i=0;i<m;++i){
        printf("%d\n",lilew[i]);
    }
    return 0;
}
