#include "Directory.h"//главный хедер файл

int main()
{
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_HIDE);//прячем консоль

	settings.antialiasingLevel = 8; //настройки четкости картинки
	
	Music music;//создаем объект музыки
	music.openFromFile("bensound-littleidea.ogg");//загружаем файл
	music.setVolume(4);//настройка громкости музыки
	music.play();//воспроизводим музыку
	music.setLoop(true);//повторение музыки

	//начальные установки для клавиш, пустого места, флагов
	ij = 0;
	black = 4;
	flag = 0;
	flag1 = 0;

	//делаем доску на которой шарики
	RectangleShape rectangle(Vector2f(790, 50));
	rectangle.setFillColor(Color::Red);
	rectangle.setPosition(50, 350);
	
	//делаем шарики
	CircleShape A[n];
	CircleShape circle(40);

	for (i=0 ; i < n; i++){
		A[i] = circle;
		if (i <= 3) 
		{
			A[i].setPosition(50 + space, 265);
			space += 100;
			A[i].setFillColor(Color::Black);
			A[i].setOutlineColor(Color::Blue);
			A[i].setOutlineThickness(4);
		}
		else if (i==4)
			{
				A[i].setPosition(50 + space, 265);
				space += 100;
				A[i].setFillColor(Color::Blue);
				A[i].setOutlineColor(Color::Blue);
				A[i].setOutlineThickness(4);
			}
			else
			{
				A[i].setPosition(50 + space, 265);
				space += 100;
				A[i].setFillColor(Color::White);
				A[i].setOutlineColor(Color::Blue);
				A[i].setOutlineThickness(4);
			}
	}
	
	//цвета, которые будем менять местами
	Color b = A[0].getFillColor();
	Color c = A[n - 1].getFillColor();
	
	//обводка первого шарика (стартовая позиция, для прохода по шариках)
	A[0].setOutlineColor(Color::Green);

	//Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не загруженности/мощности процессора).

	while (window.isOpen())
	//цыкл, который позволяет роботать с окном
	{	
		window.setFramerateLimit(15);//fps limite
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();//если нажать на крестик, окно закроется
			menu(window);//вызываем меню
		}

			if (isMenu == false) {
				/*float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
				clock.restart(); //перезагружает время
				time = time / 15; //скорость игры*/

				window.clear(Color::Blue);//рисуем фон

				window.draw(rectangle);//рисуем доску

				for (int i = 0; i < n; i++)
				{
					window.draw(A[i]); // рисуем шарики
				}

				ChangePlaces(&A[0], b, c);//вызываем функцию,которая позволяет ходить по шариках и менять их
				Win(&A[0], b, c);//вызываем функцию победы
				window.display();
			}
	}
	return 0;
}

void ChangePlaces(CircleShape *A, Color f, Color l)
//функия, которая позволяет ходить по шариках и менять их
{
	if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D)))
	{
		if (ij != n - 1) {
			A[ij].setOutlineColor(Color::Blue);
			A[ij + 1].setOutlineColor(Color::Green);
			ij++;
		}
		else
		{
			A[n - 1].setOutlineColor(Color::Blue);
			A[0].setOutlineColor(Color::Green);
			ij = 0;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))
	{
		if (ij != 0) {
			A[ij - 1].setOutlineColor(Color::Green);
			A[ij].setOutlineColor(Color::Blue);
			ij--;
		}
		else
		{
			A[0].setOutlineColor(Color::Blue);
			A[n - 1].setOutlineColor(Color::Green);
			ij = n - 1;
		}
	}

//ставим шарик на пустую позицию		
	if (((Keyboard::isKeyPressed(Keyboard::S)) || (Keyboard::isKeyPressed(Keyboard::Down)))) {
		if ((ij > black) && (A[ij].getFillColor() != f)) {
			A[ij].setFillColor(Color::Blue);
			A[black].setFillColor(Color::White);
			black = ij;
			
		}
		else if ((ij < black) && (A[ij].getFillColor() != l)) {
			A[ij].setFillColor(Color::Blue);
			A[black].setFillColor(Color::Black);
			black = ij;
		}
	}
//после нажатия Esc програма закрывается
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}

void Win(CircleShape *A, Color f, Color l) 
//функция, которая проверяет правильность розстановки шариков. Когда шарики отсортированы виводит сообщения: "Вы Победили"
{	
	n1 = 0;
	n2 = 0;
	for (i = 0; i < 3; i++) {
		if (A[i].getFillColor() == l) n1++;
		if (n1 == 3) flag = 1;
		}

	for (i = 4; i < n; i++) {
		if (A[i].getFillColor() == f) n2++;
		if (n2 == 4) flag1 = 1;
	}
		
	if ((flag == 1) && (flag1 == 1 )) {
			Font font;//шрифт 
			font.loadFromFile("arial.ttf");//передаем нашему шрифту файл шрифта

			Text text("", font, 80);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
			text.setFillColor(Color::Yellow);//покрасили текст в желтый
			text.setStyle(Text::Bold | Text::Underlined);//жырный подчеркнутый
			text.setString("YOU WIN!");//задает строку тексту
			text.setPosition(280, 160);//задаем позицию текста
			window.draw(text);//выводим текст

			Text ExitText("", font, 25);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
			ExitText.setFillColor(Color::Yellow);//покрасили текст в желтый
			ExitText.setStyle(Text::Bold);//жырный
			ExitText.setString("Press ESC for exit...");//задает строку тексту
			ExitText.setPosition(355, 425);//задаем позицию текста
			window.draw(ExitText);//выводим текст

		}
}

void menu(RenderWindow & window)
//функция меню
{
	//загружаем кратинки "игра", "выход","FAQ",фон. Делаем их спрайтами.
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("new_game.png");
	menuTexture2.loadFromFile("FAQIO.png");
	menuTexture3.loadFromFile("exit.png");
	aboutTexture.loadFromFile("BackFaq.jpg");
	menuBackground.loadFromFile("background.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);

	int menuNum = 0;

	//выводим спрайты на заданые позиции
	menu1.setPosition(275, 175);
	menu2.setPosition(0, 385);
	menu3.setPosition(800, 390);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ////////////////////////////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;

		//выделяем спрайт, если на него навестись мышкой
		if (IntRect(270, 170, 365, 100).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(0, 385, 225, 100).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(785, 385, 225, 100).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали левую кнопку, то выходим из меню и заходит в игру
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); } //выводит правила, что-бы выйти из правил - Esc
			if (menuNum == 3) { window.close(); isMenu = false; }
		}
		
		//рисуем спрайты
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}