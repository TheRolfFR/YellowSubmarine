#include <stdlib.h>

/**
 * Classe RÉUTILISABLE de génération de nombres aléatoires en tout genre
 */
class RandomGenerator {
  private:
    RandomGenerator() {}

  public:
    static void setSeed(unsigned int seed) {
      srand(seed);
    }
    static bool getBoolean() {
      return rand()%2 == 1;
    }
    static int getInt() {
      return rand();
    }
    static int getIntInRange(int min, int max) {
        if(min == max) return min; // comportement de sécurité on donne le mih (évite les crashs)
        return min + getInt()%(max - min);
    }
    static float getFloat(unsigned int precision) {
      unsigned int power = 1;
      for(unsigned int i = 0; i < precision; ++i) {
        power*=10;
      }
      int integerPart = getInt();
      float decimalPart = (precision > 0) ? (float) (getIntInRange(0, power) / (float) power) : 0;

      return (float) integerPart + decimalPart;
    }
    static float getFloatInRange(unsigned int precision, float min, float max) {
      unsigned int power = 1;
      for(unsigned int i = 0; i < precision; ++i) {
        power*=10;
      }

      // bon classique quoi
      int partieEntiere = getIntInRange(min, max+1);

      // la on commence a etre serieux
      // si on est entre [X,Y; Z,T[
      // on veut donc [X;Z] et [0,Y;0,T[
      // eh ben la decimalMin et decimalMax c'est 0,Y et 0,T
      // et on refait comme dans getFloat mais avec la range
      float decimalMin = min - ((int) min);
      float decimalMax = max - ((int) max);
      float partieDecimale = (precision > 0 && decimalMax - decimalMin != 0) ? getIntInRange(decimalMin * power, decimalMax * power) / (float) power : 0;

      return min + partieEntiere + partieDecimale;
    }
};