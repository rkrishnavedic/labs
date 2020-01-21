//Labs

#include "total.h"

#define fori(n) for(long long i=0;i<n;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define ll long long

using namespace std;

void qS(vector<ll> &v, ll l, ll r){
    ll p;
    ll i,j;
    if(l<r){
        i=l;j=r+1;
        p=v[l];
        do{
            do i++; while(v[i]<p);
            do j--; while(p<v[j]);
            if(i<j) swap(v[i],v[j]);
        }while(i<j);
        swap(v[l],v[j]);
        qS(v,l,j-1);
        qS(v,j+1,r);
    }
}

void merge(vector<ll> &v, ll l, ll m, ll r){
    vector<ll> a,b;
    for(ll i=l;i<=m;i++){
        a.push_back(v[i]);
    }
    for(ll i=m+1;i<=r;i++){
        b.push_back(v[i]);
    }
    ll k=l,i=0,j=0;
    ll x=a.size();ll y=b.size();
    while(i<x && j<y){
        if(a[i]<=b[j]){
            v[k]=a[i];i++;
        }else{v[k]=b[j];j++;}
        k++;
    }
    for(ll h=i;h<x;h++){
        v[k]=a[h];k++;
    }
    for(ll h=j;h<y;h++){
        v[k]=b[h];k++;
    }
}
void mergesort(vector<ll> &v, ll l, ll r){
    if(l<r){
        ll m=l+(r-l)/2;
        mergesort(v, l, m);
        mergesort(v, m+1, r);
        merge(v,l,m,r);
    }
}

void hal(ll x[],ll y[],ll n,ll a, ll b){
    ll c=0;ll t=0;ll z=0;
    fori(n){
        z=0;
        if(y[(i+1)%n]<y[i]){
            swap(y[(i+1)%n],y[i]);
            swap(x[(i+1)%n],x[i]);
            z=1;
        }
        if((y[i]-b)*(y[(i+1)%n]-b)<=0){
            if((x[(i+1)%n]-x[i])*(b-y[i])<(y[(i+1)%n]-y[i])*(a-x[i])){
                if(b!=y[(i+1)%n]) c++;
            }
            if((x[(i+1)%n]-x[i])*(b-y[i])==(y[(i+1)%n]-y[i])*(a-x[i])){
                t=1;break;
            }
        }
        if(z==1){swap(y[(i+1)%n],y[i]);
            swap(x[(i+1)%n],x[i]);}
    }
    if(t==1){
        cout<<"BORDER\n";
    }
    else{
        if(c%2!=0){cout<<"INSIDE\n";}
        else{
            cout<<"OUTSIDE\n";
        }
    }
}

int main(){
    cout<<"Om\n";
    //praise to lord
    //make cin/cout faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code now
    
    ll n;
    cin>>n;
    vector<ll> b(n);
    fori(n){
        cin>>b[i];
    }
    qS(b, 0, n-1);
    fori(n){
        cout<<b[i]<<" ";
    }
    
    return 0;
}
