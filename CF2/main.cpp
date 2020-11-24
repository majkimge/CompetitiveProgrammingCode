#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MAX 1000009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

lld n,m,a,dl,pocz,czy,dod;
lld wyn=1;
char co[10];
priority_queue<lld> sell;
priority_queue<lld> buy;
vector<lld> niew;
int shame=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%s",&co[0]);
        //cout<<"F";
        cin>>a;
        if(!shame){
            if(co[2]=='D'){
                if(!sell.empty()&&a>-sell.top()){
                    sell.push(-a);
                }else if(!buy.empty()&&a<buy.top()){
                    buy.push(a);
                }else{
                    niew.pb(a);
                    //cout<<"A";
                }
            }else{
                if(!sell.empty()&&a>-sell.top()){
                    shame=1;
                    //break;
                }else if(!buy.empty()&&a<buy.top()){
                    shame=1;
                    //break;
                }else if(!sell.empty()&&a==-sell.top()){
                    sell.pop();
                    for(int j=0;j<niew.size();++j){
                        buy.push(niew[j]);
                    }
                    niew.clear();
                }else if(!buy.empty()&&a==buy.top()){
                    buy.pop();
                    for(int j=0;j<niew.size();++j){
                        sell.push(-niew[j]);
                    }
                    niew.clear();
                }else{
                    czy=0;
                    for(int j=0;j<niew.size();++j){
                        if(niew[j]==a){
                            czy=1;
                            wyn*=2;
                            wyn%=MOD;
                        }else if(niew[j]>a){
                            sell.push(-niew[j]);
                        }else{
                            buy.push(niew[j]);
                        }
                    }
                    niew.clear();
                    if(!czy){
                        //shame=1;
                        //break;
                    }else{
                        //cout<<"F";

                    }
                }
            }

        }

    }
    if(shame){
        printf("0");
    }else{


        wyn*=(niew.size()+1);

        wyn%=MOD;
        cout<<wyn;
    }

}
