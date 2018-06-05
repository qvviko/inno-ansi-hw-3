//
// Created by puzankova 02.06.18
//
#include "bitMap.h"

void setBitByNumber(int *array, int bit, int position) {
    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    if (position < 0) {
        printf("Error: position has to be greater then zero\n");
    } else if (position > (sizeof(int) * 8)) {
        printf("Error: position is to high\n");
    } else if (bit != 0 && bit != 1) {
        printf("Error: Bit has to be 1 or 0\n");
    } else if (array == NULL) {
        printf("Error: array is NULL\n");
    } else {
        unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
        mask = mask >> position;
        if (bit == 1) {
            *array = *array | mask;
        } else {
            *array = *array & (~mask);
        }
    }
}


int getBitByNumber(int *array, int position) {
    // this function returns position's bit from the array

    if (position < 0) {
        printf("Error: position has to be greater then zero\n");
        return INT_MIN;
    } else if (position > (sizeof(int) * 8)) {
        printf("Error: position is to high\n");
        return INT_MIN;
    } else if (array == NULL) {
        printf("Error: array is NULL\n");
        return INT_MIN;
    } else {
        unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
        mask = mask >> position;
        unsigned int to_return = (*array) & mask;
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