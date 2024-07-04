#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "seamcarving.h"
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

/*void calc_energy(struct rgb_img *im, struct rgb_img **grad)
{
    int Rx, Gx, Bx, Ry, Gy, By;
    double energy;
    uint8_t final_energy;

    size_t height = im->height;
    size_t width = im->width;

    *grad = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*grad)->height = height;
    (*grad)->width = width;
    (*grad)->raster = (uint8_t *)malloc(height * width);
    

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){ //
            if(x == 0){
              Rx = im->raster[3*(y*width + x) + 3] - im->raster[y*width*3 + width*3 - 3];
              Gx = im->raster[3*(y*width + x) + 4] - im->raster[y*width*3 + width*3 - 2];            
              Bx = im->raster[3*(y*width + x) + 5] - im->raster[y*width*3 + width*3 - 1];
            }
            else if(x == width - 1){
                Rx = im->raster[y*width*3] - im->raster[y*width*3 + 3*x - 3];
                Gx = im->raster[y*width*3 + 1] - im->raster[y*width*3 + x*3 - 2];
                Bx = im->raster[y*width*3 + 2] - im->raster[y*width*3 + x*3 - 1];
            }
            else{
                Rx = im->raster[3*(y*width + x) + 3] - im->raster[3*(y*width + x) - 3];
                Gx = im->raster[3*width*y + 3*x + 4] - im->raster[3*width*y + 3*x - 2];
                Bx = im->raster[3*width*y + 3*x + 5] - im->raster[3*width*y + x*3 - 1];
            }

            if(y == 0){
                Ry = im->raster[y*width*3 + width*(height-1)*3 + x*3] - im->raster[y*width*3 + width*3 + x*3];
                Gy = im->raster[y*width*3 + width*(height-1)*3 + x*3 + 1] - im->raster[y*width*3 + width*3 + x*3 + 1];
                By = im->raster[y*width*3 + width*(height-1)*3 + x*3 + 2] - im->raster[y*width*3 + width*3 + x*3 + 2];
            }
            else if(y == (height-1)){
                Ry = im->raster[y*width*3 - width*3 + x*3] - im->raster[x*3];
                Gy = im->raster[y*width*3 - width*3 + x*3 + 1] - im->raster[x*3+1];
                By = im->raster[y*width*3 - width*3 + x*3 + 2] - im->raster[x*3+2];
            }

            else{
                Ry = im->raster[y*width*3 + width*3 + x*3] - im->raster[y*width*3 - width*3 + x*3];
                Gy = im->raster[y*width*3 + width*3 + x*3 + 1] - im->raster[y*width*3 - width*3 + x*3 + 1];
                By = im->raster[y*width*3 + width*3 + x*3 + 2] - im->raster[y*width*3 - width*3 + x*3 + 2];
            }

            energy = sqrt(Rx*Rx + Gx*Gx + Bx*Bx + Ry*Ry + Gy*Gy + By*By);
            final_energy = energy/10;
            //printf("%f\t", energy);
            //(*grad)->raster[xy] = energy/10; 
            
            set_pixel(*grad, y, x, final_energy, final_energy, final_energy);
        }
    }
}*/

void dynamic_seam(struct rgb_img *grad, double **best_arr)
{
    size_t height = grad->height;
    size_t width = grad->width;
    double sum = 0;
    int i = 0;
    int j = 0;
  
    *best_arr = (double *)malloc(height*width*sizeof(double));
  
    for(i=0; i < width; i++){
        (*best_arr)[i] = (double)(grad->raster[i]);
        //(*best_arr)[i] = get_pixel(grad,0,i,0);
    }
  
    
    for(i = width; i < height*width; i += width){
        for(j=0; j<width; j++){
            if(j==0){
                sum = fmin(grad->raster[i] + (*best_arr)[i-width], grad->raster[i] + (*best_arr)[i - width + 1]);
                (*best_arr)[i] = sum;
            }
            else if(j==width-1){
                sum = fmin(grad->raster[i+j]+(*best_arr)[i+j-width], grad->raster[i+j]+(*best_arr)[i+j-width-1]);
                (*best_arr)[i+j] = sum;
            }
            else{
                sum = fmin(grad->raster[i+j]+(*best_arr)[i+j-width-1], grad->raster[i+j]+(*best_arr)[i+j-width]);
                sum = fmin(sum, grad->raster[i+j]+(*best_arr)[i+j-width+1]);
                (*best_arr)[i+j] = sum;
            }
        }
    
    }
}


void recover_path(double *best, int height, int width, int **path) {
    *path = (int *)malloc(height * sizeof(int));

    (*path)[height - 1] = 0;
    int k = height - 1;

    for (int i = 1; i < width; i++) {
        if (best[(height - 1) * width + i] < best[(height - 1) * width + (*path)[k]]) {
            (*path)[k] = i;
        }
    }
    k--;

    for (int j = (height - 2) * width; j >= 0; j -= width){
        if ((*path)[k + 1] == 0){
            if (best[j] < best[j + 1]){
                (*path)[k] = 0;
            } 
            else{
                (*path)[k] = 1;
            }
        } 
        else if ((*path)[k + 1] == width - 1) {
            if (best[j + (*path)[k + 1]] < best[j + (*path)[k + 1] - 1]) {
                (*path)[k] = (*path)[k + 1];
            } 
            else {
                (*path)[k] = (*path)[k + 1] - 1;
            }
        } 
        else {
            if (best[j + (*path)[k + 1]] <= best[j + (*path)[k + 1] - 1] && best[j + (*path)[k + 1]] <= best[j + (*path)[k + 1] + 1]) {
                (*path)[k] = (*path)[k + 1];
            } 
            else if (best[j + (*path)[k + 1] - 1] <= best[j + (*path)[k + 1] + 1] && best[j + (*path)[k + 1] - 1] <= best[j + (*path)[k + 1]]) {
                (*path)[k] = (*path)[k + 1] - 1;
            } 
            else if (best[j + (*path)[k + 1] + 1] <= best[j + (*path)[k + 1]] && best[j + (*path)[k + 1] + 1] <= best[j + (*path)[k + 1] - 1]) {
                (*path)[k] = (*path)[k + 1] + 1;
            } 
            else {
                (*path)[k] = (*path)[k + 1];
            }
        }
        k--;
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path)
{
  create_img(dest, src->height, src->width-1);

  size_t height = (*dest)->height;
  size_t width = (*dest)->width+1;
  int offset=0;

  for(int i=0; i < height; i++){
    offset=0;
    for(int j=0; j < width; j++){
      if(path[i]!= j){
        set_pixel(*dest, i, j-offset,get_pixel(src,i,j,0),get_pixel(src,i,j,1),get_pixel(src,i,j,2));
      }else{
        offset++;
      }
    }
    
  }

}

int main()
{
    //struct rgb_img *im;
    //struct rgb_img *grad;
    //char filename[100] = "6x5.bin";
    //double *best_arr;
    //int *path;

    //read_in_img(&im, "6x5.bin");
    //calc_energy(im, &grad);
    //print_grad(grad);
    //dynamic_seam(grad, &best_arr);
    //for(int i=0; i< (grad->width)*(grad->height); i++){
    //    printf("%f\t", best_arr[i]);
    //}
    // recover_path(best_arr, grad->height, grad->width, &path);
    // for(int a=0; a<grad->height; a++){
    //     printf("%d\t", path[a]);
    // }

    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Projects\\Project 2\\HJoceanSmall.bin");
    
    for(int i = 0; i < 199; i++){
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

    return 0;
}