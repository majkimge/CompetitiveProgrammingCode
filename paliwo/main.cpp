#include <bits/stdc++.h>
#define lld long long
#define MAX 1000009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

pair<lld,lld> sta[MAX];
lld p,n,a,b,cena;
pair<lld,lld> tera[2];

int main()
{
    scanf("%lld",&p);
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        sta[i]=mp(a,b);
    }
    tera.pb(mp(sta[0].f,p-sta[0].s));
    cena+=sta[0].s*sta[0].f;
    for(int i=1;<n;++i){
        if(tera[0].f>=sta[i].f){
            tera[0]=mp(sta[i].f,p-sta[i].s);
            cena+=sta[i].s*sta[i].f;
        }else{
            if(tera[1].f>=sta[i].f){
                tera[1]=mp(sta[i].f,p-tera[0].s);
                tera[0]=mp(sta[i].f,tera[0].s-sta[i].s);
                cena+=tera[0].f*min(p-tera[1].s,sta[i].s)
                if(tera[0].s<0){
                    cena+=-tera[0].s*tera[1].f;
                    tera[1]=mp(tera[1].f,tera[1].s+tera[0].s);
                    tera[0]=tera[1];
                    tera[1]=mp(INF,INF);

                }else{

                }
            }

            if()
        }
    }

    return 0;
}
