#include <stdio.h>
#include "utility.h"
/*This is a permutation generator.
 */
typedef struct permu{
    int *permutation;
    int *inversetable;
    int length;
    int overflow;
} permu;


int _add(int *invertation,int length)
{
    /* This function is modify the data in the place.
     * 'flag' is a mark of whether the operation has done.
     * 'index' is the place where the carrying of number take place.
     * 'forward' is the amount of carrying.
     */
    int flag = 0,index = 0,forward = 1;
    while(flag==0 && index < length){
        /*no carrying*/
        if(*(invertation+index)+forward < index +1){
            *(invertation +index)=*(invertation+index)+forward;
            flag = 1;
        }
        /*carry the number*/
        else{
            forward = (int)((*(invertation+index) + forward)/(index + 1));
            *(invertation+index) = (int)((*(invertation+index) + forward)%(index + 1));
            index++;
        }
    }
    if(flag == 0) {
        int i;
        for(i=0;i<length;i++){
            *(invertation+i)=-1;
        }
        return 0;
    }
    else return 1;
}


int _geninversetable(permu *container)
{
    int *inversetable = container->inversetable;
    int length = container->length;

    if(_add(inversetable,length)){
        return 1;
    }
    else{
        container->overflow = 1;
        return 0;
    }
}

/*Produce a permutation from a inversetable.Store the permutation in permutation variable.
 * all this is in the structure permu.*/
int _permutation(permu *permutation)
{
    int *permu = permutation->permutation;
    int *inversetable = permutation->inversetable;
    int length = permutation->length;

    int i;
    int insert,inverseNum;
    for(i=0;i< length;i++){
        insert = length - i;/*The number will be inserted into the array.*/
        inverseNum = *(inversetable + i);/*The amount how many numbers bigger before.*/

        _rshift(permu,length,inverseNum,i);/*Empty the place where we want to insert number.*/
        *(permu+inverseNum) = insert;/*Insert.*/
    }

    return 1;
}

int permutation(permu *p){
    while(!(p->overflow)){
        _geninversetable(p);
        _permutation(p);
        print_1array(p->permutation,p->length);
    }
    return 1;
}
int main(int argc, const char *argv[])
{
#ifdef TEST
    permu p;
    int permutations[26];
    int inversetable[26];
    _initialize(inversetable,26,0);    

    /*Initialize the structure.*/
    p.permutation = permutations;
    p.inversetable = inversetable;
    p.length = 26;
    p.overflow = 0;
    
    permutation(&p);
#endif 
    return 0;
}
