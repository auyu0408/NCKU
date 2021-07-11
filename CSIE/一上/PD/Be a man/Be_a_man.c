#include<stdio.h>
#include<math.h>

int main(){
    int year,high,weight;
    double BMI,h;
    scanf("%d%d%d",&year,&high,&weight);
    h=(double)high/100;
    BMI=weight/pow(h,2);
    printf("Age = %d\nHeight = %dcm\nWeight = %dkg\n",2021-year,high,weight);
    printf("BMI = %.1f\n",BMI);
    BMI=BMI+0.05;
    if(2021-year<19||2021-year>36)
    {
        printf("Not a Draftee (age < 19 or age > 36 years old)\n");
        printf("No need to perform Military Service");
    }
    else if(17<=BMI&&BMI<=31)
    {
        printf("Physical Status of Regular Service Draftees\n");
        if(year>1994) printf("4 months of Regular Service");
        else printf("1 year of Regular Service");
    }
    else if(BMI>=16.5&&BMI<17||BMI>31&&BMI<=31.5)
    {
        printf("Physical Status of Substitute Service Draftees\n");
        if(year<1994) printf("Substitute Services");
        else printf("Replacement Service");
    }
    else
    {
        printf("Physical Status of Military Service Exemption\n");
        printf("Exemption from Military Service");
    }
    return 0;
}