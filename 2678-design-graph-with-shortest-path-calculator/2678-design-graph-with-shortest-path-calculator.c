
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int** adjmatrix;
    int v;
} Graph;


Graph* graphCreate(int n, int** edges, int edgesSize, int* edgesColSize) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjmatrix = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i<n; ++i){
        graph->adjmatrix[i] = (int*)calloc(n,sizeof(int));
    }

    for(int i = 0; i<edgesSize; ++i){
        int* edge = edges[i];
        graph->adjmatrix[edge[0]][edge[1]] = edge[2];
    }
    graph->v = n;
    return graph;
}

void graphAddEdge(Graph* obj, int* edge, int edgeSize) {
    obj->adjmatrix[edge[0]][edge[1]] = edge[2];
}

int graphShortestPath(Graph* obj, int node1, int node2) {
    int* dist = (int*)malloc(obj->v * sizeof(int));
    for(int i= 0; i<obj->v; ++i){
        dist[i] = 1000000000;
    }

    dist[node1] = 0;
    bool* vis = (bool*)calloc(obj->v, sizeof(bool));

    for(int i = 0; i<obj->v; ++i){
        //printf("i = %d\n", i);
        int u = -1;
        for(int k = 0; k<obj->v; ++k){
            if(!vis[k]&& (u==-1 || dist[k]<dist[u]))
                u = k;
        }
        vis[u] = true;
        for(int j = 0; j<obj->v; ++j){
            if(obj->adjmatrix[u][j]!=0 && !vis[j] && 
                (dist[j]>dist[u] + obj->adjmatrix[u][j])){
                    dist[j] =  dist[u]+obj->adjmatrix[u][j];
            }
        }
    }
   
    int result  = dist[node2];
    free(dist);
    free(vis);
    return result == 1000000000 ? -1 : result; 
   
}

void graphFree(Graph* obj) {
    for(int i = 0; i<obj->v; ++i)
        free(obj->adjmatrix[i]);
    free(obj->adjmatrix);
    free(obj);
}

/**
 * Your Graph struct will be instantiated and called as such:
 * Graph* obj = graphCreate(n, edges, edgesSize, edgesColSize);
 * graphAddEdge(obj, edge, edgeSize);
 
 * int param_2 = graphShortestPath(obj, node1, node2);
 
 * graphFree(obj);
*/