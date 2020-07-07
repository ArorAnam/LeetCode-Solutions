class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        peri = 0
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    if j-1 >= 0:
                        if grid[i][j-1] == 0:
                            peri += 1
                    elif j-1 < 0:
                        peri += 1
                        
                    if i-1 >= 0:
                        if grid[i-1][j] == 0:
                            peri += 1
                    elif i-1 < 0:
                        peri += 1
                    
                    if j+1 < m:
                        if grid[i][j+1] == 0:
                            peri += 1
                    elif j+1 > m:
                        peri += 1
                    
                    if i+1 < n:
                        if grid[i+1][j] == 0:
                            peri += 1
                    elif i+1 > n:
                        peri += 1
                        
        return peri
                    