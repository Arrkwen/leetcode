#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


/* 
�Ϸ���ip��
1 ÿһ�εĳ��Ȳ�����3��ֵС�ڵ���255
2 ���ȳ���1�����ǵ�һλ��0�Ĳ��Ϸ�������010��001���Ϸ���

˼·1���ҳ�����λ�õ�ȫ���� (n-1)!�ֿ����ԣ�����1֮��Ϊһ�Σ�Ȼ���ж�ÿһ�εĺϷ��ԣ����ÿ�ζ��Ϸ���������

˼·2��dfs�����ݺϷ�ip���ص㣬ȷ��ÿһ�ο��ܵ�λ�ã�(endMin~endMax)�����Χ��Ȼ��ݹ��ѯÿһ�εĺϷ���
       ��������Ķζ��Ϸ�������������������˳����ֽ��
	   ������ֻ�� (endMin~endMax)_0 x (endMin~endMax)_1 x (endMin~endMax)_2 x (endMin~endMax)_3�ֿ�����
	   ��󽵵ͼ��㸴�Ӷ�
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
    int n; //�ַ���s����
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        dfs(0, 0, "", s);
        return res;
    }
	void dfs(int start, int depth,string path,string s)
	{
		if(depth==4)
		{
			path.pop_back();//��������"."
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