#!/usr/bin/python

'''
Given an array of integers, find two numbers such that they
add up to a specific trget number, return (index1, index2) with index1 < index2. Note that returned indexes should not be 0 based

i.e.
Input: [2, 7, 11, 15], target = 9
Output: (1, 2)

Assume that each input has exactly one solution
'''

import collections

class Solution:
    '''
    Stupidest way, time complexity O(n^2)
    Also input cannot contain two same numbers
    '''
    def twoSum(self, li, target):
        dic = {}
        res = []
        
        for i in xrange(len(li)):
             dic[li[i]] = i + 1
                 
        for key1, value1 in dic.items():
            for key2, value2 in dic.items():
                if key1 + key2 == target and value1 < value2:
                    res.append((value1, value2))
       
        print "Result: " + str(res)
        return res
    
    '''
    Much smarter way, time complexity O(nlgn), depending on sorting 
    Use dictonary to trace the index
    '''
    def twoSum_(self, li, target):
        right = len(li) - 1
        left = 0
        oli  = sorted(li)    # Complexity depends on the sorting here
        dic  = {}
        res  = []
       

        for i in xrange(len(li)):
             dic[li[i]] = i + 1
        
        while left < right:
            sum = oli[left] + oli[right]
            if sum == target:
                res.append((dic[oli[left]], dic[oli[right]]))
                break
            elif sum > target:
                right -= 1
            else:
                left += 1
        
        print "Result: " + str(res)
     

s = Solution()
s.twoSum([2, 7, 11, 15], 9)
s.twoSum_([2, 7, 11, 15], 9)
