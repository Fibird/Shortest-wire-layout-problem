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

#define E -3 // End point

bool FindShortestPath(Matrix board, Position startPoint, Position endPoint);
void Output(Matrix board);

int main()
{
    int m_width, m_height;
    Matrix circuitBoard;
    Position s, e;
    ifstream fin;
    fin.open("circuit.txt");    // Read the circuit layout from a file

    fin >> m_height >> m_width;
    fin >> s.row >> s.col;
    fin >> e.row >> e.col;

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
    if (FindShortestPath(circuitBoard, s, e))
    {
        cout << "------One of Solution------\n";
        Output(circuitBoard);
    }
    else
    {
        cout << "There is no path!" << endl;
    }
    fin.close();
    return 0;
}

bool FindShortestPath(Matrix board, Position startPoint, Position endPoint)
{
    queue<Position> nodeQueue;
    Position curPos(startPoint);
    Position neighbor[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (true)
    {
        for (int i = 0; i < 4; ++i)
        {
            Position pos;
            pos.row = curPos.row + neighbor[i].row;
            pos.col = curPos.col + neighbor[i].col;
            if (board.m[pos.row][pos.col] == 0)
            {
                board.m[pos.row][pos.col] = board.m[curPos.row][curPos.col] + 1;
                nodeQueue.push(pos);
            }
            if (board.m[pos.row][pos.col] == E)
                return true;
        }
        if (nodeQueue.empty())
        {
            return false;
        }
        else
        {
            curPos = nodeQueue.front();
            nodeQueue.pop();
        }
    }
}

void Output(Matrix board)
{
    for (int i = 0; i < board.height; ++i)
    {
        for (int j = 0; j < board.width; ++j)
        {
            cout << board.m[i][j] << "\t";
        }
        cout << endl;
    }
}
