#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 50009
#define MOD 1000000009

using namespace std;

lld n,a,b,c,d;
lld w1,w2;
double c1,c2;

lld pot(lld co,lld dok){
    if(dok<=0){
        return 1;
    }else if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%(b);

    }else{
        return (co*pot(co,dok-1))%(b);
    }



}

pair<lld,lld> euklides(lld a, lld b,lld cc){
    if(b==0){
        return(mp(a,b));
    }
    pair<lld,lld> temp=euklides(b,a%b,cc);
    return mp(temp.s,(cc-a*temp.s)/b);
}



int main()
{

    while(true){
        scanf("%lld",&n);
        if(!n) break;
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        scanf("%lld",&d);
        c1=(double) a/b;
        c2=(double) c/d;
        int swaper=0;
        if(c1>=c2){
            swap(c1,c2);
            swap(a,c);
            swap(b,d);
            swaper=1;
        }
        if(c1<=c2){
            //lld temp=0;
            if(n%b==0&&n>=b){
                if(swaper){
                    printf("0 %lld\n",n/b);
                }else{
                    printf("%lld 0\n",n/b);
                }

            }else{
                lld temp=n%b;
               // cout<<" "<<temp<<" ";
                lld temp1=d%b;
                //cout<<temp1<<" ";
                //cout<<__gcd(temp1,b)<<" ";
                if(__gcd(temp1,b)!=1){
                    if(n%d==0&&n>=d){

                        if(swaper){
                            printf("%lld 0\n",n/d);
                        }else{
                            printf("0 %lld\n",n/d);
                        }

                    }else{
                        if(b>n/2&&(n-b)%d==0){
                            if(!swaper){
                                printf("1 %lld\n",(n-b)/d);
                            }else{
                                printf("%lld 1\n",(n-b)/d);
                            }
                        }else{
                            //cout<<"F";
                            printf("failed\n");
                        }

                    }
                }else{
                    //lld temp2=temp*pot(temp1,b-2);
                    //cout<<" "<<(euklides(555,8884).f)%b<<" ";
                    lld temp3=euklides(temp1,b,__gcd(temp1,b)).f;
                    if(temp3<0)temp3=b+temp3;

                    lld temp2=temp*temp3;
                    if(b<2){
                        temp2=0;
                    }



                    temp2%=b;
                    //cout<<temp2<<" ";
                    if(temp2*d+b>n){
                        if(n==(temp2*d)){ //cout<<"F";
                            if(swaper){
                                printf("%lld 0\n",n/d);
                            }else{
                                printf("0 %lld\n",n/d);
                            }
                        }else{
                            if(b>n/2&&(n-b)%d==0){
                            if(!swaper){
                                printf("1 %lld\n",(n-b)/d);
                            }else{
                                printf("%lld 1\n",(n-b)/d);
                            }
                        }else{
                            //cout<<"F";
                            printf("failed\n");
                        }
                        }

                    }else{
                        if(swaper){
                            printf("%lld %lld\n",temp2,(n-temp2*d)/b);
                        }else{
                            printf("%lld %lld\n",(n-temp2*d)/b,temp2);//cout<<temp2;
                        }
                    }



                }
            }
        }
    }
    return 0;
}
