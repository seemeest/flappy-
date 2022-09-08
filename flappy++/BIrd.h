#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Bird {

public:
	Texture birdtexture;//создаем объект Texture (текстура)
	Sprite birdsprite;//создаем объект Sprite(спрайт)

	int x=20, y=100;
	Bird() {

		birdtexture.loadFromFile("C:/Users/galuz/source/repos/flappy++/flappy++/flappy-bird-assets-master/sprites/bluebird-downflap.png");//загружаем картинку
		birdsprite.setTexture(birdtexture);//передаём в него объект Texture (текстуры)
		birdsprite.setPosition(x, y);//задаем начальные координаты появления спрайта

	};

	void SetPos(float x,float y) {
		this->x = x;
		this->y = y;
		birdsprite.setPosition(x, y);
	}




};