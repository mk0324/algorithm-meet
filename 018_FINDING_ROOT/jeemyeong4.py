import copy

inputList = []
size = int(input())
for _ in range(size):
    inputList.append(list(map(lambda x:int(x),input().split())))
    
solution = copy.deepcopy(inputList)

for i in range(size):
	for j in range(size):
		if solution[i][j] == 0:
			solution[i][j] = 9999
for i in range(size):
    for j in range(size):
        for k in range(size):
        	if solution[j][k] > solution[j][i] + solution[i][k]:
        		solution[j][k] = solution[j][i] + solution[i][k]
                
for i in solution:
    for j in i:
    	if j == 9999:
    		print(0, end=" ")
    	else:
    		print(1, end=" ")
    print()