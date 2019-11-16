"""
给你一些区域列表 regions ，每个列表的第一个区域都包含这个列表内所有其他区域。

很自然地，如果区域 X 包含区域 Y ，那么区域 X  比区域 Y 大。

给定两个区域 region1 和 region2 ，找到同时包含这两个区域的 最小 区域。

如果区域列表中 r1 包含 r2 和 r3 ，那么数据保证 r2 不会包含 r3 。

数据同样保证最小公共区域一定存在。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-common-region
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def findSmallestRegion(self, regions, region1, region2):
        tree = {}
        for reg_list in regions:
            for reg in reg_list[1:]:
                if reg not in tree:
                    tree[reg] = reg_list[0]

        # father1 = tree[region1]
        # father2 = tree[region2]
        while True:
            temp = region2
            try:
                while True:
                    if region1 == temp:
                        return region1
                    else:
                        father2 = tree[temp]
                        temp = father2
            except:
                region1 = tree[region1]


if __name__ == '__main__':
    so = Solution()
    input = [["Earth", "North America", "South America"],["North America", "United States", "Canada"],["United States", "New York", "Boston"],["Canada", "Ontario", "Quebec"],["South America", "Brazil"]]

    res = so.findSmallestRegion([["Earth",
                            "North America",
                            "South America"], ["North America",
                                               "United States",
                                               "Canada"], ["United States",
                                                           "New York",
                                                           "Boston"], ["Canada",
                                                                       "Ontario",
                                                                       "Quebec"], ["South America",
                                                                                   "Brazil"]],
                          "Canada",
                          "South America")
    print(res)
