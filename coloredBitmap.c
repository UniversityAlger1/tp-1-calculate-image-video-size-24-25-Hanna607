#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
    // Taille totale en bits pour une image RGB
    int totalBits = w * h * 3 * 8; // Chaque pixel a 3 composantes RGB, codées sur 8 bits chacune

    // Conversion selon l'unité spécifiée
    if (strcmp(unit, "bt") == 0) {
        return totalBits; // En bits
    } else if (strcmp(unit, "ko") == 0) {
        return totalBits / 1000.0; // En kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalBits / (1000.0 * 1000.0); // En megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalBits / (1000.0 * 1000.0 * 1000.0); // En gigabits
    } else {
        return -1; // Unité non reconnue
    }
}