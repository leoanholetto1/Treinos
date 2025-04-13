#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vet(Type) vector<Type>
#define s second
#define f first
#define pb push_back
#define sz size()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct point{
    ll x, y;
    int id;
    point(ll x=0, ll y=0): x(x), y(y){}

    point operator+(const point &o) const{ return {x + o.x, y + o.y}; } // a + b
    point operator-(const point &o) const{ return {x - o.x, y - o.y}; } // a - b
    point operator*(ll t) const{ return {x * t, y * t}; } // a * t
    point operator/(ll t) const{ return {x / t, y / t}; } // a / t
    ll operator*(const point &o) const{ return x * o.x + y * o.y; } // Escalar  (a * b)
    ll operator^(const point &o) const{ return x * o.y - y * o.x; } // Vetorial (a ^ b)
};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

const int maxN=1e3+5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;
const ll M2 = 998244353;
const ll M1 = 100000007;
const ld PI = acos(-1.0);
const double ep = 1e-9;

template <typename T>
vector<T> create_vector(size_t size) {
    return vector<T>(size);
}

void solve(){
    set<string> s,s2;
    string str;
    while(getline(cin,str)){
        int i=0;
        while(i<str.sz){
            string resp;
            while(i<str.sz && str[i]==' ') i++;
            while(i<str.sz && str[i]!=' '){
                resp+=str[i];
                i++;
            }
            if(resp.sz>0) s.insert(resp);
        }
    }
    for(auto p: s){
        for(auto x: s){
            if(p!=x) s2.insert(p+x);
        }
    }
    for(auto p: s2) cout<<p<<endl;
}  

int main() {
    IOS;
    //clock_t tStart = clock();
    solve();
    //cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    return 0;
}