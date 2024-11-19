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
    // Taille d'une image en bits
    int colorBitsPerFrame = w * h * 3 * 8;  // RGB : 3 composantes, 8 bits chacune
    int bwBitsPerFrame = w * h * 8;         // Noir et blanc : 8 bits par pixel

    // Nombre total de frames pour chaque section
    int totalFramesMovie = durationMovie * fps;
    int totalFramesCredits = durationCredits * fps;

    // Taille totale des sections (en bits)
    long long totalColorBits = (long long)totalFramesMovie * colorBitsPerFrame;
    long long totalBWBits = (long long)totalFramesCredits * bwBitsPerFrame;
    long long totalBits = totalColorBits + totalBWBits;

    // Conversion selon l'unité
    if (strcmp(unit, "bt") == 0) {
        // Retourner la taille en bits
        return (float)totalBits;
    } else if (strcmp(unit, "ko") == 0) {
        // Convertir en kilobits (1 kilobit = 1024 bits)
        return totalBits / 1024.0f;
    } else if (strcmp(unit, "mo") == 0) {
        // Convertir en mégabits (1 mégabit = 1024 kilobits)
        return totalBits / (1024.0f * 1024.0f);
    } else if (strcmp(unit, "go") == 0) {
        // Convertir en gigabits (1 gigabit = 1024 mégabits)
        return totalBits / (1024.0f * 1024.0f * 1024.0f);
    } else {
        // Unité invalide, retourner 0
        return 0.0f;
    }
}