/*
 * =====================================================================================
 *
 *    Description:  
 *    You have k lists of sorted integers. Find the smallest range that includes               
 *    at least one number from each of the k lists.
 *
 *    Reference: http://www.fgdsb.com/2015/01/17/smallest-range/
 *
 *    For example,
 *    List 1: [4, 10, 15, 24, 26]
 *    List 2: [0, 9, 12, 20]
 *    List 3: [5, 18, 22, 30]
 *
 *    The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, 
 *    and 22 from list 3.G家题，实际上就是k路归并的变种题。维护一个长度为n的min heap
 *    （n为数组个数），每次找一个最小的，同时保持记录一个最大的。
 *    
 *    比如那个例子：
 *    heap初始化为[0,4,5]，min = 0, max = 5，当前最小range为[0,5]。
 *    pop掉最小的再push，[4,5,9]，min = 4, max = 9，当前最小range还是[0,5]。
 *    继续，[5,9,10]，min = 5, max = 10，当前最小range还是[0,5]。
 *    继续，[9,10,18]，min = 9, max = 18，当前最小range还是[0,5]。
 *    继续，[10,12,18]，min = 10, max = 18，当前最小range还是[0,5]。
 *    继续，[12,15,18]，min = 12, max = 18，当前最小range还是[0,5]。
 *    继续，[15,18,20]，min = 15, max = 20，当前最小range还是[0,5]。
 *    继续，[18,20,24]，min = 18, max = 24，当前最小range还是[0,5]。
 *    继续，[20,22,24]，min = 20, max = 24，当前最小range变成[20,24]。
 *    
 *    依次类推，最小范围为[20,24]。
 *
 * =====================================================================================
 */


