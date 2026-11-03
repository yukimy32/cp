#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	string S; cin >> S;
	cout << (count(S.begin(), S.end(), 'o') % 2 == 0 ? "even" : "odd") << '\n';
}