// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxPerem = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxPerem) {
            maxPerem = num;
        }
    }
    return maxPerem;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 0;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    return length + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int BNum = lbound;
  unsigned int mxLength = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int currentLen = collatzLen(i);
    if (currentLen > mxLength) {
      mxLength = currentLen;
      BNum = i;
    }
  }
  if (maxlen != nullptr) {
    *maxlen = mxLength;
  }
  return BNum;
}
