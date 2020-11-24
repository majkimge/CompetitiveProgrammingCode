#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back


using namespace std;

lld a,b,t,stg,stp;
char s[100];

int main()
{
    scanf("%lld",&t);
    scanf("%lld",&a);
    scanf("%lld",&b);
    for(int xdd=1;xdd<=t;++xdd){
        lld hor=999999900;
        int in=0;
        int nin=0;
        int lhor=hor;
        int lvert=-50;
        for(int i=-50;i<=50;++i){
            if(in==0){
                cout<<hor<<" "<<i<<endl;
                scanf("%s",s);
                if(s[0]=='H'){
                    in=1;
                    lhor=hor;
                    lvert=i;
                    ++hor;
                    --i;
                }
            }else if(in==1){
                cout<<hor<<" "<<i<<endl;
                scanf("%s",s);
                if(s[0]=='H'){
                    lhor=hor;
                    lvert=i;
                    ++hor;
                    --i;
                }
            }
            if(hor>1000000000)break;
        }
        cout<<lhor-a<<" "<<lvert<<endl;
        scanf("%s",s);
    }

    return 0;
}
