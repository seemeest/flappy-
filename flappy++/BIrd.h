#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Bird {

public:
	Texture birdtexture;//������� ������ Texture (��������)
	Sprite birdsprite;//������� ������ Sprite(������)

	int x=20, y=100;
	Bird() {

		birdtexture.loadFromFile("C:/Users/galuz/source/repos/flappy++/flappy++/flappy-bird-assets-master/sprites/bluebird-downflap.png");//��������� ��������
		birdsprite.setTexture(birdtexture);//������� � ���� ������ Texture (��������)
		birdsprite.setPosition(x, y);//������ ��������� ���������� ��������� �������

	};

	void SetPos(float x,float y) {
		this->x = x;
		this->y = y;
		birdsprite.setPosition(x, y);
	}




};