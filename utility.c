#include "utility.h"
#ifdef TEST
#include "testools.h"
#endif /*TEST*/


int print_1array(int *array,int length)
{
    if((length==0))
    {
        return 0;
    }

    int i;

    /*print the first (length-1) elements.seprated by space.*/
    for(i=0;i<length-1;i++)
    {
        printf("%d ",*(array+i));
    }
    /*print the last element, and begin a new line.*/
    printf("%d\n",*(array+length-1));

    return 1;
}


/*Move the elements of array between start and end(not include end) to right,
 *which start and end is the index of array.*/
int _rshift(int *array,int length,int start,int end)
{
    if(end >= length || start < 0){
        return 0;
    }
    else{
        int i;
        for(i=end;i > start; i--){
            *(array+i)=*(array+i-1);
        }
        return 1;
    }

}

/*Initilize an array with the number 'init'.*/
int _initialize(int *array,int length,int init)
{
    int i;
    for(i=0;i<length;i++){
        *(array+i) = init;
    }
    return 1;
}

#ifdef TEST
int main(int argc, const char *argv[])
{
    int array[10]={1,3,3,4,5,6,7,8,9,10};
    _rshift(array,10,0,0);
    print_1array(array,10);
    return 0;
}

#endif /*DEBUG*/
