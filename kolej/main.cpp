#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009

using namespace std;

int n,kk=1,ost=0,ost1=0,a;
int tab1[MAX];
pair<int,int> tab[MAX];
queue<int> q[2];
int wynik[MAX];
vector<int> v;


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        tab[i].s=a;
        tab[i].s=i;
        tab1[i]=tab[i].f;
    }
    sort(tab,tab+n);
    ost=n;
    for(int i=0;i<n;++i){
        if(tab[i].s==ost-1){

            q[ost1].push(tab[i].s);
            ost=tab[i].s;
        }else if(tab[i].s<ost-1){cout<<"F";
            for(int j=tab[i].s+1;j<ost;++j){
                q[ost1^1].push(j);
            }
            q[ost1].push(tab[i].s);
            ost=tab[i].s;
        }
    }
    cout<<q[1].size();
    while(v.size()<n){
        if(q[0].empty()){
            v.pb(tab1[q[1].front()]);
            wynik[q[1].front()]=2;
            q[1].pop();
        }else if(q[1].empty()){
            v.pb(tab1[q[0].front()]);
            wynik[q[0].front()]=1;
            q[0].pop();
        }else{
            if(tab1[q[1].front()]<tab1[q[0].front()]){
                v.pb(tab1[q[1].front()]);
                wynik[q[1].front()]=2;
                q[1].pop();
            }else{
                v.pb(tab1[q[0].front()]);
                wynik[q[0].front()]=1;
                q[0].pop();
            }
        }


    }
    int czy=1;
    for(int i=1;i<n;++i){
        if(v[i]-v[i-1]!=1){
            czy=0;
        }
    }
    if(!czy){
        printf("NIE\n");
    }else{
        printf("TAK\n");
        for(int i=0;i<n;++i){
            printf("%d ",wynik[i]);
        }
    }

    return 0;
}
