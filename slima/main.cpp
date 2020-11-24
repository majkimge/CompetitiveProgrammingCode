#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 70009
#define pii pair<int,int>

using namespace std;

pii bloki[MAX];
vector<pii> dbloki;
int pola[MAX];
int n,m,a;
int tasma[200009];
int dp[MAX][2];
int wielpref[MAX];
int wielsuf[MAX];
int czy=0,wynik;

vector<pair<int,pii> >wszystko;
vector<pair<int,pii> >wszystkop;

int bin(int kt, int ile){
    int l=kt-1;
    int p=0;
    int s=(l+p)/2;
    int wyn=-1;
    while(l>=p){
        s=(l+p)/2;
        if(wielpref[kt]-wielpref[s]>=ile){
            wyn=s;
            p=s+1;
        }else{
            l=s-1;
        }
    }
    return wyn;
}

int binp(int kt, int ile){
    int l=kt+1;
    int p=dbloki.size();
    int s=(l+p)/2;
    int wyn=-1;
    while(l<=p){
        s=(l+p)/2;
        if(wielsuf[kt]-wielpref[s]>=ile){
            wyn=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    return wyn;
}

void liczdp(int kt){
    int pier=-1;
    int wyn=0;
    for(int i=1;i<=m;++i){
        if(pola[i]<=dbloki[kt].s){
            pier=i;
        }else{
            break;
        }
    }
    //cout<<pier<<endl;
    for(int i=pier;i>0;--i){
        int twyn=0;
        if(kt>0)dp[kt][0]=max(dp[kt][0],dp[kt-1][0]);
        int temp=bin(kt,dbloki[kt].s-pola[i]+1);

        if(temp>=0){
            dp[kt][0]=max(dp[kt][0],pier-i+1+dp[temp][0]);
            //cout<<kt<<" "<<i<<" "<<temp<<" "<<dp[3][0]<<endl;
        }
    }

}

void liczdpp(int kt){
    int pier=m+1;
    int wyn=0;
    for(int i=m;i>0;--i){
        if(pola[i]>=dbloki[kt].f){
            pier=i;
        }else{
            break;
        }
    }
    //cout<<kt<<" "<<pier<<endl;
    for(int i=pier;i<=m;++i){
        int twyn=0;
        if(kt>0)dp[kt][1]=max(dp[kt][1],dp[kt+1][1]);
        int temp=binp(kt,pola[i]-dbloki[kt].f+1);
        if(temp>=0){
            dp[kt][1]=max(dp[kt][1],i-pier+1+dp[temp][1]);
        }
    }

}

int binost(int kt){
    int l=1;
    int p=m;
    int s=(l+p)/2;
    int wynl=-1;
    while(l<=p){
        s=(l+p)/2;
        if(pola[s]>=dbloki[kt].f){
            p=s-1;
            wynl=s;
        }else{
            l=s+1;
        }
    }
    l=1;
    p=m;
    int wynp=-1;
    while(l<=p){
        s=(l+p)/2;
        if(pola[s]<=dbloki[kt].s){
            l=s+1;
            wynp=s;
        }else{
            p=s-1;
        }
    }
    if(wynp<0||wynl<0){
        return 0;
    }
    return wynp-wynl+1;

}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        bloki[i].f=a;
        bloki[i].s=a;
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&pola[i]);
        wszystko.pb(mp(pola[i],mp(0,i)));
        wszystkop.pb(mp(pola[i],mp(1,i)));
    }
    sort(bloki+1,bloki+n+1);
    sort(pola+1,pola+m+1);
    dbloki.pb(mp(-1,-1));
    for(int i=1;i<=n;++i){
        int pocz=bloki[i].f;
        int kon=bloki[i].s;
        while(i<n&&bloki[i+1].f==kon+1){
            ++kon;
            ++i;
        }
        dbloki.pb(mp(pocz,kon));

    }
    /*for(int i=0;i<dbloki.size();++i){
        cout<<dbloki[i].f<<" "<<dbloki[i].s<<endl;
    }*/
    for(int i=0;i<dbloki.size();++i){
        wszystko.pb(mp(dbloki[i].s,mp(1,i)));
        wszystkop.pb(mp(dbloki[i].f,mp(0,i)));
    }

    //wielpref[0]=dbloki[0].s-dbloki[0].f+1;
    for(int i=1;i<dbloki.size();++i){
        wielpref[i]=wielpref[i-1]+dbloki[i].s-dbloki[i].f+1;
        //cout<<wielpref[i]<<" ";
    }

    //wielsuf[dbloki.size()-1]=dbloki[dbloki.size()-1].s-dbloki[dbloki.size()-1].f+1;
    for(int i=dbloki.size()-1;i>0;--i){
        wielsuf[i]=wielsuf[i+1]+dbloki[i].s-dbloki[i].f+1;

    }
    sort(wszystko.begin(),wszystko.end());
    sort(wszystkop.begin(),wszystkop.end());
    czy=0;
    for(int i=1;i<wszystko.size();++i){
        //cout<<wszystko[i].s.s<<" "<<wszystko[i].s.f<<endl;
        if(wszystko[i].s.f==0){
            czy=1;
        }else{
            if(czy==1){
                //cout<<wszystko[i].s.s<<endl;
                liczdp(wszystko[i].s.s);

                czy=0;
            }else{
                dp[wszystko[i].s.s][0]=dp[wszystko[i].s.s-1][0];
            }

        }
    }
    czy=0;
    for(int i=wszystkop.size()-1;i>0;--i){
        if(wszystkop[i].s.f==1){
            czy=1;
        }else{
            if(czy==1){
                liczdpp(wszystkop[i].s.s);
                czy=0;
            }else{
                dp[wszystkop[i].s.s][1]=dp[wszystkop[i].s.s+1][1];
            }
            //cout<<wszystkop[i].s.s<<" "<<dp[wszystkop[i].s.s][1]<<endl;
        }
    }
    for(int i=1;i<dbloki.size();++i){
        wynik=max(wynik,dp[i][0]+dp[i][1]-binost(i));
    }
    printf("%d",wynik);
    return 0;
}
/*
6 6
5 14 8 1 15 13
6 3 12 11 16 14
*/
