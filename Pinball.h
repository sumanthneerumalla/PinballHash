//File:    Pinball.h
// Project: CMSC 202 Project 5, Fall 2016
// Author:  Sumanth Neerumalla
// Date:    12/4/16
// Section: 05
// E-mail:  sz60171@umbc.edu
//Description: This file has the declaration of the Pinball class

#ifndef _PINBALL_H_
#define _PINBALL_H_

#include <string>
#include <stdexcept>
using namespace std;
#include <string.h>
#include <stdlib.h>

class PinballHashFull : public std::out_of_range {

 public:
  PinballHashFull(const string &what) : std::out_of_range(what) {}
};

class Pinball {

 public:
  Pinball(int n = 1019);    // default capacity is prime
  ~Pinball();

  void insert(const char *str);
  int find(const char *str);
  const char *at(int index);
  char *remove(const char *str);
  void printStats();

  int size() { return m_size; }

  // add public data members and
  // public member functions as needed

  //created my own strDup function since my computer didnt' have strdup for some reason
  char *myStrdup(const char *s);

 private:

  char **H;        // the actual hash table
  int m_size;       // number of items stored in H
  int m_capacity;   // number slots allocated in H

  int m_degree;     // use degree assigned to you
  int m_ejectLimit; // use ejection limit assigned to you


  // Made inline definition of hashCode() so everyone uses
  // the same function.
  //
  unsigned int hashCode(const char *str) {

    unsigned int val = 0;
    const unsigned int thirtyThree = 33;  // magic number from textbook

    int i = 0;
    while (str[i] != '\0') {
      val = val * thirtyThree + str[i];
      i++;
    }
    return val;
  }


  // add private data members and
  // private member functions as needed

  //these statistics are initialized to 0, and adjusted everytime insert() runs
  int numPrimarySlots;
  float avgPrimaryHits;
  int * maxPrimaryHits ;
  int totalEjections;
  int maxEjections;
  unsigned int* offsets;

  bool isValidSlot(int someLocation);

};

#endif
