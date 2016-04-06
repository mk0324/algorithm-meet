import re
from math import log
cases = int(input())
while cases > 0:
    pw_cnt = int(input())
    result = ''
    pw_strength = 0
    while pw_cnt > 0:
        pw = input()
        tmp = len(re.findall(r'[a-z]', pw)) * log(26, 10) + len(re.findall(r'\d', pw))
        if tmp > pw_strength:
            result = pw
            pw_strength = tmp
        elif tmp == pw_strength and pw < result:
            result = pw
            pw_strength = tmp
        pw_cnt -= 1
    print(result)
    cases -= 1
