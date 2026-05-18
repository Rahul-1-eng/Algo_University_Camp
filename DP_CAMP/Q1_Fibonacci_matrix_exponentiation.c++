#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define fe(i,b) for(auto &i:b)
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rv(a) cout<<a<<"\n";
vvi multiply(vvi &A, vvi &B){
    ll n=A.size(), m=A[0].size(), k=B[0].size();
    vvi C(n, vi(k,0));
    fr(i,0,n)
        fr(j,0,k)
            fr(l,0,m)
                C[i][j] += A[i][l]*B[l][j];

    return C;
}
vvi power(vvi A, ll p){
    ll n=A.size();
    vvi R(n, vi(n,0));
    fr(i,0,n) 
    R[i][i]=1;
    while(p){
        if(p&1) 
        R=multiply(R,A);
        A=multiply(A,A);
        p>>=1;
    }
    return R;
}
void solve(){
    ll n;
    cin >> n;
    vi base = {1,1,2,5,9,18};
    if(n <= 5)
    {
        rv(base[n])
        return;
    }
    vvi A = 
    {
        {2,1,2,-5,-4,-4},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0}
    };
    vvi P = power(A, n - 5);
    vi initial = {18, 9, 5, 2, 1, 1};
    ll ans = 0;
    fr(i,0,6)
    ans += P[0][i] * initial[i];
    rv(ans)
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while(t--) 
    solve();
}
