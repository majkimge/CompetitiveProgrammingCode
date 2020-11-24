#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

int n,c,a,b;

int main()
{
    scanf("%d",&n);
    scanf("%d",&c);
    scanf("%d",&a);
    scanf("%d",&b);
    if(b>a){
        swap(a,b);
    }
    if(a+b<=c){
        printf("%.11lf",(double) 0);
    }else if(a>=c){
        printf("%.11lf",(double) 1);
    }else
        {
        printf("%.11lf",(double) (b-c+a)/c);
    }

    return 0;
}
