// Author: Sylvester Agyiri
// Date: Tuesday, 1 December 2020 (Covid-19 year)
// Started: Tuesday, 1 December 2020 (12:00 pm)
// Ended: Tuesday, 1 December 2020 (6:00pm)
// Language: C++11
// IDE: Visual Studio Code
// Compiler: GCC 10.2.0
// Libraries used: SFML and fstream
// Inspired by: Tech with tim multiplay game (with python using pygame library)
// About the project
// This is a multiplayer game that does not use socket 
// But it saves the players position to a file (named:- client1.txt)
// And reads the other player's position from a file (named:- client2.txt)
// Resources:
// - Read and Write int into a file in binary 
// ---- site:: https://stackoverflow.com/questions/15017879/reading-and-writing-into-a-binary-file-in-c/15018625

// Challenges:
// - Keyboard event 
// - Handling client 1 and client 2 positioning

#include <SFML/Graphics.hpp>
#include <fstream>

// Write client 1 position to the file name client1.txt
void writePosition(sf::RectangleShape* client1) // Pass by reference
{
    float meposition[2] = {client1->getPosition().x, client1->getPosition().y};
    std::ofstream out("../.client1.txt", std::ios::binary);
    out.write((char*)&meposition, sizeof(meposition));
    out.close();
}

// Read client 2 position from client2.txt
void readPosition(sf::RectangleShape* client2) // Pass by reference
{
    float clientposition[2];
    std::ifstream in("../.client2.txt", std::ios::binary);
    in.read((char*)&clientposition, sizeof(clientposition));
    in.close();

    // Set client 2 position to client shape
    client2->setPosition(clientposition[0], clientposition[1]);
}

int main(int argc, char const *argv[])
{
    // client 1 x and y position values
    float x = 100.f;
    float y = 100.f;

    // Create a window for drawing the shapes
    sf::RenderWindow window(sf::VideoMode(800, 720), "Client 1");

    // Event handle class
    sf::Event event;

    // The Rectangle shapes
    sf::RectangleShape client1(sf::Vector2f(100, 100)); // client 1 shape
    sf::RectangleShape client2(sf::Vector2f(100, 100)); // Client 2 shape
    
    // Set the shapes colors
    client1.setFillColor(sf::Color::Blue); // color client 1 blue
    client2.setFillColor(sf::Color::Red); // color client 2 red

    
    // Window loop
    while (window.isOpen())
    {
        // Set the position of the client 1
        client1.setPosition(x, y);

        // Write client 1 position to a file
        writePosition(&client1);

        // Read client 2 position and set it position
        readPosition(&client2);

        // Check for close button click and close
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Keyboard Events 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x -= 1.0f;
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x += 1.0f;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            y -= 1.0f;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            y += 1.0f;

        // Clear the screen
        window.clear();

        // Draw client 1 
        window.draw(client1);

        // Draw client 2
        window.draw(client2);

        // Display the window
        window.display();
    }
    
    return 0;
}
