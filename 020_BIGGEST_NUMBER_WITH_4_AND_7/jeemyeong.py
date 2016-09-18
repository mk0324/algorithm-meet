num = int(input())
num = list(str(num))
for i in range(len(num)):
	if int(num[i])>7:
		num[i] = "7"
		if i<len(num)-1:
			num[i+1] = "9"
	elif int(num[i])==7:
		num[i] = "7"
	elif int(num[i])>4:
		num[i] = "4"
		if i<len(num)-1:
			num[i+1] = "9"
	elif int(num[i])==4:
		num[i] = "4"
	elif int(num[i])>0:
		num[i] = "0"
		if i<len(num)-1:
			num[i+1] = "9"
print(int("".join(num)))