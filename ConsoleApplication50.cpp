#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

struct Client {
	char surname[20];
	char name[20];
	char otc[20];
	char phone[20];
	int d1;
	int m1;
	int y1;
	int d2;
	int m2;
	int y2;
	int dolg;
	int credit;
};
Client info[10];
struct Uslugi

{
	char name[100];
	int code;
	char tarif[7];
	char time[20];
};
Uslugi dat[10];
struct Clock
{
	int sec;
	int min;
	int hours;
};
Clock time1;
struct Calendar
{
	int day;
	int month;
	int year;
};
Calendar data;
struct Information
{
	char number[20];
	int ucode;
	Clock time1;
	Calendar data;
	char sectime[10];
};
Information itog[10];

void readclients() {
	FILE* file;
	fopen_s(&file, "users.txt", "r");
	int i = 0;
	if (file != NULL)
	{
		while (!feof(file)) {
			fscanf_s(file, "%s %s %[a-zA-Zа-яА-Я]%*c%*c%[0-9]%*c %d%*c%d%*c%d%*c %d%*c%d%*c%d%*c%d%*c%d\n", info[i].surname, 20, info[i].name, 20, info[i].otc, 20, info[i].phone, 20, &info[i].d1, &info[i].m1, &info[i].y1, &info[i].d2, &info[i].m2, &info[i].y2, &info[i].dolg, &info[i].credit);
			i++;
		}
		fclose(file);
	}
}

