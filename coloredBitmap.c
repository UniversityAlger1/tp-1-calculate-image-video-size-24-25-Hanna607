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

    // Conversion selon l'unité demandée
    if (strcmp(unit, "bt") == 0) {
        // Retourner la taille en bits
        return (float)totalBits;
    } else if (strcmp(unit, "ko") == 0) {
        // Convertir en kilobits : 1 kilobit = 1024 bits
        return totalBits / 1024.0f;
    } else if (strcmp(unit, "mo") == 0) {
        // Convertir en mégabits : 1 mégabit = 1024 kilobits
        return totalBits / (1024.0f * 1024.0f);
    } else if (strcmp(unit, "go") == 0) {
        // Convertir en gigabits : 1 gigabit = 1024 mégabits
        return totalBits / (1024.0f * 1024.0f * 1024.0f);
    } else {
        // Unité invalide, retourner 0
        return 0.0f;
    }
}