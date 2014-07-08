#!/usr/bin/python

'''
Merge two sorted lists
'''

class Solution:
    '''More python style'''
    def mergeTwoLists(self, l1, l2):
        return sorted(l1 + l2)

    def mergeTwoLists_(self, l1, l2):
        l1.extend(l2)
        return sorted(l1)
    
    '''More C++ style'''
    def mergeTwoLists__(self, l1, l2):
        res = []
        while l1 and l2:
            if l1[0] <= l2[0]:
                item = l1.pop(0)
                res.append(item)
            else:
                item = l2.pop(0)
                res.append(item)
        
        res.extend(l1 if l1 else l2)
        return res

s = Solution()
print s.mergeTwoLists([1, 3, 6, 8], [2, 4, 7, 10, 12, 13])
print s.mergeTwoLists_([1, 3, 6, 8], [2, 4, 7, 10, 12, 13])
print s.mergeTwoLists__([1, 3, 6, 8], [2, 4, 7, 10, 12, 13])
