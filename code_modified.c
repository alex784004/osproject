#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t r1,r3,r2,r4,mut;
struct direction
{
    int o;
    int d;
};
int origin=0,destination=0;

void *p1(struct direction *s1)
{    //   sem_wait(&mut);
        if(s1->d==3)//north to south
            {
            sem_wait(&r3);
          sem_wait(&r2);
sleep(5);
            sem_post(&r3);
            
             sem_post(&r2);
            printf("car travelled from north to south\n");


            }
        else if(s1->d==4)//north to west
            {
            sem_wait(&r1);
     sem_wait(&r2);
            sem_wait(&r3); 
sleep(5);  
               sem_post(&r1);
          
            sem_post(&r2);
            
              sem_post(&r3);                      

            printf("car travelled from north to west\n");
            }
        else if(s1->d==2)//north to east
            {
              sem_wait(&r2);
              sleep(5);
              sem_post(&r2);

            printf("car travelled from north to east\n");
            }

//sem_post(&mut);
    
    
}
void *p2(struct direction *s1)
{
  //  sem_wait(&mut);
       if(s1->d==4)//east to west
           {
            sem_wait(&r3);
   sem_wait(&r4);            

 sleep(5);
            sem_post(&r3);
         
                   sem_post(&r4);

            printf("car travelled from east to west\n");
              
            }
        else if(s1->d==1)//east to north
            {
            sem_wait(&r4);
 sem_wait(&r3);           
 sem_wait(&r1);
 sleep(5);
            sem_post(&r4);
           
         
            sem_post(&r3);
           
                     sem_post(&r3);
            printf("car travelled from east to north\n");

            }
         else if(s1->d==3)//east to south   
            {
             sem_wait(&r3);
             sleep(5);
             sem_post(&r3);
            printf("car travelled from east to south\n");

            }  

// sem_post(&mut);
}
   
void *p3(struct direction *s1)
{
  // sem_wait(&mut);
 
        if(s1->d==1)//south to north
        {
            sem_wait(&r1);
   sem_wait(&r4);
                  
   sleep(5);
            sem_post(&r1);   
      
            sem_post(&r4);
            printf("car travelled from south to north\n");

        }
        else if(s1->d==2)//south to east
        {
            sem_wait(&r4);
            sem_wait(&r1);
     sem_wait(&r2);
            sleep(5); 
            sem_post(&r4);            
           
            sem_post(&r1);
    
            sem_post(&r2);
            printf("car travelled from south to east\n");
         }
         else if(s1->d==4)//south to west
         {
            sem_wait(&r4);
            sleep(5);
            sem_post(&r4);
            printf("car travelled from south to west\n");
         }
    
  // sem_post(&mut);
    }  
void *p4(struct direction *s1)
{
   
  //  sem_wait(&mut);
        if(s1->d==2) //west to east
        {
            sem_wait(&r1);
            sem_wait(&r2);
          sleep(5);
            sem_post(&r1);      
          
            sem_post(&r2);
            printf("car travelled from west to east\n");
        }
        else if(s1->d==3)//west to south
        {
            sem_wait(&r3);
            sem_wait(&r2);
            sem_wait(&r1);
           sleep(5);
            sem_post(&r3);            
         
            sem_post(&r2);            
                   sem_post(&r1);            

            printf("car travelled from west to south\n");
          }
         else if(s1->d==1)//west to north
          {
            sem_wait(&r1);
            sleep(5);
            sem_post(&r1);
          
            printf("car travelled from west to north\n");
          }
 
  //          sem_post(&mut);
          }



int main()
{
    
        sem_init(&r1,0,1);
    sem_init(&r2,0,1);
    sem_init(&r3,0,1);
   sem_init(&r4,0,1);
   sem_init(&mut,0,1);
pthread_t arr[10];
    
 printf("north is 1\n");

        printf("east is 2\n");

        printf("south is 3\n");
        
        printf("west is 4\n");



for(int i=0;i<4;i++)
    {
        struct direction *s2= malloc(sizeof(struct direction));
      
  //      printf("enter the origin direction\n");
        scanf("%d",&(s2->o));
      
    //    printf("enter the destination direction\n");
        scanf("%d",&(s2->d));
           
        if(s2->o==1)
               {
                pthread_create(arr+i,NULL,p1,(void *)s2);
               }
        else if(s2->o==2)
               {
                pthread_create(arr+i,NULL,p2,(void *)s2);
                } 
 
        else if(s2->o==3)
                {
                pthread_create(arr+i,NULL,p3,(void *)s2);
                }
        else if(s2->o==4)
                {
                pthread_create(arr+i,NULL,p4,(void *)s2);
                }
        

        
       } 
         for(int i=0;i<4;i++)
              pthread_join(*(arr+i),NULL); 
    
}
