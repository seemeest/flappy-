#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class background
{
public:
	Texture backxture;//������� ������ Texture (��������)
	Sprite  backsprite;//������� ������ Sprite(������)

	background(float x,float y) {

		backxture.loadFromFile("flappy-bird-assets-master/sprites/background-day.png");//��������� ��������
		backsprite.setTexture(backxture);//������� � ���� ������ Texture (��������)
		backsprite.setPosition(x, y);//������ ��������� ���������� ��������� �������
	}
};

