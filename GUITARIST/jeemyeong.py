restriction = list(map(int, input().split()))
inputList = list(map(int, input().split()))

start = restriction[1]
maximum = restriction[2]

recentNumbers = [start]

for i in inputList:
	newNumbers = []
	for j in recentNumbers:
		if 0 <= j-i:
			newNumbers.append(j-i)
		if j+i <= maximum:
			newNumbers.append(j+i)
	recentNumbers = list(newNumbers)
	if not recentNumbers:
		print("-1")
		break

if recentNumbers:
	print(max(recentNumbers))

