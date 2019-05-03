#ifndef ZQUEUE_H_
#define ZQUEUE_H_

#include <stdint.h>
#include <stdbool.h>

//队列占用256，实际可用长度255
//利用uint8_t溢出实现环形队列
#define ZQ_MAX 255
typedef uint8_t item;

typedef struct
{
	uint8_t head;
	uint8_t rear;
	item data[ZQ_MAX + 1];
}zqueue;

void zq_init(zqueue* q);
void zq_enqueue(zqueue* q, item x);
item zq_dequeue(zqueue* q);
bool zq_empty(const zqueue* q);
bool zq_full(const zqueue* q);
uint8_t zq_size(const zqueue* q);

#endif
