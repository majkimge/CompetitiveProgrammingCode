#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 2009
#define MAX1 200009
#define MAX2 1000009
#define INF 1000000000

using namespace std;

int n,m,w,kt=1,ileszcz;

int tab[MAX1];
int grupa[MAX1];
int wysgr[MAX1];
int czysz[MAX1];
vector<int> szcz[MAX1];
vector<int> kraw[MAX1];
vector<int> kraw1[MAX1];
int odw[MAX1];
int odw1[MAX1];
vector<int> wysy[MAX2];
vector<pair<int,pair<int,int> > > bin[MAX2][2];
int rep[MAX1];
int najsz[MAX1];
vector<pair<int,int> > wyniki;

void dfs(int from, int jaki, int num){                  //robienie grup
    odw[from]=1;
    grupa[from]=num;
    szcz[num].pb(from);
    wysgr[num]=jaki;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]&&tab[kraw[from][i]]==jaki){
            dfs(kraw[from][i], jaki, num);
        }
    }
}

int Find(int x){
    if(x!=rep[x]) rep[x]=Find(rep[x]);
    return rep[x];
}

void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        rep[y]=x;
        najsz[x]=najsz[y]=max(najsz[x],najsz[y]);
    }
}

void dfs1(int from, int mini, int num){                         //dfs w trakcie binsearcha
    odw1[from]=num;
    for(int i=0;i<kraw1[from].size();++i){
        if(odw1[kraw1[from][i]]<num&&wysgr[kraw1[from][i]]>=mini){
            Union(from,kraw1[from][i]);
            dfs1(kraw1[from][i], mini, num);
        }
    }
}



int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){                          //dodawanie kraw
            scanf("%d",&tab[i*(m+2)+j]);
            kraw[i*(m+2)+j].pb(i*(m+2)+j+1);
            kraw[i*(m+2)+j].pb(i*(m+2)+j-1);
            kraw[i*(m+2)+j].pb(i*(m+2)+j+1+(m+2));
            kraw[i*(m+2)+j].pb(i*(m+2)+j-1+(m+2));
            kraw[i*(m+2)+j].pb(i*(m+2)+j+(m+2));
            kraw[i*(m+2)+j].pb(i*(m+2)+j+1-(m+2));
            kraw[i*(m+2)+j].pb(i*(m+2)+j-1-(m+2));
            kraw[i*(m+2)+j].pb(i*(m+2)+j-(m+2));
        }
    }
    for(int i=1;i<=n;++i){                          //ustawianie grup do wysokosci
        for(int j=1;j<=m;++j){
            if(!odw[i*(m+2)+j]){
                wysy[tab[i*(m+2)+j]].pb(kt);
                dfs(i*(m+2)+j,tab[i*(m+2)+j],kt);
                kt++;
            }
        }
    }
    for(int i=1;i<kt;++i){                                  //robienie kraw dla grup
        for(int j=0;j<szcz[i].size();++j){
            //cout<<i<<" "<<szcz[i][j]<<endl;
            for(int z=0;z<kraw[szcz[i][j]].size();++z){
                kraw1[i].pb(grupa[kraw[szcz[i][j]][z]]);
            }
        }
    }
    for(int i=1;i<kt;++i){                          //ustalanie czy grupa to szczyt
        int tt=1;
        for(int j=0;j<kraw1[i].size();++j){
            //cout<<i<<" "<<kraw1[i][j]<<endl;
            if(wysgr[kraw1[i][j]]>wysgr[i]){
                tt=0;
                break;
            }
        }
        if(tt){
            czysz[i]=1;
            ileszcz++;
        }
    }
    for(int i=1;i<kt;++i){                            //inicjacja bina
        if(czysz[i]) bin[MAX2/2][1].pb(mp(i,mp(0,MAX2-2)));

    }
    cout<<czysz[2];
    for(int xd=1;xd<30;++xd){  //cout<<"A";                        //bin
        for(int i=1;i<kt;++i){
            odw1[i]=0;
            rep[i]=i;
            if(czysz[i]){                       //czyszczenie
                najsz[i]=wysgr[i];
            }else{
                najsz[i]=0;
            }
        }
        for(int i=0;i<MAX2-2;++i){
            for(int j=0;j<bin[i][1].size();++j){
                bin[i][0].pb(bin[i][1][j]);
            }
            bin[i][1].clear();
        }
        for(int i=MAX2-2;i>=0;--i){
            for(int j=0;j<wysy[i].size();++j){
                //cout<<i;
                if(!odw1[wysy[i][j]]){
                    //cout<<"X";
                    dfs1(wysy[i][j],i,1);
                }
            }

            for(int j=0;j<bin[i][0].size();++j){
                if(najsz[Find(bin[i][0][j].f)]>wysgr[bin[i][0][j].f]){
                    bin[(i+bin[i][0][j].s.s)/2][1].pb(mp(bin[i][0][j].f,mp(i,bin[i][0][j].s.s)));
                }else{
                    bin[(i+bin[i][0][j].s.f)/2][1].pb(mp(bin[i][0][j].f,mp(bin[i][0][j].s.f,i)));
                }
                bin[i][0].clear();
            }
        }
    }
    for(int i=0;i<MAX2-2;++i){
        for(int j=0;j<bin[i][1].size();++j){
            wyniki.pb(mp(wysgr[bin[i][1][j].f],i));
        }
    }
    sort(wyniki.begin(),wyniki.end());
    printf("%d\n",ileszcz);
    for(int i=wyniki.size()-1;i>=0;--i){
        printf("%d %d\n",wyniki[i].f,wyniki[i].s);
    }
    return 0;
}
