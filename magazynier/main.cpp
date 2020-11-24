#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 109

using namespace std;

char s[MAX][MAX];
int h,szer;
vector<int> kraw[MAX*MAX];
int repy[MAX*MAX];
int ojciec[MAX*MAX];
int gleb[MAX*MAX];
int low[MAX*MAX];
int odw[MAX*MAX];
vector<pair<int,int> > kraw1[MAX*MAX][4];

int dfs(int from,int gl){
    odw[from]=1;
    gleb[from]=low[from]=gl;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            ojciec[kraw[from][i]]=from;
            low[from]=min(low[from],dfs(kraw[from][i],gl+1));
        }else if(kraw[from][i]!=ojciec[from]){
            low[from]=min(low[from],gleb[kraw[from][i]]);
        }
    }
    return low[from];
}

int Find(int x){
    if(x!=repy[x])repy[x] = Find(repy[x]);
    return repy[x];
}

void Union(int a, int b){
    int ra=Find(a);
    int rb=Find(b);
    if(ra!=rb){
        repy[rb]=ra;
    }
}

int czyw(int a, int b){
    if(Find(a)==Find(b)||(ojciec[Find(b)]==a&&low[Find(b)]==gleb[a])) return 1;
    return 0;
}

int main()
{
    scanf("%d%d",&h,&szer);
    for(int i=1;i<=h;++i){
        scanf("%s",&s[i][1]);
    }
    for(int i=1;i<=h;++i){
        for(int j=1;j<=szer;++j){
            if(s[i][j]!='S'&&s[i][j]){
                if(s[i+1][j]!='S'&&s[i+1][j]){
                    kraw[i*(szer+1)+j].pb((i+1)*(szer+2)+j);
                }
                if(s[i-1][j]!='S'&&s[i-1][j]){
                    kraw[i*(szer+1)+j].pb((i-1)*(szer+2)+j);
                }
                if(s[i][j+1]!='S'&&s[i][j+1]){
                    kraw[i*(szer+1)+j].pb((i)*(szer+2)+j+1);
                }
                if(s[i][j-1]!='S'&&s[i][j-1]){
                    kraw[i*(szer+1)+j].pb((i)*(szer+2)+j-1);
                }
            }
        }
    }
    for(int i=0;i<MAX*MAX;++i){
        repy[i]=i;
    }
    for(int i=0;i<MAX*MAX;++i){
        if(!odw[i]){
            ojciec[i]=i;
            dfs(i);
        }
    }
    for(int i=0;i<MAX*MAX;++i){
        if(low[i]<gleb[i]){
            Union(ojciec[i],i);
        }
    }
    for(int i=1;i<=h;++i){
        for(int j=1;j<=szer;++j){
            if(s[i][j]!='S'&&s[i][j]){
                if(s[i+1][j]!='S'&&s[i+1][j]){
                    kraw1[i*(szer+1)+j][0].pb(mp((i+1)*(szer+2)+j),0);
                }
                if(s[i-1][j]!='S'&&s[i-1][j]){
                    kraw1[i*(szer+1)+j][2].pb(mp((i-1)*(szer+2)+j),2);
                }
                if(s[i][j+1]!='S'&&s[i][j+1]){
                    kraw1[i*(szer+1)+j][3].pb(mp((i)*(szer+2)+j+1),3);
                }
                if(s[i][j-1]!='S'&&s[i][j-1]){
                    kraw1[i*(szer+1)+j].pb((i)*(szer+2)+j-1);
                }
            }
        }
    }
    return 0;
}
