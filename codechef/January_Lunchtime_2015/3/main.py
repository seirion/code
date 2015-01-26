#!/usr/bin/python
# -*- coding: utf8 -*-

"""
http://www.codechef.com/LTIME20/problems/LCH15JEF
Just multiply
"""
import sys

def power(a, b, M):
    if b == 0:
        return 1
    if b == 1:
        return a
    if (b % 2 == 0):
        c = power(a, b/2, M)
        return c * c % M
    c = power(a, (b-1)/2, M)
    return c * c * a % M
    

def each(s, M):
    s = s.split('^')
    if len(s) is 1:
        return int(s[0]) % M
    else:
        return power(int(s[0]) % M, int(s[1]) % M, M)

def calc(s, M):
    res = 1
    s = s.replace('**', '^').split('*')
    for e in s:
        res *= each(e, M)
    print res

def solve():
    line = sys.stdin.readline().split(' ')
    M = int(line[0]) 
    calc(line[1], M)

def main():
    C = int(sys.stdin.readline())
    for _ in xrange(C):
        solve()

if '__main__' == __name__:
    main()
