#include "Directory.h"//������� ����� ����

int main()
{
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_HIDE);//������ �������

	settings.antialiasingLevel = 8; //��������� �������� ��������
	
	Music music;//������� ������ ������
	music.openFromFile("bensound-littleidea.ogg");//��������� ����
	music.setVolume(4);//��������� ��������� ������
	music.play();//������������� ������
	music.setLoop(true);//���������� ������

	//��������� ��������� ��� ������, ������� �����, ������
	ij = 0;
	black = 4;
	flag = 0;
	flag1 = 0;

	//������ ����� �� ������� ������
	RectangleShape rectangle(Vector2f(790, 50));
	rectangle.setFillColor(Color::Red);
	rectangle.setPosition(50, 350);
	
	//������ ������
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
	
	//�����, ������� ����� ������ �������
	Color b = A[0].getFillColor();
	Color c = A[n - 1].getFillColor();
	
	//������� ������� ������ (��������� �������, ��� ������� �� �������)
	A[0].setOutlineColor(Color::Green);

	//Clock clock; //������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).

	while (window.isOpen())
	//����, ������� ��������� �������� � �����
	{	
		window.setFramerateLimit(15);//fps limite
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();//���� ������ �� �������, ���� ���������
			menu(window);//�������� ����
		}

			if (isMenu == false) {
				/*float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
				clock.restart(); //������������� �����
				time = time / 15; //�������� ����*/

				window.clear(Color::Blue);//������ ���

				window.draw(rectangle);//������ �����

				for (int i = 0; i < n; i++)
				{
					window.draw(A[i]); // ������ ������
				}

				ChangePlaces(&A[0], b, c);//�������� �������,������� ��������� ������ �� ������� � ������ ��
				Win(&A[0], b, c);//�������� ������� ������
				window.display();
			}
	}
	return 0;
}

void ChangePlaces(CircleShape *A, Color f, Color l)
//������, ������� ��������� ������ �� ������� � ������ ��
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

//������ ����� �� ������ �������		
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
//����� ������� Esc �������� �����������
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}

void Win(CircleShape *A, Color f, Color l) 
//�������, ������� ��������� ������������ ����������� �������. ����� ������ ������������� ������� ���������: "�� ��������"
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
			Font font;//����� 
			font.loadFromFile("arial.ttf");//�������� ������ ������ ���� ������

			Text text("", font, 80);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
			text.setFillColor(Color::Yellow);//��������� ����� � ������
			text.setStyle(Text::Bold | Text::Underlined);//������ ������������
			text.setString("YOU WIN!");//������ ������ ������
			text.setPosition(280, 160);//������ ������� ������
			window.draw(text);//������� �����

			Text ExitText("", font, 25);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
			ExitText.setFillColor(Color::Yellow);//��������� ����� � ������
			ExitText.setStyle(Text::Bold);//������
			ExitText.setString("Press ESC for exit...");//������ ������ ������
			ExitText.setPosition(355, 425);//������ ������� ������
			window.draw(ExitText);//������� �����

		}
}

void menu(RenderWindow & window)
//������� ����
{
	//��������� �������� "����", "�����","FAQ",���. ������ �� ���������.
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("new_game.png");
	menuTexture2.loadFromFile("FAQIO.png");
	menuTexture3.loadFromFile("exit.png");
	aboutTexture.loadFromFile("BackFaq.jpg");
	menuBackground.loadFromFile("background.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);

	int menuNum = 0;

	//������� ������� �� ������� �������
	menu1.setPosition(275, 175);
	menu2.setPosition(0, 385);
	menu3.setPosition(800, 390);
	menuBg.setPosition(0, 0);

	//////////////////////////////����////////////////////////////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;

		//�������� ������, ���� �� ���� ��������� ������
		if (IntRect(270, 170, 365, 100).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(0, 385, 225, 100).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(785, 385, 225, 100).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//���� ������ ����� ������, �� ������� �� ���� � ������� � ����
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); } //������� �������, ���-�� ����� �� ������ - Esc
			if (menuNum == 3) { window.close(); isMenu = false; }
		}
		
		//������ �������
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}