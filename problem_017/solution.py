#!/bin/python

units = ['one' , 'two' , 'three' , 'four' , 'five' , 'six' , 'seven' , 'eight' , 'nine']
first_dezenes = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
dezenes = ['-', '-', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
hundreds = ['-', 'onehundred', 'twohundred', 'threehundred', 'fourhundred', 'fivehundred', 'sixhundred', 'sevenhundred', 'eighthundred', 'ninehundred']
thousands = 'onethousand'

word_string = ''
for i in range(1001):
	#if i < 400: continue
	#if i > 420: continue
	#if i != 342: continue
	if i == 0: continue
	if i < 10:
		word_string += units[i-1]
	elif i < 20:
		word_string += first_dezenes[i-10]
	elif i < 100:
		dezene = i/10
		unit_index = i - (dezene * 10)
		word_string += dezenes[dezene]
		if unit_index != 0:
			word_string += units[unit_index - 1]
	elif i < 1000:
		centene = i/100
		dezene = (i-(centene*100))/10
		unit_index = i - (centene*100 + dezene*10)
		print str(i) +' '+ str(centene) + str(dezene) + str(unit_index)
		word_string += hundreds[centene]
		if dezene == 1:
			word_string += 'and'
			word_string += first_dezenes[unit_index]
		elif dezene > 1:
			word_string += 'and'
			word_string += dezenes[dezene]
			if unit_index != 0:
				word_string += units[unit_index - 1]
		elif unit_index > 0: 
			word_string += 'and'
			word_string += units[unit_index - 1]
	elif i == 1000: word_string += 'onethousand'


print word_string
print len(word_string)
