#include<iostream>
#include<string>

bool allCharsUnique(char* in){//All input expected ASCII
//O(n) runtime
	bool alphabet[256];	//Doesn't need delete: stack clears upon function end

	for(int i=0; i<256; i++)	//ReZero
		alphabet[i]=false;


	for(; *in; in++)
		if(alphabet[(int)*in])
                	return false;
		else
			alphabet[(int)*in] = true;
	return true;
}


bool checkPermutation(char* inA, char* inB){
//Letter histograms equal:return true? return false;
//O(n)

//ASSUMPTION: one-to-one permutation expected
//'cat' is not a permutation of 'racetrack'

	int histA[256], histB[256];
	for(int a = 0; a < 256; a++){
		histA[a] = 0; histB[a] = 0;
	}

	for(char* ap = inA; *ap != '\0'; ap++)
		histA[(int) *ap]++;
	for(char* bp = inA; *bp != '\0'; bp++)
		histB[(int) *bp]++;

	for(int a = 0; a < 256; a++){
		if(histA[a] != histB[a]) return false;
	}


	return true;

}

char* urlify(char* in, int argc){
	//O(n) complexity
	return toRet;
}

bool palindromePermutationable(char* in){
				//Question can effectively be rephrased to "can I reorganise a plaindrome?"
				//Yes, if only 1 char or less is odd in a histogram. Histogram simplified to bools
	int histIn[26];
	for(int a = 0; a < 26; a++) histIn[a] = 0; //ReZero

	for(char* cnt = in; *cnt != '\0'; cnt++)
		histIn[*cnt - 97] += 1;
	int odds = 0;

	for(int a = 0; a < 26; a++)
		if(histIn[a] % 2 == 1)
			odds++;

	if(odds <= 1)
		return true;
	return false;

}
bool oboTester(char* inA, char* inB){//--------To finish, need to work on end dimensions
//	O(n)
	int lenA = 0, lenB = 0, dev = 0, firstDev = 0, lastDev = 0;
	for(char* cmp = inA; *cmp != '\0'; cmp++) lenA++;
	for(char* cmp = inB; *cmp != '\0'; cmp++) lenB++;
	if(lenA == lenB){
		for(int a = 0; a < lenA; a++)
			if(*(inA+a) != *(inB+a))
				dev++;
		if(dev>1) return false;
		return true;
	}
	if(lenA - lenB > 1 || lenB - lenA > 1) return false; //over 2 insert/deletes
	dev = -1;
	for(int a = 0; a < (lenA > lenB? lenB:lenA) && dev == -1; a++){
		if(dev == -1 && *(inA+a) != *(inB+a)){
			dev = a;
		}
	}
	for(int a = dev;*(inA + a)!= '\0' ; a++ ){//for shorter one
		if(lenA > lenB){
			if(*(inA + a + 1) != *(inB+a))
				return false;
		}
                if(lenA < lenB){ 
                        if(*(inA + a) != *(inB+a+1))
                                return false;
                }
	}
	std::cout << dev << '\n';
	return true;
}

char* compressor(char* in){ //------To finish, doesn't work on compressing single char partitions
	int len = 0;
	for(char* a = in; *a != '\0'; a++) len++;
	char* toRet = new char[len];
//	std::cout << "Len:" << len << std::endl;
	int parse = 1 ,combo = 1, added = 1; char cpy = *in;
	*toRet = cpy;
	while(parse < len){
		if(*(in+parse) == cpy){
			combo++;
			parse++;
		}
		else{
			*(toRet+added) = (char)(combo+48);
			added++;
			parse++;
			cpy = *(in+parse);
			combo = 1;
			*(toRet+added) = cpy;
			added++;
		}
	}
	*(toRet+added) = (char)(combo+48);
	return toRet;

}

void matrixRotate(int in[3][3], int n){ //--------Unknown if possible: C++ unknown size multidim arrs a bietch
	int tmp;
	for(int a = 1; a < n; a++)
		for(int b = 0; b < n; b++)
			if(b < a){
				tmp = in[b][a];
				in[b][a] = in[a][b];
				in[a][b] = tmp;
			}

}

void zeroMatrix(int in[3][3], int n){
	int rZ[] = {0,0,0};
	int cZ[] = {0,0,0};


	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(in[i][j] == 0){
				rZ[i] = 1;
				cZ[i] = 1;
			}

	for(int i = 0; i < n; i++)
		if(rZ[i] == 1)
			for(j= 0; j < n; j++)
				in[i][j] = 0;

        for(int i = 0; i < n; i++)
                if(cZ[i] == 1)
                        for(j= 0; j < n; j++)
                                in[j][i] = 0;




}



int main(int argc, char** argv){
//	std::cout << (int)'a' << std::endl; //Remnant of debugging. Answer 97
//	std::cout << "ASCII of 0:\t" << (char)(48) << '\n';

//	std::cout 	<< "Ex1:\nTest of dopamine\t" 	<< allCharsUnique("dopamine")<<std::endl
//			<< "Test of testosterone\t"	<< allCharsUnique("testosterone")<<std::endl;

//	std::cout	<< "Ex2:\nTest of abc cab\t" 	<< checkPermutation("abc", "cab") << std::endl
//			<< "Test of stick meat\t"	<< checkPermutation("stick", "meat") <<std::endl;

//	char* result = urlify("I beat Meat",12);
//	std::cout	<< "Ex3:\nTest of I beat Meat\t" <<result << std::endl;
//	delete []result;

//	std::cout	<< "Ex4:\nTest of tactcoa\t" 	<< palindromePermutationable("tactcoa") << '\n'
//			<< "Test of xdfgf\t" 		<< palindromePermutationable("xdfgf") << '\n';

//	std::cout 	<< "Ex5:\nTest of abc abc:\t"	<< oboTester("abc","abc") << '\n' //---------NOT FULLY DONE
//			<< "Test of adc abc:\t"		<< oboTester("adc", "abc")<< '\n'
//			<< "Test of adb abc:\t"		<< oboTester("adb", "abc")<< '\n'
//			<< "Test of adbgcc abc:\t"	<< oboTester("adbgcc", "abc")<< '\n'
//			<< "Test of abdc abc:\t"		<< oboTester("abdc", "abc")<< '\n'
//			<< "Test of adb abdc:\t"		<< oboTester("adb", "abdc")<< '\n';


//	std::cout << "Compressing aaagggddfff:\t" << compressor("aaagggddfff") << '\n'; //-----------NOT FULLY DONE


	int matr[3][3] = {	{0,1,2},
				{3,4,5},
				{6,7,8}};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			std::cout << matr[i][j] << ' ';
		std::cout << '\n';
	}

//	matrixRotate(matr, 3);	//-------------NOT FULLY DONE, maybe? SEE 1ST COMMENT




        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++)
                        std::cout << matr[i][j] << ' ';
                std::cout << '\n';
        }
*/

	return 0;
}
