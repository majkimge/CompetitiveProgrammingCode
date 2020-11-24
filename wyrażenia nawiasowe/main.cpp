#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define MAX 300009
#pragma GCC optimalize ("ofast")

using namespace std;

int n,a,b,ktt=1;
vector<int>kraw[MAX];
int wag[MAX];
char s[MAX];
int odw[MAX];
int otw[MAX];
int zam[MAX];
lld wynik;
int wielk[MAX];
int gl[MAX];

int wykl[MAX];
int terotw[MAX];
int terite;
int zamite;
int terzam[MAX];




int dfswiel(int from, int gleb){

    gl[from]=gleb;
    odw[from]=ktt;
    int ret=0;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<ktt&&!wykl[kraw[from][i]]){
            ret+=dfswiel(kraw[from][i],gleb+1);
        }
    }
    wielk[from]=ret+1;
    return ret+1;
}

int dfsfind(int from, int wlk){
    odw[from]=ktt;
    int ret=from;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<ktt&&wielk[kraw[from][i]]>wlk/2&&!wykl[kraw[from][i]]){
            ret=dfsfind(kraw[from][i],wlk);
        }
    }
    return ret;
}

void dfsotw(int from, int sum, int doz, int czyc){

    odw[from]=ktt;
    if(wag[from]==1){
        sum++;
        if(doz<0)doz++;
        if(doz==0){
            otw[sum]++;
            //cout<<"X"<<sum;
            if(otw[sum]==1){
                terotw[terite]=sum;
                ++terite;
            }
        }
    }else{
        sum--;
        doz--;
    }
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<ktt&&!wykl[kraw[from][i]]){
            dfsotw(kraw[from][i],sum,doz,0);
        }
    }
}

void dfszam(int from, int sum, int doz, int czyc){
    odw[from]=ktt;
    if(!czyc){
        if(wag[from]==-1){
        sum++;
        if(doz<0)doz++;
        if(doz==0&&!czyc){
            zam[sum]++;
            if(zam[sum]==1){
                terzam[zamite]=sum;
                ++zamite;
            }
        }


    }else{

        doz--;
        sum--;

    }
    }

    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<ktt&&!wykl[kraw[from][i]]){
            dfszam(kraw[from][i],sum,doz,0);
        }
    }
}

void dfscofzam(int from, int sum, int doz){
    odw[from]=ktt;

    if(wag[from]==-1){
        sum++;
        if(doz<0)doz++;
        if(doz==0){
            zam[sum]--;
        }


    }else{

        doz--;
        sum--;

    }
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<ktt&&!wykl[kraw[from][i]]){
            dfscofzam(kraw[from][i],sum,doz);
        }
    }
}

void dfsod(int from, int sum, int doz){
    //cout<<"Y"<<from<<endl;
    odw[from]=ktt;
    if(wag[from]==1){
        sum++;
        doz++;
        if(doz==0&&sum==0){
            wynik++;
        }
    }else{
        sum--;
        doz--;
        if(doz==0&&sum==0){
            wynik++;
        }
    }
    if(doz<0)return;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<ktt&&!wykl[kraw[from][i]]){
            dfsod(kraw[from][i],sum,doz);
        }
    }
}



void rob(int from, int duz){
    if(duz==1)return;
    dfswiel(from,0);
    ++ktt;
    int centr=dfsfind(from,duz);

    ++ktt;
    dfszam(centr,0,0,1);
    ++ktt;
    wykl[centr]=1;
    dfsod(centr,0,0);
   // cout<<"X"<<wynik;
    ++ktt;
    dfswiel(centr,0);
    ++ktt;
    //cout<<centr<<" "<<duz<<endl;
    //wynik+=zam[0];
    //cout<<zam[2]<<endl;

    for(int i=0;i<kraw[centr].size();++i){
        if(!wykl[kraw[centr][i]]){
            if(wag[centr]==1){
                dfscofzam(kraw[centr][i],0,0);

                ++ktt;


                dfsotw(kraw[centr][i],1,0,1);
                ++ktt;

                for(int j=0;j<terite;++j){

                    wynik+=(lld)zam[terotw[j]]*otw[terotw[j]];
                    if(terotw[j]==0){
                        wynik+=(lld)otw[terotw[j]];
                    }

                    otw[terotw[j]]=0;
                }

                terite=0;
                dfszam(kraw[centr][i],0,0,0);
                ++ktt;
                //cout<<"X"<<zam[1]<<endl;

                //cout<<": "<<otw[1]<<endl;
            }else{
                dfscofzam(kraw[centr][i],0,0);
                ++ktt;
                dfsotw(kraw[centr][i],-1,-1,1);
                ++ktt;
                for(int j=0;j<terite;++j){

                    wynik+=(lld)zam[terotw[j]]*otw[terotw[j]];
                    if(terotw[j]==0){
                        wynik+=(lld)otw[terotw[j]];
                    }

                    otw[terotw[j]]=0;
                }
                terite=0;

                dfszam(kraw[centr][i],0,0,0);
                ++ktt;
            }

            }

    }
    for(int i=0;i<zamite;++i){
        zam[terzam[i]]=0;
    }
    zamite=0;
        ++ktt;
    //cout<<wynik<<endl;
    for(int i=0;i<kraw[centr].size();++i){
        //cout<<kraw[centr][i];
        if(!wykl[kraw[centr][i]])rob(kraw[centr][i],wielk[kraw[centr][i]]);

    }
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    srand(time(0));
    for(int i=0;i<n;++i){
        if(s[i]=='('){
            wag[i+1]=1;
        }else{
            wag[i+1]=-1;
        }
    }
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        //a=rand()%(i+1)+1;
        //b=i+2;
        kraw[a].pb(b);
        kraw[b].pb(a);
    }

    rob(1,n);
    printf("%lld",wynik);
    return 0;
}


/*
13
()()()()()
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
8 11
11 12
12 13
*/
