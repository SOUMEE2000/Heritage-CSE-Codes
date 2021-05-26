#include <stdio.h>

int main()
{
    int x1, x2, y1, y2;
    printf("Enter first complex no ");
    scanf("%d%d",&x1,&y1);
    printf("Enter second complex no ");
    scanf("%d%d",&x2,&y2);
    
    printf("Addition of the two numbers is %d + (%d)i\n",(x1+x2),(y1+y2));
    printf("Subtraction of the two numbers is %d + (%d)i\n",(x1-x2),(y1-y2));
    printf("Addition of the two numbers is %d + (%d)i\n",(x1*x2-y1*y2),(x1*y2+y1*x2));    

    return 0;
}
