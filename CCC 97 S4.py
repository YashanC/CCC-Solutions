n = int(input())
found = dict()
passage = []
for i in range(n):
    eofline = [0]
    while True:
        line = input().split()
        if not line:
            break
        passage.extend(line)
        eofline.append(len(passage))
    for j in range(len(passage)):
        if passage[j] not in found:
            found[passage[j]] = len(found)+1
        else:
            passage[j] = found[passage[j]]
    while len(eofline)>1:
        print(" ".join(str(passage[k]) for k in range(eofline[0],eofline[1])))
        del eofline[0]
    del passage[:]
    found.clear()
