#! /bin/python

import sys

class List:
	"List class"

	def __init__(self):
		"initialize the list"
		self.stack = [];
		self.last_sum = 0;
		self.last_num = 0;

	def push(self, num):
		self.stack.append(num);

	def pop(self, num):
		return self.stack.pop();

	def length(self):
		return len(self.stack);


triangle      = List();
divisible_for = 0;

while True:
	triangle.last_num = triangle.last_num + 1;
	triangle.last_sum = triangle.last_sum + triangle.last_num;
	# triangle.push(triangle.last_num);

	# sys.stdout.write(str(triangle.last_sum) + " ");

	for i in xrange(1,triangle.last_sum,1):
		if (triangle.last_num % i) == 0:
			divisible_for = divisible_for + 1;

	# print "has " + str(divisible_for) + " divisors"
		
	if divisible_for >= 500:
		break;

	divisible_for = 0;
