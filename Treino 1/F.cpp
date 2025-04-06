#include<bits/stdc++.h>            

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vet(Type) vector<Type>
#define all(x) x.begin(),x.end()
#define s second
#define f first
#define lc ((n)<<1)
#define rc ((n)<<1|1)
#define pb push_back
#define sz size()
#define isPowerOfTwo(S) (!(S & (S-1)))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod = 1000000007;
const int INF = 1e9;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int dxx[] = {-1,-1,0,1,1,1,0,-1};
int dyy[] = {0,1,1,1,0,-1,-1,-1};

struct Pessoa {
	string nome;
	int dia, mes, ano;
};

void solve(){
	int n, m, q, t, aux, dia, mes, ano;
	string s;
	vector<Pessoa> v;

	cin >> t ;
	for(int i=0;i<t;i++){
		cin >> s >> dia >> mes >> ano;

		v.push_back({s,dia,mes,ano});
	}

	sort(v.begin(), v.end(), [] (const Pessoa& a, const Pessoa& b){
		if (a.ano != b.ano) return a.ano < b.ano;
        if (a.mes != b.mes) return a.mes < b.mes;
        return a.dia < b.dia;
	});

	cout << v[t-1].nome << endl;
	cout << v[0].nome << endl;
}

int main() {
	IOS;
	solve();
	return 0;
}
