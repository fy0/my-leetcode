# coding: utf-8

class Solution(object):

    def pickUnique(self, board, possibleTable, x, y, val):
        board[x][y] = val
        rows = len(board)
        columns = len(board[0])
        
        del possibleTable[x, y]
        
        def pt_remove(i, j, val):
            if val in possibleTable[i, j]:
                possibleTable[i, j].remove(val)
                if not possibleTable[i, j]:
                    del possibleTable[i, j]

        # 横向更新
        for i in range(rows):
            if (i, y) in possibleTable:
                pt_remove(i, y, val)

        # 纵向更新
        for i in range(columns):
            if (x, i) in possibleTable:
                pt_remove(x, i, val)

        # 方块更新
        x1 = x - x % 3
        y1 = y - y % 3
        
        for i in range(x1, x1 + 3):
            for j in range(y1, y1 + 3):
                if (i, j) in possibleTable:
                    pt_remove(i, j, val)


    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        columns = len(board[0])
        possibleTable = {}
        
        board = list(map(list, board))

        # 横向可能性
        for i in range(rows):
            possible = set(range(1, columns+1))
            for j in range(columns):
                if board[i][j] != '.':
                    possible.remove(int(board[i][j]))

            for j in range(columns):
                if board[i][j] == '.':
                    possibleTable[i, j] = possible.copy()


        # 纵向可能性
        for j in range(columns):
            possible = set(range(1, rows+1))
            for i in range(rows):
                if board[i][j] != '.':
                    possible.remove(int(board[i][j]))

            for i in range(rows):
                if board[i][j] == '.':
                    if possibleTable[i, j]:
                        possibleTable[i, j] = possibleTable[i, j].intersection(possible)
                    else:
                        possibleTable[i, j] = possible.copy()

        # 填方格
        for i in range(rows // 3):
            for j in range(columns // 3):
                possible = set(range(1, columns+1))
                for x in range(i * 3, (i+1) * 3):
                    for y in range(j * 3, (j+1) * 3):
                        if board[x][y] != '.':
                            possible.remove(int(board[x][y]))
                        #print(x, y)
                #print('---')

                for x in range(i * 3, (i+1) * 3):
                    for y in range(j * 3, (j+1) * 3):
                        if board[x][y] == '.':
                            if possibleTable[x, y]:
                                possibleTable[x, y] = possibleTable[x, y].intersection(possible)
                            else:
                                possibleTable[x, y] = possible.copy()
                        

        for k, v in possibleTable.items():
            print(k, v)
            
        for i in board:
            print(list(map(str, i)))

        while True:
            items = []
            vals = []
            for k, v in possibleTable.items():
                if len(v) == 1:
                    items.append(k)
                    vals.append(list(v)[0])
    
            for i in range(len(items)):
                x, y = items[i]
                self.pickUnique(board, possibleTable, x, y, vals[i])
                
            if not items:
                break

        #print(len(possibleTable))
        print('-----')
        for i in board:
            print(list(map(str, i)))

        #if s.i < 7:
        #    s.i += 1
        #    self.solveSudoku(board)

s = Solution()

s.i = 1

s.solveSudoku(["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."])

