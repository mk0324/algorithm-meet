#finding root

import copy


inputList = []
size = int(input())
for _ in range(size):
	inputList.append(list(map(lambda x:int(x),input().split())))

solution = copy.deepcopy(inputList)

for i in range(size):
	for j in range(size):
		if inputList[i][j]:
			nextStep = []
			nextStep.append((i,j))
			while nextStep:
				(start, goTo) = nextStep.pop()
				if i != goTo:
					for n in range(size):
						if inputList[goTo][n]:
							nextStep.append((goTo, n))
							solution[i][n] = 1
for i in solution:
    for j in i:
        print(j, end=" ")
    print()










