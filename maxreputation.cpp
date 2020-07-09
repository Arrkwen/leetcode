class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        if n1 == 0:
            return 0
        s1cnt, index, s2cnt = 0, 0, 0
        // recall ������������ѭ���ڵı���������һ����ϣӳ��
        // ���������ѭ���ڣ��������Ǳ����� s1cnt �� s1����ʱƥ�䵽�˵� s2cnt �� s2 �еĵ� index ���ַ�
        // �������֮ǰ������ s1cnt' �� s1 ʱ��ƥ�䵽���ǵ� s2cnt' �� s2 ��ͬ���ĵ� index ���ַ�����ô����ѭ������
        // ������ (s1cnt', s2cnt', index) �� (s1cnt, s2cnt, index) ��ʾ���ΰ�����ͬ index ��ƥ����
        // ��ô��ϣӳ���еļ����� index��ֵ���� (s1cnt', s2cnt') �����Ԫ��
        // ѭ���ھ��ǣ�
        //    - ǰ s1cnt' �� s1 ������ s2cnt' �� s2
        //    - �Ժ��ÿ (s1cnt - s1cnt') �� s1 ������ (s2cnt - s2cnt') �� s2
        // ��ô����ʣ�� (n1 - s1cnt') % (s1cnt - s1cnt') �� s1, ���Ƕ���Щ�� s2 ���б���ƥ��
        // ע�� s2 Ҫ�ӵ� index ���ַ���ʼƥ��
        recall = dict()
        while True:
            // ���Ƕ����һ�� s1�������ܲ����ҵ�ѭ����
            s1cnt += 1
            for ch in s1:
                if ch == s2[index]:
                    index += 1
                    if index == len(s2):
                        s2cnt, index = s2cnt + 1, 0
            // ��û���ҵ�ѭ���ڣ����е� s1 ��������
            if s1cnt == n1:
                return s2cnt // n2
            // ������֮ǰ�� index����ʾ�ҵ���ѭ����
            if index in recall:
                s1cnt_prime, s2cnt_prime = recall[index]
                // ǰ s1cnt' �� s1 ������ s2cnt' �� s2
                pre_loop = (s1cnt_prime, s2cnt_prime)
                // �Ժ��ÿ (s1cnt - s1cnt') �� s1 ������ (s2cnt - s2cnt') �� s2
                in_loop = (s1cnt - s1cnt_prime, s2cnt - s2cnt_prime)
                break
            else:
                recall[index] = (s1cnt, s2cnt)

        // ans �洢���� S1 ������ s2 �����������ǵ�֮ǰ�� pre_loop �� in_loop
        ans = pre_loop[1] + (n1 - pre_loop[0]) // in_loop[0] * in_loop[1]
        // S1 ��ĩβ��ʣ��һЩ s1�����Ǳ�������ƥ��
        rest = (n1 - pre_loop[0]) % in_loop[0]
        for i in range(rest):
            for ch in s1:
                if ch == s2[index]:
                    index += 1
                    if index == len(s2):
                        ans, index = ans + 1, 0
        // S1 ���� ans �� s2����ô�Ͱ��� ans / n2 �� S2
        return ans // n2
