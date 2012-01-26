/* for this problem just a little bit of logic
 * 1-19        - one word
 * x % 10 == 0 - one word (twenty, fourty...)
 * 101-119     - 4 words (one hundred and one)
 * 121-999     - 5 words (one hundred and twenty-one)
 */

#include <stdio.h>
#include <string.h>

#define ONE 		"one"
#define TWO 		"two"
#define THREE 		"three"
#define FOUR 		"four"
#define FIVE 		"five"
#define SIX  		"six"
#define SEVEN 		"seven"
#define EIGHT 		"eight"
#define NINE 		"nine"

#define TEN 		"ten"
#define ELEVEN 		"eleven"
#define TWELVE 		"twelve"
#define THIRTEEN 	"thirteen"
#define FOURTEEN 	"fourteen"
#define FIVETEEN	"fiveteen"
#define SIXTEEN		"sixteen"
#define SEVENTEEN	"seventeen"
#define EIGHTEEN	"eighteen"
#define NINETEEN	"nineteen"

#define TWENTY		"twenty"
#define THIRTY		"thirty"
#define FOURTY		"fourty"
#define FIFTY		"fifty"
#define SIXTY		"sixty"
#define SEVENTY		"seventy"
#define EIGHTY		"eighty"
#define NINETY		"ninety"
#define HUNDRED		"hundred"

char *units(int n)
{
	switch(n)
	{
		case 1: return ONE; ;;
		case 2: return TWO; ;;
		case 3: return THREE; ;;
		case 4: return FOUR; ;;
		case 5: return FIVE; ;;
		case 6: return SIX; ;;
		case 7: return SEVEN; ;;
		case 8: return EIGHT; ;;
		case 9: return NINE; ;;
		case 10: return TEN; ;;
		case 11: return ELEVEN; ;;
		case 12: return TWELVE; ;;
		case 13: return THIRTEEN; ;;
		case 14: return FOURTEEN; ;;
		case 15: return FIVETEEN; ;;
		case 16: return SIXTEEN; ;;
		case 17: return SEVENTEEN; ;;
		case 18: return EIGHTEEN; ;;
		case 19: return NINETEEN; ;;
		case 20: return TWENTY; ;;
		case 30: return THIRTY; ;;
		case 40: return FOURTY; ;;
		case 50: return FIFTY; ;;
		case 60: return SIXTY; ;;
		case 70: return SEVENTY; ;;
		case 80: return EIGHTY; ;;
		case 90: return NINETY; ;;

		case 0: return "";
	}
}

void foo(int n)
{
	char number_string[3];
	sprintf(number_string, "%d", n);

	if (n <= 20)
	{
		printf("%s\n", units(n));
		return;
	}

	if (n % 10)
	{
		if (n < 100)
		{
			if (n > 20 && n <= 29)
			{
				printf("%s-", units(20));
				printf("%s\n", units(n - 20));
			}
		}

		if (n > 100 && n < 200)
		{
			printf("one hundred ");

			int decimal = 100 - n;
			if (decimal > 0)
			{
				printf("and ");
				units(100 - n);
			}
		}
	}
}

int main(int argc, const char *argv[])
{
    int i;
    for (i=1; i<=1000; i++)
    {
           foo(i); 
    }
    return 0;
}





