#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<string> S(N);
	for (int i = 0; i < N; i++) cin >> S[i];
	vector<int> cnt(N);
	for (int i = 0; i < M; i++) {
		string T; cin >> T;
		int D0 = -1;
		vector<int> D1;
		for (int j = 0; j < N; j++) {
			if (S[j].size() != T.size()) continue;
			int diff = 0;
			for (int k = 0; k < T.size(); k++) diff += (S[j][k] != T[k]);
			if (diff == 0) D0 = j;
			if (diff == 1) D1.push_back(j);
		}
		if (D0 != -1) cnt[D0]++;
		else if (D1.size() == 1) cnt[D1[0]]++;
	}
	for (int i: cnt) cout << i << '\n';
}