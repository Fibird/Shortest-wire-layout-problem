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
#define W -1 // Wall
#define P -4 // Path

bool FindShortestPath(Matrix board, Position startPoint, Position endPoint);
void Output(Matrix board);
void MarkPath(Matrix board, Position endPoint);

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
        cout << "------Solution------\n";
        MarkPath(circuitBoard, e);
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
    Position neighbor[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (true)
    {
        for (int i = 0; i < 4; ++i)
        {
            Position pos;
            pos.row = curPos.row + neighbor[i].row;
            pos.col = curPos.col + neighbor[i].col;
            if (pos.row >= 0 && pos.col >= 0 && pos.row < board.height && pos.col < board.width)
            {
                if (board.m[pos.row][pos.col] == 0)
                {
                    board.m[pos.row][pos.col] = board.m[curPos.row][curPos.col] + 1;
                    nodeQueue.push(pos);
                }
                if (board.m[pos.row][pos.col] == E)
                {
                    board.m[startPoint.row][startPoint.col] = 0;
                    board.m[endPoint.row][endPoint.col] = board.m[curPos.row][curPos.col] + 1;
                    return true;
                }
            }
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
            if (board.m[i][j] == P)
                cout << '-' << "\t";
            else if (board.m[i][j] == W)
                cout << '#' << "\t";
            else
                cout << "*" << "\t";
        }
        cout << endl;
    }
}

void MarkPath(Matrix board, Position endPoint)
{
    Position curPos(endPoint);
    int curValue = board.m[endPoint.row][endPoint.col];

    while (curValue != 0)
    {
        if (board.m[curPos.row - 1][curPos.col] == (curValue - 1))
        {
            curValue--;
            board.m[--curPos.row][curPos.col] = P;
        }
        else if (board.m[curPos.row][curPos.col + 1] == (curValue - 1))
        {
            curValue--;
            board.m[curPos.row][++curPos.col] = P;
        }
        else if (board.m[curPos.row + 1][curPos.col] == (curValue - 1))
        {
            curValue--;
            board.m[++curPos.row][curPos.col] = P;
        }
        else if (board.m[curPos.row][curPos.col - 1] == (curValue - 1))
        {
            curValue--;
            board.m[curPos.row][--curPos.col] = P;
        }
    }
}
