#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, res;
int map[8][8];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, +1};

void bfs()
{
    queue<int> q;
    int backup[8][8];
    int visited[8][8] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            backup[i][j] = map[i][j];
            if (backup[i][j] == 2)
            {
                q.push(i * 10 + j);
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int cy = cur / 10;
        int cx = cur % 10;

        backup[cy][cx] = 2;

        for (int dir = 0; dir < 4; ++dir)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny > n || nx < 0 || nx > m)
                continue;

            if (visited[ny][nx] == 0 && backup[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                q.push(ny * 10 + nx);
            }
        }
    }
    int candi = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (backup[y][x] == 0)
            {
                candi++;
            }
        }
    }
    if (res < candi)
    {
        res = candi;
    }
}
void pick_dfs(int count, int sy, int sx)
{
    if (count == 3)
    {
        bfs();
        return;
    }

    for (int i = sy; i < n; i++)
    {
        for (int j = sx; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                pick_dfs(count + 1, i, j);
                map[i][j] = 0;
            }
        }
        sx = 0;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    pick_dfs(0, 0, 0);

    cout << res;

    return 0;
}
