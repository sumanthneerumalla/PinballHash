//File:    Pinball.cpp
// Project: CMSC 202 Project 5, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    12/4/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the implementation of the Pinball class

#ifndef PINBALL_CPP_
#define PINBALL_CPP_

#include <cstring>
#include <string.h>
#include "Pinball.h"

#endif
Pinball::Pinball(int n) {
  m_capacity = n;
  m_size = 0; //start off size of hash table at 0
  m_degree = 7; //configuration given by professor
  m_ejectLimit = 20; //configuration given by professor
  H = new char *[m_capacity]();
  memset(H, 0, n * sizeof(char *));
//  char* c3 = strdup("rabbits");
//  char* c4 = strdup("parrots");

}
Pinball::~Pinball() {
  for (int i = 0; i < m_capacity; ++i) {
    free(H[i]);
  }
  delete[] H;
}
void Pinball::insert(const char *str) {
  m_size++;

}
int Pinball::find(const char *str) {
  return 0;
}
const char *Pinball::at(int index) {
  return nullptr;
}
char *Pinball::remove(const char *str) {
  return nullptr;
}
void Pinball::printStats() {

}
