# coding: utf-8

class InvalidBoard(BaseException):
    pass


class Solution(object):
    
    def show_pt(self, pt):
        for k, v in pt.items():
            print(k, v)
    
    def show_board(self, board):
        for i in board:
            print(list(map(str, i)))
        

    def pickUnique(self, board, possibleTable, x, y, val):
        board[x][y] = val
        rows = len(board)
        columns = len(board[0])
        
        if (x, y) in possibleTable:
            del possibleTable[x, y]

        def pt_remove(i, j, val):
            if val in possibleTable[i, j]:
                possibleTable[i, j].remove(val)
                if len(possibleTable[i, j]) == 0:
                    #print(board[i][j])
                    #print(i, j)
                    #self.show_board(board)
                    raise InvalidBoard

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


    def solveSudoku(self, rawboard):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        rows = len(rawboard)
        columns = len(rawboard[0])
        possibleTable = {}
        
        board = list(map(list, rawboard))

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
                        

        #for k, v in possibleTable.items():
        #    print(k, v)
            
        #for i in board:
        #    print(list(map(str, i)))
        
        
        def solve_unique(board, possibleTable):
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
                    
        solve_unique(board, possibleTable)

        def dup_board(_board):
            board = _board[:]
            for _, i in enumerate(board):
                board[_] = i[:]
            return board

        def dup_pt(_pt):
            pt = _pt.copy()
            for k, v in pt.items():
                pt[k] = v.copy()
            return pt

        def try_solve(_board, _pt):
            if len(_pt):
                pt = dup_pt(_pt)
                k, v = pt.popitem()

                for i in v:
                    pt = dup_pt(_pt)
                    board = dup_board(_board)

                    try:
                        self.pickUnique(board, pt, k[0], k[1], i)
                        solve_unique(board, pt)
    
                        if len(pt) == 0:
                            # solved
                            #for i in board:
                            #    print(list(map(str, i)))
                            return board
                        else:
                            ret = try_solve(board, pt)
                            if ret:
                                return ret
                    except InvalidBoard:
                        pass
            else:
                return _board


        ret = try_solve(board, possibleTable)
        #print(ret)
        #self.show_board(ret)
        
        if ret:
            for i in range(len(ret)):
                rawboard[i] = map(str, ret[i])
            #for i in ret:
            #    print(list(map(str, i)))
        
        #print('-----')
        #for i in rawboard:
        #    print(list(map(str, i)))


s = Solution()

#s.solveSudoku(["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."])

s.solveSudoku(["...2...63","3....54.1","..1..398.",".......9.","...538...",".3.......",".263..5..","5.37....8","47...1..."])


