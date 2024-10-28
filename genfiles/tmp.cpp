#include <bits/stdc++.h>

using namespace std;

// Macros
#define MAXN 10000001
#define ll long long
#define Yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define YESr { cout << "YES" << endl; return; }
#define No cout << "No" << endl
#define NO cout << "NO" << endl
#define NOr { cout << "NO" << endl; return; }
#define _n cout << "\n"

#define F first
#define S second
#define vi vector<ll>
#define vpi vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define show(v) for (auto it : v) cout << it << " "
#define pb push_back
#define fori(n) for (ll i = 0; i < n; i++)
#define f(i, n) for (ll i = 0; i < n; i++)
#define in(v) for (auto &it : v) cin >> it
#define read(a, n) for (ll i = 0; i < n; i++) cin >> a[i]

#define flush ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    string s;
    while(cin >> s) {
        cout << "{";
        fori(3) cout << s[i] << ",";
        cout << s[3] << "},\n";
    }
}