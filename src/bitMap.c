//
// Created by puzankova 02.06.18
//
#include "bitMap.h"

void setBitByNumber(int *array, int len, int bit, int position) {
    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    if (position < 0) {
        printf("Error: position has to be greater then zero\n");
    } else if (array == NULL) {
        printf("Error: array is NULL\n");
    } else if (position > (len - 1)) {
        printf("Error: position has to be less then length\n");
    } else {
        setBitByAddress((array + position), bit);
    }
}


int getBitByNumber(int *array, int len, int position) {
    // this function returns position's bit from the array

    if (position < 0) {
        printf("Error: position has to be greater then zero\n");
        return INT_MIN;
    } else if (array == NULL) {
        printf("Error: array is NULL\n");
        return INT_MIN;
    } else if (position > (len - 1)) {
        printf("Error: position has to be less then length\n");
        return INT_MIN;
    } else {
        return getBitByAddress(array + position);
    }
}

void setBitByAddress(void *position, int bit) {
    // position - pointer to the bit to change
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit by memory address to 'bit'
    if (position == NULL) {
        printf("Error: Position is NULL\n");

    } else if (bit == 0 || bit == 1) {
        *((int *) position) = bit;
    } else {
        printf("Error: Bit has to be 1 or 0\n");
    }

}

int getBitByAddress(void *position) {
    // this function returns first bit by memory address 'position'

    if (position == NULL) {
        printf("Error: Position is NULL\n");
        return INT_MIN;
    }
    int to_return = *((int *) position);

    if (to_return != 0 && to_return != 1) {
        printf("Error: This is not a bitmap\n");
        return INT_MIN;
    }
    return to_return;
}