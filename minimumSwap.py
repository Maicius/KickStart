
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        str2 = s1 + s2
        count = 0
        for i in range(len(str2)):
            if str2[i] == 'x':
                count += 1
        if count % 2 != 0:
            return -1
        count = 0
        new_s1 = ''
        new_s2 = ''
        for i in range(len(s1)):
            if (s1[i]!= s2[i]):
                new_s1 += s1[i]
                new_s2 += s2[i]
        count = 0
        s1 = new_s1
        s2 = new_s2
        if (len(s1)) >= 2:
            while (s1.find('xx') != -1 or s1.find('yy') != -1):
                if s1.find('xx') != -1:
                    count += 1
                    s1 = s1.replace('xx', '', 1)
                    s2 = s2.replace('yy', '', 1)
                elif s1.find('yy') != -1:
                    count += 1
                    s1 = s1.replace('yy', '', 1)
                    s2 = s2.replace('xx', '', 1)

            count += (len(s1) // 4) * 2 + (len(s1) % 4)

        return count

if __name__ == '__main__':
    so = Solution()
    # "xxyyxyyyy"
    # "yxyxxxyyxxyxxxx"
    # "yyyxyyyxyxxxyxy"

    print(so.minimumSwap('yxyxxxyyxxyxxxx', 'yyyxyyyxyxxxyxy'))

