#include <iostream>
#include <queue>
using namespace std;

struct ROBOT
{
    int y, x, dir;
};

int n, m;
int map[50][50];
ROBOT robot;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main()
{
    cin >> n >> m;
    cin >> robot.y >> robot.x >> robot.dir;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
        }
    }

    queue<ROBOT> q;
    q.push(robot);

    int res = 0;

    while (!q.empty())
    {
        ROBOT cur = q.front();
        q.pop();

        if (map[cur.y][cur.x] == 0)
        {
            map[cur.y][cur.x] = 2;
            res++;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            ROBOT next;
            next.dir = (cur.dir + 3 + (dir * 3)) % 4;
            next.y = cur.y + dy[next.dir];
            next.x = cur.x + dy[next.dir];

            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] != 0)
            {
                continue;
            }

            q.push(next);
            break;
        }

        if (q.empty())
        {
            ROBOT next;
            next.dir = cur.dir + 3;
            next.y = cur.y + dy[(next.dir + 2) % 4];
            next.x = cur.x + dy[(next.dir + 2) % 4];

            if (map[next.y][next.x] == 1)
            {
                break;
            }
        }
    }

    cout << res;

    return 0;
}