#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define fe(i,b) for(auto &i:b)
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define ry cout<<"YES\n";
#define rn cout<<"NO\n";
#define rv(a) cout<<a<<"\n";
#define rh(a) cout<<a<<" ";
void solve()
{
  ll n,q;
  cin>>n>>q;
  vi b(n),c;
  for(auto &i:b)
  {
    cin>>i;
  }
  ll r=sqrt(n);
  for(int i=0;i<n;i+=r)
  {
    ll s=0;
    for(int j=0;j<r;j++)
    {
      if(i+j>=n)
      break;
      s+=b[i+j];
    }
    c.push_back(s);
  }
  vi d(c.size()+1,0);
  ll a=1;
  for(auto i:c)
  {
    // cout<<i<<" ";
    d[a]=d[a-1]+i;
    a++;
  }
  cout<<endl;
  for(int i=0;i<q;i++)
  {
    ll t=0;
    string w;
    if(i==0)
    cin.ignore();
    getline(cin,w);
    // cout<<w<<endl;
    ll s=0,j=2;
      for(;w[j]>='0'&&w[j]<='9';j++)
      {
          s*=10;
          s+=w[j]-'0';
      }
      t=s;
      s=0;
      j++;
      for(;w[j]>='0'&&w[j]<='9';j++)
      {
          s*=10;
          s+=w[j]-'0';
      }
      // cout<<t<<s<<endl;
      ll p=t,h=s;
    if(w[0]=='1')
    {
      if(t%r==0)
      {
        t/=r;
      }
      else
      {
        t/=r;
        t++;
      }
      // cout<<t<<b[p-1]<<s<<endl;
      c[t-1]-=b[p-1];
      c[t-1]+=s;
      for(ll j=t;j<=c.size();j++)
      {
        d[j]+=s-b[p-1];
      }
      b[p-1]=s;
      for(auto i:c)
      {
        cout<<i<<" ";
      }
      cout<<endl;
    }
    else
    {
      ll y=0;
      if(t%r==0)
      {
        t/=r;
      }
      else
      {
        t/=r;
        t++;
      }
      for(ll j=max(p-1,0LL);j<min(t*r,n);j++)
      y+=b[j];
      // cout<<y<<endl;
      if(s%r==0)
      {
        s/=r;
      }
      else
      {
        s/=r;
        s++;
      }
      for(ll j=min(h-1,n-1);j>=max((s-1)*r,0LL);j--)
      {
        y+=b[j];
      }
      y+=d[s-1]-d[t];
      cout<<y<<endl;
    }
    for(auto i:b)
    cout<<i<<" ";
    cout<<endl;
  }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}
