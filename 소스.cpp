#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//binary search
pair<int, int> Search_range(const vector<int>& arr, const int n) {
	int i = 0, j = arr.size() - 1;
	int half;
	while (1) {
		half = (i + j + 1) / 2;
		if (arr[half] == n) {
			if (!half) {
				//n�� �ߺ��̸� �̹� S�� n�� �־��ٴ� ���̹Ƿ� ������ ���� �� ����.
				if (arr[half + 1] == n) return make_pair(0, 0);
				return make_pair(1, n);
			}
			if (half == arr.size() - 1) {
				if (arr[half - 1] == n) return make_pair(0, 0);
				return make_pair(arr[half - 1] + 1, n);
			}
			if (arr[half - 1] == n || arr[half + 1] == n) return make_pair(0, 0);
			return make_pair(arr[half - 1] + 1, arr[half + 1] - 1);
		}
		if (arr[half] < n) i = half + 1;
		else j = half - 1;
	}
}
int Count(const pair<int, int>& range, const int n) {
	if (!range.second || range.first == range.second) return 0;
	//n ~ max ������ ���۹����� �׻� n�̸� ������ ������ max - n�� ���� = more
	//[10, 11], [10, 12]
	//min ~ n ������ i���� n �̻��� �� ~ max�� ���� = (more + 1) * less
	//[9, 10], [9, 11], [9, 12]
	int less = n - range.first, more = range.second - n;
	int ans = (more + 1) * less + more;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> arr;
	int L, N;
	cin >> L;
	while (L--) {
		cin >> N;
		arr.push_back(N);
	}
	cin >> N;
	arr.push_back(N); 
	sort(arr.begin(), arr.end());
	//N�� S�� �ְ� �����Ͽ� ������ �� ���Ҹ� ������ ��´�.
	pair<int, int> range = Search_range(arr, N);
	cout << Count(range, N) << "\n";
}
