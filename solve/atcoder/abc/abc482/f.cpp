#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll N; int M; cin >> N >> M;
	if (N == 1) {
		if (M == 1) {
			cout << 1 << '\n';
		} else {
			for (int i = 0; i < M; i++) {
				cout << (i == 1 ? 1 : -1) << '\n';
			}
		}
		return 0;
	}
	vector<pair<ll, int>> pf;
	for (ll p = 2; p * p <= N; p++) {
		if (N % p == 0) {
			int e = 0;
			while (N % p == 0) {
				N /= p; e++;
			}
			pf.push_back({p, e});
		}
	}
	if (N > 0) {
		pf.push_back({N, 1});
	}
	int L = pf.size();
	vector<vector<int>> g(L * M);
	for (int i = 0; i < L; i++) {
		ll w = 1;
		for (int x = 0; x <= pf[i].second; x++) {
			for (int j = 0; j < M; j++) {
				g[i * M + j].push_back((i + 1) % L * M + j * w % M);
			}
			w = w * pf[i].first % M;
		}
	}
	vector<int> dist(L * M, inf);
	deque<int> dq;
	if (M == 1) {
		dist[0] = 0;
		dq.push_back(0);
	} else {
		dist[1] = 0;
		dq.push_back(1);
	}
	while (!dq.empty()) {
		int u = dq.front(); dq.pop_front();
		for (int v: g[u]) {
			if (u < M) {
				if (dist[u] + 1 < dist[v]) {
					dist[v] = dist[u] + 1;
					dq.push_back(v);
				}
			} else {
				if (dist[u] < dist[v]) {
					dist[v] = dist[u];
					dq.push_front(v);
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		int ans = inf;
		for (int j = 0; j < L; j++) {
			ans = min(ans, dist[j * M + i]);
		}
		ans = max(ans, 1);
		cout << (ans == inf ? -1 : ans) << '\n';
	}
}