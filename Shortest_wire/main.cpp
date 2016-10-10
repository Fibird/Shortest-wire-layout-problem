#include <iostream>
#include <queue>

using namespace std;

struct Matrix
{
    int width;
    int height;
    int **m;
};
struct Position
{
    int row;
    int col;
};
bool FindShortestPath(Matrix board, Position startPoint, Position endPoint);
void Output(Matrix board);

int main()
{
    int m_width, m_height;
    Matrix circuitBoard;
    cout << "Please Enter the width and height of the circuit board: ";
    cin >> m_width >> m_height;
    circuitBoard.width = m_width;
    circuitBoard.height = m_height;
    // Allocate memory for circuit board
    circuitBoard.m = new int*[m_height];
    for (int i = 0; i < 0; ++i)
    {
        circuitBoard.m[i] = new int[m_width];
    }

    return 0;
}

bool FindShortestPath(Matrix board, Position startPoint, Position endPoint)
{

    return true;
}

void Output(Matrix board)
{

}
