#include <iostream>
#include <vector>
#define ll long long
#define V vector<vector<ll>>
#define divider 1000000007
using namespace std;
//행렬을 출력한다.
void Print(const V& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
V Multiply(V& a, V& b) {
	V ans;
	ll sum;
	for (int i = 0; i < a.size(); i++) {
		vector<ll> tmp;
		for (int j = 0; j < b[0].size(); j++) {
			sum = 0;
			for (int k = 0; k < b.size(); k++) {
				sum += (a[i][k] * b[k][j]) % divider;
			}
			tmp.push_back(sum % divider);
		}
		ans.push_back(tmp);
	}
	return ans;
}
V Exp(ll e) {
	V matrix, total;
	//(1, 1)
	//(1, 0)
	for (int i = 0; i < 2; i++) {
		vector<ll> tmp;
		for (int j = 0; j < 2; j++) {
			if (i == 1 && j == 1) tmp.push_back(0);
			else tmp.push_back(1);
		}
		matrix.push_back(tmp);
	}
	//단위행렬
	for (int i = 0; i < matrix.size(); i++) {
		vector<ll> tmp;
		for (int j = 0; j < matrix.size(); j++) {
			if (i == j) tmp.push_back(1);
			else tmp.push_back(0);
		}
		total.push_back(tmp);
	}
	while (e > 0) {
		if (e % 2) total = Multiply(total, matrix);
		matrix = Multiply(matrix, matrix);
		e /= 2;
	}
	return total;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//(Fn) =  (1 1)^(n-2)(F2)
	//(Fn-1)  (1 0)      (F1)
	ll n;
	cin >> n;
	//F1 = F2 = 1
	if (n == 1 || n == 2) {
		cout << 1 << "\n";
		return 0;
	}
	V ans = Exp(n - 2);
	//(F2) = (1)
	//(F1)   (1)
	V first;
	vector<ll> tmp;
	tmp.push_back(1);
	first.push_back(tmp);
	first.push_back(tmp);

	ans = Multiply(ans, first);
	cout << ans[0][0] << "\n";
}