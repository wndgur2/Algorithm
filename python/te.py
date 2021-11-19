def howM(number, devision):
    tempRes = 0
    square = 1
    while 1:
        temp = number//(devision**square)
        if(temp >= 1):
            tempRes += temp
            square += 1
        else:
            return tempRes


print(howM(10, 2))
