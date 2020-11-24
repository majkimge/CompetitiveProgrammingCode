#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define PIER 77

using namespace std;

int n,a,counter,kk=1;
vector<int> kraw[MAX];
vector<int> kraw1[MAX];
int deg[MAX];
int gleby[MAX];
int wiel[MAX];
int pre[MAX];               //preorder wierz i
int ktpre[MAX];             //jaki wierz jest w preorderze i
int ostg[MAX];            //ostatni grubol
int odw[MAX];
int ostgk[MAX];             //ktora kraw z grubola
int odwrot[MAX];
int kolej[MAX];
vector<int> grpref[MAX];   //prefy gruboli
int q;
char co[1];
int tree[270000];
int oczy[MAX];
int iled=-1;                 //ile drzwi przeszedl
int odw1[MAX];

void dod(int l,int p,int ile){
    l+=kk;
    p+=kk;
    if(l!=p){
        tree[l]+=ile;
        tree[p]+=ile;
    }else{
        tree[l]+=ile;
    }
    while(l/2!=p/2){
        if((l&1)==0){
            tree[l+1]+=ile;
        }
        if((p&1)==1){
            tree[p-1]+=ile;
        }
        l>>=1;
        p>>=1;
    }
}

void dfs1(int from,int ojc){
	odw1[from]=1;
	//oczy[from]=ojc;
	//cout<<"Y"<<from;
	for(int i=0;i<kraw1[from].size();++i){//cout<<"X"<<from<<" "<<kraw1[from][i];
		if(kraw1[from][i]==ojc){
			int j=i;
			kraw[from].pb(kraw1[from][j%(kraw1[from].size())]);
			++j;
			while(kraw1[from][(j)%(kraw1[from].size())]!=ojc){
				kraw[from].pb(kraw1[from][j%kraw1[from].size()]);

				++j;
			}
		}else if(!odw1[kraw1[from][i]]){
			dfs1(kraw1[from][i],from);
		}
	}

}

int dfs(int from,int gleb,int ktg, int ktk,int ojc,int kl){
    //cout<<"Z"<<from;
    gleby[from]=gleb;
    odw[from]=1;
    ostg[from]=ktg;
    ostgk[from]=ktk;
    pre[from]=counter;
    ktpre[counter]=from;
    kolej[from]=kl;
    counter++;
    oczy[from]=ojc;
    iled++;
    dod(pre[from],pre[from],iled);
    int wyn=0;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            if(deg[from]>PIER||from==0){
                wyn+=dfs(kraw[from][i],gleb+1,from,i,from,i);
            }else{
                wyn+=dfs(kraw[from][i],gleb+1,ktg,ktk,from,i);
            }

        }
    }
    wiel[from]=wyn+1;
    iled++;
    return wyn+1;
}

int check(int gdzie){
    gdzie+=kk;
    int wyn=0;
    while(gdzie>0){
        wyn+=tree[gdzie];
        gdzie>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    while(kk<n){
        kk<<=1;
    }
    //kraw1[0].pb(0);
    for(int i=1;i<=n;++i){
        scanf("%d",&deg[i]);//cout<<i;
        for(int j=0;j<deg[i];++j){
            scanf("%d",&a);
            if(a==-1){
                kraw1[i].pb(0);
                kraw1[0].pb(i);
                kraw[0].pb(i);
            }else{
                kraw1[i].pb(a);
            }
            //cout<<a;

        }
    }//cout<<"F";

    dfs1(0,-1);
    /*for(int i=1;i<=n;++i){
		for(int j=0;j<kraw[i].size();++j){
			cout<<kraw[i][j]<<" ";
		}
		cout<<endl;
	}*/


    dfs(0,0,0,0,0,0);
    for(int i=1;i<=n;++i){
        //dod(i,i,i);
    }

    for(int i=1;i<=n;++i){
        if(deg[i]>PIER){
            grpref[i].pb(0);
            grpref[i].pb(2*wiel[kraw[i][1]]);
            for(int j=2;j<kraw[i].size();++j){
                grpref[i].pb(2*wiel[kraw[i][j]]+grpref[i][j-1]);
            }
        }
    }

    scanf("%d",&q);
    for(int i=0;i<q;++i){
        scanf("%s",co);
        scanf("%d",&a);
        if(co[0]=='z'){
            if(deg[a]<=PIER){
                if(odwrot[a]==0){
                    int sumix=0;
                    for(int j=1;j<kraw[a].size();++j){
                        sumix+=2*wiel[kraw[a][j]];
                        dod(pre[kraw[a][j]],pre[kraw[a][j]]+wiel[kraw[a][j]]-1,2*wiel[a]-2-sumix-(sumix-2*wiel[kraw[a][j]]));
                    }

                }else{
                    int sumix=0;
                    for(int j=1;j<kraw[a].size();++j){
                        sumix+=2*wiel[kraw[a][j]];
                        dod(pre[kraw[a][j]],pre[kraw[a][j]]+wiel[kraw[a][j]]-1,-2*wiel[a]+2+sumix+(sumix-2*wiel[kraw[a][j]]));
                    }
                }
            }
            odwrot[a]=odwrot[a]^1;
        }else{
            int wynik=check(pre[a]);
            int gdziej=ostg[a];
            int kgdzie=ostgk[a];
            while(gdziej!=0){
                //cout<<gdziej;
                if(odwrot[gdziej]){
                    //cout<<"X";
                    wynik+=grpref[gdziej][grpref[gdziej].size()-1]-grpref[gdziej][kgdzie]-grpref[gdziej][kgdzie-1];
                }
                kgdzie=ostgk[gdziej];
                gdziej=ostg[gdziej];
            }
            printf("%d\n",wynik);
        }
    }
    return 0;
}

/*
5
1 3
1 4
3
4 5 1
3 -1 2 3
1 3
5
*/
