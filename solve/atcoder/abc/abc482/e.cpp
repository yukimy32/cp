#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<vector<int>> g(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> C(N);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
		C[i]--;
	}
	auto dist = [&] (int u, int x) -> vector<int> {
		vector<int> D(N, 1e9); D[u] = 0;
		deque<int> dq; dq.push_back(u);
		while (!dq.empty()) {
			int v = dq.front(); dq.pop_front();
			for (int w: g[v]) {
				if (D[w] == 1e9 && w != x) {
					D[w] = D[v] + 1;
					dq.push_back(w);
				}
			}
		}
		return D;
	};
	vector<int> d0 = dist(0, -1);
	int S = max_element(d0.begin(), d0.end()) - d0.begin();
	vector<int> ds = dist(S, -1);
	int T = max_element(ds.begin(), ds.end()) - ds.begin();
	vector<int> diam;
	diam.push_back(T);
	while (diam.back() != S) {
		for (int u: g[diam.back()]) {
			if (ds[u] == ds[diam.back()] - 1) {
				diam.push_back(u);
				break;
			}
		}
	}
	int L = diam.size();
	if (L % 2 == 0) {
		int ml = diam[L / 2 - 1], mr = diam[L / 2];
		vector<int> dl = dist(ml, mr), dr = dist(mr, ml);
		vector<int> cl(N), cr(N);
		for (int i = 0; i < N; i++) {
			if (dl[i] == L / 2 - 1) cl[C[i]]++;
			if (dr[i] == L / 2 - 1) cr[C[i]]++;
		}
		ll ans = 0;
		for (int i = 0; i < N; i++) {
			ans += (ll)cl[i] * cr[i];
		}
		cout << ans << '\n';
	} else {
		int m = diam[L / 2];
		vector<int> dm = dist(m, -1);
		ll ans = 0;
		vector<int> cn(N);
		for (int i = 0; i < N; i++) {
			if (dm[i] == L / 2) {
				cn[C[i]]++;
			}
		}
		for (int i = 0; i < N; i++) {
			ans += (ll)cn[i] * cn[i];
		}
		vector<int> ld(N, -1);
		deque<int> dq;
		ld[m] = m;
		for (int i: g[m]) {
			ld[i] = i;
			dq.push_back(i);
		}
		while (!dq.empty()) {
			int u = dq.front(); dq.pop_front();
			for (int v: g[u]) {
				if (ld[v] == -1) {
					ld[v] = ld[u];
					dq.push_back(v);
				}
			}
		}
		map<ll, int> mp;
		for (int i = 0; i < N; i++) {
			if (dm[i] == L / 2) {
				mp[(ll)ld[i] * N + C[i]]++;
			}
		}
		for (auto [_, c]: mp) ans -= (ll)c * c;
		cout << ans / 2 << '\n';
	}
}