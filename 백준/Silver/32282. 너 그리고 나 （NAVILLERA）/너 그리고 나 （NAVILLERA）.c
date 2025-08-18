#include <stdio.h>
#include <math.h>

int main() {
    int X,Y,c;
    scanf("%d %d %d",&X,&Y,&c);
    long long dist2 = 1LL*X*X + 1LL*Y*Y;
    if(dist2==0){
        printf("0\n");
        return 0;
    }
    double dist = sqrt((double)dist2);
    int ans = (int)ceil(dist/c);
    if(ans==1 && dist<c) ans=2;
    printf("%d\n",ans);
}
