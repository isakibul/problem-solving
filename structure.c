#include<stdio.h>
#include<string.h>

int main(){
  struct Person{
    char name[50];
    int age;
  };

  typedef struct Person p;

  p p1;

  strcpy(p1.name, "Sakibul Islam");
  p1.age = 23;

  printf("%s\n", p1.name);
  printf("%d", p1.age);
}