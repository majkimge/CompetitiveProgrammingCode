#include <bits/stdc++.h>

#define lld long long
#define MAX 3002
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second
using namespace std;

lld n,k;
char temp;
int tab[MAX][MAX];
pair<pair<int,int>,lld > tab1[MAX*MAX];
lld ilej,iled,ilet,ilec;
lld ileich[5];
lld ilepar;
lld iledwoj;
lld ktoradwoja;
lld iledwojtworzy[MAX*MAX];
lld wynik;
lld oddwoj;
lld odtroj;
lld iledwojtemp;
lld dwojezjed;
lld wsp[MAX*MAX];
bool tempczy,tempczy1;
lld iletego[5];
lld zilomadwojami;
lld zilomatrojami;
lld zilomatrojamijuz[MAX*MAX];
lld zilomadwojamijuz[MAX*MAX];
lld ujdwoj;
lld ujtroj;
vector<lld> kraw[MAX*MAX];
vector<pair<lld,pair<lld,lld> > > pierwsi;
vector <pair<lld,lld> > pierwsi1;
queue<lld> kol;



void bfs(lld ktor,lld doilu,lld ilep){
    while(!kol.empty()){
        int x=kol.front();
        kol.pop();
        for(int i=0;i<kraw[x].size();i++){
            if((tab1[kraw[x][i]].f.f!=1&&tab1[kraw[x][i]].f.f!=2)&&(tab1[kraw[x][i]].s!=x||tab1[kraw[x][i]].f.s!=tab1[x].f.s)){

                tab1[kraw[x][i]]=mp(mp(tab1[x].f.f+1,ktor),x);
                if(tab1[x].f.f<doilu+1)
                kol.push(kraw[x][i]);
                if(tab1[x].f.f==2){

                    ilepar+=iledwoj-iledwojtworzy[kraw[x][i]]-ktoradwoja;
                    ilepar%=MOD;
                    iledwojtworzy[kraw[x][i]]++;
                    iledwoj++;
                    ktoradwoja++;
                    iledwojtemp=0;
                    for(int p=0;p<kraw[kraw[x][i]].size();p++){
                        if(tab1[kraw[kraw[x][i]][p]].f.f==2&&kraw[kraw[x][i]][p]!=x){
                            oddwoj++;
                            zilomadwojami++;
                            iledwojtemp++;
                            tempczy=1;
                            //cout<<oddwoj;
                        }
                    }
                    if(tempczy){
                        ujdwoj=zilomadwojami-zilomadwojamijuz[kraw[x][i]];
                        if(ilep-zilomadwojami-2+zilomadwojamijuz[kraw[x][i]]>0){
                            dwojezjed+=(ilep-zilomadwojami-2+zilomadwojamijuz[kraw[x][i]])*(ilep-zilomadwojami-1+zilomadwojamijuz[kraw[x][i]])/2;
                            dwojezjed%=MOD;
                        }
                        zilomadwojamijuz[kraw[x][i]]++;

                    }
                    iletego[iledwojtemp]++;
                    if(iletego[iledwojtemp]==iledwojtemp){
                        oddwoj+=iledwojtemp;
                        iletego[iledwojtemp]=0;
                    }
                }
                if(tab1[x].f.f==3){
                    for(int p=0;p<kraw[kraw[x][i]].size();p++){
                        if(tab1[kraw[kraw[x][i]][p]].f.f==2&&kraw[kraw[x][i]][p]!=x){
                            odtroj++;
                            zilomatrojami++;
                            wsp[tab1[kraw[kraw[x][i]][p]].f.s]++;
                            tempczy1=1;
                        }
                    }
                    if(tempczy1){
                        ujtroj+=ilep-1-zilomatrojami+wsp[ktor];

                        zilomatrojamijuz[kraw[x][i]]++;
                    }
                }

                ileich[tab1[x].f.f]++;
            }
        }
    }
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;++j){
            scanf(" %c",&temp);
            if(temp=='#'){
                tab[i][j]=1;
                tab1[i*n+j]=mp(mp(1,0),-1);
            }else{
                tab[i][j]=0;
                tab1[i*n+j]=mp(mp(0,0),-1);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;++j){
            if(j<n-1)
            kraw[i*n+j].push_back(i*n+j+1);
            if(j>0)
            kraw[i*n+j].push_back(i*n+j-1);
            if(i<n-1)
            kraw[i*n+j].push_back((i+1)*n+j);
            if(i>0)
            kraw[i*n+j].push_back((i-1)*n+j);

        }
    }
    /*for(int i=0;i<n*n;i++){
        for(int j=0;j<kraw[i].size();++j){
            cout<<kraw[i][j];
        }
    }*/
    for(int i=0;i<n*n;++i){//cout<<ilej;
        for(int j=0;j<kraw[i].size();++j){
            if(tab1[kraw[i][j]].f.f==1&&tab1[i].f.f==0){
                ilej++;
                ilej%=MOD;
                tab1[i]=mp(mp(2,ilej),-1);
            }
        }
    }

    for(int i=0;i<n*n;++i){
        if(tab1[i].f.f==2){
            kol.push(i);
            ktoradwoja=0;
            ileich[2]=0;
            ileich[3]=0;
            ileich[4]=0;
            zilomadwojami=0;
            zilomatrojami=0;
            tempczy=0;
            tempczy1=0;

            bfs(tab1[i].f.s,k,ilej);
            pierwsi.push_back(mp(ileich[2],mp(ileich[3],ileich[4])));
            pierwsi1.push_back(mp(ujdwoj,ujtroj));
        }
    }
    if(k==1){
        wynik=ilej;
        wynik%=MOD;
    }else if(k==2){
    for(int i=0;i<pierwsi.size();++i){
        wynik+=pierwsi[i].f;
        wynik%=MOD;

    }
        wynik+=ilej*(ilej-1)/2;
        wynik%=MOD;
    }else if(k==3){
        for(int i=0;i<pierwsi.size();++i){
        wynik+=pierwsi[i].s.f;
        wynik%=MOD;

        }
        for(int i=0;i<pierwsi.size();++i){
        wynik+=pierwsi[i].f*(ilej-1);
        wynik-=pierwsi1[i].f;
        wynik%=MOD;

        }
        wynik+=ilej*(ilej-1)*(ilej-2)/6;
        wynik%=MOD;

    }else if(k==4){
        for(int i=0;i<pierwsi.size();++i){
        wynik+=pierwsi[i].s.s;
        wynik%=MOD;

        }
        /*for(int i=0;i<pierwsi.size();++i){
        wynik+=pierwsi[i].s.f*(ilej-1)-pierwsi1[i].s;
        wynik%=MOD;

        }*/
        wynik+=ujtroj;
        wynik%=MOD;
        wynik+=ilepar;
        wynik%=MOD;
        wynik+=dwojezjed;
        wynik%=MOD;
        if(ilej>2){
            wynik+=ilej*(ilej-1)*(ilej-2)*(ilej-3)/24;
            wynik%=MOD;
        }
    }
    printf("%lld",wynik);
    return 0;
}
