#include <stdio.h>

int longestPalindrome(char* s) {
    int count = 0;
    int i = 0;
    int freq[128] = {0};

    while(s[i])
    {
        count += (++freq[s[i]] % 2) == 1 ? 1 : -1;
        i++;
    }
    return count > 0 ? i + 1 - count : i;
}

int main()
{
		char s[] = "abccccdd";
		printf("%d\n", longestPalindrome(s));
		return 0;
}