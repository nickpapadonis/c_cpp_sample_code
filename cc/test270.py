
for n in range(2, 10):
    pfound = True
    for x in range(2, n):
        if n % x == 0:
            pfound = False
            break
    if pfound == True:
        print("prime ", n)
        
