# def pyramid(n):
#     count = 1
#     # for _ in range(n-1, 0, -1):
#     #         print(end="  ")

#     # print(1)

#     for x in range(2, n+1):

#         for _ in range(n-x, 0, -1):
#             print(end="  ")
#         for i in range(1, x):
#             print(i, end=" ")
#         print()
#         for _ in range(n-x, 0, -1):
#             print(end="  ")
#         for _ in range(1, x-1):
#             print(end="  ")
#         for j in range(x, 0, -1):
#             print(j, end=" ")

#         print()
#         count = count + 1


def pyramid(n):

    for x in range(1, n+1):

        for gap in range(n-x, 0, -1):
            print(end="  ")
        if (x % 2 == 0):
            for gap in range(1, x):
                print(end="  ")
            for i in range(x, 0, -1):
                print(i, end=" ")
        else:
            for j in range(1, x+1):
                print(j, end=" ")
        print()


pyramid(5)
