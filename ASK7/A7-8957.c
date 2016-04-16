//Kostas Mpouzios. Copyrights? LoL
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int chartoint(char ch) {
    return ch-97;
}
void least(int frq[]) {
    int i,l,thesi;
    l = frq[0];
    thesi = 0;
    for(i=0;i<=25;i++) {
        if(frq[i] < l) {
            l = frq[i];
            thesi = i;
        }
    }
    printf("Least frequent is %c, %d times.\n",thesi+97,frq[thesi]);
}
void most(int frq[]) {
    int i,m,thesi;
    m = frq[0];
    thesi = 0;
    for(i=0;i<=25;i++) {
        if(frq[i] > m) {
            m = frq[i];
            thesi = i;
        }
    }
    printf("Most frequent is %c, %d times.\n",thesi+97,frq[thesi]);
}
void stars(int k) {
    int i;
    for(i=1;i<=k;i++) {
        printf("%c",'*');
    }
    putchar('\n');
}
void print(int frq[]) {
    int i;
    for(i=0;i<=25;i++) {
        printf("%c",i+97);
        stars(frq[i]);
    }
}
int main() {
    int c;
    char ch;
    int freq[26]={0};
    do {
        ch = getchar();
        ch = tolower(ch);
        c = chartoint(ch);
        if(c > 25 || c < 0)
            continue;
        freq[c]++;
        //printf("%d\n",c);
    } while(ch != '!');

    print(freq);
    most(freq);
    least(freq);
    return 0;
}
