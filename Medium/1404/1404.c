#include <stdio.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int numSteps(char* s) {
    int k = 0;
    int l = 0;
    int n = ft_strlen(s);
    int i = n - 1;

    while (i > 0)
    {
        if (s[i] - '0' + l == 1)
        {
            l = 1;
            k += 2;
        }
        else
            k += 1;
        i--;
    }
    return k + l;
}

int main()
{
		char s[] = "11010101010101011";
		printf("%d\n", numSteps(s));
		return 0;
}