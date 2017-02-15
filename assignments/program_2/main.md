```cpp
/**
* @ProgramName: Program-1
* @Author: Buddy Smith
* @Description:
*     This program reads in images stored as rgb values in
*     text format.  The values are stored in a 2d array to be
*     be used by methods of the class ImageManip.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date:    15 02 07
*/

#include <iostream>     // cin, cout, endl, <<, >>
#include <fstream>      // ifstream, ofstream
#include <algorithm>    // swap

using namespace std;

struct rgb{
    int r,              // red value
        g,              // green value
        b;              // blue value
};
/**
*/
class ImageManip{
private:
    rgb** image;
    int width;          // width of photo
    int height;         // height of photo
    ifstream infile;    // fstream object
    ofstream ofile;     // fstream object
    string ifile_name;  // input file name
    string ofile_name;  // output file name

    /**
    * @FunctionName: readFile
    * @Description:
    *     Loops through a 2D array and stores the values of RGB from the
    *     image text and stores the values in the array.
    * @Params:
    *     string ifile_name: file to be read
    * @Returns:
    *    void
    */
    void readFile(string ifile_name){
        infile.open(ifile_name.c_str());
        infile >> width >> height;
        cout << width << height;
        // create 2d array
        image = new rgb *[height];
        for(int i=0;i<height;i++){
            image[i] = new rgb[width]; //Now allocate each row of rgb's
        }
        // read values from file
        int x ,
            y ;
        for( x = 0; x < height; x++){
            for(y = 0 ; y < width; y++){
               infile >> image[x][y].r;
               infile >> image[x][y].g;
               infile >> image[x][y].b;
            }
        }


    }
/*****************************************************************************/
     /**
    * @FunctionName: writeFile
    * @Description:
    *     The method opens the output file supplied by the user in the
    *     constructor and writes the altered data to the file
    * @Params:
    *     string fileOut:  file to output data to.
    * @Returns:
    *    void
    */

    void writeFile(string fileOut){
        int x,
            y;
        ofile.open(fileOut.c_str());
        ofile << width << " " << height << endl;
        for(x = 0; x < height; x++){
            for(y = 0; y < width; y++){
                ofile << image[x][y].r << " "
                      << image[x][y].g << " "
                      << image[x][y].b << " ";
            }
            ofile << endl;
        }
    }
public:
/*****************************************************************************/
    /**
    * @Constructor: ImageManip
    * @Description:
    *    Default Class Constructor
    * @Params:
    *   none
    * @Returns:
    *    void
    */

    ImageManip(){
    }
/*****************************************************************************/
    /**
    * @FunctionName: flipVert
    * @Description:
    *     Loops through a 2D array and swaps the first row with the last row.
    * @Params:
    *   string fileIn:  file to gather input from
    *   string fileOut: file to output data to
    * @Returns:
    *    void
    */

    void flipVert(string fileIn, string fileOut){

        readFile(fileIn);


        for(int i = 0; i < height / 2; i++){
            for(int j = 0; j < width; j++){
                swap(image[i][j].r,image[height-1-i][j].r);
                swap(image[i][j].b,image[height-1-i][j].b);
                swap(image[i][j].g,image[height-1-i][j].g);
            }
        }
        writeFile(fileOut);
    }
/*****************************************************************************/
    /**
    * @FunctionName: flipHorz
    * @Description:
    *     Loops through a 2D array and swaps values of the 2d array to
    *     flip the image Horizontally. writeFile() is called to store the
    *     changed values of the image text
    * @Params:
    *     string fileIn: file to gather input from
    *     string fileOut: file to output data to
    * @Returns:
    *    void
    */
    void flipHorz(string fileIn, string fileOut){
        readFile(fileIn);

        for(int x = 0; x < height; x++ ){
            for(int y = 0; y< width / 2; y++){          // swap values
                swap(image[x][y].r,image[x][width-1-y].r);
                swap(image[x][y].g,image[x][width-1-y].g);
                swap(image[x][y].b,image[x][width-1-y].b);
            }
        }
        writeFile(fileOut);
    }
/*****************************************************************************/
    /**
    * @FunctionName: grayScale
    * @Description:
    *    Loops through a 2D array and turns every RGB value into its grayscale equivalent.
    *    The new data is store in the output file designated by the user.
    * @Params:
    *    string fileIn: file to gather input from
    *    string fileOut: file to output data to
    * @Returns:
    *    void
    */
    void grayScale(string fileIn, string fileOut){

        readFile(fileIn);
        int temp;

        for(int i = 0; i < height; i++){
            for(int j =0; j < width; j++){
                temp = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
                image[i][j].r = temp;
                image[i][j].g = temp;
                image[i][j].b = temp;

            }
        }
        writeFile(fileOut);
    }
/*****************************************************************************/
    ~ImageManip(){
        delete image;
    }
};


int main()
{
    ImageManip image;
    image.flipVert("data.txt","data2.txt");


    return 0;
}


```/**
* @ProgramName: Program-1
* @Author: Buddy Smith
* @Description:
*     This program reads in images stored as rgb values in
*     text format.  The values are stored in a 2d array to be
*     be used by methods of the class ImageManip.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date:    15 02 07
*/

