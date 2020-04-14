#include<iostream>
#include<math.h>
#include <string>
#include <vector>

using namespace std;

/// 最长公共子序列长度
int lcs(string &X, string &Y, int m, int n) {

    // 构造二维数组 
    //  m+1 * n+1
    vector<vector<int> > table(m+1, vector<int>(n+1));

    for (size_t i = 0; i < m + 1; i++)
    {
        for (size_t j = 0; j < n + 1; j++)
        {
            // 第一行，第一列初始化为0
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            // 如果字符相等
            else if(X[i-1] == Y[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
            }
            // 不相等
            else {
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    
    // (m, n)就是最终的结果
    return table[m][n];
}

// 回溯最长公共子串
vector<string> tracebackLCS2(vector<vector<int> >& table, int max, string &X, string &Y) {

    vector<string>vt;
    for (size_t row = table.size() - 1; row > max - 1; row--)
    {
        vector<int> colTable = table[row];
        for (size_t col = colTable.size() - 1; col > max - 1; col--)
        {
            // 回溯, 找到一个
            if (table[row][col] == max)
            {
                string oneLcs;
                int tRow = row, tCol = col;
                while (table[tRow][tCol] != 0)
                {
                    oneLcs.push_back(X[tRow - 1]);
                    
                    // 对角线回溯
                    tRow--;
                    tCol--;
                }
                reverse(oneLcs.begin(), oneLcs.end());
                vt.push_back(oneLcs);
            }
        }
    }

    return vt;
}

// 最长公共子串
vector<string> lcs_2(string &X, string &Y, int m, int n) {

    // 构造二维数组 
    //  m+1 * n+1
    vector<vector<int> > table(m+1, vector<int>(n+1));
    int biggest = 0;
    for (size_t i = 0; i < m + 1; i++)
    {
        for (size_t j = 0; j < n + 1; j++)
        {
            // 第一行，第一列初始化为0
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            // 如果字符相等
            else if(X[i-1] == Y[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
                // 记录最大值
                if (table[i][j] > biggest) {
                    biggest = table[i][j];
                }
            }
            // 不相等
            else {
                // 不相等则要归0
                table[i][j] = 0;
            }
        }
    }
    
    // biggest 就是最终的结果
    // 回溯
    return tracebackLCS2(table, biggest, X, Y);
}

int main(int argc, char const *argv[])
{
    string X = "ABCBDAB";
	string Y = "BDCABA";
 
	cout << "The length of LCS is " << lcs(X, Y, X.length(), Y.length());
	cout << endl;

    cout << "The length of LCS2 is ";
    
    vector <string> vt = lcs_2(X, Y, X.length(), Y.length());
    for (size_t i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
    cout << endl;

    return 0;
}