#include "stdafx.h"
#include "particleSystem.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(1920.f,1080.f), "Demo");
	sf::Mouse mouse;
	particleSystem system;
	particle _particle(sf::Vector2f(1,1),100,sf::Vector2f(500,500));
	//system.update();

	//for each (particle p in particles) {
	//	std::cout << "asd";
	//}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f mousePos = sf::Vector2f(mouse.getPosition(window).x-2, mouse.getPosition(window).y-2);
		system.setSpawnpoint(mousePos);

		window.clear();

		system.update();
		std::list<particle*> x = system.getParticles();
		for (std::list<particle*>::iterator it = x.begin(); it != x.end(); ++it) {
			if (!(*it)->isDead) {
				window.draw(*(*it));
			}
		}

		//window.draw(_particle);
		//window.draw(system.getParticles().front());
		//std::cout << mousePos.x << "," << mousePos.y << "\n";

		
		//window.draw(shape);
		//window.draw(x);
		//x.update();
		window.display();
		
	}

	return 0;
}