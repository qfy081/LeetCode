#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> searchRange(int A[], int n, int target) 
    {
        begin = end = -1;
        find(A, 0, n - 1, target);
        vector<int> ans;
        ans.push_back(begin);
        ans.push_back(end);
        return ans;
    }
    
private:
    int begin;
    int end;
    
    void find(int A[], int l, int r, int target) 
    {
        if (l > r) 
        {
            return;
        }
        int mid = (l + r) >> 1;
        if (A[mid] == target) 
        {
            if (mid < begin || begin == -1) 
            {
                begin = mid;
            }            
            if (mid > end) 
            {
                end = mid;
            }
            find(A, l, mid - 1, target);
            find(A, mid + 1, r, target);
        }
        else if (A[mid] < target) 
        {
            find(A, mid + 1, r, target);
        }
        else 
        {
            find(A, l, mid - 1, target);
        }
    }
};

int main()
{
    int a[] = {5, 7, 7, 8, 8, 10};
    Solution sol;
    vector<int> res = sol.searchRange(a,6,8);
    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
    cout<<endl;
    return 0;
}