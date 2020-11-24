#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 500009

using namespace std;

int w,h,n,x,y,kk=1;
map<int,int> mmx;
map<int,int> mmy;

int przedsx[MAX];
int przedsy[MAX];


pair<int,int> tab[MAX];
int xy[MAX];
int yy[MAX];
int kiedby[MAX];
lld wynik[5];

pair<pair<int,int>, int> tree[1100000];

void dod(int od, int dok, int gdz, int ile){
    od+=kk;
    dok+=kk;
    if(gdz==0){
        tree[od].f.f+=ile;
    }else if(gdz==1){
        tree[od].f.s+=ile;
    }else if(gdz==2){
        tree[od].s+=ile;
    }
    if(od!=dok){
        if(gdz==0){
            tree[dok].f.f+=ile;
        }else if(gdz==1){
            tree[dok].f.s+=ile;
        }else if(gdz==2){
            tree[dok].s+=ile;
        }
    }
    while(od/2!=dok/2){
        if(od%2==0){
            if(gdz==0){
                tree[od+1].f.f+=ile;
            }else if(gdz==1){
                tree[od+1].f.s+=ile;
            }else if(gdz==2){
                tree[od+1].s+=ile;
            }
        }

        if(dok%2==1){
            if(gdz==0){
                tree[dok-1].f.f+=ile;
            }else if(gdz==1){
                tree[dok-1].f.s+=ile;
            }else if(gdz==2){
                tree[dok-1].s+=ile;
            }
        }
        od>>=1;
        dok>>=1;
    }
}

int sum(int gdz, int jak){
    gdz+=kk;
    int ret=0;
    while(gdz){
        if(jak==0){
            ret+=tree[gdz].f.f;
        }else if(jak==1){
            ret+=tree[gdz].f.s;
        }else if(jak==2){
            ret+=tree[gdz].s;
        }
        gdz>>=1;
    }
    return ret;
}

int main()
{
    scanf("%d%d%d",&w,&h,&n);
    xy[0]=0;
    xy[1]=w;
    yy[0]=0;
    yy[1]=h;
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        tab[i]=mp(x,y);
        xy[i+2]=x;
        yy[i+2]=y;
    }
    while(kk<n)kk<<=1;
    sort(xy,xy+n+2);
    sort(yy,yy+n+2);
    int ktx=0;
    for(int i=0;i<n+2;++i){
        mmx[xy[i]]=ktx;
        przedsx[ktx]=xy[i];
        while(i<n+1&&xy[i]==xy[i+1])++i;
        ++ktx;
    }
    int kty=0;
    for(int i=0;i<n+2;++i){
        mmy[yy[i]]=kty;
        przedsy[kty]=yy[i];
        while(i<n+1&&yy[i]==yy[i+1])++i;
        ++kty;
    }
    for(int i=0;i<n+2;++i){
        kiedby[i]=-1;
    }
    sort(tab,tab+n);
    for(int i=0;i<n;++i){
        tab[i].f=mmx[tab[i].f];
        tab[i].s=mmy[tab[i].s];

    }

    for(int i=0;i<n;++i){
        //cout<<tab[i].f<<" "<<tab[i].s<<endl;
        int ter=tab[i].f;
        if(tab[i].s!=0){
            dod(0,tab[i].s-1,1,1);
        }
            wynik[1]+=przedsy[tab[i].s];
            int il2=0;
            int il1=0;
            if(kiedby[tab[i].s]==-1){
                il2=sum(tab[i].s,2);
                wynik[2]-=il2;
                wynik[3]+=il2;
                dod(tab[i].s,tab[i].s,2,-il2);

                il1=sum(tab[i].s,1);
                wynik[1]-=il1;
                wynik[2]+=il1;
                dod(tab[i].s,tab[i].s,1,-il1);

                wynik[1]+=przedsx[tab[i].f]-il1-il2;
            }else{
                il2=sum(tab[i].s,2);
                wynik[2]-=il2;
                wynik[4]+=il2;
                dod(tab[i].s,tab[i].s,2,-il2);

                il1=sum(tab[i].s,1);
                wynik[1]-=il1;
                wynik[3]+=il1;
                dod(tab[i].s,tab[i].s,1,-il1);

                wynik[2]+=przedsx[tab[i].f]-il1-il2-kiedby[tab[i].s]-1;
            }
            kiedby[tab[i].s]=przedsx[tab[i].f];
           // cout<<wynik[1]<<" "<<wynik[2]<<" "<<wynik[3]<<" "<<wynik[4]<<endl;

            while(i<n-1&&tab[i+1].f==ter){
                ++i;
                if(tab[i].s-1>=tab[i-1].s+1){
                    dod(tab[i-1].s+1,tab[i].s-1,2,1);
                }

                wynik[2]+=przedsy[tab[i].s]-przedsy[tab[i-1].s]-1;
                int il2=0;
                int il1=0;
                if(kiedby[tab[i].s]==-1){
                    il2=sum(tab[i].s,2);
                    wynik[2]-=il2;
                    wynik[3]+=il2;
                    dod(tab[i].s,tab[i].s,2,-il2);

                    il1=sum(tab[i].s,1);
                    wynik[1]-=il1;
                    wynik[2]+=il1;
                    dod(tab[i].s,tab[i].s,1,-il1);

                    wynik[1]+=przedsx[tab[i].f]-il1-il2;
                }else{
                    il2=sum(tab[i].s,2);
                    wynik[2]-=il2;
                    wynik[4]+=il2;
                    dod(tab[i].s,tab[i].s,2,-il2);

                    il1=sum(tab[i].s,1);
                    wynik[1]-=il1;
                    wynik[3]+=il1;
                    dod(tab[i].s,tab[i].s,1,-il1);

                    wynik[2]+=przedsx[tab[i].f]-il1-il2-kiedby[tab[i].s]-1;
                }
                kiedby[tab[i].s]=przedsx[tab[i].f];
                //cout<<tab[i].f<<" "<<tab[i].s<<endl;
                //cout<<wynik[1]<<" "<<wynik[2]<<" "<<wynik[3]<<" "<<wynik[4]<<endl;
            }

            if(tab[i].s+1<=kty){
                dod(tab[i].s+1,kty,1,1);
            }

            wynik[1]+=max(0,kty-przedsy[tab[i].s]-1);
            //cout<<tab[i].f<<" "<<tab[i].s<<endl;
            //cout<<wynik[1]<<" "<<wynik[2]<<" "<<wynik[3]<<" "<<wynik[4]<<endl;

    }

    for(int i=0;i<=kty;++i){
       // cout<<i<<endl;
        int ter=przedsy[i];
        if(kiedby[i]!=-1){
            int il2=sum(i,2);
            wynik[2]-=il2;
            wynik[3]+=il2;
            //dod(tab[i].s,tab[i].s,2,-il2);

            int il1=sum(i,1);
            wynik[1]-=il1;
            wynik[2]+=il1;
            //dod(tab[i].s,tab[i].s,1,-il1);
            //cout<<kiedby[tab[i]
            wynik[1]+=max(0,w-il1-il2-kiedby[i]);
        }
        //cout<<wynik[1]<<" "<<wynik[2]<<" "<<wynik[3]<<" "<<wynik[4]<<endl;
    }
    wynik[0]=(lld)(w+1)*(h+1)-n-wynik[1]-wynik[2]-wynik[3]-wynik[4];
    for(int i=0;i<5;++i){
        printf("%lld ",wynik[i]);
    }
    return 0;
}
