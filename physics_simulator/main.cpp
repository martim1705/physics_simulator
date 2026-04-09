#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


float g = 2354.4f; // pixels / segundo^2
float perda_energia = 0.7; 
float atrito_ar = 200.f;

// energia cinetica = 1/2 * m * v^2

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
    float vy = 240.0f; // pixel / segundo
    float vx = 0.0f;
     
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

        // se a tecla da esquerda é selecionada, bola move-se para a esquerda
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            vx = -120.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            vx = 120.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            vy = -900.f;
        }


        // velocidade 
        vy += g * dt;

        sf::Vector2f initial_position = shape.getPosition();
        yf = initial_position.y + vy * dt;
        xf = initial_position.x + vx * dt; 

        
        sf::Vector2f final_position = shape.getPosition();
        

        if (yf > 430.f) { // colisões para o "chão
            yf = 430.0f;
            vy = -(perda_energia * vy);
        }
        else if (yf < 50.f) { // colisões para o "teto"
            yf = 50.f;
            vy = -perda_energia * vy;
        }

        if (xf < 50.0f) { // colisões à esquerda
            xf = 50.0f; 
            vx = -vx;

        }
        else if (xf > 670.0f) { // colisões à direita
            xf = 670.0f;
            vx = -vx;
        }

        
        
        if (vx > 0.f) {
            vx -= atrito_ar * dt;
            if (vx < 0.f) vx = 0.f;
        }
        else if (vx < 0) {
            vx += atrito_ar * dt;
            if (vx > 0.f) vx = 0.f;
        }
        shape.setPosition({ xf, yf });


        std::cout << "Ball position: (" << xf << "," << yf << ")\n";

        // limpar e desenhar
        window.clear();
        window.draw(shape);
        window.display();
    }
}