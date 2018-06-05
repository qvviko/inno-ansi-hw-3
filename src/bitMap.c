//
// Created by puzankova 02.06.18
//
#include "bitMap.h"

void setBitByNumber(int *array, int bit, int position, int ar_pos) {
    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    if (position < 0 && ar_pos < 0) {
        printf("Error: position has to be greater then zero\n");
    } else if (position >= (sizeof(int) * 8)) {
        printf("Error: position is to high\n");
    } else if (bit != 0 && bit != 1) {
        printf("Error: Bit has to be 1 or 0\n");
    } else if (array == NULL) {
        printf("Error: array is NULL\n");
    } else {
        unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
        mask = mask >> position;
        int *to_change = (array + ar_pos);
        if (bit == 1) {
            *to_change = *to_change | mask;
        } else {
            *to_change = *to_change & (~mask);
        }
    }
}


int getBitByNumber(int *array, int position, int ar_pos) {
    // this function returns position's bit from the array

    if (position < 0 && ar_pos < 0) {
        printf("Error: position has to be greater then zero\n");
        return INT_MIN;
    } else if (position >= (sizeof(int) * 8)) {
        printf("Error: position is to high\n");
        return INT_MIN;
    } else if (array == NULL) {
        printf("Error: array is NULL\n");
        return INT_MIN;
    } else {
        unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
        mask = mask >> position;
        unsigned int to_return = (*array + ar_pos) & mask;
        if (to_return == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

void setBitByAddress(void *position, int bit) {
    // position - pointer to the bit to change
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit by memory address to 'bit'
    if (position == NULL) {
        printf("Error: Position is NULL\n");
    } else if (bit != 0 && bit != 1) {
        printf("Error: Bit has to be 1 or 0\n");
    } else {
        unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
        unsigned int *to_change = (unsigned int *) position;
        if (bit == 0) {
            *to_change = *to_change & (~mask);
        } else {
            *to_change = *to_change | mask;
        }
    }

}

int getBitByAddress(void *position) {
    // this function returns first bit by memory address 'position'

    if (position == NULL) {
        printf("Error: Position is NULL\n");
        return INT_MIN;
    }
    unsigned int to_return = *((unsigned int *) position) >> (sizeof(unsigned int) * 8 - 1);
    return to_return;
}