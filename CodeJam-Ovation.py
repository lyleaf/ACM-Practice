# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 17:56:44 2015

@author: yiling
For Google Code Jam
"""

        
import fileinput

def friends_to_invite(n,shyness):
    invite = 0
    joined = shyness[0]

    for index in range(1,n+1):
        if index <= joined:
            joined += shyness[index]
        else:
            invite += (index - joined) 
            joined += (shyness[index] + index - joined)
    return invite

def main():
    fin = fileinput.input("A-large.in.txt")
    T = int(next(fin)) # number of test cases
    
    for case in range(1, T+1):
        line = next(fin) # number of figure skaters
        n = int(line.split()[0])
        shyness = list(line.split()[1])
        shyness = list(map(int, shyness))
        invite = friends_to_invite(n,shyness)
        print("Case #{}: {}".format(case, invite))


if __name__ == '__main__':
    main()

