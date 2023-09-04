/*An animal could be a canine (dog, wolf, fox, etc.), a feline (cat, lynx,
jaguar, etc.), a cetacean (whale, narwhal, etc.) or a marsupial (koala,
wombat, etc.). The information whether a particular animal is
canine, feline, cetacean, or marsupial is stored in bit number 0, 1, 2
and 3, respectively of a integer variable called type. Bit number 4 of
the variable type stores the information about whether the animal
is Carnivore or Herbivore.
For the following animal, complete the program to determine
whether the animal is a herbivore or a carnivore. Also determine
whether the animal is a canine, feline, cetacean or a marsupial.
struct animal
{
char name[ 30 ] ;
int type ;
}
struct animal a = { "OCELOT", 18 } ;
*/
#include <stdio.h>
#include <string.h>

// Constants for type and herbivore/carnivore information
#define TYPE_CANINE    0x1
#define TYPE_FELINE    0x2
#define TYPE_CETACEAN  0x4
#define TYPE_MARSUPIAL 0x8
#define CARNIVORE      0x10

// Struct to represent an animal
struct animal {
    char name[30];
    int type;
};

int main() {
    // Define the given animal
    struct animal a = { "OCELOT", 18 };

    // Determine if it's a herbivore or carnivore
    if (a.type & CARNIVORE) {
        printf("%s is a carnivore.\n", a.name);
    } else {
        printf("%s is a herbivore.\n", a.name);
    }

    // Determine the specific type of animal
    printf("%s is a", a.name);

    if (a.type & TYPE_CANINE) {
        printf(" canine");
    }
    if (a.type & TYPE_FELINE) {
        printf(" feline");
    }
    if (a.type & TYPE_CETACEAN) {
        printf(" cetacean");
    }
    if (a.type & TYPE_MARSUPIAL) {
        printf(" marsupial");
    }

    printf(".\n");

    return 0;
}
