#include<bits/stdc++.h>
//#pragma GCC target("popcnt")
//#include <boost/multiprecision/cpp_int.hpp>
//#include <bits/extc++.h>      
//#include <ext/pb_ds/assoc_container.hpp>

                
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vt vector
#define all(x) x.begin(),x.end()
#define unico(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin());
#define s second
#define f first
#define lc ((n)<<1)
#define rc ((n)<<1|1)
#define pb push_back
#define sz size()
#define isPowerOfTwo(S) (!(S & (S-1)))
#define LSOne(S) ((S)&-(S))
#define Log2(x) (31^__builtin_clz(x))
#define LLog2(x) (63 ^ __builtin_clzll(x))
#define mem(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

//typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pds; 
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ost;//repetido
//gp_hash_table<int, int> sMap;  
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,ll> pil;
using cd = complex<double>;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int dxx[] = {-1,-1,0,1,1,1,0,-1};
int dyy[] = {0,1,1,1,0,-1,-1,-1};

vt<pii> mov = {
	{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
	{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

const int maxN= 2*1e5+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;
const ld PI = acos(-1.0);
const double eps = 1e-9;
const double DINF = 1e9;

//+22
// \ | /

ll solve(vi &v,int flag){
	map<pii,int> mp;
	map<pii,map<int,int>> mp2;
	if(flag==1){
		for(int i=0;i+2<v.sz;i++){
			int a = v[i],b=v[i+1],c=v[i+2];
			mp[{a,b}]++;
			mp2[{a,b}][c]++;
		}
		ll ans = 0;
		for(int i=0;i+2<v.sz;i++){
			int a = v[i],b=v[i+1],c=v[i+2];
			ans+=mp[{a,b}];
			ans-=mp2[{a,b}][c];
		}
		return ans;
	}
	else if(flag==2){
		for(int i=0;i+2<v.sz;i++){
			int a = v[i],b=v[i+1],c=v[i+2];
			mp[{a,c}]++;
			mp2[{a,c}][b]++;
		}
		ll ans = 0;
		for(int i=0;i+2<v.sz;i++){
			int a = v[i],b=v[i+1],c=v[i+2];
			ans+=mp[{a,c}];
			ans-=mp2[{a,c}][b];
		}
		return ans;
	}
	else{
		for(int i=0;i+2<v.sz;i++){
			int a = v[i],b=v[i+1],c=v[i+2];
			mp[{b,c}]++;
			mp2[{b,c}][a]++;
		}
		ll ans = 0;
		for(int i=0;i+2<v.sz;i++){
			int a = v[i],b=v[i+1],c=v[i+2];
			ans+=mp[{b,c}];
			ans-=mp2[{b,c}][a];
		}
		return ans;
	}
}

void solve(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		string s;
		cin>>s;
		map<char,vi> mp,mp2;
		string ans(n,' ');
		for(int i=0;i<n;i++){
			mp[s[i]].pb(i);
		}
		for(auto p: mp){
			bool flag=1;
			for(int i=0;i<p.s.sz-(p.s.sz&1);i++){
				if(flag) ans[p.s[i]] = 'R';
				else ans[p.s[i]] = 'H';
				flag = 1 - flag;
			}
			if(p.s.sz&1) mp2[p.f].pb(p.s[p.s.sz-1]);
		}
		bool flag=1;
		if(mp2['N'].sz){
			if(mp2['S'].sz){
				ans[mp2['N'][0]] = 'R';
				ans[mp2['S'][0]] = 'R';
			}
			else flag = 0;
		}
		if(mp2['S'].sz){
			if(mp2['N'].sz){
				ans[mp2['N'][0]] = 'R';
				ans[mp2['S'][0]] = 'R';
			}
			else flag = 0;
		}
		if(mp2['W'].sz){
			if(mp2['E'].sz){
				ans[mp2['W'][0]] = 'H';
				ans[mp2['E'][0]] = 'H';
			}
			else flag = 0;
		}
		if(mp2['E'].sz){
			if(mp2['W'].sz){
				ans[mp2['W'][0]] = 'H';
				ans[mp2['E'][0]] = 'H';
			}
			else flag = 0;
		}
		int c1=0,c2=0;
		for(int i=0;i<ans.sz;i++){
			if(ans[i]=='R') c1=1;
			if(ans[i]=='H') c2=1;
		}
		flag&=c1;
		flag&=c2;
		if(flag) cout << ans << endl;
		else cout <<"NO" << endl;
	}
}	



void abrir(){
	string str = "";
	if(!str.empty()){
		freopen((str+".in").c_str(), "r", stdin);
		freopen((str+".out").c_str(), "w", stdout);
	}
}

int main() {
	IOS
	abrir();
	//clock_t tStart = clock();
	solve();
	//cerr<<fixed<<setprecision(10) << "\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl; 
	return 0;
}