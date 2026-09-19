#include <cstdlib>  // Для rand(), srand()
#include <ctime>    // Для time()
int random_cow(){
	srand(time(NULL));
	int num = rand()%9000 + 1000;
	while((num%10 == num/10%10) || (num%10 == num/100%10) || (num%10 == num/1000%10) || (num/10%10 == num/100%10) || (num/10%10 == num/1000%10) || (num/100%10 == num/1000%10)){
		num = rand()%9000 + 1000;
	}
	return num;
}