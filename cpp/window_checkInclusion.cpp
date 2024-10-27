/* 
���������ַ���?s1?��?s2��дһ���������ж� s2 �Ƿ���� s1?�����С�

���仰˵����һ���ַ���������֮һ�ǵڶ����ַ������Ӵ���

ʾ��1:

����: s1 = "ab" s2 = "eidbaooo"
���: True
����: s2 ���� s1 ������֮һ ("ba").

˼·����������
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define INT_MAX __INT_MAX__

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(char c:s1)
            need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        int size_s1 = s1.size();
        int size_need = need.size();
        int size_s2 = s2.size();
        while(right<size_s2)
        {
            char c = s2[right];
            right++;
            //�������ƶ����������ֵ
            if(need.count(c))
            {
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }
            //�ж���ര���Ƿ�Ҫ����
            while(right-left>=size_s1)
            {
                //���½��
                if(valid==size_need)
                    return true;
                //�������ƣ��������ֵ
                char c = s2[left];
                left++;
                if(need.count(c))
                {
                    if(window[c]==need[c])
                        valid--;
                    window[c]--;
                }
            }
        }
        return false;
    }
};