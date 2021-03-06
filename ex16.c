#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person {
    char *name;
    int age;
    struct _Person *next;
    int height;
    int weight;
} Person;

struct _Person *Person_create(char *name, int age, int height, int weight,  Person *next)
{
    Person *who = malloc(sizeof(Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;
    who->next = next;

    return who;
}

void Person_destroy(Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
    if (who->next != NULL) {
      printf("\tNext: %s\n", who->next-> name);
    }
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct _Person *joe = Person_create(
            "Joe Alex", 32, 64, 140, NULL);

    struct _Person *frank = Person_create(
            "Frank Blank", 20, 72, 180, joe);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_print(frank);
    Person_destroy(frank);

    return 0;
}
