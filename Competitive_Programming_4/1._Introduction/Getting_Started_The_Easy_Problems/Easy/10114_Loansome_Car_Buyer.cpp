//2019-12-31 Loansome Car Buyer by Mutska

#include <iostream>

using namespace std;

int main(){

	int loan_months, depreciation;
	long double down_payment, loan, car_price, payment;
	int month;
	long double percentage;
	long double record[101];

	while(scanf("%d %Lg %Lg %d", &loan_months, &down_payment, &loan, &depreciation) != EOF){
		if(loan_months < 0)
			break;
		int count = 0;
		car_price = down_payment + loan;	
		payment = loan / loan_months;

		while(depreciation--){
			scanf("%d %Lg", &month, &percentage);
			for (int i = month; i < 101; i++)
				record[i] = percentage;

		}
		car_price -= (car_price * record[0]);
		while (car_price < loan){
			count++;
			car_price -= (car_price*record[count]);
			loan -= payment;

		}

		if(count == 1)	
			printf("%d month\n", count);
		else
			printf("%d months\n", count);



	}


	return  0;
}
