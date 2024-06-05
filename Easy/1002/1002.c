#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillzero(int *temp, int size) {
    int i = 0;
    while(i < size) {
			temp[i] = 0;
			i++;
    }
}

char ** commonChars(char ** words, int wordsSize, int* returnSize) {
    int i = 0, j = 0, num = 0;

    int *temp = malloc(26 * sizeof(int));
    fillzero(temp, 26);

    i = 0;
    while (i < strlen(words[0])) {
			temp[words[0][i] - 'a']++;
			i++;
    }

    i = 1;
    while (i < wordsSize) {
			int *currentCount = malloc(26 * sizeof(int));
			fillzero(currentCount, 26);

			j = 0;
			while (j < strlen(words[i])) {
				currentCount[words[i][j] - 'a']++;
				j++;
			}

			j = 0;
			while (j < 26) {
				if (currentCount[j] < temp[j]) {
						temp[j] = currentCount[j];
				}
				j++;
			}
			free(currentCount);
			i++;
    }

    i = 0;
    while (i < 26) {
			num += temp[i];
			i++;
    }

    char **result = malloc(num * sizeof(char *));
    int index = 0;

    i = 0;
    while (i < 26) {
			while (temp[i] > 0) {
				result[index] = malloc(2 * sizeof(char));
				result[index][0] = 'a' + i;
				result[index][1] = '\0';
				index++;
				temp[i]--;
			}
			i++;
    }

    free(temp);

    *returnSize = num;
    return result;
}

int main() {
		char *words[] = {"bella", "label", "roller"};
		int wordsSize = 3;
		int returnSize = 0;
		char **result = commonChars(words, wordsSize, &returnSize);

		int i = 0;
		while (i < returnSize) {
			printf("%s\n", result[i]);
			i++;
		}

		return 0;
}