"""
给你一个非负整数 num ，返回它的「加密字符串」。

加密的过程是把一个整数用某个未知函数进行转化，你需要从下表推测出该转化函数：
https://leetcode-cn.com/problems/encode-number/
"""
class Solution:
    def encode(self, num: int) -> str:
        return str(bin(num + 1)[3:])