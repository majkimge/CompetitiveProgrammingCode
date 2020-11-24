#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define MAX 300009
#define f first
#define s second
#define pii pair<lld,lld>

using namespace std;

int n,m,a,b;

struct node{
    int roz;
    int war;
    lld prior;
    node * lew;
    node * praw;
    node * ojc;

    node(int wara){
        roz=1;
        war=wara;
        prior=rand()%1000000000;
        lew=NULL;
        praw=NULL;
        ojc=NULL;
    }
};

void lrot(node * gdz){
    gdz->roz+=gdz->ojc->praw->roz+1;
    gdz->ojc->roz=gdz->ojc->praw->roz+gdz->praw->roz+1;
    gdz->ojc->lew=gdz->praw;
    node * temp=gdz->ojc->ojc;
    gdz->praw=gdz->ojc;
    gdz->ojc->ojc=gdz;
    gdz->ojc=temp;
}

void rrot(node * gdz){
    gdz->roz+=gdz->ojc->lew->roz+1;
    gdz->ojc->roz=gdz->ojc->lew->roz+gdz->lew->roz+1;
    gdz->ojc->praw=gdz->lew;
    gdz->lew=gdz->ojc;
    node * temp=gdz->ojc->ojc;
    gdz->ojc->ojc=gdz;
    gdz->ojc=temp;
}

void wgor(node*gdz){
    while(gdz->prior>gdz->ojc->prior){
        if(gdz->war>gdz->ojc->war){
            rrot(gdz);
        }else{
            lrot(gdz);
        }
    }
}

int add(int wart, node * gdz){

    if(wart>gdz->war){

        if(gdz->praw!=NULL){//cout<<"A";
            add(wart,gdz->praw);
        }else{ //cout<<"X";
            gdz->roz++;
            gdz->praw=&node(wart);
            gdz->praw->ojc=gdz;
            //wgor(temp1);
        }
    }else{
        if(gdz->lew!=NULL){
            add(wart,gdz->lew);
        }else{
            gdz->roz++;
            gdz->lew=&node(wart);
            gdz->lew->ojc=gdz;
            //wgor(temp1);
        }
    }
}

void prin(node * gdz){
    //cout<<gdz->ojc->war<<endl;
    if(gdz->lew!=NULL){
        node * tx=gdz->lew;
        prin(tx);
    }
    cout<<gdz->war<<" ";
    if(gdz->praw!=NULL){
        node * tx=gdz->praw;
        prin(tx);
    }
    return;
}

int main()
{
    scanf("%d",&n);
    srand(time(0));
    node korz=node(-1);
    korz.prior=1000000000;
    korz.ojc=&korz;
    node * tempor=&korz;
    for(int i=1;i<=n;++i){
        add(i,tempor);
    }
    //cout<<tempor->lew->war;
    /*node temp=node(1);
            node * temp1= &temp;
            tempor->roz++;
            tempor->praw=temp1;
            temp1->ojc=tempor;*/
    //cout<<tempor->praw->war;
    prin(tempor);
    return 0;
}
