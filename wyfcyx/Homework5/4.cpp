#include <string>
#include <iostream>
#include <algorithm>
 
int main() {
	std::string s[100];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> s[i];
	std::sort(s, s + n);
	for (int i = 0; i < n; ++i)
		std::cout << s[i] << std::endl;
	return 0;
}
