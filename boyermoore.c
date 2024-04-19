#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char *str, int size, int badChar[MAX_CHAR]) {
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < MAX_CHAR; i++)
        badChar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badChar[str[i]] = i;
}

void search(char *txt, char *pat) {
    int m = strlen(pat);
    int n = strlen(txt);

    int badChar[MAX_CHAR];

    badCharHeuristic(pat, m, badChar);

    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        /* Keep reducing index j of pattern while characters of pattern and text are matching at this shift s */
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        /* If the pattern is present at the current shift, then index j will become -1 after the above loop */
        if (j < 0) {
            printf("Pattern occurs at = %d\n", s);

            // Increment shift by 1 to find the next occurrence
            s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
        } else {
            /* Shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern.
            The max function is used to make sure that we get a positive shift. We may get a negative shift if the
            last occurrence of bad character in pattern is on the right side of the current character. */
            s += max(1, j - badChar[txt[s + j]]);
        }
    }
}

int main() {
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    search(txt, pat);
    return 0;
}