#include <iostream>     // cin, cout, endl, <<, >>
#include <fstream>      // ifstream, ofstream
#include <algorithm>    // swap

using namespace std;

struct rgb{
    int r,              // red value
        g,              // green value
        b;              // blue value
};
/**
*/
class ImageManip{
private:
    rgb** image;
    int width;          // width of photo
    int height;         // height of photo
    ifstream infile;    // fstream object
    ofstream ofile;     // fstream object
    string ifile_name;  // input file name
    string ofile_name;  // output file name

    /**
    * @FunctionName: readFile
    * @Description:
    *     Loops through a 2D array and stores the values of RGB from the
    *     image text and stores the values in the array.
    * @Params:
    *     string ifile_name: file to be read
    * @Returns:
    *    void
    */
    void readFile(string ifile_name){
        infile.open(ifile_name.c_str());
        infile >> width >> height;
        cout << width << height;
        // create 2d array
        image = new rgb *[height];
        for(int i=0;i<height;i++){
            image[i] = new rgb[width]; //Now allocate each row of rgb's
        }
        // read values from file
        int x ,
            y ;
        for( x = 0; x < height; x++){
            for(y = 0 ; y < width; y++){
               infile >> image[x][y].r;
               infile >> image[x][y].g;
               infile >> image[x][y].b;
            }
        }


    }
/*****************************************************************************/
     /**
    * @FunctionName: writeFile
    * @Description:
    *     The method opens the output file supplied by the user in the
    *     constructor and writes the altered data to the file
    * @Params:
    *     string fileOut:  file to output data to.
    * @Returns:
    *    void
    */

    void writeFile(string fileOut){
        int x,
            y;
        ofile.open(fileOut.c_str());
        ofile << width << " " << height << endl;
        for(x = 0; x < height; x++){
            for(y = 0; y < width; y++){
                ofile << image[x][y].r << " "
                      << image[x][y].g << " "
                      << image[x][y].b << " ";
            }
            ofile << endl;
        }
    }
public:
/*****************************************************************************/
    /**
    * @Constructor: ImageManip
    * @Description:
    *    Default Class Constructor
    * @Params:
    *   none
    * @Returns:
    *    void
    */

    ImageManip(){
    }
/*****************************************************************************/
    /**
    * @FunctionName: flipVert
    * @Description:
    *     Loops through a 2D array and swaps the first row with the last row.
    * @Params:
    *   string fileIn:  file to gather input from
    *   string fileOut: file to output data to
    * @Returns:
    *    void
    */

    void flipVert(string fileIn, string fileOut){

        readFile(fileIn);


        for(int i = 0; i < height / 2; i++){
            for(int j = 0; j < width; j++){
                swap(image[i][j].r,image[height-1-i][j].r);
                swap(image[i][j].b,image[height-1-i][j].b);
                swap(image[i][j].g,image[height-1-i][j].g);
            }
        }
        writeFile(fileOut);
    }
/*****************************************************************************/
    /**
    * @FunctionName: flipHorz
    * @Description:
    *     Loops through a 2D array and swaps values of the 2d array to
    *     flip the image Horizontally. writeFile() is called to store the
    *     changed values of the image text
    * @Params:
    *     string fileIn: file to gather input from
    *     string fileOut: file to output data to
    * @Returns:
    *    void
    */
    void flipHorz(string fileIn, string fileOut){
        readFile(fileIn);

        for(int x = 0; x < height; x++ ){
            for(int y = 0; y< width / 2; y++){          // swap values
                swap(image[x][y].r,image[x][width-1-y].r);
                swap(image[x][y].g,image[x][width-1-y].g);
                swap(image[x][y].b,image[x][width-1-y].b);
            }
        }
        writeFile(fileOut);
    }
/*****************************************************************************/
    /**
    * @FunctionName: grayScale
    * @Description:
    *    Loops through a 2D array and turns every RGB value into its grayscale equivalent.
    *    The new data is store in the output file designated by the user.
    * @Params:
    *    string fileIn: file to gather input from
    *    string fileOut: file to output data to
    * @Returns:
    *    void
    */
    void grayScale(string fileIn, string fileOut){

        readFile(fileIn);
        int temp;

        for(int i = 0; i < height; i++){
            for(int j =0; j < width; j++){
                temp = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
                image[i][j].r = temp;
                image[i][j].g = temp;
                image[i][j].b = temp;

            }
        }
        writeFile(fileOut);
    }
/*****************************************************************************/
    ~ImageManip(){
        delete image;
    }
};


int main()
{
    ImageManip image;
    image.flipVert("data.txt","data2.txt");


    return 0;
}
