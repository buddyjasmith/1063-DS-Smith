/**
* @ProgramName: Program-1
* @Author: Buddy Smith
* @Description:
*     This program reads in images stored as rgb values in
*     a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date:    03 02 07
*/

#include<iostream>          // cout << >> endl
#include<fstream>           // ifstream, ofstream
#include<math.h>
#include<algorithm>         // swap()



using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;                //red
    int g;                //green      
    int b;                //blue
};

/**
* @FunctionName: flipVert
* @Description:
*     Loops through a 2D array and swaps the first row with the last row.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image,int width,int height){
    /* swap values of the first node with the last node, decrement by j through
       each loop.
    */

    for(int i = 0; i < height / 2; i++){
        for(int j = 0; j < width; j++){
            swap(image[i][j].r,image[height-1-i][j].r);
            swap(image[i][j].b,image[height-1-i][j].b);
            swap(image[i][j].g,image[height-1-i][j].g);
        }
    }

}

/**
* @FunctionName: flipHorz
* @Description:
*     Loops through a 2D array and swaps values of the 2d array to
*     flip the image Horizontally.

* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*    values of image array are changed
*/

void flipHorz(rgb** image,int width,int height){
    // your code
    int tempR,
        tempG,
        tempB;

    for(int x = 0; x < height; x++ ){
        for(int y = 0; y< width / 2; y++){
            // Store temp values of starting point
            // in array
            tempR = image[x][y].r;
            tempG = image[x][y].g;
            tempB = image[x][y].b;

            image[x][y].r=image[x][width-1-y].r;
            image[x][y].g=image[x][width-1-y].g;
            image[x][y].b=image[x][width-1-y].b;

            image[x][width-1-y].r = tempR;
            image[x][width-1-y].g = tempG;
            image[x][width-1-y].b = tempB;
        
        }
    }
}

/**
* @FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image,int width,int height){
    int temp;

    for(int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            temp = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = temp;
            image[i][j].g = temp;
            image[i][j].b = temp;
        }
    }
}

int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("coffeeData.txt");
    ofile.open("bot2.txt");

    int width;               //width of image
    int height;              //height of image

    rgb **imgArray;         //Pointer var for our 2D array

    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right
                            //size.

    imgArray = new rgb*[height];    //This array points to every row

    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }

    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;
        }
    }

    //** Function calls **
    
    flipHorz(imgArray,width,height);
    //grayScale(imgArray, height, width);
    //flipVert(imgArray,width,height);
    //Write out our color data to a new file

    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
            cout <<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" " << endl;
        }
        ofile<<endl;
    }


  return 0;
}

