#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 70009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,a,b,q,c,a1,b1;
vector<int> v[MAX];
int LCA[MAX][20];
int odw[MAX];
int odw1[MAX];
int gleb[MAX];
int wyny[MAX];
set<pair<int,int> > maxi[MAX];
set<pair<int,int> > mini[MAX];
set<pair<int,int> >maxina;
set<pair<int,int> >minina;
int kraw[MAX];
int skoje[MAX];
vector<int>zap[MAX];
int ile[MAX];
vector<pair<pair<int,int>,int> >krawy;


char co;

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

void dfs1(int from){
    odw1[from]=1;
    if(v[from].size()==1&&LCA[from][0]!=0){

        set<pair<int,int> >::iterator kt=maxi[from].begin();

        while(kt!=maxi[from].end()){

            maxina.insert(*kt);
            //cout<<"XD";
            kt++;
        }


        //if(!maxina.empty())cout<<(*--maxina.end()).f;
        if(!maxina.empty()){
            zap[(*maxina.begin()).s].pb(from);
        }
        //cout<<"A"<<(*--maxina.end()).f<<from;

        kt=mini[from].begin();

        while(kt!=mini[from].end()){
            minina.insert(*kt);
            kt++;
        }

        if(!minina.empty()){
            zap[(*--minina.end()).s].pb(from);
        }

        if(!minina.empty()){
            wyny[from]=(*--minina.end()).f;
        }else if(!maxina.empty()){
            wyny[from]=(*maxina.begin()).f;
        }else{
            wyny[from]=10;
        }
    }else{

        for(int i=0;i<v[from].size();++i){
            if(!odw1[v[from][i]]){
                dfs1(v[from][i]);
            }
        }
        set<pair<int,int> >::iterator kt=maxi[from].begin();

        while(kt!=maxi[from].end()){
            if((*kt).f<0){
                //cout<<"K";
                maxina.erase(mp(-(*kt).f,(*kt).s));
            }else{
                maxina.insert(*kt);
            }
            kt++;
        }//cout<<"A";



         //if(!maxina.empty())
         if(!maxina.empty()){
            zap[(*maxina.begin()).s].pb(from);
            //cout<<"C"<<(*--maxina.end()).f;
         }


        kt=mini[from].begin();

        while(kt!=mini[from].end()){
            if((*kt).f<0){
                minina.erase(mp(-(*kt).f,(*kt).s));
            }else{
                minina.insert(*kt);
            }
            kt++;
        }

        if(!minina.empty()){

        zap[(*--minina.end()).s].pb(from);
        }
        if(!minina.empty()){
            wyny[from]=(*--minina.end()).f;
        }else if(!maxina.empty()){
            wyny[from]=(*maxina.begin()).f;
        }else{
            wyny[from]=10;
        }
    }
}

bool skoj(int from){
    for(int i=0;i<zap[from].size();++i){
        if(!skoje[zap[from][i]]){
            skoje[zap[from][i]]=from;
            wyny[zap[from][i]]=ile[from];
            return 1;
        }
    }
    for(int i=0;i<zap[from].size();++i){

            if(skoj(skoje[zap[from][i]])) return 1;

    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d",&a1);
        scanf("%d",&b1);
        v[a1].pb(b1);
        v[b1].pb(a1);
    }
    dfs(1,0,0);
    for(int i=1;i<20;++i){
        for(int j=1;j<=n;++j){
            LCA[j][i]=LCA[LCA[j][i-1]][i-1];
        }
    }
    scanf("%d",&q);
    for(int z=0;z<q;++z){
            //cout<<"A";
        scanf(" %c",&co);
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        int a1=a;
        int b1=b;
        krawy.pb(mp(mp(a,b),0));

        if(gleb[a]>gleb[b]){
            for(int i=19;i>=0;--i){
                if(gleb[LCA[a1][i]]>=gleb[b]){
                    a1=LCA[a1][i];
                }
            }

        }else if(gleb[a]<gleb[b]){
            for(int i=19;i>=0;--i){
                if(gleb[LCA[b1][i]]>=gleb[a]){
                    b1=LCA[b1][i];
                }
            }
        }
        int lc=a1;
        for(int i=19;i>=0;--i){
                if(LCA[a1][i]!=LCA[b1][i]){
                    b1=LCA[b1][i];
                    a1=LCA[a1][i];
                }
            }
            if(a1!=b1){
                lc=max(LCA[a1][0],1);
            }

        //cout<<lc;
        if(co=='M'){
            //cout<<c;
            if(a!=lc) maxi[a].insert(mp(c,z));
            if(b!=lc)maxi[b].insert(mp(c,z));
            //cout<<"C"<<(*maxi[b].begin()).f;
            maxi[lc].insert(mp(-c,z));
        }
        if(co=='m'){
            if(a!=lc) mini[a].insert(mp(c,z));
            if(b!=lc) mini[b].insert(mp(c,z));
            mini[lc].insert(mp(-c,z));
        }
        ile[z]=c;
    }

    dfs1(1);
    //cout<<"B";
    /*for(int i=0;i<q;++i){
        for(int j=0;j<zap[i].size();++j){
            cout<<"D"<<zap[i][j]<<i;
        }
    }*/
    for(int i=0;i<q;++i){
        skoj(i);
    }

    for(int i=2;i<=n;++i){
        printf("%d %d %d\n",i,LCA[i][0],wyny[i]);
    }
    return 0;
}
/*4
1 2
2 3
3 4
2
M 1 2 1
M 2 3 100
*/
