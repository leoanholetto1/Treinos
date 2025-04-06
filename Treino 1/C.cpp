/*
Existe uma solução usando força bruta, você pode gerar todas as 
possibilidades de escolha de disas e testar qual gera o maior valor
*/
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

const int maxN= 1e5+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;
const ld PI = acos(-1.0);
const double eps = 1e-9;
const double DINF = 1e9;

//+19
//+6	
// \ | /
vi v,v2,v3;
int dp[maxN][2][2][2];

int f(int i,int flag,int flag2,int flag3){
	if(i==v.sz or (flag && flag2 && flag3)) return 0;
	if(dp[i][flag][flag2][flag3]!=-1) return dp[i][flag][flag2][flag3];
	int ans = f(i+1,flag,flag2,flag3);
	if(!flag) ans = max(ans,v[i]+f(i+1,1,flag2,flag3));
	if(!flag2) ans = max(ans,v2[i]+f(i+1,flag,1,flag3));
	if(!flag3) ans = max(ans,v3[i]+f(i+1,flag,flag2,1));
	return dp[i][flag][flag2][flag3]=ans;
}

void solve(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n;
		v.clear(); v2.clear(); v3.clear();
		for(int i=0;i<n;i++){
			cin>>k;
			v.pb(k);
			for(int j=0;j<2;j++){
				for(int p=0;p<2;p++){
					dp[i][j][p][0] = dp[i][j][p][1] = -1;
				}
			}
		}
		for(int i=0;i<n;i++){
			cin>>k;
			v2.pb(k);
		}
		for(int i=0;i<n;i++){
			cin>>k;
			v3.pb(k);
		}
		cout << f(0,0,0,0) << endl;
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