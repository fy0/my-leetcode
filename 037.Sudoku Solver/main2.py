# coding: utf-8
# 这个也咸鱼掉了，解着解着可能性不为1，线索中断

class Solution(object):
    
    def solveNext(self, board, possibleTable):
        rows = len(board)
        columns = len(board[0])

        items = []
        vals = []
        for k, v in possibleTable.items():
            if len(v) == 1:
                items.append(k)
                vals.append(v[0])

        key = items[0]
        val = vals[0]

        # 横向填写
        board[key[0]][key[1]] = val
        


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

        items = []
        vals = []
        for k, v in possibleTable.items():
            if len(v) == 1:
                board[k[0]][k[1]] = list(v)[0]
                #items.append(k)
                #vals.append(v)
            

        print(len(possibleTable))
        print('-----')
        #for i in board:
        #    print(list(map(str, i)))

        if s.i < 7:
            s.i += 1
            self.solveSudoku(board)

s = Solution()

s.i = 1

s.solveSudoku(["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."])

