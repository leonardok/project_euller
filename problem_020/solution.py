#!/bin/python
import sys

def fac(n):
	if n == 1:
		return 1
	
	return n * fac(n-1)


def main():
	sys.setrecursionlimit(2000)
	fact_str = str(fac(100))

	digit_sum = 0
	for i in range(len(fact_str)):
		digit_sum += int(fact_str[i])
	print digit_sum

if __name__ == "__main__":
	main()
