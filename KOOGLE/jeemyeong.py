import math


list_power = []
first = int(input())
while first != 0:
    first -= 1

    distin = 0
    second = int(input())
    while second !=0:
        second -= 1

        third = input()

        digit_count = 0
        alpha_count = 0

        digit_count += [c.isdigit() for c in third].count(True)
        alpha_count += [c.isalpha() for c in third].count(True)

        log = digit_count*math.log(10) + alpha_count*math.log(26)
        if log > distin:
            distin = log
            power = third
        elif log == distin:
            if len(third) > len(power):                   
                for i in range(len(third)):
                    if ord(third[i]) < ord(power[i]):
                        distin = log
                        power = third
                    elif ord(third[i]) > ord(power[i]):
                        break
                    elif ord(third[i]) == ord(power[i]):
                        continue
                    else:
                        break
            else:
                for i in range(len(power)):
                    if ord(third[i]) < ord(power[i]):
                        distin = log
                        power = third
                    elif ord(third[i]) > ord(power[i]):
                        break
                    elif ord(third[i]) == ord(power[i]):
                        continue
                    else:
                        power = third
                        break
    list_power.append(power)
for i in list_power:
    print(i)
