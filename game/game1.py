#include <iostream>
using namespace std;

// Define the player's attributes
struct Player {
string name;
int health = 100;
int mana = 50;
int strength = 10;
int agility = 6;
int intellect = 8;
}
// Function to print the player's status
void PrintStatus() {
cout << "Name: " + name << endl;
cout << "Health: " + to_string(health) << "/" + to_string(GetMaxHealth()) << endl;
cout << "Mana: " + to_string(mana) << "/" + to_string(GetMaxMana()) << endl;
cout << "Strength: " + to_string(strength) << endl;
cout << "Agility: " + to_string(agility) << endl;
cout << "Intellect: " + to_string(intellect) << endl;


// Calculate the maximum possible health based on level and constitution stat
int GetMaxHealth() { return (int)(level * 10); }

// Calculate the maximum possible mana based on level and wisdom stat
int GetMaxMana() { return (int)(level * 7); }
};

// Define the enemy struct
struct Enemy {
string name;
int health = 20;
int damage = 3;

// Function to attack the enemy with the given weapon
void Attack(Player& player, Weapon& weapon) {
int totalDamage = random(damage - weapon.defense / 2, damage + weapon.attack);
if (!weapon.magic)
player.health -= totalDamage;
else
DoMagicAttack(player, weapon);
}

// Magic function for doing special attacks like fireball or ice bolt
void DoMagicAttack(Player& player, Weapon& magicWeapon) {}
};

// Define the weapon struct
struct Weapon {
bool magic;
float attack;
float defense;
};

// Create some example weapons
const vector<Weapon> Weapons = {
{ false, 4.f, 2.f }, // Fists
{ true, 20.f, 5.f }, // Staff
{ true, 10.f, 0.f }, // Wand
{ false, 6.f, 4.f }, // Sword
{ true, 15.f, 3.f }, // Bow
{ true, 25.f, 2.f } }; // Crossbow

void Battle(Enemy& enemy, Player& player) {
while (enemy.health > 0 && player.health > 0) {
// Choose a random weapon from our list of options
size_t choice = rand() % Weapons.size();

// Show the player their choices and get input
cout << "Choose a weapon:" << endl;
for (size_t i = 0; i < Weapons.size(); ++i) {
cout << "[" << i+1 << "] " << Weapons[i].name
<< ": Att+" << Weapons[i].attack
<< ", Def-" << Weapons[i].defense << endl;
}
cin >> choice;

// If they enter an invalid option, loop again
if (choice == 0 || choice > Weapons.size()) continue;

// Otherwise, have them choose which one to use
Weapon* chosenWeapon = &Weapons[choice - 1];

// Have the enemy attack using the selected weapon
enemy.Attack(*player, *chosenWeapon);

// Check if the player died during combat
if (player->health <= 0) break;

// The player takes turn now...
cout << "The enemy attacks!" << endl;
player.Attack(*enemy, *chosenWeapon);

// Again check if the player died this time around too
if (player->health <= 0) break;
}
}

int main() {
srand((unsigned int)time(NULL)); // Initialize random seed

// Set up the player
Player player;
player.name = "<NAME>";

// Give the player some starting equipment
player.inventory.push({ "Sword", EquipmentSlot::WEAPON });
player.inventory.back().item.as<Weapon>().attack += 5;
player.inventory.back().item.as<Weapon>().defense += 2;

// Start the battle
Enemy dragon("Goblin Dragon");
Battle(dragon, player);

// Print out the final result
cout << "\nFinal Result:\n";
player.PrintStats();
dragon.PrintStats();

return 0;
}