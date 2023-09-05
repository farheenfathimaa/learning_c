/*write a c program for generating and verifying hamming code for 7 bit, 12 bit and 15 bits of data.*/
#include<stdio.h>
int main(){
    int n,i,a[20],p[20],p0,p1,p3,p7,t;
    printf("Enter the number of bits: ");
    scanf("%d",&n);
    switch(n){
        case 7: printf("Enter the data: ");
                for(i=0;i<n;i++){
                    if(i==0||i==1||i==3)
                    continue;
                    scanf("%d",&a[i]);
                    }
                a[0]=a[2]^a[4]^a[6];
                a[1]=a[2]^a[5]^a[6];
                a[3]=a[4]^a[5]^a[6];
                printf("Hamming code generated is :");
                for(i=0;i<n;i++)
                printf("%d",a[i]);
                p0=a[0]^a[2]^a[4]^a[6];
                p1=a[1]^a[2]^a[5]^a[6];
                p3=a[3]^a[4]^a[5]^a[6];
                if((p0==0)&&(p1==0)&&(p3==0))
                printf("\nNo error detected\n");
                else{
                 t=(p3*4)+(p1*2)+(p0*1);
                 printf("Error detected at position :%d\n",t);
    }
    if(a[t-1]==0)
    a[t-1]=1;
    else
    a[t-1]=0;
    for(i=0;i<7;i++)
    printf("%d",a[i]);  
                break;
        case 12: printf("Enter the data: ");
                for(i=0;i<n;i++){
                    if(i==0||i==1||i==3||i==7)
                    continue;
                    scanf("%d",&a[i]);
                }
                a[0]=a[2]^a[4]^a[6]^a[8]^a[10];
                a[1]=a[2]^a[5]^a[6]^a[9]^a[10];
                a[3]=a[4]^a[5]^a[6]^a[11];
                a[7]=a[8]^a[9]^a[10]^a[11];
                printf("Hamming code generated is :");
                for(i=0;i<n;i++)
                printf("%d",a[i]);
                printf("\nError identification\n");
                p0=a[0]^a[2]^a[4]^a[6]^a[8]^a[10];
                p1=a[1]^a[2]^a[5]^a[6]^a[9]^a[10];
                p3=a[3]^a[4]^a[5]^a[6]^a[11];
                p7=a[8]^a[9]^a[10]^a[11];
                if((p0==0)&&(p1==0)&&(p3==0)&&(p7==0))
                printf("\nNo error detected\n");
                else{
                 t=(p7*8)+(p3*4)+(p1*2)+(p0*1);
                 printf("Error detected at position :%d\n",t);
    }
    if(a[t-1]==0)
    a[t-1]=1;
    else
    a[t-1]=0;
    for(i=0;i<12;i++)
    printf("%d",a[i]);  
                break;
        case 15: printf("Enter the data: ");
                for(i=0;i<n;i++){
                    if(i==0||i==1||i==3||i==7)
                    continue;
                    scanf("%d",&a[i]);
                
}
                a[0]=a[2]^a[4]^a[6]^a[8]^a[10]^a[12]^a[14];
                a[1]=a[2]^a[5]^a[6]^a[9]^a[10]^a[13]^a[14];
                a[3]=a[4]^a[5]^a[6]^a[11]^a[12]^a[13]^a[14];
                a[7]=a[8]^a[9]^a[10]^a[11]^a[12]^a[13]^a[14];
                printf("Hamming code generated is :");
                for(i=0;i<n;i++)
                printf("%d",a[i]);
                printf("\nError identification\n");
                p0=a[0]^a[2]^a[4]^a[6]^a[8]^a[10]^a[12]^a[14];
                p1=a[1]^a[2]^a[5]^a[6]^a[9]^a[10]^a[13]^a[14];
                p3=a[3]^a[4]^a[5]^a[6]^a[11]^a[12]^a[13]^a[14];
                p7=a[8]^a[9]^a[10]^a[11]^a[12]^a[13]^a[14];
                if((p0==0)&&(p1==0)&&(p3==0)&&(p7==0))
                printf("\nNo error detected\n");
                else{
                 t=(p7*8)+(p3*4)+(p1*2)+(p0*1);
                 printf("\nError detected at position :%d\n",t);
    }
    if(a[t-1]==0)
    a[t-1]=1;
    else
    a[t-1]=0;
    for(i=0;i<15;i++)
    printf("%d",a[i]); 
                break;
        default:printf("invalid size.\n");
    }
    
    return 0;
}
