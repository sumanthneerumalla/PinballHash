//File:    Pinball.cpp
// Project: CMSC 202 Project 5, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    12/4/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the implementation of the Pinball class

#ifndef PINBALL_CPP_
#define PINBALL_CPP_

#include <iostream>
#include <string.h>
#include <cstring>
#include <stdexcept>
#include <string.h>
#include "Pinball.h"

#endif
Pinball::Pinball(int n) {
  m_capacity = n;
  m_size = 0; //start off size of hash table at 0
  m_degree = 7; //configuration given by professor
  m_ejectLimit = 20; //configuration given by professor

  //create arrays
  H = new char *[m_capacity];
  for (int i = 0; i < m_capacity; ++i) {
    H[i] = NULL;
  }
  int myCounter = 0;

  for (int i = 0; i < m_capacity; ++i) {
    if (H[i] == NULL) {
      myCounter++;
    }
  }
  cout << "number of nulls is: " << myCounter << endl;
  cout << "mcapacity is : " << m_capacity << endl;

  offsets = new unsigned int[m_degree - 1];

  for (int i = 0; i < m_degree - 1; ++i) {
    offsets[i] = rand() % m_capacity;
    cout << offsets[i] << endl;
  }


  //these statistics are initialized to 0, and adjusted everytime insert() runs
  numPrimarySlots = 0;
  avgPrimaryHits = 0;
  maxPrimaryHits = 0;
  totalEjections = 0;
  maxEjections = 0;

  memset(H, '\0', n * sizeof(char *));
//  char* temp = myStrdup("hello");
//  string tempSTr = temp;
//  cout<< tempSTr<<endl;

}
Pinball::~Pinball() {
  for (int i = 0; i < m_capacity; ++i) {
    free(H[i]);
  }
  delete[] H;
  delete[] offsets;
}

void Pinball::insert(const char *str) {
  if ((m_size == m_capacity)) {
    throw PinballHashFull("*** Exception: Hash map full!!");
  }
  if (find(str) != -1) {
    //as long as the string hasn't already been stored
    int primarySlotIndex = hashCode(str);

  }

  m_size++;

}

int Pinball::find(const char *str) {
  for (int i = 0; i < m_capacity; ++i) {
    if (strcmp(H[i], str) == 0) {
      return i;
    }
  }
  return -1;
}

const char *Pinball::at(int index) {
  if (index < 0 || index >= m_capacity)
    throw std::out_of_range("Index out of range");

  return H[index];
}

char *Pinball::remove(const char *str) {
  int myIndex = find(str);
  m_size--;
  char *myLocation = H[myIndex];
  H[myIndex] = NULL;
  return myLocation;
}

void Pinball::printStats() {
  cout << "Hash statistics report: " << endl;
  cout << "\trandomness level = not very random" << endl;
  cout << "\tcapacity = " << m_capacity << endl;
  cout << "\tsize = " << m_size << endl;
  cout << "\tdegree = " << m_degree << endl;
  cout << "\tejection limit = " << m_ejectLimit << endl;

  //These results are calculated
  cout << "\tnumber of primary slots  = " << numPrimarySlots << endl;
  cout << "\taverage hits to primary slots = " << avgPrimaryHits << endl;
  cout << "\tmaximum hits to primary slots = " << maxPrimaryHits << endl;
  cout << "\t total number of ejections = " << totalEjections << endl;
  cout << "\tmaximum number of ejections in a single insertion = " << maxEjections << endl;
  cout << "\t" << endl;

}
char *Pinball::myStrdup(const char *s) {
  size_t size = strlen(s) + 1;

  //allocate memory enough for copy
//  char *p = new char[size];
  char *p = (char *) malloc(size);

  if (p) {
    strcpy(p, s); // Copy the characters
  }
  return p;
}
bool Pinball::isPrimarySlot(int someLocation) {
//get the pointer at the primary slot location
  const char *current = at(someLocation);
  if (current == NULL) {
    numPrimarySlots++;
    return true;
  }
  else {
    return false;
  }
}


