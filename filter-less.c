#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            int gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = gray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            int tmpRed = (sepiaRed > 255) ? 255 : sepiaRed;
            int tmpGreen = (sepiaGreen > 255) ? 255: sepiaGreen;
            int tmpBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

            image[i][j].rgbtRed = tmpRed;
            image[i][j].rgbtGreen = tmpGreen;
            image[i][j].rgbtBlue = tmpBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++){
        for(int j=0; j < width / 2; j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int neighborhood_size = 3;

    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            int redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;

            for(int ni = i - neighborhood_size / 2; ni <= i + neighborhood_size / 2; ni++){
                for(int nj = j - neighborhood_size / 2; nj <= j + neighborhood_size / 2; nj++){
                    if(ni >= 0 && ni < height && nj >= 0 && nj < width){
                        redSum += image[ni][nj].rgbtRed;
                        greenSum += image[ni][nj].rgbtGreen;
                        blueSum += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            temp[i][j].rgbtRed = round((float)redSum / count);
            temp[i][j].rgbtGreen = round((float)greenSum / count);
            temp[i][j].rgbtBlue = round((float)blueSum / count);
        }
    }
    for(int i=0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = temp[i][j];
        }
    }
}
