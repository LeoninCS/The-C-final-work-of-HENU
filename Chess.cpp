#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include<string.h>
#include<stack>
#include<Windows.h>
using namespace std;

int arr[15][15];
stack<pair<int, int>> sta;
//����
void reset() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			arr[i][j] = 0;
		}
	}
	while (!sta.empty()) sta.pop();
}
//��ͼ
void drawline() {
	setlinecolor(BLACK);
	for (int i = 0; i < 15; i++) {
		line(40, 40 * i + 20, 600, 40 * i + 20);
		line(40 + 40 * i, 20, 40 + 40 * i, 580);
	}
	line(40, 19, 600, 19);
	line(40, 581, 600, 581);
	line(39, 20, 39, 580);
	line(601, 20, 601, 580);
	settextstyle(15, 0, "Times New Roman");
	for (int i = 15; i > 0; i--) {
		outtextxy(10, 610 - 40 * i, i - 1 + 'A');
		outtextxy(40 * i - 5, 600, i - 1 + 'A');
	}
	setfillcolor(BLACK);
	solidcircle(160, 140, 5);
	solidcircle(480, 140, 5);
	solidcircle(160, 460, 5);
	solidcircle(480, 460, 5);
	solidcircle(320, 300, 5);
	solidcircle(650, 320, 30);
	setfillcolor(WHITE);
	solidcircle(650, 220, 30);
	setfillcolor(LIGHTBLUE);
	fillrectangle(700, 200, 800, 245);
	fillrectangle(830, 200, 930, 245);
	fillrectangle(700, 300, 800, 345);
	fillrectangle(830, 300, 930, 345);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);
	settextstyle(35, 0, "����");
	outtextxy(715, 205, "����");
	outtextxy(715, 305, "����");
	outtextxy(845, 205, "����");
	outtextxy(845, 305, "����");
	settextstyle(45, 0, "����");
	outtextxy(690, 460, "���¿�ʼ");
	outtextxy(690, 395, "����ƽ��");
	outtextxy(630, 60, "���ߣ�LeoninCS");
}
//��������
void init()
{
	initgraph(1000, 700, 0);
	setbkcolor(BROWN);
	cleardevice();
	drawline();
}

// ����
void clear() {
	cleardevice();
	drawline();
	reset();
}
//�ж�
bool judge(int a, int b)
{
	int x = arr[a][b];
	int n = 0;
	//�� 
	n = 0;
	for (int i = b - 4; i < b + 5; i++) {
		if (i < 0 || i>14) continue;
		else {
			if (arr[a][i] == x) {
				n++;
			}
			else n = 0;
		}
		if (n == 5) return true;
	}
	//��
	n = 0;
	for (int i = a - 4; i < a + 5; i++) {
		if (i < 0 || i>14) continue;
		else {
			if (arr[i][b] == x) {
				n++;
			}
			else n = 0;
		}
		if (n == 5) return true;
	}
	//��б
	n = 0;
	for (int i = a + 4, j = b - 4; j < b + 5; i--, j++) {
		if (i < 0 || i>14 || j < 0 || j>14) continue;
		else {
			if (arr[i][j] == x) {
				n++;
			}
			else n = 0;
		}
		if (n == 5) return true;
	}
	//��б
	n = 0;
	for (int i = a - 4, j = b - 4; i < a + 5; i++, j++) {
		if (i < 0 || i>14 || j < 0 || j>14) continue;
		else {
			if (arr[i][j] == x) {
				n++;
			}
			else n = 0;
		}
		if (n == 5) return true;
	}
	return false;
}
//����
void back() {
	auto i = sta.top();
	sta.pop();
	arr[i.first][i.second] = 0;
	clearcircle(40 + i.second * 40, 20 + i.first * 40, 15);
	line(25 + i.second * 40, 20 + i.first * 40, 55 + i.second * 40, 20 + i.first * 40);
	line(40 + i.second * 40, 5 + i.first * 40, 40 + i.second * 40, 35 + i.first * 40);
	i = sta.top();
	sta.pop();
	arr[i.first][i.second] = 0;
	clearcircle(40 + i.second * 40, 20 + i.first * 40, 15);
	line(25 + i.second * 40, 20 + i.first * 40, 55 + i.second * 40, 20 + i.first * 40);
	line(40 + i.second * 40, 5 + i.first * 40, 40 + i.second * 40, 35 + i.first * 40);
}
//��Ϸ
void playChess()
{
	int a, b;
	MOUSEMSG m;
	HWND hwnd;
	hwnd = GetHWnd();
	int flag = 1;
	while (1) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			cout << m.x << " " << m.y << endl;
			a = m.y / 40;
			b = (m.x - 20) / 40;
			cout << a << " " << b << endl;
			if (m.x >= 690 && m.y >= 395 && m.x <= 865 && m.y <= 435) {
				MessageBox(hwnd, "�þ�Ϊƽ��", "��ʾ", MB_OK);
				break;
			}
			else if (m.x >= 690 && m.y >= 460 && m.x <= 865 && m.y <= 500) {
				break;
			}
			else if (m.x >= 700 && m.x <= 800 && m.y >= 200 && m.y <= 245) {
				MessageBox(hwnd, "��������", "��ʾ", MB_OK);
				break;
			}
			else if (m.x >= 700 && m.x <= 800 && m.y >= 300 && m.y <= 345) {
				MessageBox(hwnd, "��������", "��ʾ", MB_OK);
				break;
			}
			else if (m.x >= 830 && m.x <= 930 && m.y >= 200 && m.y <= 245) {
				if (flag % 2 == 1) {
					MessageBox(hwnd, "��ǰΪ����غ�", "��ʾ", MB_OK);
				}
				else {
					if (sta.size() < 2)
						MessageBox(hwnd, "��������", "��ʾ", MB_OK);
					else
						back();
				}
			}
			else if (m.x >= 830 && m.x <= 930 && m.y >= 300 && m.y <= 345) {
				if (flag % 2 == 0) {
					MessageBox(hwnd, "��ǰΪ����غ�", "��ʾ", MB_OK);
				}
				else {
					if (sta.size() < 2)
						MessageBox(hwnd, "��������", "��ʾ?", MB_OK);
					else
						back();
				}
			}
			else if (a < 0 || a>14 || b < 0 || b>14) {
				MessageBox(hwnd, "�����Խ��", "��ʾ", MB_OK);
			}
			else if (arr[a][b] != 0) {
				MessageBox(hwnd, "�����Ѿ���������", "��ʾ", MB_OK);
			}
			else {
				flag++;
				sta.push({ a,b });
				if (flag % 2 == 0) {
					setfillcolor(BLACK);
					arr[a][b] = 1;
				}
				else {
					setfillcolor(WHITE);
					arr[a][b] = 2;
				}
				solidcircle(40 + b * 40, 20 + a * 40, 15);
				if (judge(a, b)) {
					if (flag % 2 == 0) MessageBox(hwnd, "����ʤ��", "��ʾ", MB_OK);
					else MessageBox(hwnd, "����ʤ��", "��ʾ", MB_OK);
					break;
				}
			}
		}
	}
}
//������
int main()
{
	init();
	while (1) {
		playChess();
		clear();
	}
	return 0;
}