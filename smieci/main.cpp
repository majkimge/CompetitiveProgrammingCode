#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define MAX 1000009

using namespace std;

int n,m,a,b,c,d,wyn,kto=1,czyost=1,ilek,iled;
vector<pii> kraw[MAX];
int odw[MAX];
vector<int> wyniki[MAX*5];
int odwkraw[MAX];
int todwkraw[MAX];
vector<pair<int,pii> >doz;
int wych[MAX];
vector<int> temp;
int ziom[MAX];

int dfs(int kt,int from){
    odw[from]=kt;
    temp.pb(from);
    ziom[from]=kt;
    for(int i=0;i<kraw[from].size();++i){
        if(odwkraw[kraw[from][i].s]){
            swap(kraw[from][i],kraw[from][kraw[from].size()-1]);
            kraw[from].pop_back();
            --i;
        }else{
            if(odw[kraw[from][i].f]==kt&&ziom[kraw[from][i].f]==kt&&todwkraw[kraw[from][i].s]<kt){
                odwkraw[kraw[from][i].s]=1;
                temp.pb(kraw[from][i].f);
                wyniki[wyn].pb(temp.size()-1);
                ilek+=temp.size()-1;
                for(int j=0;j<temp.size();++j){
                    wyniki[wyn].pb(temp[j]);
                }
                temp.clear();
                wyn++;
                return 1;
            }else if(todwkraw[kraw[from][i].s]<kt){
                todwkraw[kraw[from][i].s]=kt;
                if(dfs(kt,kraw[from][i].f)){
                    odwkraw[kraw[from][i].s]=1;
                    return 1;
                }
            }
        }
    }
    temp.pop_back();
    ziom[from]=0;
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(c!=d&&a!=b){
            kraw[a].pb(mp(b,i));
            kraw[b].pb(mp(a,i));
            doz.pb(mp(i,mp(a,b)));
            iled++;
            //doz.pb(mp(i*2+1,mp(b,a)));
        }else if(c!=d&&a==b){
            wyniki[wyn].pb(1);
            wyniki[wyn].pb(a);
            wyniki[wyn].pb(a);
            wyn++;
        }
    }
    for(int i=0;i<doz.size();++i){
        if(!odwkraw[doz[i].f]){
            int czyost=dfs(kto,doz[i].s.f);
            kto++;

            if(!czyost)break;
        }
    }
    if(!czyost||ilek!=iled){
        printf("NIE");
    }else{
        printf("%d\n",wyn);
        for(int i=0;i<wyn;++i){
            for(int j=0;j<wyniki[i].size();++j){
                printf("%d ",wyniki[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
