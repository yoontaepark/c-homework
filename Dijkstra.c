#include <stdio.h> 
#include <limits.h> // �ڷ����� �ִ밪�� �ּҰ��� ���ǵ� ��� ����
#include <stdbool.h>  //bool �ڷ��� ����� ����

#define V 8 //������ ���� ����
int minDistance(int dist[], bool sptSet[]); // �ּҰŸ��� ã�� ���� �Լ�(������� ���� ��ε��� Ž��) 
int printSolution(int dist[], int n); // ������ �Ÿ��� ����ϴ� �Լ�
void dijkstra(int graph[V][V], int src); // ����ũ��Ʈ�� �˰����� �����ϴ� �Լ�

int main()
{
    int graph[V][V] = {                //���ϰ��� �ϴ� �������鰣�� �Ÿ��� ����
        { 0, 4, 3, 0, 0, 0, 0, 0 },
        { 4, 0, 2, 5, 0, 0, 0, 0 },
        { 3, 2, 0, 3, 6, 0, 0, 0 },
        { 0, 5, 3, 0, 1, 5, 0, 0 },
        { 0, 0, 6, 1, 0, 0, 5, 0 },
        { 0, 0, 0, 5, 0, 0, 2, 7 },
        { 0, 0, 0, 0, 5, 2, 0, 4 },
        { 0, 0, 0, 0, 0, 7, 4, 0 } 
    };

    dijkstra(graph, 0);  //����ũ��Ʈ�� �˰����� �����ϴ� �Լ�(�Լ��ȿ� ��¹��� ���ԵǾ� ����) 

    return 0;
}


int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;     // �ּҰŸ��� �ִ�ġ�� �ʱ�ȭ ��Ų��

    for (int v = 0; v < V; v++)                     // 0���� 7����(a~z����) �ݺ��� ����
        if (sptSet[v] == false && dist[v] <= min)   // �������� ���õ��� �ʾҾ���, �Ÿ����� min���� �۴ٸ�, min���� �ش� �Ÿ������� ������Ʈ �Ѵ�. 
            min = dist[v], min_index = v;

    return min_index;
}


int printSolution(int dist[], int n)
{
    printf("������ a~z�� ���� 0~7�̶�� �Ҷ�,\n");
    for (int i = 0; i < V; i++)
    {
        printf("0���� %d ������ �Ÿ� %d\n", i, dist[i]);
    }
}



void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // ���������, �ּ��� �Ÿ����� ���������� ������Ʈ ��

    bool sptSet[V]; // �ּҰŸ��� Ȯ���� �������̶�� true, Ȯ���ؾ��ϴ� �������̶�� false

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;  //��� �Ÿ��� ���Ѵ�� �ʱ�ȭ�ϰ�, stpSet�� false(Ȯ���ʿ��� ������)���� �ʱ�ȭ

    dist[src] = 0; // ���������� ������������ �Ÿ��� 0���� ����

    for (int count = 0; count < V - 1; count++) {  

        int u = minDistance(dist, sptSet); //�������� ���� �������鿡 ���� �ּҰŸ��� Ȯ���Ͽ� u�� ����
 
        sptSet[u] = true;  //���õ� �������� ���ؼ��� true�� ���� ������

        for (int v = 0; v < V; v++)  //���õ� �������� ���� �Ÿ����� ������Ʈ �Ѵ� 
                                                 

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];  //���õ� �������� �ƴϰ�, �Ÿ����� �ִ밡 �ƴ϶��, �Ÿ����� ������Ʈ �Ѵ�. 
    }

    printSolution(dist, V); //���� ������� ����Ѵ�. 
}
