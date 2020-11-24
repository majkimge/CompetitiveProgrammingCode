#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>
#define piii pair<pii,int>

using namespace std;

int t,n,s,m,a,b,star;

vector<int> kraw[MAX];
int odw[MAX];
int odwied[MAX];
lld wynik,wyn,dodad;
int gl[MAX];
int czyk[MAX];
int ojc[MAX],ilek;
priority_queue<pii> q;

void dfs(int gleb, int gdz, int oczy){
    odw[gdz]=1;
    //cout<<gdz;
    gl[gdz]=gleb;
    ojc[gdz]=oczy;
    for(int i=0;i<kraw[gdz].size();++i){
        //if(gdz>42000)cout<<kraw[gdz].size();
        if(!odw[kraw[gdz][i]]){
            dfs(gleb+1,kraw[gdz][i],gdz);
        }
    }
}




int main()
{
    scanf("%d",&t);
    for(int xdd=0;xdd<t;++xdd){
        scanf("%d%d%d",&n,&s,&m);
        //cout<<m;
        for(int i=1;i<=n;++i){
            odw[i]=gl[i]=czyk[i]=ojc[i]=odwied[i]=0;
            kraw[i].clear();
        }
        while(!q.empty()){
            q.pop();
        }
        wyn=wynik=0;
        ilek=0;
        for(int i=0;i<n-1;++i){
            scanf("%d%d",&a,&b);
            kraw[a].pb(b);
            kraw[b].pb(a);
            //kraw[i+1].pb(i+2);
            //kraw[i+2].pb(i+1);
        }



        dfs(0,m,0);//cout<<"D";
        int ter=s;

        odwied[m]=1;
        ilek++;
        while(ter!=m){
            odwied[ter]=1;
            ilek++;
            ter=ojc[ter];
        }
        for(int i=1;i<=n;++i){
            if(!odwied[i]){
                q.push(mp(gl[i],i));
            }

        }
        wynik=gl[s];
        if(!q.empty())wynik+=q.top().f;

        dodad=gl[s];
        //cout<<wynik;

        while(!q.empty()){
            wyn=dodad;
            int akt=q.top().s;
            //cout<<akt;
            while(!odwied[akt]){
                odwied[akt]=1;
                wyn+=2;
                dodad+=2;
                akt=ojc[akt];
            }
            while(!q.empty()&&odwied[q.top().s])q.pop();
            if(!q.empty())wyn+=q.top().f;

            if(wyn<wynik){
                wynik=wyn;
            }
        }
        printf("%lld\n",wynik);
    }
    return 0;
}

/*
100
7 1 1
1 2
2 3
3 4
4 5
5 6
5 7

11 2 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
5 9
9 10
10 11

*/
