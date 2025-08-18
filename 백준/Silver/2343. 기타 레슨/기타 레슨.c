#include <stdio.h>
int main(){
    int n,m,a[100000],i,l=0,r=0;scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){scanf("%d",&a[i]);if(a[i]>l)l=a[i];r+=a[i];}
    int ans=r;
    while(l<=r){
        int mid=(l+r)/2,s=0,c=1;
        for(i=0;i<n;i++){if(s+a[i]>mid)c++,s=0;s+=a[i];}
        if(c<=m)ans=mid,r=mid-1;else l=mid+1;
    }
    printf("%d",ans);
}
