#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 4002
#define MOD 1000000009
#define pii pair<int,int>

using namespace std;

int t,n,ile=1;
pii a,b;
char s[309][309];
vector<int> kraw[MAX*MAX];
vector<int> kraw1[MAX*MAX];
queue<pair<pii,int> > q;
vector<pii> gleby[MAX];

int dist(pii xx, pii yy){
    return abs(xx.f-yy.f)+abs(xx.s-yy.s);
}

int robgraf(){
    while(!q.empty()){
        pii ter=q.front().f;
        int ind=q.front().s;
        q.pop();
        int tdist=dist(ter,b);
        if(dist(mp(ter.f,ter.s+1),b)<tdist){
            kraw[ile].pb(ile+1);
            kraw1[ile+1].pb(ile);
            ++ile;
            q.push(mp(ter.f,ter.s+1),ile);
            gleby[dist(q.front().f]
        }
        if(dist(mp(ter.f,ter.s-1),b)<tdist){
            kraw[ile].pb(ile+1);
            kraw1[ile+1].pb(ile);
            ++ile;
            q.push(mp(ter.f,ter.s-1),ile);
        }
        if(dist(mp(ter.f+1,ter.s),b)<tdist){
            kraw[ile].pb(ile+1);
            kraw1[ile+1].pb(ile);
            ++ile;
            q.push(mp(ter.f+1,ter.s),ile);
        }
        if(dist(mp(ter.f-1,ter.s),b)<tdist){
            kraw[ile].pb(ile+1);
            kraw1[ile+1].pb(ile);
            ++ile;
            q.push(mp(ter.f-1,ter.s),ile);
        }

    }
}

int bfs(){

}

int main()
{
    scanf("%d",&t);
    for(int xdd=0;xdd<t;++xdd){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%s",&s[i]);
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(s[i]=='A')a=mp(i,j);
                if(s[i]=='B')b=mp(i,j);
            }
        }
        if(dist(a,b)){
            printf("A\n");
            break;
        }
        q.push(a);
        robgraf();
    }
    return 0;
}
