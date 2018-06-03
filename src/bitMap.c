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

    if (position >= 0) {
        setBitByAddress((array + position), bit);
    } else {
        printf("Error: position has to be greater then zero");
    }

}

int getBitByNumber(int *array, int position) {
    // this function returns position's bit from the array

    /* YOUR CODE */
    //TODO: consider including length of the array
    if (position >= 0) {
        return *(array + position);
    } else {
        printf("Error: position has to be greater then zero");
        return -INFINITY;
    }
}

void setBitByAddress(void *position, int bit) {
    // position - pointer to the bit to change
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit by memory address to 'bit'

    /* YOUR CODE */
    if (bit == 0 || bit == 1) {
        *((int *) position) = bit;
    } else {
        printf("Error: Bit has to be 1 or 0");
    }

}

int getBitByAddress(void *position) {
    // this function returns first bit by memory address 'position'

    return *((int *) position);
}