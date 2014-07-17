#!/usr/bin/python

'''Permutation'''

class Solution:
    def __init__(self):
        self.result = []

    def __swap(self, word, i, j):
        temp = word[i]
        word[i] = word[j]
        word[j] = temp

    def permutation(self, word, start):
        self.result.append(''.join(word)) 
        for i in xrange(start, len(word)):
            for j in xrange(i + 1, len(word)):
                self.__swap(word, i, j)
                self.permutation(word, i+1)
                self.__swap(word, i, j)

s = Solution()
s.permutation(list('abcd'), 0)
print s.result


