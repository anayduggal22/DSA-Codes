// Rotten Oranges

#include <stdio.h>

struct coordinates
{
    int x;
    int y;
};

int visited[130][130];

struct coordinates queue[130];
int front = -1;
int rear = -1;

int bfs(int **graph, int rows, int cols, int *fresh_oranges)
{

    int nrows[] = {-1, 0, 1, 0};
    int ncols[] = {0, 1, 0, -1};
    int time = 0;

    while (front < rear && *fresh_oranges > 0)
    {
        // This is number of oranges rotting others in the current minute
        // Each level = 1 minute.
        int size = rear - front;
        
        for (int j = 0; j < size; j++)
        {

            front++;
            int r = queue[front].x;
            int c = queue[front].y;

            // Rotting done for one rotten orange
            for (int i = 0; i < 4; i++)
            {
                int nr = r + nrows[i];
                int nc = c + ncols[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && visited[nr][nc] == 1)
                {
                    (*fresh_oranges)--;

                    visited[nr][nc] = 2;
                    rear++;
                    queue[rear].x = nr;
                    queue[rear].y = nc;
                }
            }
        }

        time++;
    }

    return time;
}

int rotten_oranges(int **graph, int rows, int cols)
{
    int fresh_oranges = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            visited[i][j] = 0;
            if (graph[i][j] == 1)
            {
                visited[i][j] = 1;
                fresh_oranges++;
            }
            else if (graph[i][j] == 2)
            {
                rear++;
                queue[rear].x = i;
                queue[rear].y = j;
            }
        }
    }
    int time = bfs(graph, rows, cols, &fresh_oranges);

    if (fresh_oranges > 0)
    {
        return -1;
    }

    return time;
}

int main()
{

    return 0;
}