// Insertion Sort 

    int n=7;
    int a[10]={17,5,38,73,15,91,42};
    int i, j,y ;
    for(i=0 ; i<n ; i++)
    {
        y=a[i];
        j=i-1;
        while(j>=0 && a[j]>y)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=y;
    }
for(i=0 ; i<n ; i++)
{
    printf("%d  ,",a[i]); 
}
 
 
 //Bubble Sort
 
  int n=7;
    int a[10]={17,5,38,73,15,91,42};
    int i, j,y ;
    for(i=0 ; i<n ; i++)
    {
       for(j=0 ; j<n-i-1 ; j++)
       {
           if(a[j+1]<a[j])
           {
               y=a[j+1];
               a[j+1]=a[j];
               a[j]=y;
           }
       }
    }
for(i=0 ; i<n ; i++)
{
    printf("%d  ,",a[i]); 
} 
    return 0;
   
}
