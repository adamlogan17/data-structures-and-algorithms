#ifndef MYLIB_H
#define MYLIB_H

void mul_div(double* first, double* second);
int search(char* pchs, int size, char key);
bool bResizeArray(int*& pi, int& size, int sizeNew);
bool bAddArrays(char*& pchs, int& size, char* pchs2, int size2);
bool bInsert(int*& pi, int& size, int pos, int val);

#endif


