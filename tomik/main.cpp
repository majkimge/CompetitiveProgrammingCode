#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MAX 1000009
#define iNF 1000000009
#define MOD 1000696969

using namespace std;

int n,s,a,done;
vector<int> tab[MAX];
int ktor[MAX];
vector<int> wynik;
int wyn;
priority_queue<pair<int,int> >q;
vector<pair<pair<int,int>,pair<int,int> > >v;

int main()
{
    scanf("%d",&n);
    scanf("%d",&s);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        tab[(a+1)%s].pb(i+1);
    }
    for(int i=0;i<s;++i){
        if(tab[i].size())q.push(mp(tab[i].size(),i));

    }
    int akt=0;
    //cout<<q.size();
    while(!q.empty()){
        //cout<<"F";
        pair<int,int> ter=q.top();
        //cout<<ter.ss;
        pair<int,int> ter1;
        q.pop();//cout<<"F";
        if((akt+ter.ss)%s==s-1&&!q.empty()){
            ter1=q.top();
            q.pop();
            q.push(ter);
            //cout<<tab[ter1.ss][ktor[ter1.ss]];
            wynik.pb(tab[ter1.ss][ktor[ter1.ss]]);
            if((akt+ter1.ss)%s==s-1) wyn++;
            akt+=ter1.ss;
            ktor[ter1.ss]++;
            ter1.f--;
            if(ter1.f){
                q.push(ter1);
            }
        }else{
            //cout<<tab[ter.ss][ktor[ter.ss]];
            wynik.pb(tab[ter.ss][ktor[ter.ss]]);
            ktor[ter.ss]++;
            if((akt+ter.ss)%s==s-1&&(!q.empty()||(q.empty()&&ter.f!=1))){
                wyn++;
                akt=0;
            }else{
                akt+=ter.ss;
            }

            ter.f--;
            if(ter.f){
                q.push(ter);
            }
        }
    }
    printf("%d\n",wyn);
    for(int i=0;i<wynik.size();++i){
        printf("%d ",wynik[i]);
    }
    return 0;
}
