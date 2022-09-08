#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class pipe
{
public:
	Texture backxture;//создаем объект Texture (текстура)
	Sprite  backsprite;//создаем объект Sprite(спрайт)

	Texture backxture1;//создаем объект Texture (текстура)
	Sprite  backsprite1;//создаем объект Sprite(спрайт)
	float y2, x, y;
	pipe() {
		
			backxture.loadFromFile("flappy-bird-assets-master/sprites/pipe-green.png");//загружаем картинку
			backsprite.setTexture(backxture);//передаём в него объект Texture (текстуры)	

			backxture1.loadFromFile("flappy-bird-assets-master/sprites/pipe-red.png");//загружаем картинку
			backsprite1.setTexture(backxture1);//передаём в него объект Texture (текстуры)	
	}
	 //установка позиции трубы 
	void SetPos(float x,float y) {
		this->x = x;
		this->x = y;
		y2 = y - 80;
		
		backsprite.setPosition(x, y);//задаем начальные координаты появления спрайта
		backsprite1.setPosition(x+50, y2);//задаем начальные координаты появления спрайта
	}

	//для отрисовки из класса  
	void Draw(RenderWindow& window) { //передаю ссылку на адрес окна для работы с ним из другого класса 

		if (y2 == NULL || x == NULL || y == NULL) { //проверка на ошибки  можно и не писать
			
			std::cout << "ERROR y2 == NULL || x == NULL || y == NULL " << std::endl;
			return;

		}
		else {

			backsprite1.setRotation(180.f); //повернуд вторую трубу на 180 
			window.draw(backsprite); //отрсовка трубы
			window.draw(backsprite1); //отрсовка трубы
		}
	
	}
};

