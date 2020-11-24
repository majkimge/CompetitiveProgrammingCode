#include <bits/stdc++.h>
#define lld long long
#define pb push_back

using namespace std;

lld n;
vector<lld> primes;



lld pot(lld co, lld dok, lld mod){
    if(dok==0)return 1;
    if(dok%2==0){
        lld temp=pot(co,dok/2,mod);
        temp*=temp;
        temp%=mod;
        return temp;
    }else{
        lld temp=pot(co,dok-1,mod);
        temp*=co;
        temp%=mod;
        return temp;
    }

}

int miller(lld num){
    lld ile=0;
    lld temp=num-1;
    if(!temp)temp++;
    while(temp%2==0){
        temp>>=1;
        ++ile;
    }
    for(int i=0;i<16;++i){
        lld a=rand()%num;
        if(!a)++a;
        lld dok=1;
        lld czy=1;
        //cout<<a<<" "<<pot(a,temp,num)<<" "<<temp<<endl;
        if(pot(a,temp,num)==1){
            czy=0;
            continue;
        }
        for(int j=0;j<=ile;++j){
            if(pot(a,temp*dok,num)==num-1){
                czy=0;

            }
            dok<<=1;
        }
        if(czy)return 1;
    }
    return 0;
}

int pollard(lld num, lld c){
    //cout<<num<<endl;
    lld i=1;
    lld k=2;
    lld x=rand()%num;
    lld y=x;
    if(num==1||miller(num)==0){
        primes.pb(num);
        return 1;
    }
    while(true){
        x=(x*x-c+num*4)%num;
        lld fac=__gcd(abs(x-y),num);
        /*if(i<10){
            cout<<x<<" "<<y<<endl;
        }*/
        if(fac!=1&&fac!=num){
            pollard(fac,1);
            pollard(num/fac,1);
            return 1;
        }

        if(i*i*i*i>num){
            pollard(num,3);
            return 1;
        }
        if(i==k){
            k<<=1;
            y=x;
        }
        ++i;
    }
}

int main()
{
    scanf("%lld",&n);
    srand(time(0));
    cout<<miller(n)<<endl;
    pollard(n,1);
    cout<<(lld)15485993*15485941;
    sort(primes.begin(),primes.end());
    for(int i=0;i<primes.size();++i){
        //cout<<primes[i]<<" ";
    }
    return 0;
}
