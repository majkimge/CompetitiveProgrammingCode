#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 200009

using namespace std;

int t,n,kt;
int tab[MAX];
vector<pair<int,int> >skal;
int czywl[MAX];
int czywp[MAX];
int iler[MAX];
int dokl[MAX];
int dokp[MAX];
int odw[MAX];
vector<int> jakier;
vector<int> jakiel;
vector<int> jakiep;
priority_queue<pair<int,int> >q;

int rozw(int l, int p){
    if(l==p)return 1;
    int ret=1;

    int czyl=rozw(l,(l+p)/2);
    //cout<<"L"<<czyl<<" ";
    int czyp=rozw((l+p)/2+1,p);
    //cout<<l<<" "<<p<<" "<<czyl<<" "<<czyp<<endl;
    //cout<<"P"<<czyp<<" ";
    if((!czyl)||(!czyp)) return 0;
    for(int i=l;i<=(l+p)/2;++i){
        if(!czywl[tab[i]])czywl[tab[i]]=i;

        //jakiel.pb(tab[i]);
    }
    for(int i=(l+p)/2+1;i<=p;++i){
        if(!czywp[tab[i]])czywp[tab[i]]=i;
        //jakiep.pb(tab[i]);
    }
    int ileb=0;
    //if(l==0&&p==2)
    for(int i=(l+p)/2;i>=l;--i){
        iler[tab[i]]++;
        if(iler[tab[i]]==1){
            if(czywp[tab[i]]){
                q.push(mp(czywp[tab[i]],tab[i]));
            }else{
                q.push(mp(p+1,tab[i]));
            }
            //ileb++;
        }else if(iler[tab[i]]==2){
            odw[tab[i]]=1;
        }
        while(!q.empty()&&odw[q.top().s])q.pop();
        if(q.empty()){
            dokl[i]=(l+p)/2+1;
        }else{
            dokl[i]=q.top().f;
        }
    }
    for(int i=l+1;i<=(l+p)/2;++i){
        dokl[i]=min(dokl[i],dokl[i-1]);
    }
    while(!q.empty())q.pop();


    for(int i=(l+p)/2;i>=l;--i){
        iler[tab[i]]=0;
        odw[tab[i]]=0;
    }

    for(int i=(l+p)/2+1;i<=p;++i){
        iler[tab[i]]++;
        if(iler[tab[i]]==1){
            if(czywl[tab[i]]){
                q.push(mp(-czywl[tab[i]],tab[i]));
            }else{
                q.push(mp(1,tab[i]));
            }
            //ileb++;
        }else if(iler[tab[i]]==2){
            odw[tab[i]]=1;
        }
        while(!q.empty()&&odw[q.top().s])q.pop();
        if(q.empty()){
            if(dokl[(l+p)/2]<=i)ret=0;
            //dokp[i]=(l+p)/2;
        }else if(-q.top().f!=-1){
            if(dokl[-q.top().f]<=i)ret=0;
            //dokl[i]=q.top().f;
        }
    }

    while(!q.empty())q.pop();
    for(int i=(l+p)/2;i>=l;--i){
        iler[tab[i]]=0;
        odw[tab[i]]=0;
    }
    for(int i=l+1;i<=(l+p)/2;++i){
        dokl[i]=0;
    }

    /*
    ileb=0;
    for(int i=(l+p)/2+1;i<=p;++i){
        iler[tab[i]]++;
        if(iler[tab[i]]==1&&czywl[tab[i]]==0){
            ileb++;
        }else if(iler[tab[i]]==2&&czywl[tab[i]]==0){
            ileb--;
        }
        if(!ileb){
            ret=0;
            break;
        }
    }*/
    for(int i=(l+p)/2+1;i<=p;++i){
        iler[tab[i]]=0;
    }
    for(int i=l;i<=(l+p)/2;++i){
        czywl[tab[i]]=0;
        //jakiel.pb(tab[i]);
    }
    for(int i=(l+p)/2+1;i<=p;++i){
        czywp[tab[i]]=0;
        //jakiep.pb(tab[i]);
    }
    return ret;
}

int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
            scanf("%d",&n);
            skal.clear();
        for(int i=0;i<n;++i){
            scanf("%d",&tab[i]);
            skal.pb(mp(tab[i],i));
        }
        sort(skal.begin(),skal.end());
        for(int i=0;i<skal.size();++i){
            int ter=skal[i].f;
            tab[skal[i].s]=kt;
            while(i<skal.size()-1&&skal[i+1].f==ter){
                ++i;
                tab[skal[i].s]=kt;
            }
            ++kt;
        }
        int wyn=rozw(0,n-1);
        if(wyn){
            printf("TAK\n");
        }else{
            printf("NIE\n");
        }
    }
    return 0;
}
/*
3
3
1 2 3
*/
