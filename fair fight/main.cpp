#include <bits/stdc++.h>
#define MAX 100009
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pii pair<lld,lld>
#define lld long long

using namespace std;

lld tt,n,k;

lld cha[MAX];
lld del[MAX];
lld wynik;
pii chalew[MAX][30];
pii chapraw[MAX][30];
pii delpraw[MAX][30];
pii dellew[MAX][30];
vector<lld> gdzcha[MAX];

int main()
{
    scanf("%lld",&tt);
    for(int xd=1;xd<=tt;++xd){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;++i){
            scanf("%lld",&cha[i]);
            gdzcha[cha[i]].pb(i);
            //scanf("%lld",&del[i]);
        }
        for(int i=1;i<=n;++i){
            //scanf("%lld",&cha[i]);
            scanf("%lld",&del[i]);

        }
        cha[n+1]=MAX*2;
        del[n+1]=MAX*5;
        chapraw[n+1][0]=mp(MAX*2,n+1);
        delpraw[n+1][0]=mp(MAX*5,n+1);
        for(lld i=1;i<=n;++i){
            chalew[i][0]=mp(max(cha[i],cha[i-1]),i-1);
            chapraw[i][0]=mp(max(cha[i],cha[i+1]),i+1);
            dellew[i][0]=mp(max(del[i],del[i-1]),i-1);
            delpraw[i][0]=mp(max(del[i],del[i+1]),i+1);

        }
        for(lld i=1;i<28;++i){
            for(lld j=1;j<=n+1;++j){
                chalew[j][i]=mp(max(chalew[j][i-1].f,chalew[max((lld)0,chalew[j][i-1].s)][i-1].f),chalew[max((lld)0,chalew[j][i-1].s)][i-1].s);
                chapraw[j][i]=mp(max(chapraw[j][i-1].f,chapraw[max((lld)0,chapraw[j][i-1].s)][i-1].f),chapraw[max((lld)0,chapraw[j][i-1].s)][i-1].s);
                dellew[j][i]=mp(max(dellew[j][i-1].f,dellew[max((lld)0,dellew[j][i-1].s)][i-1].f),dellew[max((lld)0,dellew[j][i-1].s)][i-1].s);
                delpraw[j][i]=mp(max(delpraw[j][i-1].f,delpraw[max((lld)0,delpraw[j][i-1].s)][i-1].f),delpraw[max((lld)0,delpraw[j][i-1].s)][i-1].s);
            }
        }

        lld lastl=0;
        lld lastp=0;
        for(lld i=0;i<MAX;++i){
            for(lld j=0;j<gdzcha[i].size();++j){
                lld gdz=gdzcha[i][j];
                if(lastl<=gdz&&lastp>=gdz||del[gdz]-i>k)continue;
                //lld maxl=i;
                lld gdzl=gdz;
                lld gdzp=gdz;
                lld odl=gdz;
                lld dol=gdz;
                lld odp=gdz;
                lld dop=gdz;
                for(lld z=27;z>=0;--z){
                    if(chalew[gdzl][z].f<=i){
                        gdzl=chalew[gdzl][z].s;
                    }
                }
                for(lld z=27;z>=0;--z){
                    if(chapraw[gdzp][z].f<=i){
                        gdzp=chapraw[gdzp][z].s;
                    }
                }


                for(lld z=27;z>=0;--z){
                    if(dellew[odl][z].f<i-k){
                        odl=dellew[odl][z].s;
                    }
                }
                for(lld z=27;z>=0;--z){
                    if(delpraw[odp][z].f<i-k){
                        odp=delpraw[odp][z].s;
                    }
                }


                for(lld z=27;z>=0;--z){
                    if(dellew[dol][z].f<=i+k){
                        dol=dellew[dol][z].s;
                    }
                }
                for(lld z=27;z>=0;--z){
                    if(delpraw[dop][z].f<=i+k){
                        dop=delpraw[dop][z].s;
                    }
                }
                if(abs(i-del[gdz])>k){
                    odl--;
                    odp++;
                }

                odl=max((lld)1,odl);
                dol=max((lld)1,dol);
                gdzl=max((lld)1,gdzl);
                gdzp=min(n,gdzp);
                dol=max(dol,gdzl);
                dop=min(n,dop);
                odp=min(n,odp);
                dop=min(dop,gdzp);

                cout<<odl<<" "<<odp<<endl;
                //wynik+=max((lld)0,(-dol+odl+1)*(dop-odp+1));
                wynik+=max((lld)0,(dop-odp+1)*(gdz-dol+1)+(odl-dol+1)*(odp-gdz));
                lastl=dol;
                lastp=dop;
            }
        }
        printf("Case #%d: %lld\n",xd,wynik);
        wynik=0;
        for(int i=1;i<28;++i){

            for(int j=1;j<=n;++j){
                chalew[j][i]=mp(0,0);
                chapraw[j][i]=mp(0,0);
                dellew[j][i]=mp(0,0);
                delpraw[j][i]=mp(0,0);
            }
        }
        for(int i=0;i<MAX;++i){
            gdzcha[i].clear();
            cha[i]=del[i]=0;
        }
    }
    return 0;
}
