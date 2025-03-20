'''
Created on 17 Aug 2019

@author: ctait
'''

def solution_stonewall(H):
    block_cnt = 0
     
    stack = []
     
    for height in H:
        # remove all blocks that are bigger than my height
        while len(stack) != 0 and stack[-1] > height:
            stack.pop()
         
        if len(stack) != 0 and stack[-1] == height:
            # we already paid for this size
            pass
        else:
            # new block is required, push it's size to the stack
            block_cnt += 1
            stack.append(height)
             
    return block_cnt

if __name__ == '__main__':
    H = [ 8, 8, 5, 7, 9, 8, 7, 4, 8]
    block_cnt = solution_stonewall(H)
    print("solution_stonewall 1 = {0:d}".format(block_cnt))
