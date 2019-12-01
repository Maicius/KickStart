class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        children = list(map(lambda x: [], range(0, nodes)))
        for i in range(1, nodes):
            children[parent[i]].append(i)
        node_sum = [0] * nodes
        def dfs1(node):
            node_sum[node] += value[node]
            for child in children[node]:
                node_sum[node] += dfs1(child)
            return node_sum[node]
        dfs1(0)
        def dfs2(node):
            if node_sum[node] == 0:
                return 0
            ret = 1
            for child in children[node]:
                ret += dfs2(child)
            return ret
        return dfs2(0)

    def deleteTreeNodes2(self, nodes, parent, value):
        """
        BFS 层次遍历
        """
        # 先由下到上汇聚
        for i in range(nodes - 1, 0, -1):
            if parent[i] != -1:
                value[parent[i]] += value[i]
        
        # 再由上到下广播
        ans = 0
        for i in range(1, nodes):
            if parent[i] != -1 and && value[parent[i]] == 0:
                value[i] = 0
            if value[i] != 0:
                ans += 1
        return ans

so = Solution()
nodes = 7
parent = [-1,0,0,1,2,2,2]
value = [1,-2,4,0,-2,-1,-1]
print(so.deleteTreeNodes(nodes, parent, value))