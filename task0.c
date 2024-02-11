#include <stdbool.h>
#include <stdio.h>
#include <math.h> //use "-l m" in the command line

int input() { //0 = success, 1 = error

    char c;
    int i;
    while (true) {
        scanf("%c", &c);
        if (c >= '0' && c <= '9') {
            printf("[%c]\n", c);
        }
        else {
            printf("test");
            break;
        }
    }
    return 0;
}

int main () {
    //int d = 50;
    //char string[] = "test string";
    //input();

    printf("Rozmer mistnosti:\n");
    int cube_i;
    scanf("%d", &cube_i); //filter inputs
    //printf("//You entered: %d\n", cube_i);
    printf("Bod #1:\n");
    int point_a[3];
    scanf("%d %d %d", &point_a[0], &point_a[1], &point_a[2]);
    //printf("//You endeted: %d %d %d\n", point_a[0], point_a[1], point_a[2]);
    int point_b[3];
    printf("Bod #2:\n");
    scanf("%d %d %d", &point_b[0], &point_b[1], &point_b[2]);
    //printf("//You endeted: %d %d %d\n", point_b[0], point_b[1], point_b[2]);

    int point_a_on_wall = 0;
    int point_b_on_wall = 0;
    //testing inputted parameters
    if (cube_i > 0) {
        //is A on a wall?
        if (point_a[0] == cube_i || point_a[0] == 0 || point_a[1] == cube_i || point_a[1] == 0 || point_a[2] == cube_i || point_a[2] == 0) {
            point_a_on_wall = 1;
        }
        //is B on a wall?
        if (point_b[0] == cube_i || point_b[0] == 0 || point_b[1] == cube_i || point_b[1] == 0 || point_b[2] == cube_i || point_b[2] == 0) {
            point_b_on_wall = 1;
        }
        //Are both on a wall?
        int pipe_length  = 0;
        float diagonal_length = 0;

        if (point_a_on_wall && point_b_on_wall) { //works with neighbouring walls

/*
            if (point_a[0] == 0 && point_b[0] == cube_i || point_b[0] == 0 && point_a[0] == cube_i || point_a[1] == 0 && point_b[1] == cube_i || point_b[1] == 0 && point_a[1] == cube_i || point_a[2] == 0 && point_b[2] == cube_i || point_b[2] == 0 && point_a[2] == cube_i) { //is it on opposite walls?
                printf("Opposite\n");
                //calculate distance of the point A from the 0 coordinate, do the same for B


            }

*/
            bool opposite_x = false;
            bool opposite_y = false;
            bool opposite_z = false;
            int coords_a[2];
            int coords_b[2];
//            int coords_a_to_zero;
//            int coords_a_to_plus;
//            int coords_b_to_zero;
//            int coords_b_to_plus;
            int coords_0_shorter;
            int coords_1_shorter;
            if (point_a[0] == 0 && point_b[0] == cube_i || point_b[0] == 0 && point_a[0] == cube_i) {
                //printf("Opposite x\n");
                opposite_x = true;
                coords_a[0] = point_a[1];
                coords_a[1] = point_a[2];
                coords_b[0] = point_b[1];
                coords_b[1] = point_b[2];
            }
            if (point_a[1] == 0 && point_b[1] == cube_i || point_b[1] == 0 && point_a[1] == cube_i) {
                //printf("Opposite y\n");
                opposite_y = true;
                coords_a[0] = point_a[0];
                coords_a[1] = point_a[2];
                coords_b[0] = point_b[0];
                coords_b[1] = point_b[2];
            }
            if (point_a[2] == 0 && point_b[2] == cube_i || point_b[2] == 0 && point_a[2] == cube_i) { //is it on opposite walls?
                //printf("Opposite z\n");
                opposite_z = true;
                coords_a[0] = point_a[0];
                coords_a[1] = point_a[1];
                coords_b[0] = point_b[0];
                coords_b[1] = point_b[1];

                //calculate distance of the point A from the 0 coordinate, do the same for B
            }

            //Calculating pipe length

            if (!opposite_x && !opposite_y && !opposite_z) {
                pipe_length += point_a[0] >= point_b[0] ? point_a[0] - point_b[0] : point_b[0] - point_a[0]; //X coord length
//            if (!opposite_y)
                pipe_length += point_a[1] >= point_b[1] ? point_a[1] - point_b[1] : point_b[1] - point_a[1]; //Y coord length
//            if (!opposite_z)
                pipe_length += point_a[2] >= point_b[2] ? point_a[2] - point_b[2] : point_b[2] - point_a[2]; //Z coord length
            }
            //printf("0 pipe: %d, cube:%d\n", pipe_length, cube_i);


            int all_dirs_length[4];
            int all_dirs_a[4];
            int all_dirs_b[4];
            if (opposite_x || opposite_y || opposite_z) {

                /*
                if (coords_a[0] + coords_b[0] < cube_i - coords_a[0] + cube_i - coords_b[0]) {
                    coords_0_shorter = coords_a[0] + coords_b[0];
                    printf("X: Going to 0 is shorter %d vs [%d]\n", coords_0_shorter, (cube_i - coords_a[0]) + (cube_i - coords_b[0]));
                }
                else {
                    coords_0_shorter = cube_i - coords_a[0] + cube_i - coords_b[0];
                    printf("X: Going to the edge is shorter %d\n", coords_0_shorter);
                }
                if (coords_a[1] + coords_b[1] < cube_i - coords_a[1] + cube_i - coords_b[1]) {
                    coords_1_shorter = coords_a[1] + coords_b[1];
                    printf("Y: Going to 0 is shorter %d (%d + %d)\n", coords_1_shorter, coords_a[1], coords_b[1]);
                }
                else {
                    coords_1_shorter = cube_i - coords_a[1] + cube_i - coords_b[1];
                    printf("Y: Going to the edge is shorter %d\n", coords_1_shorter);
                }
                */
                all_dirs_a[0] = coords_a[0] + coords_b[0] + (cube_i); //Calculating first direction
                all_dirs_a[1] = (cube_i - coords_a[0]) + (cube_i - coords_b[0]) + (cube_i);
                all_dirs_a[2] = (coords_a[1] + coords_b[1]) + (cube_i);
                all_dirs_a[3] = (cube_i - coords_a[1]) + (cube_i - coords_b[1]) + (cube_i);
                all_dirs_b[0] = (coords_a[1] > coords_b[1] ? coords_a[1] - coords_b[1] : coords_b[1] - coords_a[1]); //calculating second direction
                all_dirs_b[1] = (coords_a[1] > coords_b[1] ? coords_a[1] - coords_b[1] : coords_b[1] - coords_a[1]);
                all_dirs_b[2] = (coords_a[0] > coords_b[0] ? coords_a[0] - coords_b[0] : coords_b[0] - coords_a[0]);
                all_dirs_b[3] = (coords_a[0] > coords_b[0] ? coords_a[0] - coords_b[0] : coords_b[0] - coords_a[0]);
                //all_dirs_length[x] = (all_dirs_b[x] = 1) + (all_dirs_a[x] = 1) //can be shortened into one line
//                all_dirs_length[0] = (coords_a[0] + coords_b[0]) + (coords_a[1] > coords_b[1] ? coords_a[1] - coords_b[1] : coords_b[1] - coords_a[1]) + (cube_i); //X to zero
//                all_dirs_length[1] = ((cube_i - coords_a[0]) + (cube_i - coords_b[0])) + (coords_a[1] > coords_b[1] ? coords_a[1] - coords_b[1] : coords_b[1] - coords_a[1]) + (cube_i); //X to the edge
//                all_dirs_length[2] = (coords_a[1] + coords_b[1]) + (coords_a[0] > coords_b[0] ? coords_a[0] - coords_b[0] : coords_b[0] - coords_a[0]) + (cube_i); //Y to zero
//                all_dirs_length[3] = ((cube_i - coords_a[1]) + (cube_i - coords_b[1])) + (coords_a[0] > coords_b[0] ? coords_a[0] - coords_b[0] : coords_b[0] - coords_a[0]) + (cube_i); //Y to the edge
                all_dirs_length[0] = (all_dirs_a[0] + all_dirs_b[0]);
                int smallest = all_dirs_length[0]; //why can't you put this into the for loop?
                float buffer = sqrt(((all_dirs_a[0]) * (all_dirs_a[0])) + ((all_dirs_b[0]) * (all_dirs_a[0])));
                float smallest_diagonal = buffer;
//                printf("sd: %f\n", smallest_diagonal);
                printf("0: a: %d b: %d pyt: %f\n", all_dirs_a[0], all_dirs_b[0], buffer);
                for (int i = 1; i < 4; i++) {
                    buffer = sqrt(((all_dirs_a[i]) * (all_dirs_a[i])) + ((all_dirs_b[i]) * (all_dirs_a[i])));
                    printf("%d: a: %d b: %d pyt: %f\n", i, all_dirs_a[i], all_dirs_b[i], buffer);
//                    printf("sd: %f\n", smallest_diagonal);
                    if (smallest_diagonal > buffer)
                        smallest_diagonal = buffer;
                    all_dirs_length[i] = (all_dirs_a[i] + all_dirs_b[i]);
                    if (smallest > all_dirs_length[i]) {
                        smallest = all_dirs_length[i];
                    }
                }
                pipe_length = smallest;
                diagonal_length = smallest_diagonal;
                /*
                printf("1 pipe: %d\n", pipe_length);
                if (coords_0_shorter < coords_1_shorter) {
                    pipe_length += coords_0_shorter;
                    printf("2a pipe: %d\n", pipe_length);
                    pipe_length += coords_a[1] >= coords_b[1] ? coords_a[1] - coords_b[1] : coords_b[1] - coords_a[1];
                    printf("3a pipe: %d\n", pipe_length);
                    printf("Going x is shorter\n");

                }
                //printf("0: %d\n", coords_0_shorter);
                else {
                    pipe_length += coords_1_shorter;
                    printf("2b pipe: %d\n", pipe_length);
                    pipe_length += coords_a[0] >= coords_b[0] ? coords_a[0] - coords_b[0] : coords_b[0] - coords_a[0];
                    printf("3b pipe: %d\n", pipe_length);
                    printf("Going y is shorter\n");
                }
                */
                //printf("1: %d\n", coords_1_shorter);
            }

            printf("Delka potrubi: %d\n", pipe_length);
            printf("Delka hadice: %f\n", diagonal_length);
        }
    }

}
