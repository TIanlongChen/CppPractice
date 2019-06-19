#include <iostream>
using namespace std;

const float LOWERLIMIT = 0;
const float UPPERLIMIT = 50000;

float askLowerLimit(){
    float lower;
    cout<<"Please give a lower limit, limit >= "<< LOWERLIMIT;
    cin>> lower;
    return lower;
}

float askHigerLimit(){
    float higer;
    cout<<"Please give a higer limit, limit <= "<< UPPERLIMIT;
    cin>> higer;
    return higer;
}
float askStepSize(){
  float stepsize;
    cout<<"Please give in a step, 0 < step <= 10"<< LOWERLIMIT;
    cin>> stepsize;
    return stepsize;
}
float barricadeLowerInput(){
    float lower;
    do{
        lower = askLowerLimit();
        if(lower < LOWERLIMIT)
            cout<<"Start temperature is too low"<<endl;
        if(lower > UPPERLIMIT)
            cout<<"Start temperature is too high"<<endl;
    }
    while(lower < LOWERLIMIT);
    return lower;
}
float barricadeHigerInput(float lower){
    float higer;
    do{
        higer = askHigerLimit();
        if(higer > UPPERLIMIT)
            cout<<"End temperature is too high"<<endl;
        if(higer < lower)
            cout<<"End temperature is lower than start temprature"<<endl;
    }
    while(higer > UPPERLIMIT);
    return higer;
}

float barricadeStepSize(float startTemp, float endTemp){
    float stepSize;
    do{
        stepSize = askStepSize();
        if(stepSize > (endTemp - startTemp) )
            cout<<"Step size is too big, should be lower than the difference between start and end temperature"<<endl;
    }
    while(stepSize > (endTemp - startTemp));
    return stepSize;
}



float CelciusToFerehei(float Celcius){
    return Celcius/5*9;
}

int main(){
    float lower,higer,stepsize;
    lower = barricadeLowerInput();
    higer = barricadeHigerInput(lower);
    stepsize = barricadeStepSize(lower,higer);
    float currentStep = lower;
    cout<<"C              F"<<endl;
    cout<<"================="<<endl;

    while(currentStep <= higer){
    cout<< currentStep<<"      "<< CelciusToFerehei(currentStep)<<endl;
    currentStep += stepsize;
    }
}

