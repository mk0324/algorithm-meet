# https://www.acmicpc.net/problem/1992
def quadtree():
    size = int(input())
    data = read_data(size)
    while(size > 1):
        data = check_the_smallest_square(data, size)
        size //= 2
    print_data(data)

def read_data(size):
    data = []
    for _ in range(size):
        temp = list(map(int, list(input())))
        data.append(temp)
    return data

def check_the_smallest_square(data, size):
    result = []
    for i in range(0, size, 2):
        raw = []
        for j in range(0, size, 2):
            temp = [data[i][j], data[i][j+1], data[i+1][j], data[i+1][j+1]]
            if all(map(lambda x: True if isinstance(x, int) else False, temp)) and len(set(temp)) == 1:
                raw.append(temp[0])
            else:
                raw.append(temp)
        result.append(raw)
    return result

def print_data(data):
    str_data = str(data)
    str_data = ''.join(str_data.split(", "))
    str_data = str_data.replace("[", "(")
    str_data = str_data.replace("]", ")")
    print(str_data[2:-2])

if __name__ == '__main__':
    quadtree()
