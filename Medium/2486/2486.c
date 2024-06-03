#include <stdio.h>

int ft_strlen(char *a)
{
    int i = 0;
    while(a[i])
        i++;
    return i;
}

int appendCharacters(char* s, char* t) {
    int i = 0;
    int j = 0;
    while(s[i])
    {
        if(s[i] == t[j])
            j++;
        i++;
    }
    return (ft_strlen(t) - j);
}

int main()
{
		char s[10] = "selam";
		char t[6] = "selim";
		printf("%d", appendCharacters(s, t));
		return 0;
}