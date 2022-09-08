#include <SFML/Graphics.hpp> 
#include "Bird.h"
#include <iostream>
#include "background.h"
#include "pipe.h"
#include "Values.h"

#include <sstream>//из int в string 
#include <string>



//для общего доступа у всех нейронных сетей(я это в зрание написал ) для просто игры оно не нужно
//сами переменные находястся в Статическом классе  Values
float Values::bordY = 100; //иницилизация статических переменных 
float Values::bordX = 40;//иницилизация статических переменных 
float Values::pipeX = 400; //иницилизация статических переменных 
float Values::pipeY = 100;//иницилизация статических переменных 


using namespace sf; // использование пространства имён  sfml
int main()
{

	Texture basetexture;//создаем объект Texture (текстура)
	Sprite  basesprite;//создаем объект Sprite(спрайт)
	Sprite  basesprite1;//создаем объект Sprite(спрайт)
	basetexture.loadFromFile("flappy-bird-assets-master/sprites/base.png");//загружаем картинку


	basesprite.setTexture(basetexture);//передаём в него объект Texture (текстуры)
	basesprite1.setTexture(basetexture);//передаём в него объект Texture (текстуры)
	basesprite.setPosition(0, 400);//задаем начальные координаты появления спрайта
	basesprite1.setPosition(336, 400);//задаем начальные координаты появления спрайта



	sf::RenderWindow window(sf::VideoMode(400, 500), "C++Version"); //создание окна указание разрешения и  title окна


	bool Spase = false; //это для првоерки нажатия чтобы нельзя было зажимать

	//сглаживание 
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	//создание экземпляров классов
	Bird bird;
	background _background1(0,0);
	background _background2(288,0);

	pipe _pipe; 

	int suorce = 0;//cчёт

	//шрифт
	sf::Font font;

	font.loadFromFile("Docker.ttf");//подключить шрифт (кидать шрифт в папку где main)
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта
	
	//для отслеживания время
	Clock clock;

	while (window.isOpen())
	{


		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 800; //скорость игры


		sf::Event event;//класс эвент дли эвентов 
		while (window.pollEvent(event)) //проверка сробатывания одного из эвентов 
		{
			if (event.type == sf::Event::Closed) //если эвент закрытия окна сработал закрыть окно ( нажатие на крестик)
				window.close();
		}


		//проверка нажатия на клавишу проблел
		if (Keyboard::isKeyPressed(Keyboard::Space) && Spase == false) {
			Spase = true;
			Values::bordY -=70*time;
			//умнажаю на time для плавности 
			bird.birdsprite.setRotation(-3.f);//при прыжке птичка смотрит вверх (просто вращаю картинку)

		}
		else if(!Keyboard::isKeyPressed(Keyboard::Space)){

			bird.birdsprite.setRotation(3.f);//при падение  птичка смотрит вверх (просто вращаю картинку)
			Spase = false;
		}

		if (Values::bordY>Values::pipeY && Values::bordX> Values::pipeX && Values::bordX < Values::pipeX+52||
			Values::bordY<Values::pipeY-80 && Values::bordX > Values::pipeX && Values::bordX < Values::pipeX + 52|| Values::bordY<0|| Values::bordY>380) { //столкнавения  //+52 так как труба имеет размер 52 на 302

			Values::bordY = 100;//изначальная позиция птички
			Values::pipeX = 400;//вернуть трубу на изначальную позицию 
			Values::pipeY = rand() % 280 + 100;//рандомим новую высоту для труб
			suorce = 0;
		}
		std::ostringstream playerScoreString;    // объявили переменную для перевода текста 
		playerScoreString << suorce;		//занесли в нее число очков, то есть формируем строку
		text.setString("suorce=" + playerScoreString.str());//задаём сам текст 

		text.setPosition(10,10);//позиция текста на экране 
		Values::pipeX -= 0.13 * time;//движение трубы каждый кадр 

		if (Values::pipeX<0) { //проверка если труба ушла в лево за экран 

			Values::pipeX = 400;//вернуть её обратно 
			Values::pipeY = rand() %280  + 100;//рандомим новую высоту для труб
			suorce++;//прибавить очки

		}

		_pipe.SetPos(Values::pipeX, Values::pipeY); //установка позиции трубы

		Values::bordY += 0.1*time; //Падение птички
		bird.SetPos(Values::bordX, Values::bordY); //установка позии птички

		window.clear();//обязятельно отчситка экрана 
		
		window.draw(_background1.backsprite); //задний фон
	    window.draw(_background2.backsprite);  //задний фон
		

		_pipe.Draw(window);//трубы
	
		window.draw(basesprite);  //хрень снизу 
		window.draw(basesprite1);  //хрень снизу 



		window.draw(bird.birdsprite);///птичка
	
		window.draw(text);//рисую  текст
		window.display(); //обязятельно отрисовка  экрана 
		//без отчистки и отрисовки экрана  окно не будет обнавляться 

		
	}

	return 0;
}