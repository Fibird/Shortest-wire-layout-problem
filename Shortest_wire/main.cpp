#include <iostream>
#include <queue>
#include <fstream>

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
    ifstream fin;
    fin.open("circuit.txt");    // Read the circuit layout from a file

    fin >> m_height >> m_width;
    circuitBoard.width = m_width;
    circuitBoard.height = m_height;
    // Allocate memory for circuit board
    circuitBoard.m = new int*[m_height];
    for (int i = 0; i < m_height; ++i)
    {
        circuitBoard.m[i] = new int[m_width];
    }
    // Initialize the circuit board from a file
    for (int i = 0; i < m_height; ++i)
    {
        for (int j = 0; j < m_width; ++j)
        {
            fin >> circuitBoard.m[i][j];
        }
    }

    fin.close();
    return 0;
}

bool FindShortestPath(Matrix board, Position startPoint, Position endPoint)
{

    return true;
}

void Output(Matrix board)
{

}
