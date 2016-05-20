def eval(dic, calAccumul, money):
	if money < min(dic, key = lambda t: t[0])[0]:
		return calAccumul
	caloList = set()
	caloList.add(calAccumul)
	for i in range(len(dic)):
		if money-dic[i][0] >=0:
			moneyLeft = money - dic[i][0]
			calAccumulRes = calAccumul + dic[i][1]
			z = eval(dic[i:], calAccumulRes, moneyLeft)
			caloList.add(z)
	return max(caloList)


while True:
	inputLimit = input()
	if inputLimit =='0 0.00':
		break
	number = int(inputLimit.split()[0])
	money = float(inputLimit.split()[1])
	candyDic = []
	for case in range(number):
		candy = input().split()
		if not (float(candy[1]) == 0 or int(candy[0]) == 0):
			candyDic.append((float(candy[1]), int(candy[0])))
	print(eval(candyDic, 0, money))
