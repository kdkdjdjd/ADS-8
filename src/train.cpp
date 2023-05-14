// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCage(bool light) {
  Cage* van = new Cage();
  van->light = light;
  if (first == nullptr) {
    first = van;
    first->next = van;
    first->prev = van;
  } else {
    van->next = first;
    van->prev = first->prev;
    (first->prev)->next = van;
    first->prev = van;
  }
}

int Train::getLength() {
  int length = 0;
  first->light = true;
  while (first->light) {
    length = 0;
    Cage* cur_van = first->next;
    countOp++;
    length++;
    while (!cur_van->light) {
      countOp++;
      length++;
      cur_van = cur_van->next;
    }
    cur_van->light = false;
  }
  countOp *= 2;
  return length;
}

int Train::getOpCount() {
  return countOp;
}
