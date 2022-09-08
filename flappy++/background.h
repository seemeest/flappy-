#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class background
{
public:
	Texture backxture;//создаем объект Texture (текстура)
	Sprite  backsprite;//создаем объект Sprite(спрайт)

	background(float x,float y) {

		backxture.loadFromFile("flappy-bird-assets-master/sprites/background-day.png");//загружаем картинку
		backsprite.setTexture(backxture);//передаём в него объект Texture (текстуры)
		backsprite.setPosition(x, y);//задаем начальные координаты появления спрайта
	}
};

