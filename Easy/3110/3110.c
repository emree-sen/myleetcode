#include <stdio.h>
#include <math.h>
#include <string.h>

int scoreOfString(char* s) {
    int i = 0;
    int j = strlen(s);
    int out = 0;
    while(i < j - 1)
    {
        out += abs(s[i] - s[i + 1]);
        i++;
    }
    return out;
}

int main() {
		char s[10] = "acdde";
		printf("%d\n", scoreOfString(s));
		return 0;
}