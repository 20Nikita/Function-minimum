#include "pch.h"
#include <iostream>
#include <iomanip>

void a() { setlocale(LC_ALL, "C"); }						// подключение английского языка
void r() { setlocale(LC_ALL, "Russian"); }					//подключение русского языка

//        таблицы
//void tabl_H();		начало таблицы
//void tabl_O();		отчерк таблицы
//void tabl_k();		конец таблицы
//void tabl_C(int K, double Ak, double Bk, double ak, double bk, double Fak, double Fbk);	заполнение таблицы
void A1_Min(double Eps, double l, double A, double B);		//метод дихотомического поиска минемума F1
void A1_F2_Min(double Eps, double l, double A, double B);	//метод дихотомического поиска минемума F2
void A1_F2_Max(double Eps, double l, double A, double B);	//метод дихотомического поиска максимума F2
void A2_Min(double Eps, double l, double A, double B);		//метод золотого сечения поиска минемума F1
void A2_F2_Min(double Eps, double l, double A, double B);	//метод золотого сечения поиска минемума F2
void A2_F2_Max(double Eps, double l, double A, double B);	//метод золотого сечения поиска максимума F2
void A3_Min(double Eps, double l, double A, double B);		//метод фибоначи поиска минемума F1
void A3_F2_Min(double Eps, double l, double A, double B);	//метод фибоначи поиска минемума F2
void A3_F2_Max(double Eps, double l, double A, double B);	//метод фибоначи поиска максимума F2
using namespace std;
int main()
{
	system("color F0");

	/*----------------------------------------------------------
	---------------ЗДЕСЬ МЕНЯТЬ НАЧАЛЬНЫЕ УСЛОВИЯ---------------
	-----------------------------------------------------------*/
	double Eps = 0.001;			// константа разлечимости (вспомогательна)
	double A = -1;				// начало отрезка
	double B = 2;				// конец отрезка
	double l = 0.1;				// длинна отрезка (точность)
	r(); cout << "Введите A" << endl; a();
	cin >> A;
	r(); cout << endl << "Введите B" << endl; a();
	cin >> B;
	r(); cout << endl << "Введите Epc" << endl; a();
	cin >> Eps;
	r(); cout << endl << "Введите l" << endl; a();
	cin >> l;
	cout << endl;

	r(); cout << "Алгорита дихотомического поиска Min функции F1 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A1_Min(Eps, l, A, B);
	r(); cout << "Алгорита дихотомического поиска Min функции F2 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A1_F2_Min(Eps, l, A, B);
	r(); cout << "Алгорита дихотомического поиска Max функции F2 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A1_F2_Max(Eps, l, A, B);
	r(); cout << "Алгорита золотого сечения для поиска Min функции F1 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A2_Min(Eps, l, A, B);
	r(); cout << "Алгорита золотого сечения для поиска Min функции F2 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A2_F2_Min(Eps, l, A, B);
	r(); cout << "Алгорита золотого сечения для поиска Max функции F2 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A2_F2_Max(Eps, l, A, B);
	r(); cout << "Алгорита фибоначи для поиска Min функции F1 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A3_Min(Eps, l, A, B);
	r(); cout << "Алгорита фибоначи для поиска Min функции F2 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A3_F2_Min(Eps, l, A, B);
	r(); cout << "Алгорита фибоначи для поиска Max функции F2 на трезке [" << A << " ; " << B << " ]. l = " << l << ", Eps = " << Eps << endl; a();
	A3_F2_Max(Eps, l, A, B); 
}
void tabl_H() {
	cout << char(218);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(191) << endl;
	cout << char(179) << "      K       ";
	cout << char(179) << "      Ak      ";
	cout << char(179) << "      Bk      ";
	cout << char(179) << "      ak      ";
	cout << char(179) << "      bk      ";
	cout << char(179) << "    F(ak)     ";
	cout << char(179) << "    F(bk)     ";
	cout << char(179) << endl;
	cout << char(195);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(180) << endl;
}

void tabl_O() {
	cout << char(195);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(180) << endl;
}
void tabl_k() {
	cout << char(192);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(217) << endl;
}

