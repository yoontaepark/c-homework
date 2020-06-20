#include <stdio.h> 
#include <limits.h> // 자료형의 최대값과 최소값이 정의된 헤더 파일
#include <stdbool.h>  //bool 자료형 사용을 위함

#define V 8 //꼭지점 개수 정의
int minDistance(int dist[], bool sptSet[]); // 최소거리를 찾기 위한 함수(사용하지 않은 경로들을 탐색) 
int printSolution(int dist[], int n); // 구성된 거리를 출력하는 함수
void dijkstra(int graph[V][V], int src); // 데이크스트라 알고리즘을 수행하는 함수

int main()
{
    int graph[V][V] = {                //구하고자 하는 꼭지점들간의 거리를 구성
        { 0, 4, 3, 0, 0, 0, 0, 0 },
        { 4, 0, 2, 5, 0, 0, 0, 0 },
        { 3, 2, 0, 3, 6, 0, 0, 0 },
        { 0, 5, 3, 0, 1, 5, 0, 0 },
        { 0, 0, 6, 1, 0, 0, 5, 0 },
        { 0, 0, 0, 5, 0, 0, 2, 7 },
        { 0, 0, 0, 0, 5, 2, 0, 4 },
        { 0, 0, 0, 0, 0, 7, 4, 0 } 
    };

    dijkstra(graph, 0);  //데이크스트라 알고리즘을 수행하는 함수(함수안에 출력문도 포함되어 있음) 

    return 0;
}


int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;     // 최소거리를 최대치로 초기화 시킨다

    for (int v = 0; v < V; v++)                     // 0부터 7까지(a~z까지) 반복문 수행
        if (sptSet[v] == false && dist[v] <= min)   // 꼭지점이 선택되지 않았었고, 거리값이 min보다 작다면, min값을 해당 거리값으로 업데이트 한다. 
            min = dist[v], min_index = v;

    return min_index;
}


int printSolution(int dist[], int n)
{
    printf("꼭지점 a~z를 각각 0~7이라고 할때,\n");
    for (int i = 0; i < V; i++)
    {
        printf("0에서 %d 까지의 거리 %d\n", i, dist[i]);
    }
}



void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // 결과값으로, 최소의 거리값이 최종적으로 업데이트 됨

    bool sptSet[V]; // 최소거리를 확인한 꼭지점이라면 true, 확인해야하는 꼭지점이라면 false

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;  //모든 거리를 무한대로 초기화하고, stpSet도 false(확인필요한 꼭지점)으로 초기화

    dist[src] = 0; // 시작점에서 시작점까지의 거리는 0으로 지정

    for (int count = 0; count < V - 1; count++) {  

        int u = minDistance(dist, sptSet); //선택하지 않은 꼭지점들에 대해 최소거리를 확인하여 u에 대입
 
        sptSet[u] = true;  //선택된 꼭지점에 대해서는 true로 값을 변경함

        for (int v = 0; v < V; v++)  //선택된 꼭지점에 대해 거리값을 업데이트 한다 
                                                 

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];  //선택된 꼭지점이 아니고, 거리값이 최대가 아니라면, 거리값을 업데이트 한다. 
    }

    printSolution(dist, V); //이후 결과값을 출력한다. 
}
