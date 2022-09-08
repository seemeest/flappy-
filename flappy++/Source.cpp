#include <SFML/Graphics.hpp> 
#include "Bird.h"
#include <iostream>
#include "background.h"
#include "pipe.h"
#include "Values.h"

#include <sstream>//�� int � string 
#include <string>



//��� ������ ������� � ���� ��������� �����(� ��� � ������ ������� ) ��� ������ ���� ��� �� �����
//���� ���������� ���������� � ����������� ������  Values
float Values::bordY = 100; //������������ ����������� ���������� 
float Values::bordX = 40;//������������ ����������� ���������� 
float Values::pipeX = 400; //������������ ����������� ���������� 
float Values::pipeY = 100;//������������ ����������� ���������� 


using namespace sf; // ������������� ������������ ���  sfml
int main()
{

	Texture basetexture;//������� ������ Texture (��������)
	Sprite  basesprite;//������� ������ Sprite(������)
	Sprite  basesprite1;//������� ������ Sprite(������)
	basetexture.loadFromFile("flappy-bird-assets-master/sprites/base.png");//��������� ��������


	basesprite.setTexture(basetexture);//������� � ���� ������ Texture (��������)
	basesprite1.setTexture(basetexture);//������� � ���� ������ Texture (��������)
	basesprite.setPosition(0, 400);//������ ��������� ���������� ��������� �������
	basesprite1.setPosition(336, 400);//������ ��������� ���������� ��������� �������



	sf::RenderWindow window(sf::VideoMode(400, 500), "C++Version"); //�������� ���� �������� ���������� �  title ����


	bool Spase = false; //��� ��� �������� ������� ����� ������ ���� ��������

	//����������� 
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	//�������� ����������� �������
	Bird bird;
	background _background1(0,0);
	background _background2(288,0);

	pipe _pipe; 

	int suorce = 0;//c���

	//�����
	sf::Font font;

	font.loadFromFile("Docker.ttf");//���������� ����� (������ ����� � ����� ��� main)
	Text text("", font, 20);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������
	
	//��� ������������ �����
	Clock clock;

	while (window.isOpen())
	{


		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 800; //�������� ����


		sf::Event event;//����� ����� ��� ������� 
		while (window.pollEvent(event)) //�������� ������������ ������ �� ������� 
		{
			if (event.type == sf::Event::Closed) //���� ����� �������� ���� �������� ������� ���� ( ������� �� �������)
				window.close();
		}


		//�������� ������� �� ������� �������
		if (Keyboard::isKeyPressed(Keyboard::Space) && Spase == false) {
			Spase = true;
			Values::bordY -=70*time;
			//������� �� time ��� ��������� 
			bird.birdsprite.setRotation(-3.f);//��� ������ ������ ������� ����� (������ ������ ��������)

		}
		else if(!Keyboard::isKeyPressed(Keyboard::Space)){

			bird.birdsprite.setRotation(3.f);//��� �������  ������ ������� ����� (������ ������ ��������)
			Spase = false;
		}

		if (Values::bordY>Values::pipeY && Values::bordX> Values::pipeX && Values::bordX < Values::pipeX+52||
			Values::bordY<Values::pipeY-80 && Values::bordX > Values::pipeX && Values::bordX < Values::pipeX + 52|| Values::bordY<0|| Values::bordY>380) { //������������  //+52 ��� ��� ����� ����� ������ 52 �� 302

			Values::bordY = 100;//����������� ������� ������
			Values::pipeX = 400;//������� ����� �� ����������� ������� 
			Values::pipeY = rand() % 280 + 100;//�������� ����� ������ ��� ����
			suorce = 0;
		}
		std::ostringstream playerScoreString;    // �������� ���������� ��� �������� ������ 
		playerScoreString << suorce;		//������� � ��� ����� �����, �� ���� ��������� ������
		text.setString("suorce=" + playerScoreString.str());//����� ��� ����� 

		text.setPosition(10,10);//������� ������ �� ������ 
		Values::pipeX -= 0.13 * time;//�������� ����� ������ ���� 

		if (Values::pipeX<0) { //�������� ���� ����� ���� � ���� �� ����� 

			Values::pipeX = 400;//������� � ������� 
			Values::pipeY = rand() %280  + 100;//�������� ����� ������ ��� ����
			suorce++;//��������� ����

		}

		_pipe.SetPos(Values::pipeX, Values::pipeY); //��������� ������� �����

		Values::bordY += 0.1*time; //������� ������
		bird.SetPos(Values::bordX, Values::bordY); //��������� ����� ������

		window.clear();//����������� �������� ������ 
		
		window.draw(_background1.backsprite); //������ ���
	    window.draw(_background2.backsprite);  //������ ���
		

		_pipe.Draw(window);//�����
	
		window.draw(basesprite);  //����� ����� 
		window.draw(basesprite1);  //����� ����� 



		window.draw(bird.birdsprite);///������
	
		window.draw(text);//�����  �����
		window.display(); //����������� ���������  ������ 
		//��� �������� � ��������� ������  ���� �� ����� ����������� 

		
	}

	return 0;
}