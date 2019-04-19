#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int a = 0;

void *imprimir_letra(void *arg) {
	
	switch(a) {
		case 0:
			printf("A\n");
			a++;
			break;
		case 1:
			printf("B\n");
			a++;
			break;
		case 2:
			printf("C\n");
			a++;
			break;
	}
}

int main() {
	pthread_t thread_id[3];
	for (int i = 0; i < 3; i++) {
		pthread_create(&thread_id[i], NULL, imprimir_letra, NULL);
	}
	pthread_exit(NULL);
	return 0;
}