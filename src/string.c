//
// Created by jianyuelin on 12/25/2020.
//

#include <stdio.h>
#include <assert.h>
#include <strop/string.h>
#define MAXLINES 5000
#define MAXLEN 1000
int getline(char *,int );
char *alloc(int);


void get_arg(const char *source, char *arg) {
    assert(source != NULL);

    while (*source != '=')source++;

    while (*source != NULL && source++) {
        *arg = *source;
        arg++;
    }
}

int str_len(const char *str) {
    assert(str != NULL);
    int count = 0;
    while (*str != NULL && str++)
        count++;
    return count;
}

int NewStr_index(char s[], char t[]) {
    assert(s != NULL);
    assert(t != NULL);
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;

}

int getline_(char s[], int lim) {
    assert(s != NULL);
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void strcpy(char *s,char *t){
    while (*s++ = *t++);
}

int readlines (char *lineptr[],int maxlines){
    int len,nlines;
    char *p,line[MAXLEN];

    nlines = 0;
    while ((len = getline(line,MAXLEN))>0)
        if (nlines >= maxlines || p = alloc(len) == NULL)
            return  -1;
        else{
            line[len -1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    return  nlines;
}

void writelines(char *lineptr[],int nlines){
    int  i;
    for (i = 0; i < nlines ; i++) {
        printf("%s\n",lineptr[i]);
    }
}







