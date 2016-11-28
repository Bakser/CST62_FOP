#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
 
std::vector<int> v;
std::vector<char> op;
 
int mul(int l, int r) {
	int ans = 1;
	for (int i = l; i <= r; ++i)
		ans *= v[i];
	return ans;
}
 
int main() {
	char s[100];
	scanf("%s", s);
	int n = strlen(s), i = 0, num;
	while (i < n) {
		if (isdigit(s[i])) {
			for (num = 0; i + 1 < n && isdigit(s[i + 1]); ++i)
				num = num * 10 + s[i] - '0';
			num = num * 10 + s[i] - '0';
			v.push_back(num);
		}
		else
			op.push_back(s[i]);
		++i;
	}
	/*
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	puts("");
	for (int i = 0; i < op.size(); ++i)
		printf("%c ", op[i]);
	puts("");
	*/
	int ans = 0, l = v.size() - 1;
	for (i = v.size() - 2; i >= 0; --i) {
		if (op[i] == '+')
			ans += mul(i + 1, l), l = i;
		else if (op[i] == '-')
			ans -= mul(i + 1, l), l = i;
	}
	printf("%d\n", ans + mul(0, l));
	return 0;
}
