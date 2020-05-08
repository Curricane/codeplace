#include <iostream>
#include <vector>

using namespace std;

/**
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
*/

class Solution
{
public:
    bool Find(vector<vector<int> > array, int target)
    {
        if (array.size() <= 0 )
        {
            return false;
        }

        int m = array.size();
        int n = array[0].size();

        int h = 0;
        int l = n - 1;

        while( h < m && l > 0)
        {
            int now = array[h][l];
            if ( now == target)
                return true;
            else if (now < target)
                ++h;
            else
            {
                --l;
            }
        }

        return false;
    }
};

int test1()
{
    int a1[] = {1,2,8,9};
    int a2[] = {2, 4, 9, 12};
    int a3[] = {4, 7, 10, 13};
    int a4[] = {6, 8, 11, 15};
    vector<vector<int> > array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution s;
    cout << "s.Find(array, 7): " << s.Find(array, 7) << endl;
    cout << "s.Find(array, 16): " << s.Find(array, 16) << endl;
    cout << "s.Find(array, 0): " << s.Find(array, 0) << endl;

    vector<vector<int> > a;
    cout << "s.Find(a, 10): " << s.Find(a, 10) << endl;

    return 0;
}

int main()
{
    test1();
    return 0;
}
