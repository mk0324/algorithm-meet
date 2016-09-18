# n = 5
# nArrays = [6,3,2,10,-10]
# m = 8 
# mArrays = [10,9,-5,2,3,4,5,-10]
# nArrays.sort()

n = int(input())
nArrays = list(map(lambda x:int(x),input().split()))
m = int(input())
mArrays = list(map(lambda x:int(x),input().split()))
print(n,m)
print(nArrays)
print(mArrays)
print
for i in mArrays:
	l = 0
	r = n-1
	find = False
	while l<=r:
		mid = int((l+r)/2)
		if nArrays[mid] == i:
			print(1, end=" ")
			find = True
			break
		elif nArrays[mid] < i:
			l = mid+1
		else:
			r = mid-1
	if not find:
		print(0, end=" ")
print()
