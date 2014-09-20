#!/usr/bin/python

'''
Group anagrams for a given list of words

e.g
input = ["art", "rat", "bats", "banana", "stab", "tar"]
output = [["art", "rat", "tar], ["bats", "stab"], ["banana"]]"]]
'''
from itertools import groupby

class Solution():
    def groupAnagrams(self, words):
        '''Using the dictionary data structure'''
        dic = {}
        for word in words:
            hash_word = ''.join(sorted(word))
            if hash_word not in dic:
                dic[hash_word] = []
                dic[hash_word].append(word)
            else:
                dic[hash_word].append(word)
        return sorted(dic.values())
    
    def groupAnagrams_(self, words):
        '''Using the built-in groupby function'''
        result = []
        for key, group in groupby(sorted(words, key=sorted), sorted):         
            result.append(list(group))
        return sorted(result)

s = Solution()
words = ["art", "rat", "bats", "banana", "stab", "tar"]
print s.groupAnagrams(words)
print s.groupAnagrams_(words)



