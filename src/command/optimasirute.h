#ifndef OPTIMASIRUTE_H
#define OPTIMASIRUTE_H

typedef struct{
	int a;
  int b;
	int cost;
}infoo;

typedef struct{
  int deg;
  int l;
  int r;
  int paren;
}pointif;

void bubblesort(infoo bruh[], int et);

void optimasirute();

#endif