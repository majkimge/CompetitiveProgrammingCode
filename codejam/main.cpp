#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second


using namespace std;

int n, tab[109][109],t,k,r,c,il[109];
char s[109];
char wyn[100000];
vector<pair<int,int> >duty[100000];
vector<int> fr;
int wyny[100000];
int czyk=1;

int main()
{
    scanf("%d",&t);
    for(int xdd=1;xdd<=t;++xdd){
        fr.clear();
        fr.pb(0);
        fr.pb(1);
        for(int i=0;i<2000;++i)duty[i].clear();
        scanf("%d",&n);
        for(int i=0;i<n;++i){

            scanf("%d%d",&r,&c);
            duty[r].pb(mp(1,i));
            duty[c].pb(mp(-1,i));
        }
        czyk=1;
        for(int i=0;i<2000;++i){
            if(!czyk)break;
            sort(duty[i].begin(),duty[i].end());
            for(int j=0;j<duty[i].size();++j){
                if(duty[i][j].f==-1){
                    fr.pb(wyny[duty[i][j].s]);
                }else{
                    if(fr.empty()){
                        czyk=0;
                        break;
                    }
                    wyny[duty[i][j].s]=fr[fr.size()-1];
                    fr.pop_back();
                }
            }
        }
        if(!czyk){
            printf("Case #%d: IMPOSSIBLE\n",xdd);
        }else{
            printf("Case #%d: ",xdd);
            for(int i=0;i<n;++i){
                if(wyny[i]){
                    printf("J");
                }else{
                    printf("C");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
