#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_SIZE 10
typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
	// do nothing -- no free buffer item
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
	// do nothing -- nothing to consume
}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}
int pthread_create(
	pthread_t *thread,
	const pthread_attr_t *attr,
	void *(*start_routine) (void *),
	void *arg );

void *threadFunction(void *param) {
	// do something in the background
	item i1,i2,i3;
	//////
	i1.type= '0';
	i1.amount = 1111;
	i1.unit= '1';
	
	i2.type= '1';
	i2.amount = 5;
	i2.unit= '0';


	i3.type= '1';
	i3.amount = 33333;
	i3.unit= '0';

	///////
	printf("Type: %c Amount: %d Unit: %c \n", i1.type, i1.amount, i1.unit);
 	printf("Type: %c Amount: %d Unit: %c \n", i2.type, i2.amount, i2.unit);

	produce(&i1);
 	printf("Item 1: %c, %d, %c\tfirst = %d, last=%d\n\n", i1.type, i1.amount, i1.unit, first, last);
 	produce(&i2);
 	printf("Item 2: %c, %d, %c\tfirst = %d, last=%d\n\n", i2.type, i2.amount, i2.unit, first, last);
	produce(&i3);
 	printf("Item 3: %c, %d, %c\tfirst = %d, last=%d\n\n", i3.type, i3.amount, i3.unit, first, last);
	
}

void *threadFunction2(void *param) {
	consume();
	printf("Consumed item 1: first = %d, last=%d\n\n", first, last);
	consume();
	printf("Consumed item 2: first = %d, last=%d\n\n", first, last);
}

int main(){
	
	pthread_t tid;
	pthread_create(&tid,NULL,threadFunction,NULL);
	pthread_join(tid, NULL);

	
	pthread_t tid2;
	pthread_create(&tid2,NULL,threadFunction2,NULL);
	pthread_join(tid2, NULL);
	
	return 0;




}
