#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int A[101][101];
    FILE * graph1, * graph2;
    graph1 = fopen("graph1.txt", "r");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(graph1, "%d", &A[i][j]);
        }
    }
    fclose(graph1);

    graph2 = fopen("graph2.txt", "w");
    fprintf(graph2, "graph {");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                fprintf(graph2, "%d", i + 1);
                fprintf(graph2, " -- ");
                fprintf(graph2, "%d\n", j + 1);
                
                if (A[i][j] > 1)
                {
                    fprintf(graph2, " [label = %d", A[i][j]);
                    fprintf(graph2, " ]\n ");
                }
            }
        }
    }
    fprintf(graph1, " } ");
    fclose(graph1);
    fclose(graph2);

    return 0;
}
