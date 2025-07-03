#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4
#define M 10
int memory[M][N];
int R1[N];
int R2[N];
void boot()
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			memory[i][j] = rand() % 2;
		}
	}
	for (i = 0; i < N; i++)
	{
		R1[i] = rand() % 2;
		R2[i] = rand() % 2;
	}
}
int loadR1(int address)
{
	int i;
	if (address >= 0 && address < 10)
	{
		for (i = 0; i < N; i++)
		{
			R1[i] = memory[address][i];
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
int loadR2(int address)
{
	int i;
	if (address >= 0 && address < 10)
	{
		for (i = 0; i < N; i++)
		{
			R2[i] = memory[address][i];
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
int storeR1(int address)
{
	int i;
	if (address >= 0 && address < 10)
	{
		for (i = 0; i < N; i++)
		{
			memory[address][i] = R1[i];
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
int storeR2(int address)
{
	int i;
	if (address >= 0 && address < 10)
	{
		for (i = 0; i < N; i++)
		{
			memory[address][i] = R2[i];
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
void addRegistersR1()
{
	int dec1 = 0;
	int dec2 = 0;
	int i, j = 8;
	for (i = 0; i < N; i++)
	{
		dec1 += R1[i] * j;
		dec2 += R2[i] * j;
		j /= 2;
	}
	int s = dec1 + dec2;
	if (s > 15)
	{
		for (i = 0; i < N; i++)
		{
			R1[i] = 0;
		}
	}
	else
	{
		for (i = N - 1; i >= 0; i--)
		{
			R1[i] = s % 2;
			s /= 2;
		}
	}
}
void addRegistersR2()
{
	int dec1 = 0;
	int dec2 = 0;
	int i, j = 8;
	for (i = 0; i < N; i++)
	{
		dec1 += R1[i] * j;
		dec2 += R2[i] * j;
		j /= 2;
	}
	int s = dec1 + dec2;
	if (s > 15)
	{
		for (i = 0; i < N; i++)
		{
			R2[i] = 0;
		}
	}
	else
	{
		for (i = N - 1; i >= 0; i--)
		{
			R2[i] = s % 2;
			s /= 2;
		}
	}
}
void subRegistersR1()
{
	int dec1 = 0;
	int dec2 = 0;
	int i, j = 8;
	for (i = 0; i < N; i++)
	{
		dec1 += R1[i] * j;
		dec2 += R2[i] * j;
		j /= 2;
	}
	int s = dec1 - dec2;
	if (s < 0)
	{
		for (i = 0; i < N; i++)
		{
			R1[i] = 1;
		}
	}
	else
	{
		for (i = N - 1; i >= 0; i--)
		{
			R1[i] = s % 2;
			s /= 2;
		}
	}
}
void subRegistersR2()
{
	int dec1 = 0;
	int dec2 = 0;
	int i, j = 8;
	for (i = 0; i < N; i++)
	{
		dec1 += R1[i] * j;
		dec2 += R2[i] * j;
		j /= 2;
	}
	int s = dec2 - dec1;
	if (s < 0)
	{
		for (i = 0; i < N; i++)
		{
			R1[i] = 1;
		}
	}
	else
	{
		for (i = N - 1; i >= 0; i--)
		{
			R1[i] = s % 2;
			s /= 2;
		}
	}
}
void displayR1()
{
	int i;
	printf("o kataxwriths R1 einai:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d", R1[i]);
	}
	printf("\n");
}
void displayR2()
{
	int i;
	printf("o kataxwriths R2 einai:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d", R2[i]);
	}
	printf("\n");
}
void displayMemory()
{
	int i, j;
	printf("H mnhmh einai \n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d", memory[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//metatropi protashs se diaforetikes lexeis
void wordsAdd(char entolh[], char word1[], char word2[], char word3[], char keno)
{
	int i;
	int countWord = 0, word1count = 0, word2count = 0, word3count = 0;
	strcpy(word1, "");
	strcpy(word2, "");
	strcpy(word3, "");

	for (i = 0; i < strlen(entolh); i++)
	{
		if (entolh[i] != keno)
		{
			if (countWord == 0)
			{
				word1[word1count++] = entolh[i];
			}
			else if (countWord == 1)
			{
				word2[word2count++] = entolh[i];
			}
			else
			{
				word3[word3count++] = entolh[i];
			}
		}
		else
		{
			countWord++;
		}
	}
	word1[word1count] = '\0';
	word2[word2count] = '\0';
	word3[word3count] = '\0';
}
int main()
{
	int i, address;
	char entolh[50], word1[50], word2[50], word3[50];
	char keno = ' ';
	while (1)
	{
		printf("Grapse thn entolh pou thes:\n");
		gets(entolh);
		wordsAdd(entolh, word1, word2, word3, keno);
		if (strcmp(word1, "BOOT") == 0)
		{
			boot();
			printf("To bootarisma oloklhrwthike!");
			printf("\n");
		}
		else if (strcmp(word1, "LOAD") == 0)
		{
			if (strlen(word3) != 1)
			{
				printf("H diefthinsi pou dwsate den yparxei!");
				printf("\n");
			}
			else
			{
				int address = word3[0] - '0';
				if (strcmp(word2, "R1") == 0)
				{
					int load1 = loadR1(address);
					if (load1 == 0)
					{
						printf("H diefthinsi pou dwsate den yparxei!");
						printf("\n");
					}
					else
					{
						printf("H fortwsh sto R1 oloklhrwthike!");
						printf("\n");
					}
				}
				else if (strcmp(word2, "R2") == 0)
				{
					int load2 = loadR2(address);
					if (load2 == 0)
					{
						printf("H diefthinsi pou dwsate den yparxei!");
						printf("\n");
						break;
					}
					else
					{
						printf("H fortwsh sto R2 oloklhrwthike!");
						printf("\n");
					}
				}
				else
				{
					printf("Den dwsate swsto register!");
					printf("\n");
				}
			}
		}
		else if (strcmp(word1, "STORE") == 0)
		{
			if (strlen(word3) != 1)
			{
				printf("H diefthinsi pou dwsate den yparxei!");
				printf("\n");
				break;
			}
			else
			{
				int address = word3[0] - '0';
				if (strcmp(word2, "R1") == 0)
				{
					int store1 = storeR1(address);
					if (store1 == 0)
					{
						printf("H diefthinsi pou dwsate den yparxei!");
						printf("\n");
					}
					else
					{
						printf("H fortwsh sth mnhmh apo to R1 oloklhrwthike!");
						printf("\n");
					}
				}
				else if (strcmp(word2, "R2") == 0)
				{
					int store2 = storeR2(address);
					if (store2 == 0)
					{
						printf("H diefthinsi pou dwsate den yparxei!");
						printf("\n");
					}
					else
					{
						printf("H fortwsh sth mnhmh apo to R2 oloklhrwthike!");
						printf("\n");
					}
				}
				else
				{
					printf("Den dwsate swsto register!");
					printf("\n");
				}
			}
		}
		else if ((strcmp(word1, "ADD") == 0))
		{
			if (strcmp(word2, "R1") == 0)
			{
				addRegistersR1();
				printf("H prosthesi twn R1 kai R2 sto R1 oloklhrwthike!");
				printf("\n");
			}
			else if (strcmp(word2, "R2") == 0)
			{
				addRegistersR2();
				printf("H prosthesi twn R1 kai R2 sto R2 oloklhrwthike!");
				printf("\n");
			}
			else
			{
				printf("Den dwsate swsto register!");
				printf("\n");
			}
		}
		else if ((strcmp(word1, "SUB") == 0))
		{
			if (strcmp(word2, "R1") == 0)
			{
				subRegistersR1();
				printf("H afairesh twn R1 kai R2 sto R1 oloklhrwthike!");
				printf("\n");
			}
			else if (strcmp(word2, "R2") == 0)
			{
				subRegistersR2();
				printf("H afairesh twn R1 kai R2 sto R2 oloklhrwthike!");
				printf("\n");
			}
			else
			{
				printf("Den dwsate swsto register!");
				printf("\n");
			}
		}
		else if ((strcmp(word1, "SHOW") == 0))
		{
			if (strcmp(word2, "R1") == 0)
			{
				displayR1();
			}
			else if (strcmp(word2, "R2") == 0)
			{
				displayR2();
			}
			else
			{
				printf("Den dwsate swsto register");
			}
		}
		else if ((strcmp(word1, "MEM") == 0))
		{
			displayMemory();
		}
		else if ((strcmp(word1, "STOP") == 0))
		{
			break;
		}
		else
		{
			printf("Den yparxei tetoia entoli");
		}
	}
	return 0;
}
