#pragma once
#include <SFML/Graphics.hpp> //���������� ������� � ����
#include <SFML/Audio.hpp> //���������� ����� � ����
#include <iostream>
#include <Windows.h>

using namespace std; // ������������ ���� ��� ������ � ������� � �.�
using namespace sf; // ������������ ���� ��� ������ � ����

ContextSettings settings; // ��������� ��������

//������ ����, � ������� ����� ��������
RenderWindow window(VideoMode(980, 480), "JumpBubles1", Style::Default, settings);
const int n = 8; // ���������� �������
int space = 0, i, ij, black, flag, flag1, n1, n2; // ����������,
bool isMenu = true; // ���������� ��� ����

//��������� �������, ������� ����� ������������� � ��������
void ChangePlaces(CircleShape *A, Color f, Color l); // ������� ������� ��������� ������ �� �������
void Win(CircleShape *A, Color f, Color l); // ������� ��������
void menu(RenderWindow & window); // ������� ����

