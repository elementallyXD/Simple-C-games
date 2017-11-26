#pragma once
#include <SFML/Graphics.hpp> //библиотека графики в СФМЛ
#include <SFML/Audio.hpp> //библиотека аудио в СФМЛ
#include <iostream>
#include <Windows.h>

using namespace std; // пространство имен для роботы с выводом и т.д
using namespace sf; // пространство имен для роботы в СФМЛ

ContextSettings settings; // настройки картинок

//делаем окно, с которым будем роботать
RenderWindow window(VideoMode(980, 480), "JumpBubles1", Style::Default, settings);
const int n = 8; // количество шариков
int space = 0, i, ij, black, flag, flag1, n1, n2; // переменные,
bool isMenu = true; // переменная для меню

//прототипы функций, которые будут использоватся в програме
void ChangePlaces(CircleShape *A, Color f, Color l); // функция которая позволяет ходить по шариках
void Win(CircleShape *A, Color f, Color l); // функция выиграша
void menu(RenderWindow & window); // функция меню

