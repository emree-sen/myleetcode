#include <stdio.h>

void reverseString(char* s, int sSize) {
    int i = 0;
    char temp;
    while(i < sSize / 2)
    {
        temp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = temp;
        i++;
    }
}

int main()
{
		char s[] = "hello";
		reverseString(s, 5);
		printf("%s\n", s);
		return 0;
}