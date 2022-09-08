#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class pipe
{
public:
	Texture backxture;//������� ������ Texture (��������)
	Sprite  backsprite;//������� ������ Sprite(������)

	Texture backxture1;//������� ������ Texture (��������)
	Sprite  backsprite1;//������� ������ Sprite(������)
	float y2, x, y;
	pipe() {
		
			backxture.loadFromFile("flappy-bird-assets-master/sprites/pipe-green.png");//��������� ��������
			backsprite.setTexture(backxture);//������� � ���� ������ Texture (��������)	

			backxture1.loadFromFile("flappy-bird-assets-master/sprites/pipe-red.png");//��������� ��������
			backsprite1.setTexture(backxture1);//������� � ���� ������ Texture (��������)	
	}
	 //��������� ������� ����� 
	void SetPos(float x,float y) {
		this->x = x;
		this->x = y;
		y2 = y - 80;
		
		backsprite.setPosition(x, y);//������ ��������� ���������� ��������� �������
		backsprite1.setPosition(x+50, y2);//������ ��������� ���������� ��������� �������
	}

	//��� ��������� �� ������  
	void Draw(RenderWindow& window) { //������� ������ �� ����� ���� ��� ������ � ��� �� ������� ������ 

		if (y2 == NULL || x == NULL || y == NULL) { //�������� �� ������  ����� � �� ������
			
			std::cout << "ERROR y2 == NULL || x == NULL || y == NULL " << std::endl;
			return;

		}
		else {

			backsprite1.setRotation(180.f); //�������� ������ ����� �� 180 
			window.draw(backsprite); //�������� �����
			window.draw(backsprite1); //�������� �����
		}
	
	}
};

