#include <stdio.h>
#define INF 1000000000

int min(int a,int b){return a<b?a:b;}

int main(){
    int V,E;
    scanf("%d%d",&V,&E);
    int dist[401][401];
    for(int i=1;i<=V;i++) for(int j=1;j<=V;j++) dist[i][j]=INF;
    for(int i=0;i<E;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dist[a][b]=c;
    }
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                if(dist[i][k]<INF && dist[k][j]<INF)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    int ans=INF;
    for(int i=1;i<=V;i++) ans=min(ans,dist[i][i]);
    printf("%d\n",ans==INF?-1:ans);
}
