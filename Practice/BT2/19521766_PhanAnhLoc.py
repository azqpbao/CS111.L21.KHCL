def chat_win(a, b):
    if ((b == "C") or (b == "B" and a != "C") or (b == "R" and (a != "C" or a != "B"))):
        return True 
    return False

def turn(x):
    if (x == "T"):
        return "10"
    if (x == "J"):
        return "11"
    if (x == "Q"):
        return "12"
    if (x == "K"): 
        return "13"
    if (x == "A"):
        return "14"

def compare(a, b):
    if (int(a[0]) < int(b[0])):
        return 1
    elif (int(a[0]) == int(b[0])):
        if (chat_win(a[1], b[1]) == True):
            return 1
    return 0

f = open("/CARD.INP.txt", "r")
cases = int(f.readline())
f1 = open("/CARD.OUT.txt", "w")

for i in range(cases):
    temp = f.readline() 
    n = int(f.readline())
    adam = []
    eva = []
    points = 0
    for j in range(n):
        adam.append(f.readline())
    for j in range(n):
        eva.append(f.readline())
    eva.reverse()
    for i in range(n):
        a = list(adam[i])
        b = list(eva[i])

        if (a[0].isdigit() and b[0].isdigit()):
            points += compare(a, b)
        
        elif (a[0].isdigit() and b[0].isalpha()):
            points += 1
        
        elif (a[0].isalpha() and b[0].isalpha()):
            a[0] = turn(a[0])
            b[0] = turn(b[0])
            points += compare(a, b)
    f1.write(str(points) + "\n")
f.close()
f1.close()