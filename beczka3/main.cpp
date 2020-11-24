#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009

using namespace std;

double vv,s,h,komh,dod,dodw,ss,rw;
double dlug[MAX];
double wys[MAX];
double gest[MAX];
double gest1[MAX];
double dlap[MAX];
priority_queue<pair<double,int> >q;
vector<pair<double,int> >v;
int czyj[MAX];
int n;

int main()
{
    scanf("%lf",&s);
    ss=s;
    scanf("%lf",&h);
    scanf("%lf",&vv);
    komh=vv/s;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lf",&dlug[i]);
        scanf("%lf",&gest1[i]);
        gest[i]=min(gest1[i],(double)1.00000000);
        dod=(min(komh,dlug[i]*gest[i]))*dlug[i]*dlug[i];

        dodw=0;
        if(dlug[i]*gest[i]>komh){
            czyj[i]=1;
            wys[i]=dlug[i];
            s-=dlug[i]*dlug[i];
            q.push(mp(-dlug[i]*gest[i],i));
        }else{
            wys[i]=komh+dlug[i]-dlug[i]*gest[i];
        }

        while(!q.empty()&&-q.top().f<=dod/s+komh){
            double temp=0;

            temp=(-q.top().f-komh)*s;
            dodw+=-q.top().f-komh;
            komh=-q.top().f;
            czyj[q.top().s]=0;
            s+=dlug[q.top().s]*dlug[q.top().s];
            dod-=temp;
            q.pop();
        }
        komh+=dod/s;
        dodw+=dod/s;
        //cout<<komh<<endl;
        for(int j=0;j<=i;++j){
            if(!czyj[j]&&gest1[j]<1.00000000){
                wys[j]+=dodw;//cout<<"X"<<wys[1]<<endl;
                //cout<<wys[0]<<endl;
            }
        }

    }
    for(int i=0;i<n;++i){
        v.pb(mp(wys[i],i));
    }
    sort(v.begin(),v.end());
    double ww=v[n-1].f;
    //cout<<ww;
    dod=0;
    double szer=dlug[v[n-1].s]*dlug[v[n-1].s];

    /*dod=dlug[v[n-1].s]*dlug[v[n-1].s];

    if(ww>h){
        for(int i=n-2;i>=0;--i){
            if(v[i].f>h){
                if(i-1)
            }
        }
    }*/

    cout<<wys[0]<<endl;
    cout<<"A";
    ss=s;
    if(ww>h){
        int kk=n-2;
        while(kk>=0&&wys[v[kk].s]>h){
            //cout<<wys[v[kk].s];
            rw=(ww-wys[v[kk].s])*s/(szer+s);
        cout<<rw<<endl;
            dod=rw*szer;
            szer+=dlug[v[kk].s]*dlug[v[kk].s];

            ww-=rw;

                while(!q.empty()&&-q.top().f<=dod/s+komh){
                    double temp=0;
                    temp=(-q.top().f-komh)*s;
                    dodw+=-q.top().f-komh;
                    komh=-q.top().f;
                    czyj[q.top().s]=0;
                    s+=dlug[q.top().s]*dlug[q.top().s];
                    dod-=temp;
                    q.pop();
                }
                komh+=dod/s;
                cout<<komh;
                dodw+=dod/s;
                for(int j=kk;j>=0;--j){
                    if(!czyj[j]&&gest1[j]<1.0000000){
                        wys[j]+=dodw;
                    }
                }
                kk--;
        }
        rw=(ww-h);
            dod=rw*szer;
            //szer+=dlug[v[kk].s]*dlug[v[kk].s];
            ww-=rw;

                while(!q.empty()&&-q.top().f<=dod/s+komh){
                    double temp=0;
                    temp=(-q.top().f-komh)*s;
                    dodw+=-q.top().f-komh;
                    komh=-q.top().f;
                    czyj[q.top().s]=0;
                    s+=dlug[q.top().s]*dlug[q.top().s];
                    dod-=temp;
                    q.pop();
                }
                komh+=dod/s;
                dodw+=dod/s;
                for(int j=kk;j>=0;--j){
                    if(!czyj[j]&&gest1[j]<1.0000000){
                        wys[j]+=dodw;
                    }
                }

    }




    printf("%.14lf",min(h,komh));
    return 0;
}
/*
100 4 300
3
2 0.1
2 0.9
2 0.5
*/
