class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque

        rows, coll = len(grid), len(grid[0])
        queue = deque()
        fresh = 0

        for r in range(rows):
            for c in range(coll):
                if grid[r][c] == 2:
                    queue.append((r, c, 0))  
                elif grid[r][c] == 1:
                    fresh += 1

        directions = [(-1,0), (1,0), (0,-1), (0,1)]
        minutes = 0

        while queue:
            r, c, minutes = queue.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < coll and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    fresh -= 1
                    queue.append((nr, nc, minutes + 1))

        return minutes if fresh == 0 else -1