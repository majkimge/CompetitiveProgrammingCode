#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000009
#define llu unsigned long long


using namespace std;

llu n,p;
llu wynik;
llu tab[MAX];
int odw[MAX];
vector<int> codw;
int tab1[MAX],war;
vector<pair<llu,llu> >v;
vector<llu> v1;
priority_queue<pair<int,int> >q;
vector<pair<int,int> >bloki[MAX];
pair<llu,llu> wyny[MAX];
llu sumyp[MAX];

llu bin(llu l, llu pp, llu h){
    llu ss=(l+pp)/2;
    llu wyn=0;
    while(l<=pp){
        ss=(l+pp)/2;
        if((p+ss-1)/ss<=h){
            wyn=ss;
            pp=ss-1;
        }else{
            l=ss+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%llu",&n);
    scanf("%llu",&p);
    for(int i=0;i<n;++i){
        scanf("%llu",&tab[i]);
        //tab[i]=10000-i;
        v.pb(mp(tab[i],i));
        v1.pb(tab[i]);
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    for(int i=0;i<v.size();++i){
        war++;
        tab1[v[i].s]=war;
        llu ter=v[i].f;
        i++;
        while(v[i].f==ter){
            tab1[v[i].s]=war;
            ++i;
        }
        i--;

    }
    vector<llu>::iterator it;
    it=unique(v1.begin(),v1.end());
    v1.resize(distance(v1.begin(),it));
    for(int i=0;i<v1.size();++i){
        //v1[i]++;
    }
    for(int i=0;i<=n;++i){
        if(q.empty()){
            q.push(mp(tab1[i],-i));
            odw[tab1[i]]=1;
        }else{
            if(tab1[i]>=q.top().f&&!odw[tab1[i]]){
                q.push(mp(tab1[i],-i));
                odw[tab1[i]]=1;
                //codw.pb(tab1[i]);
            }else if(tab1[i]<q.top().f){
                int pocz=i;
                while(!q.empty()&&q.top().f>tab1[i]){
                    pair<int,int> temp=q.top();
                    q.pop();
                    pocz=min(pocz,-temp.s);
                    if(q.empty()){
                        bloki[temp.f].pb(mp(i+temp.s,tab1[i]));

                    }else{
                        bloki[temp.f].pb(mp(i+temp.s,max(tab1[i],q.top().f)));
                    }
                    odw[temp.f]=0;
                }
                if(!odw[tab1[i]]){
                    q.push(mp(tab1[i],-pocz));
                odw[tab1[i]]=1;
                }


            }
        }
    }
    /*for(int i=0;i<n;++i){
        for(int j=0;j<bloki[i].size();++j){
            cout<<i<<" "<<bloki[i][j].f<<" "<<bloki[i][j].s<<endl;
        }
    }*/
    for(llu i=1;i<=n;++i){
        sumyp[i]=sumyp[i-1]+(p+i-1)/i;
        wyny[i]=mp(i*(i+1)/2,wyny[i-1].s+sumyp[i]);
        //cout<<"A"<<sumyp[i]<<" ";
    }

    for(int i=1;i<=n;++i){
        for(int j=0;j<bloki[i].size();++j){
            //cout<<v1[i-1]<<" "<<bloki[i][j].f<<" "<<bloki[i][j].s<<endl;
            llu od=bin(1,bloki[i][j].f,v1[i-1]);
            //cout<<od<<" ";
            if(od){

                    wynik+=wyny[bloki[i][j].f].f*(v1[i-1]+1);

                    wynik-=wyny[bloki[i][j].f].s;//cout<<wyny[bloki[i][j].f].s<<" ";
                    wynik-=(wyny[od-1].f+(od-1)*(bloki[i][j].f-od+1))*(v1[i-1]+1);
                    wynik+=wyny[od-1].s+sumyp[(od-1)]*(bloki[i][j].f-od+1);
                if(bloki[i][j].s){
                    llu od1=bin(1,bloki[i][j].f,v1[bloki[i][j].s-1]);
                    if(od1){
                        wynik-=wyny[bloki[i][j].f].f*(v1[bloki[i][j].s-1]+1);
                        wynik+=wyny[bloki[i][j].f].s;
                        wynik+=(wyny[od1-1].f+(od1-1)*(bloki[i][j].f-od1+1))*(v1[bloki[i][j].s-1]+1);
                        wynik-=wyny[od1-1].s+sumyp[(od1-1)]*(bloki[i][j].f-od1+1);
                    }
                }
            }
           // cout<<wynik<<endl;
        }
    }
    printf("%llu",wynik);
    return 0;
}
