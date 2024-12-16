#include "Enemy.h"
#include "Textures.h"

Enemy::Enemy()
    : size(64, 64), moveSpeed(200.0f), HealthPoint(100)  // Initialize size, moveSpeed, and health
{
    // Set the initial texture for the sprite (Skeleton texture)
    Sprite.setTexture(Textures::Skeleton);
    // Set the texture rectangle to show a specific part of the texture (part of the skeleton sprite)
    Sprite.setTextureRect(sf::IntRect(0, 2 * size.y, size.x, size.y));
    // Scale the sprite by a factor of 3 to make it larger
    Sprite.scale(sf::Vector2f(3, 3));
    // Set the initial position of the sprite
    Sprite.setPosition(500, 500);
    
    // Set up the health text display (font and color)
    HealthText.setFont(Textures::Ariel);  // Load the font for health text
    HealthText.setFillColor(sf::Color::White);  // Set text color to white
    HealthText.setString(std::to_string(HealthPoint));  // Display current health as string
    HealthText.setPosition(Sprite.getPosition());  // Position the health text above the sprite
}

void Enemy::update(sf::RenderWindow& window, float deltaTime)
{
    // If the health is 0 and the enemy is not already dead, change the texture to the dead version
    if (HealthPoint == 0 && Sprite.getTexture() != &Textures::SkeletonDead) {
        Sprite.setTexture(Textures::SkeletonDead);
    }
    // If health is not 0, reset the position of the sprite
    else {
        Sprite.setPosition(500, 500);  // Example: you can change this to dynamic position updates
    }
}

void Enemy::draw(sf::RenderWindow& window, float deltaTime)
{
    // Only draw if the health is greater than or equal to 0
    if (HealthPoint >= 0) {
        static float elapsedTime = 0.f;  // Elapsed time to control animation frames
        static int frameIndex = 0;  // Frame index for animation

        elapsedTime += deltaTime;

        // If the health is 0, we switch to a death animation
        if (HealthPoint == 0) {
            if (elapsedTime >= 0.5f) {  // Switch frame every 0.5 seconds
                elapsedTime = 0.f;  // Reset elapsed time
                // Change the texture rectangle to show the next frame of the death animation
                Sprite.setTextureRect(sf::IntRect(frameIndex * size.x, 0 * size.y, size.x, size.y));
                frameIndex++;
                window.draw(Sprite);  // Draw the sprite with the updated frame

                // If all death frames are shown, decrement health further (for dead state an

void Enemy::ChangeHP(int damage)
{
    // Decrease the health by the specified damage
    HealthPoint -= damage;

    // Update the health text to reflect the new health
    HealthText.setString(std::to_string(HealthPoint));

    // Reposition the health text to match the enemy's position
    HealthText.setPosition(Sprite.getPosition());
}

}
        }
    }

