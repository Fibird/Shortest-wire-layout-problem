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
    for (int i = 0; i < m_height; ++i)
    {
        circuitBoard.m[i] = new int[m_width];
    }
    // Initialize the circuit board
    for (int i = 0; i < m_width; ++i)
    {
        if (i == (m_width / 2) && j == 0)
        {
            circuitBoard.m[i][j] = -1;
        }
        if (i == 3 && j < 4)
        {
            circuitBoard.m[i][j] = -1;
        }
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
