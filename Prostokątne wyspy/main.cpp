#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MAX 300009

using namespace std;

pair<pair<int,int>,pair<int,int> > zam[MAX];
int tree[MAX*2],wynik;
int n,x,y,w,h,ite,kk=1;
map<int,int> skal;
int ys[MAX];

int add(int l, int p, int co){
    l+=kk;
    p+=kk;
    if(l!=p){
        tree[l]+=co;
        tree[p]+=co;
    }else{
        tree[l]+=co;
    }
    while(l/2!=p/2){
        if(l%2==0){
            tree[l+1]+=co;
        }
        if(p%2==1){
            tree[p-1]+=co;
        }
        l>>=1;
        p>>=1;
    }
}

int check(int gdzie){
    int wyn=0;
    gdzie+=kk;
    while(gdzie>0){
        wyn+=tree[gdzie];
        gdzie>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d",&x,&y,&w,&h);
        ys[i*2]=y;
        ys[i*2+1]=y+h;
        zam[2*i]=mp(mp(x,1),mp(y,y+h));
        zam[2*i+1]=mp(mp(x+w,-1),mp(y,y+h));

    }
    sort(ys,ys+n*2);
    for(int i=0;i<2*n;++i){
        skal[ys[i]]=ite;
        ite++;
        while(i<2*n&&ys[i]==ys[i+1]){
            ++i;
        }
    }
    for(int i=0;i<2*n;++i){
        zam[i].s.f=skal[zam[i].s.f];
        zam[i].s.s=skal[zam[i].s.s];
    }
    sort(zam,zam+n*2);
    while(kk<2*n) kk<<=1;
    for(int i=0;i<2*n;++i){
        //cout<<zam[i].s.f<<" "<<zam[i].s.s<<endl;
        if(zam[i].f.s==1){
            if(check(zam[i].s.f)%2==0){
                wynik++;
                //cout<<zam[i].f.f<<endl;
            }
            add(zam[i].s.f,zam[i].s.s,1);
        }else{
            add(zam[i].s.f,zam[i].s.s,-1);
        }
    }
    printf("%d",wynik);
    return 0;
}
