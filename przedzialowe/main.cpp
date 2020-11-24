#include <bits/stdc++.h>

#define lld long long
#define MAX 100000000
using namespace std;

lld n;
lld lev=0;
lld len;
lld a,b,c,d;
//lld tab[MAX];
lld tab[MAX];

lld query(lld a,lld b){
    lld suma=0;
    if(a==b){
        return tab[a];
    }
    suma+=tab[a]+tab[b];
    while((a/2)!=(b/2)){
        if(a%2==0){
            suma+=tab[a+1];
        }
        if(b%2==1){
            suma+=tab[b-1];
        }
        a=a/2;
        b=b/2;
    }
    return suma;
}

void act(lld a,lld k){
    while(a!=0){
        tab[a]+=k;
        a=a/2;
    }
}
int main()
{
    //std::ios_base::sync_with_stdio(0);
    cin>>n;

    for(lld i=1;i<=n*2;i*=2){
        lev++;
        len=i;
        //cout<<i;
        //cout<<n;
    }
    for(lld i=0;i<n;i++){
        cin>>tab[len+i];
    }
    cin>>c;
    cin>>d;
    cin>>a;
    cin>>b;
    lld k=lev-1;
    while(k>0){
        for(lld i=pow(2,k-1);i<pow(2,k);++i){
            tab[i]=tab[i*2]+tab[i*2+1];
        }
        k--;
    }
    tab[1]=tab[2]+tab[3];
    act(c+len-1,d);
    cout<<query(a+len-1,b+len-1);

    return 0;
}
