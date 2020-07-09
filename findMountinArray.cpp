
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation

/* 
���룺array = [1,2,3,4,5,3,1], target = 3
�����2
���ͣ�3 �������г��������Σ��±�ֱ�Ϊ 2 �� 5�����Ƿ�����С���±� 2��

˼·
1 ���ַ��ҵ��ⶥλ��
2 ��߶��ַ���Ŀ��ֵ
3 ������û�ҵ����ұ��ҡ�
 */
class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int biSearch(int target, MountainArray &mountainArr, int start, int end)
    {
        int mid = 0;
        if (start == 0)
        {
            while (start <= end)
            {
                mid = (end - start) / 2 + start;
                if (mountainArr.get(mid) == target)
                    return mid;
                else if (mountainArr.get(mid) > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        else
        {
            while (start <= end)
            {
                mid = (end - start) / 2 + start;
                if (mountainArr.get(mid) == target)
                    return mid;
                else if (mountainArr.get(mid) > target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int start = 0, end = mountainArr.length() - 1;
        int right = end;
        int mid = 0, peakPos = 0, targetPos = 0;
        while (start <= end)
        {
            mid = start+ (end - start) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                end = mid - 1;
            else
                start = mid + 1;
        }
        peakPos = start;
        targetPos = biSearch(target, mountainArr, 0, peakPos);
        if (targetPos == -1)
            targetPos = biSearch(target, mountainArr, peakPos, right);
        return targetPos;
    }
};
