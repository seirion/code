#!/usr/bin/env python3
# coding: utf-8

n = int(input())
for i in range(n):
    s = input().replace('1', 'True').replace('0', 'False')
    x = True
    X = False
    r1 = eval(s)
    x = False
    X = True
    r2 = eval(s)
    if (r1 == r2):
        print("Case #{}: 0".format(i+1))
    else:
        print("Case #{}: 1".format(i+1))

