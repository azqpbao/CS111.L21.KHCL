// Including Libraries
#include <bits/stdc++.h>
using namespace std;

int z = 0, i = 0, j = 0, c = 0;
char a[50], ac[30], stk[50], act[10];

void check()
{
	//Rule 1
	strcpy(ac,"REDUCE TO F -> ");
    //Reduction F -> (E)
	for (z = 0; z < c - 2; z++)
	{
        if(stk[z] == '(' && stk[z+1] == 'E' && stk[z+2] == ')')
		{
            printf("\n%s%s", ac, "(E)");
            stk[z] = 'F';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
            i -= 2;
			//printing action
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
		}
	}

	//Reduction F -> id
	for(z = 0; z < c - 1; z++)
	{
		if(stk[z] == 'i')
		{
			printf("\n%s%s", ac, "id");
			stk[z] = 'F';
			stk[z + 1] = '\0';
            i -= 1;
			//printing action
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
		}

	}


	//Rule 2
	strcpy(ac,"REDUCE TO S -> ");

	//Reduction S -> F
	for(z = 0; z < c ; z++)
	{
		if(stk[z] == 'F' && stk[z+1] != '^' && a[j+1] != '^')
		{
			printf("\n%s%s", ac, "F");
			stk[z] = 'S';
			stk[z + 1] = '\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
		}

	}

    //Reduction S -> F^S
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'F' && stk[z + 1] == '^' && stk[z + 2] == 'S')
		{
			printf("\n%s%s", ac, "F^S");
			stk[z]='S';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
			i = i - 2;
		}
	}


	//Rule 3
	strcpy(ac, "REDUCE TO T -> ");

    //Reduction T -> T*S
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'T' && stk[z + 1] == '*' &&
								stk[z + 2] == 'S' && a[j+1] != '^')
		{
			printf("\n%s%s", ac, "T*S");
			stk[z]='T';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
			i = i - 2;
		}
	}

    //Reduction T -> T/S
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'T' && stk[z + 1] == '/' && stk[z + 2] == 'S' && a[j+1] != '^')
		{
			printf("\n%s%s", ac, "T/S");
			stk[z]='T';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
			i = i - 2;
		}
	}

    //Reduction T -> S
	for(z = 0; z < c; z++)
	{
		if(stk[z] == 'S' && a[j+1] != '^' && stk[z+1] != '^')
		{
			printf("\n%s%s", ac, "S");
			stk[z]='T';
			stk[z + 1]='\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
		}
	}

	//Rule 4
	strcpy(ac, "REDUCE TO E -> ");

    //Reduction E -> E+T
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'T' && a[j+1] != '/' && a[j+1] != '*' && stk[z+3] != '*' && stk[z+3] != '/')
		{
			printf("\n%s%s", ac, "E+T");
			stk[z]='E';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
			i = i - 2;
		}
	}

    //Reduction E -> E-T
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'E' && stk[z + 1] == '-' && stk[z + 2] == 'T' && a[j+1] != '/' && a[j+1] != '*' && stk[z+3] != '*' && stk[z+3] != '/')
		{
			printf("\n%s%s", ac, "E-T");
			stk[z]='E';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
			i = i - 2;
		}
	}

    //Reduction E -> T
	for(z = 0; z < c; z++)
	{
		if(stk[z] == 'T' && a[j+1] != '/' && a[j+1] != '*' && stk[z+1] != '*' && stk[z+1] != '/')
		{
			printf("\n%s%s", ac, "T");
			stk[z]='E';
			stk[z + 1]='\0';
			printf("\t$%s\t\t\t%s$\t", stk, a);
            if (a[j+1] == 'i')
			{
                printf("\t\t%s", "id");
            }
            else{
                printf("\t\t%c", a[j+1]);
            }
		}
	}

	//Rule 5
        strcpy(ac, "REDUCE TO P -> ");
        //Reduction P -> E
        for(z = 0; z < c; z++)
        {
            if(stk[z] == 'E' && a[j+1] != 'i' && a[j+1] != '+' && a[j+1] != '-' && a[j+1] != '*' && a[j+1] != '/' && a[j+1] != '^')
            {
                printf("\n%s%s", ac, "E");
                stk[z]='P';
                stk[z + 1]='\0';
                printf("\t$%s\t\t\t%s$\t", stk, a);
                if (a[j+1] == 'i')
				{
                    printf("\t\t%s", "id");
                }
                else{
                    printf("\t\t%c", a[j+1]);
                }
            }
        }

	return ;
}


int main()
{
    cout << "\nGrammar rule\n";
	ifstream file;
	file.open("G.txt");
	string str;
    while (getline(file, str))
	{
        cout << str << "\n";
    }
    file.close();

    cout << "\nSentence\n";

    //Đọc câu cấu trúc để parse
    file.open("Input.txt");
    while (!file.eof()){
        file >> a;
    }
    file.close();
    cout << a;

    //Độ dài câu
	c=strlen(a);

	strcpy(act,"SHIFT");
	printf("\nLuat \t\t Chuoi parsed \t\t\t Input con lai \t\t\t Ky tu dang xet");

    printf("\n\t\t\t$\t\t\t%s$\t", a);
    if (a[j] == 'i')
	{
        printf("\t\t%s", "id");
    }
    else{
        printf("\t\t%c", a[j]);
    }
	for(i = 0; j < c; i++, j++)
	{
		printf("\n%s", act);
        if (a[j] == 'i')
		{
            stk[i] = a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j] = ' ';
            a[j+1] = ' ';
            i += 1;
            j += 1;
        }
        else{
            stk[i] = a[j];
            stk[i + 1] = '\0';
        }


		a[j] = ' ';


		printf("\t\t\t$%s\t\t\t%s$\t", stk, a);
        if (a[j+1] == 'i')
		{
            printf("\t\t%s", "id");
        }
        else{
            printf("\t\t%c", a[j+1]);
        }

		check();
	}

	if(stk[0] == 'P' && stk[1] == '\0')
		printf("\nAccept\n");
	else
		printf("\nReject\n");
}
