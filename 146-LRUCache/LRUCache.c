#include <stdio.h>
#include <stdlib.h>

typedef struct LRUNode {
	int val;
	int key;
	struct LRUNode *prev;
	struct LRUNode *next;
} LRUNode;

typedef struct {
	int size;
	int currentSize;
	LRUNode *head;
	LRUNode *tail;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
	LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
	cache->size = capacity;
	cache->currentSize = 0;
	cache->head = NULL;
	cache->tail = NULL;
	
	return cache;
}

void moveCacheToHead(LRUCache *obj, LRUNode *node) {
	if (node == NULL || node == obj->head || (node->prev == NULL && node->next == NULL)) {
		return;
	}
	
	LRUNode *prev = node->prev;
	LRUNode *next = node->next;
	prev->next = next;
	node->next = obj->head;
	obj->head->prev = node;
	obj->head = node;
	node->prev = NULL;
	if (node == obj->tail) {
		obj->tail = prev;
	} else {
		next->prev = prev;
	}
}

int lRUCacheGet(LRUCache* obj, int key) {
	if (obj->currentSize == 0 || obj->head == NULL || obj->tail == NULL) {
		return -1;
	}
	
	if (obj->head->key == key) {
		return obj->head->val;
	}
	
	if (obj->tail->key == key) {
		moveCacheToHead(obj, obj->tail);
		
		return obj->head->val;
	}
	
	LRUNode *current = obj->head;
	while (current != NULL) {
		if (current->key == key) {
			moveCacheToHead(obj, current);
			
			return obj->head->val;
		}
		current = current->next;
	}
	
	return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
	LRUNode *current = obj->head;
	while (current != NULL) {
		if (current->key == key) {
			current->val = value;
			moveCacheToHead(obj, current);
			
			return;
		}
		current = current->next;
	}
	
	if (obj->currentSize == obj->size) {
		LRUNode *tail = obj->tail;
		if (obj->size == 1) {
			obj->tail = NULL;
			obj->head = NULL;
		} else {
			tail->prev->next = NULL;
			obj->tail = tail->prev;
		}
		
		free(tail);
	}
	
	LRUNode *node = (LRUNode *)malloc(sizeof(LRUNode));
	node->val = value;
	node->key = key;
	node->prev = NULL;
	node->next = obj->head;
	if (obj->head != NULL) {
		obj->head->prev = node;
	}
	obj->head = node;
	if (obj->currentSize < obj->size) {
		obj->currentSize += 1;
	}
	
	if (obj->currentSize == 1) {
		obj->tail = obj->head;
	} else if (obj->currentSize == 2) {
		obj->tail = node->next;
	}
}

void lRUCacheFree(LRUCache* obj) {
	LRUNode *current = obj->head;
	LRUNode *prev = obj->head;
	while (current != NULL) {
		prev = current;
		current = current->next;
		free(prev);
	}
	
	free(obj);
}

void printCache(LRUCache *obj) {
	if (obj == NULL) {
		printf("Null cache!");
		
		return;
	}
	
	if (obj->currentSize == 0) {
		printf("Empty cache!");
		
		return;
	}
	
	LRUNode *node = obj->head;
	while (node != NULL) {
		printf("The key is %d, the value is %d\n", node->key, node->val);
		node = node->next;
	}
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */

int main(int argc, char *argv[]) {
	LRUCache *cache = lRUCacheCreate(1);
	lRUCachePut(cache, 1000, 1);
	lRUCachePut(cache, 2000, 2);
	lRUCachePut(cache, 3000, 3);
	int x = lRUCacheGet(cache, 3000);
	printf("Get the cache %d\n", x);
	printCache(cache);
	lRUCachePut(cache, 3000, 4);
	printCache(cache);
	x = lRUCacheGet(cache, 1000);
	printf("Get the cache %d\n", x);
	int y = lRUCacheGet(cache, 3000);
	printf("Get the cache %d\n", y);
	
	return 0;
}