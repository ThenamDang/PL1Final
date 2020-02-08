#include <iostream>
#include <stdlib.h> 
#include <unistd.h>
#include<time.h>  
using namespace std;

int enemypow()
{
	int EP;
	EP = rand() % 141 + 10;
}
// Generate a random enemy with random power


int main()
{
	srand((unsigned)time(NULL));
	do
	{
		// Main menu
		cout << " _    _   ___  ______  _   _   ___  ___  ______  ___ _____ ______  \n";
		cout << "| |  | | / _ \\ | ___ \\| | | | / _ \\ |  \\/  ||  \\/  ||  ___|| ___ \\ \n";
		cout << "| |  | |/ /_\\ \\| |_/ /| |_| |/ /_\\ \\| .  . || .  . || |__  | |_/ / \n";
		cout << "| |/\\| ||  _  ||    / |  _  ||  _  || |\\/| || |\\/| ||  __| |    / \n";
		cout << "\\  /\\  /| | | || |\\ \\ | | | || | | || |  | || |  | || |___ | |\\ \\ \n";
		cout << " \\/  \\/ \\_| |_/\\_| \\_|\\_| |_/\\_| |_/\\_|  |_/\\_|  |_/\\____/ \\_| \\_| \n";
		cout << endl;
		cout << "               ___  _____  _____  _____  _____                     \n";
		cout << "              /   ||  _  ||  _  ||  _  ||  _  |                    \n";
		cout << "             / /| || |/' || |/' || |/' || |/' |                    \n";
		cout << "            / /_| ||  /| ||  /| ||  /| ||  /| |                   \n";
		cout << "            \\___  |\\ |_/ /\\ |_/ /\\ |_/ /\\ |_/ /                   \n";
		cout << "                |_/ \\___/  \\___/  \\___/  \\___/                    \n";
		cout << endl;
		cout << "	      ___                                 \n";
		cout << "	       |    _ _  _ . _| _   _    _  _ _  \n";
		cout << "	       | \\/| (_|| )|(_|_)  _)\\)/(_|| ||| \n";
		cout << "	       	 /                               ";
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Initializing......";
		sleep(2);
		cout << endl;
		cout << endl;
		// Create character
		// Name
		cout << "Your name: ";
		string Pname;
		cin >> Pname;
		char character;
		// Determind your character power
		cout << "                      1                                  2                                   3  \n";
		cout << "         >T< ~ Adeptus Astartes ~ >T<         =][= ~ Inquisition ~ =][=        <0> ~ Astra Millitarum ~ <0>\n";
		cout << "Base:          power 70 - 100                       power 40 - 60                      power 10 - 15\n"; // Base power
		do
		{
			cout << "Choose your character (1/2/3): ";
			cin >> character;
		} while (character != '1' && character != '2' && character != '3');
		// Determind player power based on choice
		int playerpow;
		int basepow;
		int extrapow;
		// Playerpow is player character total power = Base power + extrapow
		switch (character)
		{
		case '1':
			basepow = rand() % 31 + 70;
			extrapow = rand() & 35;
			playerpow = basepow + extrapow;
			break;
		case '2':
			basepow = rand() % 21 + 40;
			extrapow = rand() % 100;
			playerpow = basepow + extrapow;
			break;
		case '3':
			basepow = rand() % 6 + 10;
			extrapow = rand() % 150;
			playerpow = basepow + extrapow;
			break;
		}
		// Difficulty choosing, higher difficulty, more enemy. Amount of enemy is random
		char difficulty;
		cout << "Threat level: \n";
		cout << "1. Small swarm (5 - 10 waves)\n";
		cout << "2. Hive Fleet (10 - 20 waves)\n";
		cout << "3. Hive Fleet Behemoth (20 - 40 waves)\n";
		do
		{
			cout << "Choose: ";
			cin >> difficulty;
		} while (difficulty != '1' && difficulty != '2' & difficulty != '3');
		int waves;
		switch (difficulty)
		{
		case '1':
			waves = rand() % 5 + 5;
		case '2':
			waves = rand() % 10 + 10;
			break;
		case '3':
			waves = rand() % 20 + 20;
			break;
		}
		cout << endl;
		// Main game
		int wavessurv = 0; // Games end after wavessurv = waves
		int playersurv = true; // If player survive is false game end
		cout << "Warning! Tyranids swarm detected!!!\n";
		cout << "Press [ENTER] to ready\n";
		cin.ignore();
		cin.get();
		cout << endl;
		// Battle start
		while (playersurv && wavessurv < waves)
		{
			// Generate a random enemy
			int wavesstr = enemypow();

			// This part is just to have different type of enemy based on their power
			if (wavesstr >= 100)
			{
				cout << "Hive Tyrant incoming\n";
			}
			else if (50 <= wavesstr < 100)
			{
				cout << "Carnifex incoming";
			}
			else if (10 <= wavesstr < 50)
			{
				cout << "Tyranid Warrior incoming";
			}
			else
			{
				cout << "Hormagaunt incoming";
			}
			cout << endl;
			cout << "Engaging...\n";
			cout << "...\n";
			sleep(2);
			// Determine the battle, if the enemy has more power than the player, the player lose. The player win under the oposite condition
			if (wavesstr - playerpow < 0 && playersurv)
			{
				cout << "Nid exterminated\n";
				cout << "___________________________________________________";
				cout << endl;
			}
			else if (wavesstr - playerpow == 0 && playersurv)
			{
				cout << "Nids exterminated.   Injure detected\n";
				int damage = rand() % 30; // lower your power
				cout << "Suffered " << damage << " damage\n";
				playerpow = playerpow - damage;
				cout << "___________________________________________________\n";
				cout << endl;
			}
			else if (wavesstr - playerpow > 0 && playersurv)
			{
				cout << "Lethal injure suffered.   No life sign detected\n";
				playerpow = 0;
				cout << "___________________________________________________";
				cout << endl;
				playersurv = false;
			}
			wavessurv++;
			sleep(1);
			cout << endl;
		}
		//game end
		if (wavessurv >= waves)
		{
			// Win
			cout << "Battle ends\n";
			cout << "Swarm destroy\n";
			cout << endl;
			cout << "\"Glory to the Emperor!\"\n";
			cout << endl;
		}
		else
		{
			// Lose
			cout << "Battle ends\n";
			cout << "You Perished\n";
			cout << "\"Only in death does duty end\"";
			cout << endl;
		}
		// After battle details
		cout << "Battle report\n";
		cout << "*		*		*";
		cout << endl;
		switch (character)
		{
		case '1':
			cout << "Astartes " << Pname << " >T<";
			cout << endl;
			break;
		case '2':
			cout << "Inquisitor: " << Pname << " =][=";
			cout << endl;
			break;
		case '3':
			cout << "Guardsmen: " << Pname << " <0>";
			cout << endl;
			break;
		}
		cout << "Kill counts: " << wavessurv << " Tyranids";
		cout << endl;
		int playerscore = wavessurv * 100 - playerpow;
		cout << "Battle performance: " << playerscore << " scores.\n";
		cout << "Your power remaining: " << playerpow;
		cout << endl;
		cout << endl;
		cout << "Press [ENTER] to restart.\n";
	} while (cin.ignore());
	return 0;
}




