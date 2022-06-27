#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compute_prefix_function(char *, int );
int kmp(char *, int, char *, int );

int main()
{
    int len_p, len_t, cnt=0;
    char target[200], pattern[200];
    printf("Inserisci target\n");
    fflush(stdin);
    gets(target);
    printf("Inserisci pattern\n");
    fflush(stdin);
    gets(pattern);
    len_p=strlen(pattern);
    len_t=strlen(target);
	int i;
	i = kmp(target, strlen(target), pattern, strlen(pattern));
	if (i >= 0)
		cnt++;
    while(i>=0)
    {
        memmove(target, target+i+len_p, len_t-len_p-i);
        target[len_t-len_p-i]='\0';
        len_t=strlen(target);
        i = kmp(target, strlen(target), pattern, strlen(pattern));
        if (i >= 0)
            cnt++;
    }
    printf("numero occorrenze: %d", cnt);
	return 0;
}

int kmp(char *target, int tsize, char *pattern, int psize)
{
	int i;
	int *pi = compute_prefix_function(pattern, psize);
	int k = -1;
	if (!pi)
		return -1;
	for (i = 0; i < tsize; i++) {
		while (k > -1 && pattern[k+1] != target[i])
			k = pi[k];
		if (target[i] == pattern[k+1])
			k++;
		if (k == psize - 1) {
			free(pi);
			return i-k;
		}
	}
	free(pi);
	return -1;
}

int *compute_prefix_function(char *pattern, int psize)
{
	int k = -1;
	int i = 1;
	int *pi = malloc(sizeof(int)*psize);
	if (!pi)
		return NULL;
	pi[0] = k;
	for (i = 1; i < psize; i++)
	{
		while (k > -1 && pattern[k+1] != pattern[i])
			k = pi[k];
		if (pattern[i] == pattern[k+1])
			k++;
		pi[i] = k;
	}
	return pi;
}
