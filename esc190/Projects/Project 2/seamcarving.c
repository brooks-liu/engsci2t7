#include "seamcarving.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "c_img.c"

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    /*write the dual-gradient energy function and place it in *grad */
    int y1 = 0;
    int y2 = 0;
    int x1 = 0;
    int x2 = 0;
    int totalenergy = 0;

    *grad = (struct rgb_img*)malloc(sizeof(struct rgb_img)); // allocating space
    (*grad)->height = im->height;
    (*grad)->width = im->width;
    (*grad)->raster = (uint8_t *)malloc(3 * im->height * im->width);

    for(int row = 0; row < im->height; row++){
        for(int col = 0; col < im->width; col++){
            y1 = row + 1;
            y2 = row - 1;
            x1 = col + 1;
            x2 = col - 1;
            totalenergy = 0;
            if(row == 0){y2 = im->height - 1;}
            if(row == im->height - 1){y1 = 0;}
            if(col == 0){x2 = im->width - 1;}
            if(col == im->width - 1){x1 = 0;} // all in case pixel is on the edge; we loop around if that is the case

            totalenergy += pow((get_pixel(im, y1, col, 0) - get_pixel(im, y2, col, 0)), 2);
            totalenergy += pow((get_pixel(im, y1, col, 1) - get_pixel(im, y2, col, 1)), 2);
            totalenergy += pow((get_pixel(im, y1, col, 2) - get_pixel(im, y2, col, 2)), 2); // adding each square of differences
            totalenergy += pow((get_pixel(im, row, x1, 0) - get_pixel(im, row, x2, 0)), 2);
            totalenergy += pow((get_pixel(im, row, x1, 1) - get_pixel(im, row, x2, 1)), 2);
            totalenergy += pow((get_pixel(im, row, x1, 2) - get_pixel(im, row, x2, 2)), 2);  // same as above

            set_pixel(*grad, row, col, sqrt(totalenergy) / 10, sqrt(totalenergy) / 10, sqrt(totalenergy) / 10);
        }
    }
}

uint8_t min2(uint8_t num1, uint8_t num2){
    if(num1 <= num2){
        return num1;
    }
    return num2;
}

void dynamic_seam(struct rgb_img *grad, double **best_arr){
    size_t height = grad->height;
    size_t width = grad->width;
    (*best_arr) = (double*)malloc(height * width * sizeof(double));
    double tempsum = 0;
    for(int i = 0; i < width; i++){ //write in first line first
        (*best_arr)[i] = (double)grad->raster[i * 3]; // since grad is the same for all three pixels, we can take just the red
    }
    for(int row = width; row < height * width; row += width){ // row in rastor for ease of indexing
        for(int col = 0; col < width; col++){
            tempsum = 0.0;
            if(col == 0){
                tempsum = min2((*best_arr)[row - width] + grad->raster[row * 3], (*best_arr)[row - width + 1] + grad->raster[row * 3]);
            }
            else if (col == width - 1){
                tempsum = min2((*best_arr)[row - width + col] + grad->raster[(row + col) * 3], (*best_arr)[row - width + col - 1] + grad->raster[(row + col) * 3]);
            }
            else{
                tempsum = min2((*best_arr)[row - width + col] + grad->raster[(row + col) * 3], (*best_arr)[row - width + col + 1] + grad->raster[(row + col) * 3]); // compare right
                tempsum = min2(tempsum, (*best_arr)[row - width + col - 1] + grad->raster[(row + col) * 3]); // compare left
            }
            (*best_arr)[row + col] = tempsum;
        }
    }
}

void recover_path(double* best, int height, int width, int** path){
    *path = (int*)malloc(height* sizeof(int)); 
    double curval = best[(height - 1) * width];
    int index = 0;
    for(int i = 1; i < width; i++){
        if(best[(height - 1) * width + i] < curval){ // start of last row
            index = i;
            curval = best[(height - 1) * width + i];
        }
    }
    (*path)[height - 1] = index;
    for(int row = height - 2; row >= 0; row--){ // just did last row
        if(best[row * width + index - 1] < best[row * width + index] && best[row * width + index - 1] < best[row * width + index + 1]){
            index--;  // if index - 1 is the best row, shift the index left
        }
        else if(best[row * width + index] > best[row * width + index + 1]){ // if the left is not the smallest, compare middle and right
            index++;  // if the right is smaller, shift index right
        }
        (*path)[row] = index;
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    create_img(dest, src->height, src->width - 1);
    int shift = 0;
    for(int row = 0; row < src->height; row++){
        shift = 0;
        for(int pixel = 0; pixel < src->width; pixel++){
            if(pixel == path[row]){
                shift++;
            }
            else{
                set_pixel((*dest), row, pixel - shift, get_pixel(src, row, pixel, 0), get_pixel(src, row, pixel, 1), get_pixel(src, row, pixel, 2));
            }
        }
    }
}

int main(){
    /*
    struct rgb_img* im;
    struct rgb_img* grad;
    read_in_img(&im, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Projects\\Project 2\\3x4.bin");
    // printf("%d\n", im->height);
    calc_energy(im, &grad);
    // print_grad(grad);

    read_in_img(&im, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Projects\\Project 2\\6x5.bin");
    calc_energy(im, &grad);
    // print_grad(grad);
    // printf("%d\n", grad->width);
    // printf("%d\n", grad->height);

    double* best_array;
    dynamic_seam(grad, &best_array);

    // for(int i=0; i< (grad->width)*(grad->height); i++){
    //     printf("%f\t", best_array[i]);
    // }

    int* path;

    recover_path(best_array, grad->height, grad->width, &path);
    // for(int i = 0; i < grad->height; i++){
    //     printf("%d\n", path[i]);
    // } 
    */

    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Projects\\Project 2\\HJoceanSmall.bin");
    
    for(int i = 0; i < 200; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        char filename[200];
        sprintf(filename, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Projects\\Project 2\\img%d.bin", i);
        write_img(cur_im, filename);

        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    destroy_image(im);

}