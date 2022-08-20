def checkBoxIsEmpty(pos):
    if (board[pos] == ' '):
        return True
    else:
        return False


def checkDraw():
    for key in board.keys():
        if board[key] == ' ':
            return False

    return True


def checkWin():
    if (board[1] == board[2] and board[1] == board[3] and board[1] != ' '):
        return True
    elif (board[4] == board[5] and board[4] == board[6] and board[4] != ' '):
        return True
    elif (board[7] == board[8] and board[7] == board[9] and board[7] != ' '):
        return True
    elif (board[1] == board[4] and board[1] == board[7] and board[1] != ' '):
        return True
    elif (board[2] == board[5] and board[2] == board[8] and board[2] != ' '):
        return True
    elif (board[3] == board[6] and board[3] == board[9] and board[3] != ' '):
        return True
    elif (board[1] == board[5] and board[1] == board[9] and board[1] != ' '):
        return True
    elif (board[7] == board[5] and board[7] == board[3] and board[7] != ' '):
        return True
    else:
        return False


def checkWhichMarkWon(mark):
    if (board[1] == board[2] and board[1] == board[3] and board[1] == mark):
        return True
    elif (board[4] == board[5] and board[4] == board[6] and board[4] == mark):
        return True
    elif (board[7] == board[8] and board[7] == board[9] and board[7] == mark):
        return True
    elif (board[1] == board[4] and board[1] == board[7] and board[1] == mark):
        return True
    elif (board[2] == board[5] and board[2] == board[8] and board[2] == mark):
        return True
    elif (board[3] == board[6] and board[3] == board[9] and board[3] == mark):
        return True
    elif (board[1] == board[5] and board[1] == board[9] and board[1] == mark):
        return True
    elif (board[7] == board[5] and board[7] == board[3] and board[7] == mark):
        return True
    else:
        return False


def insertLetter(letter, pos):
    if checkBoxIsEmpty(pos):
        board[pos] = letter
        printBoard(board)

        if (checkDraw()):
            print("Draw!!")
            exit()
        if (checkWin()):
            if letter == bot:
                print("AI wins!!")
                exit()
            else:
                print("Player Wins!!")
                exit()
        return
    else:
        print("Can't insert here!!")
        newPosition = int(input("Enter the new position: "))
        insertLetter(letter, newPosition)

def playerMove():
    position = int(input("Enter the position for 'O': "))
    insertLetter(player, position)
    return


def compMove():
    bestScore = -1000
    bestMove = 0
    for key in board.keys():
        if (board[key] == ' '):
            board[key] = bot
            score = minimax(board, False)
            board[key] = ' '

            if (score > bestScore):
                bestScore = score
                bestMove = key

    insertLetter(bot, bestMove)
    return

#minimax algorithm
def minimax(board, isMaximizing):

    if checkWhichMarkWon(bot):
        return 100
    elif checkWhichMarkWon(player):
        return -100
    elif checkDraw():
        return 0

    if isMaximizing:
        bestScore = -1000
        for key in board.keys():
            if (board[key] == ' '):
                board[key] = bot
                score = minimax(board, False)
                board[key] = ' '

                if (score > bestScore):
                    bestScore = score

        return bestScore

    else:
        bestScore = 800
        for key in board.keys():
            if (board[key] == ' '):
                board[key] = player
                score = minimax(board, True)
                board[key] = ' '

                if (score < bestScore):
                    bestScore = score

        return bestScore

def printBoard(board):
    print("   " + board[1] + "  |   " + board[2] + "  |  " + board[3])
    print("______+______+______")
    print("   " + board[4] + "  |   " + board[5] + "  |  " + board[6])
    print("______+______+______")
    print("   " + board[7] + "  |   " + board[8] + "  |  " + board[9])
    print("\n")


#driver code starts here!!
board = {1: ' ', 2: ' ', 3: ' ',
         4: ' ', 5: ' ', 6: ' ',
         7: ' ', 8: ' ', 9: ' '
         }

player = 'O'
bot = 'X'

printBoard(board)

while not checkWin():
    playerMove()
    compMove()
