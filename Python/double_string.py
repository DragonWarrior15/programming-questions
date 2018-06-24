'''
Given a string S, find if it is possible, after removing none, some or all
characters, that we get a double string
lala, wow etc are examples of double strings
lala = la + la and la == la
wow, remove o and we get ww which can be broken in a similar fashion as above
'''

from sys import stdin

def check_double_string_possible(s):
    if(len(s) == 1):
        return(False)
    char_list = [0] * 26
    for c in s:
        print(c, ord(c) - 97)
        if(char_list[ord(c) - 97] == 1):
            # means that this char has appeared twice
            return(True)
        else:
            char_list[ord(c) - 97] += 1
    return(False)

T = int(stdin.readline().strip())
S =  stdin.readlines()
for s in S:
    if(check_double_string_possible(s)):
        print('Yes')
    else:
        print('No')
