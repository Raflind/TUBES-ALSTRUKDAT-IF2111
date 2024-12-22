#include <stdio.h>
#include <stdlib.h>
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "optimasirute.h"


infoo datas[1000];

pointif points[1000];

void bubblesort(infoo fo[], int ez){
  int tempa, tempb, tempc;
  for(int i=1;i<=ez;i++){
    for(int j=ez;j>=i+1;j--){
      if(fo[j].cost < fo[j-1].cost){
        tempa = fo[j-1].a;
        tempb = fo[j-1].b;
        tempc = fo[j-1].cost;
        fo[j-1].a = fo[j].a;
        fo[j-1].b = fo[j].b;
        fo[j-1].cost = fo[j].cost;
        fo[j].a = tempa;
        fo[j].b = tempb;
        fo[j].cost = tempc;
      }
    }
  }
}

void optimasirute(){
  int n,e;
  printf("Masukkan jumlah lokasi pengiriman (node): ");
  IgnoreBlanks();
  StartWord();
  n = WordToInt(currentWord);
  printf("Masukkan jumlah rute (edge): ");
  IgnoreBlanks();
  StartWord();
  e = WordToInt(currentWord);
  printf("Masukkan jarak antarlokasi (weight):\n");
  printf("(Format: <Angka Node> <Angka Node> <Cost>)\n");
  int ap,bp,c;
  for(int i=1; i<=e; i++){
    IgnoreBlanks();
    StartWord();
    ap = WordToInt(currentWord);
    IgnoreBlanks();
    StartWord();
    bp = WordToInt(currentWord);
    IgnoreBlanks();
    StartWord();
    c = WordToInt(currentWord);
    datas[i].a = ap;
    datas[i].b = bp;
    datas[i].cost = c;
    points[datas[i].a].l = -1;
    points[datas[i].a].r = -1;
    points[datas[i].b].l = -1;
    points[datas[i].b].r = -1;
    points[datas[i].a].paren = -1;
    points[datas[i].b].paren = -1;
  }

  bubblesort(datas, e);
  /*printf("\n");
  for(int i=1;i<=e;i++){
    printf("%d %d %d\n", datas[i].a, datas[i].b, datas[i].cost);
  }
  printf("\n");*/
  int pickr = n-1;
  int totalcost = 0;
  int curr = 0;
  points[datas[1].a].deg++;
  points[datas[1].b].deg++;
  if(points[datas[1].a].l != -1){
    points[datas[1].a].r = datas[1].b;
    curr = datas[1].a;
  }
  else{
    points[datas[1].a].l = datas[1].b;
    curr = datas[1].a;
  }
  if(points[datas[1].b].l != -1){
    points[datas[1].b].r = datas[1].a;
    curr = datas[1].b;
  }
  else{
    points[datas[1].b].l = datas[1].a;
    curr = datas[1].b;
  }
  points[datas[1].a].paren = datas[1].a;
  points[datas[1].b].paren = datas[1].a;
  int originalparen = datas[1].a;
  totalcost += datas[1].cost;
  pickr--;
  for(int i=2;i<=e;i++){
    if((points[datas[i].a].deg == 2) || (points[datas[i].b].deg == 2)){
      continue;
    }
    if((points[datas[i].a].paren == points[datas[i].b].paren) && (points[datas[i].a].paren != -1) && (points[datas[i].b].paren != -1)){
      continue;
    }
    points[datas[i].a].deg++;
    points[datas[i].b].deg++;
    if(points[datas[i].a].l != -1){
      points[datas[i].a].r = datas[i].b;
      curr = datas[i].a;
    }
    else{
      points[datas[i].a].l = datas[i].b;
      curr = datas[i].a;
    }
    if(points[datas[i].b].l != -1){
      points[datas[i].b].r = datas[i].a;
      curr = datas[i].b;
    }
    else{
      points[datas[i].b].l = datas[i].a;
      curr = datas[i].b;
    }
    totalcost += datas[i].cost;
    pickr--;
    if((points[datas[i].a].paren == originalparen) && (points[datas[i].b].paren == -1)){
      points[datas[i].b].paren = originalparen;
      //no need
    }
    else if((points[datas[i].a].paren == -1) && (points[datas[i].b].paren == originalparen)){
      points[datas[i].a].paren = originalparen;
      //no need
    }
    else if((points[datas[i].a].paren == -1) && (points[datas[i].b].paren == -1)){
      points[datas[i].a].paren = datas[i].a;
      points[datas[i].b].paren = datas[i].a;
      //no need
    }
    else if((points[datas[i].a].paren == originalparen) && (points[datas[i].b].paren != -1)){
      //case division: 6 and 10
      if(datas[i].b != points[datas[i].b].paren){
        points[points[datas[i].b].paren].paren = originalparen;
        points[datas[i].b].paren = originalparen;
      }
      else{ //travers
        int prev1 = datas[i].b;
        int curr1 = -1;
        if(points[datas[i].b].l != -1){
          curr1 = points[datas[i].b].l;
        }
        else{
          curr1 = points[datas[i].b].r;
        }
        int deca = -2;
        while(deca == -2){
          if(points[curr1].r != -1){
            points[curr1].paren = originalparen;
            prev1 = curr1;
            curr1 = points[curr1].r;
          }
          else{
            points[curr1].paren = originalparen;
            deca = 2;
            break;
          }
        }
      }
    }
    else if((points[datas[i].b].paren == originalparen) && (points[datas[i].a].paren != -1)){
      //case division: 6 and 10
      if(datas[i].a != points[datas[i].a].paren){
        points[points[datas[i].a].paren].paren = originalparen;
        points[datas[i].a].paren = originalparen;
      }
      else{ //travers
        int prev1 = datas[i].a;
        int curr1 = -1;
        if(points[datas[i].a].l != -1){
          curr1 = points[datas[i].a].l;
        }
        else{
          curr1 = points[datas[i].a].r;
        }
        int deca = -2;
        while(deca == -2){
          if(points[curr1].r != -1){
            points[curr1].paren = originalparen;
            prev1 = curr1;
            curr1 = points[curr1].r;
          }
          else{
            points[curr1].paren = originalparen;
            deca = 2;
            break;
          }
        }
      }
    }
    else if((points[datas[i].a].paren != -1) && (points[datas[i].b].paren != -1)){
      points[datas[i].a].paren = datas[i].a;
      points[datas[i].b].paren = datas[i].a;
      int currpar = datas[i].a;
      int prev1 = datas[i].b;
      int curr1 = -1;
      if(points[datas[i].b].l != -1){
        curr1 = points[datas[i].b].l;
      }
      else{
        curr1 = points[datas[i].b].r;
      }
      int deca = -2;
      while(deca == -2){
        if(points[curr1].r != -1){
          points[curr1].paren = currpar;
          prev1 = curr1;
          curr1 = points[curr1].r;
        }
        else{
          points[curr1].paren = currpar;
          deca = 2;
          break;
        }
      }
    }
    //printf("\n %d, %d %d ,%d %d %d %d \n", i, points[datas[i].a].deg, points[datas[i].b].deg, points[datas[i].a].l, points[datas[i].a].r, points[datas[i].b].l, points[datas[i].b].r);
    if(pickr == 0){
      break;
    }
  }
  int decidr = -1;
  int endr = -1;
  int prev = -1;
  if(points[curr].l != -1){
    prev = curr;
    curr = points[curr].l;
  }
  else{
    endr = curr;
    decidr = 1;
  }
  while(decidr == -1){
    if((points[curr].l !=-1) && (points[curr].r !=-1)){
      if(prev == points[curr].l){
        prev = curr;
        curr = points[curr].r;
      }
      else{
        prev = curr;
        curr = points[curr].l;
      }
    }
    else{
      decidr = 0;
      endr = curr;
    }
  }
  decidr = -1;
  curr = endr;
  prev = curr;
  printf("\nRute Optimal: %d - ", curr);
  if(points[curr].l != -1){
    curr = points[curr].l;
  }
  else{
    curr = points[curr].r;
  }
  while(decidr = -1){
    if((points[curr].l !=-1) && (points[curr].r !=-1)){
      printf("%d - ", curr);
      if(prev == points[curr].l){
        prev = curr;
        curr = points[curr].r;
      }
      else{
        prev = curr;
        curr = points[curr].l;
      }
    }
    else{
      printf("%d", curr);
      break;
    }
  }
  printf(", Total Rute Cost: %d\n", totalcost);
  return;
}