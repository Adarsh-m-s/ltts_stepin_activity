// Use structures to find the volume and the total surface area of the box. 
//    You need to access the members of the structure with the help of a structure pointer:
//     a. With the help of (*) asterisk or indirection operator and (.) dot operator.
//     b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.

#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box *box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box box;
    struct Box *boxPtr;

    box.length = 5.0;
    box.width = 3.0;
    box.height = 4.0;

    double volume = calculateVolume(&box);
    double surfaceArea = calculateSurfaceArea(&box);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    boxPtr = &box;
    double volumePtr = calculateVolume(boxPtr);
    double surfaceAreaPtr = calculateSurfaceArea(boxPtr);

    printf("Volume (Pointer): %.2f\n", volumePtr);
    printf("Surface Area (Pointer): %.2f\n", surfaceAreaPtr);

    return 0;
}