void readusligi()
{
	int t = 0;
	FILE* file1;
	fopen_s(&file1, "usluga.txt", "r");
	if (file1 != NULL)
	{
		while (!feof(file1)) {
			fscanf_s(file1, "%[^0123456789,]%*c %d%*c %[0-9.]%*c %s\n", dat[t].name, 100, &dat[t].code, dat[t].tarif, 7, dat[t].time, 20);
			t++;
		}
		fclose(file1);
	}
}
void readsusp()
{
	FILE* file1;
	int q = 0;
	fopen_s(&file1, "uinfo.txt", "r");
	if (file1 != NULL)
	{
		while (!feof(file1)) {
			fscanf_s(file1, "%[0-9]%*c %d%*c %d.%d.%d %d:%d:%d%*c %s\n", itog[q].number, 20, &itog[q].ucode, &itog[q].data.day, &itog[q].data.month, &itog[q].data.year, &itog[q].time1.hours, &itog[q].time1.min, &itog[q].time1.sec, itog[q].sectime, 10);
			q++;
		}
		fclose(file1);
	}
}
bool checktime(int days, int month, int year, int hour, int min, int sec)
{
	int delta = 60 * 60 * 24 * 7;
	int sutki = 86400; // количество секунд в сутках
	long long int del1, del2, del3left, del3right;
	struct tm* u;
	char s1[100] = { 0 }, s2[40] = { 0 };
	int ndays, nmonth, nyear;
	int nhour, nsec, nmin;
	int leftday, rightday;
	int newmonth;
	char dayofweek[15] = { 0 };
	const time_t timer = time(NULL);
	u = localtime(&timer);
	strftime(s1, 100, "%d.%m.%Y %H:%M:%S %A", u);
	sscanf_s(s1, "%d%*c%d%*c%d %d%*c%d%*c%d %s", &ndays, &nmonth, &nyear, &nhour, &nmin, &nsec, dayofweek, 15);
	newmonth = nmonth;
	if ((nmonth == 1) || (nmonth == 3) || (nmonth == 5) || (nmonth == 7) || (nmonth == 8) || (nmonth == 10) || (nmonth == 12)) {
		if ((nmonth == 5) || (nmonth == 7) || (nmonth == 10) || (nmonth == 12)) {
			if (strcmp(dayofweek, "Monday") == 0) {
				leftday = ndays;
			}
			else if (strcmp(dayofweek, "Tuesday") == 0) {
				if ((ndays - 1) <= 0) {
					leftday = 30;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 1;
				}
			}
			else if (strcmp(dayofweek, "Wednesday") == 0) {
				if ((ndays - 2) <= 0) {
					leftday = 30 - 2 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 2;

				}
			}
			else if (strcmp(dayofweek, "Thursday") == 0) {
				if ((ndays - 3) <= 0) {
					leftday = 30 - 3 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 3;

				}
			}
			else if (strcmp(dayofweek, "Friday") == 0) {
				if ((ndays - 4) <= 0) {
					leftday = 30 - 4 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 4;

				}
			}
			else if (strcmp(dayofweek, "Saturday") == 0) {
				if ((ndays - 5) <= 0) {
					leftday = 30 - 5 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 5;
				}
			}
			else if (strcmp(dayofweek, "Sunday") == 0) {
				if ((ndays - 6) <= 0) {
					leftday = 30 - 6 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 6;

				}
			}
		}
		else if (nmonth == 3) {
			if (((nyear % 400) == 0) || ((nyear % 4) == 0)) {
				if (strcmp(dayofweek, "Monday") == 0) {
					leftday = ndays;
				}
				else if (strcmp(dayofweek, "Tuesday") == 0) {
					if ((ndays - 1) <= 0) {
						leftday = 29;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 1;
					}
				}
				else if (strcmp(dayofweek, "Wednesday") == 0) {
					if ((ndays - 2) <= 0) {
						leftday = 29 - 2 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 2;
					}
				}
				else if (strcmp(dayofweek, "Thursday") == 0) {
					if ((ndays - 3) <= 0) {
						leftday = 29 - 3 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 3;
					}
				}
				else if (strcmp(dayofweek, "Friday") == 0) {
					if ((ndays - 4) <= 0) {
						leftday = 29 - 4 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 4;
					}
				}
				else if (strcmp(dayofweek, "Saturday") == 0) {
					if ((ndays - 5) <= 0) {
						leftday = 29 - 5 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 5;
					}
				}
				else if (strcmp(dayofweek, "Sunday") == 0) {
					if ((ndays - 6) <= 0) {
						leftday = 29 - 6 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 6;
					}
				}
			}
			else {
				if (strcmp(dayofweek, "Monday") == 0) {
					leftday = ndays;
				}
				else if (strcmp(dayofweek, "Tuesday") == 0) {
					if ((ndays - 1) <= 0) {
						leftday = 28;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 1;
					}
				}
				else if (strcmp(dayofweek, "Wednesday") == 0) {
					if ((ndays - 2) <= 0) {
						leftday = 28 - 2 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 2;
					}
				}
				else if (strcmp(dayofweek, "Thursday") == 0) {
					if ((ndays - 3) <= 0) {
						leftday = 28 - 3 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 3;
					}
				}
				else if (strcmp(dayofweek, "Friday") == 0) {
					if ((ndays - 4) <= 0) {
						leftday = 28 - 4 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 4;
					}
				}
				else if (strcmp(dayofweek, "Saturday") == 0) {
					if ((ndays - 5) <= 0) {
						leftday = 28 - 5 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 5;
					}
				}
				else if (strcmp(dayofweek, "Sunday") == 0) {
					if ((ndays - 6) <= 0) {
						leftday = 28 - 6 + ndays;
						newmonth -= 1;
					}
					else {
						leftday = ndays - 6;
					}
				}
			}
		}
		else if ((nmonth == 1) || (nmonth == 8)) {
			if (strcmp(dayofweek, "Monday") == 0) {
				leftday = ndays;
			}
			else if (strcmp(dayofweek, "Tuesday") == 0) {
				if ((ndays - 1) <= 0) {
					leftday = 31;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 1;
				}
			}
			else if (strcmp(dayofweek, "Wednesday") == 0) {
				if ((ndays - 2) <= 0) {
					leftday = 31 - 2 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 2;
				}
			}
			else if (strcmp(dayofweek, "Thursday") == 0) {
				if ((ndays - 3) <= 0) {
					leftday = 31 - 3 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 3;
				}
			}
			else if (strcmp(dayofweek, "Friday") == 0) {
				if ((ndays - 4) <= 0) {
					leftday = 31 - 4 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 4;
				}
			}
			else if (strcmp(dayofweek, "Saturday") == 0) {
				if ((ndays - 5) <= 0) {
					leftday = 31 - 5 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 5;
				}
			}
			else if (strcmp(dayofweek, "Sunday") == 0) {
				if ((ndays - 6) <= 0) {
					leftday = 31 - 6 + ndays;
					newmonth -= 1;
				}
				else {
					leftday = ndays - 6;
				}
			}
		}
	}
	else if ((nmonth == 4) || (nmonth == 6) || (nmonth == 9) || (nmonth == 11)) {
		if (strcmp(dayofweek, "Monday") == 0) {
			leftday = ndays;
		}
		else if (strcmp(dayofweek, "Tuesday") == 0) {
			if ((ndays - 1) <= 0) {
				leftday = 31;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 1;
			}
		}
		else if (strcmp(dayofweek, "Wednesday") == 0) {
			if ((ndays - 2) <= 0) {
				leftday = 31 - 2 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 2;
			}
		}
		else if (strcmp(dayofweek, "Thursday") == 0) {
			if ((ndays - 3) <= 0) {
				leftday = 31 - 3 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 3;
			}
		}
		else if (strcmp(dayofweek, "Friday") == 0) {
			if ((ndays - 4) <= 0) {
				leftday = 31 - 4 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 4;
			}
		}
		else if (strcmp(dayofweek, "Saturday") == 0) {
			if ((ndays - 5) <= 0) {
				leftday = 31 - 5 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 5;
			}
		}
		else if (strcmp(dayofweek, "Sunday") == 0) {
			if ((ndays - 6) <= 0) {
				leftday = 31 - 6 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 6;
			}
		}
	}
	else if (nmonth == 2) {
		if (strcmp(dayofweek, "Monday") == 0) {
			leftday = ndays;
		}
		else if (strcmp(dayofweek, "Tuesday") == 0) {
			if ((ndays - 1) <= 0) {
				leftday = 31;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 1;
			}
		}
		else if (strcmp(dayofweek, "Wednesday") == 0) {
			if ((ndays - 2) <= 0) {
				leftday = 31 - 2 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 2;
			}
		}
		else if (strcmp(dayofweek, "Thursday") == 0) {
			if ((ndays - 3) <= 0) {
				leftday = 31 - 3 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 3;
			}
		}
		else if (strcmp(dayofweek, "Friday") == 0) {
			if ((ndays - 4) <= 0) {
				leftday = 31 - 4 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 4;
			}
		}
		else if (strcmp(dayofweek, "Saturday") == 0) {
			if ((ndays - 5) <= 0) {
				leftday = 31 - 5 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 5;
			}
		}
		else if (strcmp(dayofweek, "Sunday") == 0) {
			if ((ndays - 6) <= 0) {
				leftday = 31 - 6 + ndays;
				newmonth -= 1;
			}
			else {
				leftday = ndays - 6;
			}
		}
	}
	del3left = (long long int)leftday * (long long int)sutki + (long long int)newmonth * 30 * (long long int)sutki + (long long int)nyear * 365 * (long long int)sutki;
	del3right = (del3left + delta) - 1;
	del2 = (long long int)days * (long long int)sutki + (long long int)month * 30 * (long long int)sutki + (long long int)year * 365 * (long long int)sutki + (long long int)hour * 3600 + (long long int)min * 60 + (long long int)sec;
	if ((del2 >= del3left) && (del2 <= del3right)) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	readclients();
	readusligi();
	readsusp();
	double paramdept;
	FILE* file1;
	fopen_s(&file1, "param.ini", "r");
	if (file1 != NULL)
	{
		while (!feof(file1)) {

			fscanf_s(file1, "%lf", &paramdept);

		}
		fclose(file1);
	}
	char numbers[10][100];
	char space[] = "";
	for (int i = 0; i < 10; i++) {
		strcpy(numbers[i], itog[i].number);
	}
	int p = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if ((strcmp(numbers[i], numbers[j]) == 0) && (j != i)) {
				strcpy(numbers[j], space);
			}
		}
	}
	char numberssort[10][100] = { 0 };
	for (int i = 0; i < 10; i++) {
		if (strcmp(numbers[i], space) != 0) {
			strcpy(numberssort[p], numbers[i]);
			p++;
		}
	}
	double sum[10] = { 0 };
	int t = 0;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < 10; j++) {
			if (strcmp(numberssort[i], itog[j].number) == 0) {
				if (itog[j].ucode == 1) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 2) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 3) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 4) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 5) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 6) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 7) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 8) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 9) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
				else if (itog[j].ucode == 10) {
					while ((dat[t].code != itog[j].ucode) && (t < 10)) {
						t += 1;
					}
					if (((strcmp(dat[t].time, "min") == 0) || (strcmp(dat[t].time, "мин") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 60.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "day") == 0) || (strcmp(dat[t].time, "день") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 86400.0) * atof(dat[t].tarif);
					}
					else if (((strcmp(dat[t].time, "month") == 0) || (strcmp(dat[t].time, "месяц") == 0)) && (strcmp(itog[j].sectime, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += ((atoll(itog[j].sectime)) / 2592000.0) * atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += atof(dat[t].tarif);
					}
					else if ((strcmp(itog[j].sectime, "#") == 0) && (strcmp(dat[t].time, "#") != 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					else if ((strcmp(itog[j].sectime, "#") != 0) && (strcmp(dat[t].time, "#") == 0) && (checktime(itog[j].data.day, itog[j].data.month, itog[j].data.year, itog[j].time1.hours, itog[j].time1.min, itog[j].time1.sec)) == true) {
						sum[i] += 0;
					}
					t = 0;
				}
			}
		}
	}
	FILE* zq;
	int h = 0;
	fopen_s(&zq, "Report.txt", "w");
	int k = 0;
	for (int i = 0; i < p; i++) {
		if (sum[i] >= paramdept) {
			while (strcmp(info[h].phone, numberssort[i]) != 0) {
				h++;
			}
			fprintf(zq, "%d.%d.%d, %d.%d.%d, %s\n", info[h].d1, info[h].m1, info[h].y1, info[h].d2, info[h].m2, info[h].y2, info[h].phone);
			k++;
		}
		h = 0;
	}
	if (k == 0) {
		fprintf(zq, "Нет данных");
		printf("Ничего не найдено");
	}
	else {
		printf("Результаты записаны в файл!!!");
	}
	fclose(zq);
	return 0;
}
