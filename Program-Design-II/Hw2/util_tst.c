
#include <stdio.h>
#include "util.h"


int main(){
int tst_num=1;
int npassed=0;
int nfailed=0;


//test 1    
  if(abs_diff(5.0, 3.0) != 2.0){
	printf("test %i failed\n", tst_num);
	nfailed++;
  }
  else {
	npassed++;
  }
  tst_num++;

// test 2
  if(abs_diff(9.0, 6.0) != 3.0){
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 3 
  if(abs_diff(4.0, 12.0) != 8.0){
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 4
  if(abs_diff(-4.0, 12.0) != 16.0){
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 5
  if(abs_diff(4.0, -12.0) != 16.0){
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 6

  if(abs_diff(-7.0, -9.0) != 2.0){
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 7

  if(abs_diff(-1.6, -9.2) != 7.6){
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 8
  
  if(median3(3, 3, 3) != 3) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 9

    if(median3(44, 59, 99) != 44) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;  

// test 10

    if(median3(19, 18, 12) != 18) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;


// test 11

    if(median3(9, 14, 12) != 12) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;


// test 12

    if(median3(3, 9, 6) != 6) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;


// test 13

    if(median3(8, 2, 5) != 5) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;


// test 14

    if(median3(7, 9, 3) != 7) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 15

    if(median3(8, 4, 2) != 4) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;


// test 16

  if(median3(-1, 5, 4) != 4) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;


// test 17

    if(median3(8, 4, 6) != 6) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;



// test 18

    if(median3(2, 1, 3) != 2) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;




// test 19

  if(sqrt_floor(4) != 2) {
	printf("test %i failed\n", tst_num);
	nfailed++;
  }
  else {
	npassed++;
  }
  tst_num++;


// test 20

  if(sqrt_floor(5) != 2) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;

// test 21

  if(sqrt_floor(10) != 3) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }
  tst_num++;


// test 22

  if(num_ones(2) != 1) {
	printf("test %i failed\n", tst_num);
	nfailed++;
  }
  else {
	npassed++;
  }


// test 23

  if(num_ones(15) != 4) {
        printf("test %i failed\n", tst_num);
        nfailed++;
  }
  else {
        npassed++;
  }


  printf("num_tests:     %i\n", tst_num);
  printf("num_passed:    %i\n", npassed);
  printf("num_failed:    %i\n", nfailed);


}
