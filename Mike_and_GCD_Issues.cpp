#include <bits/stdc++.h>
using namespace std;

#define N 100002
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define deb(x) cout << #x << '=' << x << endl;
#define deb2(x, y) cout << #x << '=' << x << ', ' << #y << '=' << y << endl;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const double PI = 3.1415926535897932384626;
const ll oo = 1e18;

ll n;
vi fact(2 * N, -1);

void calculateNearest(vi &a, vi &v, vi &d){
    fo(i, 0, n){
        ll tmp = a[i];
        while (fact[tmp] != -1){
            ll val = fact[tmp];
            if (v[val] != -1){
                d[i]= (d[i]==-1 ? v[val] : max(d[i],v[val]));
            }
            v[val] = i;
            while (tmp % val == 0)
                tmp /= val;
        }
        if (tmp > 1){
            if (v[tmp] != -1){
                d[i] = (d[i]==-1 ? v[tmp] : max(d[i],v[tmp]));
            }
            v[tmp] = i;
        }
    }
}

void solution(){
    cin >> n;
    vi v1(2 * N, -1), v2(2 * N, -1), d1(n, -1), d2(n, -1), a(n);
    fo(i, 0, n) cin >> a[i];
    calculateNearest(a, v1, d1);
    reverse(all(a));
    calculateNearest(a, v2, d2);
    reverse(all(d2));
    fo(i, 0, n) if (d2[i] != -1) d2[i] = n - 1 - d2[i];
    fo(i, 0, n){
        if (d1[i] == -1 && d2[i] == -1)
            cout << "-1 ";
        else if (d1[i] == -1 || d2[i] == -1)
            cout << (d1[i] == -1 ? d2[i] : d1[i]) + 1 << " ";
        else{
            cout<<(abs(i-d1[i])>abs(i-d2[i]) ? d2[i]+1 : d1[i]+1)<<" ";
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long t = 1;
    for (ll i = 2; i * i < 2 * N; ++i){
        if (fact[i] == -1){
            for (ll j = i * i; j < 2 * N; j += i)
                fact[j] = i;
        }
    }
    while (t--)
        solution();
    return 0;
}