#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 20009
#define iNF 1000000009
#define MOD 1000696969

using namespace std;

int k,n,dl,temp;
int mody[20009];
int poktorym1[12][12];
int poktorym0[12][12];
vector<int> modv;
vector<int> liczby[7];
vector<int> wynik;
int odw[MAX];
int wierz[MAX][4];
queue<int> q;

int solve(int cot,int moda){
    odw[moda]=1;
    //cout<<moda;
    if(mody[moda]){
        printf("%d",mody[moda]);
        //cout<<"A"<<moda;
        return 1;
    }
    //cout<<poktorym0[6][2];
    if(poktorym0[moda][cot%10]!=-1&&!odw[((poktorym0[moda][cot%10]*cot+moda)/10)%cot]){
        //cout<<poktorym0[moda][cot%10]*cot/10;
        if(solve(cot,((poktorym0[moda][cot%10]*cot+moda)/10)%cot)){
            //printf("0");
            wynik.pb(0);
            return 1;
        }
    }
    if(poktorym1[moda][cot%10]!=-1&&!odw[((poktorym1[moda][cot%10]*cot+moda)/10)%cot]){

        if(solve(cot,((poktorym1[moda][cot%10]*cot+moda)/10)%cot)){
            //printf("0");
            wynik.pb(1);
            return 1;
        }
    }
    return 0;

}

int solve1(int cot){
    //
    cout<<"A"<<mody[3];
    while(!q.empty()){
        int moda=q.front();
        q.pop();
        //cout<<moda;
        odw[moda]=1;
        if(mody[moda]){
            printf("%d",mody[moda]);
            //cout<<"A"<<moda;
            int gdz=moda;
            while(gdz!=0){
                //cout<<gdz;
                //printf("%d",wierz[moda][4]);
                cout<<gdz;
                gdz=wierz[moda][3];
            }
            return 1;
            break;
        }else{
            if(poktorym0[moda][cot%10]!=-1&&!odw[((poktorym0[moda][cot%10]*cot+moda)/10)%cot]){
        //cout<<poktorym0[moda][cot%10]*cot/10;
        odw[((poktorym0[moda][cot%10]*cot+moda)/10)%cot]=1;
                wierz[((poktorym0[moda][cot%10]*cot+moda)/10)%cot][4]=0;
                wierz[((poktorym0[moda][cot%10]*cot+moda)/10)%cot][3]=moda;
                q.push(((poktorym0[moda][cot%10]*cot+moda)/10)%cot);
            }

            if(poktorym1[moda][cot%10]!=-1&&!odw[((poktorym1[moda][cot%10]*cot+moda)/10)%cot]){
                    odw[((poktorym1[moda][cot%10]*cot+moda)/10)%cot]=1;
                wierz[((poktorym1[moda][cot%10]*cot+moda)/10)%cot][4]=1;
                wierz[((poktorym1[moda][cot%10]*cot+moda)/10)%cot][3]=moda;
                q.push(((poktorym1[moda][cot%10]*cot+moda)/10)%cot);

            }

        }
    }
    return 0;
}


void dodaj(int dlug,int cot,int ktor){
    if(ktor==dlug){
        cot*=10;
        liczby[dlug].pb(cot);
        liczby[dlug].pb(cot^1);
    }else{
        cot*=10;
        dodaj(dlug,cot,ktor+1);
        dodaj(dlug,cot^1,ktor+1);
    }
}

int main()
{
    scanf("%d",&k);
    for(int i=1;i<=6;++i){
        dodaj(i,1,1);
    }
    for(int i=0;i<=9;++i){
        for(int j=1;j<=9;++j){
            int wyn=1;
            int tt=i+j;
            if((i%2==0&&j%2==0)||(j==5&&i%5!=1)){
                poktorym1[i][j]=-1;
            }else{
                while(tt%10!=1){
                    wyn++;
                    tt+=j;

                    //cout<<i<<" "<<j<<endl;

                }
                poktorym1[i][j]=wyn;
            }

        }
    }
    for(int i=0;i<=9;++i){
        for(int j=1;j<=9;++j){
            int wyn=1;
            int tt=i+j;
            if((i%2==1&&j%2==0)||(j==5&&i%5!=0)){
                poktorym0[i][j]=-1;
            }else{
                while(tt%10!=0){
                    wyn++;
                    tt+=j;

                }
                poktorym0[i][j]=wyn;
            }

        }
    }
    //cout<<poktorym1[3][2];

    for(int i=0;i<k;++i){
        scanf("%d",&n);
        temp=n;
        dl=0;
        while(temp>0){
            dl++;
            temp/=10;
        }
        //modv.clear();
        for(int j=0;j<n;++j){
            mody[j]=0;
            odw[j]=0;
        }
        //cout<<dl;
        for(int j=0;j<liczby[dl].size();++j){
            //modv.pb(liczby[dl][j]%n);
            for(int z=dl;z<=6;++z){
                if(!mody[liczby[z][j]%n]){
                mody[liczby[z][j]%n]=liczby[z][j];
                //cout<<liczby[dl][j]<<" "<<liczby[dl][j]%n<<endl;
                }
            }


        }
        q.push(0);
        if(solve1(n)){

        }else{
            printf("BRAK");
        }
        printf("\n");
        wynik.clear();

    }
    return 0;
}
