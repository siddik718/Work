t = int(input())
while(t):
    l = list(map(int,input().split))
    l.sort()
    print(l[0]*l[2])
    t-=1