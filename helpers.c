#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height;i++){
        for(int j=0; j<width;j++){

          int avg=(round(image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/3);

          image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg;

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
            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;

        int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
           int sepiaGreen = round( .349 * originalRed + .686 * originalGreen + .168 * originalBlue);
           int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if(sepiaRed > 255){

              sepiaRed = 255;
            }
            if( sepiaGreen > 255 ){
               sepiaGreen = 255;
            }
             if( sepiaBlue > 255 ){
              sepiaBlue = 255;
            }
            image[i][j].rgbtRed= sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;

            image[i][j].rgbtBlue = sepiaBlue;
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
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
         for (int i = 0; i < height; i++)
          {
            for (int j = 0; j < width; j++)
            {

            float sum_red;
            float sum_blue;
            float sum_green;
            int counter;
            sum_red = sum_blue = sum_green = counter = 0;
              for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                   if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }

            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}
