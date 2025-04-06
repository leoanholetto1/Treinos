#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long ll;

const int maxN= 1e6+5;
const ll mod = 1e9+7;
int arr[maxN];
int output[maxN];

void countSort(int n, int exp, int base) {
    int i;int count[base];
    memset(count, 0, sizeof(count));
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % base]++;
    for (i = 1; i < base; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
		count[(arr[i] / exp) % base]--;
    }

    for (i = 0; i < n; i++){
		arr[i] = output[i];
	}
}

void radixsort(int n, int base,int m) {
    for (ll exp = 1; m / exp > 0; exp *= base){
		countSort(n, exp, base);
	}  
}

void solve() {
    int n,t;
	int m;
    int a, b, c, x, y;
    int base = 1<<16;  
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%d %d %d", &a, &b, &c);
        scanf("%d %d", &x, &y);
        arr[0] = a;
		m = a;
        for (int i = 1; i < n; i++) {
            arr[i] = ((ll)arr[i-1] * b + a) % c;
			m = max(m,arr[i]);
        }
        radixsort(n, base,m);
        int hash = 0;
        for (int i = 0; i < n; i++) {
            hash = ((ll)hash * x + arr[i]) % y;
        }
        printf("%d\n", hash);
    }
}

int main() {
	IOS;
    solve();
    return 0;
}
