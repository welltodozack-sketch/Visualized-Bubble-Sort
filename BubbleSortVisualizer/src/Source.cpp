#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main(){
    vector<float> list = {64, 80, 46, 69, 80, 63, 94, 77, 28, 66, 27, 73, 25, 95, 13, 48, 94, 46, 54, 5, 55, 68, 13, 8, 83, 9, 15, 19, 26, 28, 4, 74, 35, 91, 94, 23, 20, 16, 7, 74, 35, 58, 19, 78, 46, 44, 40, 86, 50, 82, 7, 68, 85, 9, 10, 19, 35, 74, 28, 53, 27, 5, 38, 76, 96, 85, 21, 8, 4, 29, 50, 7, 35, 51, 2, 52, 96, 39, 6, 28, 75, 31, 27, 86, 37, 43, 9, 69, 8, 95, 51, 1, 67, 28, 17, 1, 5, 78, 29, 79};

    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Visualized Bubble Sort");

    std::vector<sf::RectangleShape> bars;

    sf::Vector2f windowSize(window.getSize());

    float barWidth = windowSize.x / list.size();

    for (int i = 0; i < list.size(); i++)
    {   
        sf::RectangleShape bar;
        bar.setSize(sf::Vector2f(barWidth - 2.f, list[i]*4));
        float y = (windowSize.y) - (bar.getSize().y);
        bar.setPosition({i * barWidth, y});
        bar.setFillColor(sf::Color::White); // change color of rectangle
        bars.push_back(bar);
    }


    sf::Clock clock;

    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        int size = list.size();

        for(int i = 0; i < size; i++){ // elements to be sorted
            bool swapped = false;

            for(int j = 0; j < size - 1; j++){

                if(list[j] > list[j+1]){ // swap if item is bigger
                    swap(list[j], list[j+1]);

                    // Clear screen
                    window.clear();

                    bars[j].setSize(sf::Vector2f(barWidth - 2.f, list[j]*4));
                    float y = (windowSize.y) - (bars[j].getSize().y);
                    bars[j].setPosition({j * barWidth, y});
                    bars[j].setFillColor(sf::Color::Red);

                    bars[j+1].setSize(sf::Vector2f(barWidth - 2.f, list[j+1]*4));
                    float y2 = (windowSize.y) - (bars[j+1].getSize().y);
                    bars[j+1].setPosition({(j+1) * barWidth, y2});
                    bars[j+1].setFillColor(sf::Color::Green);

                    for (auto& bar : bars){
                        window.draw(bar);
                    }

                    // update window
                    window.display();

                    bars[j].setFillColor(sf::Color::White);
                    bars[j+1].setFillColor(sf::Color::White);

                    swapped = true; // set swapped flag to true
                    Sleep(0.9);
                }
            }
        }
    }
    return 0;
}