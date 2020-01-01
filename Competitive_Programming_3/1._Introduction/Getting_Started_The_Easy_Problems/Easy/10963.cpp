//2019-12-32 The Swallowing Ground by Mutska
//Need for check with cin... subtle errors >:c
#include <cstdio>

int main(){

	int T, N, y1,y2, gap;
	bool result;

	scanf("%d", &T);

	while(T--){

		scanf("%d", &N);
		scanf("%d %d", &y1, &y2);
		gap = y1 - y2;
		N--;
		result = true;
		while(N--){

			scanf("%d %d", &y1, &y2);
			if(gap != (y1 - y2))
				result = false;
		}
		if(result)
			printf("yes\n");
		else
			printf("no\n");

		if(T)
			printf("\n");
		
	}

	return 0;
}
