def sumToMax(inputList):
	indexMax = inputList.index(max(inputList))
	if indexMax == 0:
		return 0
	sumingToMax = 0
	for i in range(indexMax):
		sumingToMax += (inputList[indexMax] - inputList[i])
	if len(inputList)-1 == indexMax:
		return sumingToMax
	sumingToMax += sumToMax(inputList[indexMax+1:])
	return sumingToMax

for case in range(int(input())):
	N = int(input())
	inputList = list(map(int, input().split()))
	print(sumToMax(inputList))



