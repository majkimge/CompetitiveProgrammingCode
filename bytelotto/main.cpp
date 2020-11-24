#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 10009
#define INF 1000000000
#define pb push_back
#define pii pair<int,int>


using namespace std;

int n,l,m,k,kt;
vector<int> skal;
map<int,int> ma;
int tab[MAX];
pii zapy[109];
int wyny[MAX][109];
vector<int> wyst[MAX];
//vector<int> odl[MAX];
int odtab[MAX];
int odp[MAX];
int lastl[MAX];
int pierl[MAX];

void akt(int p){
    for(int i=0;i<l;++i){


        //lastl[p+i]=max(pierl[p+i],lastl[p+i]);
        //cout<<"X"<<lastl[p+i]<<wyst[tab[p+i]][pierl[p+i]];
        int czyk=0;
        while(lastl[p+i]<wyst[tab[p+i]].size()-1&&wyst[tab[p+i]][lastl[p+i]+1]<=n-l+i){
            //cout<<"D";

            lastl[p+i]++;
            czyk=1;
            if(wyst[tab[p+i]][lastl[p+i]]>p+i)odtab[wyst[tab[p+i]][lastl[p+i]]-p-i]++;
            //if(p==0&&i==0)cout<<"X"<<wyst[tab[p+i]][lastl[p+i]]-p+i;
        }
//cout<<"D"<<wyst[tab[p+i]][lastl[p+i]];
            //if(wyst[tab[p+i]][lastl[p+i]]<=n-l+i&&czyk)odtab[wyst[tab[p+i]][lastl[p+i]]-p-i]++;

            //lastl[p+i]++;cout<<"X";
            //if(p==0&&i==0)cout<<"X"<<wyst[tab[p+i]][lastl[p+i]]-p+i;
        while(lastl[p+i]>0&&wyst[tab[p+i]][lastl[p+i]]>n-l+i){
            //cout<<lastl[p+i];
            if(wyst[tab[p+i]][lastl[p+i]]>p+i)odtab[wyst[tab[p+i]][lastl[p+i]]-p-i]--;
            //if(p==0&&i==0)cout<<"D"<<wyst[tab[p+i]][lastl[p+i]]-p+i;

            lastl[p+i]--;
        }
        while(pierl[p+i]<wyst[tab[p+i]].size()&&wyst[tab[p+i]][pierl[p+i]]<=p+i){
            if(wyst[tab[p+i]][pierl[p+i]]>p+i)odtab[wyst[tab[p+i]][pierl[p+i]]-p-i]--;
            pierl[p+i]++;
        }

    }
}

void zer(int p){
    for(int i=pierl[p];i<=lastl[p];++i){
        if(wyst[tab[p]][i]-p>0)odtab[wyst[tab[p]][i]-p]--;
    }
}

int main()
{
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        skal.pb(tab[i]);
    }
    sort(skal.begin(),skal.end());
    for(int i=0;i<skal.size();++i){
        ma[skal[i]]=kt;
        while(i!=skal.size()-1&&skal[i]==skal[i+1]){
            ++i;
        }
        ++kt;
    }
    for(int i=0;i<n;++i){
        //lastl[i]=-1;
        tab[i]=ma[tab[i]];
        wyst[tab[i]].pb(i);
    }


    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&zapy[i].f);
        zapy[i].s=i;
    }
    //sort(zapy,zapy+m);

    akt(0);
//cout<<"X";
//cout<<lastl[1];
    for(int i=0;i<n-l+1;++i){


        //int ktzap=m-1;
        //int akt=0;
        for(int j=0;j<=n;++j){
            odp[j]=0;
        }
        for(int j=0;j<=n;++j){
            odp[odtab[j]]++;
        }
        for(int j=n;j>=0;--j){
            odp[j]+=odp[j+1];
        }
        for(int j=0;j<m;++j){
            wyny[i][j]+=odp[l-zapy[j].f];
        }
        zer(i);
        akt(i+1);

    }//cout<<"X";







    for(int i=0;i<n/2;++i){
        swap(tab[i],tab[n-i-1]);
    }

    for(int i=0;i<n;++i){
        //tab[i]=ma[tab[i]];

        wyst[i].clear();
    }
    for(int i=0;i<n;++i){
        //tab[i]=ma[tab[i]];

        wyst[tab[i]].pb(i);
    }


    for(int i=0;i<=n;++i){
        odtab[i]=lastl[i]=pierl[i]=0;
    }

    akt(0);
    for(int i=0;i<n-l+1;++i){
        /*for(int i=0;i<n;++i){

                cout<<odtab[i]<<" ";

            cout<<endl;
        }
        cout<<endl;*/

        for(int j=0;j<=n;++j){
            odp[j]=0;
        }
        for(int j=0;j<=n;++j){
            odp[odtab[j]]++;
        }
        for(int j=n;j>=0;--j){
            odp[j]+=odp[j+1];
        }
        for(int j=0;j<m;++j){
            wyny[n-i-l][j]+=odp[l-zapy[j].f];
        }

        zer(i);
        akt(i+1);
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n-l+1;++j){
            if(zapy[i].f!=l){
                printf("%d ",wyny[j][i]);
            }else{
                printf("%d ",n-l);
            }

        }
        printf("\n");
    }
    return 0;
}

/*
6 2
2 3 1 1 3 2
3
0
1
2
*/
