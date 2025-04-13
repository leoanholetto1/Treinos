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

const int maxN=1e6+5;
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
    int n;
    string s;
    int i,j;
    while(cin>>n && n){
        char vet[32];
        for(int i=0;i<32;i++) vet[i] = '?';
        while(n--){
            cin>>s;
            if(s=="SET"){
                cin>>i;
                vet[i] = 1;
            }
            else if(s=="CLEAR"){
                cin>>i;
                vet[i] = 0;
            }
            else if(s=="OR"){
                cin>>i>>j;
                if(vet[i]==1 || vet[j]==1) vet[i] = 1;
                else if(vet[i]==0 && vet[j]==0) vet[i] = 0;
                else vet[i] = '?';
            }
            else{
                cin>>i>>j;
                if(vet[i]==1 && vet[j]==1) vet[i] = 1;
                else if(vet[i]==0 || vet[j]==0) vet[i] = 0;
                else vet[i] = '?';
            }
        }
        for(int i=31;i>=0;i--){
            if(vet[i]=='?') cout<<"?";
            else cout<<(char) (vet[i]+'0');
        }
        cout<<endl;
    }
}


void abrir(string str){
    freopen((str+".in").c_str(), "r", stdin);
    freopen((str+".out").c_str(), "w", stdout);
}

int main() {
    //usar no usaco
    //abrir("");

    IOS;
    
    //clock_t tStart = clock();
    solve();
    //cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl; 
    return 0;
}