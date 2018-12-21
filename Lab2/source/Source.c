#include <stdio.h>
#include <stdlib.h>

struct clientData
{
	int acctNum;
	char lasrName[15];
	char firstName[10];
	double balance;
};

int main()
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int a,b,cnt = 0;
	struct clientData client = { 0,"","",0.0 };
	
	a = fopen_s(&pRead, "C://Users/User/Desktop/gradedata.txt", "r");
	if (pRead == NULL)
		return 0;


	b = fopen_s(&pWrite, "C://Users/User/Desktop/gradeoutput.txt", "wb");
	if (pWrite == NULL)
	{
		fclose(pRead);
		return 0;
	}

	while (!feof(pRead))
	{
		fscanf_s(pRead, "%d", &client.acctNum);

		fscanf_s(pRead, "%s",client.lasrName,10);
		fscanf_s(pRead, "%s",client.firstName,10);
		fscanf_s(pRead, "%1f",&client.balance);

		





		fwrite(&client, sizeof(struct clientData), 1, pWrite);
		
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lasrName, client.firstName, client.balance);

	}


	fclose(pRead);
	fclose(pWrite);
	printf("已讀取文字檔的ACSII資料,並轉存成二進位資料檔案\n\n");
	system("pause");

	printf("\n讀取二進位資料檔案,並格式化輸出如下:\n");
	if ((cfPtr = a) == NULL)
		printf("File Could not be opened.\n");
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Last Name", "First Name", "Balance");

		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);

		while (cnt>0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lasrName, client.firstName, client.balance);

			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);
	}

	system("pause");
	return 0;

}