#include "bmp.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int avg = round((red + blue + green) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // getting original colors
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // applying sepia formulas
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            // checking conditions for greater range of color
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // storing sepia color to image
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // creating a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // iterate rows
    for (int i = 0; i < height; i++)
    {
        // iterate columns
        for (int j = 0; j < width; j++)
        {
            int redBlur, blueBlur, greenBlur;
            redBlur = blueBlur = greenBlur = 0;
            // count the number of valid around pixels
            int count = 0;
            // iterate from row - 1 to row + 1
            for (int n = i - 1; n <= i + 1; n++)
            {
                // check if row is valid or not
                if (n < 0 || n > height - 1)
                {
                    continue;
                }
                // iterate from columns or boxes from column - 1 to column + 1
                for (int m = j - 1; m <= j + 1; m++)
                {
                    // check if column or pixel is valid or not
                    if (m < 0 || m > width - 1)
                    {
                        continue;
                    }
                    // if row is valid and column is valid increase count and sum the colors
                    redBlur += copy[n][m].rgbtRed;
                    blueBlur += copy[n][m].rgbtBlue;
                    greenBlur += copy[n][m].rgbtGreen;
                    count++;
                }
            }
            // calculate average of colors by dividing by count
            image[i][j].rgbtRed = round(redBlur / (float)count);
            image[i][j].rgbtGreen = round(greenBlur / (float)count);
            image[i][j].rgbtBlue = round(blueBlur / (float)count);
        }
    }
    return;
}
