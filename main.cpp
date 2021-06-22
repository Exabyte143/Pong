#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <ctime>
#include <cstdlib>

int checkCollision(sf::RectangleShape shape1, sf::RectangleShape shape2)
{

    if (shape1.getPosition().x - shape2.getPosition().x <= 10 && shape1.getPosition().y - shape2.getPosition().y <= 100 && shape1.getPosition().y - shape2.getPosition().y > 0)
    {
        return shape1.getPosition().y - shape2.getPosition().y;
    }
    return -1;
}

int main()
{
    float direction = 0.25f;
    float direction2 = 0.0f;

    // Window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Pong", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(360);
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    //Dotted line
    sf::Texture texture;
    if (!texture.loadFromFile("src/line.png"))
    {
        return 1;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    //Clock
    sf::Clock clock;

    //Font
    sf::Font font;

    if (!font.loadFromFile("src/PixelSplitter-Bold.ttf"))
    {
        return 0;
    }

    //Player1
    sf::RectangleShape player(sf::Vector2f(10.0f, 100.0f));
    player.setFillColor(sf::Color::White);
    player.setPosition(10.0f, 256.0f);
    int PlayerScore1 = 0;
    sf::Text player1Text;
    player1Text.setFont(font);
    player1Text.setString("0");
    player1Text.setPosition(218.0f, 472.0f);

    //Player2
    sf::RectangleShape player2(sf::Vector2f(10.0f, -100.0f));
    player2.setFillColor(sf::Color::White);
    player2.setPosition(492.0f, 356.0f);
    int PlayerScore2 = 0;
    sf::Text player2Text;
    player2Text.setFont(font);
    player2Text.setString("0");
    player2Text.setPosition(276.0f, 472.0f);

    //Ball
    sf::RectangleShape ball(sf::Vector2f(10.0f, 10.0f));
    ball.setFillColor(sf::Color::White);
    ball.setPosition(246.0f, 246.0f);

    // Gameloop
    while (window.isOpen())
    {
        //Time
        sf::Time time = clock.restart();

        //Event handlers
        sf::Event event;
        while (window.pollEvent((event)))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        //PlayerMovement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            if (player2.getPosition().y > 100)
            {
                player2.move(0.0f, -0.5f * time.asMilliseconds());
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            if (player2.getPosition().y < 512)
            {
                player2.move(sf::Vector2f(0.0, 0.5 * time.asMilliseconds()));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            if (player.getPosition().y > 0)
            {
                player.move(0.0f, -0.5f * time.asMilliseconds());
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            if (player.getPosition().y < 412)
            {

                player.move(0.0f, 0.5f * time.asMilliseconds());
            }
        }

        //Ball movement
        if (ball.getPosition().x < 502 && ball.getPosition().x > 0)
        {

            ball.move(direction * time.asMilliseconds(), direction2 * time.asMilliseconds());
            if (checkCollision(player2, ball) != -1 && checkCollision(player2, ball) > 50)
            {
                direction = -0.25f;
                direction2 = -0.25f;
            }
            else if (checkCollision(player2, ball) != -1 && checkCollision(player2, ball) <= 50)
            {
                direction = -0.25f;
                direction2 = 0.25f;
            }
            else if (checkCollision(ball, player) != -1 && checkCollision(ball, player) < 50)
            {
                direction = 0.25f;
                direction2 = -0.25f;
            }
            else if (checkCollision(ball, player) != -1 && checkCollision(ball, player) >= 50)
            {
                direction = 0.25f;
                direction2 = 0.25f;
            }
        }
        else if (ball.getPosition().x < 502)
        {
            PlayerScore2++;
            ball.setPosition(246.0f, 246.0f);
            player2Text.setString(std::to_string(PlayerScore2));
            direction = 0.25f;
            direction2 = 0.0f;
        }
        else if (ball.getPosition().x > 0)
        {
            PlayerScore1++;
            ball.setPosition(246.0f, 246.0f);
            player1Text.setString(std::to_string(PlayerScore1));
            direction = -0.25f;
            direction2 = 0.0f;
        }
        if (ball.getPosition().y < 0)
        {
            direction2 = 0.25f;
        }
        else if (ball.getPosition().y > 512)
        {
            direction2 = -0.25f;
        }

        // Render
        window.clear();
        window.draw(sprite);
        window.draw(player);
        window.draw(player2);
        window.draw(player1Text);
        window.draw(player2Text);
        window.draw(ball);
        window.display();
    }

    return 0;
}
