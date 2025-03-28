#include<stdio.h> 
#include<stdlib.h> 
void main() 
{ 
    int q[100],n,seek=0,i,cur,prev,j,m,cyl,loc;     
    float avg; 
    printf("Enter the no. of Cylinders: ");     
    scanf("%d",&cyl);     
    printf("Cylinders: 0 to %d\n",cyl-1);    
    printf("Enter the Queue Size: ");     
    scanf("%d",&m);     
    n=m+1; 
    printf("Enter the Queue: "); 
    for(i=1;i<n;i++)        
    scanf("%d",&q[i]);    
    printf("Enter Current Head Position: ");     
    scanf("%d",&cur);     
    q[0]=cur; 
    printf("Enter Previous Head Position: ");     
    scanf("%d",&prev);        
    for(i=1;i<n;i++)         
    for(j=0;j<n-i;j++)             
    if(q[j]>q[j+1]) 
    {                 
    int temp=q[j];                 
    q[j]=q[j+1]; 
    q[j+1]=temp; 
    } 
    printf("Displaying Requests in Order...\n"); 
    for(i=0;i<n;i++)         
    printf("%d\t",q[i]);     
    for(i=0;i<n;i++)         
    if(q[i]==cur) 
    {             
    loc=i; 
    break; 
    } 
    if(cur<prev) 
    { 
        printf("\n\nScanning towards left...then restart at right end\n");         
        for(i=loc;i>=0;i--)  
 	printf("%d --> ",q[i]);  	    
 	printf("0 --> ");         
 	printf("%d --> ",cyl-1); 
        for(i=n-1;i>loc;i--)  
 	printf("%d --> ",q[i]); 
        seek=cur+2*(cyl-1)-q[loc+1]; 
    }     
    else 
    { 
        printf("\n\nScanning towards right...then restart at left end\n");       
        for(i=loc;i<n;i++)  
        printf("%d --> ",q[i]); 
 	printf("%d --> ",cyl-1); 
        printf("0 --> "); 
        for(i=0;i<loc;i++)  
        printf("%d --> ",q[i]);         
        seek=2*(cyl-1)-cur+q[loc-1]; 
    } 
    printf("\n\nTotal Seek Distance: %d\t",seek);     
    avg=(float)seek/(n+1); 
    printf("\nAverage Seek Distance: %.3f\t",avg); 
}  
