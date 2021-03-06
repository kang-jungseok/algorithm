#include <iostream>
using namespace std;

int n, l, res = 0;
int map[200][100];

int main()
{
    cin >> n >> l;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; x++)
        {
            map[n + y][x] = map[x][y];
        }
    }

    int cnt = 0;
    int i, j;

    for (i = 0; i < 2 * n; i++)
    {
        cnt = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (map[i][j] == map[i][j + 1])
            {
                cnt++;
            }
            else if (map[i][j] + 1 == map[i][j + 1] && cnt >= l)
            {
                cnt++;
            }
            else if (map[i][j] - 1 == map[i][j + 1] && cnt >= 0)
            {
                cnt = (1 - l);
            }
            else
                break;
            if (j == (n - 1) && cnt >= 0)
            {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}