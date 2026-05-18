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
  vector<map<char,int>> c;
  string b;
  cin>>n>>q;
  cin>>b;
  // cout<<b;
  ll r=sqrt(n);
  for(int i=0;i<n;i+=r)
  {
    map<char,int> o;
    for(int j=0;j<r;j++)
    {
      if(i+j>=n)
      break;
      o[b[i+j]]++;
    }
    c.push_back(o);
  }
  vector<map<char,int>> d(c.size()+1);
  ll a=1;
  for(int i=1;i<=c.size();i++)
  {
    for(char j='a';j<='z';j++)
    {
      d[i][j]=d[i-1][j];
    }
    for(auto j:c[i-1])
    {
      d[i][j.first]+=j.second;
    }
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
    if(w[0]=='1')
    {
      ll s=0,j=2;
      for(;w[j]>='0'&&w[j]<='9';j++)
      {
          s*=10;
          s+=w[j]-'0';
      }
      t=s;
      j++;
      char x=w[j];
      ll p=t;
      if(t%r==0)
      {
        t/=r;
      }
      else
      {
        t/=r;
        t++;
      }
      c[t-1][x]++;
      c[t-1][b[p-1]]--;
      for(ll j=t;j<=c.size();j++)
      {
        d[j][x]+=1;
        d[j][b[p-1]]-=1;
      }
      b[p-1]=x;
      for(auto i:c)
      {
        for(auto j:i)
        {
          cout<<j.first<<" "<<j.second<<" | ";
        }
        cout<<endl;
      }
      cout<<endl;
    }
    else
    {
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
      char x;
      j++;
      x=w[j];
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
      {
        if(b[j]==x)
        y++;
      }
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
        if(b[j]==x)
        y++;
      }
      y+=d[s-1][x]-d[t][x];
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
