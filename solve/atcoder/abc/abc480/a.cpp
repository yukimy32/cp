#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	string S, T; cin >> S >> T;
	if (abs(S[0] - T[1]) == 3 || abs(S[1] - T[0]) == 3) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}