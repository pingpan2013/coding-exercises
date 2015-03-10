/*
 * =====================================================================================
 *
 *       Filename:  implement_stack_using_heap.cc
 *
 *    Description:  implement stack using heap
 *
 *        Created:  03/10/2015 01:11:02
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// Idea:
// for each element, use a variable to indicate its priority
// each time we push the pair <element, priority> into the max heap
//
// using a priority queue to represent heap for simplicity
//
// for push(), increase the priority
// for pop(),  decrease the priority
