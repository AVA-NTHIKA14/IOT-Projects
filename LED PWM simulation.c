#include <stdio.h>
#include <unistd.h>   
#include <time.h>

int main()
 {
    float frequency, dutyCycle;

    printf("Enter PWM frequency in Hz: ");
    scanf("%f", &frequency);

    if (frequency<=0)
     {
        printf("Invalid frequency! Must be > 0.\n");
        return 1;
     }

    printf("Enter duty cycle (0 to 100): ");
    scanf("%f", &dutyCycle);

    if (dutyCycle < 0 || dutyCycle > 100) 
   {
        printf("Invalid duty cycle! Must be between 0 and 100.\n");
        return 1;
    }

    
    float period = 1.0f / frequency;              
    float onTime = period * (dutyCycle / 100.0f); 
    float offTime = period - onTime;               

    printf("\nSimulating PWM for 10 seconds...\n\n");

   
    time_t start = time(NULL);

    while (time(NULL) - start < 10)
    {
       
        if (onTime > 0)
         {
            printf("LED ON\n");
            usleep(onTime * 1000000); 
         }
      
        if (offTime > 0) 
        {
            printf("LED OFF\n");
            usleep(offTime * 1000000);
        }
        

    printf("\nSimulation complete!\n");
    return 0;
   }
}
