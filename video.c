#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Taille totale en bits pour la section colorée
    int totalColorBits = w * h * 3 * 8 * fps * durationMovie; // RGB, 3 composantes, 8 bits chacune

    // Taille totale en bits pour la section noir et blanc
    int totalBWBits = w * h * 8 * fps * durationCredits; // 1 composante, 8 bits

    // Taille totale en bits de la vidéo
    int totalBits = totalColorBits + totalBWBits;

    // Conversion selon l'unité spécifiée
    if (strcmp(unit, "bt") == 0) {
        return totalBits / 8.0; // En bytes
    } else if (strcmp(unit, "ko") == 0) {
        return totalBits / (8.0 * 1024.0); // En kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalBits / (8.0 * 1024.0 * 1024.0); // En megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalBits / (8.0 * 1024.0 * 1024.0 * 1024.0); // En gigabits
    } else {
        return -1; // Unité non reconnue
    }
}