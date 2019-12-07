/**
字符串

ipv4
// 微软终面的第一题
//难点在于考虑到所有可能的情况
x.y.z.w
0<= x<255

192.168.1.1
192..1.1
192.a.b.c
192.a.b.c.d
192.a.b
192.258.1.1 3 
""
92.1.1.1
.1.1.1
.1.1.
1.2.3.1000
...1000

*/
bool judgeIPV4(char* s) {
    if (!s) return false;
    int digit = -1;
    int count = 0;
    while (*s != '\0') {
        if (*s >= '0' && *s <= '9' && digit == -1) {
            digit = 0;
        }
        if (*s >= '0' && *s <= '9' && digit != -1) {
            int temp = *s - '0';
            digit = digit * 10 + temp;
            if (digit > 255) {
                return false;
            }
        } 
        else if(digit == '.') {
            if (digit < 0) {
                return false;
            }
            count += 1;
            if (count > 3) return false;
            digit = -1;
        } else {
            return false;
        }
        s++;
    }
    if (count != 3 || digit < 0) return false;
    return true;
}