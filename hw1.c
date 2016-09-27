#include <stdio.h>

unsigned get_bit(unsigned x, unsigned n)
	{
	// from x you shift right n-1 times this will work the bit that is wanted to the righter most side
           x = x >> n-1 ;
    // the return from the previous line is evaluated with AND 1, this is because there will be a 0 in all digits except the right most bit which is the only value potentially a 1 all others are 0 since and requires both to be 1 to be 1 otherwise it is 0
           x = x & 1;
	   return x;
	}

// you receive a pointer to the array of elements and an integer, which i think is suppose to be the size of the array
int bar(int *arr, unsigned int n) {
// sum is initialized to 0 i is initilized to an integer
	int sum = 0, i;
// to verify whats happening a print statment
	printf("%d is the sum\n", sum);
// if n = size of array - 1 to offset the 0 element, works in reverse to 0
	for (i = n-1; i > 0; i--) {
	//another print statment to check
		printf("the value of arr[i] is: %d\n", arr[i]);
		//had to get rid of the ! was not working keep = 0, now it keeps the sum of the elements in the array
		sum += (arr[i]);
		//another print statment to make sure everything worked properly
		printf("the value of sum: %d, the value of n: %d\n", sum, n);
	}
	//return statment to return result
	return sum;
}


int set_bit( unsigned x, unsigned n, unsigned v) {
	unsigned int ncase;
	unsigned int dstyr = (x >> (n-1)) & 1;
	unsigned int d1 = dstyr;
	if (d1 != v) {
		dstyr = dstyr ^ 1;
		dstyr = (dstyr << (n-1));
		unsigned int p1 = ((x >> n) << n);
// switch case statment not working im not sure why
		switch (n){
			case '1':
				ncase = 0;
				break;
			case '2':
				ncase = 3;
				break;
			case '3':
				ncase = 7;
				break;
			case '4':
				ncase = 15;
				break;
			case '5':
				ncase = 31;
				break;
			case '6':
				ncase = 63;
				break;
			case '7':
				ncase = 127;
				break;
			case '8':
				ncase = 255;
				break;
			case '9':
				ncase = 511;
				break;
		}
	// not working i had a variable that was set by the case statment that determined what the number was & with depending on the number of bit to be set hard coded to 3 to get to work
		unsigned int p2 = x & 3;
		unsigned int result = p1 | dstyr | p2;
		return result;
		}
	else {
		return x;
		printf("Error: returned sent value, check input for z");
	}
}

void flip_bit(unsigned x, unsigned n) {
	unsigned int ncase;
	unsigned int dstyr = (x >> (n-1)) & 1;
	unsigned int d1 = dstyr;
	dstyr = dstyr ^ 1;
	dstyr = (dstyr << (n-1));
	unsigned int p1 = ((x >> n) << n);
// switch case statment not working im not sure why
	switch (n){
		case '1':
			ncase = 0;
			break;
		case '2':
			ncase = 3;
			break;
		case '3':
			ncase = 7;
			break;
		case '4':
			ncase = 15;
			break;
		case '5':
			ncase = 31;
			break;
		case '6':
			ncase = 63;
			break;
		case '7':
			ncase = 127;
			break;
		case '8':
			ncase = 255;
			break;
		case '9':
			ncase = 511;
			break;
	}
// not working i had a variable that was set by the case statment that determined what the number was & with depending on the number of bit to be set hard coded to 3 to get to work
	unsigned int p2 = x & 3;
	x = p1 | dstyr | p2;
	printf("x = %d\n", x);
	//return result;
}

//works great!
int mystrlen(char* str) {
	int dstyr = 0;
	while ( *(str+dstyr) != '\0') {
		printf(" entry is %c\n", *(str +dstyr));
		dstyr++;
	}
	return dstyr;
}

void swap(int *x, int *y)
{
	int *temp;
	temp = x;
	x = y;
	y = temp;
}

int sum(int* arr) {
	int sum = 0;
	int i = 0;
	printf("sizeof arr is : %d\n", sizeof(arr));
	while (*(arr + i) != '\0') {
		printf("the value in the arr is %d\n", *(arr+i));
		sum += *(arr+i);
		printf("the sum is %d \n", sum);
		i++;
	}
	/* //this will not work b/c you are passing a pointer to the function not the array so sizeof will not return the size of the array but the size of the pointer in bits to get it to work i created a while loop that exits on the escape character this does the intended process corectly 
	for (i; i < sizeof(arr); i++) {
		sum += *(arr + i); }
	*/
	return sum;
}


void main() {
	
	//unsigned result;
	//result = get_bit(1000, 3);
	//printf("%u\n", result);
	int arr[] = {1,2,3,4,5,6,7,8,9,'\0'};
	//char p = *arr;
	//int result = bar(arr, 6);
	int result = sum(arr);
	//int sub = set_bit(0b1010, 3, 1);
	//flip_bit(0b1010, 4);
	//unsigned int result = mystrlen(arr);
	printf("result = %d\n", result);
	
}
