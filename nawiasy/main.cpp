#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 2000000
#define INF 100000000000

using namespace std;

lld tree[MAX];
pair<pair<lld,lld>,bool> ost;
char nawiasy[MAX];
lld n;
lld q,ktory,co,od1,do1,k,ilemocy=1;

void update(lld x){
    int p=ilemocy+x;
    int b=ilemocy*2-1;

    if(tree[ilemocy+x]>tree[ilemocy+x-1]){
        if(p!=b){
            tree[p]-=2;
            tree[b]-=2;
        }
        while(p/2!=b/2){
            if(p%2==0){
                tree[p+1]-=2;
            }
            tree[p/2]=min(tree[p],tree[p+1]);

            if(b%2==1){
                tree[b-1]-=2;
            }
            tree[b/2]=min(tree[b],tree[b-1]);
            p>>=1;
            b>>=1;
        }
    }else{
        if(p!=b){
            tree[p]+=2;
            tree[b]+=2;
        }
        while(p/2!=b/2){
            if(p%2==0){
                tree[p+1]+=2;
            }
            tree[p/2]=min(tree[p],tree[p+1]);

            if(b%2==1){
                tree[b-1]+=2;
            }
            tree[b/2]=min(tree[b],tree[b-1]);
            p>>=1;
            b>>=1;
        }
        }
    }


bool check(lld a,lld b){
    bool jest;
    lld mini;
    lld a1=ilemocy+a;
    lld b1=ilemocy+b;
    if(a1!=b1){
        mini=min(tree[a1],tree[b1]);
    }
    while(a1/2!=b1/2){
        if(a1%2==0){
            mini=min(mini,tree[a1+1]);
        }
        if(b1%2==1){
            mini=min(mini,tree[b1-1]);
        }
        a1>>=1;
        b1>>=1;
    }
    a1=ilemocy+a;
    b1=ilemocy+b;
    if(a==0){
        if(mini>=0&&tree[b1]==0){
            return true;
        }else{
            return false;
        }
    }else{
        if(mini-tree[a1-1]>=0&&(tree[b1]-tree[a1-1])==0){
            return true;
        }else{
            return false;
        }
    }
    return jest;
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
            tree[ilemocy+i]=tree[ilemocy+i-1]+1;
        }else{
            tree[ilemocy+i]=tree[ilemocy+i-1]-1;
        }
    }
    for(int i=n;i<ilemocy;++i){
        tree[ilemocy+i]=INF;
    }
    k=ilemocy/2;
    while(k>0){
        for(int i=k;i<k*2;i++){
            tree[i]=min(tree[i*2],tree[i*2+1]);
        }
        k=k>>1;
    }

    for(int i=1;i<ilemocy*2;i++){
        //cout<<tree[i].f<<tree[i].s<<endl;
    }
    for(int i=0;i<q;++i){
        scanf("%lld",&co);
        if(co==1){
            scanf("%lld",&ktory);
            update(ktory-1);
        }else{
            scanf("%lld",&od1);
            scanf("%lld",&do1);
            bool moc=check(od1-1,do1-1);
            if(moc){
                printf("TAK\n");
            }else{
                printf("NIE\n");
            }
        }
    }
    return 0;
}
