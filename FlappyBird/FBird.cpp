#include "FBird.hpp"
#include <iostream>
#include <random>

sf::SoundBuffer jumpBuffer;
sf::Sound jumpSound;

FBird::FBird() : window(sf::VideoMode(1000, 600), "Flappy Bird"), bird(), bg(), pipe(), birdSprite(), bgSprite(), pipeSpriteBottom(), animaInterval(sf::seconds(0.1f))
{ // incializando variaveis membros

    if (!bg.loadFromFile("assets/background.png") || !bird.loadFromFile("assets/flappy.png") || !pipe.loadFromFile("assets/pipe.png"), !gameOver.loadFromFile("assets/gameOver1.png"))
    {
        std::cout << "algum asset nao carregou!";
    }
    gameover = false;

    window.setFramerateLimit(60);

    pipeSpriteBottom.setTexture(pipe);
    pipeSpriteBottom.setScale(1.5f, 1.5f);

    pipeSpriteTop.setTexture(pipe);
    pipeSpriteTop.setScale(1.5f, -1.5f);

    birdSprite.setTexture(bird);
    bgSprite.setTexture(bg);
    birdSprite.setOrigin(birdSprite.getTextureRect().width / 2, birdSprite.getTextureRect().height / 2);

    gameOverSprite.setTexture(gameOver);
    gameOverSprite.setScale(0.3f, 0.3f);
    gameOverSprite.setPosition(300, 100);

    // sounds
    if (!jumpBuffer.loadFromFile("assets/jump.wav"))
    {
        std::cout << "o audio não foi carregado!";
    }
    jumpSound.setBuffer(jumpBuffer);

    if (font.loadFromFile("assets/flappybird.ttf"))
    {
        std::cout << "houve um erro!";
    }

    text.setFont(font);
    text.setPosition(500, 50);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    GameOverText.setFont(font);
    GameOverText.setPosition(250, 500);
    GameOverText.setCharacterSize(50);
    sf::Color color(4, 51, 64, 255);
    GameOverText.setColor(color);

    frames = {
        sf::IntRect(0, 0, 34, 24),
        sf::IntRect(34, 0, 34, 24),
        sf::IntRect(68, 0, 34, 24)

    };

    birdSprite.setTextureRect(frames[0]);

    birdSprite.setScale(1.5f, 1.5f);
    bgSprite.setPosition(0.f, 0.0f);
    birdSprite.setPosition(360, 300);
}

FBird::~FBird()
{
    std::cout << "Destruindo o jogo na memoria" << std::endl;
}

void FBird::run()
{
    while (true)
    { // para podermos reiniciar o jogo
        while (window.isOpen())
        {
            deltaTime = deltaClock.getElapsedTime().asSeconds();
            deltaClock.restart();

            // ordem correta em um loop principal: eventos, logica e desenho
            events();
            logic();
            draw();
        }
    }
}

void FBird::draw()
{
    window.clear(sf::Color(70, 190, 240)); // lembre-se primeiro limpe o quadro e depois renderize os desenhos
    window.draw(bgSprite);                 // seu burro! não coloque o sprite entidade atrás do background kkkk

    printPipes();
    window.draw(birdSprite);

    window.draw(text);
    if (gameover)
    {
        GameOverText.setString("Press R to restart");
        window.draw(gameOverSprite);
        window.draw(GameOverText);
    }
    window.display();
}

void FBird::events()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            break;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        { // 1-verifica o tipo do evento e depois o codigo da chave de evento
            window.close();
            break;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            reloadGame();
        }
    }
}

void FBird::logic()
{
    if (isColliding())
    {

        gameover = true;
    }

    if (!gameover)
    {
        spawnPipes();
        birdMove();
        scoreLogic();
        animations();
    }
}

void FBird::animations()
{ // devo escrever um codigo onde em certo e certo tempo eu troque de sprite no array

    if (animationClock.getElapsedTime().asSeconds() > animaInterval.asSeconds())
    {
        if (currentFrame == 2)
        {

            birdSprite.setTextureRect(frames[currentFrame]);
            animationClock.restart();
            currentFrame = 0;
        }
        else
        {
            birdSprite.setTextureRect(frames[currentFrame]);
            animationClock.restart();
            currentFrame++;
        }
    }
}

void FBird::spawnPipes() // spanw -> logic ->
{
    if (timeEachPipe.getElapsedTime().asSeconds() > 1.5f)
    {
        int pos = std::rand() % 300 + 50;

        pipeSpriteBottom.setPosition(1000, pos + SPACE_BETWEEN_PIPES);
        pipeSpriteTop.setPosition(1000, pos);
        pipesArray.push_back(pipeSpriteBottom);
        pipesArray.push_back(pipeSpriteTop);

        timeEachPipe.restart();
    }
    for (int i = 0; i < pipesArray.size(); i++)
    {
        if (pipesArray[i].getPosition().x < -50)
        {
            pipesArray.erase(pipesArray.begin() + i);
        }
        // std::cout << pipesArray[i].getPosition().y << std::endl;
        pipesArray[i].move(-5, 0);
    }
}

void FBird::printPipes()
{
    for (sf::Sprite pipe : pipesArray)
    {
        window.draw(pipe);
    }
}

bool FBird::isColliding()
{
    for (int i = 0; i < pipesArray.size(); i++)
    {
        if (birdSprite.getGlobalBounds().intersects(pipesArray[i].getGlobalBounds()))
        {
            return true;
        }
    }
    if (birdSprite.getPosition().y < 0 || birdSprite.getPosition().y > window.getSize().y)
    {
        return true;
    }

    return false;
}
// sf::Vector2f gravity = sf::Vector2f(0, 2);

void FBird::birdMove()
{

    velocity_y1 += gravity1 * deltaTime;
    birdSprite.move(0, velocity_y1 * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {

        jumpSound.play();
        velocity_y1 = -250;
    }
    if (velocity_y1 < 0)
    {
        if (velocity_y1 < -260)
        {
            birdSprite.setRotation(-20);
        }
        birdSprite.setRotation(-10);
    }
    else if (velocity_y1 > 100)
    {
        birdSprite.setRotation(10);
    }
    else if (velocity_y1 < 100 && velocity_y1 > 0)
    {
        birdSprite.setRotation(0);
    }
}

void FBird::scoreLogic()
{
    for (int i = 0; i < pipesArray.size(); i++)
    {
        if (birdSprite.getPosition().x == pipesArray[i].getPosition().x + 50)
        {
            score++;
        }

        text.setString(std::to_string(score / 2));
    }
}

void FBird::reloadGame()
{
    birdSprite.setPosition(360, 300);
    score = 0;
    gameover = false;
    pipesArray.clear();
    velocity_y1 = 0;
}