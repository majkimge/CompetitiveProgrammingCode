#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,a,b,c,d,x,y;
map<pair<int,int>,int >m;
vector<int> v[MAX];
int kol[MAX];
vector<int> koly[MAX];
int ile[MAX];
int wyn;
int LCA[MAX][30];
int odw[MAX];
int odw1[MAX];
int gleb[MAX];

void dfs(int from,int z,int gl){
    LCA[from][0]=z;
    odw[from]=1;
    gleb[from]=gl;
    for(int i=0;i<v[from].size();++i){
        if(!odw[v[from][i]]){
            dfs(v[from][i],from,gl+1);

        }
    }
}

int dfs1(int from){
    odw1[from]=1;

    if(v[from].size()==1&&LCA[from][0]!=0){//cout<<from;
        if(ile[from]==0){
            wyn++;

        }
        return ile[from];
    }
    int comam=0;
    for(int i=0;i<v[from].size();++i){
        if(!odw1[v[from][i]]){
            comam+=dfs1(v[from][i]);
        }


    }
    comam+=ile[from];
    //cout<<"B"<<from<<comam;
    if(!comam&&from!=1){
        //cout<<from;
        wyn++;
    }
    return comam;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        scanf("%d",&y);
    }
    for(int i=1;i<=n-2;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        if(m[mp(a,b)]){
            v[i].pb(m[mp(a,b)]);
            v[m[mp(a,b)]].pb(i);


        }m[mp(a,b)]=i;
            m[mp(b,a)]=i;
        if(m[mp(c,b)]){
            v[i].pb(m[mp(c,b)]);
            v[m[mp(c,b)]].pb(i);


        }m[mp(c,b)]=i;
            m[mp(b,c)]=i;

        if(m[mp(c,a)]){
            v[i].pb(m[mp(c,a)]);
            v[m[mp(c,a)]].pb(i);


        }m[mp(c,a)]=i;
            m[mp(a,c)]=i;
       kol[i]=d;
        koly[d].pb(i);


    }
    for(int i=1;i<=n-2;++i){
        for(int j=0;j<v[i].size();++j){
            //cout<<v[i][j];
        }
        //cout<<endl;
    }
    dfs(1,0,0);
    for(int i=1;i<20;++i){
        for(int j=1;j<=n;++j){
            LCA[j][i]=LCA[LCA[j][i-1]][i-1];
        }
    }
    for(int i=0;i<MAX;++i){
            if(!koly[i].empty()){
        int mgleb=INF;
        for(int j=0;j<koly[i].size();++j){
            //cout<<i<<" "<<koly[i][j];
            mgleb=min(mgleb,gleb[koly[i][j]]);
        }
        //cout<<mgleb;
        for(int j=0;j<koly[i].size();++j){
            ile[koly[i][j]]++;
            if(gleb[koly[i][j]]>mgleb){
            for(int z=19;z>=0;--z){
                if(gleb[LCA[koly[i][j]][z]]>=mgleb){
                    koly[i][j]=LCA[koly[i][j]][z];
                }
            }

        }
        }

        int lc=koly[i][0];
        for(int j=1;j<koly[i].size();++j){

        for(int z=19;z>=0;--z){
                if(LCA[lc][z]!=LCA[koly[i][j]][z]){
                    lc=LCA[lc][z];
                    koly[i][j]=LCA[koly[i][j]][z];
                }
            }
            if(lc!=koly[i][j]){
                lc=LCA[lc][0];
            }

        lc=max(lc,1);

        }//cout<<"A"<<ile[3];
        ile[lc]-=koly[i].size();
    }
}
    //cout<<ile[3];
    LCA[1][0]=0;
    dfs1(1);
    printf("%d",wyn);

    return 0;
}
