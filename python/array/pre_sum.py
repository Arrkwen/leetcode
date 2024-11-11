# https://kamacoder.com/problempage.php?pid=1070
# 本地意在考察输入输出
# ctrl + D 结束输入
# ctrl + C 结束程序
import sys
input = sys.stdin.read

def main():
    data = input().split()
    idx = 1
    n = int(data[0])
    pre_sum = 0
    nums = [0] * n
    for i in range(n):
        pre_sum += int(data[idx+i])
        nums[i] = pre_sum
    idx = idx + n
    while idx < len(data) - 1:
        l, r = int(data[idx]), int(data[idx+1])
        if l < 1:
            print(nums[r])
        else:
            print(nums[r] - nums[l-1])
        idx += 2

if __name__ == "__main__":
    main()
    