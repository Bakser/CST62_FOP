#include <cstdio>
#include <algorithm>
 
struct student {
	int sum, math, eng, id;
	student() {}
	student(int _id, int _math, int _eng, int _chn) {
		sum = _math + _eng + _chn;
		math = _math;
		eng = _eng;
		id = _id;
	}
	bool operator < (const student &B) const {
		if (sum != B.sum)
			return sum > B.sum;
		else if (math != B.math)
			return math > B.math;
		else if (eng != B.eng)
			return eng > B.eng;
		else
			return id < B.id;
	}
}S[100];
 
 
int main() {
	int n, a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		S[i] = student(i + 1, a, b, c);
	}
	std::sort(S, S + n);
	for (int i = 0; i < n; ++i)
		printf("%d %d %d %d\n", S[i].math, S[i].eng, S[i].sum - S[i].math - S[i].eng, S[i].id);
	return 0;
}
