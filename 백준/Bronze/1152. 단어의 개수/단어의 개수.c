#include <stdio.h>
#include <string.h>
int main(){
    char s[1000001];int c=0;
    fgets(s,1000001,stdin);
    char *p=strtok(s," \n");
    while(p){c++;p=strtok(0," \n");}
    printf("%d",c);
}
