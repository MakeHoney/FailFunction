#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEN	100
int failure[MAX_LEN] = { 0, };

void fail(char* pat) {
	int i = 0;
	int j = 0;

	
	failure[0] = -1;


	while (pat[j + 1] != '\0') {
		j++;
		i = failure[j - 1];

		if (pat[i + 1] != pat[j] && i == -1)
			failure[j] = -1;
		else if (pat[i + 1] == pat[j])
			failure[j] = i + 1;
		else if (pat[i + 1] != pat[j] && i != -1) {
			while (!(pat[i + 1] == pat[j] || i == -1)) {
				i = failure[i];
			}
			if (i == -1) {
				if (pat[0] == pat[j])
					failure[j] = i + 1;
				else
					failure[j] = i;
			}
			else if (pat[i + 1] == pat[j])
				failure[j] = i + 1;
		}
	}
}

int main() {
	char pattern[MAX_LEN] = "abababac";

	fail(pattern);

	for(int i = 0 ; i< MAX_LEN ; i++)
		printf("%d ", failure[i]);
}