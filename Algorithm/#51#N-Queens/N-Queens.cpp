#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution 
{
public:
    vector<vector<string> > result;
    vector<string> tempResult;
    vector<int> chessBoard;
    int target;

    bool isAvailable(int row, int line)
    {
        for(int i=0;i<row;i++)
        {
            if( line == chessBoard[i]
                || abs(row-i) == abs(line - chessBoard[i]) )
                return false;
        }
        return true;
    }

    void solve(int curLine)
    {
        if(curLine == target)
        {
            result.push_back(tempResult);
            for(int i=0;i<target;i++)
                result.back()[i][chessBoard[i]] = 'Q';
        }
        else
        {
            for(int i=0;i<target;i++)
            {
                if(isAvailable(curLine,i))
                {
                    chessBoard[curLine] = i;
                    solve(curLine+1);
                }
            }
        }
    }

    vector<vector<string> > solveNQueens(int n)
    {
        chessBoard.resize(n);
        target = n;

        string tempRow;
        for(int i=0;i<n;i++)
            tempRow.push_back('.');
        for(int i=0;i<n;i++)
            tempResult.push_back(tempRow);

        solve(0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int n = 12;
    Solution sol;
    vector<vector<string> > result = sol.solveNQueens(n);
    cout<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout << " num " << i+1 <<endl;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
                cout<<result[i][j][k]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}