#include "Textures.h"
sf::Texture Textures::PlayerBow;
sf::Texture Textures::PlayerWalk;
sf::Texture Textures::Spare;
sf::Texture Textures::Skeleton;
sf::Texture Textures::SkeletonDead;
sf::Font Textures::Ariel;

Textures::Textures()
{
    Ariel.loadFromFile("/Library/Fonts/Arial Unicode.ttf");
    PlayerBow.loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Player/Assets/Player/Textures/player_bow.png");
    PlayerWalk.loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Player/Assets/Player/Textures/player_walk.png");
    Skeleton.loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Enemy/Assets/BODY_skeleton.png");
    SkeletonDead.loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Enemy/Assets/skeleton_dead.png");
    Spare.loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Bullet/Bullet_Texture/WEAPON_spear.png");
}
