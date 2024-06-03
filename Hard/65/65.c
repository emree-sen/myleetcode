#include <stdio.h>

int isNumber(char* s) {
    int artisayisi = 0;
    int esayisi = 0;
    int noktasayisi = 0;
    int sayisayisi = 0;
    int genel = 0;
    int esonrasisayi = 0;
    int i = 0;
    int tutucu = 0;
    while(s[i])
    {
        if(s[i] == '+' || s[i] == '-')
            artisayisi++;
        if(s[i] == 'e' || s[i] == 'E')
        {
            esayisi++;
            tutucu = i;
        }
        if(s[i] >= 47 && s[i] <= 57)
            sayisayisi++;
        if(s[i] == '.')
            noktasayisi++;
        if(esayisi != 0 && s[i] >= 47 && s[i] <= 57)
        esonrasisayi++;
        if(!((s[i] >= 47 && s[i] <= 57) || s[i] == '+' || s[i] == '-'
        || s[i] == 'e' || s[i] == 'E' || s[i] == '.'))
            genel++;
        if((s[i] == 'e' || s[i] == 'E') && (sayisayisi == 0))
            genel++;
        if((s[i] == '+' || s[i] == '-') && i != tutucu + 1 && esayisi != 0)
            genel++;
        if((s[i] == '+' || s[i] == '-') && esayisi == 0 && i != 0)
            genel++;
        if(esayisi != 0 && s[i] == '.')
            genel++;
        i++;
    }
    if(esayisi != 0 && esonrasisayi == 0)
        genel++;

    if(genel == 0 && sayisayisi != 0 && noktasayisi < 2 && esayisi < 2)
        return 1;
    else
        return 0;
}

int main()
{
		char s[] = "0";
		printf("%d", isNumber(s));
		return 0;
}