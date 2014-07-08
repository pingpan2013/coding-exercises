#!/usr/bin/python

'''
Remove duplicates from sorted array
'''

class Solution:
    '''more python'''
    def removeDup(self, text):
        tem = list(text)
        res = []
        for i in tem:
            if i not in res:
                res.append(i)
        return "".join(res)


    '''move C++'''
    def removeDup_(self, text):
        pass

s = Solution()
print s.removeDup("TestMDest")
