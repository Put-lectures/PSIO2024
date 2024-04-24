#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
class GraphicalObject : public sf::Sprite
{
    sf::Texture texture_;

public:
    GraphicalObject(string texture, sf::Vector2f pos = sf::Vector2f(0, 0), bool is_repeated = false)
    {
        if (!texture_.loadFromFile(texture)) {
            throw("Wrong texture filename");

            //     return 1;
        }
        texture_.setRepeated(is_repeated);
        this->setTexture(texture_);
        this->setPosition(pos);
        //
    }

    virtual bool collision(GraphicalObject *ob) = 0;
};
class Hero : public GraphicalObject
{
    int hp_;
    float velocity_;
    float direction_;

public:
    Hero(int hp, sf::Vector2f pos, sf::IntRect rect, string texture)
        : GraphicalObject(texture, pos)
        , hp_(hp)
        , velocity_(0)
        , direction_(0)
    {
        this->setTextureRect(sf::IntRect(10, 10, 800, 600));
    }
    virtual bool collision(GraphicalObject *ob)
    {
        if (this->getGlobalBounds().intersects(ob->getGlobalBounds())) {
            cout << "Collision detected" << std::endl;
            return true;
        }
        return false;
    }
};
class Background : public GraphicalObject
{
public:
    Background(string texture, bool is_repeated)
        : GraphicalObject(texture, sf::Vector2f(0, 0), is_repeated)
    {}
    virtual bool collision(GraphicalObject *ob) { return false; }
};
class Wall : public GraphicalObject
{
public:
    Wall(sf::IntRect rect, sf::Vector2f pos, float scale, string texture, bool is_repeated)
        : GraphicalObject(texture, pos, is_repeated)
    {
        this->setScale(scale, scale);
        this->setTextureRect(rect);
    }
    virtual bool collision(GraphicalObject *ob)
    {
        if (this->getGlobalBounds().intersects(ob->getGlobalBounds())) {
            cout << "Collision detected" << std::endl;
            return true;
        }
        return false;
    }
};
class Engine
{
    sf::RenderWindow window_;

public:
    vector<GraphicalObject *> objects;
    Hero *hero_;
    Engine(Hero *hero)
        : window_(sf::VideoMode(800, 600), "My window")
        , hero_(hero)

    {
        build_map();
        hero->setPosition(sf::Vector2f(10, 10));
    }
    void build_map()
    {
        objects.emplace_back(new Background("./tex/grass.png", true));

        objects.emplace_back(new Wall(sf::IntRect(0, 0, 80, 200),
                                      sf::Vector2f(200, 200),
                                      0.3,
                                      "./tex/wall.png",
                                      true));
        objects.emplace_back(new Wall(sf::IntRect(0, 0, 200, 80),
                                      sf::Vector2f(300, 300),
                                      0.3,
                                      "./tex/wall.png",
                                      true));

        // Hero hero(100, sf::Vector2f(10, 10), sf::IntRect(10, 10, 800, 600), "./tex/guy.png");

        // Wall wall_1(sf::IntRect(0, 0, 80, 200), sf::Vector2f(200, 200), 0.3, "./tex/wall.png", true);
        // Wall wall_2(sf::IntRect(0, 0, 200, 80), sf::Vector2f(300, 300), 0.3, "./tex/wall.png", true);
    }
    void main_loop()
    {
        sf::Clock clock;
        while (window_.isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window_.pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window_.close();
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Space) {
                        std::cout << "Space released" << std::endl;
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
                        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                                  << std::endl;
                    }
                }
            }
            collision();
            display();
        }
    }
    void collision()
    {
        for (auto &el : objects) {
            if (el->collision(hero_)) {
                // Wall *e = dynamic_cast<Wall *>(el); Złamanie zasady postawenia Liskov
                // if (e!=nullptr)
                // {

                // }
                // else{
                //     Bonus *e = dynamic_cast<Bonus *>(el);
                // }
            }
        }
    }
    void display()
    {
        window_.clear(sf::Color::Black);
        for (auto &el : objects) {
            window_.draw(*el);
        }
        window_.draw(*hero_);
        window_.display();
    }
    ~Engine()
    {
        for (auto &el : objects) {
            delete el;
        }
    }
};

int main()
{
    Hero hero(100, sf::Vector2f(10, 10), sf::IntRect(10, 10, 800, 600), "./tex/guy.png");
    Engine game(&hero);
    game.main_loop();
    return 0;
}
