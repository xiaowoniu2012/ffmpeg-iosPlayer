//
//  zz_queue.h
//  testFFmpeg
//
//  Created by smart on 2017/5/23.
//  Copyright © 2017年 XiaoWoNiu2014. All rights reserved.
//

#ifndef zz_queue_h
#define zz_queue_h

#include <stdio.h>

typedef void (zz_node_free_callback)(void *);

typedef struct zz_node {
    void *data;
    struct zz_node *pre,*next;
}zz_node;

typedef struct zz_queue {
    pthread_mutex_t lock;
    zz_node *first,*last;
    zz_node_free_callback *callbackFunc;
    int size;
    int capacity;
}zz_queue;


zz_queue * zz_queue_alloc(int capacity,zz_node_free_callback *callback);

void zz_queue_put(zz_queue *queue,void *data);
void * zz_queue_pop(zz_queue *quque);
void zz_quque_free(zz_queue *quque);


#endif /* zz_queue_h */