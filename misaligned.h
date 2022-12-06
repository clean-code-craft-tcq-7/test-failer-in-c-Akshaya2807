#include <stdio.h>
#include <assert.h>

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

const char* majorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors =
    sizeof(majorColorNames) / sizeof(majorColorNames[0]);

int numberOfMinorColors =
    sizeof(minorColorNames) / sizeof(minorColorNames[0]);

typedef struct {
    enum MajorColor majorColorValue;
    enum MinorColor minorColorValue;
} ColorPair;
