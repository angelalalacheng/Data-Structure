#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void print_graph(int** G, int vertex){
    for(int i=0; i<vertex;i++){
        printf("> ");
        for(int j=0;j<vertex;j++){
            printf("%d ", G[i][j]);
            if(j==(vertex-1)) printf("\n");
        }
    }
    printf("\n");
}

int deep=1;
void DFS(int** graph, int depth[] , int start, int vertex){
    for(int i=0;i<vertex;i++){
        if(depth[i]==0 && graph[start][i]==1){
            //don't change the original value
            if(depth[start]==0){
                depth[start]=deep;
                deep++;
            }
            DFS(graph, depth, i, vertex);
        }
    }
    if(depth[start]==0) depth[start] = deep;
    for(int i=0;i<vertex;i++){
        if(depth[i]==depth[start]-1){
            deep = depth[start];
            DFS(graph, depth, i, vertex);
        }
    }
    Traversal(graph, depth, vertex);
}

void Traversal(int** graph, int depth[], int vertex){
    // verify every node visited
    for(int i=0;i<vertex;i++){
        if(depth[i]==0){
            DFS(graph, depth, i, vertex);
        }
    }
    return;
}

void Verify(int** graph, int depth[], int vertex){
    // view odd and even as different two colors
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            if((j>i) && (graph[i][j]==1)){
                if(depth[i]%2==depth[j]%2) {
                    printf("> Not bicolorable\n");
                    return;
                }
            }
        }
    }
    printf("> Bicolorable\n");
}

int main(){
    int vertex, edge, nodeX, nodeY;
    scanf("%d %d", &vertex, &edge);

    while(vertex!=-1 && edge!=-1){
    //construct the graph
        int graph[vertex][vertex];
        int* pass[vertex];
        int depth[vertex];
        memset(graph, 0, sizeof(graph));
        memset(depth, 0,sizeof(depth));

        for(int i=0;i<edge;i++){
            scanf("%d %d", &nodeX, &nodeY);
            graph[nodeX][nodeY]=1;
            graph[nodeY][nodeX]=1;
        }
        for(int i=0;i<vertex;i++){
            pass[i]=graph[i];
        }

    //DFS
        Traversal(pass, depth, vertex);
        Verify(pass, depth, vertex);
        print_graph(pass, vertex);

    //next loop
        deep=1;
        scanf("%d %d", &vertex, &edge);
    }
}
