#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> fuckYou;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                stringstream ss(tokens[i]);
                int temp;
                ss >> temp; 
                fuckYou.push(temp);
            }
            else
            {
                int b = fuckYou.empty()? 0:fuckYou.top();
                fuckYou.pop();
                int a = fuckYou.empty()? 0:fuckYou.top();
                fuckYou.pop();
                if(tokens[i] == "+")
                    fuckYou.push(a+b);
                if(tokens[i] == "-")
                    fuckYou.push(a-b);
                if(tokens[i] == "*")
                    fuckYou.push(a*b);
                if(tokens[i] == "/")
                    fuckYou.push(a/b);
            }
        }
        return fuckYou.top();
    }
};

int main()
{
    string a[] = {"0","3","/"};
    vector<string> tokens(a,a+3);
    Solution sol;
    cout<<sol.evalRPN(tokens)<<endl;
    return 0;
}