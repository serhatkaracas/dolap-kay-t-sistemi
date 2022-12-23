#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	while (1)
	{
		FILE* dosya;
		char metin[100];
		int j=0,i=0,durum=0,parola=0,sifre=0,dolapsayisi=0,onay=0;
		int dizi[10000]={0};
		char dolap[10000][64];
		void dolulari_gosterme() /*Tam sayý deðer dönen ve parametre içermeyen bir fonksiyon*/
		{
			for (i=1;i<dolapsayisi+1;i++) 
			{
				if (dizi[i]==1)
					printf("%d. dolap: %s, ",i,dolap[i]);
			}
		printf("\nEsyalarini almadan gidenler varsa dolap numaralarina gore yukarida yazmaktadir.\n");
		}
		int kod_belirleme(int kod,int altsinir) /*Tam sayý deðer dönen ve tam sayý türünde parametre girdisi olan bir fonksiyon*/
		{
			for (kod=0;kod<altsinir;)
			{
				scanf("%d",&kod);
				if (kod<altsinir)
					printf("istenilen sartlara uymuyor. Lutfen sartlara uygun olacak sekilde tekrar giriniz.\n");		
				else if (kod>=altsinir)
				{
					printf("%d olarak olusturuldu.\n",kod);
					return kod;
				}		
			}	
		}
		void hata(int i) /*Deðer dönmeyen ve tam sayý türünde parametre girdisi olan bir fonksiyon*/
		{
			if (i>dolapsayisi||i<1)
				printf("%d. dolap diye bir dolap yok, lutfen tekrar secim yapiniz.\n",i);	
		}		
		printf("Mevcut dolap sayisini yazar misiniz?\n");
		scanf("%d", &dolapsayisi);
		for (i=0;i<dolapsayisi+1; i+=2)
		{
			strcpy(dolap[i], "bos");     
    		strcpy(dolap[i+1], dolap[i]);
		}		
		printf("Dolaplari kullanan kisileri gosterecek en az 6 haneli sifreyi belirleyiniz.\n");
		sifre=kod_belirleme(sifre,100000);	
		printf("Mesai bitip tum dolaplar bosaltiginda kullanilacak sifreden buyuk sifirlama parolasini belirleyiniz.\n");
		parola=kod_belirleme(parola,sifre+1);
		while (1)
		{
			dosya=fopen("yazi.txt","w");/*Dosyaya yazdýrma*/
			for(i=1;i<dolapsayisi+1;i++)
			{	
				fprintf(dosya,"%d. dolap: %s\n",i,dolap[i]);
			}
			fclose(dosya);
			int bosVarmi=0;
			printf("Giris icin 1, cikis icin 2'ye basiniz.\n");
			scanf("%d",&durum);
			if (durum == 1)
			{
				for (i=1;i<dolapsayisi+1;i++)
				{
					if (dizi[i]==0)
					{
						printf("%d,",i);
						bosVarmi=1;
					}
				}
				if(bosVarmi == 1)
				{
					printf("\nBos olan dolaplar yukarida yazmaktadir. Istediginizi seciniz.\n");
					scanf("%d",&i);
					if (dizi[i]==0&&i<=dolapsayisi&&i>0)
					{
						printf("Ad ve soyadinizi yaziniz.\n");
						gets(dolap[i]);
						gets(dolap[i]);
						dizi[i]=1;
						printf("%d. dolap: %s\n",i,dolap[i]);
					}							
					else if (dizi[i]!=0)
						printf("%d. dolap dolu tekrar secim yapiniz.\n",i);	
					hata(i);				
				}
			else if (bosVarmi == 0)
					printf("Maalesef bos dolap kalmadi lutfen biri cikis yapana kadar bekleyiniz.\n");	
			}
			else if (durum == 2)
			{
				printf("Bosaltiginiz dolabi yaziniz\n");
				scanf("%d", &i);
				if (dizi[i]==1&&i<=dolapsayisi&&i>0)
				{
					printf("Adiniz %s, dogru mu? Dogruysa 1'e degilse herhangi bir rakama basiniz.\n",dolap[i]);
					scanf("%d",&onay);
					if (onay==1)
					{
						dizi[i]=0;
						strcpy(dolap[i],"bos");
						printf("%d. dolap: %s, \n",i,dolap[i]);
						bosVarmi = 1;
					}	
					else
						printf("%d. dolap size ait degil lutfen tekrar secim yapiniz.\n",i);	
				}
				else if(dizi[i]!=1&&i<=dolapsayisi&&i>0)
						printf("%d. dolap zaten bos tekrar secim yapiniz.\n",i);
				hata(i);		
			}
			else if (durum==sifre)
				dolulari_gosterme();
			else if (durum == parola)
			{
				dolulari_gosterme();
				printf("Mesai bitti, hoscakalin.\n");
				break;
			}
		else if (durum!=sifre||1||2||parola)
			printf("Yanlis tuslama yaptiniz.\n");			
		}	
	}
return 0;
}
