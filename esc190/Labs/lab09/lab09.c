#include "c_img.h"
#include "c_img.c"

int main(){
    struct rgb_img* image;
    int tempred, tempblue, tempgreen;
    read_in_img(&image, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Labs\\lab09\\image.bin");

    for(int i = 0; i < image->width; i++){
        for(int j = 0; j < image->height; j++){
            tempred = get_pixel(image, j, i, 0);
            tempgreen = get_pixel(image, j, i, 1);
            tempblue = get_pixel(image, j, i, 2);
            tempred *= 2;
            tempgreen *= 2;
            tempblue *= 2;
            if(tempred > 255){
                tempred = 255;
            }
            if(tempgreen > 255){
                tempgreen = 255;
            }
            if(tempblue > 255){
                tempblue = 255;
            }

            set_pixel(image, j, i, tempred, tempgreen, tempblue);
        }
    }
    printf("complete\n");
    write_img(image, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Labs\\lab09\\newimage.bin");

}
