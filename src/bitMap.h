//
// Created by artem on 02.06.2018.
//

#ifndef __BITMAP_H_
#define __BITMAP_H_

#include <stdio.h>
#include <limits.h>

void setBitByNumber(int *array, int bit, int position, int ar_pos);

int getBitByNumber(int *array, int position, int ar_pos);

void setBitByAddress(void *position, int bit);

int getBitByAddress(void *position);

#endif //__BITMAP_H_
