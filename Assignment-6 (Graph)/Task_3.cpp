#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 100


class Rider {
    public:
    int x,y,k;

    Rider(){
        x=0;
        y=0;
        k=0;
    }
};

int main() {
    ifstream input("in.txt");
    ofstream output("out.txt");
     int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
     int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

     int n,m,q;
    input >> n >> m >> q;
    vector<Rider> rider;
    int x, y, k;
    for (int i = 0; i < q; i++) {
        input >> x >> y >> k;
        rider.push_back({x, y, k});
    }
    int arr[MAX][MAX][MAX*MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= 100;k++) {
                arr[i][j][k] = -1;
            }
        }
    }
    //
    while (!q1.empty()) {
        int x = q1.front();  //
        top--;
        int y = q1.front();  //
        q1.pop();

        for (int K = 0; K < 8; K++) {
            for ( Rider& i : rider) {
                int nx = x + dx[K] * i.k;
                int ny = y + dy[K] * i.k;
                while(true) {
                    arr[nx][ny][i.k] = arr[x][y][i.k] + 1;
                    q1.push({nx, ny});
                }
            }
        }
    }

    int min = -1;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            int Moves = 0;
            for ( Rider& i : rider) {
                if (arr[x][y][i.k] == -1) {
                    Moves = -1;
                    break;
                }
                Moves += board[x][y][i.k];
            }
            ?
        }
    }

    output << min << endl;

    return 0;
}
