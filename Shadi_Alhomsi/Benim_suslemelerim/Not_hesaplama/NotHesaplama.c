#include <stdio.h>
#include <stdlib.h>

int main()
{
  int quiz, vize, finel, ders, lab, odev;
  float ort, quiz1, vize1, finel1, lab1, odev1;

  while (1){

  printf("lutfen Notunu hesaplamak istediginiz dersi secin\n");
  printf("1-fizik\n");
  printf("2-MATEMATIK ");
  scanf("%d",&ders);
  system("cls || clear");


  switch(ders){
  case 1:
  printf("Fizikte odev notunu gir : ");
  scanf("%d",&odev);
  odev1 = odev *0.1;

  printf("Fizikte lab notunu gir : ");
  scanf("%d",&lab);
  lab1 = lab *0.05;

  printf("Fizikte quiz notunu gir : ");
  scanf("%d",&quiz);
  quiz1 = quiz *0.05;

  printf("Fizikte vize notunu gir : ");
  scanf("%d",&vize);
  vize1 = vize* 0.3;

  printf("Fizikte final notunu gir : ");
  scanf("%d",&finel);
  finel1 = finel* 0.5;

  ort = vize1+quiz1+finel1+odev1+lab1 ;
  printf("ortalamaniz = %f \n",ort);


  if (ort<=100 && ort>=90){
    printf("Tebrikler fizigi A ile gectiniz \n");
    break;
  }

  else if(ort>=80)
  {
      printf("fizigi B ile gectiniz \n");
    break;
  }

  else if(ort>=70)
  {
      printf("fizigi C ile gectiniz \n");
    break;
  }

    else if(ort>=50)
  {
      printf("fizigi D ile gectiniz \n");
    break;
  }

  else if(ort>=0)
  {
      printf("Maalesef fizikten kaldiniz \n");
    break;
  }

  else{
    printf("lutfen 0ile100 arasi sayi giriniz\n");
    break;
  }

  case 2:
      printf("Matematik quiz notunu gir : ");
  scanf("%d",&quiz);
  quiz1 = quiz *0.1;

  printf("Matematik vize notunu gir : ");
  scanf("%d",&vize);
  vize1 = vize* 0.4;

  printf("Matematik final notunu gir : ");
  scanf("%d",&finel);
  finel1 = finel* 0.5;

  ort = vize1+quiz1+finel1 ;
  printf("ortalamaniz = %f \n",ort);


  if (ort<=100 && ort>=90){
    printf("Tebrikler matematigi A ile gectiniz \n");
    break;
  }

  else if(ort>=80)
  {
      printf("matematigi B ile gectiniz \n");
    break;
  }

  else if(ort>=70)
  {
      printf("matematigi C ile gectiniz \n");
    break;
  }

    else if(ort>=50)
  {
      printf("matematigi D ile gectiniz \n");
    break;
  }

  else if(ort>=0)
  {
      printf("Maalesef matematikten kaldiniz \n");
    break;
  }

  else{
    printf("lutfen 0ile100 arasi sayi giriniz\n");
    break;
  }

  default :
      system("cls || clear");
      printf("*Lutfen gecerli bir sayi giriniz*\n");

      while (getchar() != '\n'); // yanlış girişi temizle
    continue;
    }
  }

  return 0;
}
