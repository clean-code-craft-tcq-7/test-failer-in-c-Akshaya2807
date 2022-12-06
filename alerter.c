#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

typedef enum
{
   Production,
   Test
}Environment;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius<=200)
    {
     return 200;
     }
    else
    {
     return 500;
    }
}

int networkAlertProduction(float celcius){
  if(celcius<=200)
  {
     return 200;
  }
  else
  {
    return 500;
  }
}  

float SelectAlertEnvironment(float celcius, Environment environment_e)
{
    float calculated_Value;
   if(environment_e == Production)
   {
     calculated_Value = networkAlertProduction(celcius);
   }
   else
   {
     calculated_Value = networkAlertStub(celcius);
   }
   return calculated_Value;
}
    
float convertfarenheittocelcius(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit,Environment environment_e) {
    float celcius  = convertfarenheittocelcius(farenheit);
    int returnCode = SelectAlertEnvironment(celcius,environment_e);
    if (returnCode != 200) {
     alertFailureCount +=1;
    }
}

int main() {
    alertInCelcius(380.5,Test);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6,Production);
    assert(alertFailureCount == 0);
    alertInCelcius(515.5,Production);
    assert(alertFailureCount == 1);
    alertInCelcius(515.5,Test);
    assert(alertFailureCount == 2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
