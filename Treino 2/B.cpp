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

const int maxN= 1e6+1;
const int maxN2= 1e6;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;
const ld PI = acos(-1.0);
const double eps = 1e-9;
const double DINF = 1e9;

//+19
//+28
//+10
// \ | /


void solve(){
    int n,q,a,b,c;
    cin>>n>>q;
    vi v(n+1);
    for(int i=1;i<=n;i++){
        cin>>a;
        v[i] = a;
    }
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            v[b] = c;
        }
        else cout << abs(v[b]-v[c]) << endl;
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