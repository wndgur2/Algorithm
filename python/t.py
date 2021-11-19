def updown(n):
    if(n >= 0):
        return int(n)+((n) % 1 >= 0.5)
    else:
        return int(n)+((n) % 1 > 0.5)-(n % 1 != 0)


print(updown(-4))
