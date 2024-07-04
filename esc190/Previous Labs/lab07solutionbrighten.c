#include "c_img.h"

#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    struct rgb_img *im;
    read_in_img(&im, "cannon.bin");
    for(int i = 0; i < im->height; i++){
        for(int j = 0; j < im->width; j++){
            int r = get_pixel(im, i, j, 0);
            int g = get_pixel(im, i, j, 1);
            int b = get_pixel(im, i, j, 2);
            set_pixel(im, i, j, min(2*r, 255), min(2*g, 255), min(2*b, 255));
        }
    }
    write_img(im, "cannon2.bin");
    
    destroy_image(im);
    return 0;
}