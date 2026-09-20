#include "R.h"

#include <iostream>
#include <cstdlib>  // Для rand(), srand()
#include <ctime>    // Для time()
#include <string>
using namespace std;
int random_cow(){
	srand(time(NULL));
	int num = rand()%9000 + 1000;
	while((num%10 == num/10%10) || (num%10 == num/100%10) || (num%10 == num/1000%10) || (num/10%10 == num/100%10) || (num/10%10 == num/1000%10) || (num/100%10 == num/1000%10)){
		num = rand()%9000 + 1000;
	}
	return num;
}
int prov(int tvoe, int random_num_cow){
	string stvoe = to_string(tvoe);
	string snetvoe = to_string(random_num_cow);
	int bik = 0;
	int cow = 0;
	for(int i=0; i<4; i++){
		if(stvoe[i]==snetvoe[i]){bik+=1;}
		else if((stvoe[i]==snetvoe[(i+1)%4]) || (stvoe[i]==snetvoe[(i+2)%4]) || (stvoe[i]==snetvoe[(i+3)%4])){
			cow+=1;
		}
	}
	if(bik==4){cout << "YOU WIN!!!"<<endl;;return 0;}
	else{
		if(bik!=0){cout<<"bik:"<<bik;}
		if(cow!=0){cout<<" cow:"<<cow;}
		cout<<endl;
	}
	return 1;
}
void inp_num(){
	int num;
	int cow_num = random_cow();
	int flag = 1;
	do{
		cin >> num;
		if(num>9999 || num<1000 || (num%10 == num/10%10) || (num%10 == num/100%10) || (num%10 == num/1000%10) || (num/10%10 == num/100%10) || (num/10%10 == num/1000%10) || (num/100%10 == num/1000%10)){cout << "Некоректная форма" << endl;}	
		else{cout << cow_num << " ";
		flag = prov(num, cow_num);}
	}while(flag);
}