#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    // janela - cria a janela com tamanho e título
    sf::RenderWindow window(sf::VideoMode({ 720, 480 }), "SFML works!");
    // Cria uma entidade desenhável (Ex: RectangleShape, Sprite, Text)
    sf::CircleShape shape(50.f);
    // Preenche a entidade com a cor Verde
    shape.setFillColor(sf::Color(0xFF,0xF2,0xA6, 255));

    // colocar a origem no centro do círculo 
    shape.setOrigin({ 50.f, 50.f });

    float dt = 0.1;
    float x = 360.f; 
    float y = 240.f;
    float yf;
    float vy = 0.1;

    // posicionar na janela 
    shape.setPosition({ x, y });
    // loop principal
    while (window.isOpen())
    {
        // eventos
        while (const std::optional event = window.pollEvent())
        {
            // fechar a janela 
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        sf::Vector2f initial_position = shape.getPosition();
        yf = initial_position.y + vy * dt;
        shape.setPosition({ x, yf});

        sf::Vector2f final_position = shape.getPosition();
        if (final_position.y >= 450.f) {
            vy = -vy;
        }
        else if (final_position.y <= 10.f) {
            vy = -vy; 
        }
        // limpar e desenhar
        window.clear();
        window.draw(shape);
        window.display();

        dt += 0.1; 
    }
}