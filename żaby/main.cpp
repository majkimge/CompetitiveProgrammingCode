#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define pii pair<int,int>

using namespace std;

vector<int> kraw[MAX];
int odl[MAX];
int odw[MAX];
int p1,p2,k1,k2,wid,len,n,x,y,rep[MAX],pocz,kon;
queue<pair<int,int> > q;

vector<int> zodl[MAX];


void bfs(){
    while(!q.empty()){
        int ter=q.front().f;
        int od=q.front().s;
        q.pop();
        odw[ter]=1;
        odl[ter]=min(odl[ter],od);
        for(int i=0;i<kraw[ter].size();++i){
            if(!odw[kraw[ter][i]]){
                q.push(mp(kraw[ter][i],odl[ter]+1));
                odw[kraw[ter][i]]=1;
            }
        }
    }
}

int main()
{
    scanf("%d%d",&wid,&len);
    scanf("%d%d%d%d",&p1,&p2,&k1,&k2);

    for(int i=1;i<=len;++i){
        for(int j=1;j<=wid;++j){
            if(i!=1){
                kraw[(i-1)*wid+j].pb((i-2)*wid+j);
            }
            if(j!=1){
                kraw[(i-1)*wid+j].pb((i-1)*wid+j-1);
            }
            if(i!=len){
                kraw[(i-1)*wid+j].pb((i)*wid+j);
            }
            if(j!=wid){
                kraw[(i-1)*wid+j].pb((i-1)*wid+j+1);
            }
        }
    }

    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        odw[(y-1)*wid+x]=1;
        q.push(mp((y-1)*wid+x,0));
    }

    for(int i=1;i<MAX;++i){
        rep[i]=i;
        odl[i]=MAX;
    }

    bfs();

    for(int i=1;i<=len;++i){
        for(int j=1;j<=wid;++j){
            cout<<endl<<odl[(i-1)*wid+j];
        }
    }
    return 0;
}
