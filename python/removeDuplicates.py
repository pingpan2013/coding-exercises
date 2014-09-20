#!/usr/bin/python

'''
Remove duplicates from sorted array
'''

class Solution:
    '''more python and used extra space'''
    def removeDup(self, text):
        tem = list(text)
        res = []
        for i in tem:
            if i not in res:
                res.append(i)
        return ("".join(res), len(res))


    '''move C++, no extra space'''
    def removeDup_(self, text):
        if len(text) <= 1:
            return (text, 0)
        
        tail = 1
        for fast in xrange(1, len(text)):
            for slow in xrange(0, tail):
                if text[slow] == text[fast]:
                    break;    
            if slow == tail - 1:
                text[tail] = text[fast] 
                tail += 1
        return ("".join(text[:tail]), tail)


s = Solution()
print s.removeDup(list("TestMDest"))
print s.removeDup_(list("TestMDest"))
