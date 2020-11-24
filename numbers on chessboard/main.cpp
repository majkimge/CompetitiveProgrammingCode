#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 1000000009

using namespace std;

lld n,q,x,y,wyn;

int main()
{
    cin>>n;
    cin>>q;
    for(int i=0;i<q;++i){
        wyn=0;
        cin>>y;
    cin>>x;
        if(n%2==1&&(x+y)%2==0){
            wyn+=(n/2+1)*(y/2);
            wyn+=(n/2)*max((lld)0,((y-1)/2));
        }else if(n%2==1&&(x+y)%2==1){
            wyn+=(n/2+1)*max((lld)0,((y-1)/2));
            wyn+=(n/2)*(y/2);
        }
        if(n%2==0){
            wyn+=(n/2)*(y-1);
        }
        //cout<<wyn;
        if(n%2==1){
            if(y%2==0){
                if((x+y)%2==0){
                    wyn+=x/2;
                }else{
                wyn+=(x+1)/2;
                }
            }else{
                if((x+y)%2==0){
                    wyn+=(x+1)/2;
                }else{
                    wyn+=(x)/2;
                }
            }
        }else{
            if(y%2==0){
                if((x+y)%2==0){
                    wyn+=x/2;
                }else{
                wyn+=(x+1)/2;
                }
            }else{
                if((x+y)%2==0){
                    wyn+=(x+1)/2;
                }else{
                    wyn+=(x)/2;
                }
            }
        }
        if((x+y)%2==1){
            wyn+=n*n-n*n/2;
        }
        cout<<wyn<<"\n";

    }
    return 0;
}
