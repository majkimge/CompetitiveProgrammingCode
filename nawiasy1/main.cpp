#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 2000000
#define INF 1000000000
using namespace std;

lld n, q, k,najm=INF+INF,co,ktory,do1,od1, ilemocy,najm2;
char nawiasy[MAX];
pair<lld,lld> tree[MAX];

pair<lld,bool> update(lld a, lld b, lld c, lld d,lld kt, lld co){
    pair<lld,bool> mocarz;
    pair<lld,bool> mocarz1;
    pair<lld,bool> mocarz2;
    pair<lld,bool> mocarz3;

    if(d<a||c>b){
            mocarz2=mp(tree[kt].f+tree[kt].s,0);
            //cout<<"A"<<tree[4].f;
        return mocarz2;
    }else
    if(c>=a&&d<=b){
            //if(kt==4) cout<<"B";
        tree[kt]=mp(tree[kt].f,tree[kt].s+co);
    mocarz2=mp(tree[kt].f+tree[kt].s,1);
    //cout<<"B"<<tree[4].f;
        return mocarz2;
    }else {
        mocarz=update(a,b,c,(c+d)/2,kt*2,co);
        mocarz1=update(a,b,(c+d)/2+1,d,kt*2+1,co);
        //cout<<mocarz1.f;
        //if(kt==4) cout<<"B";
        tree[kt]=mp(min(mocarz.f,mocarz1.f),tree[kt].s);
        mocarz2=mp(tree[kt].f+tree[kt].s,1);
        //cout<<mocarz2.f;
        //cout<<"C"<<tree[4].f;
        return mocarz2;
    }

}
void check(lld a,lld b,lld c,lld d,lld kt,lld sum){
    if(d<a||c>b){
        //return;
        //cout<<"A";
    }else if(c>=a&&d<=b){
        //cout<<kt<<endl<<tree[kt]
        najm=min(tree[kt].f+sum+tree[kt].s,najm);
        //cout<<"B";
        //return;
    }else{
        check(a,b,c,(c+d)/2,kt*2,sum+tree[kt].s);
        check(a,b,(c+d)/2+1,d,kt*2+1,sum+tree[kt].s);
        //return;
    }

}
int main()
{
    scanf("%lld",&n);

    scanf("%lld",&q);
    scanf("%s",nawiasy);
    ilemocy=1;
    while(ilemocy<n){
        ilemocy*=2;

    }
//cout<<n<<ilemocy<<endl;
    for(int i=0;i<n;i++){
        //scanf("%c",&naw[0]);
        if(nawiasy[i]=='('){
            tree[ilemocy+i]=mp(tree[ilemocy+i-1].f+1,0);
        }else{
            tree[ilemocy+i]=mp(tree[ilemocy+i-1].f-1,0);
        }
    }
    for(int i=n;i<ilemocy;i++){
        tree[i+ilemocy]=mp(INF,0);
    }
    k=ilemocy/2;
    while(k>0){
        for(int i=k;i<k*2;i++){
            tree[i]=mp(min(tree[i*2].f,tree[i*2+1].f),0);
        }
        k>>=1;
    }
     for(int i=1;i<ilemocy*2;i++){
                //cout<<tree[i].f;
               }
    for(int i=0;i<q;++i){
        scanf("%lld",&co);
        if(co==1){
                //cout<<"D"<<tree[4].f;
            scanf("%lld",&ktory);
            if(nawiasy[ktory-1]=='('){
               // cout<<nawiasy[ktory-1];
                update(ktory,ilemocy,1,ilemocy,1,-2);
                nawiasy[ktory-1]=')';
               }else{
                  // cout<<"B";
                update(ktory,ilemocy,1,ilemocy,1,2);
                nawiasy[ktory-1]='(';
               }
               for(int i=1;i<ilemocy*2;i++){
                //cout<<tree[i].f<<tree[i].s<<endl;
               }
               //cout<<ilemocy;

        }else{
            scanf("%lld",&od1);
            scanf("%lld",&do1);
            najm=INF+INF;
            if(od1==1){
                check(od1,do1,1,ilemocy,1,0);
                //cout<<najm;
                if(najm>=0){
                    najm=2*INF;
                    check(do1,do1,1,ilemocy,1,0);
                    if(najm==0){
                        printf("TAK\n");
                    }else{
                        printf("NIE\n");
                    }
                }else{
                    printf("NIE\n");
                }
            }else{
                najm=2*INF;
            check(od1,do1,1,ilemocy,1,0);
            lld najm1=najm;
            //cout<<najm1;
            najm=2*INF;
            check(od1-1,od1-1,1,ilemocy,1,0);
                //cout<<najm;
                if(najm1>=najm){
                        najm2=najm;
                        najm=INF*2;
                    check(do1,do1,1,ilemocy,1,0);
                    //cout<<najm;
                    if(najm-najm2==0){
                        printf("TAK\n");
                    }else{
                        printf("NIE\n");
                    }
                }else{
                    printf("NIE\n");
                }
            }


        }
    }

    return 0;
}
