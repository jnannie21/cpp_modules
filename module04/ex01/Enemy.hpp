//
// Created by jnannie on 12/22/20.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
private:
	Enemy();

	int _hp;
	std::string _type;

public:
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const &other);
	Enemy &operator=(Enemy const &other);
	~Enemy();
	std::string [...] getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};


#endif //ENEMY_HPP
