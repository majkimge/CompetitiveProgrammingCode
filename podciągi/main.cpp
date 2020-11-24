#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 5000009

using namespace std;

lld n,q;
vector<lld> roz;
vector<char>alf;
lld czypier[309];

int main()
{
    scanf("%lld",&q);
    for(lld i=2;i<307;++i){
        for(lld j=2;j*j<=307;++j){
            if(i%j==0) break;
        }
        czypier[i]=1;
    }
    for(char i='a';i<='z';++i){
        alf.pb(i);
    }
    for(char i='A';i<='Z';++i){
        alf.pb(i);
    }
    for(char i='1';i<='9';++i){
        alf.pb(i);
    }
    for(lld xx=0;xx<q;++xx){
        roz.clear();
        scanf("%lld",&n);
        lld dl=0;
        lld jed=0;
        lld xd=0;
        lld czy=1;
        lld tn=n;
        while(tn){
            dl++;

            if(!jed&&tn%2==1){
                xd=dl;
                jed=1;

            }else if(jed&&tn%2==0){
                //cout<<dl;
                czy=0;
            }
            tn>>=(lld)1;
        }
        //cout<<dl;
        if(czy&&n%2==1){
                //cout<<"A";
            for(int i=0;i<dl-1;++i){
               printf("%c",alf[i]);
            }
            printf("%c",alf[xd-1]);
        }else{

            for(lld i=2;i<=308;++i){
                while(n%i==0&&czypier[i]){
                    roz.pb(i);
                    n/=i;
                }
            }
            lld kt=0;
            for(lld i=0;i<roz.size();++i){
                //cout<<roz[i];
                for(lld j=0;j<roz[i]-1;++j){
                    printf("%c",alf[kt]);
                }
                kt++;
            }
        }

    printf("\n");
    }
    return 0;
}
