from math import *
a, b, x, y = map(int, input().split(' '))
print(min(a//(x//gcd(x,y)), b//(y//gcd(x,y))))
