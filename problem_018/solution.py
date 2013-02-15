#!/usr/bin/python

# This same structure is inside tree.txt.
#
# By starting at the top of the triangle below and moving to adjacent numbers
# on the row below, the maximum total from top to bottom is 23.
#
#    3
#   7 4            That is, 3 + 7 + 4 + 9 = 23.
#  2 4 6
# 8 5 9 3


import sys
import math
from array import array


tree_file = 'tree.txt'

class MotherfuckingTriangleTreeList(object):
	def __init__(self):
		self.value = 0

		self.left  = None
		self.right = None

		self.left_parent = None
		self.righ_parent = None

		self.last_element = None
		self.depth = 0

def debug_array(array, prefix = ''):
	array_str = ''
	for node in array:
		array_str += str(node.value) + ', '
	
	print prefix + ' - ' + array_str


def walk(tree, node, array, current_sum, best, best_sum):
	if node: print 'walking into ' + str(node.value)

	if node:
		array.append(node)
		current_sum += int(node.value)

	envisioned_sum = ( (tree[0].depth - len(array)) * 99 ) + current_sum
	if envisioned_sum < best_sum:
		# print 'visioned sum ' + str(envisioned_sum) + ' < best ' + str(int(best_sum)) + ' array size ' + str(len(array))
		array.pop()
		current_sum -= int(node.value)
		return best, best_sum

	if current_sum > best_sum:
		# print 'increasing best sum from ' + str(best_sum) + ' to ' + str(current_sum)
		best = list(array)
		best_sum = int(current_sum)
	
	if node.left:  best, best_sum = walk(tree, node.left,  array, current_sum, best, best_sum)
	if node.right: best, best_sum = walk(tree, node.right, array, current_sum, best, best_sum)

	array.pop()
	return best, best_sum


def main():
	print 'Starting...'

	# set the root node
	tree_list = []
	total_lines = 0

	fp = open(tree_file)

	for line in fp:
		numbers = line.split()
		for number in numbers:
			new_item = MotherfuckingTriangleTreeList()
			new_item.value = number
			tree_list.append(new_item)

		total_lines += 1

	fp.close()


	line_index = 1
	elements_to_next_line = 1
	elements_behind = 0
	for node in tree_list:
		if elements_to_next_line == 0:
			line_index += 1
			elements_to_next_line = line_index - 1
			elements_behind = (line_index + 1) * (line_index + 2) / 2
		else:
			elements_to_next_line -= 1

		if elements_behind <= len(tree_list):
			left_child_index = tree_list.index(node) + line_index
			node.left  = tree_list[left_child_index + 0]
			node.right = tree_list[left_child_index + 1]
		else:
			break
	
	tree_list[0].depth = total_lines
	print 'list has ' + str(total_lines)
	
	# do a walk
	node = tree_list[0]
	array = []
	best = []
	current_sum = 0
	best_sum = 0

	best, best_sum = walk(tree_list, tree_list[0], array, current_sum, best, best_sum)
	debug_array(best, 'total sum is ' + str(best_sum))


if __name__ == "__main__":
	main()
