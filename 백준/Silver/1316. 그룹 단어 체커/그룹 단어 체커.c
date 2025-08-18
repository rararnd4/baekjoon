#include <stdio.h>
#include <string.h>
int main(){
    int n,a=0;scanf("%d",&n);
    while(n--){
        char s[101];scanf("%s",s);
        int v[26]={0},ok=1;
        for(int i=0;s[i];i++){
            if(s[i]!=s[i-1]&&v[s[i]-97])ok=0;
            v[s[i]-97]=1;
        }
        a+=ok;
    }
    printf("%d",a);
}
