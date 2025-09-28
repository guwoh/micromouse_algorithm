N = 16

maze = [
    list("S111000000000000"),
    list("0011011111111000"),
    list("0010010000011000"),
    list("0010010111011000"),
    list("0010010100011000"),
    list("0011110101111000"),
    list("0000010100010000"),
    list("0000011011101000"),
    list("0000010000010000"),
    list("0111111111111110"),
    list("0100000100010010"),
    list("0111111101111010"),
    list("0000000101000010"),
    list("0111111101111110"),
    list("0100000000000010"),
    list("01111111C1111110")
]

visited = [[False]*N for _ in range(N)]
path = []   # lưu các bước đi

def dfs(x, y):
    if x < 0 or x >= N or y < 0 or y >= N:
        return False
    if maze[x][y] == '0' or visited[x][y]:
        return False
    
    path.append((x,y))  # thêm bước hiện tại vào đường đi

    if maze[x][y] == 'C':
        print("Chuột đã tìm thấy phô mai!")
        print("Đường đi:", path)
        return True
    else:
        print("Chuột không tìm thấy phô mai!")
        return False 
    visited[x][y] = True

    if dfs(x-1, y): return True
    if dfs(x+1, y): return True
    if dfs(x, y-1): return True
    if dfs(x, y+1): return True

    path.pop()  # nếu đi sai thì bỏ bước này ra
    return False

# tìm vị trí Start
for i in range(N):
    for j in range(N):
        if maze[i][j] == 'S':
            start = (i,j)

dfs(*start)

