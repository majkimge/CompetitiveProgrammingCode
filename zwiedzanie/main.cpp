#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define MOD 1000000009
#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;

lld n,wyn,a,b,kt=1;
vector<lld> kraw[MAX];
lld gleb[MAX];
lld sumygl[MAX];
lld odw[MAX];
lld wyw[MAX];
lld ilesyn[MAX];
lld oczy[MAX];

lld dfs(lld z,lld gl,lld od){//licz synow
    odw[z]=kt;
    //gleb[z]=gl;
    //oczy[z]=od;
    lld iles=0;
    for(int i=0;i<kraw[z].size();++i){
        if(odw[kraw[z][i]]<kt&&!wyw[kraw[z][i]]){
            iles+=dfs(kraw[z][i],gl+1,z)+1;
        }
    }
    ilesyn[z]=iles;
    return iles;
}

lld dfs1(lld z,lld wlk){//poddaj cc
    odw[z]=kt;
    lld czy=1;
    lld doret=z;
    for(int i=0;i<kraw[z].size();++i){
        if(odw[kraw[z][i]]<kt&&!wyw[kraw[z][i]]&&ilesyn[kraw[z][i]]+1>wlk/2){
            czy=0;
            doret=dfs1(kraw[z][i],wlk);
        }
    }

        return doret;

}

lld dfs2(lld z,lld gl,lld od){//licz syn, gleb
    odw[z]=kt;

    gleb[z]=gl;
    oczy[z]=od;
    lld iles=0;
    for(int i=0;i<kraw[z].size();++i){
        if(odw[kraw[z][i]]<kt&&!wyw[kraw[z][i]]){//cout<<kt;
            iles+=dfs2(kraw[z][i],gl+1,z)+1;
        }
    }
    ilesyn[z]=iles;
    return iles;
}
lld dfs3(lld z,lld gl,lld od){//podaj sumy gleb
    odw[z]=kt;
    //gleb[z]=gl;
    //oczy[z]=od;
    lld ss=0;
    for(int i=0;i<kraw[z].size();++i){
        if(odw[kraw[z][i]]<kt&&!wyw[kraw[z][i]]){
            ss+=dfs3(kraw[z][i],gl+1,z);
        }
    }
    sumygl[z]=ss+gleb[z];
    return ss+gleb[z];
}
void cd(lld z,lld wlk){
    dfs(z,0,0);
    kt++;
    //cout<<endl<<z<<" ";
    //cout<<ilesyn[z]<<" ";
    if(ilesyn[z]<=1){
        wyn+=ilesyn[z];
        return;
    }
    lld cc=dfs1(z,wlk);
    //cout<<cc<<" ";
    kt++;
    dfs2(cc,0,cc);
    kt++;

    dfs3(cc,0,cc);
    kt++;

    //cout<<sumygl[cc]<<" ";
    wyn+=sumygl[cc];
    for(int i=0;i<kraw[cc].size();++i){
        if(!wyw[kraw[cc][i]]){
            wyn+=sumygl[kraw[cc][i]]*(ilesyn[cc]-ilesyn[kraw[cc][i]]-1)+(ilesyn[kraw[cc][i]]+1)*(sumygl[cc]-sumygl[kraw[cc][i]]);
            //cout<<wyn<<" ";
            sumygl[cc]-=sumygl[kraw[cc][i]];
            ilesyn[cc]-=(ilesyn[kraw[cc][i]]+1);

        }

    }
    //cout<<endl;
    wyw[cc]=1;
    for(int i=0;i<kraw[cc].size();++i){
        if(!wyw[kraw[cc][i]]){
        cd(kraw[cc][i],ilesyn[kraw[cc][i]]+1);
        }
    }


}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n-1;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    cd(1,n);
    printf("%lld",wyn);
    return 0;
}
