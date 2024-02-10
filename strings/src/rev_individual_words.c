// program to reverse individual words in a string

#include "cmn_defs.h"
#include "cmn_hdr.h"

void reverse_words(char *s, int start, int end)
{
	int i, j;
	char temp;

	for (i = start, j = end; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

char *rev_individual_words(char *s)
{
	int i;
	int start, end; // start & end index of a word

	if (s == NULL) {
		return NULL;
	}

	if (s[0] == '\0') {
		printf("empty string - return");
		return s;
	}

	if (strlen(s) == 1U) {
		printf("1 byte string - return");
		return s;
	}

	start = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			end = i - 1;
			reverse_words(s, start, end);
			start = i + 1;
		}
	}
	//reached end of string - reverse last word
	reverse_words(s, start, end);

	return s;
}

int main()
{
	char str[BUFSZ_512] = {0};

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);

	printf("Entered string is:\"%s\"\n", str);

	/* Knock off the trailing newling character */
	str[strcspn(str, "\n")] = '\0';
	printf("Entered string after knocking off newline:\"%s\"\n", str);

	rev_individual_words(str);

	printf("Output: \"%s\"\n", str);

	return 0;
}
