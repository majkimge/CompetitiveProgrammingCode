#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 509
#define ENDER 1000009
using namespace std;

int n,k,c,a,il;
int dok[7],odw[MAX];
int zawb[7][MAX];
pair<int,int> zaw[7][MAX];
vector<int> wyny;
vector<int> brut;
int jacy[8];
int jacybr[8];
int ziomodw[MAX];
vector<int> dody;

/*void rob(int kt,int kol, int ziomo,int poczo){
    if(kt==k){
        int sum=0;
        for(int i=0;i<k;++i){
            int maxi=0;
            for(int j=0;j<k;++j){
                maxi=max(maxi,zawb[i][jacy[j]]);
            }
            sum+=maxi;
        }
        wyny.pb(sum);
        if(wyny.size()>ENDER)return;
    }else if(kt==kol){
        odw[ziomo]=1;
        jacy[kt]=ziomo;
        rob(kt+1,kol,ziomo);
    }else{
        for(int i=0;i<=dok[kt];++i){
            if(!odw[zaw[kt][i].s]){
                odw[zaw[kt][i].s]=1;
                jacy[kt]=zaw[kt][i].s;
                rob(kt+1,kol,ziomo);
                odw[zaw[kt][i].s]=0;
            }
        }


    }

}*/

void rob1(int kt,int ost){
    if(wyny.size()>ENDER)return;
    if(kt==k){

        if(ost>=dody.size())return;
        int sum=0;
        for(int i=0;i<k;++i){
            int maxi=0;
            for(int j=0;j<k;++j){
                maxi=max(maxi,zawb[i][jacy[j]]);
            }
            sum+=maxi;

        }
        //cout<<sum<<endl;
        wyny.pb(sum);
        if(wyny.size()>ENDER)return;
    }else{
        for(int i=ost+1;i<dody.size();++i){

            jacy[kt]=dody[i];
            rob1(kt+1,i);

        }


    }

}

pair<int,int> bestziomo(){
    int ret=-1;
    int kol=-1;
    int minim=1000000000;
    for(int i=0;i<k;++i){
        if(dok[i]<n-1){
            if(zaw[i][0].f-zaw[i][dok[i]+1].f<minim){
                minim=zaw[i][0].f-zaw[i][dok[i]+1].f;
                kol=i;
                ret=zaw[i][dok[i]+1].s;
            }
        }
    }
    return mp(kol,ret);
}

/*void br(int kt){
    if(kt==k){

        int sum=0;
        for(int i=0;i<k;++i){
            int maxi=0;
            for(int j=0;j<k;++j){
                maxi=max(maxi,zawb[i][jacybr[j]]);
            }
            sum+=maxi;
        }
        brut.pb(sum);
    }else{
        for(int i=0;i<n;++i){
            if(!odw[zaw[kt][i].s]){
                odw[zaw[kt][i].s]=1;
                jacybr[kt]=zaw[kt][i].s;
                br(kt+1);
                odw[zaw[kt][i].s]=0;
            }
        }
    }
}*/

int main()
{
    scanf("%d%d%d",&n,&k,&c);
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            scanf("%d",&a);
            zawb[j][i]=a;
            zaw[j][i]=mp(-a,i);
        }
    }
    for(int i=0;i<k;++i)sort(zaw[i],zaw[i]+n);
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){

            zaw[j][i].f=-zaw[j][i].f;
        }
    }
    /*rob(0,0,zaw[0][0].s,0);
    while(wyny.size()<ENDER&&bestziomo().f!=-1){
        pair<int,int> temp=bestziomo();
        cout<<temp.s<<endl;
        dok[temp.f]++;
        if(ziomodw[temp.s])continue;
        ziomodw[temp.s]=1;
        odw[temp.s]=1;
        rob(0,temp.f,temp.s);
        odw[temp.s]=0;
    }*/
    //cout<<odw[0];
    //br(0);
    //cout<<brut.size();
    for(int i=0;i<k;++i){
        if(!ziomodw[zaw[i][0].s]){
            ziomodw[zaw[i][0].s]=1;
            dody.pb(zaw[i][0].s);
        }

    }
    //for(int i=0;i<dody.size();++i)cout<<dody[i];
    rob1(1,0);
    while(wyny.size()<ENDER&&bestziomo().f!=-1){
        pair<int,int> temp=bestziomo();
        //cout<<temp.s<<endl;
        dok[temp.f]++;
        if(ziomodw[temp.s])continue;
        ziomodw[temp.s]=1;
        //odw[temp.s]=1;
        dody.pb(temp.s);
        swap(dody[0],dody[dody.size()-1]);
        jacy[0]=dody[0];
        rob1(1,0);
    }
    //cout<<wyny.size();
    //sort(brut.begin(),brut.end());
    sort(wyny.begin(),wyny.end());
    printf("%d\n",wyny[wyny.size()-c]);
   // printf("%d\n",brut[0]);
    return 0;
}
