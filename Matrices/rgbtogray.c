#include <stdio.h>

#define R 0.2989
#define G 0.5870
#define B 0.1140
#define N 3
#define M 5
#define RGB_M (3 * M)

void rgbToGray(unsigned char rgb[][RGB_M], unsigned char gray[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < RGB_M; j += 3) {
            gray[i][j / 3] = R * rgb[i][j] + G * rgb[i][j + 1] + B * rgb[i][j + 2];
        }
    }
}






int main() {
    // Test your rgbToGray function here
    unsigned char rgb[N][RGB_M] = {
        {255, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0},
        {0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 0},
        {0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255}
    };
    unsigned char gray[N][M];

    rgbToGray(rgb, gray);

    // Print the gray image
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", gray[i][j]);
        }
        printf("\n");
    }

    return 0;
}