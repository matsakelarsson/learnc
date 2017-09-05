#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct item
{
  char *name;
  char *desc;
  int price;
  char *shelf;
};



  typedef struct item item_t;


void print_item(item_t *i){
  
  printf("Name: %s\n", i->name);
  printf("Desc: %s\n",i->desc);
  printf("Price: %d.%d\n", i->price / 100, i->price % 100);
  printf("Shelf: %s\n", i->shelf);
}

item_t make_item(char *name, char *desc, int price, char *shelf){
  return (item_t){.name=name, .desc=desc, .price=price, .shelf=shelf};
}

bool is_shelf(char *shelf){
  char first = shelf[0];
  return 'A' <= first && first <= 'Z' && is_number(shelf + 1);  
}

char *ask_question_shelf(char* question) {
  return ask_question(question, is_shelf, (convert_func) strdup).s;
}


item_t input_item(){

char *n = ask_question_string("Vad dens namn!?!?!?");
char *d =  ask_question_string("vem är den");
int p = ask_question_int("hur mkt moneys");
char *s =  ask_question_shelf("vareeäärrden?!!?");
 return (make_item(n, d, p, s));
}

char *magick(char *arr1[], char *arr2[], char *arr3[], int size) {
  int i1 = random() % size;
  int i2 = random() % size;
  int i3 = random() % size;
  char buf[255];
  snprintf(buf, 255, "%s-%s %s", arr1[i1], arr2[i2], arr3[i3]);
  return strdup(buf);
}

void list_db(item_t *items, int no_items){
    for (int i = 0 ; i < no_items; ++i){
      printf("%d. %s\n", i , items[i].name);
        }
  
}

void edit_db(item_t *arr){
  int i = ask_question_int("Vilken vill du ändra?");
  if(i > 0 && i < 16){
  print_item(&(arr[i]));
  arr[i] = input_item();
  }
  else
    printf("DET FINNS FÖR FAN ITE");
  
} 


  
int main(int argc, char *argv[])
{
 char *array1[] = { "Laser",        "Polka",    "Extra" };
 char *array2[] = { "förnicklad",   "smakande", "ordinär" };
 char *array3[] = { "skruvdragare", "kola",     "uppgift" };


  if (argc < 2)
  {
    printf("Usage: %s number\n", argv[0]);
  }
  else
  {
    item_t db[16]; // Array med plats för 16 varor
    int db_siz = 0;    // Antalet varor i arrayen just nu

    int items = atoi(argv[1]); // Antalet varor som skall skapas

    if (items > 0 && items <= 16)
    {
      for (int i = 0; i < items; ++i)
      {
        // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
        item_t item = input_item();
        db[db_siz] = item;
        ++db_siz;
      }
    }
    else
    {
      puts("Sorry, must have [1-16] items in database.");
      return 1; // Avslutar programmet!
    }

    for (int i = db_siz; i < 16; ++i)
      {
        char *name = magick(array1, array2, array3, 3); /// Lägg till storlek
        char *desc = magick(array1, array2, array3, 3
                            ); /// Lägg till storlek
        int price = random() % 200000;
        char shelf[] = { random() % ('Z'-'A') + 'A',
                         random() % 10 + '0',
                         random() % 10 + '0',
                         '\0' };
        item_t item = make_item(name, desc, price, shelf);

        db[db_siz] = item;
        ++db_siz;
      }

    list_db(db, 16);
    edit_db(db);
     }
  
  return 0;
}

  


