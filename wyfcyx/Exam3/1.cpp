#include <cstdio>
#include <cstring>
#include <algorithm>
  
char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
char upper(char c) {
    return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}
  
int main() {
    char s[201], ss[201];
    int o, n, m, i, j1, j2, j;
    scanf("%d%s", &o, s);
    n = strlen(s);
    if (o == 1)
        for (i = 0; i < n; ++i)
            s[i] = upper(s[i]);
    if (o == 2)
        for (i = 0; i < n; ++i)
            s[i] = lower(s[i]);
    if (o == 3)
        for (i = 0; i < n - 1 - i; ++i)
            std::swap(s[i], s[n - 1 - i]);
    if (o == 4)
        for (i = 0; i < n; ++i)
            s[i] = (s[i] >= 'a' && s[i] <= 'z') ? upper(s[i]) : lower(s[i]);
    if (o == 5) {
        for (i = 0; i < n; ++i)
            s[i] = lower(s[i]);
        memcpy(ss, s, sizeof s);
        i = m = 0;
        while (i < n) {
            for (j1 = i; j1 != n - 1 && ss[j1] + 1 == ss[j1 + 1]; ++j1);
            for (j2 = i; j2 != n - 1 && ss[j2] - 1 == ss[j2 + 1]; ++j2);
            j = std::max(j1, j2);
            if (j == i)
                s[m++] = ss[i];
            else if (j == i + 1)
                s[m++] = ss[i], s[m++] = ss[i + 1];
            else
                s[m++] = ss[i], s[m++] = '-', s[m++] = ss[j];
            i = j + 1;
        }
        s[m] = '\0';
    }
    printf("%s", s);
    return 0;
}
