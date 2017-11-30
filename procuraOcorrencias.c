#include <string.h>
#include <stdio.h>


// procura quantas ocorrencias de STR1 existem  em STR2
// tanto STR1 quanto STR2 nao podem conter espacosno meio ao serem fornecidas no terminal


int stradd(char *str1, char c, int len)// adiciona o caractere 'c' no final de str1 respeitando seu tamanho máx.
{
	int fim = strlen(str1);
	
	if ((len-fim)<2)
	{
		printf("str1 no tamanho maximo.\n");
		return 0;
	}
	str1[fim]=c;
	str1[fim+1]='\0';
	return 1;

}

int compara (char *str1, char *str2, int dif, int len1)
{
	int i, j,aux,contador=0;
	for(i=0;i<=dif;i++)// i =  indice de string2
	{
		aux=-len1+1;
		for(j=0;j<len1;j++)// j indice da string1
		{				
			if(str1[j]==str2[i+j]) aux++;

			else
			{
				aux=0;
				break;
			}
		}
		contador=contador+aux;
	}
		return contador;
}

int main (int argc, char *args[])
{
	if(argc<4)// se nao tiver pelo menos 4 arugumentos contado o nome do programa 
	{
		printf("Quantidade de argumentos invalidas.\n");
		return 0;
	}

	
	// concatena as string antes da virgula em STR1 , e as depois em STR2
	int len1,len2,i,j,aux;

	for(i=2;i<=argc;i++)
	{
		if(args[i][0]==',')
		{
			printf("virgula em %d\n",i);
			aux=i;
			len1=0;
			for(j=1;j<i;j++)
			{
				len1=len1 +strlen(args[j]);
				len1++;
			}

			len2=0;
			for(j=i+1;j<argc;j++)
			{
				len2=len2 +1+ strlen(args[j]);
			}
			break;
		}
	}

	char str1[len1],str2[len2+1];

	strcpy(str1,args[1]);	
	for(j=2;j<aux;j++)
	{		
		stradd(str1,' ',len1);
		strcat(str1,args[j]);
	}
	
	strcpy(str2,args[aux+1]);	
	for(j=aux+2;j<argc;j++)
	{
		stradd(str2,' ',len2);
		strcat(str2,args[j]);
	}

	//printf("str1: '%s', str2: '%s'\n",str1,str2);

	if(len1>len2)
	{
		printf("Tamanho imcompativel das strings.\n");
		return 0;
	}
	else if(len1==len2)
	{
		printf("len1==len2\n");
		printf("str1 %s , str2 %s\n",str1,str2);
	}
	
	else
	{
		int dif = len2 - len1;		
		int contador=0;
		printf("len1: %d\n",len1);
		printf("len2: %d\n",len2);
		contador=compara(str1,str2,dif,len1-1);
		printf("%d ocorrencias de '%s' em '%s'.\n",contador,str1,str2);
	}
	return 0;
}