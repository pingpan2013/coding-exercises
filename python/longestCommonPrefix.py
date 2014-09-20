#!/usr/bin/python

'''calculate longest common prefix of a given list of words'''

class Solution():
    def __init__(self, _words):
        self.words = _words
    
    def longestCommonPrefix_(self):
        '''Most pythonic way to find out the most common prefix of two strings'''
        word0 = self.words[0]
        word1 = self.words[1]
        return word1[:[x[0] == x[1] for x in zip(word0, word1) + [False]].index(False)]
                                                '''+ [False] here is in case of null'''                        
    def longestCommonPrefix(self):
        '''For a list of words'''
        words = sorted(self.words)
        first = words[0]
        last  = words[-1]
        result = ""

        for i in xrange(min(len(first), len(last))):
            if first[i] == last[i]:
                result += first[i] 
            else:
                break
        return result

s = Solution(['Test_DTW', 'Test_AMD', 'Test_CPP', 'Test_Lynn'])
print s.longestCommonPrefix()
print s.longestCommonPrefix_()

