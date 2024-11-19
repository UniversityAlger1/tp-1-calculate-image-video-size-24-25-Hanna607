#include "config/grayScaleImage.h"
// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
    // Chaque pixel d'une image en niveaux de gris utilise 1 byte (8 bits)
    // Calculer la taille de l'image en bytes
    float size = w * h; // Taille totale en bytes
    return size;
}

