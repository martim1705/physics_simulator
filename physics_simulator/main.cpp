#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
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

    sf::Clock clock; 
    
    float x = 360.f; 
    float y = 240.f;
    float yf, xf;
    float vy = 240; // pixel / segundo
    float vx = 0; 
    // posicionar na janela 
    shape.setPosition({ x, y });
    // loop principal
    while (window.isOpen())
    {

        // tempo 
        sf::Time elapsed = clock.restart(); 
        float dt = elapsed.asSeconds(); 
        // eventos
        while (const std::optional event = window.pollEvent())
        {
            // fechar a janela 
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        sf::Vector2f initial_position = shape.getPosition();
        yf = initial_position.y + vy * dt;
        xf = initial_position.x + vx * dt; 

        shape.setPosition({ xf, yf});
        sf::Vector2f final_position = shape.getPosition();
        

        if (final_position.y >= 430.f) { // colisões para o "chão"
            vy = -vy;
        }
        else if (final_position.y <= 50.f) { // colisões para o "teto"
            vy = -vy; 
        }

        if (final_position.x <= 50.0f) {
            vx = 120; 
        }
        else if (final_position.x >= 670.0f) {
            vx = -120; 
        }

        // se a tecla da esquerda é selecionada, bola move-se para a esquerda
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            vx = -120;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            vx = 120; 
        }
        // limpar e desenhar
        window.clear();
        window.draw(shape);
        window.display();
    }
}