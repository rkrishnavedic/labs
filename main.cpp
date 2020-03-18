//#include <bits/stdc++.h>
#include "Header.h"

#define pi 3.14159265358979323846264

#define ll long long
#define fori(n) for(long long i=0;i<n;i++)
#define forj(n) for(long long j=0;j<n;j++)

#define sp(n) setprecision(n)
#define d7 1000000007
#define mkp make_pair
#define mkt make_tuple

using namespace std;

bool isPrime(long long k){
    if(k<=1){return false;}
    if(k==2){return true;}
    if(k%2==0){return false;}
    long long i = 3;
   while (i*i <= k) {if (k % i == 0) {return false;}i += 2;}
return true;
}

ll binomialCoeff(ll n, ll k){
    ll C[n + 1][k + 1];ll i, j;
    for (i = 0; i <= n; i++){
        for (j = 0; j <= min(i, k); j++){
            if (j == 0 || j == i){C[i][j] = 1;}
            else{C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);}}}
    return C[n][k];
 }

ll gcd(ll a, ll b){if (b == 0)
        return a;return gcd(b, a % b);}

ll srihrg(ll n,ll k,ll m){
    ll ans;
    ans=1;
    fori(k){
        ans=(ans*n)%m;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
 cout<<"Om\n";
 //Praise to Lord
 //make cin/cout faster
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
// code now
   
    ll n,k;
    k=100;
    n=100;
    n=n-(n%7);
    
    vector<ll> v;
    
    fori(k){
        n+=7;
        //n=(i+10)*(i+10);
        ll sq=(sqrt(double(n)));
        if(!isPrime(n+1)&&(sq*sq!=n)){continue;}
        
        bool t4=false,t5=false;
        ll h=n;bool y3=false,y8=false;
        while(h>0){
            if(h%10==3){y3=true;break;}
            h/=10;
        }
        h=n;
        while(h>0){
            if(h%10==8){y8=true;break;}
            h/=10;
        }
        h=n;
        if((y3&&(!y8))||(y8&&(!y3))){t4=true;}
        
        bool sn=false, s11=false;
        ll sum=0;
        while(h!=0){
            sum+=h%10;
            h/=10;
        }
        if(n%11==0){s11=true;}
        sn=isPrime(sum);
        
        if((s11&&(!sn))||(sn&&(!s11))){t5=true;}
        
        if(t4&&t5){v.push_back(n);break;}
    }
    
    if(v.size()==0){cout<<"NO";}
    else{cout<<"YES"<<" "<<v[0];}
    
//code ends
    return 0;
}
