#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


/* 
合法的ip：
1 每一段的长度不超过3且值小于等于255
2 长度超过1，但是第一位是0的不合法，例如010，001不合法的

思路1：找出所有位置的全排列 (n-1)!种可能性，两个1之间为一段，然后判断每一段的合法性，如果每段都合法，加入结果

思路2：dfs，根据合法ip的特点，确定每一段可能的位置，(endMin~endMax)这个范围，然后递归查询每一段的合法性
       如果到第四段都合法，将其加入结果，否则退出此种结果
	   可能性只有 (endMin~endMax)_0 x (endMin~endMax)_1 x (endMin~endMax)_2 x (endMin~endMax)_3种可能性
	   大大降低计算复杂度
 */
class Solution {
public:
	bool isEffectiveAddress(string s)
	{
		int len = s.length();
		int val = atoi(s.c_str());
		if (len>3 || val>255 || (s[0] == '0'&&len>1))
			return 0;
		return 1;
	}

	vector<vector<char>> Permute(int n)
	{
		vector<vector<char>> res;
		vector<char> nums(n, '1');
		int cntZero = n - 3;
		for (int i = 0; i < cntZero; i++)
		{
			nums[i] = '0';
		}
		res.push_back(nums);
		while (next_permutation(nums.begin(), nums.end()))
			res.push_back(nums);
		return res;
	}
	vector<string> restoreIpAddresses(string s) {
		int len = s.length();
		vector<string> res;
		if (len<4 || len>12)
			return res;
		vector<vector<char>> Per = Permute(len - 1);
		int rowSize = Per.size();
		int colSize = Per[0].size();
		string address = "";
		string temp = "";
		int i = 0, j = 0;
		for (i = 0; i < rowSize; i++)
		{
			temp += s[0];
			for (j = 0; j < colSize; j++)
			{
				if (Per[i][j] == '1')
				{
					if (!isEffectiveAddress(temp))
					{
						break;
					}
					temp += ".";
					address += temp;
					temp.clear();
				}
				temp += s[j + 1];
			}
			if (isEffectiveAddress(temp) && j == colSize)
			{
				address += temp;
				res.emplace_back(address);
			}
			address.clear();
			temp.clear();
		}
		return res;
	}
};


class Solution1 {
public:
    vector<string>res;
    int n; //字符串s长度
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        dfs(0, 0, "", s);
        return res;
    }
	void dfs(int start, int depth,string path,string s)
	{
		if(depth==4)
		{
			path.pop_back();//弹掉最后的"."
			res.emplace_back(path);
			return;
		}
		int n = s.length();
		int endMin = max(start + 1, n - (3 - depth) * 3);
		int endMax = min(start + 3, n - (3 - depth));

		for (int end = endMin; end <= endMax;end++)
		{
			string split = s.substr(start, end - start);
			int len = split.length();
			if(len>1&&split[0]=='0')
				break;
			if(stoi(split)<=255)
			{
				dfs(end, depth + 1, path + (split + "."), s);
			}
		}
	}
};

int main()
{
    string s = "2552551135";
    Solution1 p;
    vector <string> res = p.restoreIpAddresses(s);
	cout << res.size() << endl;
	return 0;
}