for line in range(1, 206): 
    C = 1;
    row = ""
    for i in range(1, line + 1):
        row = row + str(C)
        row = row + " "
        C = C * (line - i) // i; 
    print(row[:-1])