void tabl_C(int K, double Ak, double Bk, double ak, double bk, double Fak, double Fbk) {
	cout << char(179) << " " << setfill(char(32)) << setw(12) << K << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << Ak << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << Bk << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << ak << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << bk << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << Fak << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << Fbk << " ";
	cout << char(179) << endl;
}
void A1_Min(double Eps, double l, double A, double B) {
	double a;					// 
	double b;					// 
	int k = 0;					// Номер итерации
	double fa;
	double fb;
	tabl_H();
	while ((B - A) > l)
	{
		a = (A + B) / 2 - Eps;
		b = (A + B) / 2 + Eps;
		fa = 2 * a*a - 4 * a + 5;
		fb = 2 * b*b - 4 * b + 5;
		tabl_C(k, A, B, a, b, fa, fb);
		tabl_O();
		if (fa < fb)
			B = b;
		else
			A = a;
		k++;
	}
	tabl_C(k, A, B, a, b, fa, fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << 2 * (B + A) / 2 * (B + A) / 2 - 4 * (B + A) / 2 + 5 << "; N = " << k << endl << endl;
}

void A1_F2_Max(double Eps, double l, double A, double B) {
	double a;					// 
	double b;					// 
	int k = 0;					// Номер итерации
	double fa;
	double fb;
	tabl_H();
	while ((B - A) > l)
	{
		a = (A + B) / 2 - Eps;
		b = (A + B) / 2 + Eps;
		fa = -(a*a + a + 1) / (a*a - a + 1);
		fb = -(b*b + b + 1) / (b*b - b + 1);
		tabl_C(k, A, B, a, b, -fa, -fb);
		tabl_O();
		if (fa < fb)
			B = b;
		else
			A = a;
		k++;
	}
	tabl_C(k, A, B, a, b, -fa, -fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << ((B + A) / 2 * (B + A) / 2 + (B + A) / 2 + 1) / ((B + A) / 2 * (B + A) / 2 - (B + A) / 2 + 1) << "; N = " << k << endl << endl;
}

void A1_F2_Min(double Eps, double l, double A, double B) {
	double a;					// 
	double b;					// 
	int k = 0;					// Номер итерации
	double fa;
	double fb;
	tabl_H();
	while ((B - A) > l)
	{
		a = (A + B) / 2 - Eps;
		b = (A + B) / 2 + Eps;
		fa = (a*a + a + 1) / (a*a - a + 1);
		fb = (b*b + b + 1) / (b*b - b + 1);
		tabl_C(k, A, B, a, b, fa, fb);
		tabl_O();
		if (fa < fb)
			B = b;
		else
			A = a;
		k++;
	}
	tabl_C(k, A, B, a, b, fa, fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << ((B + A) / 2 * (B + A) / 2 + (B + A) / 2 + 1) / ((B + A) / 2 * (B + A) / 2 - (B + A) / 2 + 1) << "; N = " << k << endl << endl;
}

void A2_Min(double Eps, double l, double A, double B) {
	double a = A + (1 - 0.618)*(B - A);
	double b = A + 0.618*(B - A);
	double fa = 2 * a*a - 4 * a + 5;
	double fb = 2 * b*b - 4 * b + 5;
	int k = 1;					// Номер итерации

	tabl_H();
	while ((B - A) > l)
	{
		tabl_C(k, A, B, a, b, fa, fb);
		tabl_O();
		if (fa > fb)
		{
			A = a;
			a = b;
			b = A + 0.618*(B - A);
		}
		else
		{
			B = b;
			b = a;
			a = A + (1 - 0.618)*(B - A);
		}
		fa = 2 * a*a - 4 * a + 5;
		fb = 2 * b*b - 4 * b + 5;
		k++;
	}
	tabl_C(k, A, B, a, b, fa, fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << 2 * (B + A) / 2 * (B + A) / 2 - 4 * (B + A) / 2 + 5 << "; N = " << k << endl << endl;
}

void A2_F2_Min(double Eps, double l, double A, double B) {
	double a = A + (1 - 0.618)*(B - A);
	double b = A + 0.618*(B - A);
	double fa = (a*a + a + 1) / (a*a - a + 1);
	double fb = (b*b + b + 1) / (b*b - b + 1);
	int k = 1;					// Номер итерации

	tabl_H();
	while ((B - A) > l)
	{
		tabl_C(k, A, B, a, b, fa, fb);
		tabl_O();
		if (fa > fb)
		{
			A = a;
			a = b;
			b = A + 0.618*(B - A);
		}
		else
		{
			B = b;
			b = a;
			a = A + (1 - 0.618)*(B - A);
		}
		fa = (a*a + a + 1) / (a*a - a + 1);
		fb = (b*b + b + 1) / (b*b - b + 1);
		k++;
	}
	tabl_C(k, A, B, a, b, fa, fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << ((B + A) / 2 * (B + A) / 2 + (B + A) / 2 + 1) / ((B + A) / 2 * (B + A) / 2 - (B + A) / 2 + 1) << "; N = " << k << endl << endl;
}

void A2_F2_Max(double Eps, double l, double A, double B) {
	double a = A + (1 - 0.618)*(B - A);
	double b = A + 0.618*(B - A);
	double fa = (a*a + a + 1) / (a*a - a + 1);
	double fb = (b*b + b + 1) / (b*b - b + 1);
	int k = 1;					// Номер итерации

	tabl_H();
	while ((B - A) > l)
	{
		tabl_C(k, A, B, a, b, fa, fb);
		tabl_O();
		if (fa < fb)
		{
			A = a;
			a = b;
			b = A + 0.618*(B - A);
		}
		else
		{
			B = b;
			b = a;
			a = A + (1 - 0.618)*(B - A);
		}
		fa = (a*a + a + 1) / (a*a - a + 1);
		fb = (b*b + b + 1) / (b*b - b + 1);
		k++;
	}
	tabl_C(k, A, B, a, b, fa, fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << ((B + A) / 2 * (B + A) / 2 + (B + A) / 2 + 1) / ((B + A) / 2 * (B + A) / 2 - (B + A) / 2 + 1) << "; N = " << k << endl << endl;
}

void A3_Min(double Eps, double l, double A, double B) {
	double F[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };
	int n = 0;
	while (F[n] < (B - A) / l) { n++; }
	double a = A + F[n - 2] / F[n] * (B - A);
	double b = A + F[n - 1] / F[n] * (B - A);
	double fa = 2 * a*a - 4 * a + 5;
	double fb = 2 * b*b - 4 * b + 5;
	int k = 1;
	tabl_H(); 
	while (k < n-1)
	{
		tabl_C(k, A, B, a, b, fa, fb);
		tabl_O();
		if (fa > fb)
		{
			A = a;
			a = b;
			b = A + F[n - k] / F[n - k + 1] * (B - A);
		}
		else
		{
			B = b;
			b = a;
			a = A + F[n - k - 1] / F[n - k + 1] * (B - A);
		}
		fa = 2 * a*a - 4 * a + 5;
		fb = 2 * b*b - 4 * b + 5;
		k++;
	}
	b = a + Eps;
	fa = 2 * a*a - 4 * a + 5;
	fb = 2 * b*b - 4 * b + 5;
	if (fa > fb) A = a;
	else B = b;
	tabl_C(k, A, B, a, b, fa, fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << 2 * (B + A) / 2 * (B + A) / 2 - 4 * (B + A) / 2 + 5 << "; N = " << k << endl << endl;
}

void A3_F2_Min(double Eps, double l, double A, double B) {
	double F[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };
	int n = 0;
	while (F[n] < (B - A) / l) { n++; }
	double a = A + F[n - 2] / F[n] * (B - A);
	double b = A + F[n - 1] / F[n] * (B - A);
	double fa = (a*a + a + 1) / (a*a - a + 1);
	double fb = (b*b + b + 1) / (b*b - b + 1);
	int k = 1;
	tabl_H();
	while (k < n - 1)
	{
		tabl_C(k, A, B, a, b, fa, fb);
		tabl_O();
		if (fa > fb)
		{
			A = a;
			a = b;
			b = A + F[n - k] / F[n - k + 1] * (B - A);
		}
		else
		{
			B = b;
			b = a;
			a = A + F[n - k - 1] / F[n - k + 1] * (B - A);
		}
		fa = -(a*a + a + 1) / (a*a - a + 1);
		fb = -(b*b + b + 1) / (b*b - b + 1);
		k++;
	}
	b = a + Eps;
	fa = -(a*a + a + 1) / (a*a - a + 1);
	fb = -(b*b + b + 1) / (b*b - b + 1);
	if (fa > fb) A = a;
	else B = b;
	tabl_C(k, A, B, a, b, fa, fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << ((B + A) / 2 * (B + A) / 2 + (B + A) / 2 + 1) / ((B + A) / 2 * (B + A) / 2 - (B + A) / 2 + 1) << "; N = " << k << endl << endl;
}

void A3_F2_Max(double Eps, double l, double A, double B) {
	double F[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };
	int n = 0;
	while (F[n] < (B - A) / l) { n++; }
	double a = A + F[n - 2] / F[n] * (B - A);
	double b = A + F[n - 1] / F[n] * (B - A);
	double fa = -(a*a + a + 1) / (a*a - a + 1);
	double fb = -(b*b + b + 1) / (b*b - b + 1);
	int k = 1;
	tabl_H();
	while (k < n - 1)
	{
		tabl_C(k, A, B, a, b, -fa, -fb);
		tabl_O();
		if (fa > fb)
		{
			A = a;
			a = b;
			b = A + F[n - k] / F[n - k + 1] * (B - A);
		}
		else
		{
			B = b;
			b = a;
			a = A + F[n - k - 1] / F[n - k + 1] * (B - A);
		}
		fa = -(a*a + a + 1) / (a*a - a + 1);
		fb = -(b*b + b + 1) / (b*b - b + 1);
		k++;
	}
	b = a + Eps;
	fa = -(a*a + a + 1) / (a*a - a + 1);
	fb = -(b*b + b + 1) / (b*b - b + 1);
	if (fa > fb) A = a;
	else B = b;
	tabl_C(k, A, B, a, b, -fa, -fb);
	tabl_k();
	cout << "x = " << (B + A) / 2 << "; F(x) = " << ((B + A) / 2 * (B + A) / 2 + (B + A) / 2 + 1) / ((B + A) / 2 * (B + A) / 2 - (B + A) / 2 + 1) << "; N = " << k << endl << endl;
}
