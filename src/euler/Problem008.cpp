#include <iostream>
#include <string>
#include <vector>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../lib/converter/convert.h"

using namespace std;

class Problem008 : public EulerProblem<long long>
{
private:
	string strDigits;

	long long run(const int ADJACENT)
	{
		int curIndex = 0;
		int digitLen = strDigits.length();
		int lastIndex = digitLen - 1;
		int endIndex = curIndex + ADJACENT;

		bool zeroFound;
		long long product;
		int *buffer;

		int *maxBuffer;
		int maxBeginIndex;
		int maxEndIndex;

		long long maxProduct = 0;

		if (ADJACENT <= 0 || ADJACENT > digitLen)
		{
			return 0;
		}

		while(endIndex <= lastIndex)
		{
			zeroFound = false;
			buffer = new int[ADJACENT];

			for (int i = 0; i < ADJACENT; ++i)
			{
				int curAdjIndex = curIndex + i;
				char curChar = strDigits[curAdjIndex];
				int curValue = Convert<int>::StringToNumber(string(1, curChar));

				if (curValue == 0)
				{
					zeroFound = true;
					break;
				}

				buffer[i] = curValue;
			}

			if (!zeroFound)
			{
				product = multiply(buffer, ADJACENT);
			
				if (product > maxProduct)
				{
					maxProduct = product;
					maxBuffer = copyBuffer(buffer, ADJACENT);
					maxBeginIndex = curIndex;
					maxEndIndex = endIndex;
				}
			}

			delete[] buffer;

			curIndex++;
			endIndex = curIndex + ADJACENT;
		}

		output("Begin Index: ");
		output(Convert<int>::NumberToString(maxBeginIndex));
		output(" -> ");

		for (int i = 0; i < ADJACENT; ++i)
		{
			output(Convert<int>::NumberToString(maxBuffer[i]));
			output("");
		}

		output(" = ");

		return maxProduct;
	}

	long long multiply(int *array, int size)
	{
		long long mult = 1;

		for (int i = 0; i < size; ++i)
		{
			mult *= (long long) array[i];
		}

		return mult;
	}

	int *copyBuffer(int *buffer, const int size)
	{
		int *newBuffer = new int[size];

		for (int i = 0; i < size; ++i)
		{
			newBuffer[i] = buffer[i];
		}

		return newBuffer;
	}

protected:
	long long example()
	{
		const int ADJACENT = 4;

		return run(ADJACENT);
	}

	long long solve()
	{
		const int ADJACENT = 13;

		return run(ADJACENT);
	}
	
public:
	Problem008(ILogService *logSrv) : EulerProblem(
		logSrv,
		8, 
		"Problem 008", 
		"Largest product in a series", 
		"The four adjacent digits in the 1000-digit number \n"
		"that have the greatest product are 9 × 9 × 8 × 9 = 5832. \n\n"
		"  73167176531330624919225119674426574742355349194934 \n"
		"  96983520312774506326239578318016984801869478851843 \n"
		"  85861560789112949495459501737958331952853208805511 \n"
		"  12540698747158523863050715693290963295227443043557 \n"
		"  66896648950445244523161731856403098711121722383113 \n"
		"  62229893423380308135336276614282806444486645238749 \n"
		"  30358907296290491560440772390713810515859307960866 \n"
		"  70172427121883998797908792274921901699720888093776 \n"
		"  65727333001053367881220235421809751254540594752243 \n"
		"  52584907711670556013604839586446706324415722155397 \n"
		"  53697817977846174064955149290862569321978468622482 \n"
		"  83972241375657056057490261407972968652414535100474 \n"
		"  82166370484403199890008895243450658541227588666881 \n"
		"  16427171479924442928230863465674813919123162824586 \n"
		"  17866458359124566529476545682848912883142607690042 \n"
		"  24219022671055626321111109370544217506941658960408 \n"
		"  07198403850962455444362981230987879927244284909188 \n"
		"  84580156166097919133875499200524063689912560717606 \n"
		"  05886116467109405077541002256983155200055935729725 \n"
		"  71636269561882670428252483600823257530420752963450 \n\n"
		"Find the thirteen adjacent digits in the 1000-digit number \n"
		"that have the greatest product. What is the value of this product?")
	{
		strDigits = "73167176531330624919225119674426574742355349194934"
					"96983520312774506326239578318016984801869478851843"
					"85861560789112949495459501737958331952853208805511"
					"12540698747158523863050715693290963295227443043557"
					"66896648950445244523161731856403098711121722383113"
					"62229893423380308135336276614282806444486645238749"
					"30358907296290491560440772390713810515859307960866"
					"70172427121883998797908792274921901699720888093776"
					"65727333001053367881220235421809751254540594752243"
					"52584907711670556013604839586446706324415722155397"
					"53697817977846174064955149290862569321978468622482"
					"83972241375657056057490261407972968652414535100474"
					"82166370484403199890008895243450658541227588666881"
					"16427171479924442928230863465674813919123162824586"
					"17866458359124566529476545682848912883142607690042"
					"24219022671055626321111109370544217506941658960408"
					"07198403850962455444362981230987879927244284909188"
					"84580156166097919133875499200524063689912560717606"
					"05886116467109405077541002256983155200055935729725"
					"71636269561882670428252483600823257530420752963450";


		solved = true;
		setCorrectAnswer(23514624000);

		showExample = true;
		showOutput = false;
	}

	~Problem008()
	{
		
	}

};