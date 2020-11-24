#include <bits/stdc++.h>
#define lld unsigned long long
#define MAX 109
#define MOD 1000000000
#define mp make_pair
#define f first
#define s second

using namespace std;

lld n;
lld tab[3][3];
lld start[3];
lld ending[3];
lld wyni[3][3];
lld tab1[3][3];

void mno(lld jakie){
    if(jakie==0){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                for(int z=0;z<3;++z){
                    wyni[i][j]+=tab[i][z]*tab[z][j];
                    wyni[i][j]%=MOD;

                }
            }
        }
    }else if(jakie==1){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                tab1[i][j]=wyni[i][j];
                tab1[i][j]%=MOD;
                wyni[i][j]=0;
            }
        }
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                for(int z=0;z<3;++z){
                    wyni[i][j]+=tab1[i][z]*tab[z][j];
                    wyni[i][j]%=MOD;
                }
            }
        }
    }else if(jakie==2){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                tab1[i][j]=wyni[i][j];
                wyni[i][j]=0;
            }
        }
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                for(int z=0;z<3;++z){
                    wyni[i][j]+=tab1[i][z]*tab1[z][j];
                    wyni[i][j]%=MOD;
                }
            }
        }
    }else if(jakie==3){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                tab1[i][j]=wyni[i][j];
                wyni[i][j]=0;
            }
        }
        for(int i=0;i<3;++i){

                for(int z=0;z<3;++z){
                    wyni[i][0]+=tab1[i][z]*ending[z];
                    wyni[i][0]%=MOD;

                }//cout<<wyni[i][0]<<" ";

        }
    }else if(jakie==4){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                tab1[i][j]=wyni[i][j];
                wyni[i][j]=0;
            }
        }


                for(int z=0;z<3;++z){
                    wyni[0][0]+=tab1[z][0]*start[z];
                    wyni[0][0]%=MOD;
                }


    }
}

void pot(lld dok){
    //cout<<"F";
    if(dok==2){

        mno(0);
        return;
    }else if(dok%2==1){
        pot(dok-1);
        mno(1);
        //cout<<"G";
        return;
    }else if(dok%2==0){
        pot(dok/2);
        mno(2);
        return;
    }
}

int main()
{
    scanf("%lld",&n);
    tab[0][0]=0;
    tab[0][1]=0;
    tab[0][2]=1;
    tab[1][0]=0;
    tab[1][1]=0;
    tab[1][2]=2;
    tab[2][0]=2;
    tab[2][1]=1;
    tab[2][2]=4;
    start[0]=0;
    start[1]=2;
    start[2]=1;
    ending[0]=2;
    ending[0]=0;
    ending[0]=1;
    pot(n);
    mno(3);
    //mno(4);
    printf("%lld",wyni[0][0]);
    return 0;
}
