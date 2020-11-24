#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10004205361450474
#define MOD 1000000007
#define INF 1000696969

using namespace std;

lld ans;
int kt;

int check(){
    if(ans<0) exit(0);
}

pair<lld,lld> tenth(lld l,lld p,lld mini){
    lld coile=min(mini,p-l+1);
    lld prze=(p-l+1)/coile;
    if(kt==1) prze+=30;
    //kt++;
    cout<<coile<<" ";
    for(lld i=0;i<coile;++i){
        cout<<l+i*prze<<" ";

    }
    cout.flush();
    cin>>ans;
    if(ans<0){
        exit(0);
    }else{
        if(ans<coile){
            return mp(l+ans*prze+1,min(p,l+(ans+1)*prze)-1);
        }else{
            return mp(l+(ans-1)*prze+1,p);
        }

    }


}

int main()
{
    cout<<"1 10000 ";
    kt++;
    cout.flush();
    cin>>ans;
    check();
    if(ans==1){
        pair<lld,lld> temp;
        temp.f=10000;
        temp.s=MAX+1;
        while(kt<5){
            temp=tenth(temp.f,temp.s,10000);
            kt++;
        }
    }else{
        cout<<"2 2 100 ";
        cout.flush();
        cin>>ans;
        check();
        kt++;
        if(ans==2){
            pair<lld,lld> temp;
            temp.f=101;
            temp.s=9999;
            while(kt<5){
                temp=tenth(temp.f,temp.s,101);
                kt++;
            }
        }else{
            cout<<"3 3 10 50 ";
            cout.flush();
            cin>>ans;
            check();
            kt++;
            if(ans==3){
                pair<lld,lld> temp;
                temp.f=51;
                temp.s=99;
                while(kt<5){
                    temp=tenth(temp.f,temp.s,51);
                    kt++;
                }
            }else if(ans==2){
                pair<lld,lld> temp;
                temp.f=11;
                temp.s=49;
                while(kt<5){
                    temp=tenth(temp.f,temp.s,11);
                    kt++;
                }
            }else if(ans==1){
                pair<lld,lld> temp;
                temp.f=4;
                temp.s=9;
                while(kt<5){
                    temp=tenth(temp.f,temp.s,4);
                    kt++;
                }
            }
        }

    }


    return 0;
}
