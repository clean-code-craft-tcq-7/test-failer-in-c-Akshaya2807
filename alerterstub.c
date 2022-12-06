#include <stdio.h>
#include <assert.h>
#include "alerterstub.h"

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
