/*A robot is located at the top-left corner of a 4x4 grid. The robot can move
either up, down, left, or right, but can not visit the same spot twice. The
robot is trying to reach the bottom-right corner of the grid.
Print out the unique number of ways the robot can reach its destination.
*/
#include <bits/stdc++.h>
using namespace std;

int w,h;
vector<vector<int> > arr;

int totalPaths(int x, int y){
    if(arr[x][y]==true){
        return 0;
    }
    if(x == w - 1 && y == h - 1){
        return 1;
    }
    int count = 0;
    arr[x][y] = 1;
    if(x > 0){
        count += totalPaths(x - 1, y);
    }
    if(x < w - 1){
        count += totalPaths(x + 1, y);
    }
    if(y > 0){
        count += totalPaths(x,y-1);
    }
    if(y < h-1){
        count += totalPaths(x, y + 1);
    }
    arr[x][y] = 0;
    return count;
}

int main() {
    w=4,h=4;
    arr.resize(w,vector<int>(h,0));
    cout<<totalPaths(0,0);
    return 0;
}