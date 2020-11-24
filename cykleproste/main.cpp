#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 1000000000000000

using namespace std;

int l,n,m,a,b,przyps,wynik;
int odw[MAX];
int gleby[MAX];
vector<int> kraw[MAX];

int dfs(int from,int gleb,int oczy){
    odw[from]=1;
    gleby[from]=gleb;
    int wyn=0;
    int co=-1;
    //cout<<from<<" ";
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            int temp=dfs(kraw[from][i],gleb+1,from);
            if(temp!=-1){

                if(temp==from){
                    wynik++;
                }else{
                    //cout<<kraw[from][i];
                    wyn++;
                    co=temp;
                }
            }
        }else{
            if(gleby[kraw[from][i]]<gleb&&kraw[from][i]!=oczy){
                //cout<<"X"<<from<<" "<<kraw[from][i]<<endl;
                wyn++;
                co=kraw[from][i];
            }
        }
    }
    if(wyn>1){
        //cout<<from;
        przyps=1;
    }
    return co;
}

int main()
{
    scanf("%d",&l);
    for(int xx=0;xx<l;++xx){
        scanf("%d",&n);
        scanf("%d",&m);
        przyps=0;
        wynik=0;
        for(int i=0;i<n;++i){
            kraw[i].clear();
            odw[i]=0;
            gleby[i]=0;
        }
        for(int i=0;i<m;++i){
            scanf("%d",&a);
            scanf("%d",&b);
            kraw[a].pb(b);
            kraw[b].pb(a);
        }
        for(int i=0;i<n;++i){
            if(!odw[i]){
                dfs(i,0,-1);
            }
        }

        if(przyps){
            printf("NIE\n");
        }else{
            printf("%d\n",wynik);
        }
    }
    return 0;
}
/*
7 9
0 1
1 2
2 0
0 4
4 3
3 0
5 6
3 6
3 5
*/
