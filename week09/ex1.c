#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define number_of_pages 5000
#define bit char

double aging_simulation(int number_of_pf){ // pf = page frames
    int number_of_free_pf = number_of_pf; // initially, all page frames are empty

    // typedef struct page_frame{
    //     int number;
    // }page_frame;

    typedef struct page{
        unsigned short age; //16 bits
        int mapped_to; //number of page frame this page is mapped to
        // bit R; //referenced
        // bit M; // modified
    }page;

    int hit = 0;
    int miss = 0;
    FILE* f = fopen("input.txt", "r");
    
    // page_frame pg_frms[number_of_pf];

    page pgs[number_of_pages];
    for (int i = 0; i < number_of_pages; i++){
        //i = page's number in virtual memory
        // pgs[i].R = 0;
        // pgf[i].M = 0;
        pgs[i].age = 0;
        pgs[i].mapped_to = -1; //initially, all unmapped
    }

    short queries[10000]; // will contain numbers from the file

    char c;
    c = fgetc(f);
    int i = 0;
    while(c != '\n'){
        ungetc(c, f);
        fscanf(f, "%d", &queries[i++]);
        c = fgetc(f);
    }
    int number_of_queries = i; // because i was already incremented in while loop
    fclose(f);

    page* requested; // for a requested page

    for (int j = 0; j < number_of_queries; j++){
        requested = &pgs[queries[j]];
        if (requested->mapped_to != -1){
            hit++;
            requested->age >>= 1;
            requested->age += pow(2,15);
        }
        else{
            miss++;
            for (int p = 0; p < number_of_pages; p++)
                if (pgs[p].mapped_to != -1 && &pgs[p] != requested)
                    pgs[p].age >>= 1; // not requested but mapped so we made it older
            if (number_of_free_pf > 0){
                //therefore, we can load requested one without deleting anything
                int index = number_of_pf - number_of_free_pf + 1;
                number_of_free_pf--;
                requested->mapped_to = index;
                requested->age += pow(2,15);
            }
            else{
                //now we must substitute the oldest page with a requested one
                int min = pow(2,15);
                int number_of_the_oldest_page;
                for (int i = 0; i < number_of_pages; i++){
                    if (pgs[i].age < min){
                        min = pgs[i].age;
                        number_of_the_oldest_page = i;
                    }
                }
                requested->age += pow(2,15);
                requested->mapped_to = pgs[number_of_the_oldest_page].mapped_to;

                pgs[number_of_the_oldest_page].age = 0;
                pgs[number_of_the_oldest_page].mapped_to = -1;
            }
        }
    }
    printf("Pages: %d, Hits: %d, Misses: %d\n", number_of_pf, hit, miss);
    return (float) hit/ (float) miss;
}

int main(){
    int pg_frs;
    printf("Enter the number of page frames: ");
    scanf("%d", &pg_frs);
    double HM_ratio = aging_simulation(pg_frs);
    printf("Hit/miss ratio: %lf\n", HM_ratio);
}